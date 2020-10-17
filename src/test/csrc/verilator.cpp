#include "difftest.h"
#include "VTop.h"
#include "verilated_vcd_c.h"

Verilator::Verilator(ram_c *input_ram, uint64_t *input_time){
    top = new VTop;
    ram = input_ram;
    // init rf
    for(int i=0; i < NUM_REGS; i++) {
        regfile[i] = 0;
    }
    regfile[THIS_PC] = START_ADDR;
    main_time = input_time;
    // init buf
    top->clock = 0;
    top->reset = 1;
    for(int i=0; i<5; i++){
        top->clock = !top->clock;
        top->eval();
        (*main_time) ++;
    }
    top->clock = 0;
    top->reset = 0;

    (*main_time) ++;
    imem_buf.en = false;
    dmem_buf.en = false;

    step(1);
}

Verilator::~Verilator(){
    top->final();
    delete top;
}


void Verilator::step(int n){
    for(; n>0; n--){
        single_cycle();
    }
    get_difftest_result();
}

void Verilator::single_cycle(){
    top->clock = 1;
    eval_ram();
    top->eval();
    (*main_time) ++;
    top->clock = 0;
    top->eval();
    (*main_time) ++;
}


// !caution!: must be used every cycle in order to capture the change
// ?may change to directly reading regs?
// [TODO] change to reading regs
void Verilator::get_difftest_result(){



}

void Verilator::eval_ram(){// here, ram can always resp in 1 cycle
    // set ready signals to zero
    top->io_imem_req_ready = 0;
    top->io_dmem_req_ready = 0;

    // deal with read req last cycle
    top->io_imem_resp_bits_data = ram->Memread(imem_buf.addr, imem_buf.en);
    top->io_imem_resp_valid = imem_buf.en;
    top->io_dmem_resp_bits_data = ram->Memread(dmem_buf.addr, dmem_buf.en);
    top->io_dmem_resp_valid = dmem_buf.en;

    // accept new read req this cycle
    imem_buf.en = top->io_imem_req_valid;
    imem_buf.addr = top->io_imem_req_bits_addr;
    if(top->io_imem_req_valid) top->io_imem_req_ready = 1; //ready=1 means accept this req

    dmem_buf.en = top->io_dmem_req_valid;
    dmem_buf.addr = top->io_dmem_req_bits_addr;
    if(top->io_dmem_req_valid) top->io_dmem_req_ready = 1;

    //[TODO] write mem has one cycle delay?
    ram->Memwrite(top->io_dmem_req_bits_addr, top->io_dmem_resp_bits_data, \
        top->io_dmem_req_valid && top->io_dmem_req_bits_fcn,\
        top->io_dmem_req_bits_msk); // write mem

}