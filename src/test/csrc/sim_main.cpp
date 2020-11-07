#include "ram.h"
#include "difftest.h"

#include<iostream>
#include<cstdio>
#include<verilated.h>

uint64_t main_time = 0;
double sc_time_stamp () {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
}		                        // what SystemC does

#define VCD_TRACE
#define RAM_PATH "./testbench/build/add.bin"
// #define RAM_PATH "./testbench/rtthread.bin"

int main(int argc, char **argv){
#ifndef RAM_PATH
    #error Please define RAM_PATH
#endif

#ifdef VCD_TRACE
    Verilated::traceEverOn(true);
#endif
	Verilated::commandArgs(argc, argv);
    ram_c *ram = new ram_c(RAM_PATH);
    Verilator *verilator = new Verilator(ram, &main_time);
    Nemu *nemu = new Nemu(ram);

    // for(int i=0;i<5000;i++){
    for(int i=0; ;i++){
        printf("[TEST] %lu\n", main_time);
        verilator->step(1);
        nemu->step(1); 

        //[TEST] GPRs only
        printf("pc:\t %016lx\n\n", nemu->regfile[THIS_PC]);
        //nemu->dump();

        bool diff = false;
        // compare regs
        
        for(int j=0; j<THIS_PC+1; j++){
            if(verilator->regfile[j] != nemu->regfile[j]){
                printf("\n ================= Reg Diff =================\n");
                printf("nemu_pc:\t %016lx\nverilator_pc:\t %016lx\n%s:\n nemu:\t\t %016lx\n verilator:\t %016lx\n", \
                    nemu->regfile[THIS_PC], verilator->regfile[THIS_PC], reg_name[j], nemu->regfile[j], verilator->regfile[j]);
                diff = true;
                                
                printf("VERILATOR");
                verilator->dump();
                printf("NEMU     ");
                nemu->dump();

                break;
            }
        }
        

        if(verilator->hit_trap()){
            verilator->step(1);
            nemu->step(1); 
            break;
        }

        if(diff) break;

    }
#if VM_COVERAGE
    Verilated::mkdir("logs");
    VerilatedCov::write("logs/coverage.dat");
#endif

    delete ram;
    delete verilator;
    delete nemu;
    exit(0);
}