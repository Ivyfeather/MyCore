module Pre_TOP(
  input         clock,
  input         reset,
  input         io_fs_ready,
  output        io_fs_valid,
  output [63:0] io_fs_bits_PC,
  output        io_fs_bits_offset,
  input         io_imem_req_ready,
  output        io_imem_req_valid,
  output [63:0] io_imem_req_bits_addr,
  input  [63:0] br_old_PC_0,
  input         br_taken_0,
  output [1:0]  insts_sent_after_br_0,
  input  [63:0] br_target_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg  pre_ready_go; // @[Pre_TOP.scala 19:34]
  wire  _GEN_0 = io_fs_ready & io_fs_valid ? 1'h0 : pre_ready_go; // @[Pre_TOP.scala 21:48 Pre_TOP.scala 21:63 Pre_TOP.scala 19:34]
  wire  _GEN_1 = io_imem_req_ready | _GEN_0; // @[Pre_TOP.scala 20:48 Pre_TOP.scala 20:63]
  reg [63:0] pre_pc; // @[Reg.scala 27:20]
  reg  buf_valid; // @[Pre_TOP.scala 65:28]
  reg [63:0] buf_npc; // @[Reg.scala 27:20]
  wire [63:0] seq_pc = pre_pc + 64'h4; // @[Pre_TOP.scala 32:26]
  wire [63:0] nextpc = buf_valid ? buf_npc : seq_pc; // @[Mux.scala 98:16]
  reg  imem_req_r; // @[Pre_TOP.scala 35:29]
  wire  _GEN_3 = io_fs_ready | imem_req_r; // @[Pre_TOP.scala 38:28 Pre_TOP.scala 39:20 Pre_TOP.scala 35:29]
  wire  _GEN_4 = io_imem_req_ready ? 1'h0 : _GEN_3; // @[Pre_TOP.scala 36:29 Pre_TOP.scala 37:20]
  wire [63:0] _io_imem_req_bits_addr_T_1 = nextpc & 64'hfffffffffffffff8; // @[Pre_TOP.scala 43:69]
  wire [63:0] _T_3 = nextpc - br_old_PC_0; // @[Pre_TOP.scala 58:25]
  wire [63:0] diff = {{2'd0}, _T_3[63:2]}; // @[Pre_TOP.scala 58:37]
  wire [63:0] _insts_sent_after_br_T_2 = diff - 64'h1; // @[Pre_TOP.scala 60:46]
  wire [63:0] _insts_sent_after_br_T_3 = diff > 64'h0 ? _insts_sent_after_br_T_2 : 64'h0; // @[Pre_TOP.scala 60:31]
  wire [63:0] _insts_sent_after_br_T_4 = io_imem_req_ready ? diff : _insts_sent_after_br_T_3; // @[Pre_TOP.scala 59:31]
  wire  _GEN_6 = br_taken_0 | buf_valid; // @[Pre_TOP.scala 70:45 Pre_TOP.scala 70:57 Pre_TOP.scala 65:28]
  wire [1:0] insts_sent_after_br = _insts_sent_after_br_T_4[1:0];
  assign io_fs_valid = pre_ready_go; // @[Pre_TOP.scala 26:30]
  assign io_fs_bits_PC = pre_pc; // @[Pre_TOP.scala 78:19]
  assign io_fs_bits_offset = pre_pc[2]; // @[Pre_TOP.scala 79:32]
  assign io_imem_req_valid = imem_req_r; // @[Pre_TOP.scala 42:29]
  assign io_imem_req_bits_addr = nextpc >= 64'h80000000 ? _io_imem_req_bits_addr_T_1 : nextpc; // @[Pre_TOP.scala 43:35]
  assign insts_sent_after_br_0 = insts_sent_after_br;
  always @(posedge clock) begin
    if (reset) begin // @[Pre_TOP.scala 19:34]
      pre_ready_go <= 1'h0; // @[Pre_TOP.scala 19:34]
    end else begin
      pre_ready_go <= _GEN_1;
    end
    if (reset) begin // @[Reg.scala 27:20]
      pre_pc <= 64'h3ffffffc; // @[Reg.scala 27:20]
    end else if (io_imem_req_ready) begin // @[Reg.scala 28:19]
      if (buf_valid) begin // @[Mux.scala 98:16]
        pre_pc <= buf_npc;
      end else begin
        pre_pc <= seq_pc;
      end
    end
    if (reset) begin // @[Pre_TOP.scala 65:28]
      buf_valid <= 1'h0; // @[Pre_TOP.scala 65:28]
    end else if (buf_valid & io_imem_req_ready) begin // @[Pre_TOP.scala 68:45]
      buf_valid <= 1'h0; // @[Pre_TOP.scala 68:57]
    end else begin
      buf_valid <= _GEN_6;
    end
    if (reset) begin // @[Reg.scala 27:20]
      buf_npc <= 64'h0; // @[Reg.scala 27:20]
    end else if (br_taken_0) begin // @[Reg.scala 28:19]
      buf_npc <= br_target_0; // @[Reg.scala 28:23]
    end
    imem_req_r <= reset | _GEN_4; // @[Pre_TOP.scala 35:29 Pre_TOP.scala 35:29]
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  pre_ready_go = _RAND_0[0:0];
  _RAND_1 = {2{`RANDOM}};
  pre_pc = _RAND_1[63:0];
  _RAND_2 = {1{`RANDOM}};
  buf_valid = _RAND_2[0:0];
  _RAND_3 = {2{`RANDOM}};
  buf_npc = _RAND_3[63:0];
  _RAND_4 = {1{`RANDOM}};
  imem_req_r = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module IF_TOP(
  input         clock,
  input         reset,
  output        io_pres_ready,
  input         io_pres_valid,
  input  [63:0] io_pres_bits_PC,
  input         io_pres_bits_offset,
  input         io_ds_ready,
  output        io_ds_valid,
  output [63:0] io_ds_bits_PC,
  output [31:0] io_ds_bits_inst,
  input         io_imem_resp_valid,
  input  [63:0] io_imem_resp_bits_data
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  wire  _T = io_pres_valid & io_pres_ready; // @[IF_TOP.scala 19:92]
  reg [63:0] from_pre_r_PC; // @[Reg.scala 27:20]
  reg  from_pre_r_offset; // @[Reg.scala 27:20]
  reg  fs_ready_go; // @[IF_TOP.scala 22:33]
  wire  _GEN_2 = io_ds_ready & io_ds_valid ? 1'h0 : fs_ready_go; // @[IF_TOP.scala 24:49 IF_TOP.scala 24:63 IF_TOP.scala 22:33]
  wire  _GEN_3 = io_imem_resp_valid | _GEN_2; // @[IF_TOP.scala 23:49 IF_TOP.scala 23:63]
  reg  fs_valid; // @[Reg.scala 27:20]
  reg [31:0] io_ds_bits_inst_r; // @[Reg.scala 27:20]
  assign io_pres_ready = ~fs_valid | fs_ready_go & io_ds_ready; // @[IF_TOP.scala 30:32]
  assign io_ds_valid = fs_valid & fs_ready_go; // @[IF_TOP.scala 32:32]
  assign io_ds_bits_PC = from_pre_r_PC; // @[IF_TOP.scala 37:19]
  assign io_ds_bits_inst = io_ds_bits_inst_r; // @[IF_TOP.scala 36:21]
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      from_pre_r_PC <= 64'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_pre_r_PC <= io_pres_bits_PC; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_pre_r_offset <= 1'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_pre_r_offset <= io_pres_bits_offset; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[IF_TOP.scala 22:33]
      fs_ready_go <= 1'h0; // @[IF_TOP.scala 22:33]
    end else begin
      fs_ready_go <= _GEN_3;
    end
    if (reset) begin // @[Reg.scala 27:20]
      fs_valid <= 1'h0; // @[Reg.scala 27:20]
    end else if (io_pres_ready) begin // @[Reg.scala 28:19]
      fs_valid <= io_pres_valid; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      io_ds_bits_inst_r <= 32'h0; // @[Reg.scala 27:20]
    end else if (io_imem_resp_valid) begin // @[Reg.scala 28:19]
      if (from_pre_r_offset) begin // @[IF_TOP.scala 35:23]
        io_ds_bits_inst_r <= io_imem_resp_bits_data[63:32];
      end else begin
        io_ds_bits_inst_r <= io_imem_resp_bits_data[31:0];
      end
    end
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  from_pre_r_PC = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  from_pre_r_offset = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  fs_ready_go = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  fs_valid = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  io_ds_bits_inst_r = _RAND_4[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module RegFile(
  input         clock,
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
  reg [63:0] regfile [0:31]; // @[RegFile.scala 20:22]
  wire [63:0] regfile_io_rs1_data_MPORT_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_io_rs1_data_MPORT_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_io_rs2_data_MPORT_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_io_rs2_data_MPORT_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_1_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_1_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_2_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_2_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_3_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_3_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_4_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_4_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_5_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_5_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_6_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_6_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_7_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_7_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_8_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_8_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_9_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_9_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_10_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_10_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_11_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_11_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_12_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_12_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_13_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_13_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_14_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_14_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_15_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_15_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_16_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_16_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_17_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_17_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_18_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_18_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_19_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_19_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_20_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_20_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_21_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_21_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_22_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_22_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_23_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_23_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_24_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_24_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_25_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_25_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_26_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_26_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_27_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_27_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_28_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_28_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_29_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_29_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_30_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_30_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_31_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_31_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_32_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_32_addr; // @[RegFile.scala 20:22]
  wire [63:0] regfile_MPORT_data; // @[RegFile.scala 20:22]
  wire [4:0] regfile_MPORT_addr; // @[RegFile.scala 20:22]
  wire  regfile_MPORT_mask; // @[RegFile.scala 20:22]
  wire  regfile_MPORT_en; // @[RegFile.scala 20:22]
  wire [63:0] _WIRE_0 = regfile_MPORT_1_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_1 = regfile_MPORT_2_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_2 = regfile_MPORT_3_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_3 = regfile_MPORT_4_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_4 = regfile_MPORT_5_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_5 = regfile_MPORT_6_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_6 = regfile_MPORT_7_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_7 = regfile_MPORT_8_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_8 = regfile_MPORT_9_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_9 = regfile_MPORT_10_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_10 = regfile_MPORT_11_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_11 = regfile_MPORT_12_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_12 = regfile_MPORT_13_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_13 = regfile_MPORT_14_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_14 = regfile_MPORT_15_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_15 = regfile_MPORT_16_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_16 = regfile_MPORT_17_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_17 = regfile_MPORT_18_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_18 = regfile_MPORT_19_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_19 = regfile_MPORT_20_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_20 = regfile_MPORT_21_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_21 = regfile_MPORT_22_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_22 = regfile_MPORT_23_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_23 = regfile_MPORT_24_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_24 = regfile_MPORT_25_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_25 = regfile_MPORT_26_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_26 = regfile_MPORT_27_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_27 = regfile_MPORT_28_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_28 = regfile_MPORT_29_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_29 = regfile_MPORT_30_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_30 = regfile_MPORT_31_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  wire [63:0] _WIRE_31 = regfile_MPORT_32_data; // @[RegFile.scala 27:34 RegFile.scala 27:34]
  assign regfile_io_rs1_data_MPORT_addr = io_rs1_addr;
  assign regfile_io_rs1_data_MPORT_data = regfile[regfile_io_rs1_data_MPORT_addr]; // @[RegFile.scala 20:22]
  assign regfile_io_rs2_data_MPORT_addr = io_rs2_addr;
  assign regfile_io_rs2_data_MPORT_data = regfile[regfile_io_rs2_data_MPORT_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_1_addr = 5'h0;
  assign regfile_MPORT_1_data = regfile[regfile_MPORT_1_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_2_addr = 5'h1;
  assign regfile_MPORT_2_data = regfile[regfile_MPORT_2_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_3_addr = 5'h2;
  assign regfile_MPORT_3_data = regfile[regfile_MPORT_3_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_4_addr = 5'h3;
  assign regfile_MPORT_4_data = regfile[regfile_MPORT_4_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_5_addr = 5'h4;
  assign regfile_MPORT_5_data = regfile[regfile_MPORT_5_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_6_addr = 5'h5;
  assign regfile_MPORT_6_data = regfile[regfile_MPORT_6_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_7_addr = 5'h6;
  assign regfile_MPORT_7_data = regfile[regfile_MPORT_7_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_8_addr = 5'h7;
  assign regfile_MPORT_8_data = regfile[regfile_MPORT_8_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_9_addr = 5'h8;
  assign regfile_MPORT_9_data = regfile[regfile_MPORT_9_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_10_addr = 5'h9;
  assign regfile_MPORT_10_data = regfile[regfile_MPORT_10_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_11_addr = 5'ha;
  assign regfile_MPORT_11_data = regfile[regfile_MPORT_11_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_12_addr = 5'hb;
  assign regfile_MPORT_12_data = regfile[regfile_MPORT_12_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_13_addr = 5'hc;
  assign regfile_MPORT_13_data = regfile[regfile_MPORT_13_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_14_addr = 5'hd;
  assign regfile_MPORT_14_data = regfile[regfile_MPORT_14_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_15_addr = 5'he;
  assign regfile_MPORT_15_data = regfile[regfile_MPORT_15_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_16_addr = 5'hf;
  assign regfile_MPORT_16_data = regfile[regfile_MPORT_16_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_17_addr = 5'h10;
  assign regfile_MPORT_17_data = regfile[regfile_MPORT_17_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_18_addr = 5'h11;
  assign regfile_MPORT_18_data = regfile[regfile_MPORT_18_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_19_addr = 5'h12;
  assign regfile_MPORT_19_data = regfile[regfile_MPORT_19_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_20_addr = 5'h13;
  assign regfile_MPORT_20_data = regfile[regfile_MPORT_20_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_21_addr = 5'h14;
  assign regfile_MPORT_21_data = regfile[regfile_MPORT_21_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_22_addr = 5'h15;
  assign regfile_MPORT_22_data = regfile[regfile_MPORT_22_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_23_addr = 5'h16;
  assign regfile_MPORT_23_data = regfile[regfile_MPORT_23_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_24_addr = 5'h17;
  assign regfile_MPORT_24_data = regfile[regfile_MPORT_24_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_25_addr = 5'h18;
  assign regfile_MPORT_25_data = regfile[regfile_MPORT_25_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_26_addr = 5'h19;
  assign regfile_MPORT_26_data = regfile[regfile_MPORT_26_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_27_addr = 5'h1a;
  assign regfile_MPORT_27_data = regfile[regfile_MPORT_27_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_28_addr = 5'h1b;
  assign regfile_MPORT_28_data = regfile[regfile_MPORT_28_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_29_addr = 5'h1c;
  assign regfile_MPORT_29_data = regfile[regfile_MPORT_29_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_30_addr = 5'h1d;
  assign regfile_MPORT_30_data = regfile[regfile_MPORT_30_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_31_addr = 5'h1e;
  assign regfile_MPORT_31_data = regfile[regfile_MPORT_31_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_32_addr = 5'h1f;
  assign regfile_MPORT_32_data = regfile[regfile_MPORT_32_addr]; // @[RegFile.scala 20:22]
  assign regfile_MPORT_data = io_wdata;
  assign regfile_MPORT_addr = io_waddr;
  assign regfile_MPORT_mask = 1'h1;
  assign regfile_MPORT_en = io_wen;
  assign io_rs1_data = io_rs1_addr != 5'h0 ? regfile_io_rs1_data_MPORT_data : 64'h0; // @[RegFile.scala 23:23]
  assign io_rs2_data = io_rs2_addr != 5'h0 ? regfile_io_rs2_data_MPORT_data : 64'h0; // @[RegFile.scala 24:23]
  always @(posedge clock) begin
    if(regfile_MPORT_en & regfile_MPORT_mask) begin
      regfile[regfile_MPORT_addr] <= regfile_MPORT_data; // @[RegFile.scala 20:22]
    end
  end
// Register and memory initialization
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
    regfile[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ForwardUnit(
  input         clock,
  input  [4:0]  io_rs1_addr,
  input  [4:0]  io_rs2_addr,
  input         io_ws_res_rf_we,
  input  [4:0]  io_ws_res_wr_addr,
  input  [63:0] io_ws_res_wr_data,
  input  [1:0]  io_ws_res_wb_sel,
  output [63:0] io_rs1_data,
  output [63:0] io_rs2_data,
  output        io_wr_stall,
  input         ms_res_0_rf_we,
  input  [4:0]  ms_res_0_wr_addr,
  input  [63:0] ms_res_0_wr_data,
  input  [1:0]  ms_res_0_wb_sel,
  input         load_data_returned,
  input         es_res_0_rf_we,
  input  [4:0]  es_res_0_wr_addr,
  input  [63:0] es_res_0_wr_data,
  input  [1:0]  es_res_0_wb_sel
);
  wire  rf_clock; // @[Forward.scala 30:20]
  wire [4:0] rf_io_rs1_addr; // @[Forward.scala 30:20]
  wire [63:0] rf_io_rs1_data; // @[Forward.scala 30:20]
  wire [4:0] rf_io_rs2_addr; // @[Forward.scala 30:20]
  wire [63:0] rf_io_rs2_data; // @[Forward.scala 30:20]
  wire [4:0] rf_io_waddr; // @[Forward.scala 30:20]
  wire [63:0] rf_io_wdata; // @[Forward.scala 30:20]
  wire  rf_io_wen; // @[Forward.scala 30:20]
  wire  es_addr1 = es_res_0_wr_addr == io_rs1_addr; // @[Forward.scala 39:35]
  wire  es_addr2 = es_res_0_wr_addr == io_rs2_addr; // @[Forward.scala 40:35]
  wire  ms_addr1 = ms_res_0_wr_addr == io_rs1_addr; // @[Forward.scala 41:35]
  wire  ms_addr2 = ms_res_0_wr_addr == io_rs2_addr; // @[Forward.scala 42:35]
  wire  ws_addr1 = io_ws_res_wr_addr == io_rs1_addr; // @[Forward.scala 43:35]
  wire  ws_addr2 = io_ws_res_wr_addr == io_rs2_addr; // @[Forward.scala 44:35]
  wire  is_load = es_res_0_wb_sel == 2'h1; // @[Forward.scala 46:33]
  wire  _io_rs1_data_T_1 = ~is_load; // @[Forward.scala 48:38]
  wire  _io_rs1_data_T_2 = es_res_0_rf_we & es_addr1 & ~is_load; // @[Forward.scala 48:35]
  wire  _io_rs1_data_T_3 = ms_res_0_rf_we & ms_addr1; // @[Forward.scala 49:23]
  wire  _io_rs1_data_T_4 = io_ws_res_rf_we & ws_addr1; // @[Forward.scala 50:23]
  wire [63:0] _io_rs1_data_T_5 = _io_rs1_data_T_4 ? io_ws_res_wr_data : rf_io_rs1_data; // @[Mux.scala 98:16]
  wire [63:0] _io_rs1_data_T_6 = _io_rs1_data_T_3 ? ms_res_0_wr_data : _io_rs1_data_T_5; // @[Mux.scala 98:16]
  wire  _io_rs2_data_T_2 = es_res_0_rf_we & es_addr2 & _io_rs1_data_T_1; // @[Forward.scala 53:35]
  wire  _io_rs2_data_T_3 = ms_res_0_rf_we & ms_addr2; // @[Forward.scala 54:23]
  wire  _io_rs2_data_T_4 = io_ws_res_rf_we & ws_addr2; // @[Forward.scala 55:23]
  wire [63:0] _io_rs2_data_T_5 = _io_rs2_data_T_4 ? io_ws_res_wr_data : rf_io_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _io_rs2_data_T_6 = _io_rs2_data_T_3 ? ms_res_0_wr_data : _io_rs2_data_T_5; // @[Mux.scala 98:16]
  wire  _T = es_addr1 | es_addr2; // @[Forward.scala 60:44]
  wire  load_data_not_returned = (es_addr1 | es_addr2) & is_load & ~load_data_returned; // @[Forward.scala 60:68]
  wire  csrr_at_ws = io_ws_res_wb_sel == 2'h3; // @[Forward.scala 62:36]
  wire  _T_6 = ~csrr_at_ws; // @[Forward.scala 63:76]
  wire  is_csrr_es = _T & es_res_0_wb_sel == 2'h3 & ~csrr_at_ws; // @[Forward.scala 63:73]
  wire  is_csrr_ms = (ms_addr1 | ms_addr2) & ms_res_0_wb_sel == 2'h3 & _T_6; // @[Forward.scala 64:73]
  wire  csrr_stall = is_csrr_es | is_csrr_ms; // @[Forward.scala 73:33]
  RegFile rf ( // @[Forward.scala 30:20]
    .clock(rf_clock),
    .io_rs1_addr(rf_io_rs1_addr),
    .io_rs1_data(rf_io_rs1_data),
    .io_rs2_addr(rf_io_rs2_addr),
    .io_rs2_data(rf_io_rs2_data),
    .io_waddr(rf_io_waddr),
    .io_wdata(rf_io_wdata),
    .io_wen(rf_io_wen)
  );
  assign io_rs1_data = _io_rs1_data_T_2 ? es_res_0_wr_data : _io_rs1_data_T_6; // @[Mux.scala 98:16]
  assign io_rs2_data = _io_rs2_data_T_2 ? es_res_0_wr_data : _io_rs2_data_T_6; // @[Mux.scala 98:16]
  assign io_wr_stall = load_data_not_returned | csrr_stall; // @[Forward.scala 76:43]
  assign rf_clock = clock;
  assign rf_io_rs1_addr = io_rs1_addr; // @[Forward.scala 31:21]
  assign rf_io_rs2_addr = io_rs2_addr; // @[Forward.scala 32:21]
  assign rf_io_waddr = io_ws_res_wr_addr; // @[Forward.scala 34:21]
  assign rf_io_wdata = io_ws_res_wr_data; // @[Forward.scala 35:21]
  assign rf_io_wen = io_ws_res_rf_we; // @[Forward.scala 33:21]
endmodule
module IDU(
  input  [31:0] io_inst,
  output [3:0]  io_ctrl_br_type,
  output [1:0]  io_ctrl_op1_sel,
  output [1:0]  io_ctrl_op2_sel,
  output [5:0]  io_ctrl_alu_op,
  output [1:0]  io_ctrl_wb_sel,
  output        io_ctrl_rf_wen,
  output        io_ctrl_mem_en,
  output        io_ctrl_mem_wr,
  output [2:0]  io_ctrl_mem_msk,
  output [2:0]  io_ctrl_csr_cmd
);
  wire [31:0] _T = io_inst & 32'h707f; // @[Lookup.scala 31:38]
  wire  _T_1 = 32'h2003 == _T; // @[Lookup.scala 31:38]
  wire  _T_3 = 32'h3 == _T; // @[Lookup.scala 31:38]
  wire  _T_5 = 32'h4003 == _T; // @[Lookup.scala 31:38]
  wire  _T_7 = 32'h1003 == _T; // @[Lookup.scala 31:38]
  wire  _T_9 = 32'h5003 == _T; // @[Lookup.scala 31:38]
  wire  _T_11 = 32'h2023 == _T; // @[Lookup.scala 31:38]
  wire  _T_13 = 32'h23 == _T; // @[Lookup.scala 31:38]
  wire  _T_15 = 32'h1023 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_16 = io_inst & 32'h7f; // @[Lookup.scala 31:38]
  wire  _T_17 = 32'h17 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_19 = 32'h37 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_21 = 32'h13 == _T; // @[Lookup.scala 31:38]
  wire  _T_23 = 32'h7013 == _T; // @[Lookup.scala 31:38]
  wire  _T_25 = 32'h6013 == _T; // @[Lookup.scala 31:38]
  wire  _T_27 = 32'h4013 == _T; // @[Lookup.scala 31:38]
  wire  _T_29 = 32'h2013 == _T; // @[Lookup.scala 31:38]
  wire  _T_31 = 32'h3013 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_32 = io_inst & 32'hfc00707f; // @[Lookup.scala 31:38]
  wire  _T_33 = 32'h1013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_35 = 32'h40005013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_37 = 32'h5013 == _T_32; // @[Lookup.scala 31:38]
  wire [31:0] _T_38 = io_inst & 32'hfe00707f; // @[Lookup.scala 31:38]
  wire  _T_39 = 32'h1033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_41 = 32'h33 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_43 = 32'h40000033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_45 = 32'h2033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_47 = 32'h3033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_49 = 32'h7033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_51 = 32'h6033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_53 = 32'h4033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_55 = 32'h40005033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_57 = 32'h5033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_59 = 32'h6f == _T_16; // @[Lookup.scala 31:38]
  wire  _T_61 = 32'h67 == _T; // @[Lookup.scala 31:38]
  wire  _T_63 = 32'h63 == _T; // @[Lookup.scala 31:38]
  wire  _T_65 = 32'h1063 == _T; // @[Lookup.scala 31:38]
  wire  _T_67 = 32'h5063 == _T; // @[Lookup.scala 31:38]
  wire  _T_69 = 32'h7063 == _T; // @[Lookup.scala 31:38]
  wire  _T_71 = 32'h4063 == _T; // @[Lookup.scala 31:38]
  wire  _T_73 = 32'h6063 == _T; // @[Lookup.scala 31:38]
  wire  _T_75 = 32'h6003 == _T; // @[Lookup.scala 31:38]
  wire  _T_77 = 32'h3003 == _T; // @[Lookup.scala 31:38]
  wire  _T_79 = 32'h3023 == _T; // @[Lookup.scala 31:38]
  wire  _T_81 = 32'h1b == _T; // @[Lookup.scala 31:38]
  wire  _T_83 = 32'h101b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_85 = 32'h501b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_87 = 32'h4000501b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_89 = 32'h3b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_91 = 32'h4000003b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_93 = 32'h103b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_95 = 32'h503b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_97 = 32'h4000503b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_99 = 32'h5073 == _T; // @[Lookup.scala 31:38]
  wire  _T_101 = 32'h6073 == _T; // @[Lookup.scala 31:38]
  wire  _T_103 = 32'h7073 == _T; // @[Lookup.scala 31:38]
  wire  _T_105 = 32'h1073 == _T; // @[Lookup.scala 31:38]
  wire  _T_107 = 32'h2073 == _T; // @[Lookup.scala 31:38]
  wire  _T_109 = 32'h3073 == _T; // @[Lookup.scala 31:38]
  wire  _T_111 = 32'h73 == io_inst; // @[Lookup.scala 31:38]
  wire  _T_113 = 32'h30200073 == io_inst; // @[Lookup.scala 31:38]
  wire  _T_115 = 32'h100073 == io_inst; // @[Lookup.scala 31:38]
  wire  _T_117 = 32'h10500073 == io_inst; // @[Lookup.scala 31:38]
  wire  _T_119 = 32'h100f == _T; // @[Lookup.scala 31:38]
  wire  _T_121 = 32'hf == _T; // @[Lookup.scala 31:38]
  wire  _T_123 = 32'h200503b == _T_38; // @[Lookup.scala 31:38]
  wire  _T_125 = 32'h200703b == _T_38; // @[Lookup.scala 31:38]
  wire [3:0] _T_214 = _T_73 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_215 = _T_71 ? 4'h5 : _T_214; // @[Lookup.scala 33:37]
  wire [3:0] _T_216 = _T_69 ? 4'h4 : _T_215; // @[Lookup.scala 33:37]
  wire [3:0] _T_217 = _T_67 ? 4'h3 : _T_216; // @[Lookup.scala 33:37]
  wire [3:0] _T_218 = _T_65 ? 4'h1 : _T_217; // @[Lookup.scala 33:37]
  wire [3:0] _T_219 = _T_63 ? 4'h2 : _T_218; // @[Lookup.scala 33:37]
  wire [3:0] _T_220 = _T_61 ? 4'h8 : _T_219; // @[Lookup.scala 33:37]
  wire [3:0] _T_221 = _T_59 ? 4'h7 : _T_220; // @[Lookup.scala 33:37]
  wire [3:0] _T_222 = _T_57 ? 4'h0 : _T_221; // @[Lookup.scala 33:37]
  wire [3:0] _T_223 = _T_55 ? 4'h0 : _T_222; // @[Lookup.scala 33:37]
  wire [3:0] _T_224 = _T_53 ? 4'h0 : _T_223; // @[Lookup.scala 33:37]
  wire [3:0] _T_225 = _T_51 ? 4'h0 : _T_224; // @[Lookup.scala 33:37]
  wire [3:0] _T_226 = _T_49 ? 4'h0 : _T_225; // @[Lookup.scala 33:37]
  wire [3:0] _T_227 = _T_47 ? 4'h0 : _T_226; // @[Lookup.scala 33:37]
  wire [3:0] _T_228 = _T_45 ? 4'h0 : _T_227; // @[Lookup.scala 33:37]
  wire [3:0] _T_229 = _T_43 ? 4'h0 : _T_228; // @[Lookup.scala 33:37]
  wire [3:0] _T_230 = _T_41 ? 4'h0 : _T_229; // @[Lookup.scala 33:37]
  wire [3:0] _T_231 = _T_39 ? 4'h0 : _T_230; // @[Lookup.scala 33:37]
  wire [3:0] _T_232 = _T_37 ? 4'h0 : _T_231; // @[Lookup.scala 33:37]
  wire [3:0] _T_233 = _T_35 ? 4'h0 : _T_232; // @[Lookup.scala 33:37]
  wire [3:0] _T_234 = _T_33 ? 4'h0 : _T_233; // @[Lookup.scala 33:37]
  wire [3:0] _T_235 = _T_31 ? 4'h0 : _T_234; // @[Lookup.scala 33:37]
  wire [3:0] _T_236 = _T_29 ? 4'h0 : _T_235; // @[Lookup.scala 33:37]
  wire [3:0] _T_237 = _T_27 ? 4'h0 : _T_236; // @[Lookup.scala 33:37]
  wire [3:0] _T_238 = _T_25 ? 4'h0 : _T_237; // @[Lookup.scala 33:37]
  wire [3:0] _T_239 = _T_23 ? 4'h0 : _T_238; // @[Lookup.scala 33:37]
  wire [3:0] _T_240 = _T_21 ? 4'h0 : _T_239; // @[Lookup.scala 33:37]
  wire [3:0] _T_241 = _T_19 ? 4'h0 : _T_240; // @[Lookup.scala 33:37]
  wire [3:0] _T_242 = _T_17 ? 4'h0 : _T_241; // @[Lookup.scala 33:37]
  wire [3:0] _T_243 = _T_15 ? 4'h0 : _T_242; // @[Lookup.scala 33:37]
  wire [3:0] _T_244 = _T_13 ? 4'h0 : _T_243; // @[Lookup.scala 33:37]
  wire [3:0] _T_245 = _T_11 ? 4'h0 : _T_244; // @[Lookup.scala 33:37]
  wire [3:0] _T_246 = _T_9 ? 4'h0 : _T_245; // @[Lookup.scala 33:37]
  wire [3:0] _T_247 = _T_7 ? 4'h0 : _T_246; // @[Lookup.scala 33:37]
  wire [3:0] _T_248 = _T_5 ? 4'h0 : _T_247; // @[Lookup.scala 33:37]
  wire [3:0] _T_249 = _T_3 ? 4'h0 : _T_248; // @[Lookup.scala 33:37]
  wire [1:0] _T_261 = _T_103 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_262 = _T_101 ? 2'h2 : _T_261; // @[Lookup.scala 33:37]
  wire [1:0] _T_263 = _T_99 ? 2'h2 : _T_262; // @[Lookup.scala 33:37]
  wire [1:0] _T_264 = _T_97 ? 2'h0 : _T_263; // @[Lookup.scala 33:37]
  wire [1:0] _T_265 = _T_95 ? 2'h0 : _T_264; // @[Lookup.scala 33:37]
  wire [1:0] _T_266 = _T_93 ? 2'h0 : _T_265; // @[Lookup.scala 33:37]
  wire [1:0] _T_267 = _T_91 ? 2'h0 : _T_266; // @[Lookup.scala 33:37]
  wire [1:0] _T_268 = _T_89 ? 2'h0 : _T_267; // @[Lookup.scala 33:37]
  wire [1:0] _T_269 = _T_87 ? 2'h0 : _T_268; // @[Lookup.scala 33:37]
  wire [1:0] _T_270 = _T_85 ? 2'h0 : _T_269; // @[Lookup.scala 33:37]
  wire [1:0] _T_271 = _T_83 ? 2'h0 : _T_270; // @[Lookup.scala 33:37]
  wire [1:0] _T_272 = _T_81 ? 2'h0 : _T_271; // @[Lookup.scala 33:37]
  wire [1:0] _T_273 = _T_79 ? 2'h0 : _T_272; // @[Lookup.scala 33:37]
  wire [1:0] _T_274 = _T_77 ? 2'h0 : _T_273; // @[Lookup.scala 33:37]
  wire [1:0] _T_275 = _T_75 ? 2'h0 : _T_274; // @[Lookup.scala 33:37]
  wire [1:0] _T_276 = _T_73 ? 2'h0 : _T_275; // @[Lookup.scala 33:37]
  wire [1:0] _T_277 = _T_71 ? 2'h0 : _T_276; // @[Lookup.scala 33:37]
  wire [1:0] _T_278 = _T_69 ? 2'h0 : _T_277; // @[Lookup.scala 33:37]
  wire [1:0] _T_279 = _T_67 ? 2'h0 : _T_278; // @[Lookup.scala 33:37]
  wire [1:0] _T_280 = _T_65 ? 2'h0 : _T_279; // @[Lookup.scala 33:37]
  wire [1:0] _T_281 = _T_63 ? 2'h0 : _T_280; // @[Lookup.scala 33:37]
  wire [1:0] _T_282 = _T_61 ? 2'h0 : _T_281; // @[Lookup.scala 33:37]
  wire [1:0] _T_283 = _T_59 ? 2'h0 : _T_282; // @[Lookup.scala 33:37]
  wire [1:0] _T_284 = _T_57 ? 2'h0 : _T_283; // @[Lookup.scala 33:37]
  wire [1:0] _T_285 = _T_55 ? 2'h0 : _T_284; // @[Lookup.scala 33:37]
  wire [1:0] _T_286 = _T_53 ? 2'h0 : _T_285; // @[Lookup.scala 33:37]
  wire [1:0] _T_287 = _T_51 ? 2'h0 : _T_286; // @[Lookup.scala 33:37]
  wire [1:0] _T_288 = _T_49 ? 2'h0 : _T_287; // @[Lookup.scala 33:37]
  wire [1:0] _T_289 = _T_47 ? 2'h0 : _T_288; // @[Lookup.scala 33:37]
  wire [1:0] _T_290 = _T_45 ? 2'h0 : _T_289; // @[Lookup.scala 33:37]
  wire [1:0] _T_291 = _T_43 ? 2'h0 : _T_290; // @[Lookup.scala 33:37]
  wire [1:0] _T_292 = _T_41 ? 2'h0 : _T_291; // @[Lookup.scala 33:37]
  wire [1:0] _T_293 = _T_39 ? 2'h0 : _T_292; // @[Lookup.scala 33:37]
  wire [1:0] _T_294 = _T_37 ? 2'h0 : _T_293; // @[Lookup.scala 33:37]
  wire [1:0] _T_295 = _T_35 ? 2'h0 : _T_294; // @[Lookup.scala 33:37]
  wire [1:0] _T_296 = _T_33 ? 2'h0 : _T_295; // @[Lookup.scala 33:37]
  wire [1:0] _T_297 = _T_31 ? 2'h0 : _T_296; // @[Lookup.scala 33:37]
  wire [1:0] _T_298 = _T_29 ? 2'h0 : _T_297; // @[Lookup.scala 33:37]
  wire [1:0] _T_299 = _T_27 ? 2'h0 : _T_298; // @[Lookup.scala 33:37]
  wire [1:0] _T_300 = _T_25 ? 2'h0 : _T_299; // @[Lookup.scala 33:37]
  wire [1:0] _T_301 = _T_23 ? 2'h0 : _T_300; // @[Lookup.scala 33:37]
  wire [1:0] _T_302 = _T_21 ? 2'h0 : _T_301; // @[Lookup.scala 33:37]
  wire [1:0] _T_303 = _T_19 ? 2'h1 : _T_302; // @[Lookup.scala 33:37]
  wire [1:0] _T_304 = _T_17 ? 2'h1 : _T_303; // @[Lookup.scala 33:37]
  wire [1:0] _T_305 = _T_15 ? 2'h0 : _T_304; // @[Lookup.scala 33:37]
  wire [1:0] _T_306 = _T_13 ? 2'h0 : _T_305; // @[Lookup.scala 33:37]
  wire [1:0] _T_307 = _T_11 ? 2'h0 : _T_306; // @[Lookup.scala 33:37]
  wire [1:0] _T_308 = _T_9 ? 2'h0 : _T_307; // @[Lookup.scala 33:37]
  wire [1:0] _T_309 = _T_7 ? 2'h0 : _T_308; // @[Lookup.scala 33:37]
  wire [1:0] _T_310 = _T_5 ? 2'h0 : _T_309; // @[Lookup.scala 33:37]
  wire [1:0] _T_311 = _T_3 ? 2'h0 : _T_310; // @[Lookup.scala 33:37]
  wire [1:0] _T_331 = _T_87 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_332 = _T_85 ? 2'h1 : _T_331; // @[Lookup.scala 33:37]
  wire [1:0] _T_333 = _T_83 ? 2'h1 : _T_332; // @[Lookup.scala 33:37]
  wire [1:0] _T_334 = _T_81 ? 2'h1 : _T_333; // @[Lookup.scala 33:37]
  wire [1:0] _T_335 = _T_79 ? 2'h2 : _T_334; // @[Lookup.scala 33:37]
  wire [1:0] _T_336 = _T_77 ? 2'h1 : _T_335; // @[Lookup.scala 33:37]
  wire [1:0] _T_337 = _T_75 ? 2'h1 : _T_336; // @[Lookup.scala 33:37]
  wire [1:0] _T_338 = _T_73 ? 2'h0 : _T_337; // @[Lookup.scala 33:37]
  wire [1:0] _T_339 = _T_71 ? 2'h0 : _T_338; // @[Lookup.scala 33:37]
  wire [1:0] _T_340 = _T_69 ? 2'h0 : _T_339; // @[Lookup.scala 33:37]
  wire [1:0] _T_341 = _T_67 ? 2'h0 : _T_340; // @[Lookup.scala 33:37]
  wire [1:0] _T_342 = _T_65 ? 2'h0 : _T_341; // @[Lookup.scala 33:37]
  wire [1:0] _T_343 = _T_63 ? 2'h0 : _T_342; // @[Lookup.scala 33:37]
  wire [1:0] _T_344 = _T_61 ? 2'h1 : _T_343; // @[Lookup.scala 33:37]
  wire [1:0] _T_345 = _T_59 ? 2'h0 : _T_344; // @[Lookup.scala 33:37]
  wire [1:0] _T_346 = _T_57 ? 2'h0 : _T_345; // @[Lookup.scala 33:37]
  wire [1:0] _T_347 = _T_55 ? 2'h0 : _T_346; // @[Lookup.scala 33:37]
  wire [1:0] _T_348 = _T_53 ? 2'h0 : _T_347; // @[Lookup.scala 33:37]
  wire [1:0] _T_349 = _T_51 ? 2'h0 : _T_348; // @[Lookup.scala 33:37]
  wire [1:0] _T_350 = _T_49 ? 2'h0 : _T_349; // @[Lookup.scala 33:37]
  wire [1:0] _T_351 = _T_47 ? 2'h0 : _T_350; // @[Lookup.scala 33:37]
  wire [1:0] _T_352 = _T_45 ? 2'h0 : _T_351; // @[Lookup.scala 33:37]
  wire [1:0] _T_353 = _T_43 ? 2'h0 : _T_352; // @[Lookup.scala 33:37]
  wire [1:0] _T_354 = _T_41 ? 2'h0 : _T_353; // @[Lookup.scala 33:37]
  wire [1:0] _T_355 = _T_39 ? 2'h0 : _T_354; // @[Lookup.scala 33:37]
  wire [1:0] _T_356 = _T_37 ? 2'h1 : _T_355; // @[Lookup.scala 33:37]
  wire [1:0] _T_357 = _T_35 ? 2'h1 : _T_356; // @[Lookup.scala 33:37]
  wire [1:0] _T_358 = _T_33 ? 2'h1 : _T_357; // @[Lookup.scala 33:37]
  wire [1:0] _T_359 = _T_31 ? 2'h1 : _T_358; // @[Lookup.scala 33:37]
  wire [1:0] _T_360 = _T_29 ? 2'h1 : _T_359; // @[Lookup.scala 33:37]
  wire [1:0] _T_361 = _T_27 ? 2'h1 : _T_360; // @[Lookup.scala 33:37]
  wire [1:0] _T_362 = _T_25 ? 2'h1 : _T_361; // @[Lookup.scala 33:37]
  wire [1:0] _T_363 = _T_23 ? 2'h1 : _T_362; // @[Lookup.scala 33:37]
  wire [1:0] _T_364 = _T_21 ? 2'h1 : _T_363; // @[Lookup.scala 33:37]
  wire [1:0] _T_365 = _T_19 ? 2'h0 : _T_364; // @[Lookup.scala 33:37]
  wire [1:0] _T_366 = _T_17 ? 2'h3 : _T_365; // @[Lookup.scala 33:37]
  wire [1:0] _T_367 = _T_15 ? 2'h2 : _T_366; // @[Lookup.scala 33:37]
  wire [1:0] _T_368 = _T_13 ? 2'h2 : _T_367; // @[Lookup.scala 33:37]
  wire [1:0] _T_369 = _T_11 ? 2'h2 : _T_368; // @[Lookup.scala 33:37]
  wire [1:0] _T_370 = _T_9 ? 2'h1 : _T_369; // @[Lookup.scala 33:37]
  wire [1:0] _T_371 = _T_7 ? 2'h1 : _T_370; // @[Lookup.scala 33:37]
  wire [1:0] _T_372 = _T_5 ? 2'h1 : _T_371; // @[Lookup.scala 33:37]
  wire [1:0] _T_373 = _T_3 ? 2'h1 : _T_372; // @[Lookup.scala 33:37]
  wire [5:0] _T_374 = _T_125 ? 6'h3e : 6'h0; // @[Lookup.scala 33:37]
  wire [5:0] _T_375 = _T_123 ? 6'h3f : _T_374; // @[Lookup.scala 33:37]
  wire [5:0] _T_376 = _T_121 ? 6'h0 : _T_375; // @[Lookup.scala 33:37]
  wire [5:0] _T_377 = _T_119 ? 6'h0 : _T_376; // @[Lookup.scala 33:37]
  wire [5:0] _T_378 = _T_117 ? 6'h0 : _T_377; // @[Lookup.scala 33:37]
  wire [5:0] _T_379 = _T_115 ? 6'h0 : _T_378; // @[Lookup.scala 33:37]
  wire [5:0] _T_380 = _T_113 ? 6'h0 : _T_379; // @[Lookup.scala 33:37]
  wire [5:0] _T_381 = _T_111 ? 6'h0 : _T_380; // @[Lookup.scala 33:37]
  wire [5:0] _T_382 = _T_109 ? 6'h8 : _T_381; // @[Lookup.scala 33:37]
  wire [5:0] _T_383 = _T_107 ? 6'h8 : _T_382; // @[Lookup.scala 33:37]
  wire [5:0] _T_384 = _T_105 ? 6'h8 : _T_383; // @[Lookup.scala 33:37]
  wire [5:0] _T_385 = _T_103 ? 6'h8 : _T_384; // @[Lookup.scala 33:37]
  wire [5:0] _T_386 = _T_101 ? 6'h8 : _T_385; // @[Lookup.scala 33:37]
  wire [5:0] _T_387 = _T_99 ? 6'h8 : _T_386; // @[Lookup.scala 33:37]
  wire [5:0] _T_388 = _T_97 ? 6'h26 : _T_387; // @[Lookup.scala 33:37]
  wire [5:0] _T_389 = _T_95 ? 6'h25 : _T_388; // @[Lookup.scala 33:37]
  wire [5:0] _T_390 = _T_93 ? 6'h24 : _T_389; // @[Lookup.scala 33:37]
  wire [5:0] _T_391 = _T_91 ? 6'h30 : _T_390; // @[Lookup.scala 33:37]
  wire [5:0] _T_392 = _T_89 ? 6'h20 : _T_391; // @[Lookup.scala 33:37]
  wire [5:0] _T_393 = _T_87 ? 6'h26 : _T_392; // @[Lookup.scala 33:37]
  wire [5:0] _T_394 = _T_85 ? 6'h25 : _T_393; // @[Lookup.scala 33:37]
  wire [5:0] _T_395 = _T_83 ? 6'h24 : _T_394; // @[Lookup.scala 33:37]
  wire [5:0] _T_396 = _T_81 ? 6'h20 : _T_395; // @[Lookup.scala 33:37]
  wire [5:0] _T_397 = _T_79 ? 6'h0 : _T_396; // @[Lookup.scala 33:37]
  wire [5:0] _T_398 = _T_77 ? 6'h0 : _T_397; // @[Lookup.scala 33:37]
  wire [5:0] _T_399 = _T_75 ? 6'h0 : _T_398; // @[Lookup.scala 33:37]
  wire [5:0] _T_400 = _T_73 ? 6'h12 : _T_399; // @[Lookup.scala 33:37]
  wire [5:0] _T_401 = _T_71 ? 6'h11 : _T_400; // @[Lookup.scala 33:37]
  wire [5:0] _T_402 = _T_69 ? 6'h12 : _T_401; // @[Lookup.scala 33:37]
  wire [5:0] _T_403 = _T_67 ? 6'h11 : _T_402; // @[Lookup.scala 33:37]
  wire [5:0] _T_404 = _T_65 ? 6'h10 : _T_403; // @[Lookup.scala 33:37]
  wire [5:0] _T_405 = _T_63 ? 6'h10 : _T_404; // @[Lookup.scala 33:37]
  wire [5:0] _T_406 = _T_61 ? 6'h0 : _T_405; // @[Lookup.scala 33:37]
  wire [5:0] _T_407 = _T_59 ? 6'h0 : _T_406; // @[Lookup.scala 33:37]
  wire [5:0] _T_408 = _T_57 ? 6'h5 : _T_407; // @[Lookup.scala 33:37]
  wire [5:0] _T_409 = _T_55 ? 6'h6 : _T_408; // @[Lookup.scala 33:37]
  wire [5:0] _T_410 = _T_53 ? 6'h1 : _T_409; // @[Lookup.scala 33:37]
  wire [5:0] _T_411 = _T_51 ? 6'h2 : _T_410; // @[Lookup.scala 33:37]
  wire [5:0] _T_412 = _T_49 ? 6'h3 : _T_411; // @[Lookup.scala 33:37]
  wire [5:0] _T_413 = _T_47 ? 6'h12 : _T_412; // @[Lookup.scala 33:37]
  wire [5:0] _T_414 = _T_45 ? 6'h11 : _T_413; // @[Lookup.scala 33:37]
  wire [5:0] _T_415 = _T_43 ? 6'h10 : _T_414; // @[Lookup.scala 33:37]
  wire [5:0] _T_416 = _T_41 ? 6'h0 : _T_415; // @[Lookup.scala 33:37]
  wire [5:0] _T_417 = _T_39 ? 6'h4 : _T_416; // @[Lookup.scala 33:37]
  wire [5:0] _T_418 = _T_37 ? 6'h5 : _T_417; // @[Lookup.scala 33:37]
  wire [5:0] _T_419 = _T_35 ? 6'h6 : _T_418; // @[Lookup.scala 33:37]
  wire [5:0] _T_420 = _T_33 ? 6'h4 : _T_419; // @[Lookup.scala 33:37]
  wire [5:0] _T_421 = _T_31 ? 6'h12 : _T_420; // @[Lookup.scala 33:37]
  wire [5:0] _T_422 = _T_29 ? 6'h11 : _T_421; // @[Lookup.scala 33:37]
  wire [5:0] _T_423 = _T_27 ? 6'h1 : _T_422; // @[Lookup.scala 33:37]
  wire [5:0] _T_424 = _T_25 ? 6'h2 : _T_423; // @[Lookup.scala 33:37]
  wire [5:0] _T_425 = _T_23 ? 6'h3 : _T_424; // @[Lookup.scala 33:37]
  wire [5:0] _T_426 = _T_21 ? 6'h0 : _T_425; // @[Lookup.scala 33:37]
  wire [5:0] _T_427 = _T_19 ? 6'h8 : _T_426; // @[Lookup.scala 33:37]
  wire [5:0] _T_428 = _T_17 ? 6'h0 : _T_427; // @[Lookup.scala 33:37]
  wire [5:0] _T_429 = _T_15 ? 6'h0 : _T_428; // @[Lookup.scala 33:37]
  wire [5:0] _T_430 = _T_13 ? 6'h0 : _T_429; // @[Lookup.scala 33:37]
  wire [5:0] _T_431 = _T_11 ? 6'h0 : _T_430; // @[Lookup.scala 33:37]
  wire [5:0] _T_432 = _T_9 ? 6'h0 : _T_431; // @[Lookup.scala 33:37]
  wire [5:0] _T_433 = _T_7 ? 6'h0 : _T_432; // @[Lookup.scala 33:37]
  wire [5:0] _T_434 = _T_5 ? 6'h0 : _T_433; // @[Lookup.scala 33:37]
  wire [5:0] _T_435 = _T_3 ? 6'h0 : _T_434; // @[Lookup.scala 33:37]
  wire [1:0] _T_444 = _T_109 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_445 = _T_107 ? 2'h3 : _T_444; // @[Lookup.scala 33:37]
  wire [1:0] _T_446 = _T_105 ? 2'h3 : _T_445; // @[Lookup.scala 33:37]
  wire [1:0] _T_447 = _T_103 ? 2'h3 : _T_446; // @[Lookup.scala 33:37]
  wire [1:0] _T_448 = _T_101 ? 2'h3 : _T_447; // @[Lookup.scala 33:37]
  wire [1:0] _T_449 = _T_99 ? 2'h3 : _T_448; // @[Lookup.scala 33:37]
  wire [1:0] _T_450 = _T_97 ? 2'h0 : _T_449; // @[Lookup.scala 33:37]
  wire [1:0] _T_451 = _T_95 ? 2'h0 : _T_450; // @[Lookup.scala 33:37]
  wire [1:0] _T_452 = _T_93 ? 2'h0 : _T_451; // @[Lookup.scala 33:37]
  wire [1:0] _T_453 = _T_91 ? 2'h0 : _T_452; // @[Lookup.scala 33:37]
  wire [1:0] _T_454 = _T_89 ? 2'h0 : _T_453; // @[Lookup.scala 33:37]
  wire [1:0] _T_455 = _T_87 ? 2'h0 : _T_454; // @[Lookup.scala 33:37]
  wire [1:0] _T_456 = _T_85 ? 2'h0 : _T_455; // @[Lookup.scala 33:37]
  wire [1:0] _T_457 = _T_83 ? 2'h0 : _T_456; // @[Lookup.scala 33:37]
  wire [1:0] _T_458 = _T_81 ? 2'h0 : _T_457; // @[Lookup.scala 33:37]
  wire [1:0] _T_459 = _T_79 ? 2'h0 : _T_458; // @[Lookup.scala 33:37]
  wire [1:0] _T_460 = _T_77 ? 2'h1 : _T_459; // @[Lookup.scala 33:37]
  wire [1:0] _T_461 = _T_75 ? 2'h1 : _T_460; // @[Lookup.scala 33:37]
  wire [1:0] _T_462 = _T_73 ? 2'h0 : _T_461; // @[Lookup.scala 33:37]
  wire [1:0] _T_463 = _T_71 ? 2'h0 : _T_462; // @[Lookup.scala 33:37]
  wire [1:0] _T_464 = _T_69 ? 2'h0 : _T_463; // @[Lookup.scala 33:37]
  wire [1:0] _T_465 = _T_67 ? 2'h0 : _T_464; // @[Lookup.scala 33:37]
  wire [1:0] _T_466 = _T_65 ? 2'h0 : _T_465; // @[Lookup.scala 33:37]
  wire [1:0] _T_467 = _T_63 ? 2'h0 : _T_466; // @[Lookup.scala 33:37]
  wire [1:0] _T_468 = _T_61 ? 2'h2 : _T_467; // @[Lookup.scala 33:37]
  wire [1:0] _T_469 = _T_59 ? 2'h2 : _T_468; // @[Lookup.scala 33:37]
  wire [1:0] _T_470 = _T_57 ? 2'h0 : _T_469; // @[Lookup.scala 33:37]
  wire [1:0] _T_471 = _T_55 ? 2'h0 : _T_470; // @[Lookup.scala 33:37]
  wire [1:0] _T_472 = _T_53 ? 2'h0 : _T_471; // @[Lookup.scala 33:37]
  wire [1:0] _T_473 = _T_51 ? 2'h0 : _T_472; // @[Lookup.scala 33:37]
  wire [1:0] _T_474 = _T_49 ? 2'h0 : _T_473; // @[Lookup.scala 33:37]
  wire [1:0] _T_475 = _T_47 ? 2'h0 : _T_474; // @[Lookup.scala 33:37]
  wire [1:0] _T_476 = _T_45 ? 2'h0 : _T_475; // @[Lookup.scala 33:37]
  wire [1:0] _T_477 = _T_43 ? 2'h0 : _T_476; // @[Lookup.scala 33:37]
  wire [1:0] _T_478 = _T_41 ? 2'h0 : _T_477; // @[Lookup.scala 33:37]
  wire [1:0] _T_479 = _T_39 ? 2'h0 : _T_478; // @[Lookup.scala 33:37]
  wire [1:0] _T_480 = _T_37 ? 2'h0 : _T_479; // @[Lookup.scala 33:37]
  wire [1:0] _T_481 = _T_35 ? 2'h0 : _T_480; // @[Lookup.scala 33:37]
  wire [1:0] _T_482 = _T_33 ? 2'h0 : _T_481; // @[Lookup.scala 33:37]
  wire [1:0] _T_483 = _T_31 ? 2'h0 : _T_482; // @[Lookup.scala 33:37]
  wire [1:0] _T_484 = _T_29 ? 2'h0 : _T_483; // @[Lookup.scala 33:37]
  wire [1:0] _T_485 = _T_27 ? 2'h0 : _T_484; // @[Lookup.scala 33:37]
  wire [1:0] _T_486 = _T_25 ? 2'h0 : _T_485; // @[Lookup.scala 33:37]
  wire [1:0] _T_487 = _T_23 ? 2'h0 : _T_486; // @[Lookup.scala 33:37]
  wire [1:0] _T_488 = _T_21 ? 2'h0 : _T_487; // @[Lookup.scala 33:37]
  wire [1:0] _T_489 = _T_19 ? 2'h0 : _T_488; // @[Lookup.scala 33:37]
  wire [1:0] _T_490 = _T_17 ? 2'h0 : _T_489; // @[Lookup.scala 33:37]
  wire [1:0] _T_491 = _T_15 ? 2'h0 : _T_490; // @[Lookup.scala 33:37]
  wire [1:0] _T_492 = _T_13 ? 2'h0 : _T_491; // @[Lookup.scala 33:37]
  wire [1:0] _T_493 = _T_11 ? 2'h0 : _T_492; // @[Lookup.scala 33:37]
  wire [1:0] _T_494 = _T_9 ? 2'h1 : _T_493; // @[Lookup.scala 33:37]
  wire [1:0] _T_495 = _T_7 ? 2'h1 : _T_494; // @[Lookup.scala 33:37]
  wire [1:0] _T_496 = _T_5 ? 2'h1 : _T_495; // @[Lookup.scala 33:37]
  wire [1:0] _T_497 = _T_3 ? 2'h1 : _T_496; // @[Lookup.scala 33:37]
  wire  _T_500 = _T_121 ? 1'h0 : _T_123 | _T_125; // @[Lookup.scala 33:37]
  wire  _T_501 = _T_119 ? 1'h0 : _T_500; // @[Lookup.scala 33:37]
  wire  _T_502 = _T_117 ? 1'h0 : _T_501; // @[Lookup.scala 33:37]
  wire  _T_503 = _T_115 ? 1'h0 : _T_502; // @[Lookup.scala 33:37]
  wire  _T_504 = _T_113 ? 1'h0 : _T_503; // @[Lookup.scala 33:37]
  wire  _T_505 = _T_111 ? 1'h0 : _T_504; // @[Lookup.scala 33:37]
  wire  _T_521 = _T_79 ? 1'h0 : _T_81 | (_T_83 | (_T_85 | (_T_87 | (_T_89 | (_T_91 | (_T_93 | (_T_95 | (_T_97 | (_T_99
     | (_T_101 | (_T_103 | (_T_105 | (_T_107 | (_T_109 | _T_505)))))))))))))); // @[Lookup.scala 33:37]
  wire  _T_524 = _T_73 ? 1'h0 : _T_75 | (_T_77 | _T_521); // @[Lookup.scala 33:37]
  wire  _T_525 = _T_71 ? 1'h0 : _T_524; // @[Lookup.scala 33:37]
  wire  _T_526 = _T_69 ? 1'h0 : _T_525; // @[Lookup.scala 33:37]
  wire  _T_527 = _T_67 ? 1'h0 : _T_526; // @[Lookup.scala 33:37]
  wire  _T_528 = _T_65 ? 1'h0 : _T_527; // @[Lookup.scala 33:37]
  wire  _T_529 = _T_63 ? 1'h0 : _T_528; // @[Lookup.scala 33:37]
  wire  _T_553 = _T_15 ? 1'h0 : _T_17 | (_T_19 | (_T_21 | (_T_23 | (_T_25 | (_T_27 | (_T_29 | (_T_31 | (_T_33 | (_T_35
     | (_T_37 | (_T_39 | (_T_41 | (_T_43 | (_T_45 | (_T_47 | (_T_49 | (_T_51 | (_T_53 | (_T_55 | (_T_57 | (_T_59 | (
    _T_61 | _T_529)))))))))))))))))))))); // @[Lookup.scala 33:37]
  wire  _T_554 = _T_13 ? 1'h0 : _T_553; // @[Lookup.scala 33:37]
  wire  _T_555 = _T_11 ? 1'h0 : _T_554; // @[Lookup.scala 33:37]
  wire  _T_563 = _T_119 ? 1'h0 : _T_121; // @[Lookup.scala 33:37]
  wire  _T_564 = _T_117 ? 1'h0 : _T_563; // @[Lookup.scala 33:37]
  wire  _T_565 = _T_115 ? 1'h0 : _T_564; // @[Lookup.scala 33:37]
  wire  _T_566 = _T_113 ? 1'h0 : _T_565; // @[Lookup.scala 33:37]
  wire  _T_567 = _T_111 ? 1'h0 : _T_566; // @[Lookup.scala 33:37]
  wire  _T_568 = _T_109 ? 1'h0 : _T_567; // @[Lookup.scala 33:37]
  wire  _T_569 = _T_107 ? 1'h0 : _T_568; // @[Lookup.scala 33:37]
  wire  _T_570 = _T_105 ? 1'h0 : _T_569; // @[Lookup.scala 33:37]
  wire  _T_571 = _T_103 ? 1'h0 : _T_570; // @[Lookup.scala 33:37]
  wire  _T_572 = _T_101 ? 1'h0 : _T_571; // @[Lookup.scala 33:37]
  wire  _T_573 = _T_99 ? 1'h0 : _T_572; // @[Lookup.scala 33:37]
  wire  _T_574 = _T_97 ? 1'h0 : _T_573; // @[Lookup.scala 33:37]
  wire  _T_575 = _T_95 ? 1'h0 : _T_574; // @[Lookup.scala 33:37]
  wire  _T_576 = _T_93 ? 1'h0 : _T_575; // @[Lookup.scala 33:37]
  wire  _T_577 = _T_91 ? 1'h0 : _T_576; // @[Lookup.scala 33:37]
  wire  _T_578 = _T_89 ? 1'h0 : _T_577; // @[Lookup.scala 33:37]
  wire  _T_579 = _T_87 ? 1'h0 : _T_578; // @[Lookup.scala 33:37]
  wire  _T_580 = _T_85 ? 1'h0 : _T_579; // @[Lookup.scala 33:37]
  wire  _T_581 = _T_83 ? 1'h0 : _T_580; // @[Lookup.scala 33:37]
  wire  _T_582 = _T_81 ? 1'h0 : _T_581; // @[Lookup.scala 33:37]
  wire  _T_586 = _T_73 ? 1'h0 : _T_75 | (_T_77 | (_T_79 | _T_582)); // @[Lookup.scala 33:37]
  wire  _T_587 = _T_71 ? 1'h0 : _T_586; // @[Lookup.scala 33:37]
  wire  _T_588 = _T_69 ? 1'h0 : _T_587; // @[Lookup.scala 33:37]
  wire  _T_589 = _T_67 ? 1'h0 : _T_588; // @[Lookup.scala 33:37]
  wire  _T_590 = _T_65 ? 1'h0 : _T_589; // @[Lookup.scala 33:37]
  wire  _T_591 = _T_63 ? 1'h0 : _T_590; // @[Lookup.scala 33:37]
  wire  _T_592 = _T_61 ? 1'h0 : _T_591; // @[Lookup.scala 33:37]
  wire  _T_593 = _T_59 ? 1'h0 : _T_592; // @[Lookup.scala 33:37]
  wire  _T_594 = _T_57 ? 1'h0 : _T_593; // @[Lookup.scala 33:37]
  wire  _T_595 = _T_55 ? 1'h0 : _T_594; // @[Lookup.scala 33:37]
  wire  _T_596 = _T_53 ? 1'h0 : _T_595; // @[Lookup.scala 33:37]
  wire  _T_597 = _T_51 ? 1'h0 : _T_596; // @[Lookup.scala 33:37]
  wire  _T_598 = _T_49 ? 1'h0 : _T_597; // @[Lookup.scala 33:37]
  wire  _T_599 = _T_47 ? 1'h0 : _T_598; // @[Lookup.scala 33:37]
  wire  _T_600 = _T_45 ? 1'h0 : _T_599; // @[Lookup.scala 33:37]
  wire  _T_601 = _T_43 ? 1'h0 : _T_600; // @[Lookup.scala 33:37]
  wire  _T_602 = _T_41 ? 1'h0 : _T_601; // @[Lookup.scala 33:37]
  wire  _T_603 = _T_39 ? 1'h0 : _T_602; // @[Lookup.scala 33:37]
  wire  _T_604 = _T_37 ? 1'h0 : _T_603; // @[Lookup.scala 33:37]
  wire  _T_605 = _T_35 ? 1'h0 : _T_604; // @[Lookup.scala 33:37]
  wire  _T_606 = _T_33 ? 1'h0 : _T_605; // @[Lookup.scala 33:37]
  wire  _T_607 = _T_31 ? 1'h0 : _T_606; // @[Lookup.scala 33:37]
  wire  _T_608 = _T_29 ? 1'h0 : _T_607; // @[Lookup.scala 33:37]
  wire  _T_609 = _T_27 ? 1'h0 : _T_608; // @[Lookup.scala 33:37]
  wire  _T_610 = _T_25 ? 1'h0 : _T_609; // @[Lookup.scala 33:37]
  wire  _T_611 = _T_23 ? 1'h0 : _T_610; // @[Lookup.scala 33:37]
  wire  _T_612 = _T_21 ? 1'h0 : _T_611; // @[Lookup.scala 33:37]
  wire  _T_613 = _T_19 ? 1'h0 : _T_612; // @[Lookup.scala 33:37]
  wire  _T_614 = _T_17 ? 1'h0 : _T_613; // @[Lookup.scala 33:37]
  wire  _T_646 = _T_77 ? 1'h0 : _T_79; // @[Lookup.scala 33:37]
  wire  _T_647 = _T_75 ? 1'h0 : _T_646; // @[Lookup.scala 33:37]
  wire  _T_648 = _T_73 ? 1'h0 : _T_647; // @[Lookup.scala 33:37]
  wire  _T_649 = _T_71 ? 1'h0 : _T_648; // @[Lookup.scala 33:37]
  wire  _T_650 = _T_69 ? 1'h0 : _T_649; // @[Lookup.scala 33:37]
  wire  _T_651 = _T_67 ? 1'h0 : _T_650; // @[Lookup.scala 33:37]
  wire  _T_652 = _T_65 ? 1'h0 : _T_651; // @[Lookup.scala 33:37]
  wire  _T_653 = _T_63 ? 1'h0 : _T_652; // @[Lookup.scala 33:37]
  wire  _T_654 = _T_61 ? 1'h0 : _T_653; // @[Lookup.scala 33:37]
  wire  _T_655 = _T_59 ? 1'h0 : _T_654; // @[Lookup.scala 33:37]
  wire  _T_656 = _T_57 ? 1'h0 : _T_655; // @[Lookup.scala 33:37]
  wire  _T_657 = _T_55 ? 1'h0 : _T_656; // @[Lookup.scala 33:37]
  wire  _T_658 = _T_53 ? 1'h0 : _T_657; // @[Lookup.scala 33:37]
  wire  _T_659 = _T_51 ? 1'h0 : _T_658; // @[Lookup.scala 33:37]
  wire  _T_660 = _T_49 ? 1'h0 : _T_659; // @[Lookup.scala 33:37]
  wire  _T_661 = _T_47 ? 1'h0 : _T_660; // @[Lookup.scala 33:37]
  wire  _T_662 = _T_45 ? 1'h0 : _T_661; // @[Lookup.scala 33:37]
  wire  _T_663 = _T_43 ? 1'h0 : _T_662; // @[Lookup.scala 33:37]
  wire  _T_664 = _T_41 ? 1'h0 : _T_663; // @[Lookup.scala 33:37]
  wire  _T_665 = _T_39 ? 1'h0 : _T_664; // @[Lookup.scala 33:37]
  wire  _T_666 = _T_37 ? 1'h0 : _T_665; // @[Lookup.scala 33:37]
  wire  _T_667 = _T_35 ? 1'h0 : _T_666; // @[Lookup.scala 33:37]
  wire  _T_668 = _T_33 ? 1'h0 : _T_667; // @[Lookup.scala 33:37]
  wire  _T_669 = _T_31 ? 1'h0 : _T_668; // @[Lookup.scala 33:37]
  wire  _T_670 = _T_29 ? 1'h0 : _T_669; // @[Lookup.scala 33:37]
  wire  _T_671 = _T_27 ? 1'h0 : _T_670; // @[Lookup.scala 33:37]
  wire  _T_672 = _T_25 ? 1'h0 : _T_671; // @[Lookup.scala 33:37]
  wire  _T_673 = _T_23 ? 1'h0 : _T_672; // @[Lookup.scala 33:37]
  wire  _T_674 = _T_21 ? 1'h0 : _T_673; // @[Lookup.scala 33:37]
  wire  _T_675 = _T_19 ? 1'h0 : _T_674; // @[Lookup.scala 33:37]
  wire  _T_676 = _T_17 ? 1'h0 : _T_675; // @[Lookup.scala 33:37]
  wire  _T_680 = _T_9 ? 1'h0 : _T_11 | (_T_13 | (_T_15 | _T_676)); // @[Lookup.scala 33:37]
  wire  _T_681 = _T_7 ? 1'h0 : _T_680; // @[Lookup.scala 33:37]
  wire  _T_682 = _T_5 ? 1'h0 : _T_681; // @[Lookup.scala 33:37]
  wire  _T_683 = _T_3 ? 1'h0 : _T_682; // @[Lookup.scala 33:37]
  wire [2:0] _T_707 = _T_79 ? 3'h4 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_708 = _T_77 ? 3'h4 : _T_707; // @[Lookup.scala 33:37]
  wire [2:0] _T_709 = _T_75 ? 3'h7 : _T_708; // @[Lookup.scala 33:37]
  wire [2:0] _T_710 = _T_73 ? 3'h0 : _T_709; // @[Lookup.scala 33:37]
  wire [2:0] _T_711 = _T_71 ? 3'h0 : _T_710; // @[Lookup.scala 33:37]
  wire [2:0] _T_712 = _T_69 ? 3'h0 : _T_711; // @[Lookup.scala 33:37]
  wire [2:0] _T_713 = _T_67 ? 3'h0 : _T_712; // @[Lookup.scala 33:37]
  wire [2:0] _T_714 = _T_65 ? 3'h0 : _T_713; // @[Lookup.scala 33:37]
  wire [2:0] _T_715 = _T_63 ? 3'h0 : _T_714; // @[Lookup.scala 33:37]
  wire [2:0] _T_716 = _T_61 ? 3'h0 : _T_715; // @[Lookup.scala 33:37]
  wire [2:0] _T_717 = _T_59 ? 3'h0 : _T_716; // @[Lookup.scala 33:37]
  wire [2:0] _T_718 = _T_57 ? 3'h0 : _T_717; // @[Lookup.scala 33:37]
  wire [2:0] _T_719 = _T_55 ? 3'h0 : _T_718; // @[Lookup.scala 33:37]
  wire [2:0] _T_720 = _T_53 ? 3'h0 : _T_719; // @[Lookup.scala 33:37]
  wire [2:0] _T_721 = _T_51 ? 3'h0 : _T_720; // @[Lookup.scala 33:37]
  wire [2:0] _T_722 = _T_49 ? 3'h0 : _T_721; // @[Lookup.scala 33:37]
  wire [2:0] _T_723 = _T_47 ? 3'h0 : _T_722; // @[Lookup.scala 33:37]
  wire [2:0] _T_724 = _T_45 ? 3'h0 : _T_723; // @[Lookup.scala 33:37]
  wire [2:0] _T_725 = _T_43 ? 3'h0 : _T_724; // @[Lookup.scala 33:37]
  wire [2:0] _T_726 = _T_41 ? 3'h0 : _T_725; // @[Lookup.scala 33:37]
  wire [2:0] _T_727 = _T_39 ? 3'h0 : _T_726; // @[Lookup.scala 33:37]
  wire [2:0] _T_728 = _T_37 ? 3'h0 : _T_727; // @[Lookup.scala 33:37]
  wire [2:0] _T_729 = _T_35 ? 3'h0 : _T_728; // @[Lookup.scala 33:37]
  wire [2:0] _T_730 = _T_33 ? 3'h0 : _T_729; // @[Lookup.scala 33:37]
  wire [2:0] _T_731 = _T_31 ? 3'h0 : _T_730; // @[Lookup.scala 33:37]
  wire [2:0] _T_732 = _T_29 ? 3'h0 : _T_731; // @[Lookup.scala 33:37]
  wire [2:0] _T_733 = _T_27 ? 3'h0 : _T_732; // @[Lookup.scala 33:37]
  wire [2:0] _T_734 = _T_25 ? 3'h0 : _T_733; // @[Lookup.scala 33:37]
  wire [2:0] _T_735 = _T_23 ? 3'h0 : _T_734; // @[Lookup.scala 33:37]
  wire [2:0] _T_736 = _T_21 ? 3'h0 : _T_735; // @[Lookup.scala 33:37]
  wire [2:0] _T_737 = _T_19 ? 3'h0 : _T_736; // @[Lookup.scala 33:37]
  wire [2:0] _T_738 = _T_17 ? 3'h0 : _T_737; // @[Lookup.scala 33:37]
  wire [2:0] _T_739 = _T_15 ? 3'h2 : _T_738; // @[Lookup.scala 33:37]
  wire [2:0] _T_740 = _T_13 ? 3'h1 : _T_739; // @[Lookup.scala 33:37]
  wire [2:0] _T_741 = _T_11 ? 3'h3 : _T_740; // @[Lookup.scala 33:37]
  wire [2:0] _T_742 = _T_9 ? 3'h6 : _T_741; // @[Lookup.scala 33:37]
  wire [2:0] _T_743 = _T_7 ? 3'h2 : _T_742; // @[Lookup.scala 33:37]
  wire [2:0] _T_744 = _T_5 ? 3'h5 : _T_743; // @[Lookup.scala 33:37]
  wire [2:0] _T_745 = _T_3 ? 3'h1 : _T_744; // @[Lookup.scala 33:37]
  wire [2:0] _T_751 = _T_115 ? 3'h6 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_752 = _T_113 ? 3'h4 : _T_751; // @[Lookup.scala 33:37]
  wire [2:0] _T_753 = _T_111 ? 3'h5 : _T_752; // @[Lookup.scala 33:37]
  wire [2:0] _T_754 = _T_109 ? 3'h3 : _T_753; // @[Lookup.scala 33:37]
  wire [2:0] _T_755 = _T_107 ? 3'h2 : _T_754; // @[Lookup.scala 33:37]
  wire [2:0] _T_756 = _T_105 ? 3'h1 : _T_755; // @[Lookup.scala 33:37]
  wire [2:0] _T_757 = _T_103 ? 3'h3 : _T_756; // @[Lookup.scala 33:37]
  wire [2:0] _T_758 = _T_101 ? 3'h2 : _T_757; // @[Lookup.scala 33:37]
  wire [2:0] _T_759 = _T_99 ? 3'h1 : _T_758; // @[Lookup.scala 33:37]
  wire [2:0] _T_760 = _T_97 ? 3'h0 : _T_759; // @[Lookup.scala 33:37]
  wire [2:0] _T_761 = _T_95 ? 3'h0 : _T_760; // @[Lookup.scala 33:37]
  wire [2:0] _T_762 = _T_93 ? 3'h0 : _T_761; // @[Lookup.scala 33:37]
  wire [2:0] _T_763 = _T_91 ? 3'h0 : _T_762; // @[Lookup.scala 33:37]
  wire [2:0] _T_764 = _T_89 ? 3'h0 : _T_763; // @[Lookup.scala 33:37]
  wire [2:0] _T_765 = _T_87 ? 3'h0 : _T_764; // @[Lookup.scala 33:37]
  wire [2:0] _T_766 = _T_85 ? 3'h0 : _T_765; // @[Lookup.scala 33:37]
  wire [2:0] _T_767 = _T_83 ? 3'h0 : _T_766; // @[Lookup.scala 33:37]
  wire [2:0] _T_768 = _T_81 ? 3'h0 : _T_767; // @[Lookup.scala 33:37]
  wire [2:0] _T_769 = _T_79 ? 3'h0 : _T_768; // @[Lookup.scala 33:37]
  wire [2:0] _T_770 = _T_77 ? 3'h0 : _T_769; // @[Lookup.scala 33:37]
  wire [2:0] _T_771 = _T_75 ? 3'h0 : _T_770; // @[Lookup.scala 33:37]
  wire [2:0] _T_772 = _T_73 ? 3'h0 : _T_771; // @[Lookup.scala 33:37]
  wire [2:0] _T_773 = _T_71 ? 3'h0 : _T_772; // @[Lookup.scala 33:37]
  wire [2:0] _T_774 = _T_69 ? 3'h0 : _T_773; // @[Lookup.scala 33:37]
  wire [2:0] _T_775 = _T_67 ? 3'h0 : _T_774; // @[Lookup.scala 33:37]
  wire [2:0] _T_776 = _T_65 ? 3'h0 : _T_775; // @[Lookup.scala 33:37]
  wire [2:0] _T_777 = _T_63 ? 3'h0 : _T_776; // @[Lookup.scala 33:37]
  wire [2:0] _T_778 = _T_61 ? 3'h0 : _T_777; // @[Lookup.scala 33:37]
  wire [2:0] _T_779 = _T_59 ? 3'h0 : _T_778; // @[Lookup.scala 33:37]
  wire [2:0] _T_780 = _T_57 ? 3'h0 : _T_779; // @[Lookup.scala 33:37]
  wire [2:0] _T_781 = _T_55 ? 3'h0 : _T_780; // @[Lookup.scala 33:37]
  wire [2:0] _T_782 = _T_53 ? 3'h0 : _T_781; // @[Lookup.scala 33:37]
  wire [2:0] _T_783 = _T_51 ? 3'h0 : _T_782; // @[Lookup.scala 33:37]
  wire [2:0] _T_784 = _T_49 ? 3'h0 : _T_783; // @[Lookup.scala 33:37]
  wire [2:0] _T_785 = _T_47 ? 3'h0 : _T_784; // @[Lookup.scala 33:37]
  wire [2:0] _T_786 = _T_45 ? 3'h0 : _T_785; // @[Lookup.scala 33:37]
  wire [2:0] _T_787 = _T_43 ? 3'h0 : _T_786; // @[Lookup.scala 33:37]
  wire [2:0] _T_788 = _T_41 ? 3'h0 : _T_787; // @[Lookup.scala 33:37]
  wire [2:0] _T_789 = _T_39 ? 3'h0 : _T_788; // @[Lookup.scala 33:37]
  wire [2:0] _T_790 = _T_37 ? 3'h0 : _T_789; // @[Lookup.scala 33:37]
  wire [2:0] _T_791 = _T_35 ? 3'h0 : _T_790; // @[Lookup.scala 33:37]
  wire [2:0] _T_792 = _T_33 ? 3'h0 : _T_791; // @[Lookup.scala 33:37]
  wire [2:0] _T_793 = _T_31 ? 3'h0 : _T_792; // @[Lookup.scala 33:37]
  wire [2:0] _T_794 = _T_29 ? 3'h0 : _T_793; // @[Lookup.scala 33:37]
  wire [2:0] _T_795 = _T_27 ? 3'h0 : _T_794; // @[Lookup.scala 33:37]
  wire [2:0] _T_796 = _T_25 ? 3'h0 : _T_795; // @[Lookup.scala 33:37]
  wire [2:0] _T_797 = _T_23 ? 3'h0 : _T_796; // @[Lookup.scala 33:37]
  wire [2:0] _T_798 = _T_21 ? 3'h0 : _T_797; // @[Lookup.scala 33:37]
  wire [2:0] _T_799 = _T_19 ? 3'h0 : _T_798; // @[Lookup.scala 33:37]
  wire [2:0] _T_800 = _T_17 ? 3'h0 : _T_799; // @[Lookup.scala 33:37]
  wire [2:0] _T_801 = _T_15 ? 3'h0 : _T_800; // @[Lookup.scala 33:37]
  wire [2:0] _T_802 = _T_13 ? 3'h0 : _T_801; // @[Lookup.scala 33:37]
  wire [2:0] _T_803 = _T_11 ? 3'h0 : _T_802; // @[Lookup.scala 33:37]
  wire [2:0] _T_804 = _T_9 ? 3'h0 : _T_803; // @[Lookup.scala 33:37]
  wire [2:0] _T_805 = _T_7 ? 3'h0 : _T_804; // @[Lookup.scala 33:37]
  wire [2:0] _T_806 = _T_5 ? 3'h0 : _T_805; // @[Lookup.scala 33:37]
  wire [2:0] _T_807 = _T_3 ? 3'h0 : _T_806; // @[Lookup.scala 33:37]
  wire  is_trap = 32'h6b == _T; // @[IDU.scala 125:27]
  assign io_ctrl_br_type = _T_1 ? 4'h0 : _T_249; // @[Lookup.scala 33:37]
  assign io_ctrl_op1_sel = _T_1 ? 2'h0 : _T_311; // @[Lookup.scala 33:37]
  assign io_ctrl_op2_sel = _T_1 ? 2'h1 : _T_373; // @[Lookup.scala 33:37]
  assign io_ctrl_alu_op = _T_1 ? 6'h0 : _T_435; // @[Lookup.scala 33:37]
  assign io_ctrl_wb_sel = _T_1 ? 2'h1 : _T_497; // @[Lookup.scala 33:37]
  assign io_ctrl_rf_wen = _T_1 | (_T_3 | (_T_5 | (_T_7 | (_T_9 | _T_555)))); // @[Lookup.scala 33:37]
  assign io_ctrl_mem_en = _T_1 | (_T_3 | (_T_5 | (_T_7 | (_T_9 | (_T_11 | (_T_13 | (_T_15 | _T_614))))))); // @[Lookup.scala 33:37]
  assign io_ctrl_mem_wr = _T_1 ? 1'h0 : _T_683; // @[Lookup.scala 33:37]
  assign io_ctrl_mem_msk = _T_1 ? 3'h3 : _T_745; // @[Lookup.scala 33:37]
  assign io_ctrl_csr_cmd = _T_1 ? 3'h0 : _T_807; // @[Lookup.scala 33:37]
endmodule
module ID_TOP(
  input         clock,
  input         reset,
  output        io_fs_ready,
  input         io_fs_valid,
  input  [63:0] io_fs_bits_PC,
  input  [31:0] io_fs_bits_inst,
  input         io_es_ready,
  output        io_es_valid,
  output [63:0] io_es_bits_PC,
  output [31:0] io_es_bits_inst,
  output [1:0]  io_es_bits_decode_op1_sel,
  output [1:0]  io_es_bits_decode_op2_sel,
  output [5:0]  io_es_bits_decode_alu_op,
  output [1:0]  io_es_bits_decode_wb_sel,
  output        io_es_bits_decode_rf_wen,
  output        io_es_bits_decode_mem_en,
  output        io_es_bits_decode_mem_wr,
  output [2:0]  io_es_bits_decode_mem_msk,
  output [2:0]  io_es_bits_decode_csr_cmd,
  output [63:0] io_es_bits_rs1_data,
  output [63:0] io_es_bits_rs2_data,
  input         io_wb_rf_we,
  input  [4:0]  io_wb_wr_addr,
  input  [63:0] io_wb_wr_data,
  input  [1:0]  io_wb_wb_sel,
  input         ms_res_rf_we,
  input  [4:0]  ms_res_wr_addr,
  input  [63:0] ms_res_wr_data,
  input  [1:0]  ms_res_wb_sel,
  input         io_dmem_resp_valid,
  input  [63:0] mepc_0,
  output [63:0] from_fs_r_PC,
  output        br_taken_final_0,
  input  [1:0]  insts_sent_after_br_0,
  input         es_res_rf_we,
  input  [4:0]  es_res_wr_addr,
  input  [63:0] es_res_wr_data,
  input  [1:0]  es_res_wb_sel,
  input  [63:0] exc_addr_0,
  output [63:0] br_target_0,
  input         exception_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  wire  rf_clock; // @[ID_TOP.scala 18:20]
  wire [4:0] rf_io_rs1_addr; // @[ID_TOP.scala 18:20]
  wire [4:0] rf_io_rs2_addr; // @[ID_TOP.scala 18:20]
  wire  rf_io_ws_res_rf_we; // @[ID_TOP.scala 18:20]
  wire [4:0] rf_io_ws_res_wr_addr; // @[ID_TOP.scala 18:20]
  wire [63:0] rf_io_ws_res_wr_data; // @[ID_TOP.scala 18:20]
  wire [1:0] rf_io_ws_res_wb_sel; // @[ID_TOP.scala 18:20]
  wire [63:0] rf_io_rs1_data; // @[ID_TOP.scala 18:20]
  wire [63:0] rf_io_rs2_data; // @[ID_TOP.scala 18:20]
  wire  rf_io_wr_stall; // @[ID_TOP.scala 18:20]
  wire  rf_ms_res_0_rf_we; // @[ID_TOP.scala 18:20]
  wire [4:0] rf_ms_res_0_wr_addr; // @[ID_TOP.scala 18:20]
  wire [63:0] rf_ms_res_0_wr_data; // @[ID_TOP.scala 18:20]
  wire [1:0] rf_ms_res_0_wb_sel; // @[ID_TOP.scala 18:20]
  wire  rf_load_data_returned; // @[ID_TOP.scala 18:20]
  wire  rf_es_res_0_rf_we; // @[ID_TOP.scala 18:20]
  wire [4:0] rf_es_res_0_wr_addr; // @[ID_TOP.scala 18:20]
  wire [63:0] rf_es_res_0_wr_data; // @[ID_TOP.scala 18:20]
  wire [1:0] rf_es_res_0_wb_sel; // @[ID_TOP.scala 18:20]
  wire [31:0] idu_io_inst; // @[ID_TOP.scala 31:21]
  wire [3:0] idu_io_ctrl_br_type; // @[ID_TOP.scala 31:21]
  wire [1:0] idu_io_ctrl_op1_sel; // @[ID_TOP.scala 31:21]
  wire [1:0] idu_io_ctrl_op2_sel; // @[ID_TOP.scala 31:21]
  wire [5:0] idu_io_ctrl_alu_op; // @[ID_TOP.scala 31:21]
  wire [1:0] idu_io_ctrl_wb_sel; // @[ID_TOP.scala 31:21]
  wire  idu_io_ctrl_rf_wen; // @[ID_TOP.scala 31:21]
  wire  idu_io_ctrl_mem_en; // @[ID_TOP.scala 31:21]
  wire  idu_io_ctrl_mem_wr; // @[ID_TOP.scala 31:21]
  wire [2:0] idu_io_ctrl_mem_msk; // @[ID_TOP.scala 31:21]
  wire [2:0] idu_io_ctrl_csr_cmd; // @[ID_TOP.scala 31:21]
  wire  _T = io_fs_valid & io_fs_ready; // @[ID_TOP.scala 20:86]
  reg [63:0] from_fs_r__PC; // @[Reg.scala 27:20]
  reg [31:0] from_fs_r__inst; // @[Reg.scala 27:20]
  wire  ds_ready_go = ~rf_io_wr_stall; // @[ID_TOP.scala 23:23]
  reg  ds_valid; // @[Reg.scala 27:20]
  wire [11:0] imm_i = from_fs_r__inst[31:20]; // @[ID_TOP.scala 48:21]
  wire  right_right = from_fs_r__inst[31]; // @[ID_TOP.scala 49:25]
  wire  right_left = from_fs_r__inst[7]; // @[ID_TOP.scala 49:35]
  wire [5:0] left_right = from_fs_r__inst[30:25]; // @[ID_TOP.scala 49:44]
  wire [3:0] left_left = from_fs_r__inst[11:8]; // @[ID_TOP.scala 49:57]
  wire [11:0] imm_b = {right_right,right_left,left_right,left_left}; // @[Cat.scala 29:58]
  wire [7:0] right_left_1 = from_fs_r__inst[19:12]; // @[ID_TOP.scala 50:35]
  wire  left_right_1 = from_fs_r__inst[20]; // @[ID_TOP.scala 50:48]
  wire [9:0] left_left_1 = from_fs_r__inst[30:21]; // @[ID_TOP.scala 50:58]
  wire [19:0] imm_j = {right_right,right_left_1,left_right_1,left_left_1}; // @[Cat.scala 29:58]
  wire [51:0] right_2 = imm_i[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_i_sext = {right_2,imm_i}; // @[Cat.scala 29:58]
  wire [52:0] right_right_2 = imm_b[11] ? 53'h1fffffffffffff : 53'h0; // @[Bitwise.scala 72:12]
  wire [65:0] imm_b_sext = {right_right_2,right_right,right_left,left_right,left_left,1'h0}; // @[Cat.scala 29:58]
  wire [52:0] right_right_3 = imm_j[19] ? 53'h1fffffffffffff : 53'h0; // @[Bitwise.scala 72:12]
  wire [73:0] imm_j_sext = {right_right_3,right_right,right_left_1,left_right_1,left_left_1,1'h0}; // @[Cat.scala 29:58]
  wire [65:0] _GEN_12 = {{2'd0}, from_fs_r__PC}; // @[ID_TOP.scala 55:39]
  wire [65:0] branch_target = _GEN_12 + imm_b_sext; // @[ID_TOP.scala 55:39]
  wire [73:0] _GEN_13 = {{10'd0}, from_fs_r__PC}; // @[ID_TOP.scala 56:35]
  wire [73:0] jmp_target = _GEN_13 + imm_j_sext; // @[ID_TOP.scala 56:35]
  wire [63:0] jr_target = rf_io_rs1_data + imm_i_sext; // @[ID_TOP.scala 57:37]
  wire  rf_eq = rf_io_rs1_data == rf_io_rs2_data; // @[ID_TOP.scala 59:34]
  wire  rf_lt = $signed(rf_io_rs1_data) < $signed(rf_io_rs2_data); // @[ID_TOP.scala 60:43]
  wire  rf_ltu = rf_io_rs1_data < rf_io_rs2_data; // @[ID_TOP.scala 61:43]
  wire  _br_taken_T_1 = idu_io_ctrl_br_type == 4'h2 & rf_eq; // @[ID_TOP.scala 75:34]
  wire  _br_taken_T_4 = idu_io_ctrl_br_type == 4'h1 & ~rf_eq; // @[ID_TOP.scala 76:34]
  wire  _br_taken_T_7 = idu_io_ctrl_br_type == 4'h3 & ~rf_lt; // @[ID_TOP.scala 77:34]
  wire  _br_taken_T_10 = idu_io_ctrl_br_type == 4'h4 & ~rf_ltu; // @[ID_TOP.scala 78:34]
  wire  _br_taken_T_12 = idu_io_ctrl_br_type == 4'h5 & rf_lt; // @[ID_TOP.scala 79:34]
  wire  _br_taken_T_14 = idu_io_ctrl_br_type == 4'h6 & rf_ltu; // @[ID_TOP.scala 80:34]
  wire  _br_taken_T_15 = idu_io_ctrl_br_type == 4'h7; // @[ID_TOP.scala 81:23]
  wire  _br_taken_T_16 = idu_io_ctrl_br_type == 4'h8; // @[ID_TOP.scala 82:23]
  wire  _br_taken_T_17 = idu_io_ctrl_csr_cmd == 3'h4; // @[ID_TOP.scala 83:23]
  wire  br_taken = exception_0 | (_br_taken_T_1 | (_br_taken_T_4 | (_br_taken_T_7 | (_br_taken_T_10 | (_br_taken_T_12 |
    (_br_taken_T_14 | (_br_taken_T_15 | (_br_taken_T_16 | _br_taken_T_17)))))))); // @[Mux.scala 98:16]
  wire [65:0] _br_target_T_3 = _br_taken_T_17 ? {{2'd0}, mepc_0} : branch_target; // @[Mux.scala 98:16]
  wire [65:0] _br_target_T_4 = _br_taken_T_16 ? {{2'd0}, jr_target} : _br_target_T_3; // @[Mux.scala 98:16]
  wire [73:0] _br_target_T_5 = _br_taken_T_15 ? jmp_target : {{8'd0}, _br_target_T_4}; // @[Mux.scala 98:16]
  wire [73:0] _br_target_T_6 = exception_0 ? {{10'd0}, exc_addr_0} : _br_target_T_5; // @[Mux.scala 98:16]
  wire  br_taken_final = rf_io_wr_stall ? 1'h0 : br_taken & ds_valid; // @[ID_TOP.scala 92:29]
  reg  flush_set; // @[ID_TOP.scala 102:28]
  reg [1:0] flush_reg; // @[ID_TOP.scala 103:28]
  wire  _T_15 = ~flush_set; // @[ID_TOP.scala 104:52]
  wire  insts_sent_after_br = insts_sent_after_br_0[0];
  wire  _flush_reg_T_1 = insts_sent_after_br - 1'h1; // @[ID_TOP.scala 105:42]
  wire [1:0] _flush_reg_T_3 = flush_reg - 2'h1; // @[ID_TOP.scala 111:32]
  wire  _flush_set_T = flush_reg == 2'h0; // @[ID_TOP.scala 112:36]
  wire  _flush_set_T_1 = flush_reg == 2'h0 ? 1'h0 : flush_set; // @[ID_TOP.scala 112:25]
  wire  _GEN_3 = _T & _flush_set_T ? 1'h0 : flush_set; // @[ID_TOP.scala 113:64 ID_TOP.scala 114:19 ID_TOP.scala 102:28]
  wire  _GEN_5 = _T & flush_reg > 2'h0 ? _flush_set_T_1 : _GEN_3; // @[ID_TOP.scala 110:62 ID_TOP.scala 112:19]
  wire  _GEN_7 = br_taken & _T_15 | _GEN_5; // @[ID_TOP.scala 107:40 ID_TOP.scala 109:19]
  wire  _GEN_9 = br_taken & io_fs_valid & io_fs_ready & ~flush_set | _GEN_7; // @[ID_TOP.scala 104:63 ID_TOP.scala 106:19]
  wire [63:0] br_target = _br_target_T_6[63:0]; // @[ID_TOP.scala 65:25 ID_TOP.scala 85:14]
  ForwardUnit rf ( // @[ID_TOP.scala 18:20]
    .clock(rf_clock),
    .io_rs1_addr(rf_io_rs1_addr),
    .io_rs2_addr(rf_io_rs2_addr),
    .io_ws_res_rf_we(rf_io_ws_res_rf_we),
    .io_ws_res_wr_addr(rf_io_ws_res_wr_addr),
    .io_ws_res_wr_data(rf_io_ws_res_wr_data),
    .io_ws_res_wb_sel(rf_io_ws_res_wb_sel),
    .io_rs1_data(rf_io_rs1_data),
    .io_rs2_data(rf_io_rs2_data),
    .io_wr_stall(rf_io_wr_stall),
    .ms_res_0_rf_we(rf_ms_res_0_rf_we),
    .ms_res_0_wr_addr(rf_ms_res_0_wr_addr),
    .ms_res_0_wr_data(rf_ms_res_0_wr_data),
    .ms_res_0_wb_sel(rf_ms_res_0_wb_sel),
    .load_data_returned(rf_load_data_returned),
    .es_res_0_rf_we(rf_es_res_0_rf_we),
    .es_res_0_wr_addr(rf_es_res_0_wr_addr),
    .es_res_0_wr_data(rf_es_res_0_wr_data),
    .es_res_0_wb_sel(rf_es_res_0_wb_sel)
  );
  IDU idu ( // @[ID_TOP.scala 31:21]
    .io_inst(idu_io_inst),
    .io_ctrl_br_type(idu_io_ctrl_br_type),
    .io_ctrl_op1_sel(idu_io_ctrl_op1_sel),
    .io_ctrl_op2_sel(idu_io_ctrl_op2_sel),
    .io_ctrl_alu_op(idu_io_ctrl_alu_op),
    .io_ctrl_wb_sel(idu_io_ctrl_wb_sel),
    .io_ctrl_rf_wen(idu_io_ctrl_rf_wen),
    .io_ctrl_mem_en(idu_io_ctrl_mem_en),
    .io_ctrl_mem_wr(idu_io_ctrl_mem_wr),
    .io_ctrl_mem_msk(idu_io_ctrl_mem_msk),
    .io_ctrl_csr_cmd(idu_io_ctrl_csr_cmd)
  );
  assign io_fs_ready = ~ds_valid | ds_ready_go & io_es_ready; // @[ID_TOP.scala 26:30]
  assign io_es_valid = ds_valid & ds_ready_go; // @[ID_TOP.scala 27:29]
  assign io_es_bits_PC = from_fs_r__PC; // @[ID_TOP.scala 41:25]
  assign io_es_bits_inst = from_fs_r__inst; // @[ID_TOP.scala 42:25]
  assign io_es_bits_decode_op1_sel = idu_io_ctrl_op1_sel; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_op2_sel = idu_io_ctrl_op2_sel; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_alu_op = idu_io_ctrl_alu_op; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_wb_sel = idu_io_ctrl_wb_sel; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_rf_wen = idu_io_ctrl_rf_wen; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_mem_en = idu_io_ctrl_mem_en; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_mem_wr = idu_io_ctrl_mem_wr; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_mem_msk = idu_io_ctrl_mem_msk; // @[ID_TOP.scala 43:25]
  assign io_es_bits_decode_csr_cmd = idu_io_ctrl_csr_cmd; // @[ID_TOP.scala 43:25]
  assign io_es_bits_rs1_data = rf_io_rs1_data; // @[ID_TOP.scala 44:25]
  assign io_es_bits_rs2_data = rf_io_rs2_data; // @[ID_TOP.scala 45:25]
  assign from_fs_r_PC = from_fs_r__PC;
  assign br_taken_final_0 = br_taken_final;
  assign br_target_0 = br_target;
  assign rf_clock = clock;
  assign rf_io_rs1_addr = from_fs_r__inst[19:15]; // @[ID_TOP.scala 37:30]
  assign rf_io_rs2_addr = from_fs_r__inst[24:20]; // @[ID_TOP.scala 38:30]
  assign rf_io_ws_res_rf_we = io_wb_rf_we; // @[ID_TOP.scala 36:23]
  assign rf_io_ws_res_wr_addr = io_wb_wr_addr; // @[ID_TOP.scala 36:23]
  assign rf_io_ws_res_wr_data = io_wb_wr_data; // @[ID_TOP.scala 36:23]
  assign rf_io_ws_res_wb_sel = io_wb_wb_sel; // @[ID_TOP.scala 36:23]
  assign rf_ms_res_0_rf_we = ms_res_rf_we;
  assign rf_ms_res_0_wr_addr = ms_res_wr_addr;
  assign rf_ms_res_0_wr_data = ms_res_wr_data;
  assign rf_ms_res_0_wb_sel = ms_res_wb_sel;
  assign rf_load_data_returned = io_dmem_resp_valid;
  assign rf_es_res_0_rf_we = es_res_rf_we;
  assign rf_es_res_0_wr_addr = es_res_wr_addr;
  assign rf_es_res_0_wr_data = es_res_wr_data;
  assign rf_es_res_0_wb_sel = es_res_wb_sel;
  assign idu_io_inst = from_fs_r__inst; // @[ID_TOP.scala 32:17]
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      from_fs_r__PC <= 64'h0; // @[Reg.scala 27:20]
    end else if (flush_reg != 2'h0) begin // @[ID_TOP.scala 117:28]
      from_fs_r__PC <= 64'h0; // @[ID_TOP.scala 118:19]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_fs_r__PC <= io_fs_bits_PC; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_fs_r__inst <= 32'h0; // @[Reg.scala 27:20]
    end else if (flush_reg != 2'h0) begin // @[ID_TOP.scala 117:28]
      from_fs_r__inst <= 32'h0; // @[ID_TOP.scala 118:19]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_fs_r__inst <= io_fs_bits_inst; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      ds_valid <= 1'h0; // @[Reg.scala 27:20]
    end else if (io_fs_ready) begin // @[Reg.scala 28:19]
      ds_valid <= io_fs_valid; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[ID_TOP.scala 102:28]
      flush_set <= 1'h0; // @[ID_TOP.scala 102:28]
    end else begin
      flush_set <= _GEN_9;
    end
    if (reset) begin // @[ID_TOP.scala 103:28]
      flush_reg <= 2'h0; // @[ID_TOP.scala 103:28]
    end else if (br_taken & io_fs_valid & io_fs_ready & ~flush_set) begin // @[ID_TOP.scala 104:63]
      flush_reg <= {{1'd0}, _flush_reg_T_1}; // @[ID_TOP.scala 105:19]
    end else if (br_taken & _T_15) begin // @[ID_TOP.scala 107:40]
      flush_reg <= {{1'd0}, insts_sent_after_br}; // @[ID_TOP.scala 108:19]
    end else if (_T & flush_reg > 2'h0) begin // @[ID_TOP.scala 110:62]
      flush_reg <= _flush_reg_T_3; // @[ID_TOP.scala 111:19]
    end
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  from_fs_r__PC = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  from_fs_r__inst = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  ds_valid = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  flush_set = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  flush_reg = _RAND_4[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ALU(
  input  [5:0]  io_opcode,
  input  [63:0] io_in1,
  input  [63:0] io_in2,
  output [63:0] io_out
);
  wire [63:0] _T_1 = ~io_in2; // @[ALU.scala 19:45]
  wire [63:0] add2 = io_opcode[4] ? _T_1 : io_in2; // @[ALU.scala 19:25]
  wire [64:0] _T_3 = io_in1 + add2; // @[ALU.scala 21:29]
  wire [64:0] _GEN_0 = {{64'd0}, io_opcode[4]}; // @[ALU.scala 21:37]
  wire [65:0] add_result = _T_3 + _GEN_0; // @[ALU.scala 21:37]
  wire [63:0] xor_result = io_in1 ^ io_in2; // @[ALU.scala 22:29]
  wire [63:0] or_result = io_in1 | io_in2; // @[ALU.scala 23:29]
  wire [63:0] and_result = io_in1 & io_in2; // @[ALU.scala 24:29]
  wire  sltu_result = ~add_result[64]; // @[ALU.scala 26:30]
  wire  slt_result = xor_result[63] ^ sltu_result; // @[ALU.scala 27:51]
  wire [5:0] shamt = io_in2[5:0]; // @[ALU.scala 30:36]
  wire [126:0] _GEN_1 = {{63'd0}, io_in1}; // @[ALU.scala 31:30]
  wire [126:0] _T_6 = _GEN_1 << shamt; // @[ALU.scala 31:30]
  wire [63:0] sll_result = _T_6[63:0]; // @[ALU.scala 31:39]
  wire [63:0] sra_result = $signed(io_in1) >>> shamt; // @[ALU.scala 32:55]
  wire [63:0] srl_result = io_in1 >> shamt; // @[ALU.scala 33:29]
  wire [4:0] shamt5 = io_in2[4:0]; // @[ALU.scala 35:24]
  wire [94:0] _GEN_2 = {{31'd0}, io_in1}; // @[ALU.scala 36:31]
  wire [94:0] _T_9 = _GEN_2 << shamt5; // @[ALU.scala 36:31]
  wire [31:0] sllw_result = _T_9[31:0]; // @[ALU.scala 36:41]
  wire [31:0] _T_11 = io_in1[31:0]; // @[ALU.scala 37:43]
  wire [31:0] sraw_result = $signed(_T_11) >>> shamt5; // @[ALU.scala 37:63]
  wire [31:0] srlw_result = io_in1[31:0] >> shamt5; // @[ALU.scala 38:36]
  wire [63:0] io_out_res = add_result[63:0]; // @[ALU.scala 43:33]
  wire  _io_out_T = io_opcode == 6'h12; // @[ALU.scala 44:20]
  wire [63:0] _io_out_T_1 = {63'h0,sltu_result}; // @[Cat.scala 29:58]
  wire  _io_out_T_2 = io_opcode == 6'h11; // @[ALU.scala 45:20]
  wire [63:0] _io_out_T_3 = {63'h0,slt_result}; // @[Cat.scala 29:58]
  wire  _io_out_T_4 = io_opcode == 6'h1; // @[ALU.scala 46:20]
  wire  _io_out_T_5 = io_opcode == 6'h2; // @[ALU.scala 47:20]
  wire  _io_out_T_6 = io_opcode == 6'h3; // @[ALU.scala 48:20]
  wire  _io_out_T_7 = io_opcode == 6'h4; // @[ALU.scala 49:20]
  wire  _io_out_T_8 = io_opcode == 6'h6; // @[ALU.scala 50:20]
  wire  _io_out_T_9 = io_opcode == 6'h5; // @[ALU.scala 51:20]
  wire  _io_out_T_10 = io_opcode == 6'h8; // @[ALU.scala 52:20]
  wire  _io_out_T_11 = io_opcode == 6'h20; // @[ALU.scala 53:20]
  wire [31:0] io_out_left = add_result[31:0]; // @[ALU.scala 53:58]
  wire [31:0] io_out_right = io_out_left[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _io_out_T_14 = {io_out_right,io_out_left}; // @[Cat.scala 29:58]
  wire  _io_out_T_15 = io_opcode == 6'h30; // @[ALU.scala 54:20]
  wire  _io_out_T_19 = io_opcode == 6'h24; // @[ALU.scala 55:20]
  wire [31:0] io_out_right_2 = sllw_result[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _io_out_T_22 = {io_out_right_2,sllw_result}; // @[Cat.scala 29:58]
  wire  _io_out_T_23 = io_opcode == 6'h26; // @[ALU.scala 56:20]
  wire [31:0] io_out_right_3 = sraw_result[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _io_out_T_26 = {io_out_right_3,sraw_result}; // @[Cat.scala 29:58]
  wire  _io_out_T_27 = io_opcode == 6'h25; // @[ALU.scala 57:20]
  wire [31:0] io_out_right_4 = srlw_result[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _io_out_T_30 = {io_out_right_4,srlw_result}; // @[Cat.scala 29:58]
  wire [63:0] _io_out_T_31 = _io_out_T_27 ? _io_out_T_30 : io_out_res; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_32 = _io_out_T_23 ? _io_out_T_26 : _io_out_T_31; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_33 = _io_out_T_19 ? _io_out_T_22 : _io_out_T_32; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_34 = _io_out_T_15 ? _io_out_T_14 : _io_out_T_33; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_35 = _io_out_T_11 ? _io_out_T_14 : _io_out_T_34; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_36 = _io_out_T_10 ? io_in1 : _io_out_T_35; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_37 = _io_out_T_9 ? srl_result : _io_out_T_36; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_38 = _io_out_T_8 ? sra_result : _io_out_T_37; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_39 = _io_out_T_7 ? sll_result : _io_out_T_38; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_40 = _io_out_T_6 ? and_result : _io_out_T_39; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_41 = _io_out_T_5 ? or_result : _io_out_T_40; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_42 = _io_out_T_4 ? xor_result : _io_out_T_41; // @[Mux.scala 98:16]
  wire [63:0] _io_out_T_43 = _io_out_T_2 ? _io_out_T_3 : _io_out_T_42; // @[Mux.scala 98:16]
  assign io_out = _io_out_T ? _io_out_T_1 : _io_out_T_43; // @[Mux.scala 98:16]
endmodule
module EXE_TOP(
  input         clock,
  input         reset,
  output        io_ds_ready,
  input         io_ds_valid,
  input  [63:0] io_ds_bits_PC,
  input  [31:0] io_ds_bits_inst,
  input  [1:0]  io_ds_bits_decode_op1_sel,
  input  [1:0]  io_ds_bits_decode_op2_sel,
  input  [5:0]  io_ds_bits_decode_alu_op,
  input  [1:0]  io_ds_bits_decode_wb_sel,
  input         io_ds_bits_decode_rf_wen,
  input         io_ds_bits_decode_mem_en,
  input         io_ds_bits_decode_mem_wr,
  input  [2:0]  io_ds_bits_decode_mem_msk,
  input  [2:0]  io_ds_bits_decode_csr_cmd,
  input  [63:0] io_ds_bits_rs1_data,
  input  [63:0] io_ds_bits_rs2_data,
  input         io_ms_ready,
  output        io_ms_valid,
  output [63:0] io_ms_bits_PC,
  output [1:0]  io_ms_bits_decode_wb_sel,
  output        io_ms_bits_decode_rf_wen,
  output        io_ms_bits_decode_mem_wr,
  output [2:0]  io_ms_bits_decode_mem_msk,
  output [2:0]  io_ms_bits_decode_csr_cmd,
  output [63:0] io_ms_bits_alu_result,
  output [4:0]  io_ms_bits_rd_addr,
  output [2:0]  io_ms_bits_load_offset,
  output [11:0] io_ms_bits_csr_addr,
  input         io_dmem_req_ready,
  output        io_dmem_req_valid,
  output [63:0] io_dmem_req_bits_addr,
  output [63:0] io_dmem_req_bits_data,
  output        io_dmem_req_bits_wr,
  output [7:0]  io_dmem_req_bits_msk,
  output        es_res_0_rf_we,
  output [4:0]  es_res_0_wr_addr,
  output [63:0] es_res_0_wr_data,
  output [1:0]  es_res_0_wb_sel,
  input         exception_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
`endif // RANDOMIZE_REG_INIT
  wire [5:0] alu_io_opcode; // @[EXE_TOP.scala 46:21]
  wire [63:0] alu_io_in1; // @[EXE_TOP.scala 46:21]
  wire [63:0] alu_io_in2; // @[EXE_TOP.scala 46:21]
  wire [63:0] alu_io_out; // @[EXE_TOP.scala 46:21]
  wire  _T = io_ds_valid & io_ds_ready; // @[EXE_TOP.scala 19:89]
  reg [63:0] from_ds_r_PC; // @[Reg.scala 27:20]
  reg [31:0] from_ds_r_inst; // @[Reg.scala 27:20]
  reg [1:0] from_ds_r_decode_op1_sel; // @[Reg.scala 27:20]
  reg [1:0] from_ds_r_decode_op2_sel; // @[Reg.scala 27:20]
  reg [5:0] from_ds_r_decode_alu_op; // @[Reg.scala 27:20]
  reg [1:0] from_ds_r_decode_wb_sel; // @[Reg.scala 27:20]
  reg  from_ds_r_decode_rf_wen; // @[Reg.scala 27:20]
  reg  from_ds_r_decode_mem_en; // @[Reg.scala 27:20]
  reg  from_ds_r_decode_mem_wr; // @[Reg.scala 27:20]
  reg [2:0] from_ds_r_decode_mem_msk; // @[Reg.scala 27:20]
  reg [2:0] from_ds_r_decode_csr_cmd; // @[Reg.scala 27:20]
  reg [63:0] from_ds_r_rs1_data; // @[Reg.scala 27:20]
  reg [63:0] from_ds_r_rs2_data; // @[Reg.scala 27:20]
  wire  es_ready_go = io_dmem_req_valid & ~io_dmem_req_ready ? 1'h0 : 1'h1; // @[EXE_TOP.scala 20:26]
  reg  es_valid; // @[Reg.scala 27:20]
  wire [11:0] imm_i = from_ds_r_inst[31:20]; // @[EXE_TOP.scala 31:21]
  wire [6:0] right = from_ds_r_inst[31:25]; // @[EXE_TOP.scala 32:25]
  wire [4:0] left = from_ds_r_inst[11:7]; // @[EXE_TOP.scala 32:39]
  wire [11:0] imm_s = {right,left}; // @[Cat.scala 29:58]
  wire [19:0] imm_u = from_ds_r_inst[31:12]; // @[EXE_TOP.scala 34:21]
  wire [4:0] left_3 = from_ds_r_inst[19:15]; // @[EXE_TOP.scala 36:40]
  wire [31:0] imm_z = {27'h0,left_3}; // @[Cat.scala 29:58]
  wire [51:0] right_4 = imm_i[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_i_sext = {right_4,imm_i}; // @[Cat.scala 29:58]
  wire [51:0] right_5 = imm_s[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_s_sext = {right_5,right,left}; // @[Cat.scala 29:58]
  wire [31:0] right_right_3 = imm_u[11] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_u_sext = {right_right_3,imm_u,12'h0}; // @[Cat.scala 29:58]
  wire  _alu_io_in1_T = from_ds_r_decode_op1_sel == 2'h0; // @[EXE_TOP.scala 49:25]
  wire  _alu_io_in1_T_1 = from_ds_r_decode_op1_sel == 2'h1; // @[EXE_TOP.scala 50:25]
  wire  _alu_io_in1_T_2 = from_ds_r_decode_op1_sel == 2'h2; // @[EXE_TOP.scala 51:25]
  wire [63:0] _alu_io_in1_T_3 = _alu_io_in1_T_2 ? {{32'd0}, imm_z} : from_ds_r_rs1_data; // @[Mux.scala 98:16]
  wire [63:0] _alu_io_in1_T_4 = _alu_io_in1_T_1 ? imm_u_sext : _alu_io_in1_T_3; // @[Mux.scala 98:16]
  wire  _alu_io_in2_T = from_ds_r_decode_op2_sel == 2'h0; // @[EXE_TOP.scala 55:25]
  wire  _alu_io_in2_T_1 = from_ds_r_decode_op2_sel == 2'h1; // @[EXE_TOP.scala 56:25]
  wire  _alu_io_in2_T_2 = from_ds_r_decode_op2_sel == 2'h2; // @[EXE_TOP.scala 57:25]
  wire  _alu_io_in2_T_3 = from_ds_r_decode_op2_sel == 2'h3; // @[EXE_TOP.scala 58:25]
  wire [63:0] _alu_io_in2_T_4 = _alu_io_in2_T_3 ? from_ds_r_PC : from_ds_r_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _alu_io_in2_T_5 = _alu_io_in2_T_2 ? imm_s_sext : _alu_io_in2_T_4; // @[Mux.scala 98:16]
  wire [63:0] _alu_io_in2_T_6 = _alu_io_in2_T_1 ? imm_i_sext : _alu_io_in2_T_5; // @[Mux.scala 98:16]
  reg  dmem_req_r; // @[EXE_TOP.scala 63:29]
  wire  _GEN_16 = io_dmem_req_ready ? 1'h0 : dmem_req_r; // @[EXE_TOP.scala 65:41 EXE_TOP.scala 65:54 EXE_TOP.scala 63:29]
  wire  _GEN_17 = _T | _GEN_16; // @[EXE_TOP.scala 64:41 EXE_TOP.scala 64:54]
  wire [63:0] _GEN_0 = alu_io_out % 64'h8; // @[EXE_TOP.scala 69:29]
  wire [3:0] offset = _GEN_0[3:0]; // @[EXE_TOP.scala 69:29]
  wire [6:0] offset_8 = {offset, 3'h0}; // @[EXE_TOP.scala 70:28]
  wire [60:0] io_dmem_req_bits_addr_right = alu_io_out[63:3]; // @[EXE_TOP.scala 74:80]
  wire [63:0] _io_dmem_req_bits_addr_T_1 = {io_dmem_req_bits_addr_right,3'h0}; // @[Cat.scala 29:58]
  wire [190:0] _GEN_33 = {{127'd0}, from_ds_r_rs2_data}; // @[EXE_TOP.scala 77:51]
  wire [190:0] _io_dmem_req_bits_data_T = _GEN_33 << offset_8; // @[EXE_TOP.scala 77:51]
  wire  _io_dmem_req_bits_msk_T = from_ds_r_decode_mem_msk == 3'h1; // @[EXE_TOP.scala 80:25]
  wire [15:0] _io_dmem_req_bits_msk_T_1 = 16'h1 << offset; // @[EXE_TOP.scala 80:48]
  wire  _io_dmem_req_bits_msk_T_2 = from_ds_r_decode_mem_msk == 3'h2; // @[EXE_TOP.scala 81:25]
  wire [16:0] _io_dmem_req_bits_msk_T_3 = 17'h3 << offset; // @[EXE_TOP.scala 81:49]
  wire  _io_dmem_req_bits_msk_T_4 = from_ds_r_decode_mem_msk == 3'h3; // @[EXE_TOP.scala 82:25]
  wire [18:0] _io_dmem_req_bits_msk_T_5 = 19'hf << offset; // @[EXE_TOP.scala 82:48]
  wire [18:0] _io_dmem_req_bits_msk_T_6 = _io_dmem_req_bits_msk_T_4 ? _io_dmem_req_bits_msk_T_5 : 19'hff; // @[Mux.scala 98:16]
  wire [18:0] _io_dmem_req_bits_msk_T_7 = _io_dmem_req_bits_msk_T_2 ? {{2'd0}, _io_dmem_req_bits_msk_T_3} :
    _io_dmem_req_bits_msk_T_6; // @[Mux.scala 98:16]
  wire [18:0] _io_dmem_req_bits_msk_T_8 = _io_dmem_req_bits_msk_T ? {{3'd0}, _io_dmem_req_bits_msk_T_1} :
    _io_dmem_req_bits_msk_T_7; // @[Mux.scala 98:16]
  wire [63:0] _io_ms_bits_alu_result_T_2 = from_ds_r_PC + 64'h4; // @[EXE_TOP.scala 87:75]
  wire  es_res_rf_we = from_ds_r_decode_rf_wen; // @[EXE_TOP.scala 95:22 EXE_TOP.scala 97:20]
  wire [4:0] es_res_wr_addr = io_ms_bits_rd_addr; // @[EXE_TOP.scala 95:22 EXE_TOP.scala 98:20]
  wire [63:0] es_res_wr_data = io_ms_bits_alu_result; // @[EXE_TOP.scala 95:22 EXE_TOP.scala 99:20]
  wire [1:0] es_res_wb_sel = from_ds_r_decode_wb_sel; // @[EXE_TOP.scala 95:22 EXE_TOP.scala 96:20]
  ALU alu ( // @[EXE_TOP.scala 46:21]
    .io_opcode(alu_io_opcode),
    .io_in1(alu_io_in1),
    .io_in2(alu_io_in2),
    .io_out(alu_io_out)
  );
  assign io_ds_ready = ~es_valid | es_ready_go & io_ms_ready; // @[EXE_TOP.scala 23:33]
  assign io_ms_valid = es_valid & es_ready_go; // @[EXE_TOP.scala 24:32]
  assign io_ms_bits_PC = from_ds_r_PC; // @[EXE_TOP.scala 86:29]
  assign io_ms_bits_decode_wb_sel = from_ds_r_decode_wb_sel; // @[EXE_TOP.scala 89:29]
  assign io_ms_bits_decode_rf_wen = from_ds_r_decode_rf_wen; // @[EXE_TOP.scala 89:29]
  assign io_ms_bits_decode_mem_wr = from_ds_r_decode_mem_wr; // @[EXE_TOP.scala 89:29]
  assign io_ms_bits_decode_mem_msk = from_ds_r_decode_mem_msk; // @[EXE_TOP.scala 89:29]
  assign io_ms_bits_decode_csr_cmd = from_ds_r_decode_csr_cmd; // @[EXE_TOP.scala 89:29]
  assign io_ms_bits_alu_result = from_ds_r_decode_wb_sel == 2'h2 ? _io_ms_bits_alu_result_T_2 : alu_io_out; // @[EXE_TOP.scala 87:35]
  assign io_ms_bits_rd_addr = from_ds_r_inst[11:7]; // @[EXE_TOP.scala 88:36]
  assign io_ms_bits_load_offset = offset[2:0]; // @[EXE_TOP.scala 90:29]
  assign io_ms_bits_csr_addr = from_ds_r_inst[31:20]; // @[EXE_TOP.scala 91:36]
  assign io_dmem_req_valid = from_ds_r_decode_mem_en & dmem_req_r; // @[EXE_TOP.scala 72:35]
  assign io_dmem_req_bits_addr = alu_io_out >= 64'h80000000 ? _io_dmem_req_bits_addr_T_1 : alu_io_out; // @[EXE_TOP.scala 74:35]
  assign io_dmem_req_bits_data = _io_dmem_req_bits_data_T[63:0]; // @[EXE_TOP.scala 77:29]
  assign io_dmem_req_bits_wr = from_ds_r_decode_mem_wr; // @[EXE_TOP.scala 78:29]
  assign io_dmem_req_bits_msk = _io_dmem_req_bits_msk_T_8[7:0]; // @[EXE_TOP.scala 79:29]
  assign es_res_0_rf_we = es_res_rf_we;
  assign es_res_0_wr_addr = es_res_wr_addr;
  assign es_res_0_wr_data = es_res_wr_data;
  assign es_res_0_wb_sel = es_res_wb_sel;
  assign alu_io_opcode = from_ds_r_decode_alu_op; // @[EXE_TOP.scala 47:19]
  assign alu_io_in1 = _alu_io_in1_T ? from_ds_r_rs1_data : _alu_io_in1_T_4; // @[Mux.scala 98:16]
  assign alu_io_in2 = _alu_io_in2_T ? from_ds_r_rs2_data : _alu_io_in2_T_6; // @[Mux.scala 98:16]
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_PC <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_PC <= 64'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_PC <= io_ds_bits_PC; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_inst <= 32'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_inst <= 32'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_inst <= io_ds_bits_inst; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_op1_sel <= 2'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_op1_sel <= 2'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_op1_sel <= io_ds_bits_decode_op1_sel; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_op2_sel <= 2'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_op2_sel <= 2'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_op2_sel <= io_ds_bits_decode_op2_sel; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_alu_op <= 6'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_alu_op <= 6'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_alu_op <= io_ds_bits_decode_alu_op; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_wb_sel <= 2'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_wb_sel <= 2'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_wb_sel <= io_ds_bits_decode_wb_sel; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_rf_wen <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_rf_wen <= 1'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_rf_wen <= io_ds_bits_decode_rf_wen; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_mem_en <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_mem_en <= 1'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_mem_en <= io_ds_bits_decode_mem_en; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_mem_wr <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_mem_wr <= 1'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_mem_wr <= io_ds_bits_decode_mem_wr; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_mem_msk <= 3'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_mem_msk <= 3'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_mem_msk <= io_ds_bits_decode_mem_msk; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_decode_csr_cmd <= 3'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_decode_csr_cmd <= 3'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_decode_csr_cmd <= io_ds_bits_decode_csr_cmd; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_rs1_data <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_rs1_data <= 64'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_rs1_data <= io_ds_bits_rs1_data; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ds_r_rs2_data <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[EXE_TOP.scala 104:21]
      from_ds_r_rs2_data <= 64'h0; // @[EXE_TOP.scala 104:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ds_r_rs2_data <= io_ds_bits_rs2_data; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      es_valid <= 1'h0; // @[Reg.scala 27:20]
    end else if (io_ds_ready) begin // @[Reg.scala 28:19]
      es_valid <= io_ds_valid; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[EXE_TOP.scala 63:29]
      dmem_req_r <= 1'h0; // @[EXE_TOP.scala 63:29]
    end else begin
      dmem_req_r <= _GEN_17;
    end
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  from_ds_r_PC = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  from_ds_r_inst = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  from_ds_r_decode_op1_sel = _RAND_2[1:0];
  _RAND_3 = {1{`RANDOM}};
  from_ds_r_decode_op2_sel = _RAND_3[1:0];
  _RAND_4 = {1{`RANDOM}};
  from_ds_r_decode_alu_op = _RAND_4[5:0];
  _RAND_5 = {1{`RANDOM}};
  from_ds_r_decode_wb_sel = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  from_ds_r_decode_rf_wen = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  from_ds_r_decode_mem_en = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  from_ds_r_decode_mem_wr = _RAND_8[0:0];
  _RAND_9 = {1{`RANDOM}};
  from_ds_r_decode_mem_msk = _RAND_9[2:0];
  _RAND_10 = {1{`RANDOM}};
  from_ds_r_decode_csr_cmd = _RAND_10[2:0];
  _RAND_11 = {2{`RANDOM}};
  from_ds_r_rs1_data = _RAND_11[63:0];
  _RAND_12 = {2{`RANDOM}};
  from_ds_r_rs2_data = _RAND_12[63:0];
  _RAND_13 = {1{`RANDOM}};
  es_valid = _RAND_13[0:0];
  _RAND_14 = {1{`RANDOM}};
  dmem_req_r = _RAND_14[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module MEM_TOP(
  input         clock,
  input         reset,
  output        io__es_ready,
  input         io__es_valid,
  input  [63:0] io__es_bits_PC,
  input  [1:0]  io__es_bits_decode_wb_sel,
  input         io__es_bits_decode_rf_wen,
  input         io__es_bits_decode_mem_wr,
  input  [2:0]  io__es_bits_decode_mem_msk,
  input  [2:0]  io__es_bits_decode_csr_cmd,
  input  [63:0] io__es_bits_alu_result,
  input  [4:0]  io__es_bits_rd_addr,
  input  [2:0]  io__es_bits_load_offset,
  input  [11:0] io__es_bits_csr_addr,
  output        io__ws_valid,
  output [63:0] io__ws_bits_PC,
  output [1:0]  io__ws_bits_decode_wb_sel,
  output        io__ws_bits_decode_rf_wen,
  output [2:0]  io__ws_bits_decode_csr_cmd,
  output [63:0] io__ws_bits_final_result,
  output [4:0]  io__ws_bits_rd_addr,
  output [11:0] io__ws_bits_csr_addr,
  input         io__dmem_resp_valid,
  input  [63:0] io__dmem_resp_bits_data,
  output        ms_res_0_rf_we,
  output [4:0]  ms_res_0_wr_addr,
  output [63:0] ms_res_0_wr_data,
  output [1:0]  ms_res_0_wb_sel,
  output        io_dmem_resp_valid,
  input         exception_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
`endif // RANDOMIZE_REG_INIT
  wire  _T = io__es_valid & io__es_ready; // @[MEM_TOP.scala 19:88]
  reg [63:0] from_es_r_PC; // @[Reg.scala 27:20]
  reg [1:0] from_es_r_decode_wb_sel; // @[Reg.scala 27:20]
  reg  from_es_r_decode_rf_wen; // @[Reg.scala 27:20]
  reg  from_es_r_decode_mem_wr; // @[Reg.scala 27:20]
  reg [2:0] from_es_r_decode_mem_msk; // @[Reg.scala 27:20]
  reg [2:0] from_es_r_decode_csr_cmd; // @[Reg.scala 27:20]
  reg [63:0] from_es_r_alu_result; // @[Reg.scala 27:20]
  reg [4:0] from_es_r_rd_addr; // @[Reg.scala 27:20]
  reg [2:0] from_es_r_load_offset; // @[Reg.scala 27:20]
  reg [11:0] from_es_r_csr_addr; // @[Reg.scala 27:20]
  wire  _GEN_6 = _T ? io__es_bits_decode_mem_wr : from_es_r_decode_mem_wr; // @[Reg.scala 28:19 Reg.scala 28:23 Reg.scala 27:20]
  reg  ms_valid; // @[Reg.scala 27:20]
  reg [3:0] unfinished_store; // @[MEM_TOP.scala 31:35]
  wire  res_from_mem = from_es_r_decode_wb_sel == 2'h1; // @[MEM_TOP.scala 27:39]
  wire  _ms_ready_go_T_5 = res_from_mem & unfinished_store == 4'h0 & ~io__dmem_resp_valid ? 1'h0 : 1'h1; // @[MEM_TOP.scala 41:23]
  wire  ms_ready_go = unfinished_store != 4'h0 ? 1'h0 : _ms_ready_go_T_5; // @[MEM_TOP.scala 40:23]
  wire  _T_2 = from_es_r_decode_mem_wr & ms_valid; // @[MEM_TOP.scala 32:24]
  wire [3:0] _unfinished_store_T_1 = unfinished_store + 4'h1; // @[MEM_TOP.scala 35:46]
  wire [3:0] _unfinished_store_T_3 = unfinished_store - 4'h1; // @[MEM_TOP.scala 38:46]
  wire [5:0] _T_7 = {from_es_r_load_offset, 3'h0}; // @[MEM_TOP.scala 46:66]
  wire [63:0] data = io__dmem_resp_bits_data >> _T_7; // @[MEM_TOP.scala 46:40]
  wire [63:0] _byte_T = data & 64'hff; // @[MEM_TOP.scala 48:18]
  wire [63:0] _half_T = data & 64'hffff; // @[MEM_TOP.scala 50:18]
  wire [63:0] _word_T = data & 64'hffffffff; // @[MEM_TOP.scala 52:18]
  wire  _T_8 = from_es_r_decode_mem_msk == 3'h1; // @[MEM_TOP.scala 55:25]
  wire [7:0] byte_ = _byte_T[7:0]; // @[MEM_TOP.scala 47:20 MEM_TOP.scala 48:10]
  wire [55:0] right = byte_[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_11 = {right,byte_}; // @[Cat.scala 29:58]
  wire  _T_12 = from_es_r_decode_mem_msk == 3'h5; // @[MEM_TOP.scala 56:25]
  wire [63:0] _T_13 = {56'h0,byte_}; // @[Cat.scala 29:58]
  wire  _T_14 = from_es_r_decode_mem_msk == 3'h2; // @[MEM_TOP.scala 57:25]
  wire [15:0] half = _half_T[15:0]; // @[MEM_TOP.scala 49:20 MEM_TOP.scala 50:10]
  wire [47:0] right_1 = half[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_17 = {right_1,half}; // @[Cat.scala 29:58]
  wire  _T_18 = from_es_r_decode_mem_msk == 3'h6; // @[MEM_TOP.scala 58:25]
  wire [63:0] _T_19 = {48'h0,half}; // @[Cat.scala 29:58]
  wire  _T_20 = from_es_r_decode_mem_msk == 3'h3; // @[MEM_TOP.scala 59:25]
  wire [31:0] word = _word_T[31:0]; // @[MEM_TOP.scala 51:20 MEM_TOP.scala 52:10]
  wire [31:0] right_2 = word[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_23 = {right_2,word}; // @[Cat.scala 29:58]
  wire  _T_24 = from_es_r_decode_mem_msk == 3'h7; // @[MEM_TOP.scala 60:25]
  wire [63:0] _T_25 = {32'h0,word}; // @[Cat.scala 29:58]
  wire [63:0] _T_26 = _T_24 ? _T_25 : io__dmem_resp_bits_data; // @[Mux.scala 98:16]
  wire [63:0] _T_27 = _T_20 ? _T_23 : _T_26; // @[Mux.scala 98:16]
  wire [63:0] _T_28 = _T_18 ? _T_19 : _T_27; // @[Mux.scala 98:16]
  wire [63:0] _T_29 = _T_14 ? _T_17 : _T_28; // @[Mux.scala 98:16]
  wire [63:0] _T_30 = _T_12 ? _T_13 : _T_29; // @[Mux.scala 98:16]
  wire [63:0] load_final = _T_8 ? _T_11 : _T_30; // @[Mux.scala 98:16]
  wire  ms_res_rf_we = from_es_r_decode_rf_wen; // @[MEM_TOP.scala 71:22 MEM_TOP.scala 73:21]
  wire [4:0] ms_res_wr_addr = io__ws_bits_rd_addr; // @[MEM_TOP.scala 71:22 MEM_TOP.scala 74:21]
  wire [63:0] ms_res_wr_data = io__ws_bits_final_result; // @[MEM_TOP.scala 71:22 MEM_TOP.scala 75:21]
  wire [1:0] ms_res_wb_sel = from_es_r_decode_wb_sel; // @[MEM_TOP.scala 71:22 MEM_TOP.scala 72:21]
  assign io__es_ready = ~ms_valid | ms_ready_go; // @[MEM_TOP.scala 23:30]
  assign io__ws_valid = ms_valid & ms_ready_go; // @[MEM_TOP.scala 24:29]
  assign io__ws_bits_PC = from_es_r_PC; // @[MEM_TOP.scala 64:29]
  assign io__ws_bits_decode_wb_sel = from_es_r_decode_wb_sel; // @[MEM_TOP.scala 65:29]
  assign io__ws_bits_decode_rf_wen = from_es_r_decode_rf_wen; // @[MEM_TOP.scala 65:29]
  assign io__ws_bits_decode_csr_cmd = from_es_r_decode_csr_cmd; // @[MEM_TOP.scala 65:29]
  assign io__ws_bits_final_result = res_from_mem ? load_final : from_es_r_alu_result; // @[MEM_TOP.scala 66:35]
  assign io__ws_bits_rd_addr = from_es_r_rd_addr; // @[MEM_TOP.scala 67:29]
  assign io__ws_bits_csr_addr = from_es_r_csr_addr; // @[MEM_TOP.scala 68:29]
  assign ms_res_0_rf_we = ms_res_rf_we;
  assign ms_res_0_wr_addr = ms_res_wr_addr;
  assign ms_res_0_wr_data = ms_res_wr_data;
  assign ms_res_0_wb_sel = ms_res_wb_sel;
  assign io_dmem_resp_valid = io__dmem_resp_valid;
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_PC <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_PC <= 64'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_PC <= io__es_bits_PC; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_decode_wb_sel <= 2'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_decode_wb_sel <= 2'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_decode_wb_sel <= io__es_bits_decode_wb_sel; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_decode_rf_wen <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_decode_rf_wen <= 1'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_decode_rf_wen <= io__es_bits_decode_rf_wen; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_decode_mem_wr <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_decode_mem_wr <= 1'h0; // @[MEM_TOP.scala 82:33]
    end else if (from_es_r_decode_mem_wr & ms_valid & io__dmem_resp_valid) begin // @[MEM_TOP.scala 32:58]
      from_es_r_decode_mem_wr <= _GEN_6;
    end else if (_T_2) begin // @[MEM_TOP.scala 34:43]
      from_es_r_decode_mem_wr <= 1'h0; // @[MEM_TOP.scala 36:26]
    end else begin
      from_es_r_decode_mem_wr <= _GEN_6;
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_decode_mem_msk <= 3'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_decode_mem_msk <= 3'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_decode_mem_msk <= io__es_bits_decode_mem_msk; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_decode_csr_cmd <= 3'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_decode_csr_cmd <= 3'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_decode_csr_cmd <= io__es_bits_decode_csr_cmd; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_alu_result <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_alu_result <= 64'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_alu_result <= io__es_bits_alu_result; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_rd_addr <= 5'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_rd_addr <= 5'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_rd_addr <= io__es_bits_rd_addr; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_load_offset <= 3'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_load_offset <= 3'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_load_offset <= io__es_bits_load_offset; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_es_r_csr_addr <= 12'h0; // @[Reg.scala 27:20]
    end else if (exception_0) begin // @[MEM_TOP.scala 82:21]
      from_es_r_csr_addr <= 12'h0; // @[MEM_TOP.scala 82:33]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_es_r_csr_addr <= io__es_bits_csr_addr; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      ms_valid <= 1'h0; // @[Reg.scala 27:20]
    end else if (io__es_ready) begin // @[Reg.scala 28:19]
      ms_valid <= io__es_valid; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[MEM_TOP.scala 31:35]
      unfinished_store <= 4'h0; // @[MEM_TOP.scala 31:35]
    end else if (!(from_es_r_decode_mem_wr & ms_valid & io__dmem_resp_valid)) begin // @[MEM_TOP.scala 32:58]
      if (_T_2) begin // @[MEM_TOP.scala 34:43]
        unfinished_store <= _unfinished_store_T_1; // @[MEM_TOP.scala 35:26]
      end else if (io__dmem_resp_valid & unfinished_store > 4'h0) begin // @[MEM_TOP.scala 37:61]
        unfinished_store <= _unfinished_store_T_3; // @[MEM_TOP.scala 38:26]
      end
    end
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  from_es_r_PC = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  from_es_r_decode_wb_sel = _RAND_1[1:0];
  _RAND_2 = {1{`RANDOM}};
  from_es_r_decode_rf_wen = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  from_es_r_decode_mem_wr = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  from_es_r_decode_mem_msk = _RAND_4[2:0];
  _RAND_5 = {1{`RANDOM}};
  from_es_r_decode_csr_cmd = _RAND_5[2:0];
  _RAND_6 = {2{`RANDOM}};
  from_es_r_alu_result = _RAND_6[63:0];
  _RAND_7 = {1{`RANDOM}};
  from_es_r_rd_addr = _RAND_7[4:0];
  _RAND_8 = {1{`RANDOM}};
  from_es_r_load_offset = _RAND_8[2:0];
  _RAND_9 = {1{`RANDOM}};
  from_es_r_csr_addr = _RAND_9[11:0];
  _RAND_10 = {1{`RANDOM}};
  ms_valid = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  unfinished_store = _RAND_11[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module CSR(
  input         clock,
  input         reset,
  input  [11:0] io_pc,
  input  [11:0] io_addr,
  input  [2:0]  io_ctrl,
  input  [63:0] io_gr_data,
  output [63:0] io_csr_data,
  output [63:0] mepc_0,
  output [63:0] exc_addr_0,
  output        exception_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [63:0] _RAND_13;
  reg [63:0] _RAND_14;
  reg [63:0] _RAND_15;
`endif // RANDOMIZE_REG_INIT
  wire  _T = io_addr == 12'h304; // @[CSR.scala 57:81]
  reg [63:0] mie; // @[Reg.scala 27:20]
  wire  _write_csr_data_T = io_ctrl == 3'h2; // @[CSR.scala 84:19]
  wire  _write_csr_data_T_1 = io_ctrl == 3'h3; // @[CSR.scala 84:45]
  wire  _write_csr_data_T_4 = (io_ctrl == 3'h2 | io_ctrl == 3'h3) & io_gr_data != 64'h0; // @[CSR.scala 84:61]
  wire  _read_csr_data_T = io_addr == 12'h300; // @[CSR.scala 70:18]
  reg [55:0] mstatus_notused_0; // @[Reg.scala 27:20]
  reg  mstatus_mpie; // @[Reg.scala 27:20]
  reg [2:0] mstatus_notused_1; // @[Reg.scala 27:20]
  reg  mstatus_mie; // @[Reg.scala 27:20]
  reg [2:0] mstatus_notused_2; // @[Reg.scala 27:20]
  wire [63:0] _read_csr_data_T_1 = {mstatus_notused_0,mstatus_mpie,mstatus_notused_1,mstatus_mie,mstatus_notused_2}; // @[CSR.scala 70:53]
  wire  _read_csr_data_T_3 = io_addr == 12'h305; // @[CSR.scala 72:18]
  reg [61:0] mtvec_base; // @[Reg.scala 27:20]
  reg [1:0] mtvec_mode; // @[Reg.scala 27:20]
  wire [63:0] _read_csr_data_T_4 = {mtvec_base,mtvec_mode}; // @[CSR.scala 72:51]
  wire  _read_csr_data_T_5 = io_addr == 12'h340; // @[CSR.scala 73:18]
  reg [63:0] mscratch; // @[Reg.scala 27:20]
  wire  _read_csr_data_T_6 = io_addr == 12'h341; // @[CSR.scala 74:18]
  reg [63:0] mepc; // @[Reg.scala 27:20]
  wire  _read_csr_data_T_7 = io_addr == 12'h342; // @[CSR.scala 75:18]
  reg  mcause_interrupt; // @[Reg.scala 27:20]
  reg [62:0] mcause_exc_code; // @[Reg.scala 27:20]
  wire [63:0] _read_csr_data_T_8 = {mcause_interrupt,mcause_exc_code}; // @[CSR.scala 75:52]
  wire  _read_csr_data_T_9 = io_addr == 12'h343; // @[CSR.scala 76:18]
  reg [63:0] mtval; // @[Reg.scala 27:20]
  wire  _read_csr_data_T_10 = io_addr == 12'h344; // @[CSR.scala 77:18]
  reg [63:0] mip; // @[Reg.scala 27:20]
  wire  _read_csr_data_T_11 = io_addr == 12'h7c0; // @[CSR.scala 78:18]
  reg [63:0] mtime; // @[CSR.scala 65:26]
  wire  _read_csr_data_T_12 = io_addr == 12'h7c2; // @[CSR.scala 79:18]
  reg [63:0] mtimecmp; // @[Reg.scala 27:20]
  wire [63:0] _read_csr_data_T_13 = _read_csr_data_T_12 ? mtimecmp : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_14 = _read_csr_data_T_11 ? mtime : _read_csr_data_T_13; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_15 = _read_csr_data_T_10 ? mip : _read_csr_data_T_14; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_16 = _read_csr_data_T_9 ? mtval : _read_csr_data_T_15; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_17 = _read_csr_data_T_7 ? _read_csr_data_T_8 : _read_csr_data_T_16; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_18 = _read_csr_data_T_6 ? mepc : _read_csr_data_T_17; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_19 = _read_csr_data_T_5 ? mscratch : _read_csr_data_T_18; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_20 = _read_csr_data_T_3 ? _read_csr_data_T_4 : _read_csr_data_T_19; // @[Mux.scala 98:16]
  wire [63:0] _read_csr_data_T_21 = _T ? mie : _read_csr_data_T_20; // @[Mux.scala 98:16]
  wire [63:0] read_csr_data = _read_csr_data_T ? _read_csr_data_T_1 : _read_csr_data_T_21; // @[Mux.scala 98:16]
  wire [63:0] _write_csr_data_T_6 = read_csr_data | io_gr_data; // @[CSR.scala 85:55]
  wire [63:0] _write_csr_data_T_8 = ~io_gr_data; // @[CSR.scala 86:57]
  wire [63:0] _write_csr_data_T_9 = read_csr_data & _write_csr_data_T_8; // @[CSR.scala 86:55]
  wire [63:0] _write_csr_data_T_10 = _write_csr_data_T_1 ? _write_csr_data_T_9 : io_gr_data; // @[Mux.scala 98:16]
  wire [63:0] _write_csr_data_T_11 = _write_csr_data_T ? _write_csr_data_T_6 : _write_csr_data_T_10; // @[Mux.scala 98:16]
  wire [63:0] write_csr_data = _write_csr_data_T_4 ? read_csr_data : _write_csr_data_T_11; // @[Mux.scala 98:16]
  wire [62:0] _GEN_5 = _read_csr_data_T_7 ? write_csr_data[62:0] : mcause_exc_code; // @[Reg.scala 28:19 Reg.scala 28:23 Reg.scala 27:20]
  wire  _GEN_6 = _read_csr_data_T_7 ? write_csr_data[63] : mcause_interrupt; // @[Reg.scala 28:19 Reg.scala 28:23 Reg.scala 27:20]
  wire [63:0] _mtime_T_1 = mtime + 64'h1; // @[CSR.scala 66:24]
  wire  is_ecall = io_ctrl == 3'h5; // @[CSR.scala 95:29]
  wire  is_ebreak = io_ctrl == 3'h6; // @[CSR.scala 96:29]
  wire  is_mret = io_ctrl == 3'h4; // @[CSR.scala 97:29]
  wire  time_int = mtime == mtimecmp; // @[CSR.scala 98:29]
  wire  exception = mstatus_mie & (is_ecall | is_ebreak | time_int); // @[CSR.scala 117:41]
  wire  _GEN_21 = time_int | _GEN_6; // @[CSR.scala 109:29 CSR.scala 110:26]
  wire [63:0] _exc_addr_T_1 = {mtvec_base,2'h0}; // @[Cat.scala 29:58]
  wire [63:0] _exc_addr_T_5 = _exc_addr_T_1 + _read_csr_data_T_8; // @[CSR.scala 118:105]
  wire [65:0] _GEN_23 = {_exc_addr_T_5, 2'h0}; // @[CSR.scala 118:123]
  wire [66:0] _exc_addr_T_6 = {{1'd0}, _GEN_23}; // @[CSR.scala 118:123]
  wire [66:0] _exc_addr_T_7 = mtvec_mode == 2'h0 ? {{3'd0}, _exc_addr_T_1} : _exc_addr_T_6; // @[CSR.scala 118:23]
  wire [63:0] exc_addr = _exc_addr_T_7[63:0];
  assign io_csr_data = _read_csr_data_T ? _read_csr_data_T_1 : _read_csr_data_T_21; // @[Mux.scala 98:16]
  assign mepc_0 = mepc;
  assign exc_addr_0 = exc_addr;
  assign exception_0 = exception;
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      mie <= 64'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        if (_read_csr_data_T) begin // @[Mux.scala 98:16]
          mie <= _read_csr_data_T_1;
        end else begin
          mie <= _read_csr_data_T_21;
        end
      end else if (_write_csr_data_T) begin // @[Mux.scala 98:16]
        mie <= _write_csr_data_T_6;
      end else begin
        mie <= _write_csr_data_T_10;
      end
    end
    if (reset) begin // @[Reg.scala 27:20]
      mstatus_notused_0 <= 56'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T) begin // @[Reg.scala 28:19]
      mstatus_notused_0 <= write_csr_data[63:8]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mstatus_mpie <= 1'h0; // @[Reg.scala 27:20]
    end else if (exception) begin // @[CSR.scala 100:20]
      mstatus_mpie <= mstatus_mie; // @[CSR.scala 102:22]
    end else if (_read_csr_data_T) begin // @[Reg.scala 28:19]
      mstatus_mpie <= write_csr_data[7]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mstatus_notused_1 <= 3'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T) begin // @[Reg.scala 28:19]
      mstatus_notused_1 <= write_csr_data[6:4]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mstatus_mie <= 1'h0; // @[Reg.scala 27:20]
    end else if (is_mret) begin // @[CSR.scala 105:18]
      mstatus_mie <= mstatus_mpie; // @[CSR.scala 106:21]
    end else if (exception) begin // @[CSR.scala 100:20]
      mstatus_mie <= 1'h0; // @[CSR.scala 103:22]
    end else if (_read_csr_data_T) begin // @[Reg.scala 28:19]
      mstatus_mie <= write_csr_data[3]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mstatus_notused_2 <= 3'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T) begin // @[Reg.scala 28:19]
      mstatus_notused_2 <= write_csr_data[2:0]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mtvec_base <= 62'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_3) begin // @[Reg.scala 28:19]
      mtvec_base <= write_csr_data[63:2]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mtvec_mode <= 2'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_3) begin // @[Reg.scala 28:19]
      mtvec_mode <= write_csr_data[1:0]; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mscratch <= 64'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_5) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        if (_read_csr_data_T) begin // @[Mux.scala 98:16]
          mscratch <= _read_csr_data_T_1;
        end else begin
          mscratch <= _read_csr_data_T_21;
        end
      end else if (_write_csr_data_T) begin // @[Mux.scala 98:16]
        mscratch <= _write_csr_data_T_6;
      end else begin
        mscratch <= _write_csr_data_T_10;
      end
    end
    if (reset) begin // @[Reg.scala 27:20]
      mepc <= 64'h0; // @[Reg.scala 27:20]
    end else if (exception) begin // @[CSR.scala 100:20]
      mepc <= {{52'd0}, io_pc}; // @[CSR.scala 101:14]
    end else if (_read_csr_data_T_6) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        mepc <= read_csr_data;
      end else begin
        mepc <= _write_csr_data_T_11;
      end
    end
    if (reset) begin // @[Reg.scala 27:20]
      mcause_interrupt <= 1'h0; // @[Reg.scala 27:20]
    end else begin
      mcause_interrupt <= _GEN_21;
    end
    if (reset) begin // @[Reg.scala 27:20]
      mcause_exc_code <= 63'h0; // @[Reg.scala 27:20]
    end else if (time_int) begin // @[CSR.scala 109:29]
      mcause_exc_code <= 63'h7; // @[CSR.scala 111:26]
    end else if (is_ecall) begin // @[CSR.scala 113:29]
      mcause_exc_code <= 63'hb; // @[CSR.scala 113:47]
    end else if (is_ebreak) begin // @[CSR.scala 114:29]
      mcause_exc_code <= 63'h3; // @[CSR.scala 114:47]
    end else begin
      mcause_exc_code <= _GEN_5;
    end
    if (reset) begin // @[Reg.scala 27:20]
      mtval <= 64'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_9) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        if (_read_csr_data_T) begin // @[Mux.scala 98:16]
          mtval <= _read_csr_data_T_1;
        end else begin
          mtval <= _read_csr_data_T_21;
        end
      end else if (_write_csr_data_T) begin // @[Mux.scala 98:16]
        mtval <= _write_csr_data_T_6;
      end else begin
        mtval <= _write_csr_data_T_10;
      end
    end
    if (reset) begin // @[Reg.scala 27:20]
      mip <= 64'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_10) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        if (_read_csr_data_T) begin // @[Mux.scala 98:16]
          mip <= _read_csr_data_T_1;
        end else begin
          mip <= _read_csr_data_T_21;
        end
      end else if (_write_csr_data_T) begin // @[Mux.scala 98:16]
        mip <= _write_csr_data_T_6;
      end else begin
        mip <= _write_csr_data_T_10;
      end
    end
    if (reset) begin // @[CSR.scala 65:26]
      mtime <= 64'h0; // @[CSR.scala 65:26]
    end else begin
      mtime <= _mtime_T_1; // @[CSR.scala 66:15]
    end
    if (reset) begin // @[Reg.scala 27:20]
      mtimecmp <= 64'h0; // @[Reg.scala 27:20]
    end else if (_read_csr_data_T_12) begin // @[Reg.scala 28:19]
      if (_write_csr_data_T_4) begin // @[Mux.scala 98:16]
        if (_read_csr_data_T) begin // @[Mux.scala 98:16]
          mtimecmp <= _read_csr_data_T_1;
        end else begin
          mtimecmp <= _read_csr_data_T_21;
        end
      end else if (_write_csr_data_T) begin // @[Mux.scala 98:16]
        mtimecmp <= _write_csr_data_T_6;
      end else begin
        mtimecmp <= _write_csr_data_T_10;
      end
    end
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  mie = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  mstatus_notused_0 = _RAND_1[55:0];
  _RAND_2 = {1{`RANDOM}};
  mstatus_mpie = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  mstatus_notused_1 = _RAND_3[2:0];
  _RAND_4 = {1{`RANDOM}};
  mstatus_mie = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  mstatus_notused_2 = _RAND_5[2:0];
  _RAND_6 = {2{`RANDOM}};
  mtvec_base = _RAND_6[61:0];
  _RAND_7 = {1{`RANDOM}};
  mtvec_mode = _RAND_7[1:0];
  _RAND_8 = {2{`RANDOM}};
  mscratch = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  mepc = _RAND_9[63:0];
  _RAND_10 = {1{`RANDOM}};
  mcause_interrupt = _RAND_10[0:0];
  _RAND_11 = {2{`RANDOM}};
  mcause_exc_code = _RAND_11[62:0];
  _RAND_12 = {2{`RANDOM}};
  mtval = _RAND_12[63:0];
  _RAND_13 = {2{`RANDOM}};
  mip = _RAND_13[63:0];
  _RAND_14 = {2{`RANDOM}};
  mtime = _RAND_14[63:0];
  _RAND_15 = {2{`RANDOM}};
  mtimecmp = _RAND_15[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module WB_TOP(
  input         clock,
  input         reset,
  output        io_ms_ready,
  input         io_ms_valid,
  input  [63:0] io_ms_bits_PC,
  input  [1:0]  io_ms_bits_decode_wb_sel,
  input         io_ms_bits_decode_rf_wen,
  input  [2:0]  io_ms_bits_decode_csr_cmd,
  input  [63:0] io_ms_bits_final_result,
  input  [4:0]  io_ms_bits_rd_addr,
  input  [11:0] io_ms_bits_csr_addr,
  output        io_rf_rf_we,
  output [4:0]  io_rf_wr_addr,
  output [63:0] io_rf_wr_data,
  output [1:0]  io_rf_wb_sel,
  output [63:0] mepc,
  output [63:0] exc_addr,
  output        exception
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [63:0] _RAND_9;
`endif // RANDOMIZE_REG_INIT
  wire  csrs_clock; // @[WB_TOP.scala 31:22]
  wire  csrs_reset; // @[WB_TOP.scala 31:22]
  wire [11:0] csrs_io_pc; // @[WB_TOP.scala 31:22]
  wire [11:0] csrs_io_addr; // @[WB_TOP.scala 31:22]
  wire [2:0] csrs_io_ctrl; // @[WB_TOP.scala 31:22]
  wire [63:0] csrs_io_gr_data; // @[WB_TOP.scala 31:22]
  wire [63:0] csrs_io_csr_data; // @[WB_TOP.scala 31:22]
  wire [63:0] csrs_mepc_0; // @[WB_TOP.scala 31:22]
  wire [63:0] csrs_exc_addr_0; // @[WB_TOP.scala 31:22]
  wire  csrs_exception_0; // @[WB_TOP.scala 31:22]
  wire  _T = io_ms_valid & io_ms_ready; // @[WB_TOP.scala 18:89]
  reg [63:0] from_ms_r_PC; // @[Reg.scala 27:20]
  reg [1:0] from_ms_r_decode_wb_sel; // @[Reg.scala 27:20]
  reg  from_ms_r_decode_rf_wen; // @[Reg.scala 27:20]
  reg [2:0] from_ms_r_decode_csr_cmd; // @[Reg.scala 27:20]
  reg [63:0] from_ms_r_final_result; // @[Reg.scala 27:20]
  reg [4:0] from_ms_r_rd_addr; // @[Reg.scala 27:20]
  reg [11:0] from_ms_r_csr_addr; // @[Reg.scala 27:20]
  reg  is_commit; // @[WB_TOP.scala 47:28]
  wire  _GEN_16 = is_commit ? 1'h0 : is_commit; // @[WB_TOP.scala 50:26 WB_TOP.scala 51:19 WB_TOP.scala 47:28]
  wire  _GEN_17 = _T | _GEN_16; // @[WB_TOP.scala 48:37 WB_TOP.scala 49:19]
  reg  REG; // @[WB_TOP.scala 54:35]
  reg [63:0] REG_1; // @[WB_TOP.scala 55:35]
  CSR csrs ( // @[WB_TOP.scala 31:22]
    .clock(csrs_clock),
    .reset(csrs_reset),
    .io_pc(csrs_io_pc),
    .io_addr(csrs_io_addr),
    .io_ctrl(csrs_io_ctrl),
    .io_gr_data(csrs_io_gr_data),
    .io_csr_data(csrs_io_csr_data),
    .mepc_0(csrs_mepc_0),
    .exc_addr_0(csrs_exc_addr_0),
    .exception_0(csrs_exception_0)
  );
  assign io_ms_ready = 1'h1; // @[WB_TOP.scala 22:30]
  assign io_rf_rf_we = from_ms_r_decode_rf_wen; // @[WB_TOP.scala 43:19]
  assign io_rf_wr_addr = from_ms_r_rd_addr; // @[WB_TOP.scala 41:19]
  assign io_rf_wr_data = from_ms_r_decode_wb_sel == 2'h3 ? csrs_io_csr_data : from_ms_r_final_result; // @[WB_TOP.scala 42:25]
  assign io_rf_wb_sel = from_ms_r_decode_wb_sel; // @[WB_TOP.scala 44:19]
  assign mepc = csrs_mepc_0;
  assign exc_addr = csrs_exc_addr_0;
  assign exception = csrs_exception_0;
  assign csrs_clock = clock;
  assign csrs_reset = reset;
  assign csrs_io_pc = from_ms_r_PC[11:0]; // @[WB_TOP.scala 35:21]
  assign csrs_io_addr = from_ms_r_csr_addr; // @[WB_TOP.scala 32:21]
  assign csrs_io_ctrl = from_ms_r_decode_csr_cmd; // @[WB_TOP.scala 33:21]
  assign csrs_io_gr_data = from_ms_r_final_result; // @[WB_TOP.scala 34:21]
  always @(posedge clock) begin
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_PC <= 64'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_PC <= io_ms_bits_PC; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_decode_wb_sel <= 2'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_decode_wb_sel <= io_ms_bits_decode_wb_sel; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_decode_rf_wen <= 1'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_decode_rf_wen <= io_ms_bits_decode_rf_wen; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_decode_csr_cmd <= 3'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_decode_csr_cmd <= io_ms_bits_decode_csr_cmd; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_final_result <= 64'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_final_result <= io_ms_bits_final_result; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_rd_addr <= 5'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_rd_addr <= io_ms_bits_rd_addr; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[Reg.scala 27:20]
      from_ms_r_csr_addr <= 12'h0; // @[Reg.scala 27:20]
    end else if (_T) begin // @[Reg.scala 28:19]
      from_ms_r_csr_addr <= io_ms_bits_csr_addr; // @[Reg.scala 28:23]
    end
    if (reset) begin // @[WB_TOP.scala 47:28]
      is_commit <= 1'h0; // @[WB_TOP.scala 47:28]
    end else begin
      is_commit <= _GEN_17;
    end
    REG <= is_commit & from_ms_r_PC != 64'h0; // @[WB_TOP.scala 54:39]
    REG_1 <= from_ms_r_PC; // @[WB_TOP.scala 55:35]
  end
// Register and memory initialization
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  from_ms_r_PC = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  from_ms_r_decode_wb_sel = _RAND_1[1:0];
  _RAND_2 = {1{`RANDOM}};
  from_ms_r_decode_rf_wen = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  from_ms_r_decode_csr_cmd = _RAND_3[2:0];
  _RAND_4 = {2{`RANDOM}};
  from_ms_r_final_result = _RAND_4[63:0];
  _RAND_5 = {1{`RANDOM}};
  from_ms_r_rd_addr = _RAND_5[4:0];
  _RAND_6 = {1{`RANDOM}};
  from_ms_r_csr_addr = _RAND_6[11:0];
  _RAND_7 = {1{`RANDOM}};
  is_commit = _RAND_7[0:0];
  _RAND_8 = {1{`RANDOM}};
  REG = _RAND_8[0:0];
  _RAND_9 = {2{`RANDOM}};
  REG_1 = _RAND_9[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module core(
  input         clock,
  input         reset,
  input         io_imem_req_ready,
  output        io_imem_req_valid,
  output [63:0] io_imem_req_bits_addr,
  input         io_imem_resp_valid,
  input  [63:0] io_imem_resp_bits_data,
  input         io_dmem_req_ready,
  output        io_dmem_req_valid,
  output [63:0] io_dmem_req_bits_addr,
  output [63:0] io_dmem_req_bits_data,
  output        io_dmem_req_bits_wr,
  output [7:0]  io_dmem_req_bits_msk,
  input         io_dmem_resp_valid,
  input  [63:0] io_dmem_resp_bits_data
);
  wire  pre_top_clock; // @[core.scala 20:25]
  wire  pre_top_reset; // @[core.scala 20:25]
  wire  pre_top_io_fs_ready; // @[core.scala 20:25]
  wire  pre_top_io_fs_valid; // @[core.scala 20:25]
  wire [63:0] pre_top_io_fs_bits_PC; // @[core.scala 20:25]
  wire  pre_top_io_fs_bits_offset; // @[core.scala 20:25]
  wire  pre_top_io_imem_req_ready; // @[core.scala 20:25]
  wire  pre_top_io_imem_req_valid; // @[core.scala 20:25]
  wire [63:0] pre_top_io_imem_req_bits_addr; // @[core.scala 20:25]
  wire [63:0] pre_top_br_old_PC_0; // @[core.scala 20:25]
  wire  pre_top_br_taken_0; // @[core.scala 20:25]
  wire [1:0] pre_top_insts_sent_after_br_0; // @[core.scala 20:25]
  wire [63:0] pre_top_br_target_0; // @[core.scala 20:25]
  wire  fs_top_clock; // @[core.scala 21:25]
  wire  fs_top_reset; // @[core.scala 21:25]
  wire  fs_top_io_pres_ready; // @[core.scala 21:25]
  wire  fs_top_io_pres_valid; // @[core.scala 21:25]
  wire [63:0] fs_top_io_pres_bits_PC; // @[core.scala 21:25]
  wire  fs_top_io_pres_bits_offset; // @[core.scala 21:25]
  wire  fs_top_io_ds_ready; // @[core.scala 21:25]
  wire  fs_top_io_ds_valid; // @[core.scala 21:25]
  wire [63:0] fs_top_io_ds_bits_PC; // @[core.scala 21:25]
  wire [31:0] fs_top_io_ds_bits_inst; // @[core.scala 21:25]
  wire  fs_top_io_imem_resp_valid; // @[core.scala 21:25]
  wire [63:0] fs_top_io_imem_resp_bits_data; // @[core.scala 21:25]
  wire  ds_top_clock; // @[core.scala 22:25]
  wire  ds_top_reset; // @[core.scala 22:25]
  wire  ds_top_io_fs_ready; // @[core.scala 22:25]
  wire  ds_top_io_fs_valid; // @[core.scala 22:25]
  wire [63:0] ds_top_io_fs_bits_PC; // @[core.scala 22:25]
  wire [31:0] ds_top_io_fs_bits_inst; // @[core.scala 22:25]
  wire  ds_top_io_es_ready; // @[core.scala 22:25]
  wire  ds_top_io_es_valid; // @[core.scala 22:25]
  wire [63:0] ds_top_io_es_bits_PC; // @[core.scala 22:25]
  wire [31:0] ds_top_io_es_bits_inst; // @[core.scala 22:25]
  wire [1:0] ds_top_io_es_bits_decode_op1_sel; // @[core.scala 22:25]
  wire [1:0] ds_top_io_es_bits_decode_op2_sel; // @[core.scala 22:25]
  wire [5:0] ds_top_io_es_bits_decode_alu_op; // @[core.scala 22:25]
  wire [1:0] ds_top_io_es_bits_decode_wb_sel; // @[core.scala 22:25]
  wire  ds_top_io_es_bits_decode_rf_wen; // @[core.scala 22:25]
  wire  ds_top_io_es_bits_decode_mem_en; // @[core.scala 22:25]
  wire  ds_top_io_es_bits_decode_mem_wr; // @[core.scala 22:25]
  wire [2:0] ds_top_io_es_bits_decode_mem_msk; // @[core.scala 22:25]
  wire [2:0] ds_top_io_es_bits_decode_csr_cmd; // @[core.scala 22:25]
  wire [63:0] ds_top_io_es_bits_rs1_data; // @[core.scala 22:25]
  wire [63:0] ds_top_io_es_bits_rs2_data; // @[core.scala 22:25]
  wire  ds_top_io_wb_rf_we; // @[core.scala 22:25]
  wire [4:0] ds_top_io_wb_wr_addr; // @[core.scala 22:25]
  wire [63:0] ds_top_io_wb_wr_data; // @[core.scala 22:25]
  wire [1:0] ds_top_io_wb_wb_sel; // @[core.scala 22:25]
  wire  ds_top_ms_res_rf_we; // @[core.scala 22:25]
  wire [4:0] ds_top_ms_res_wr_addr; // @[core.scala 22:25]
  wire [63:0] ds_top_ms_res_wr_data; // @[core.scala 22:25]
  wire [1:0] ds_top_ms_res_wb_sel; // @[core.scala 22:25]
  wire  ds_top_io_dmem_resp_valid; // @[core.scala 22:25]
  wire [63:0] ds_top_mepc_0; // @[core.scala 22:25]
  wire [63:0] ds_top_from_fs_r_PC; // @[core.scala 22:25]
  wire  ds_top_br_taken_final_0; // @[core.scala 22:25]
  wire [1:0] ds_top_insts_sent_after_br_0; // @[core.scala 22:25]
  wire  ds_top_es_res_rf_we; // @[core.scala 22:25]
  wire [4:0] ds_top_es_res_wr_addr; // @[core.scala 22:25]
  wire [63:0] ds_top_es_res_wr_data; // @[core.scala 22:25]
  wire [1:0] ds_top_es_res_wb_sel; // @[core.scala 22:25]
  wire [63:0] ds_top_exc_addr_0; // @[core.scala 22:25]
  wire [63:0] ds_top_br_target_0; // @[core.scala 22:25]
  wire  ds_top_exception_0; // @[core.scala 22:25]
  wire  es_top_clock; // @[core.scala 23:25]
  wire  es_top_reset; // @[core.scala 23:25]
  wire  es_top_io_ds_ready; // @[core.scala 23:25]
  wire  es_top_io_ds_valid; // @[core.scala 23:25]
  wire [63:0] es_top_io_ds_bits_PC; // @[core.scala 23:25]
  wire [31:0] es_top_io_ds_bits_inst; // @[core.scala 23:25]
  wire [1:0] es_top_io_ds_bits_decode_op1_sel; // @[core.scala 23:25]
  wire [1:0] es_top_io_ds_bits_decode_op2_sel; // @[core.scala 23:25]
  wire [5:0] es_top_io_ds_bits_decode_alu_op; // @[core.scala 23:25]
  wire [1:0] es_top_io_ds_bits_decode_wb_sel; // @[core.scala 23:25]
  wire  es_top_io_ds_bits_decode_rf_wen; // @[core.scala 23:25]
  wire  es_top_io_ds_bits_decode_mem_en; // @[core.scala 23:25]
  wire  es_top_io_ds_bits_decode_mem_wr; // @[core.scala 23:25]
  wire [2:0] es_top_io_ds_bits_decode_mem_msk; // @[core.scala 23:25]
  wire [2:0] es_top_io_ds_bits_decode_csr_cmd; // @[core.scala 23:25]
  wire [63:0] es_top_io_ds_bits_rs1_data; // @[core.scala 23:25]
  wire [63:0] es_top_io_ds_bits_rs2_data; // @[core.scala 23:25]
  wire  es_top_io_ms_ready; // @[core.scala 23:25]
  wire  es_top_io_ms_valid; // @[core.scala 23:25]
  wire [63:0] es_top_io_ms_bits_PC; // @[core.scala 23:25]
  wire [1:0] es_top_io_ms_bits_decode_wb_sel; // @[core.scala 23:25]
  wire  es_top_io_ms_bits_decode_rf_wen; // @[core.scala 23:25]
  wire  es_top_io_ms_bits_decode_mem_wr; // @[core.scala 23:25]
  wire [2:0] es_top_io_ms_bits_decode_mem_msk; // @[core.scala 23:25]
  wire [2:0] es_top_io_ms_bits_decode_csr_cmd; // @[core.scala 23:25]
  wire [63:0] es_top_io_ms_bits_alu_result; // @[core.scala 23:25]
  wire [4:0] es_top_io_ms_bits_rd_addr; // @[core.scala 23:25]
  wire [2:0] es_top_io_ms_bits_load_offset; // @[core.scala 23:25]
  wire [11:0] es_top_io_ms_bits_csr_addr; // @[core.scala 23:25]
  wire  es_top_io_dmem_req_ready; // @[core.scala 23:25]
  wire  es_top_io_dmem_req_valid; // @[core.scala 23:25]
  wire [63:0] es_top_io_dmem_req_bits_addr; // @[core.scala 23:25]
  wire [63:0] es_top_io_dmem_req_bits_data; // @[core.scala 23:25]
  wire  es_top_io_dmem_req_bits_wr; // @[core.scala 23:25]
  wire [7:0] es_top_io_dmem_req_bits_msk; // @[core.scala 23:25]
  wire  es_top_es_res_0_rf_we; // @[core.scala 23:25]
  wire [4:0] es_top_es_res_0_wr_addr; // @[core.scala 23:25]
  wire [63:0] es_top_es_res_0_wr_data; // @[core.scala 23:25]
  wire [1:0] es_top_es_res_0_wb_sel; // @[core.scala 23:25]
  wire  es_top_exception_0; // @[core.scala 23:25]
  wire  ms_top_clock; // @[core.scala 24:25]
  wire  ms_top_reset; // @[core.scala 24:25]
  wire  ms_top_io__es_ready; // @[core.scala 24:25]
  wire  ms_top_io__es_valid; // @[core.scala 24:25]
  wire [63:0] ms_top_io__es_bits_PC; // @[core.scala 24:25]
  wire [1:0] ms_top_io__es_bits_decode_wb_sel; // @[core.scala 24:25]
  wire  ms_top_io__es_bits_decode_rf_wen; // @[core.scala 24:25]
  wire  ms_top_io__es_bits_decode_mem_wr; // @[core.scala 24:25]
  wire [2:0] ms_top_io__es_bits_decode_mem_msk; // @[core.scala 24:25]
  wire [2:0] ms_top_io__es_bits_decode_csr_cmd; // @[core.scala 24:25]
  wire [63:0] ms_top_io__es_bits_alu_result; // @[core.scala 24:25]
  wire [4:0] ms_top_io__es_bits_rd_addr; // @[core.scala 24:25]
  wire [2:0] ms_top_io__es_bits_load_offset; // @[core.scala 24:25]
  wire [11:0] ms_top_io__es_bits_csr_addr; // @[core.scala 24:25]
  wire  ms_top_io__ws_valid; // @[core.scala 24:25]
  wire [63:0] ms_top_io__ws_bits_PC; // @[core.scala 24:25]
  wire [1:0] ms_top_io__ws_bits_decode_wb_sel; // @[core.scala 24:25]
  wire  ms_top_io__ws_bits_decode_rf_wen; // @[core.scala 24:25]
  wire [2:0] ms_top_io__ws_bits_decode_csr_cmd; // @[core.scala 24:25]
  wire [63:0] ms_top_io__ws_bits_final_result; // @[core.scala 24:25]
  wire [4:0] ms_top_io__ws_bits_rd_addr; // @[core.scala 24:25]
  wire [11:0] ms_top_io__ws_bits_csr_addr; // @[core.scala 24:25]
  wire  ms_top_io__dmem_resp_valid; // @[core.scala 24:25]
  wire [63:0] ms_top_io__dmem_resp_bits_data; // @[core.scala 24:25]
  wire  ms_top_ms_res_0_rf_we; // @[core.scala 24:25]
  wire [4:0] ms_top_ms_res_0_wr_addr; // @[core.scala 24:25]
  wire [63:0] ms_top_ms_res_0_wr_data; // @[core.scala 24:25]
  wire [1:0] ms_top_ms_res_0_wb_sel; // @[core.scala 24:25]
  wire  ms_top_io_dmem_resp_valid; // @[core.scala 24:25]
  wire  ms_top_exception_0; // @[core.scala 24:25]
  wire  ws_top_clock; // @[core.scala 25:25]
  wire  ws_top_reset; // @[core.scala 25:25]
  wire  ws_top_io_ms_ready; // @[core.scala 25:25]
  wire  ws_top_io_ms_valid; // @[core.scala 25:25]
  wire [63:0] ws_top_io_ms_bits_PC; // @[core.scala 25:25]
  wire [1:0] ws_top_io_ms_bits_decode_wb_sel; // @[core.scala 25:25]
  wire  ws_top_io_ms_bits_decode_rf_wen; // @[core.scala 25:25]
  wire [2:0] ws_top_io_ms_bits_decode_csr_cmd; // @[core.scala 25:25]
  wire [63:0] ws_top_io_ms_bits_final_result; // @[core.scala 25:25]
  wire [4:0] ws_top_io_ms_bits_rd_addr; // @[core.scala 25:25]
  wire [11:0] ws_top_io_ms_bits_csr_addr; // @[core.scala 25:25]
  wire  ws_top_io_rf_rf_we; // @[core.scala 25:25]
  wire [4:0] ws_top_io_rf_wr_addr; // @[core.scala 25:25]
  wire [63:0] ws_top_io_rf_wr_data; // @[core.scala 25:25]
  wire [1:0] ws_top_io_rf_wb_sel; // @[core.scala 25:25]
  wire [63:0] ws_top_mepc; // @[core.scala 25:25]
  wire [63:0] ws_top_exc_addr; // @[core.scala 25:25]
  wire  ws_top_exception; // @[core.scala 25:25]
  Pre_TOP pre_top ( // @[core.scala 20:25]
    .clock(pre_top_clock),
    .reset(pre_top_reset),
    .io_fs_ready(pre_top_io_fs_ready),
    .io_fs_valid(pre_top_io_fs_valid),
    .io_fs_bits_PC(pre_top_io_fs_bits_PC),
    .io_fs_bits_offset(pre_top_io_fs_bits_offset),
    .io_imem_req_ready(pre_top_io_imem_req_ready),
    .io_imem_req_valid(pre_top_io_imem_req_valid),
    .io_imem_req_bits_addr(pre_top_io_imem_req_bits_addr),
    .br_old_PC_0(pre_top_br_old_PC_0),
    .br_taken_0(pre_top_br_taken_0),
    .insts_sent_after_br_0(pre_top_insts_sent_after_br_0),
    .br_target_0(pre_top_br_target_0)
  );
  IF_TOP fs_top ( // @[core.scala 21:25]
    .clock(fs_top_clock),
    .reset(fs_top_reset),
    .io_pres_ready(fs_top_io_pres_ready),
    .io_pres_valid(fs_top_io_pres_valid),
    .io_pres_bits_PC(fs_top_io_pres_bits_PC),
    .io_pres_bits_offset(fs_top_io_pres_bits_offset),
    .io_ds_ready(fs_top_io_ds_ready),
    .io_ds_valid(fs_top_io_ds_valid),
    .io_ds_bits_PC(fs_top_io_ds_bits_PC),
    .io_ds_bits_inst(fs_top_io_ds_bits_inst),
    .io_imem_resp_valid(fs_top_io_imem_resp_valid),
    .io_imem_resp_bits_data(fs_top_io_imem_resp_bits_data)
  );
  ID_TOP ds_top ( // @[core.scala 22:25]
    .clock(ds_top_clock),
    .reset(ds_top_reset),
    .io_fs_ready(ds_top_io_fs_ready),
    .io_fs_valid(ds_top_io_fs_valid),
    .io_fs_bits_PC(ds_top_io_fs_bits_PC),
    .io_fs_bits_inst(ds_top_io_fs_bits_inst),
    .io_es_ready(ds_top_io_es_ready),
    .io_es_valid(ds_top_io_es_valid),
    .io_es_bits_PC(ds_top_io_es_bits_PC),
    .io_es_bits_inst(ds_top_io_es_bits_inst),
    .io_es_bits_decode_op1_sel(ds_top_io_es_bits_decode_op1_sel),
    .io_es_bits_decode_op2_sel(ds_top_io_es_bits_decode_op2_sel),
    .io_es_bits_decode_alu_op(ds_top_io_es_bits_decode_alu_op),
    .io_es_bits_decode_wb_sel(ds_top_io_es_bits_decode_wb_sel),
    .io_es_bits_decode_rf_wen(ds_top_io_es_bits_decode_rf_wen),
    .io_es_bits_decode_mem_en(ds_top_io_es_bits_decode_mem_en),
    .io_es_bits_decode_mem_wr(ds_top_io_es_bits_decode_mem_wr),
    .io_es_bits_decode_mem_msk(ds_top_io_es_bits_decode_mem_msk),
    .io_es_bits_decode_csr_cmd(ds_top_io_es_bits_decode_csr_cmd),
    .io_es_bits_rs1_data(ds_top_io_es_bits_rs1_data),
    .io_es_bits_rs2_data(ds_top_io_es_bits_rs2_data),
    .io_wb_rf_we(ds_top_io_wb_rf_we),
    .io_wb_wr_addr(ds_top_io_wb_wr_addr),
    .io_wb_wr_data(ds_top_io_wb_wr_data),
    .io_wb_wb_sel(ds_top_io_wb_wb_sel),
    .ms_res_rf_we(ds_top_ms_res_rf_we),
    .ms_res_wr_addr(ds_top_ms_res_wr_addr),
    .ms_res_wr_data(ds_top_ms_res_wr_data),
    .ms_res_wb_sel(ds_top_ms_res_wb_sel),
    .io_dmem_resp_valid(ds_top_io_dmem_resp_valid),
    .mepc_0(ds_top_mepc_0),
    .from_fs_r_PC(ds_top_from_fs_r_PC),
    .br_taken_final_0(ds_top_br_taken_final_0),
    .insts_sent_after_br_0(ds_top_insts_sent_after_br_0),
    .es_res_rf_we(ds_top_es_res_rf_we),
    .es_res_wr_addr(ds_top_es_res_wr_addr),
    .es_res_wr_data(ds_top_es_res_wr_data),
    .es_res_wb_sel(ds_top_es_res_wb_sel),
    .exc_addr_0(ds_top_exc_addr_0),
    .br_target_0(ds_top_br_target_0),
    .exception_0(ds_top_exception_0)
  );
  EXE_TOP es_top ( // @[core.scala 23:25]
    .clock(es_top_clock),
    .reset(es_top_reset),
    .io_ds_ready(es_top_io_ds_ready),
    .io_ds_valid(es_top_io_ds_valid),
    .io_ds_bits_PC(es_top_io_ds_bits_PC),
    .io_ds_bits_inst(es_top_io_ds_bits_inst),
    .io_ds_bits_decode_op1_sel(es_top_io_ds_bits_decode_op1_sel),
    .io_ds_bits_decode_op2_sel(es_top_io_ds_bits_decode_op2_sel),
    .io_ds_bits_decode_alu_op(es_top_io_ds_bits_decode_alu_op),
    .io_ds_bits_decode_wb_sel(es_top_io_ds_bits_decode_wb_sel),
    .io_ds_bits_decode_rf_wen(es_top_io_ds_bits_decode_rf_wen),
    .io_ds_bits_decode_mem_en(es_top_io_ds_bits_decode_mem_en),
    .io_ds_bits_decode_mem_wr(es_top_io_ds_bits_decode_mem_wr),
    .io_ds_bits_decode_mem_msk(es_top_io_ds_bits_decode_mem_msk),
    .io_ds_bits_decode_csr_cmd(es_top_io_ds_bits_decode_csr_cmd),
    .io_ds_bits_rs1_data(es_top_io_ds_bits_rs1_data),
    .io_ds_bits_rs2_data(es_top_io_ds_bits_rs2_data),
    .io_ms_ready(es_top_io_ms_ready),
    .io_ms_valid(es_top_io_ms_valid),
    .io_ms_bits_PC(es_top_io_ms_bits_PC),
    .io_ms_bits_decode_wb_sel(es_top_io_ms_bits_decode_wb_sel),
    .io_ms_bits_decode_rf_wen(es_top_io_ms_bits_decode_rf_wen),
    .io_ms_bits_decode_mem_wr(es_top_io_ms_bits_decode_mem_wr),
    .io_ms_bits_decode_mem_msk(es_top_io_ms_bits_decode_mem_msk),
    .io_ms_bits_decode_csr_cmd(es_top_io_ms_bits_decode_csr_cmd),
    .io_ms_bits_alu_result(es_top_io_ms_bits_alu_result),
    .io_ms_bits_rd_addr(es_top_io_ms_bits_rd_addr),
    .io_ms_bits_load_offset(es_top_io_ms_bits_load_offset),
    .io_ms_bits_csr_addr(es_top_io_ms_bits_csr_addr),
    .io_dmem_req_ready(es_top_io_dmem_req_ready),
    .io_dmem_req_valid(es_top_io_dmem_req_valid),
    .io_dmem_req_bits_addr(es_top_io_dmem_req_bits_addr),
    .io_dmem_req_bits_data(es_top_io_dmem_req_bits_data),
    .io_dmem_req_bits_wr(es_top_io_dmem_req_bits_wr),
    .io_dmem_req_bits_msk(es_top_io_dmem_req_bits_msk),
    .es_res_0_rf_we(es_top_es_res_0_rf_we),
    .es_res_0_wr_addr(es_top_es_res_0_wr_addr),
    .es_res_0_wr_data(es_top_es_res_0_wr_data),
    .es_res_0_wb_sel(es_top_es_res_0_wb_sel),
    .exception_0(es_top_exception_0)
  );
  MEM_TOP ms_top ( // @[core.scala 24:25]
    .clock(ms_top_clock),
    .reset(ms_top_reset),
    .io__es_ready(ms_top_io__es_ready),
    .io__es_valid(ms_top_io__es_valid),
    .io__es_bits_PC(ms_top_io__es_bits_PC),
    .io__es_bits_decode_wb_sel(ms_top_io__es_bits_decode_wb_sel),
    .io__es_bits_decode_rf_wen(ms_top_io__es_bits_decode_rf_wen),
    .io__es_bits_decode_mem_wr(ms_top_io__es_bits_decode_mem_wr),
    .io__es_bits_decode_mem_msk(ms_top_io__es_bits_decode_mem_msk),
    .io__es_bits_decode_csr_cmd(ms_top_io__es_bits_decode_csr_cmd),
    .io__es_bits_alu_result(ms_top_io__es_bits_alu_result),
    .io__es_bits_rd_addr(ms_top_io__es_bits_rd_addr),
    .io__es_bits_load_offset(ms_top_io__es_bits_load_offset),
    .io__es_bits_csr_addr(ms_top_io__es_bits_csr_addr),
    .io__ws_valid(ms_top_io__ws_valid),
    .io__ws_bits_PC(ms_top_io__ws_bits_PC),
    .io__ws_bits_decode_wb_sel(ms_top_io__ws_bits_decode_wb_sel),
    .io__ws_bits_decode_rf_wen(ms_top_io__ws_bits_decode_rf_wen),
    .io__ws_bits_decode_csr_cmd(ms_top_io__ws_bits_decode_csr_cmd),
    .io__ws_bits_final_result(ms_top_io__ws_bits_final_result),
    .io__ws_bits_rd_addr(ms_top_io__ws_bits_rd_addr),
    .io__ws_bits_csr_addr(ms_top_io__ws_bits_csr_addr),
    .io__dmem_resp_valid(ms_top_io__dmem_resp_valid),
    .io__dmem_resp_bits_data(ms_top_io__dmem_resp_bits_data),
    .ms_res_0_rf_we(ms_top_ms_res_0_rf_we),
    .ms_res_0_wr_addr(ms_top_ms_res_0_wr_addr),
    .ms_res_0_wr_data(ms_top_ms_res_0_wr_data),
    .ms_res_0_wb_sel(ms_top_ms_res_0_wb_sel),
    .io_dmem_resp_valid(ms_top_io_dmem_resp_valid),
    .exception_0(ms_top_exception_0)
  );
  WB_TOP ws_top ( // @[core.scala 25:25]
    .clock(ws_top_clock),
    .reset(ws_top_reset),
    .io_ms_ready(ws_top_io_ms_ready),
    .io_ms_valid(ws_top_io_ms_valid),
    .io_ms_bits_PC(ws_top_io_ms_bits_PC),
    .io_ms_bits_decode_wb_sel(ws_top_io_ms_bits_decode_wb_sel),
    .io_ms_bits_decode_rf_wen(ws_top_io_ms_bits_decode_rf_wen),
    .io_ms_bits_decode_csr_cmd(ws_top_io_ms_bits_decode_csr_cmd),
    .io_ms_bits_final_result(ws_top_io_ms_bits_final_result),
    .io_ms_bits_rd_addr(ws_top_io_ms_bits_rd_addr),
    .io_ms_bits_csr_addr(ws_top_io_ms_bits_csr_addr),
    .io_rf_rf_we(ws_top_io_rf_rf_we),
    .io_rf_wr_addr(ws_top_io_rf_wr_addr),
    .io_rf_wr_data(ws_top_io_rf_wr_data),
    .io_rf_wb_sel(ws_top_io_rf_wb_sel),
    .mepc(ws_top_mepc),
    .exc_addr(ws_top_exc_addr),
    .exception(ws_top_exception)
  );
  assign io_imem_req_valid = pre_top_io_imem_req_valid; // @[core.scala 36:18]
  assign io_imem_req_bits_addr = pre_top_io_imem_req_bits_addr; // @[core.scala 36:18]
  assign io_dmem_req_valid = es_top_io_dmem_req_valid; // @[core.scala 41:18]
  assign io_dmem_req_bits_addr = es_top_io_dmem_req_bits_addr; // @[core.scala 41:18]
  assign io_dmem_req_bits_data = es_top_io_dmem_req_bits_data; // @[core.scala 41:18]
  assign io_dmem_req_bits_wr = es_top_io_dmem_req_bits_wr; // @[core.scala 41:18]
  assign io_dmem_req_bits_msk = es_top_io_dmem_req_bits_msk; // @[core.scala 41:18]
  assign pre_top_clock = clock;
  assign pre_top_reset = reset;
  assign pre_top_io_fs_ready = fs_top_io_pres_ready; // @[core.scala 27:19]
  assign pre_top_io_imem_req_ready = io_imem_req_ready; // @[core.scala 36:18]
  assign pre_top_br_old_PC_0 = ds_top_from_fs_r_PC;
  assign pre_top_br_taken_0 = ds_top_br_taken_final_0;
  assign pre_top_br_target_0 = ds_top_br_target_0;
  assign fs_top_clock = clock;
  assign fs_top_reset = reset;
  assign fs_top_io_pres_valid = pre_top_io_fs_valid; // @[core.scala 27:19]
  assign fs_top_io_pres_bits_PC = pre_top_io_fs_bits_PC; // @[core.scala 27:19]
  assign fs_top_io_pres_bits_offset = pre_top_io_fs_bits_offset; // @[core.scala 27:19]
  assign fs_top_io_ds_ready = ds_top_io_fs_ready; // @[core.scala 28:18]
  assign fs_top_io_imem_resp_valid = io_imem_resp_valid; // @[core.scala 37:18]
  assign fs_top_io_imem_resp_bits_data = io_imem_resp_bits_data; // @[core.scala 37:18]
  assign ds_top_clock = clock;
  assign ds_top_reset = reset;
  assign ds_top_io_fs_valid = fs_top_io_ds_valid; // @[core.scala 28:18]
  assign ds_top_io_fs_bits_PC = fs_top_io_ds_bits_PC; // @[core.scala 28:18]
  assign ds_top_io_fs_bits_inst = fs_top_io_ds_bits_inst; // @[core.scala 28:18]
  assign ds_top_io_es_ready = es_top_io_ds_ready; // @[core.scala 29:18]
  assign ds_top_io_wb_rf_we = ws_top_io_rf_rf_we; // @[core.scala 32:18]
  assign ds_top_io_wb_wr_addr = ws_top_io_rf_wr_addr; // @[core.scala 32:18]
  assign ds_top_io_wb_wr_data = ws_top_io_rf_wr_data; // @[core.scala 32:18]
  assign ds_top_io_wb_wb_sel = ws_top_io_rf_wb_sel; // @[core.scala 32:18]
  assign ds_top_ms_res_rf_we = ms_top_ms_res_0_rf_we;
  assign ds_top_ms_res_wr_addr = ms_top_ms_res_0_wr_addr;
  assign ds_top_ms_res_wr_data = ms_top_ms_res_0_wr_data;
  assign ds_top_ms_res_wb_sel = ms_top_ms_res_0_wb_sel;
  assign ds_top_io_dmem_resp_valid = ms_top_io_dmem_resp_valid;
  assign ds_top_mepc_0 = ws_top_mepc;
  assign ds_top_insts_sent_after_br_0 = pre_top_insts_sent_after_br_0;
  assign ds_top_es_res_rf_we = es_top_es_res_0_rf_we;
  assign ds_top_es_res_wr_addr = es_top_es_res_0_wr_addr;
  assign ds_top_es_res_wr_data = es_top_es_res_0_wr_data;
  assign ds_top_es_res_wb_sel = es_top_es_res_0_wb_sel;
  assign ds_top_exc_addr_0 = ws_top_exc_addr;
  assign ds_top_exception_0 = ws_top_exception;
  assign es_top_clock = clock;
  assign es_top_reset = reset;
  assign es_top_io_ds_valid = ds_top_io_es_valid; // @[core.scala 29:18]
  assign es_top_io_ds_bits_PC = ds_top_io_es_bits_PC; // @[core.scala 29:18]
  assign es_top_io_ds_bits_inst = ds_top_io_es_bits_inst; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_op1_sel = ds_top_io_es_bits_decode_op1_sel; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_op2_sel = ds_top_io_es_bits_decode_op2_sel; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_alu_op = ds_top_io_es_bits_decode_alu_op; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_wb_sel = ds_top_io_es_bits_decode_wb_sel; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_rf_wen = ds_top_io_es_bits_decode_rf_wen; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_mem_en = ds_top_io_es_bits_decode_mem_en; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_mem_wr = ds_top_io_es_bits_decode_mem_wr; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_mem_msk = ds_top_io_es_bits_decode_mem_msk; // @[core.scala 29:18]
  assign es_top_io_ds_bits_decode_csr_cmd = ds_top_io_es_bits_decode_csr_cmd; // @[core.scala 29:18]
  assign es_top_io_ds_bits_rs1_data = ds_top_io_es_bits_rs1_data; // @[core.scala 29:18]
  assign es_top_io_ds_bits_rs2_data = ds_top_io_es_bits_rs2_data; // @[core.scala 29:18]
  assign es_top_io_ms_ready = ms_top_io__es_ready; // @[core.scala 30:18]
  assign es_top_io_dmem_req_ready = io_dmem_req_ready; // @[core.scala 41:18]
  assign es_top_exception_0 = ws_top_exception;
  assign ms_top_clock = clock;
  assign ms_top_reset = reset;
  assign ms_top_io__es_valid = es_top_io_ms_valid; // @[core.scala 30:18]
  assign ms_top_io__es_bits_PC = es_top_io_ms_bits_PC; // @[core.scala 30:18]
  assign ms_top_io__es_bits_decode_wb_sel = es_top_io_ms_bits_decode_wb_sel; // @[core.scala 30:18]
  assign ms_top_io__es_bits_decode_rf_wen = es_top_io_ms_bits_decode_rf_wen; // @[core.scala 30:18]
  assign ms_top_io__es_bits_decode_mem_wr = es_top_io_ms_bits_decode_mem_wr; // @[core.scala 30:18]
  assign ms_top_io__es_bits_decode_mem_msk = es_top_io_ms_bits_decode_mem_msk; // @[core.scala 30:18]
  assign ms_top_io__es_bits_decode_csr_cmd = es_top_io_ms_bits_decode_csr_cmd; // @[core.scala 30:18]
  assign ms_top_io__es_bits_alu_result = es_top_io_ms_bits_alu_result; // @[core.scala 30:18]
  assign ms_top_io__es_bits_rd_addr = es_top_io_ms_bits_rd_addr; // @[core.scala 30:18]
  assign ms_top_io__es_bits_load_offset = es_top_io_ms_bits_load_offset; // @[core.scala 30:18]
  assign ms_top_io__es_bits_csr_addr = es_top_io_ms_bits_csr_addr; // @[core.scala 30:18]
  assign ms_top_io__dmem_resp_valid = io_dmem_resp_valid; // @[core.scala 42:18]
  assign ms_top_io__dmem_resp_bits_data = io_dmem_resp_bits_data; // @[core.scala 42:18]
  assign ms_top_exception_0 = ws_top_exception;
  assign ws_top_clock = clock;
  assign ws_top_reset = reset;
  assign ws_top_io_ms_valid = ms_top_io__ws_valid; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_PC = ms_top_io__ws_bits_PC; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_decode_wb_sel = ms_top_io__ws_bits_decode_wb_sel; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_decode_rf_wen = ms_top_io__ws_bits_decode_rf_wen; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_decode_csr_cmd = ms_top_io__ws_bits_decode_csr_cmd; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_final_result = ms_top_io__ws_bits_final_result; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_rd_addr = ms_top_io__ws_bits_rd_addr; // @[core.scala 31:18]
  assign ws_top_io_ms_bits_csr_addr = ms_top_io__ws_bits_csr_addr; // @[core.scala 31:18]
endmodule
module ysys_chenxi(
  input         clock,
  input         reset,
  output [7:0]  io_mem_awid,
  output [63:0] io_mem_awaddr,
  output [7:0]  io_mem_awlen,
  output [2:0]  io_mem_awsize,
  output [1:0]  io_mem_awburst,
  output        io_mem_awlock,
  output [3:0]  io_mem_awcache,
  output [2:0]  io_mem_awprot,
  output        io_mem_awvalid,
  input         io_mem_awready,
  output [7:0]  io_mem_wid,
  output [63:0] io_mem_wdata,
  output [7:0]  io_mem_wstrb,
  output        io_mem_wlast,
  output        io_mem_wvalid,
  input         io_mem_wready,
  input  [7:0]  io_mem_bid,
  input  [1:0]  io_mem_bresp,
  input         io_mem_bvalid,
  output        io_mem_bready,
  output [7:0]  io_mem_arid,
  output [63:0] io_mem_araddr,
  output [7:0]  io_mem_arlen,
  output [2:0]  io_mem_arsize,
  output [1:0]  io_mem_arburst,
  output        io_mem_arlock,
  output [3:0]  io_mem_arcache,
  output [2:0]  io_mem_arprot,
  output        io_mem_arvalid,
  input         io_mem_arready,
  input  [7:0]  io_mem_rid,
  input  [63:0] io_mem_rdata,
  input  [1:0]  io_mem_rresp,
  input         io_mem_rlast,
  input         io_mem_rvalid,
  output        io_mem_rready,
  output [63:0] io_mmio_awaddr,
  output [2:0]  io_mmio_awprot,
  output        io_mmio_awvalid,
  input         io_mmio_awready,
  output [63:0] io_mmio_wdata,
  output [7:0]  io_mmio_wstrb,
  output        io_mmio_wvalid,
  input         io_mmio_wready,
  input  [1:0]  io_mmio_bresp,
  input         io_mmio_bvalid,
  output        io_mmio_bready,
  output [63:0] io_mmio_araddr,
  output [2:0]  io_mmio_arprot,
  output        io_mmio_arvalid,
  input         io_mmio_arready,
  input  [63:0] io_mmio_rdata,
  input  [1:0]  io_mmio_rresp,
  input         io_mmio_rvalid,
  output        io_mmio_rready,
  input         io_mtip,
  input         io_meip
);
  wire  core_clock; // @[ysys_chenxi.scala 18:22]
  wire  core_reset; // @[ysys_chenxi.scala 18:22]
  wire  core_io_imem_req_ready; // @[ysys_chenxi.scala 18:22]
  wire  core_io_imem_req_valid; // @[ysys_chenxi.scala 18:22]
  wire [63:0] core_io_imem_req_bits_addr; // @[ysys_chenxi.scala 18:22]
  wire  core_io_imem_resp_valid; // @[ysys_chenxi.scala 18:22]
  wire [63:0] core_io_imem_resp_bits_data; // @[ysys_chenxi.scala 18:22]
  wire  core_io_dmem_req_ready; // @[ysys_chenxi.scala 18:22]
  wire  core_io_dmem_req_valid; // @[ysys_chenxi.scala 18:22]
  wire [63:0] core_io_dmem_req_bits_addr; // @[ysys_chenxi.scala 18:22]
  wire [63:0] core_io_dmem_req_bits_data; // @[ysys_chenxi.scala 18:22]
  wire  core_io_dmem_req_bits_wr; // @[ysys_chenxi.scala 18:22]
  wire [7:0] core_io_dmem_req_bits_msk; // @[ysys_chenxi.scala 18:22]
  wire  core_io_dmem_resp_valid; // @[ysys_chenxi.scala 18:22]
  wire [63:0] core_io_dmem_resp_bits_data; // @[ysys_chenxi.scala 18:22]
  wire [7:0] bridge_awid; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_awaddr; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_awlen; // @[ysys_chenxi.scala 19:24]
  wire [2:0] bridge_awsize; // @[ysys_chenxi.scala 19:24]
  wire [1:0] bridge_awburst; // @[ysys_chenxi.scala 19:24]
  wire  bridge_awlock; // @[ysys_chenxi.scala 19:24]
  wire [3:0] bridge_awcache; // @[ysys_chenxi.scala 19:24]
  wire [2:0] bridge_awprot; // @[ysys_chenxi.scala 19:24]
  wire  bridge_awvalid; // @[ysys_chenxi.scala 19:24]
  wire  bridge_awready; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_wid; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_wdata; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_wstrb; // @[ysys_chenxi.scala 19:24]
  wire  bridge_wlast; // @[ysys_chenxi.scala 19:24]
  wire  bridge_wvalid; // @[ysys_chenxi.scala 19:24]
  wire  bridge_wready; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_bid; // @[ysys_chenxi.scala 19:24]
  wire [1:0] bridge_bresp; // @[ysys_chenxi.scala 19:24]
  wire  bridge_bvalid; // @[ysys_chenxi.scala 19:24]
  wire  bridge_bready; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_arid; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_araddr; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_arlen; // @[ysys_chenxi.scala 19:24]
  wire [2:0] bridge_arsize; // @[ysys_chenxi.scala 19:24]
  wire [1:0] bridge_arburst; // @[ysys_chenxi.scala 19:24]
  wire  bridge_arlock; // @[ysys_chenxi.scala 19:24]
  wire [3:0] bridge_arcache; // @[ysys_chenxi.scala 19:24]
  wire [2:0] bridge_arprot; // @[ysys_chenxi.scala 19:24]
  wire  bridge_arvalid; // @[ysys_chenxi.scala 19:24]
  wire  bridge_arready; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_rid; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_rdata; // @[ysys_chenxi.scala 19:24]
  wire [1:0] bridge_rresp; // @[ysys_chenxi.scala 19:24]
  wire  bridge_rlast; // @[ysys_chenxi.scala 19:24]
  wire  bridge_rvalid; // @[ysys_chenxi.scala 19:24]
  wire  bridge_rready; // @[ysys_chenxi.scala 19:24]
  wire  bridge_clock; // @[ysys_chenxi.scala 19:24]
  wire  bridge_reset; // @[ysys_chenxi.scala 19:24]
  wire  bridge_inst_req; // @[ysys_chenxi.scala 19:24]
  wire  bridge_inst_wr; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_inst_size; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_inst_addr; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_inst_wdata; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_inst_rdata; // @[ysys_chenxi.scala 19:24]
  wire  bridge_inst_addr_ok; // @[ysys_chenxi.scala 19:24]
  wire  bridge_inst_data_ok; // @[ysys_chenxi.scala 19:24]
  wire  bridge_data_req; // @[ysys_chenxi.scala 19:24]
  wire  bridge_data_wr; // @[ysys_chenxi.scala 19:24]
  wire [7:0] bridge_data_size; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_data_addr; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_data_wdata; // @[ysys_chenxi.scala 19:24]
  wire [63:0] bridge_data_rdata; // @[ysys_chenxi.scala 19:24]
  wire  bridge_data_addr_ok; // @[ysys_chenxi.scala 19:24]
  wire  bridge_data_data_ok; // @[ysys_chenxi.scala 19:24]
  wire  is_mem_raddr = bridge_araddr >= 64'h80000000; // @[ysys_chenxi.scala 52:42]
  wire  is_mem_waddr = bridge_awaddr >= 64'h80000000; // @[ysys_chenxi.scala 53:42]
  core core ( // @[ysys_chenxi.scala 18:22]
    .clock(core_clock),
    .reset(core_reset),
    .io_imem_req_ready(core_io_imem_req_ready),
    .io_imem_req_valid(core_io_imem_req_valid),
    .io_imem_req_bits_addr(core_io_imem_req_bits_addr),
    .io_imem_resp_valid(core_io_imem_resp_valid),
    .io_imem_resp_bits_data(core_io_imem_resp_bits_data),
    .io_dmem_req_ready(core_io_dmem_req_ready),
    .io_dmem_req_valid(core_io_dmem_req_valid),
    .io_dmem_req_bits_addr(core_io_dmem_req_bits_addr),
    .io_dmem_req_bits_data(core_io_dmem_req_bits_data),
    .io_dmem_req_bits_wr(core_io_dmem_req_bits_wr),
    .io_dmem_req_bits_msk(core_io_dmem_req_bits_msk),
    .io_dmem_resp_valid(core_io_dmem_resp_valid),
    .io_dmem_resp_bits_data(core_io_dmem_resp_bits_data)
  );
  AXI_Bridge bridge ( // @[ysys_chenxi.scala 19:24]
    .awid(bridge_awid),
    .awaddr(bridge_awaddr),
    .awlen(bridge_awlen),
    .awsize(bridge_awsize),
    .awburst(bridge_awburst),
    .awlock(bridge_awlock),
    .awcache(bridge_awcache),
    .awprot(bridge_awprot),
    .awvalid(bridge_awvalid),
    .awready(bridge_awready),
    .wid(bridge_wid),
    .wdata(bridge_wdata),
    .wstrb(bridge_wstrb),
    .wlast(bridge_wlast),
    .wvalid(bridge_wvalid),
    .wready(bridge_wready),
    .bid(bridge_bid),
    .bresp(bridge_bresp),
    .bvalid(bridge_bvalid),
    .bready(bridge_bready),
    .arid(bridge_arid),
    .araddr(bridge_araddr),
    .arlen(bridge_arlen),
    .arsize(bridge_arsize),
    .arburst(bridge_arburst),
    .arlock(bridge_arlock),
    .arcache(bridge_arcache),
    .arprot(bridge_arprot),
    .arvalid(bridge_arvalid),
    .arready(bridge_arready),
    .rid(bridge_rid),
    .rdata(bridge_rdata),
    .rresp(bridge_rresp),
    .rlast(bridge_rlast),
    .rvalid(bridge_rvalid),
    .rready(bridge_rready),
    .clock(bridge_clock),
    .reset(bridge_reset),
    .inst_req(bridge_inst_req),
    .inst_wr(bridge_inst_wr),
    .inst_size(bridge_inst_size),
    .inst_addr(bridge_inst_addr),
    .inst_wdata(bridge_inst_wdata),
    .inst_rdata(bridge_inst_rdata),
    .inst_addr_ok(bridge_inst_addr_ok),
    .inst_data_ok(bridge_inst_data_ok),
    .data_req(bridge_data_req),
    .data_wr(bridge_data_wr),
    .data_size(bridge_data_size),
    .data_addr(bridge_data_addr),
    .data_wdata(bridge_data_wdata),
    .data_rdata(bridge_data_rdata),
    .data_addr_ok(bridge_data_addr_ok),
    .data_data_ok(bridge_data_data_ok)
  );
  assign io_mem_awid = bridge_awid; // @[ysys_chenxi.scala 55:17]
  assign io_mem_awaddr = bridge_awaddr; // @[ysys_chenxi.scala 56:19]
  assign io_mem_awlen = bridge_awlen; // @[ysys_chenxi.scala 57:18]
  assign io_mem_awsize = bridge_awsize; // @[ysys_chenxi.scala 58:19]
  assign io_mem_awburst = bridge_awburst; // @[ysys_chenxi.scala 59:20]
  assign io_mem_awlock = bridge_awlock; // @[ysys_chenxi.scala 60:19]
  assign io_mem_awcache = bridge_awcache; // @[ysys_chenxi.scala 61:20]
  assign io_mem_awprot = bridge_awprot; // @[ysys_chenxi.scala 62:19]
  assign io_mem_awvalid = is_mem_waddr & bridge_awvalid; // @[ysys_chenxi.scala 63:26]
  assign io_mem_wid = bridge_wid; // @[ysys_chenxi.scala 65:16]
  assign io_mem_wdata = bridge_wdata; // @[ysys_chenxi.scala 66:18]
  assign io_mem_wstrb = bridge_wstrb; // @[ysys_chenxi.scala 67:18]
  assign io_mem_wlast = bridge_wlast; // @[ysys_chenxi.scala 68:18]
  assign io_mem_wvalid = is_mem_waddr & bridge_wvalid; // @[ysys_chenxi.scala 69:25]
  assign io_mem_bready = bridge_bready; // @[ysys_chenxi.scala 71:19]
  assign io_mem_arid = bridge_arid; // @[ysys_chenxi.scala 72:17]
  assign io_mem_araddr = bridge_araddr; // @[ysys_chenxi.scala 73:19]
  assign io_mem_arlen = bridge_arlen; // @[ysys_chenxi.scala 74:18]
  assign io_mem_arsize = bridge_arsize; // @[ysys_chenxi.scala 75:19]
  assign io_mem_arburst = bridge_arburst; // @[ysys_chenxi.scala 76:20]
  assign io_mem_arlock = bridge_arlock; // @[ysys_chenxi.scala 77:19]
  assign io_mem_arcache = bridge_arcache; // @[ysys_chenxi.scala 78:20]
  assign io_mem_arprot = bridge_arprot; // @[ysys_chenxi.scala 79:19]
  assign io_mem_arvalid = is_mem_raddr & bridge_arvalid; // @[ysys_chenxi.scala 80:26]
  assign io_mem_rready = bridge_rready; // @[ysys_chenxi.scala 81:19]
  assign io_mmio_awaddr = bridge_awaddr; // @[ysys_chenxi.scala 84:21]
  assign io_mmio_awprot = bridge_awprot; // @[ysys_chenxi.scala 85:21]
  assign io_mmio_awvalid = is_mem_waddr ? 1'h0 : bridge_awvalid; // @[ysys_chenxi.scala 86:27]
  assign io_mmio_wdata = bridge_wdata; // @[ysys_chenxi.scala 87:21]
  assign io_mmio_wstrb = bridge_wstrb; // @[ysys_chenxi.scala 88:21]
  assign io_mmio_wvalid = is_mem_waddr ? 1'h0 : bridge_wvalid; // @[ysys_chenxi.scala 89:27]
  assign io_mmio_bready = bridge_bready; // @[ysys_chenxi.scala 90:21]
  assign io_mmio_araddr = bridge_araddr; // @[ysys_chenxi.scala 91:21]
  assign io_mmio_arprot = bridge_arprot; // @[ysys_chenxi.scala 92:21]
  assign io_mmio_arvalid = is_mem_raddr ? 1'h0 : bridge_arvalid; // @[ysys_chenxi.scala 93:27]
  assign io_mmio_rready = bridge_rready; // @[ysys_chenxi.scala 94:21]
  assign core_clock = clock;
  assign core_reset = reset;
  assign core_io_imem_req_ready = bridge_inst_addr_ok; // @[ysys_chenxi.scala 33:16]
  assign core_io_imem_resp_valid = bridge_inst_data_ok; // @[ysys_chenxi.scala 35:21]
  assign core_io_imem_resp_bits_data = bridge_inst_rdata; // @[ysys_chenxi.scala 36:21]
  assign core_io_dmem_req_ready = bridge_data_addr_ok; // @[ysys_chenxi.scala 44:16]
  assign core_io_dmem_resp_valid = bridge_data_data_ok; // @[ysys_chenxi.scala 46:21]
  assign core_io_dmem_resp_bits_data = bridge_data_rdata; // @[ysys_chenxi.scala 47:21]
  assign bridge_awready = io_mem_awready | io_mmio_awready; // @[ysys_chenxi.scala 101:41]
  assign bridge_wready = io_mem_wready | io_mmio_wready; // @[ysys_chenxi.scala 102:41]
  assign bridge_bid = io_mem_bid; // @[ysys_chenxi.scala 97:19]
  assign bridge_bresp = io_mem_bresp | io_mmio_bresp; // @[ysys_chenxi.scala 103:41]
  assign bridge_bvalid = io_mem_bvalid | io_mmio_bvalid; // @[ysys_chenxi.scala 104:41]
  assign bridge_arready = io_mem_arready | io_mmio_arready; // @[ysys_chenxi.scala 105:41]
  assign bridge_rid = io_mem_rid; // @[ysys_chenxi.scala 98:19]
  assign bridge_rdata = io_mem_rvalid ? io_mem_rdata : io_mmio_rdata; // @[ysys_chenxi.scala 106:27]
  assign bridge_rresp = io_mem_rresp | io_mmio_rresp; // @[ysys_chenxi.scala 107:41]
  assign bridge_rlast = io_mem_rlast; // @[ysys_chenxi.scala 99:21]
  assign bridge_rvalid = io_mem_rvalid | io_mmio_rvalid; // @[ysys_chenxi.scala 108:41]
  assign bridge_clock = clock; // @[ysys_chenxi.scala 24:25]
  assign bridge_reset = reset; // @[ysys_chenxi.scala 25:25]
  assign bridge_inst_req = core_io_imem_req_valid; // @[ysys_chenxi.scala 28:25]
  assign bridge_inst_wr = 1'h0; // @[ysys_chenxi.scala 29:25]
  assign bridge_inst_size = 8'hff; // @[ysys_chenxi.scala 30:25]
  assign bridge_inst_addr = core_io_imem_req_bits_addr; // @[ysys_chenxi.scala 31:25]
  assign bridge_inst_wdata = 64'h0; // @[ysys_chenxi.scala 32:25]
  assign bridge_data_req = core_io_dmem_req_valid; // @[ysys_chenxi.scala 39:25]
  assign bridge_data_wr = core_io_dmem_req_bits_wr; // @[ysys_chenxi.scala 40:25]
  assign bridge_data_size = core_io_dmem_req_bits_msk; // @[ysys_chenxi.scala 41:25]
  assign bridge_data_addr = core_io_dmem_req_bits_addr; // @[ysys_chenxi.scala 42:25]
  assign bridge_data_wdata = core_io_dmem_req_bits_data; // @[ysys_chenxi.scala 43:25]
endmodule
