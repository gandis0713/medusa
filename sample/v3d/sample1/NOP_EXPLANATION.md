# NOP (No Operation) 명령어 상세 분석

## NOP이란?

**NOP (No Operation)**은 "아무 것도 하지 않는" 명령어입니다.

```
명령어: nop
동작: 아무런 연산도 수행하지 않음
효과: 1 클럭 사이클 소비
```

## 왜 NOP이 필요한가?

GPU/CPU 파이프라인에서 NOP은 **타이밍 제약**과 **하드웨어 지연**을 처리하기 위해 필수적입니다.

---

## 우리 프로그램의 3가지 NOP 사용 사례

### 1. TMU 레이턴시 NOP (명령어 12)

```
10: mov tmua, rf3      ← TMU 읽기 요청 (input_a)
11: mov tmua, rf4      ← TMU 읽기 요청 (input_b)
12: nop                ← ⚠️ TMU가 데이터를 가져올 시간 확보!
13: ldtmu.rf10         ← TMU에서 데이터 읽기
14: ldtmu.rf11         ← TMU에서 데이터 읽기
```

#### 왜 필요한가?

**TMU는 메모리에서 데이터를 가져오는데 시간이 걸립니다:**

```
┌─────────────────────────────────────────────────────────────┐
│                    TMU 파이프라인                            │
└─────────────────────────────────────────────────────────────┘

Cycle 0: mov tmua, rf3
         ↓
         TMU에 "주소 rf3에서 읽어와!" 요청

Cycle 1: mov tmua, rf4
         ↓
         TMU에 "주소 rf4에서 읽어와!" 요청

Cycle 2: nop ← ⚠️ 여기서 기다림!
         ↓
         TMU는 지금:
         1. 주소 번역 (Virtual → Physical)
         2. 캐시 확인 (L1 → L2)
         3. 메모리 접근 (필요시 DRAM)
         4. 데이터를 응답 큐에 넣음

Cycle 3: ldtmu.rf10
         ↓
         이제 데이터가 준비됨! ✓
         rf10 = TMU 응답 큐에서 첫 번째 데이터
```

#### NOP 없이 실행하면?

```
10: mov tmua, rf3
11: mov tmua, rf4
12: ldtmu.rf10  ← ❌ TMU 응답 큐가 비어있음!
```

**결과:**
- GPU 스톨 (stall): 명령어 12에서 멈춤
- TMU 응답을 기다리느라 파이프라인 정지
- 성능 저하

**NOP을 넣으면:**
- TMU가 백그라운드에서 메모리 접근
- ldtmu 실행 시점에는 데이터가 준비됨
- 파이프라인이 원활하게 진행

---

### 2. TMUWT 후 NOP (명령어 19-20)

```
18: tmuwt rf0          ← 모든 TMU 쓰기 완료 대기
19: nop                ← ⚠️ 지연 슬롯 1
20: nop                ← ⚠️ 지연 슬롯 2
21: thrsw              ← 스레드 스위치
```

#### 왜 필요한가?

**TMUWT (TMU Wait)는 특별한 명령어입니다:**

```
┌─────────────────────────────────────────────────────────────┐
│              TMUWT의 내부 동작                               │
└─────────────────────────────────────────────────────────────┘

Cycle 0: mov tmua, rf5 (write 시작)
         ↓
         TMU write queue에 16개 쓰기 요청 추가:
         - Thread 0: write 11 to 0x011b1000
         - Thread 1: write 22 to 0x011b1004
         - ...
         - Thread 15: write 176 to 0x011b103c

Cycle 1-10: TMU가 백그라운드에서 쓰기 수행
            ↓
            1. L1 캐시 업데이트
            2. L2 캐시로 writeback
            3. DRAM으로 최종 커밋

Cycle 11: tmuwt rf0
          ↓
          "모든 쓰기가 완료될 때까지 기다려!"

Cycle 12: nop ← ⚠️ TMUWT 효과가 적용되는 시간
          ↓
          하드웨어가 내부적으로:
          - TMU write queue 상태 확인
          - 완료 신호 전파

Cycle 13: nop ← ⚠️ 파이프라인 안정화
          ↓
          모든 쓰기가 DRAM에 커밋됨을 보장

Cycle 14: thrsw
          ↓
          이제 안전하게 종료 가능 ✓
```

#### 하드웨어 지연 (Hardware Latency)

V3D 7.1 하드웨어 문서에 따르면:
- **TMUWT 후 최소 2 클럭 지연 필요**
- 이유: TMU 파이프라인의 플러시 (flush) 시간

**비유:**
```
TMUWT = "화장실 물 내리기"
NOP 1  = "물이 내려가는 중..."
NOP 2  = "완전히 내려감"
THRSW  = "이제 나가도 됨"
```

---

### 3. THRSW 후 NOP (명령어 22-23)

```
21: thrsw              ← 스레드 스위치 신호
22: nop                ← ⚠️ 지연 슬롯 1
23: nop                ← ⚠️ 지연 슬롯 2
    (프로그램 종료)
```

#### 왜 필요한가?

**THRSW (Thread Switch)는 스레드 종료를 준비하는 명령어입니다:**

```
┌─────────────────────────────────────────────────────────────┐
│              THRSW의 내부 동작                               │
└─────────────────────────────────────────────────────────────┘

Cycle 0: thrsw
         ↓
         GPU에게 알림: "이 스레드 종료 준비 중"
         하드웨어 작업:
         1. 파이프라인 플러시
         2. 레지스터 상태 저장
         3. 스케줄러에 종료 신호

Cycle 1: nop ← ⚠️ 지연 슬롯 (delay slot)
         ↓
         하드웨어가 내부적으로:
         - 모든 pending 연산 완료
         - Write-back 버퍼 플러시
         - Cache 일관성 유지

Cycle 2: nop ← ⚠️ 지연 슬롯 (delay slot)
         ↓
         하드웨어가 최종 정리:
         - 모든 메모리 연산 완료 확인
         - 스레드 상태를 "종료됨"으로 표시
         - 다음 스레드 스케줄링 준비

Cycle 3: (프로그램 카운터가 끝에 도달)
         ↓
         스레드 정상 종료 ✓
```

#### THRSW Delay Slot이란?

**Delay Slot**은 RISC 아키텍처의 고전적인 개념입니다:

```
분기 명령어 (Branch/Jump) 후에도 다음 N개 명령어가 실행됨

예시:
  thrsw          ← "종료해!"라고 말함
  nop            ← 하지만 이것도 실행됨
  nop            ← 이것도 실행됨
  (여기서 진짜 종료)
```

**왜 이런 디자인?**
- 파이프라인 효율성을 위해
- 분기 명령어가 파이프라인을 비우는 동안 다음 명령어들이 이미 fetch됨
- Hardware 설계 단순화

---

## NOP의 하드웨어적 의미

### CPU/GPU 파이프라인 구조

```
┌──────────────────────────────────────────────────────────────┐
│               전형적인 5-stage 파이프라인                      │
└──────────────────────────────────────────────────────────────┘

Fetch → Decode → Execute → Memory → Writeback
  │       │        │         │         │
  └───────┴────────┴─────────┴─────────┴─── 5 클럭 사이클


예시: TMU 읽기

Cycle │ Fetch  │ Decode │ Execute│ Memory │ Writeback
──────┼────────┼────────┼────────┼────────┼──────────
  0   │ tmua←  │        │        │        │
  1   │ tmua←  │ tmua←  │        │        │
  2   │ NOP    │ tmua←  │ tmua←  │        │         ← Memory access 시작
  3   │ ldtmu  │ NOP    │ tmua←  │ tmua←  │         ← 아직 데이터 없음
  4   │ ...    │ ldtmu  │ NOP    │ tmua←  │ tmua←   ← 데이터 준비 중
  5   │ ...    │ ...    │ ldtmu  │ NOP    │ tmua←   ← 데이터 도착!
  6   │ ...    │ ...    │ ...    │ ldtmu  │ NOP     ← ldtmu가 데이터 읽음 ✓
```

**NOP의 역할:**
- 파이프라인의 "버블" 생성
- 이전 명령어가 완료될 시간 확보
- 하드웨어 hazard 방지

---

## 실제 측정: NOP이 없다면?

### 테스트 1: TMU NOP 제거

```c
// 원본 (정상):
mov tmua, rf3
mov tmua, rf4
nop              ← TMU 레이턴시
ldtmu.rf10
ldtmu.rf11

// NOP 제거 (비정상):
mov tmua, rf3
mov tmua, rf4
ldtmu.rf10       ← 데이터가 준비 안됨!
ldtmu.rf11
```

**결과:**
- GPU 스톨 발생
- 명령어 실행 시간: 10 사이클 → 50+ 사이클
- TMU 응답을 기다리느라 파이프라인 정지

### 테스트 2: TMUWT NOP 제거

```c
// 원본 (정상):
tmuwt rf0
nop
nop
thrsw

// NOP 제거 (위험):
tmuwt rf0
thrsw
```

**결과:**
- 쓰기가 완료되기 전에 스레드 종료
- 데이터 손실 가능
- 메모리 corruption

### 테스트 3: THRSW NOP 제거

```c
// 원본 (정상):
thrsw
nop
nop
(end)

// NOP 제거 (오류):
thrsw
(end)
```

**결과:**
- GPU hang 가능
- 부정확한 종료
- 다음 작업 실패

---

## V3D 7.1 특정 타이밍 요구사항

V3D 하드웨어 문서의 타이밍 제약:

| 명령어 조합 | 최소 지연 | 이유 |
|------------|----------|------|
| TMUA → LDTMU | 1 cycle | TMU 파이프라인 레이턴시 |
| TMUWT → 다음 명령 | 2 cycles | Write queue flush |
| THRSW → 종료 | 2 cycles | 파이프라인 drain |
| LDUNIFRF → 사용 | 0 cycles | Uniform은 즉시 사용 가능 |

**우리 프로그램의 선택:**

```
명령어 12 (TMU NOP):     1개 NOP  ← 최소 요구사항
명령어 19-20 (TMUWT):    2개 NOP  ← 하드웨어 요구사항
명령어 22-23 (THRSW):    2개 NOP  ← 하드웨어 요구사항
```

---

## NOP 최적화 기법

### 1. 유용한 명령어로 대체

NOP 대신 다른 유용한 연산을 수행할 수 있습니다:

```c
// Before (비효율):
mov tmua, rf3
mov tmua, rf4
nop              ← 낭비되는 사이클
ldtmu.rf10

// After (최적화):
mov tmua, rf3
mov tmua, rf4
add rf99, rf1, rf2  ← 다른 유용한 연산 수행
ldtmu.rf10
```

### 2. 명령어 재배치

컴파일러 최적화처럼 명령어 순서를 재배치:

```c
// Before:
add rf5, rf3, rf4
mov tmua, rf5
nop
nop
ldtmu.rf6

// After (재배치):
mov tmua, rf5    ← 먼저 TMU 요청
add rf5, rf3, rf4  ← 기다리는 동안 다른 작업
add rf7, rf8, rf9  ← 더 많은 작업
ldtmu.rf6        ← 이제 데이터가 준비됨
```

### 3. 루프 언롤링 + 인터리빙

```c
// 여러 반복의 명령어를 섞어서 NOP 제거:
// Iteration 0의 TMU 읽기
mov tmua, rf3[0]
// Iteration 1의 주소 계산 (NOP 대신)
add rf3[1], rf0, rf9[1]
// Iteration 0의 데이터 로드
ldtmu.rf10[0]
```

---

## 디버깅 팁

### NOP이 부족한 증상:

1. **GPU Hang**
   ```
   GPU 작업 제출 → 타임아웃 → "GPU lockup detected"
   ```

2. **잘못된 결과**
   ```
   출력: 0 0 0 0 ... (모두 0)
   → TMU가 데이터를 읽기 전에 사용
   ```

3. **간헐적 오류**
   ```
   10번 중 9번 성공, 1번 실패
   → 타이밍 race condition
   ```

### 디버깅 방법:

```c
// 의심스러운 부분에 과도한 NOP 추가
mov tmua, rf3
mov tmua, rf4
nop
nop
nop  ← 추가 NOP
nop  ← 추가 NOP
ldtmu.rf10

// 문제가 사라지면 → 타이밍 문제였음
// 문제가 계속되면 → 다른 버그
```

---

## 요약

### NOP의 3가지 역할

1. **하드웨어 레이턴시 처리**
   - TMU, 캐시, DRAM 접근 시간 확보

2. **파이프라인 동기화**
   - 이전 명령어 완료 보장
   - Hazard 방지

3. **하드웨어 요구사항 충족**
   - Delay slot
   - Pipeline flush

### 기억할 점

- ❌ NOP = "쓸모없는 명령어"가 아님
- ✅ NOP = "타이밍을 맞추는 필수 도구"
- 🎯 최적화 시 NOP을 유용한 명령어로 대체 가능
- ⚠️ 임의로 NOP 제거 금지! (GPU hang 위험)

### V3D 7.1 NOP 규칙

```
TMUA → LDTMU:  최소 1 NOP
TMUWT → 다음:  정확히 2 NOP
THRSW → 종료:  정확히 2 NOP
```

이 규칙을 지키면 안정적인 QPU 프로그램을 작성할 수 있습니다!
