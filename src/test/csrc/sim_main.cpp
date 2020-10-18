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

    //while(!Verilated::gotFinish()){
    for(int i=0;i<10;i++){
        verilator->step(1);
        nemu->step(1); 

        // printf("VERILATOR");
        // verilator->dump();
        // printf("NEMU     ");
        // nemu->dump();

        // difftest
        //[TEST] GPRs only
        bool diff = false;
        for(int i=0; i<THIS_PC+1; i++){
            if(verilator->regfile[i] != nemu->regfile[i]){
                printf("\n ================= Reg Diff =================\n");
                printf("nemu_pc:\t %016lx\nverilator_pc:\t %016lx\n%s:\n nemu:\t\t %016lx\n verilator:\t %016lx\n", \
                    nemu->regfile[THIS_PC], verilator->regfile[THIS_PC], reg_name[i], nemu->regfile[i], verilator->regfile[i]);
                diff = true; break;
            }
        }
        //if(diff) break;
        printf("[TEST] %lu\n", main_time);
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