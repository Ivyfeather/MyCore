// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"
#include "verilated_cov.h"

//==========

class VTop__Syms;
class VTop_VerilatedVcd;


//----------

VL_MODULE(VTop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_imem_req_ready,0,0);
    VL_OUT8(io_imem_req_valid,0,0);
    VL_OUT8(io_imem_req_bits_wr,0,0);
    VL_OUT8(io_imem_req_bits_msk,2,0);
    VL_IN8(io_imem_resp_valid,0,0);
    VL_IN8(io_dmem_req_ready,0,0);
    VL_OUT8(io_dmem_req_valid,0,0);
    VL_OUT8(io_dmem_req_bits_wr,0,0);
    VL_OUT8(io_dmem_req_bits_msk,2,0);
    VL_IN8(io_dmem_resp_valid,0,0);
    VL_OUT8(io_debug_valid,0,0);
    VL_OUT8(io_debug_trap,0,0);
    VL_OUT(io_imem_req_bits_data,31,0);
    VL_IN(io_imem_resp_bits_data,31,0);
    VL_OUT(io_debug_inst,31,0);
    VL_OUT64(io_imem_req_bits_addr,63,0);
    VL_OUT64(io_dmem_req_bits_addr,63,0);
    VL_OUT64(io_dmem_req_bits_data,63,0);
    VL_IN64(io_dmem_resp_bits_data,63,0);
    VL_OUT64(io_debug_rf_0,63,0);
    VL_OUT64(io_debug_rf_1,63,0);
    VL_OUT64(io_debug_rf_2,63,0);
    VL_OUT64(io_debug_rf_3,63,0);
    VL_OUT64(io_debug_rf_4,63,0);
    VL_OUT64(io_debug_rf_5,63,0);
    VL_OUT64(io_debug_rf_6,63,0);
    VL_OUT64(io_debug_rf_7,63,0);
    VL_OUT64(io_debug_rf_8,63,0);
    VL_OUT64(io_debug_rf_9,63,0);
    VL_OUT64(io_debug_rf_10,63,0);
    VL_OUT64(io_debug_rf_11,63,0);
    VL_OUT64(io_debug_rf_12,63,0);
    VL_OUT64(io_debug_rf_13,63,0);
    VL_OUT64(io_debug_rf_14,63,0);
    VL_OUT64(io_debug_rf_15,63,0);
    VL_OUT64(io_debug_rf_16,63,0);
    VL_OUT64(io_debug_rf_17,63,0);
    VL_OUT64(io_debug_rf_18,63,0);
    VL_OUT64(io_debug_rf_19,63,0);
    VL_OUT64(io_debug_rf_20,63,0);
    VL_OUT64(io_debug_rf_21,63,0);
    VL_OUT64(io_debug_rf_22,63,0);
    VL_OUT64(io_debug_rf_23,63,0);
    VL_OUT64(io_debug_rf_24,63,0);
    VL_OUT64(io_debug_rf_25,63,0);
    VL_OUT64(io_debug_rf_26,63,0);
    VL_OUT64(io_debug_rf_27,63,0);
    VL_OUT64(io_debug_rf_28,63,0);
    VL_OUT64(io_debug_rf_29,63,0);
    VL_OUT64(io_debug_rf_30,63,0);
    VL_OUT64(io_debug_rf_31,63,0);
    VL_OUT64(io_debug_PC,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ Top__DOT__imem_req_ready;
        CData/*0:0*/ Top__DOT__imem_resp_valid;
        CData/*0:0*/ Top__DOT__dmem_req_ready;
        CData/*0:0*/ Top__DOT__dmem_resp_valid;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top_io_pres_ready;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top_io_ds_valid;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top_io_fs_ready;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top_io_es_valid;
        CData/*0:0*/ Top__DOT__core__DOT__es_top_io_ds_ready;
        CData/*0:0*/ Top__DOT__core__DOT__es_top_io_ms_valid;
        CData/*0:0*/ Top__DOT__core__DOT__es_top_io_dmem_req_valid;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top_io_es_ready;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top_io_ws_valid;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT__pre_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT___GEN_1;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT__buf_valid;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT__imem_req_r;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT___GEN_3;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT___GEN_5;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top__DOT__fs_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top__DOT___GEN_2;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top__DOT__fs_valid;
        CData/*3:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel;
        CData/*5:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr;
        CData/*2:0*/ Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT___T;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__ds_valid;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__rf_eq;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__rf_lt;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__rf_ltu;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__flush_reg;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__br_taken;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT___flush_reg_T_1;
        CData/*3:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_221;
        CData/*3:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_236;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_266;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_281;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_296;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_334;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_349;
        CData/*5:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_383;
        CData/*5:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_398;
        CData/*5:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_413;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_443;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_458;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_473;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_507;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_536;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_560;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_577;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_594;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_641;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_659;
        CData/*2:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_698;
        CData/*2:0*/ Top__DOT__core__DOT__ds_top__DOT__idu__DOT___T_713;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT___T;
        CData/*1:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel;
        CData/*1:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel;
    };
    struct {
        CData/*5:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op;
        CData/*1:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr;
        CData/*2:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__es_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__es_valid;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__dmem_req_r;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT___GEN_17;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT___T;
        CData/*1:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr;
        CData/*4:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT___GEN_4;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT__ms_valid;
        CData/*3:0*/ Top__DOT__core__DOT__ms_top__DOT__unfinished_store;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT___T_1;
        CData/*3:0*/ Top__DOT__core__DOT__ms_top__DOT___unfinished_store_T_1;
        CData/*3:0*/ Top__DOT__core__DOT__ms_top__DOT___unfinished_store_T_3;
        CData/*0:0*/ Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen;
        CData/*4:0*/ Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr;
        CData/*0:0*/ Top__DOT__core__DOT__ws_top__DOT__is_commit;
        CData/*0:0*/ Top__DOT__core__DOT__ws_top__DOT__REG;
        SData/*11:0*/ Top__DOT__core__DOT__ds_top__DOT__imm_b;
        SData/*11:0*/ Top__DOT__core__DOT__es_top__DOT__imm_s;
        IData/*31:0*/ Top__DOT__imem_resp_bits_data;
        IData/*31:0*/ Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst;
        IData/*19:0*/ Top__DOT__core__DOT__ds_top__DOT__imm_j;
        WData/*65:0*/ Top__DOT__core__DOT__ds_top__DOT__imm_b_sext[3];
        WData/*73:0*/ Top__DOT__core__DOT__ds_top__DOT__imm_j_sext[3];
        WData/*65:0*/ Top__DOT__core__DOT__ds_top__DOT__branch_target[3];
        WData/*73:0*/ Top__DOT__core__DOT__ds_top__DOT__jmp_target[3];
        WData/*73:0*/ Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[3];
        IData/*31:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst;
        WData/*64:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[3];
        WData/*126:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_7[4];
        QData/*63:0*/ Top__DOT__core__DOT__pre_top_io_imem_req_bits_addr;
        QData/*63:0*/ Top__DOT__core__DOT__es_top_io_ms_bits_alu_result;
        QData/*63:0*/ Top__DOT__core__DOT__pre_top__DOT__pre_pc;
        QData/*63:0*/ Top__DOT__core__DOT__pre_top__DOT__buf_npc;
        QData/*63:0*/ Top__DOT__core__DOT__pre_top__DOT__seq_pc;
        QData/*63:0*/ Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__imm_i_sext;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__jr_target;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu_io_in1;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu_io_in2;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu_io_out;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__imm_i_sext;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__imm_s_sext;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__imm_u_sext;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result;
    };
    struct {
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result;
        QData/*63:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC;
        QData/*63:0*/ Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result;
        QData/*63:0*/ Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC;
        QData/*63:0*/ Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[32];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ Top__DOT____Vtogcov__clock;
        CData/*0:0*/ Top__DOT____Vtogcov__reset;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_req_valid;
        CData/*2:0*/ Top__DOT____Vtogcov__io_imem_req_bits_msk;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_wr;
        CData/*2:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_msk;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_debug_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_debug_trap;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_imem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_imem_req_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_imem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_dmem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_dmem_req_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_dmem_req_bits_wr;
        CData/*2:0*/ Top__DOT____Vtogcov__core_io_dmem_req_bits_msk;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_dmem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_debug_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__core_io_debug_trap;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__pre_top_io_fs_ready;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__pre_top_io_fs_valid;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__pre_top_br_taken_0;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__fs_top_io_ds_ready;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__fs_top_io_ds_valid;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_ready;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_valid;
        CData/*1:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_op1_sel;
        CData/*1:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_op2_sel;
        CData/*5:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_alu_op;
        CData/*1:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_rf_wen;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_mem_en;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_mem_wr;
        CData/*2:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_decode_mem_msk;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_wb_rf_we;
        CData/*4:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_wb_wr_addr;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_ms_res_rf_we;
        CData/*4:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_addr;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_es_res_rf_we;
        CData/*4:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_es_res_wr_addr;
        CData/*1:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_es_res_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__es_top_io_ms_ready;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__es_top_io_ms_valid;
        CData/*0:0*/ Top__DOT__core__DOT____Vtogcov__ms_top_io_ws_valid;
        CData/*0:0*/ Top__DOT__core__DOT__pre_top__DOT____Vtogcov__buf_valid;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top__DOT____Vtogcov__fs_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__fs_top__DOT____Vtogcov__fs_valid;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_io_wr_stall;
        CData/*3:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__idu_io_ctrl_br_type;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__ds_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__ds_valid;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__right_right;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__right_left;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__left_right_1;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_eq;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_lt;
        CData/*0:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_ltu;
        CData/*1:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__flush_reg;
        CData/*5:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__alu_io_opcode;
        CData/*1:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__from_ds_r_decode_op1_sel;
    };
    struct {
        CData/*1:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__from_ds_r_decode_op2_sel;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__from_ds_r_decode_mem_en;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__es_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__es_valid;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__dmem_req_r;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__sltu_result;
        CData/*0:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__slt_result;
        CData/*1:0*/ Top__DOT__core__DOT__ms_top__DOT____Vtogcov__from_es_r_decode_wb_sel;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT____Vtogcov__from_es_r_decode_mem_wr;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT____Vtogcov__ms_valid;
        CData/*3:0*/ Top__DOT__core__DOT__ms_top__DOT____Vtogcov__unfinished_store;
        CData/*0:0*/ Top__DOT__core__DOT__ms_top__DOT____Vtogcov__ms_ready_go;
        CData/*0:0*/ Top__DOT__core__DOT__ws_top__DOT____Vtogcov__REG;
        CData/*0:0*/ __Vdly__Top__DOT__core__DOT__pre_top__DOT__buf_valid;
        CData/*1:0*/ __Vdly__Top__DOT__core__DOT__ds_top__DOT__flush_reg;
        CData/*0:0*/ __Vdly__Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr;
        CData/*3:0*/ __Vdly__Top__DOT__core__DOT__ms_top__DOT__unfinished_store;
        CData/*0:0*/ __Vdly__Top__DOT__core__DOT__ws_top__DOT__is_commit;
        CData/*0:0*/ __Vclklast__TOP__clock;
        SData/*11:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__imm_b;
        SData/*11:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__imm_s;
        IData/*31:0*/ Top__DOT____Vtogcov__io_imem_req_bits_data;
        IData/*31:0*/ Top__DOT____Vtogcov__io_imem_resp_bits_data;
        IData/*31:0*/ Top__DOT____Vtogcov__core_io_imem_resp_bits_data;
        IData/*31:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_inst;
        IData/*19:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__imm_j;
        WData/*65:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__imm_b_sext[3];
        WData/*73:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__imm_j_sext[3];
        WData/*65:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__branch_target[3];
        WData/*73:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__jmp_target[3];
        IData/*31:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__from_ds_r_inst;
        IData/*31:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__imm_z;
        IData/*31:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__right_right_3;
        WData/*64:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__add_result[3];
        QData/*63:0*/ Top__DOT____Vtogcov__io_imem_req_bits_addr;
        QData/*63:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_addr;
        QData/*63:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_data;
        QData/*63:0*/ Top__DOT____Vtogcov__io_dmem_resp_bits_data;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_0;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_1;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_2;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_3;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_4;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_5;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_6;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_7;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_8;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_9;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_10;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_11;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_12;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_13;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_14;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_15;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_16;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_17;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_18;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_19;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_20;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_21;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_22;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_23;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_24;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_25;
    };
    struct {
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_26;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_27;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_28;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_29;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_30;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_rf_31;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_PC;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_imem_req_bits_addr;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_dmem_req_bits_addr;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_dmem_req_bits_data;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_0;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_1;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_2;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_3;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_4;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_5;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_6;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_7;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_8;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_9;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_10;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_11;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_12;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_13;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_14;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_15;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_16;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_17;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_18;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_19;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_20;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_21;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_22;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_23;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_24;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_25;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_26;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_27;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_28;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_29;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_30;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_rf_31;
        QData/*63:0*/ Top__DOT____Vtogcov__core_io_debug_PC;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__pre_top_io_fs_bits_PC;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__pre_top_br_target_0;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_PC;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_PC;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_io_wb_wr_data;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ds_top_es_res_wr_data;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__es_top_io_ms_bits_PC;
        QData/*63:0*/ Top__DOT__core__DOT____Vtogcov__ms_top_io_ws_bits_PC;
        QData/*63:0*/ Top__DOT__core__DOT__pre_top__DOT____Vtogcov__buf_npc;
        QData/*63:0*/ Top__DOT__core__DOT__pre_top__DOT____Vtogcov__seq_pc;
        QData/*51:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__right_2;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__imm_i_sext;
        QData/*52:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__right_right_2;
        QData/*52:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__right_right_3;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT____Vtogcov__rf_io_rs1_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT____Vtogcov__rf_io_rs2_data;
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data;
    };
    struct {
        QData/*63:0*/ Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__alu_io_in1;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__alu_io_in2;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__from_ds_r_rs1_data;
        QData/*51:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__right_4;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__imm_i_sext;
        QData/*51:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__right_5;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__imm_s_sext;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT____Vtogcov__imm_u_sext;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__xor_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__or_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__and_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__sll_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__sra_result;
        QData/*63:0*/ Top__DOT__core__DOT__es_top__DOT__alu__DOT____Vtogcov__srl_result;
        CData/*0:0*/ __Vm_traceActivity[2];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VTop__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VTop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VTop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VTop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VTop__Syms* __restrict vlSymsp);
    void _traceDump();void _traceDumpOpen();void _traceDumpClose();public:
    void __Vconfigure(VTop__Syms* symsp, bool first);
  private:
    static QData _change_request(VTop__Syms* __restrict vlSymsp);
    static QData _change_request_1(VTop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(VTop__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _configure_coverage_1(VTop__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VTop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__10(VTop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(VTop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(VTop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(VTop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(VTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__3(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__4(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__5(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__6(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
