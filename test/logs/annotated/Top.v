	// verilator_coverage annotation
	module Top(
 000101	  input         clock,
%000000	  input         reset,
%000000	  input  [5:0]  io_opcode,
 000197	  input  [63:0] io_in1,
 000345	  input  [63:0] io_in2,
 000297	  output [63:0] io_out
	);
	  wire [63:0] _T_1 = ~io_in2; // @[alu.scala 34:54]
	  wire [63:0] _T_3 = _T_1 + 64'h1; // @[alu.scala 34:62]
	  wire [63:0] _T_4 = io_opcode[4] ? _T_3 : io_in2; // @[alu.scala 34:35]
 000297	  wire [64:0] add_result = io_in1 + _T_4; // @[alu.scala 34:29]
 000248	  wire [63:0] xor_result = io_in1 ^ io_in2; // @[alu.scala 35:29]
 000179	  wire [63:0] or_result = io_in1 | io_in2; // @[alu.scala 36:29]
 000163	  wire [63:0] and_result = io_in1 & io_in2; // @[alu.scala 37:29]
%000001	  wire  sltu_result = ~add_result[64]; // @[alu.scala 39:22]
%000001	  wire  slt_result = xor_result[63] ^ sltu_result; // @[alu.scala 40:43]
	  wire [63:0] _T_8 = {63'h0,sltu_result}; // @[Cat.scala 29:58]
	  wire [63:0] _T_9 = {63'h0,slt_result}; // @[Cat.scala 29:58]
	  wire  _T_11 = 6'h11 == io_opcode; // @[Lookup.scala 31:38]
	  wire  _T_15 = 6'h1 == io_opcode; // @[Lookup.scala 31:38]
	  wire  _T_17 = 6'h2 == io_opcode; // @[Lookup.scala 31:38]
	  wire  _T_19 = 6'h3 == io_opcode; // @[Lookup.scala 31:38]
	  wire [63:0] _T_20 = _T_19 ? and_result : add_result[63:0]; // @[Lookup.scala 33:37]
	  wire [63:0] _T_21 = _T_17 ? or_result : _T_20; // @[Lookup.scala 33:37]
	  wire [63:0] _T_22 = _T_15 ? xor_result : _T_21; // @[Lookup.scala 33:37]
	  wire [63:0] _T_23 = _T_11 ? _T_9 : _T_22; // @[Lookup.scala 33:37]
	  wire  _T_26 = ~reset; // @[alu.scala 56:11]
	  assign io_out = _T_11 ? _T_8 : _T_23; // @[alu.scala 46:12]
	  always @(posedge clock) begin
	    `ifndef SYNTHESIS
	    `ifdef PRINTF_COND
	      if (`PRINTF_COND) begin
	    `endif
 000050	        if (_T_26) begin
	          $fwrite(32'h80000002,"in1:%d in2:%d opcode:%x adder:%d\
	          out:%d\n",io_in1,io_in2,io_opcode,add_result,io_out); // @[alu.scala 56:11]
	        end
	    `ifdef PRINTF_COND
	      end
	    `endif
	    `endif // SYNTHESIS
	  end
	endmodule
	
