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
    VL_IN8(io_rs1_addr,4,0);
    VL_IN8(io_rs2_addr,4,0);
    VL_IN8(io_waddr,4,0);
    VL_IN8(io_wen,0,0);
    VL_OUT64(io_rs1_data,63,0);
    VL_OUT64(io_rs2_data,63,0);
    VL_IN64(io_wdata,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ Top__DOT__rs1_addr;
    CData/*4:0*/ Top__DOT__rs2_addr;
    CData/*4:0*/ Top__DOT__waddr;
    CData/*0:0*/ Top__DOT__wen;
    QData/*63:0*/ Top__DOT__rf_io_rs1_data;
    QData/*63:0*/ Top__DOT__rf_io_rs2_data;
    QData/*63:0*/ Top__DOT__wdata;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data;
    QData/*63:0*/ Top__DOT__rf__DOT__regfile[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ Top__DOT____Vtogcov__clock;
    CData/*0:0*/ Top__DOT____Vtogcov__reset;
    CData/*4:0*/ Top__DOT____Vtogcov__io_rs1_addr;
    CData/*4:0*/ Top__DOT____Vtogcov__io_rs2_addr;
    CData/*4:0*/ Top__DOT____Vtogcov__io_waddr;
    CData/*0:0*/ Top__DOT____Vtogcov__io_wen;
    CData/*4:0*/ Top__DOT____Vtogcov__rf_io_rs1_addr;
    CData/*4:0*/ Top__DOT____Vtogcov__rf_io_rs2_addr;
    CData/*4:0*/ Top__DOT____Vtogcov__rf_io_waddr;
    CData/*0:0*/ Top__DOT____Vtogcov__rf_io_wen;
    CData/*0:0*/ Top__DOT__rf__DOT____Vtogcov__regfile_MPORT_mask;
    CData/*0:0*/ __Vclklast__TOP__clock;
    QData/*63:0*/ Top__DOT____Vtogcov__io_rs1_data;
    QData/*63:0*/ Top__DOT____Vtogcov__io_rs2_data;
    QData/*63:0*/ Top__DOT____Vtogcov__io_wdata;
    QData/*63:0*/ Top__DOT____Vtogcov__rf_io_rs1_data;
    QData/*63:0*/ Top__DOT____Vtogcov__rf_io_rs2_data;
    QData/*63:0*/ Top__DOT____Vtogcov__rf_io_wdata;
    QData/*63:0*/ Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data;
    QData/*63:0*/ Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data;
    CData/*0:0*/ __Vm_traceActivity[2];
    
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
    static void _combo__TOP__3(VTop__Syms* __restrict vlSymsp);
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
    static void _sequent__TOP__4(VTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
