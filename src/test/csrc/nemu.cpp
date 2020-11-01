#include "common.h"
#include "difftest.h"
#include "ram.h"
#include <dlfcn.h>

Nemu::Nemu(ram_c *ram){
//[TODO]? add init reg to args?
#ifndef NEMU_SO
    #error Please define NEMU_SO to the path of NEMU shared object file
#endif

    void *handle;
    handle = dlopen(NEMU_SO, RTLD_LAZY | RTLD_DEEPBIND);
    assert(handle);

    ref_memcpy_from_dut = (void (*)(wlen_t, void *, int))dlsym(handle, "difftest_memcpy_from_dut");
    assert(ref_memcpy_from_dut);

    ref_getregs = (void (*)(void *))dlsym(handle, "difftest_getregs");
    assert(ref_getregs);

    ref_setregs = (void (*)(const void *))dlsym(handle, "difftest_setregs");
    assert(ref_setregs);

    ref_step = (void (*)(int))dlsym(handle, "difftest_exec");
    assert(ref_step);

    ref_init = (void (*)(void))dlsym(handle, "difftest_init");
    assert(ref_init);

    ref_init();
    ref_memcpy_from_dut(START_ADDR, ram->get_img_start(), ram->get_img_size());

    //[TODO] init regs, using setregs

    //[TEST] above functions
    /*
    printf("kernel size:%d\n", ram->get_img_size());
    for(int i=0;i<20;i++)
        printf("0x%08x: 0x%08x\n", START_ADDR + 0x4*i, *(uint32_t *)(ram->get_img_start() + 0x4*i) );


    for(int i=0;i<NUM_REGS;i++) { regfile[i]=0; }    
    regfile[4] = 0x11111001;
    regfile[7] = 0x23456789;
    regfile[THIS_PC] = START_ADDR;

    ref_setregs(regfile);

    regfile[4] = regfile[7] = 0;
    ref_getregs(regfile);


    printf("nemu_init\n"); dump(); 
*/
}

int Nemu::get_cycle_cnt() { return cycle_cnt; }

void Nemu::step(int n){
    cycle_cnt += n;
    ref_step(n);
    get_difftest_result();
}

void Nemu::get_difftest_result(){

    ref_getregs(regfile);

    wlen_t next_pc = regfile[THIS_PC];
    regfile[THIS_PC] = nemu_this_pc;
    nemu_this_pc = next_pc;

}

void Nemu::set_difftest_status(){
    ref_setregs(regfile);
    nemu_this_pc = regfile[THIS_PC];
}
