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
    ram_c *ram = new ram_c(argv[1]);
    Verilator *verilator = new Verilator(ram);
    Nemu *nemu = new Nemu(ram);




    while(!Verilated::gotFinish()){
        verilator->step(1);
        nemu->step(1);

        verilator->dump();

        //[TODO] if result not the same

        main_time ++;
    }
#if VM_COVERAGE
    Verilated::mkdir("logs");
    VerilatedCov::write("logs/coverage.dat");
#endif

    delete ram;
    delete verilator;
    delete nemu;
    exit 0;
}