/* verilator lint_off UNUSED */
module Top( // @[:@3.2]
  input         clock, // @[:@4.4]
  input         reset, // @[:@5.4]
  input  [4:0]  io_rs1_addr, // @[:@6.4]
  output [31:0] io_rs1_data, // @[:@6.4]
  input  [4:0]  io_rs2_addr, // @[:@6.4]
  output [31:0] io_rs2_data, // @[:@6.4]
  input  [4:0]  io_waddr, // @[:@6.4]
  input  [31:0] io_wdata, // @[:@6.4]
  input         io_wen // @[:@6.4]
);
  reg [31:0] rf [0:31]; // @[RegFile.scala 19:17:@8.4]
  reg [31:0] _RAND_0;
  wire [31:0] rf__T_24_data; // @[RegFile.scala 19:17:@8.4]
  wire [4:0] rf__T_24_addr; // @[RegFile.scala 19:17:@8.4]
  wire [31:0] rf__T_29_data; // @[RegFile.scala 19:17:@8.4]
  wire [4:0] rf__T_29_addr; // @[RegFile.scala 19:17:@8.4]
  wire [31:0] rf__T_21_data; // @[RegFile.scala 19:17:@8.4]
  wire [4:0] rf__T_21_addr; // @[RegFile.scala 19:17:@8.4]
  wire  rf__T_21_mask; // @[RegFile.scala 19:17:@8.4]
  wire  rf__T_21_en; // @[RegFile.scala 19:17:@8.4]
  wire  _T_23; // @[RegFile.scala 22:37:@13.4]
  wire  _T_28; // @[RegFile.scala 23:37:@17.4]
  assign rf__T_24_addr = io_rs1_addr;
  assign rf__T_24_data = rf[rf__T_24_addr]; // @[RegFile.scala 19:17:@8.4]
  assign rf__T_29_addr = io_rs2_addr;
  assign rf__T_29_data = rf[rf__T_29_addr]; // @[RegFile.scala 19:17:@8.4]
  assign rf__T_21_data = io_wdata;
  assign rf__T_21_addr = io_waddr;
  assign rf__T_21_mask = 1'h1;
  assign rf__T_21_en = io_wen;
  assign _T_23 = io_rs1_addr != 5'h0; // @[RegFile.scala 22:37:@13.4]
  assign _T_28 = io_rs2_addr != 5'h0; // @[RegFile.scala 23:37:@17.4]
  assign io_rs1_data = _T_23 ? rf__T_24_data : 32'h0; // @[RegFile.scala 22:17:@16.4]
  assign io_rs2_data = _T_28 ? rf__T_29_data : 32'h0; // @[RegFile.scala 23:17:@20.4]
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
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 32; initvar = initvar+1)
    rf[initvar] = _RAND_0[31:0];
  `endif // RANDOMIZE_MEM_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(rf__T_21_en & rf__T_21_mask) begin
      rf[rf__T_21_addr] <= rf__T_21_data; // @[RegFile.scala 19:17:@8.4]
    end
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
