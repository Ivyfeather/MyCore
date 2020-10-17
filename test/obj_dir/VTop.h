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
    VL_OUT8(io_imem_req_bits_fcn,0,0);
    VL_OUT8(io_imem_req_bits_msk,2,0);
    VL_OUT8(io_imem_resp_ready,0,0);
    VL_IN8(io_imem_resp_valid,0,0);
    VL_IN8(io_dmem_req_ready,0,0);
    VL_OUT8(io_dmem_req_valid,0,0);
    VL_OUT8(io_dmem_req_bits_fcn,0,0);
    VL_OUT8(io_dmem_req_bits_msk,2,0);
    VL_OUT8(io_dmem_resp_ready,0,0);
    VL_IN8(io_dmem_resp_valid,0,0);
    VL_OUT8(io_debug_io_wen,0,0);
    VL_OUT8(io_debug_io_waddr,4,0);
    VL_OUT8(io_debug_io_stall,0,0);
    VL_OUT(io_imem_req_bits_addr,31,0);
    VL_OUT(io_imem_req_bits_data,31,0);
    VL_IN(io_imem_resp_bits_data,31,0);
    VL_OUT(io_dmem_req_bits_addr,31,0);
    VL_OUT64(io_dmem_req_bits_data,63,0);
    VL_IN64(io_dmem_resp_bits_data,63,0);
    VL_OUT64(io_debug_io_wdata,63,0);
    VL_OUT64(io_debug_io_PC,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ Top__DOT__idu_io_br_type;
    CData/*1:0*/ Top__DOT__idu_io_op1_sel;
    CData/*1:0*/ Top__DOT__idu_io_op2_sel;
    CData/*1:0*/ Top__DOT__idu_io_wb_sel;
    CData/*0:0*/ Top__DOT__idu_io_rf_wen;
    CData/*0:0*/ Top__DOT__idu_io_mem_en;
    CData/*0:0*/ Top__DOT__idu_io_mem_fcn;
    CData/*2:0*/ Top__DOT__idu_io_mem_msk;
    CData/*0:0*/ Top__DOT___T_112;
    CData/*0:0*/ Top__DOT__stall;
    CData/*0:0*/ Top__DOT__br_taken;
    CData/*0:0*/ Top__DOT__alu__DOT__slt_result;
    CData/*3:0*/ Top__DOT__idu__DOT___T_357;
    CData/*3:0*/ Top__DOT__idu__DOT___T_372;
    CData/*1:0*/ Top__DOT__idu__DOT___T_402;
    CData/*1:0*/ Top__DOT__idu__DOT___T_417;
    CData/*1:0*/ Top__DOT__idu__DOT___T_459;
    CData/*4:0*/ Top__DOT__idu__DOT___T_495;
    CData/*4:0*/ Top__DOT__idu__DOT___T_510;
    CData/*4:0*/ Top__DOT__idu__DOT__csignals_4;
    CData/*1:0*/ Top__DOT__idu__DOT___T_543;
    CData/*1:0*/ Top__DOT__idu__DOT___T_558;
    CData/*0:0*/ Top__DOT__idu__DOT___T_594;
    CData/*0:0*/ Top__DOT__idu__DOT___T_611;
    CData/*0:0*/ Top__DOT__idu__DOT___T_636;
    CData/*0:0*/ Top__DOT__idu__DOT___T_653;
    SData/*11:0*/ Top__DOT__imm_s;
    SData/*11:0*/ Top__DOT__imm_b;
    IData/*31:0*/ Top__DOT__idu_io_inst;
    IData/*19:0*/ Top__DOT__imm_j;
    IData/*31:0*/ Top__DOT__imm_i_sext;
    IData/*31:0*/ Top__DOT__imm_s_sext;
    IData/*30:0*/ Top__DOT___T_151;
    IData/*30:0*/ Top__DOT___T_163;
    WData/*64:0*/ Top__DOT___T_188[3];
    WData/*64:0*/ Top__DOT___T_189[3];
    WData/*64:0*/ Top__DOT___T_190[3];
    WData/*64:0*/ Top__DOT__alu__DOT__add_result[3];
    WData/*94:0*/ Top__DOT__alu__DOT___T_23[3];
    QData/*63:0*/ Top__DOT__alu_io_in1;
    QData/*63:0*/ Top__DOT__alu_io_in2;
    QData/*63:0*/ Top__DOT__alu_io_out;
    QData/*63:0*/ Top__DOT__rf_io_rs1_data;
    QData/*63:0*/ Top__DOT__rf_io_rs2_data;
    QData/*63:0*/ Top__DOT__rf_io_wdata;
    QData/*63:0*/ Top__DOT__pc_reg;
    QData/*63:0*/ Top__DOT___T_231;
    QData/*63:0*/ Top__DOT__alu__DOT__xor_result;
    QData/*63:0*/ Top__DOT__alu__DOT__or_result;
    QData/*63:0*/ Top__DOT__alu__DOT__and_result;
    QData/*63:0*/ Top__DOT__alu__DOT___T_25;
    QData/*63:0*/ Top__DOT__alu__DOT__srl_result;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile___05FT_24_data;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile___05FT_29_data;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ Top__DOT____Vtogcov__clock;
        CData/*0:0*/ Top__DOT____Vtogcov__reset;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_req_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_imem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_ready;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_fcn;
        CData/*2:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_msk;
        CData/*0:0*/ Top__DOT____Vtogcov__io_dmem_resp_valid;
        CData/*0:0*/ Top__DOT____Vtogcov__io_debug_io_wen;
        CData/*4:0*/ Top__DOT____Vtogcov__io_debug_io_waddr;
        CData/*0:0*/ Top__DOT____Vtogcov__io_debug_io_stall;
        CData/*5:0*/ Top__DOT____Vtogcov__alu_io_opcode;
        CData/*0:0*/ Top__DOT____Vtogcov__alu_io_zero;
        CData/*3:0*/ Top__DOT____Vtogcov__idu_io_br_type;
        CData/*1:0*/ Top__DOT____Vtogcov__idu_io_op1_sel;
        CData/*1:0*/ Top__DOT____Vtogcov__idu_io_op2_sel;
        CData/*1:0*/ Top__DOT____Vtogcov__idu_io_wb_sel;
        CData/*0:0*/ Top__DOT____Vtogcov__idu_io_rf_wen;
        CData/*0:0*/ Top__DOT____Vtogcov__idu_io_mem_en;
        CData/*0:0*/ Top__DOT____Vtogcov__idu_io_mem_fcn;
        CData/*2:0*/ Top__DOT____Vtogcov__idu_io_mem_msk;
        CData/*0:0*/ Top__DOT____Vtogcov__stall;
        CData/*0:0*/ Top__DOT____Vtogcov__br_taken;
        CData/*0:0*/ Top__DOT__alu__DOT____Vtogcov__sltu_result;
        CData/*0:0*/ Top__DOT__alu__DOT____Vtogcov__slt_result;
        CData/*4:0*/ Top__DOT__idu__DOT____Vtogcov__csignals_4;
        CData/*0:0*/ __Vclklast__TOP__clock;
        SData/*11:0*/ Top__DOT____Vtogcov__imm_s;
        SData/*11:0*/ Top__DOT____Vtogcov__imm_b;
        IData/*31:0*/ Top__DOT____Vtogcov__io_imem_req_bits_addr;
        IData/*31:0*/ Top__DOT____Vtogcov__io_imem_req_bits_data;
        IData/*31:0*/ Top__DOT____Vtogcov__io_imem_resp_bits_data;
        IData/*31:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_addr;
        IData/*31:0*/ Top__DOT____Vtogcov__idu_io_inst;
        IData/*19:0*/ Top__DOT____Vtogcov__imm_j;
        IData/*31:0*/ Top__DOT____Vtogcov__imm_z;
        IData/*31:0*/ Top__DOT____Vtogcov__imm_i_sext;
        IData/*31:0*/ Top__DOT____Vtogcov__imm_s_sext;
        IData/*31:0*/ Top__DOT____Vtogcov__imm_b_sext;
        IData/*31:0*/ Top__DOT____Vtogcov__imm_j_sext;
        IData/*31:0*/ Top__DOT____Vtogcov__pc_4;
        IData/*31:0*/ Top__DOT____Vtogcov__pc_next;
        WData/*64:0*/ Top__DOT__alu__DOT____Vtogcov__add_result[3];
        QData/*63:0*/ Top__DOT____Vtogcov__io_dmem_req_bits_data;
        QData/*63:0*/ Top__DOT____Vtogcov__io_dmem_resp_bits_data;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_io_wdata;
        QData/*63:0*/ Top__DOT____Vtogcov__io_debug_io_PC;
        QData/*63:0*/ Top__DOT____Vtogcov__alu_io_in1;
        QData/*63:0*/ Top__DOT____Vtogcov__alu_io_in2;
        QData/*63:0*/ Top__DOT____Vtogcov__alu_io_out;
        QData/*63:0*/ Top__DOT____Vtogcov__rf_io_rs1_data;
        QData/*63:0*/ Top__DOT____Vtogcov__rf_io_rs2_data;
        QData/*63:0*/ Top__DOT____Vtogcov__rf_io_wdata;
        QData/*63:0*/ Top__DOT____Vtogcov__pc_reg;
        QData/*63:0*/ Top__DOT____Vtogcov__br_target;
        QData/*63:0*/ Top__DOT____Vtogcov__jmp_target;
        QData/*63:0*/ Top__DOT____Vtogcov__jr_target;
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__xor_result;
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__or_result;
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__and_result;
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__sll_result;
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__sra_result;
    };
    struct {
        QData/*63:0*/ Top__DOT__alu__DOT____Vtogcov__srl_result;
        QData/*63:0*/ Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data;
        QData/*63:0*/ Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data;
        CData/*0:0*/ __Vm_traceActivity[3];
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
    static void _combo__TOP__4(VTop__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(VTop__Syms* __restrict vlSymsp);
  private:
    void _configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) VL_ATTR_COLD;
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
    static void _sequent__TOP__5(VTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__3(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
