#include "ram.h"
#include "difftest.h"

#include<iostream>
#include<cstdio>
#include<verilated.h>

uint64_t main_time = 0;
double sc_time_stamp () {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
}		                        // what SystemC does

int main(int argc, char **argv){
#ifndef RAM_PATH
    #error Please define RAM_PATH
#endif
    ram_c *ram = new ram_c(RAM_PATH);
    Verilator *verilator = new Verilator(ram);
    Nemu *nemu = new Nemu(ram);




    //while(!Verilated::gotFinish()){
    for(int i=0;i<20;i++){
        verilator->step(1);
        nemu->step(1); 
        //[TEST]
        nemu->dump();
        //verilator->dump();

        // difftest
        //[TEST] GPRs only
        /*
        for(int i=0; i<THIS_PC; i++){
            if(verilator->regfile[i] != nemu->regfile[i]){
                printf("\n ================= Reg Diff =================\n");
                printf("%s: nemu:\t %016lx;\n verilator:\t %016lx\n", \
                    nemu->regfile[i], verilator->regfile[i]);
                break;
            }
        }
        */

        main_time ++;
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