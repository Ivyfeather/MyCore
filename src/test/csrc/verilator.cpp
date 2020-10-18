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
    main_time = input_time;
    // init buf
    top->clock = 0;
    top->reset = 1;
    for(int i=0; i<6; i++){
        top->clock = !top->clock;
        top->eval();
        (*main_time) ++;
    }
    top->reset = 0;
    imem_buf.has = false;
    dmem_buf.has = false;

    //for(int i=0;i<20;i++)printf("[TEST]inst_ram: %016lx\n", ram->Memread(START_ADDR+i*4,1));

    single_cycle();
    get_difftest_result();
}

Verilator::~Verilator(){
    top->final();
    delete top;
}


void Verilator::step(int n){
    for(; n>0; n--){
        while(top->io_debug_stall){
            single_cycle();
        }
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


void Verilator::get_difftest_result(){
#define macro(x) regfile[x] = top->io_debug_rf_##x
    //[TEST] GPRs only for now
    macro(0); macro(1); macro(2); macro(3); macro(4); macro(5); macro(6); macro(7);
    macro(8); macro(9); macro(10); macro(11); macro(12); macro(13); macro(14); macro(15);
    macro(16); macro(17); macro(18); macro(19); macro(20); macro(21); macro(22); macro(23);
    macro(24); macro(25); macro(26); macro(27); macro(28); macro(29); macro(30); macro(31);
    regfile[THIS_PC] = top->io_debug_PC;
}

uint32_t Verilator::readinst(wlen_t addr){
#ifdef __RV32__
    return ram->Memread(imem_buf.addr, 1);
#else
    wlen_t inst2 = ram->Memread(imem_buf.addr, 1);
    if(addr % 8 == 0)
        return (uint32_t)inst2;
    else
        return (uint32_t)(inst2 >> 32);
#endif
}

void Verilator::eval_ram(){// here, ram can always resp in 1 cycle
 #if 0
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
    imem_buf.addr = top->io_imem_req_bits_addr; //!FAULT! eval ram before eval top, so ram does not get the new addr
    if(top->io_imem_req_valid) top->io_imem_req_ready = 1; //ready=1 means accept this req

    dmem_buf.en = top->io_dmem_req_valid;
    dmem_buf.addr = top->io_dmem_req_bits_addr;
    if(top->io_dmem_req_valid) top->io_dmem_req_ready = 1;

    //[TODO] write mem has one cycle delay?
    ram->Memwrite(top->io_dmem_req_bits_addr, top->io_dmem_req_bits_data, \
        top->io_dmem_req_valid && top->io_dmem_req_bits_fcn,\
        top->io_dmem_req_bits_msk); // write mem
#endif   
#if 1
    top->io_imem_req_ready = 0;
    top->io_dmem_req_ready = 0;
    top->io_imem_resp_valid = 0;
    top->io_dmem_resp_valid = 0;    

    if(!imem_buf.has && top->io_imem_req_valid){
        imem_buf.addr = top->io_imem_req_bits_addr;
        top->io_imem_req_ready = 1;
        imem_buf.has = true;
    }
    else if(imem_buf.has){
        top->io_imem_resp_bits_data = readinst(imem_buf.addr);
        top->io_imem_resp_valid = 1;
        if(top->io_imem_resp_ready) imem_buf.has = 0;
    }
    printf("[TEST] has:%d cycle: %lu, rd_addr: %016lx\n", imem_buf.has, *main_time, imem_buf.addr);


    if(!dmem_buf.has && top->io_dmem_req_valid){
        dmem_buf.addr = top->io_dmem_req_bits_addr;
        top->io_dmem_req_ready = 1;
        dmem_buf.has = true;
    }
    else if(dmem_buf.has){
        top->io_dmem_resp_bits_data = ram->Memread(dmem_buf.addr, 1);
        top->io_dmem_resp_valid = 1;
        if(top->io_dmem_resp_ready) dmem_buf.has = 0;
    }

    ram->Memwrite(top->io_dmem_req_bits_addr, top->io_dmem_req_bits_data, \
        top->io_dmem_req_valid && top->io_dmem_req_bits_fcn,\
        top->io_dmem_req_bits_msk); // write mem
#endif
}