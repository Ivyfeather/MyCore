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
    VL_IN8(io_opcode,5,0);
    VL_IN64(io_in1,63,0);
    VL_IN64(io_in2,63,0);
    VL_OUT64(io_out,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ Top__DOT__slt_result;
    WData/*64:0*/ Top__DOT__add_result[3];
    QData/*63:0*/ Top__DOT__xor_result;
    QData/*63:0*/ Top__DOT__or_result;
    QData/*63:0*/ Top__DOT__and_result;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ Top__DOT____Vtogcov__clock;
    CData/*0:0*/ Top__DOT____Vtogcov__reset;
    CData/*5:0*/ Top__DOT____Vtogcov__io_opcode;
    CData/*0:0*/ Top__DOT____Vtogcov__sltu_result;
    CData/*0:0*/ Top__DOT____Vtogcov__slt_result;
    CData/*0:0*/ __Vclklast__TOP__clock;
    WData/*64:0*/ Top__DOT____Vtogcov__add_result[3];
    IData/*31:0*/ __Vm_traceActivity;
    QData/*63:0*/ Top__DOT____Vtogcov__io_in1;
    QData/*63:0*/ Top__DOT____Vtogcov__io_in2;
    QData/*63:0*/ Top__DOT____Vtogcov__io_out;
    QData/*63:0*/ Top__DOT____Vtogcov__xor_result;
    QData/*63:0*/ Top__DOT____Vtogcov__or_result;
    QData/*63:0*/ Top__DOT____Vtogcov__and_result;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VTop__Syms* __VlSymsp;  // Symbol table
  private:
    // Coverage
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
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
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VTop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VTop__Syms* symsp, bool first);
  private:
    static QData _change_request(VTop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VTop__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(VTop__Syms* __restrict vlSymsp);
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
    static void _sequent__TOP__3(VTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
