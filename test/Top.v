module Top(
  input         clock,
  input         reset,
  input  [5:0]  io_opcode,
  input  [31:0] io_in1,
  input  [31:0] io_in2,
  output [31:0] io_out
);
  wire [31:0] _T_1 = ~io_in2; // @[alu.scala 35:54]
  wire [31:0] _T_3 = _T_1 + 32'h1; // @[alu.scala 35:62]
  wire [31:0] _T_4 = io_opcode[4] ? _T_3 : io_in2; // @[alu.scala 35:35]
  wire [32:0] add_result = io_in1 + _T_4; // @[alu.scala 35:29]
  wire [31:0] xor_result = io_in1 ^ io_in2; // @[alu.scala 36:29]
  wire [31:0] or_result = io_in1 | io_in2; // @[alu.scala 37:29]
  wire [31:0] and_result = io_in1 & io_in2; // @[alu.scala 38:29]
  wire  sltu_result = ~add_result[32]; // @[alu.scala 40:22]
  wire  slt_result = xor_result[31] ^ sltu_result; // @[alu.scala 41:43]
  wire [31:0] _T_8 = {31'h0,sltu_result}; // @[Cat.scala 29:58]
  wire [31:0] _T_9 = {31'h0,slt_result}; // @[Cat.scala 29:58]
  wire [5:0] _T_10 = io_opcode & 6'h1f; // @[Lookup.scala 31:38]
  wire  _T_11 = 6'h12 == _T_10; // @[Lookup.scala 31:38]
  wire  _T_13 = 6'h11 == _T_10; // @[Lookup.scala 31:38]
  wire [5:0] _T_14 = io_opcode & 6'h1; // @[Lookup.scala 31:38]
  wire  _T_15 = 6'h1 == _T_14; // @[Lookup.scala 31:38]
  wire [5:0] _T_16 = io_opcode & 6'h3; // @[Lookup.scala 31:38]
  wire  _T_17 = 6'h2 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_19 = 6'h3 == _T_16; // @[Lookup.scala 31:38]
  wire [5:0] _T_20 = io_opcode & 6'hf; // @[Lookup.scala 31:38]
  wire  _T_21 = 6'h8 == _T_20; // @[Lookup.scala 31:38]
  wire [31:0] _T_22 = _T_21 ? io_in1 : add_result[31:0]; // @[Lookup.scala 33:37]
  wire [31:0] _T_23 = _T_19 ? and_result : _T_22; // @[Lookup.scala 33:37]
  wire [31:0] _T_24 = _T_17 ? or_result : _T_23; // @[Lookup.scala 33:37]
  wire [31:0] _T_25 = _T_15 ? xor_result : _T_24; // @[Lookup.scala 33:37]
  wire [31:0] _T_26 = _T_13 ? _T_9 : _T_25; // @[Lookup.scala 33:37]
  wire  _T_29 = ~reset; // @[alu.scala 57:11]
  assign io_out = _T_11 ? _T_8 : _T_26; // @[alu.scala 47:12]
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_29) begin
          $fwrite(32'h80000002,"in1:%d in2:%d opcode:%x out:%d\n",io_in1,io_in2,io_opcode,io_out); // @[alu.scala 57:11]
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
