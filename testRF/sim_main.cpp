#include <verilated.h>
#include <iostream>
#include "VRegFile.h"
using namespace std;

VRegFile *top;
uint64_t main_time = 0;    

double sc_time_stamp () {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
}		                        // what SystemC does


int main(int argc, char** argv, char** env) {
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top = new VRegFile;
	top->reset = 1;
	
	while (!Verilated::gotFinish()) {
		if(main_time > 4)
			top->reset = 0;
		if(main_time % 2 == 1)
			top->clock = 1;
		if(main_time % 2 == 0)
			top->clock = 0;

		top->io_waddr = main_time % 32;
		top->io_wen = 1;
		top->io_wdata = main_time;

		top->io_rs1_addr = main_time % 32 - 1;
		top->io_rs2_addr = main_time % 32 ;

		top->eval();
		printf("%lu:\t clk:%u\t rst:%u\t raddr1:%u\t rdata1:%lu\t raddr2:%u\t rdata2:%lu\t \n",
				main_time, top->clock, top->reset, top->io_rs1_addr, top->io_rs1_data, \
				 top->io_rs2_addr, top->io_rs2_data);
		main_time ++;
		if(main_time > 100){
			break;
		}

	}
	top->final();
	delete top;
	exit(0);
}
