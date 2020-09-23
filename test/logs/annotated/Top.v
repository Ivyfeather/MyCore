	// verilator_coverage annotation
	module Top(
 000100	  input         clock,
%000002	  input         reset,
 000190	  input  [4:0]  io_rs1_addr,
 000360	  output [63:0] io_rs1_data,
 000193	  input  [4:0]  io_rs2_addr,
 000364	  output [63:0] io_rs2_data,
 000193	  input  [4:0]  io_waddr,
 000197	  input  [63:0] io_wdata,
%000001	  input         io_wen
	);
	`ifdef RANDOMIZE_MEM_INIT
	  reg [63:0] _RAND_0;
	`endif // RANDOMIZE_MEM_INIT
	  reg [63:0] rf [0:31]; // @[regs.scala 19:17]
 000360	  wire [63:0] rf__T_2_data; // @[regs.scala 19:17]
 000190	  wire [4:0] rf__T_2_addr; // @[regs.scala 19:17]
 000364	  wire [63:0] rf__T_5_data; // @[regs.scala 19:17]
 000193	  wire [4:0] rf__T_5_addr; // @[regs.scala 19:17]
 000197	  wire [63:0] rf__T_data; // @[regs.scala 19:17]
 000193	  wire [4:0] rf__T_addr; // @[regs.scala 19:17]
%000001	  wire  rf__T_mask; // @[regs.scala 19:17]
%000001	  wire  rf__T_en; // @[regs.scala 19:17]
	  wire  _T_1 = io_rs1_addr != 5'h0; // @[regs.scala 22:37]
	  wire  _T_4 = io_rs2_addr != 5'h0; // @[regs.scala 23:37]
	  assign rf__T_2_addr = io_rs1_addr;
	  assign rf__T_2_data = rf[rf__T_2_addr]; // @[regs.scala 19:17]
	  assign rf__T_5_addr = io_rs2_addr;
	  assign rf__T_5_data = rf[rf__T_5_addr]; // @[regs.scala 19:17]
	  assign rf__T_data = io_wdata;
	  assign rf__T_addr = io_waddr;
	  assign rf__T_mask = 1'h1;
	  assign rf__T_en = io_wen;
	  assign io_rs1_data = _T_1 ? rf__T_2_data : 64'h0; // @[regs.scala 22:17]
	  assign io_rs2_data = _T_4 ? rf__T_5_data : 64'h0; // @[regs.scala 23:17]
	`ifdef RANDOMIZE_GARBAGE_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_INVALID_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_REG_INIT
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	`define RANDOMIZE
	`endif
	`ifndef RANDOM
	`define RANDOM $random
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	  integer initvar;
	`endif
	`ifndef SYNTHESIS
	`ifdef FIRRTL_BEFORE_INITIAL
	`FIRRTL_BEFORE_INITIAL
	`endif
%000002	initial begin
	  `ifdef RANDOMIZE
	    `ifdef INIT_RANDOM
	      `INIT_RANDOM
	    `endif
	    `ifndef VERILATOR
	      `ifdef RANDOMIZE_DELAY
	        #`RANDOMIZE_DELAY begin end
	      `else
	        #0.002 begin end
	      `endif
	    `endif
	`ifdef RANDOMIZE_MEM_INIT
	  _RAND_0 = {2{`RANDOM}};
	  for (initvar = 0; initvar < 32; initvar = initvar+1)
	    rf[initvar] = _RAND_0[63:0];
	`endif // RANDOMIZE_MEM_INIT
	  `endif // RANDOMIZE
	end // initial
	`ifdef FIRRTL_AFTER_INITIAL
	`FIRRTL_AFTER_INITIAL
	`endif
	`endif // SYNTHESIS
 000098	  always @(posedge clock) begin
 000098	    if(rf__T_en & rf__T_mask) begin
%000000	    verilator_coverage: (next point on previous line)

 000049	      rf[rf__T_addr] <= rf__T_data; // @[regs.scala 19:17]
	    end
	  end
%000002	   initial begin
%000002	      if ($test$plusargs("trace") != 0) begin
%000000	      verilator_coverage: (next point on previous line)

%000001	         $display("[%0t] Tracing to logs/vlt_dump.vcd...\n", $time);
%000001	         $dumpfile("logs/vlt_dump.vcd");
%000001	         $dumpvars();
	      end
%000001	      $display("[%0t] Model running...\n", $time);
	   end
	endmodule
	
