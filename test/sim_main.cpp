// outdated version, for testing ALU and RegFile
#include <verilated.h>
#include <iostream>
#include "VTop.h"
#include "verilated_vcd_c.h"
using namespace std;

VTop *top;
uint64_t main_time = 0;    

double sc_time_stamp () {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
}		                        // what SystemC does

#define REGFILE
//#define ALU

int main(int argc, char** argv, char** env) {
	Verilated::traceEverOn(true);
	Verilated::commandArgs(argc, argv);

	Verilated::mkdir("logs");
	top = new VTop;

	top->reset = !0;
	top->clock = 1;
#ifdef REGFILE	
	for(int i=0; i < 100; i++){
		main_time ++;
		top->clock = !top->clock;
		top->eval();
		
		main_time ++;
		top->clock = !top->clock;
		if(main_time > 4)	top->reset = 0;		
		
		top->io_waddr = i % 32;
		top->io_wen = 1;
		top->io_wdata = i;

		top->io_rs1_addr = (i - 1) % 32 ;
		top->io_rs2_addr = i % 32 ;

		top->eval();
		// printf("%lu:\t clk:%u\t rst:%u\t raddr1:%u\t rdata1:%lu\t raddr2:%u\t rdata2:%lu\t \n",
		// 		main_time, top->clock, top->reset, top->io_rs1_addr, top->io_rs1_data, \
		// 		 top->io_rs2_addr, top->io_rs2_data);
	}
#endif

#ifdef ALU
	while (!Verilated::gotFinish()) {
		if(main_time > 4) top->reset = 0;
		top->clock = !top->clock;
		top->reset = 0;

		top->io_in1 = main_time;
		top->io_in2 = 5*main_time + 1;
		top->io_opcode = 0;
		printf("result: %lu\n", top->io_out);

		top->eval();
		
		main_time ++;
		if(main_time > 100){
			break;
		}
	}
#endif
	top->final();


#if VM_COVERAGE
    Verilated::mkdir("logs");
    VerilatedCov::write("logs/coverage.dat");
#endif

	delete top;
	exit(0);
}

