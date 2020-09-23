module Top(
  input         clock,
  input         reset,
  input  [4:0]  io_rs1_addr,
  output [63:0] io_rs1_data,
  input  [4:0]  io_rs2_addr,
  output [63:0] io_rs2_data,
  input  [4:0]  io_waddr,
  input  [63:0] io_wdata,
  input         io_wen
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] rf [0:31]; // @[regs.scala 19:17]
  wire [63:0] rf__T_2_data; // @[regs.scala 19:17]
  wire [4:0] rf__T_2_addr; // @[regs.scala 19:17]
  wire [63:0] rf__T_5_data; // @[regs.scala 19:17]
  wire [4:0] rf__T_5_addr; // @[regs.scala 19:17]
  wire [63:0] rf__T_data; // @[regs.scala 19:17]
  wire [4:0] rf__T_addr; // @[regs.scala 19:17]
  wire  rf__T_mask; // @[regs.scala 19:17]
  wire  rf__T_en; // @[regs.scala 19:17]
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
initial begin
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
  always @(posedge clock) begin
    if(rf__T_en & rf__T_mask) begin
      rf[rf__T_addr] <= rf__T_data; // @[regs.scala 19:17]
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
