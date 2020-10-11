#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <stdint.h>
#include "common.h"
#include "ram.h"
#include "VTop.h"
#include "verilated_vcd_c.h"

enum {
    // 0~31 GPRs
    THIS_PC = 32,
    NUM_REGS
};


class difftest {
public:
    wlen_t regfile[NUM_REGS];

    void dump();
}

class Nemu: public difftest {
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

    ram_c *ram;
    int cycle_cnt;
    wlen_t nemu_this_pc;
    void get_difftest_result();
}


class Verilator: public difftest {
public:
    Verilator(ram_c *ram);
    ~Verilator();
    void step(int n);
    int get_cycle_cnt();

private:
    ram_c *ram;
    int cycle_cnt;
    long *main_time;
    VTop *top;
    //[TODO] add waveform

    struct debug_IO{
        wlen_t waddr; // 5-bit wide, for 32 GPRs
        wlen_t wdata;
        bool wen;
    };
    struct debug_IO wb;

    struct memread_req{
        wlen_t addr;
        bool en;
    }
    struct memread_req imem_buf, dmem_buf;


    void get_difftest_result();
    void eval_ram();
}


#endif