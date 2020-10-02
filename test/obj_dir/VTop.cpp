// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop.h"
#include "VTop__Syms.h"

//==========

void VTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTop::eval\n"); );
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Top.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VTop::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step VTop::eval_end_step\n"); );
#ifdef VM_TRACE
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) _traceDump();
#endif  // VM_TRACE
}

void VTop::_eval_initial_loop(VTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Top.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VTop::_combo__TOP__3(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_combo__TOP__3\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) ^ vlTOPp->Top__DOT____Vtogcov__clock)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->Top__DOT____Vtogcov__clock = vlTOPp->clock;
    }
    if (((IData)(vlTOPp->reset) ^ vlTOPp->Top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->Top__DOT____Vtogcov__reset = vlTOPp->reset;
    }
    if (((IData)(vlTOPp->io_wen) ^ vlTOPp->Top__DOT____Vtogcov__io_wen)) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->Top__DOT____Vtogcov__io_wen = vlTOPp->io_wen;
    }
    if ((1U & ((IData)(vlTOPp->io_rs1_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_addr = 
            ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_addr)) 
             | (1U & (IData)(vlTOPp->io_rs1_addr)));
    }
    if ((2U & ((IData)(vlTOPp->io_rs1_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_addr = 
            ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_addr)) 
             | (2U & (IData)(vlTOPp->io_rs1_addr)));
    }
    if ((4U & ((IData)(vlTOPp->io_rs1_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_addr = 
            ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_addr)) 
             | (4U & (IData)(vlTOPp->io_rs1_addr)));
    }
    if ((8U & ((IData)(vlTOPp->io_rs1_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_addr = 
            ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_addr)) 
             | (8U & (IData)(vlTOPp->io_rs1_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_rs1_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_addr = 
            ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_addr)) 
             | (0x10U & (IData)(vlTOPp->io_rs1_addr)));
    }
    if ((1U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (1U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((2U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (2U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((4U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (4U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((8U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (8U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (0x10U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((1U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1eU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((2U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1dU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((4U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1bU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((8U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x17U 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0xfU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((1U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffeU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (1U 
                                                    & vlTOPp->io_wdata));
    }
    if ((2U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffdU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (2U 
                                                    & vlTOPp->io_wdata));
    }
    if ((4U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffbU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (4U 
                                                    & vlTOPp->io_wdata));
    }
    if ((8U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffff7U 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (8U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x10U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffefU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x10U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x20U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffdfU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x20U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x40U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffbfU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x40U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x80U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffff7fU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x80U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x100U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffeffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x100U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x200U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffdffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x200U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x400U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffbffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x400U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x800U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffff7ffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x800U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x1000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffefffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x1000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x2000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffdfffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x2000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x4000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffbfffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x4000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x8000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffff7fffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x8000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x10000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffeffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x10000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x20000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffdffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x20000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x40000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffbffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x40000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x80000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfff7ffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x80000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x100000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffefffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x100000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x200000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffdfffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x200000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x400000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffbfffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x400000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x800000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xff7fffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x800000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x1000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfeffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x1000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x2000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfdffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x2000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x4000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfbffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x4000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x8000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xf7ffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x8000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x10000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xefffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x10000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x20000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xdfffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x20000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x40000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xbfffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x40000000U 
                                                    & vlTOPp->io_wdata));
    }
    if ((0x80000000U & (vlTOPp->io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_wdata))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0x7fffffffU 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (0x80000000U 
                                                    & vlTOPp->io_wdata));
    }
}

VL_INLINE_OPT void VTop::_sequent__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_sequent__TOP__4\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__rf__v0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__rf__v0;
    // Body
    __Vdlyvset__Top__DOT__rf__v0 = 0U;
    ++(vlSymsp->__Vcoverage[181]);
    if (vlTOPp->io_wen) {
        ++(vlSymsp->__Vcoverage[179]);
        __Vdlyvval__Top__DOT__rf__v0 = vlTOPp->io_wdata;
        __Vdlyvset__Top__DOT__rf__v0 = 1U;
        __Vdlyvdim0__Top__DOT__rf__v0 = vlTOPp->io_waddr;
    } else {
        ++(vlSymsp->__Vcoverage[180]);
    }
    if (__Vdlyvset__Top__DOT__rf__v0) {
        vlTOPp->Top__DOT__rf[__Vdlyvdim0__Top__DOT__rf__v0] 
            = __Vdlyvval__Top__DOT__rf__v0;
    }
}

VL_INLINE_OPT void VTop::_combo__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_combo__TOP__5\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__rf___05FT_24_data = vlTOPp->Top__DOT__rf
        [vlTOPp->io_rs1_addr];
    vlTOPp->Top__DOT__rf___05FT_29_data = vlTOPp->Top__DOT__rf
        [vlTOPp->io_rs2_addr];
    if ((1U & (vlTOPp->Top__DOT__rf___05FT_24_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (1U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf___05FT_24_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (2U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf___05FT_24_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (4U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf___05FT_24_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (8U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x10U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x20U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x40U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x80U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x100U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x200U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x400U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x800U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf___05FT_24_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_24_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf___05FT_24_data));
    }
    vlTOPp->io_rs1_data = ((0U != (IData)(vlTOPp->io_rs1_addr))
                            ? vlTOPp->Top__DOT__rf___05FT_24_data
                            : 0U);
    if ((1U & (vlTOPp->Top__DOT__rf___05FT_29_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (1U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf___05FT_29_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (2U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf___05FT_29_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (4U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf___05FT_29_data 
               ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (8U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x10U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x20U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x40U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x80U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x100U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x200U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x400U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x800U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf___05FT_29_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__rf___05FT_29_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf___05FT_29_data));
    }
    vlTOPp->io_rs2_data = ((0U != (IData)(vlTOPp->io_rs2_addr))
                            ? vlTOPp->Top__DOT__rf___05FT_29_data
                            : 0U);
    if ((1U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (1U & vlTOPp->io_rs1_data));
    }
    if ((2U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (2U & vlTOPp->io_rs1_data));
    }
    if ((4U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (4U & vlTOPp->io_rs1_data));
    }
    if ((8U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (8U & vlTOPp->io_rs1_data));
    }
    if ((0x10U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x10U & vlTOPp->io_rs1_data));
    }
    if ((0x20U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x20U & vlTOPp->io_rs1_data));
    }
    if ((0x40U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x40U & vlTOPp->io_rs1_data));
    }
    if ((0x80U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x80U & vlTOPp->io_rs1_data));
    }
    if ((0x100U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x100U & vlTOPp->io_rs1_data));
    }
    if ((0x200U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x200U & vlTOPp->io_rs1_data));
    }
    if ((0x400U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x400U & vlTOPp->io_rs1_data));
    }
    if ((0x800U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x800U & vlTOPp->io_rs1_data));
    }
    if ((0x1000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x1000U & vlTOPp->io_rs1_data));
    }
    if ((0x2000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x2000U & vlTOPp->io_rs1_data));
    }
    if ((0x4000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x4000U & vlTOPp->io_rs1_data));
    }
    if ((0x8000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x8000U & vlTOPp->io_rs1_data));
    }
    if ((0x10000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x10000U & vlTOPp->io_rs1_data));
    }
    if ((0x20000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x20000U & vlTOPp->io_rs1_data));
    }
    if ((0x40000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x40000U & vlTOPp->io_rs1_data));
    }
    if ((0x80000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x80000U & vlTOPp->io_rs1_data));
    }
    if ((0x100000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x100000U & vlTOPp->io_rs1_data));
    }
    if ((0x200000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x200000U & vlTOPp->io_rs1_data));
    }
    if ((0x400000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x400000U & vlTOPp->io_rs1_data));
    }
    if ((0x800000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x800000U & vlTOPp->io_rs1_data));
    }
    if ((0x1000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x1000000U & vlTOPp->io_rs1_data));
    }
    if ((0x2000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x2000000U & vlTOPp->io_rs1_data));
    }
    if ((0x4000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x4000000U & vlTOPp->io_rs1_data));
    }
    if ((0x8000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x8000000U & vlTOPp->io_rs1_data));
    }
    if ((0x10000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x10000000U & vlTOPp->io_rs1_data));
    }
    if ((0x20000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x20000000U & vlTOPp->io_rs1_data));
    }
    if ((0x40000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x40000000U & vlTOPp->io_rs1_data));
    }
    if ((0x80000000U & (vlTOPp->io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (0x80000000U & vlTOPp->io_rs1_data));
    }
    if ((1U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (1U & vlTOPp->io_rs2_data));
    }
    if ((2U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (2U & vlTOPp->io_rs2_data));
    }
    if ((4U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (4U & vlTOPp->io_rs2_data));
    }
    if ((8U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (8U & vlTOPp->io_rs2_data));
    }
    if ((0x10U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x10U & vlTOPp->io_rs2_data));
    }
    if ((0x20U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x20U & vlTOPp->io_rs2_data));
    }
    if ((0x40U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x40U & vlTOPp->io_rs2_data));
    }
    if ((0x80U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x80U & vlTOPp->io_rs2_data));
    }
    if ((0x100U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x100U & vlTOPp->io_rs2_data));
    }
    if ((0x200U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x200U & vlTOPp->io_rs2_data));
    }
    if ((0x400U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x400U & vlTOPp->io_rs2_data));
    }
    if ((0x800U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x800U & vlTOPp->io_rs2_data));
    }
    if ((0x1000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x1000U & vlTOPp->io_rs2_data));
    }
    if ((0x2000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x2000U & vlTOPp->io_rs2_data));
    }
    if ((0x4000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x4000U & vlTOPp->io_rs2_data));
    }
    if ((0x8000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x8000U & vlTOPp->io_rs2_data));
    }
    if ((0x10000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x10000U & vlTOPp->io_rs2_data));
    }
    if ((0x20000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x20000U & vlTOPp->io_rs2_data));
    }
    if ((0x40000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x40000U & vlTOPp->io_rs2_data));
    }
    if ((0x80000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x80000U & vlTOPp->io_rs2_data));
    }
    if ((0x100000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x100000U & vlTOPp->io_rs2_data));
    }
    if ((0x200000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x200000U & vlTOPp->io_rs2_data));
    }
    if ((0x400000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x400000U & vlTOPp->io_rs2_data));
    }
    if ((0x800000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x800000U & vlTOPp->io_rs2_data));
    }
    if ((0x1000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x1000000U & vlTOPp->io_rs2_data));
    }
    if ((0x2000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x2000000U & vlTOPp->io_rs2_data));
    }
    if ((0x4000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x4000000U & vlTOPp->io_rs2_data));
    }
    if ((0x8000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x8000000U & vlTOPp->io_rs2_data));
    }
    if ((0x10000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x10000000U & vlTOPp->io_rs2_data));
    }
    if ((0x20000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x20000000U & vlTOPp->io_rs2_data));
    }
    if ((0x40000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x40000000U & vlTOPp->io_rs2_data));
    }
    if ((0x80000000U & (vlTOPp->io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (0x80000000U & vlTOPp->io_rs2_data));
    }
}

void VTop::_eval(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_eval\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VTop::_change_request(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_change_request\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VTop::_change_request_1(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_change_request_1\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VTop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_rs1_addr & 0xe0U))) {
        Verilated::overWidthError("io_rs1_addr");}
    if (VL_UNLIKELY((io_rs2_addr & 0xe0U))) {
        Verilated::overWidthError("io_rs2_addr");}
    if (VL_UNLIKELY((io_waddr & 0xe0U))) {
        Verilated::overWidthError("io_waddr");}
    if (VL_UNLIKELY((io_wen & 0xfeU))) {
        Verilated::overWidthError("io_wen");}
}
#endif  // VL_DEBUG
