module Top(
  input         clock,
  input         reset,
  input  [5:0]  io_opcode,
  input  [63:0] io_in1,
  input  [63:0] io_in2,
  output [63:0] io_out
);
  wire [63:0] _T_1 = ~io_in2; // @[alu.scala 34:54]
  wire [63:0] _T_3 = _T_1 + 64'h1; // @[alu.scala 34:62]
  wire [63:0] _T_4 = io_opcode[4] ? _T_3 : io_in2; // @[alu.scala 34:35]
  wire [64:0] add_result = io_in1 + _T_4; // @[alu.scala 34:29]
  wire [63:0] xor_result = io_in1 ^ io_in2; // @[alu.scala 35:29]
  wire [63:0] or_result = io_in1 | io_in2; // @[alu.scala 36:29]
  wire [63:0] and_result = io_in1 & io_in2; // @[alu.scala 37:29]
  wire  sltu_result = ~add_result[64]; // @[alu.scala 39:22]
  wire  slt_result = xor_result[63] ^ sltu_result; // @[alu.scala 40:43]
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
        if (_T_26) begin
          $fwrite(32'h80000002,"in1:%d in2:%d opcode:%x adder:%d\
          out:%d\n",io_in1,io_in2,io_opcode,add_result,io_out); // @[alu.scala 56:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
   initial begin
      if ($test$plusargs("trace") != 0) begin
         $display("[%0t] Tracing to logs/vlt_dump.vcd...\n", $time);
         $dumpfile("logs/vlt_dump.vcd");
         $dumpvars();
      end
      $display("[%0t] Model running...\n", $time);
   end

endmodule
