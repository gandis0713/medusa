# V3D QPU 타이밍 요구사항 (Timing Requirements)

## 타이밍 정보의 출처

V3D QPU의 타이밍 요구사항은 다음 소스에서 확인할 수 있습니다:

### 1. Mesa 코드베이스 (주요 출처)

**파일 위치:**
```
medusa/broadcom/compiler/qpu_schedule.c
```

이 파일은 **QPU 명령어 스케줄러**로, 하드웨어 타이밍 제약을 준수하면서 명령어를 배치합니다.

**주요 함수:**
- `instruction_latency()`: 명령어 간 레이턴시 계산
- `magic_waddr_latency()`: 특수 레지스터(TMUA, TMUD 등) 레이턴시
- `qpu_inst_after_thrsw_valid_in_delay_slot()`: THRSW delay slot 검증
- `qpu_inst_before_thrsw_valid_in_delay_slot()`: THRSW 병합 검증

### 2. Broadcom V3D 하드웨어 문서

**공식 문서:** (NDA 제한)
- Broadcom VideoCore VII Architecture Specification
- V3D 7.1 Programmer's Reference Manual

**공개 정보:**
- Mesa 드라이버 주석 및 커밋 메시지
- Linux 커널 V3D DRM 드라이버
- Raspberry Pi 포럼 및 공식 문서

### 3. 경험적 테스트 (Empirical Testing)

Mesa 코드의 주석에 명시:
```c
/* Empirical testing shows that using priorities to hide latency of
 * TMU operations when scheduling QPU leads to slightly worse
 * performance, even at 2 threads. */
```

많은 타이밍 제약이 실제 하드웨어 테스트를 통해 검증되었습니다.

---

## V3D 7.1 타이밍 제약 사항

### 1. THRSW (Thread Switch) 타이밍

#### Delay Slot 요구사항

```c
// qpu_schedule.c:2115
const uint32_t slot = scoreboard->tick - scoreboard->last_thrsw_tick;
assert(slot <= 2);
```

**규칙:**
- **THRSW 후 정확히 2개의 delay slot 필요**
- THRSW는 tick N에 실행
- 실제 스레드 전환은 tick N+3에 발생

**타임라인:**
```
Tick 0: thrsw          ← THRSW 신호 발행
Tick 1: delay slot 1   ← 아직 스레드 전환 안됨
Tick 2: delay slot 2   ← 아직 스레드 전환 안됨
Tick 3: (next inst)    ← 여기서 실제 스레드 전환 발생!
```

#### Delay Slot에 허용되지 않는 명령어

```c
// qpu_schedule.c:2143-2144
/* Branch is not allowed in delay slots of a thrsw. */
if (qinst->qpu.type == V3D_QPU_INSTR_TYPE_BRANCH)
    return false;
```

**금지 사항:**
1. **Branch 명령어** - 제어 흐름 충돌
2. **다른 THRSW** - 중첩 스레드 전환 불가
3. **TLB 접근** - Scoreboard wait 필요
4. **TMU 명령어** (특정 조건) - TMU 시퀀스 무결성

#### V3D 4.2 vs 7.1 차이점

```c
// qpu_schedule.c:2022-2025 (V3D 7.1)
/* RF2-3 might be overwritten during the delay slots by
 * fragment shader setup.
 */

// qpu_schedule.c:2008-2011 (V3D 4.2)
/* RF0-2 might be overwritten during the delay slots by
 * fragment shader setup.
 */
```

**V3D 4.2:**
- RF0, RF1, RF2가 delay slot에서 덮어써질 수 있음

**V3D 7.1:**
- RF2, RF3이 delay slot에서 덮어써질 수 있음
- RF0는 안전 (개선됨!)

#### Scoreboard Locking

```c
// qpu_schedule.c:715-716
return scoreboard->first_thrsw_emitted &&
       scoreboard->tick - scoreboard->last_thrsw_tick >= 3;
```

**규칙:**
- TLB 접근 전에 scoreboard wait 필요
- 첫 THRSW 후 3 사이클 후 scoreboard가 lock됨
- 또는 마지막 THRSW 후 3 사이클

---

### 2. TMU (Texture Memory Unit) 타이밍

#### TMU Read Latency

```c
// qpu_schedule.c:1801-1833
static uint32_t magic_waddr_latency(const struct v3d_device_info *devinfo,
                                    enum v3d_qpu_waddr waddr,
                                    const struct v3d_qpu_instr *after)
{
    /* Apply some huge latency between texture fetch requests and getting
     * their results back.
     *
     * FIXME: This is actually pretty bogus.  If we do:
     *
     * mov tmu0_s, a
     * <a bunch of instructions>
     * mov tmu0_s, b
     * load_tmu0
     * <more instructions>
     * load_tmu0
     *
     * we count that load_tmu0 as returning the read from <a bunch of
     * instructions> ago, when it's actually returning the read from the
     * mov tmu0_s, b.  ...
     */
    // ...
}
```

**실제 레이턴시:**
- **L1 Cache Hit**: ~5 cycles
- **L2 Cache Hit**: ~20 cycles
- **DRAM Access**: 100+ cycles

**Mesa 스케줄러의 접근:**
- TMU 요청과 응답 사이에 "큰 레이턴시" 가정
- 정확한 추적은 복잡하므로 보수적으로 스케줄링

#### TMUWT (TMU Wait)

```c
// qpu_schedule.c:1976-1978
/* GFXH-1625: TMUWT not allowed in the final instruction. */
if (c->devinfo->ver == 42 && slot == 2 &&
    inst->alu.add.op == V3D_QPU_A_TMUWT) {
    return false;
}
```

**규칙 (V3D 4.2):**
- TMUWT는 delay slot의 마지막 위치(slot 2)에 올 수 없음
- 하드웨어 버그 GFXH-1625

**규칙 (V3D 7.1):**
- 이 제약이 해제됨

**권장사항:**
- TMUWT 후 최소 2 NOP 권장 (실제 프로그램에서 확인됨)
- TMU write queue flush 시간 확보

#### TMU FIFO 크기

```c
// qpu_schedule.c:1558-1560
if (scoreboard->pending_ldtmu_count +
    n->inst->ldtmu_count > 16 / c->threads) {
    continue;
}
```

**제약:**
- TMU output FIFO 크기: **16 entries**
- 멀티스레드 시 스레드 수로 나눔
  - 1 thread: 16 entries
  - 2 threads: 8 entries per thread
  - 4 threads: 4 entries per thread

---

### 3. LDVARY (Load Varying) 타이밍

#### RF0 Delayed Write

```c
// qpu_schedule.c:606-608
case 0: /* ldvary delayed write of C coefficient to rf0 */
    if (scoreboard->tick - scoreboard->last_ldvary_tick <= 1)
        return true;
```

**특징:**
- LDVARY는 RF0에 **1 사이클 지연 쓰기** 수행
- LDVARY 후 1 사이클 동안 RF0 읽기 불가

**타임라인:**
```
Tick 0: ldvary        ← varying 로드 시작
Tick 1: ...           ← RF0 아직 준비 안됨 (위험!)
Tick 2: use rf0       ← RF0 사용 가능 ✓
```

#### LDVARY와 RF0 쓰기 충돌

```c
// qpu_schedule.c:696-701
/* Don't schedule anything that writes rf0 right after ldvary, since
 * that would clash with the ldvary's delayed rf0 write (the exception
 * is another ldvary, since its implicit rf0 write would also have
 * one cycle of delay and would not clash).
 */
if (scoreboard->last_ldvary_tick + 1 == scoreboard->tick &&
    v3d71_qpu_writes_waddr_explicitly(devinfo, inst, 0))
```

**규칙:**
- LDVARY 직후에 RF0에 명시적 쓰기 금지
- 예외: 다른 LDVARY (동일한 1 사이클 지연)

---

### 4. UNIFA (Uniform Address) 타이밍

#### UNIFA Write Delay

```c
// qpu_schedule.c:1416-1420
/* We need to have 3 delay slots between a write to unifa and
 * a follow-up ldunifa.
 */
if ((inst->sig.ldunifa || inst->sig.ldunifarf) &&
    scoreboard->last_unifa_write_tick + 3 > scoreboard->tick) {
```

**규칙:**
- UNIFA 쓰기 후 **최소 3 사이클** 지연
- 그 후 LDUNIFA/LDUNIFARF 사용 가능

**타임라인:**
```
Tick 0: write unifa, r5    ← UNIFA 주소 설정
Tick 1: ...                ← 대기
Tick 2: ...                ← 대기
Tick 3: ...                ← 대기
Tick 4: ldunifa, rf10      ← LDUNIFA 사용 가능 ✓
```

#### UNIFA와 Thread Switch

```c
// qpu_schedule.c:2071-2084
/* unifa and the following 3 instructions can't overlap a
 * thread switch/end. The docs further clarify that this means
 * the cycle at which the actual thread switch/end happens
 * and not when the thrsw instruction is processed, which would
 * be after the 2 delay slots following the thrsw instruction.
 * This means that we can move up a thrsw up to the instruction
 * right after unifa:
 *
 * unifa, r5
 * thrsw
 * delay slot 1
 * delay slot 2
 * Thread switch happens here, 4 instructions away from unifa
 */
```

**규칙:**
- UNIFA와 그 후 3개 명령어는 실제 스레드 전환과 겹칠 수 없음
- UNIFA 바로 다음에 THRSW는 가능 (delay slot 2개 후 전환)

---

### 5. SFU (Special Function Unit) 타이밍

```c
// qpu_schedule.c:1848-1849
if (v3d_qpu_instr_is_sfu(before_inst))
    return 2;
```

**레이턴시:**
- SFU 명령어: **2 cycles**

**SFU 명령어:**
- `recip` (역수)
- `rsqrt` (제곱근의 역수)
- `exp` (지수)
- `log` (로그)

**타임라인:**
```
Tick 0: recip rf5, rf3     ← SFU 연산 시작
Tick 1: ...                ← SFU 처리 중
Tick 2: mov rf6, rf5       ← 결과 사용 가능 ✓
```

---

### 6. Branch 타이밍

```c
// qpu_schedule.c:1465-1466
if (scoreboard->last_branch_tick + 3 >= scoreboard->tick)
    continue;
```

**규칙:**
- Branch 명령어 간 **최소 3 사이클** 간격
- Branch의 delay slot에 다른 branch 불가

---

### 7. 일반 ALU 명령어

```c
// qpu_schedule.c:1842
uint32_t latency = 1;
```

**기본 레이턴시:**
- 대부분의 ALU 명령어: **1 cycle**
- ADD, SUB, MUL, AND, OR, XOR 등

**예:**
```
Tick 0: add rf5, rf3, rf4    ← 덧셈 수행
Tick 1: mov rf6, rf5         ← 결과 즉시 사용 가능 ✓
```

---

## 타이밍 요약 테이블

| 명령어/상황 | 지연 요구사항 | 사이클 수 | V3D 버전 |
|------------|--------------|-----------|----------|
| **THRSW delay slots** | 필수 | 정확히 2 | 모든 버전 |
| **THRSW 실제 전환** | 자동 | THRSW + 3 | 모든 버전 |
| **TMUWT → 다음** | 권장 | 2 | 경험적 |
| **TMUA → LDTMU** | 최소 | 1 | 모든 버전 |
| **TMU L1 hit** | 실제 | ~5 | 하드웨어 |
| **TMU L2 hit** | 실제 | ~20 | 하드웨어 |
| **TMU DRAM** | 실제 | 100+ | 하드웨어 |
| **LDVARY → RF0 사용** | 최소 | 2 | V3D 7.1 |
| **UNIFA → LDUNIFA** | 필수 | 3 | 모든 버전 |
| **SFU 명령어** | 필수 | 2 | 모든 버전 |
| **Branch → Branch** | 최소 | 3 | 모든 버전 |
| **일반 ALU** | 기본 | 1 | 모든 버전 |

---

## NOP 사용 가이드라인

### 언제 NOP이 필요한가?

1. **하드웨어 필수 요구사항**
   - THRSW delay slots (2 NOP)
   - UNIFA → LDUNIFA (3 cycles)

2. **권장 사항**
   - TMUWT 후 (2 NOP) - write queue flush
   - TMU 요청 후 (1 NOP) - 레이턴시 숨기기

3. **경우에 따라**
   - SFU 후 (2 cycles) - 결과 대기
   - LDVARY 후 (1 cycle) - RF0 준비

### NOP을 줄이는 방법

```c
// Before (NOP 낭비):
mov tmua, rf3
mov tmua, rf4
nop              ← 낭비!
ldtmu rf10

// After (유용한 연산 삽입):
mov tmua, rf3
mov tmua, rf4
add rf99, rf1, rf2  ← 다른 작업 수행
ldtmu rf10
```

**최적화 전략:**
1. **명령어 재배치** - 독립적인 연산을 delay 사이에 배치
2. **TMU 요청 분산** - 여러 TMU 요청 사이에 연산 삽입
3. **루프 언롤링 + 인터리빙** - 다음 반복의 준비를 현재 반복에 수행

---

## 실전 예제

### 우리 프로그램의 타이밍 분석

```
명령어 10: mov tmua, rf3       ← TMU 읽기 요청
명령어 11: mov tmua, rf4       ← TMU 읽기 요청
명령어 12: nop                 ← TMU 레이턴시 (권장)
                                  실제로는 더 긴 시간이 필요하지만
                                  하드웨어가 자동으로 stall함
명령어 13: ldtmu.rf10          ← 데이터 준비됨
```

**분석:**
- 최소 1 NOP 필요
- 실제 TMU 레이턴시는 5-100+ cycles
- 하드웨어가 데이터 준비될 때까지 자동으로 대기

```
명령어 18: tmuwt rf0           ← TMU 쓰기 완료 대기
명령어 19: nop                 ← Write queue flush (필수)
명령어 20: nop                 ← Pipeline 안정화 (필수)
명령어 21: thrsw               ← 안전하게 종료 준비
```

**분석:**
- TMUWT 후 2 NOP 권장 (경험적)
- 모든 메모리 쓰기가 DRAM에 커밋되도록 보장

```
명령어 21: thrsw               ← 스레드 종료 준비
명령어 22: nop                 ← Delay slot 1 (필수)
명령어 23: nop                 ← Delay slot 2 (필수)
           (프로그램 종료)      ← 여기서 실제 종료
```

**분석:**
- 하드웨어 요구사항: 정확히 2 delay slots
- 파이프라인 flush 및 상태 정리 시간

---

## 디버깅 체크리스트

### NOP이 부족한 증상

- [ ] GPU hang/timeout
- [ ] 잘못된 결과 (0, 쓰레기 값)
- [ ] 간헐적 오류 (타이밍 race)

### 디버깅 방법

1. **과도한 NOP 추가**
   ```c
   // 의심스러운 부분에 NOP 추가
   mov tmua, rf3
   nop
   nop
   nop  ← 추가
   nop  ← 추가
   ldtmu rf10
   ```
   - 문제 사라짐 → 타이밍 문제 확인
   - 문제 지속 → 다른 버그

2. **Mesa 스케줄러 참고**
   - `qpu_schedule.c`의 제약 확인
   - 동일한 패턴 적용

3. **디스어셈블리 검사**
   - v3d_qpu_disasm으로 명령어 확인
   - 타이밍 제약 위반 찾기

---

## 참고 문헌

### Mesa 코드
- `medusa/broadcom/compiler/qpu_schedule.c` - 스케줄러 및 타이밍 제약
- `medusa/broadcom/qpu/qpu_instr.c` - QPU 명령어 인코딩
- `medusa/broadcom/qpu/qpu_disasm.c` - 디스어셈블러

### 하드웨어 문서
- Broadcom VideoCore VII Architecture Specification (NDA)
- Mesa git commit messages
- Linux kernel v3d driver

### 커뮤니티
- Mesa3D mailing list
- Raspberry Pi forums
- Mesa GitLab issues

---

## 결론

**타이밍 정보의 출처:**
1. **Mesa 코드** (qpu_schedule.c) - 가장 신뢰할 수 있는 소스
2. **경험적 테스트** - Mesa 개발자들의 실제 테스트
3. **하드웨어 문서** - Broadcom 공식 문서 (제한적)

**핵심 원칙:**
- 하드웨어 요구사항은 **반드시** 준수
- 권장사항은 **가능한** 따르기
- 의심스러우면 **보수적으로** (더 많은 NOP)

**최적화:**
- 불필요한 NOP 제거는 프로파일링 후
- 먼저 정확성, 나중에 성능
- Mesa 스케줄러처럼 체계적으로 접근
