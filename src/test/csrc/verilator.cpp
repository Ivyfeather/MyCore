#include "difftest.h"
#include "VTop.h"
#include "verilated_vcd_c.h"

Verilator::Verilator(ram_c *ram){
    top = new VTop;

    // init rf
    for(int i=0; i < NUM_REGS; i++) {
        regfile[i] = 0;
    }
    regfile[THIS_PC] = START_ADDR;

    // init buf

}

Verilator::~Verilator(){
    top->final();
    delete top;
}


void Verilator::step(int n){
    for(; n>0; n--){


    }
}

void Verilator::single_cycle(){
    top->clock = 1;
    //[TODO] why this eval? can be omitted?
    top->eval();
    eval_ram();
    top->eval();

    top->clock = 0;
    top->eval();
    cycle_cnt ++;
}


// !caution!: must be used every cycle in order to capture the change
// ?may change to directly reading 32 regs?
void Verilator::get_difftest_result(){
    regfile[THIS_PC] = top->io_debug_io_PC;

    // deal with rf change in the previous cycle
    if(wb.wen){
        regfile[wb.waddr] = wb.wdata;
    }
    // get the rf change of this cycle, handle this in the next cycle
    wb.wen    = top->io_debug_io_wen;
    wb.waddr  = top->io_debug_io_waddr;
    wb.wdata  = top->io_debug_io_wdata;
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