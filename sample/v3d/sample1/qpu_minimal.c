/*
 * 최소한의 QPU 프로그램 예제
 *
 * 단 3개의 명령어로 구성된 가장 간단한 QPU 프로그램:
 * 1. r0 = 42 (즉시값 로드)
 * 2. 스레드 종료
 * 3. NOP (delay slot)
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "broadcom/qpu/qpu_instr.h"
#include "broadcom/common/v3d_device_info.h"

int main(void)
{
    struct v3d_device_info devinfo = {
        .ver = 71,  /* V3D 7.1 */
    };

    struct v3d_qpu_instr instr;
    uint64_t packed;

    printf("최소한의 QPU 프로그램 (3개 명령어)\n");
    printf("====================================\n\n");

    /*
     * 명령어 1: r0 = 42
     * ADD 유닛을 사용하여 레지스터 r0에 42를 로드
     */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;

    /* Small immediate 사용 (V3D 7.x) */
    instr.sig.small_imm_b = true;
    instr.raddr_b = 42;  /* 즉시값 42 */

    /* ADD: r0 = 42 */
    instr.alu.add.op = V3D_QPU_A_MOV;
    instr.alu.add.a.raddr = 0;  /* 사용 안 함 */
    instr.alu.add.b.raddr = 32; /* small_imm_b 사용 시 특수 값 */
    instr.alu.add.waddr = 0;    /* r0에 쓰기 */
    instr.alu.add.magic_write = false;

    /* MUL: NOP */
    instr.alu.mul.op = V3D_QPU_M_NOP;

    if (v3d_qpu_instr_pack(&devinfo, &instr, &packed)) {
        printf("1. r0 = 42\n");
        printf("   인코딩: 0x%016lx\n\n", packed);
    }

    /*
     * 명령어 2: 스레드 종료
     */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.thrsw = true;  /* 스레드 종료 신호 */
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;

    if (v3d_qpu_instr_pack(&devinfo, &instr, &packed)) {
        printf("2. thrsw (스레드 종료)\n");
        printf("   인코딩: 0x%016lx\n\n", packed);
    }

    /*
     * 명령어 3: NOP (delay slot)
     */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;

    if (v3d_qpu_instr_pack(&devinfo, &instr, &packed)) {
        printf("3. nop (delay slot)\n");
        printf("   인코딩: 0x%016lx\n\n", packed);
    }

    printf("====================================\n");
    printf("프로그램 완료!\n");
    printf("\n설명:\n");
    printf("- QPU는 파이프라인 아키텍처이므로\n");
    printf("  thrsw 이후 최소 2개의 명령어 필요\n");
    printf("- 실제 r0의 값은 16개 레인 모두 42\n");
    printf("  (QPU는 16-way SIMD)\n");

    return 0;
}
