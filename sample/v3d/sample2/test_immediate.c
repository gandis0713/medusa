/*
 * 즉시값 테스트 - 메모리 접근 없이 즉시값만 사용
 */
#include "broadcom/common/v3d_device_info.h"
#include "broadcom/qpu/qpu_disasm.h"
#include "broadcom/qpu/qpu_instr.h"
#include <drm-uapi/v3d_drm.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <xf86drm.h>

static uint64_t qpu_code[32];
static int qpu_code_size = 0;

static void emit_qpu_instr(const struct v3d_device_info* devinfo,
                           struct v3d_qpu_instr* instr)
{
    uint64_t packed;
    bool ok = v3d_qpu_instr_pack(devinfo, instr, &packed);
    if (!ok) {
        fprintf(stderr, "Failed to pack QPU instruction\n");
        return;
    }
    qpu_code[qpu_code_size++] = packed;
}

/* 즉시값 10 + 20 = 30을 계산하는 프로그램 */
void generate_immediate_test(const struct v3d_device_info* devinfo)
{
    struct v3d_qpu_instr instr;

    printf("QPU 즉시값 테스트 프로그램 생성 중...\n");

    /* 명령어 1: rf0 = 10 (small immediate) */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.small_imm_b = true;
    instr.raddr_b = 10;
    instr.alu.add.op = V3D_QPU_A_MOV;
    instr.alu.add.b.raddr = 32;  /* special value for small_imm */
    instr.alu.add.waddr = 0;
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /* 명령어 2: rf1 = 20 */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.small_imm_b = true;
    instr.raddr_b = 20;
    instr.alu.add.op = V3D_QPU_A_MOV;
    instr.alu.add.b.raddr = 32;
    instr.alu.add.waddr = 1;
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /* 명령어 3: rf2 = rf0 + rf1 */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.alu.add.op = V3D_QPU_A_ADD;
    instr.alu.add.a.raddr = 0;
    instr.alu.add.b.raddr = 1;
    instr.alu.add.waddr = 2;
    instr.alu.add.magic_write = false;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /* 명령어 4: thrsw */
    memset(&instr, 0, sizeof(instr));
    instr.type = V3D_QPU_INSTR_TYPE_ALU;
    instr.sig.thrsw = true;
    instr.alu.add.op = V3D_QPU_A_NOP;
    instr.alu.mul.op = V3D_QPU_M_NOP;
    emit_qpu_instr(devinfo, &instr);

    /* 명령어 5-6: NOP (delay slots) */
    for (int i = 0; i < 2; i++) {
        memset(&instr, 0, sizeof(instr));
        instr.type = V3D_QPU_INSTR_TYPE_ALU;
        instr.alu.add.op = V3D_QPU_A_NOP;
        instr.alu.mul.op = V3D_QPU_M_NOP;
        emit_qpu_instr(devinfo, &instr);
    }

    printf("QPU 프로그램 생성 완료: %d 명령어\n\n", qpu_code_size);
}

void disassemble_qpu_program(const struct v3d_device_info* devinfo)
{
    printf("=== QPU 프로그램 디스어셈블 ===\n");
    for (int i = 0; i < qpu_code_size; i++) {
        printf("%2d: 0x%016lx  ", i, qpu_code[i]);
        const char* disasm = v3d_qpu_disasm(devinfo, qpu_code[i]);
        printf("%s\n", disasm);
    }
    printf("\n");
}

int main(void)
{
    struct v3d_device_info devinfo = { .ver = 71 };

    generate_immediate_test(&devinfo);
    disassemble_qpu_program(&devinfo);

    printf("이 프로그램은 rf2 = 10 + 20 = 30을 계산합니다.\n");
    printf("(실제 GPU 실행은 하지 않음)\n");

    return 0;
}
