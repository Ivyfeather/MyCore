#include "common.h"
#include "difftest.h"

const char *reg_name[NUM_REGS] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6",
  "this_pc"
#ifndef __RV32__
  ,"mstatus", "mcause", "mepc",
  "sstatus", "scause", "sepc"
#endif
};

void Difftest::dump(){
    printf(" =================  PC = 0x%016lx ================= \n", regfile[THIS_PC]);
    for(int i=0; i<THIS_PC; i+=4){
      //[TEST] print GPRs only
        printf("%s: 0x%016lx\t", reg_name[i],   regfile[i]);
        printf("%s: 0x%016lx\t", reg_name[i+1], regfile[i+1]);
        printf("%s: 0x%016lx\t", reg_name[i+2], regfile[i+2]);
        printf("%s: 0x%016lx\n", reg_name[i+3], regfile[i+3]);
    }
}