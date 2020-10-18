#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <stdint.h>
#include "common.h"
#include "ram.h"
#include "VTop.h"
#include "verilated_vcd_c.h"

// 0~31: GPRs
enum {
  THIS_PC = 32,
#ifndef __RV32__
  DIFFTEST_MSTATUS,
  DIFFTEST_MCAUSE,
  DIFFTEST_MEPC,
  DIFFTEST_SSTATUS,
  DIFFTEST_SCAUSE,
  DIFFTEST_SEPC,
#endif
  NUM_REGS
};

extern const char *reg_name[NUM_REGS]; 

class Difftest {
public:
    wlen_t regfile[NUM_REGS];

    void dump();
};

class Nemu: public Difftest {
public:
    Nemu(ram_c *ram);
    void step(int n);
    int get_cycle_cnt();
    void set_difftest_status();

private:

    void (*ref_memcpy_from_dut)(wlen_t dest, void *src, int n);
    void (*ref_getregs)(void *c);
    void (*ref_setregs)(const void *c);
    void (*ref_step)(int n);
    void (*ref_init)(void);

    //ram_c *ram;
    int cycle_cnt = 0;
    wlen_t nemu_this_pc = START_ADDR;
    void get_difftest_result();
};


class Verilator: public Difftest {
public:
    Verilator(ram_c *ram, uint64_t *main_time);
    ~Verilator();
    void step(int n);

private:
    ram_c *ram;
    uint64_t *main_time;    // to change main_time in sim_main.cpp

    VTop *top;
    //[TODO] add waveform

    struct memread_req{
        bool has;
        wlen_t addr;
    };
    uint32_t readinst(wlen_t addr);
    struct memread_req imem_buf, dmem_buf;

    void get_difftest_result();
    void single_cycle();
    void eval_ram();
};

#endif