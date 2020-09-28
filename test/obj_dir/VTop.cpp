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
            VL_FATAL_MT("Top.v", 1, "",
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
            VL_FATAL_MT("Top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VTop::_combo__TOP__2(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_combo__TOP__2\n"); );
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
    if ((1U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3eU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((2U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3dU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (2U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((4U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3bU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (4U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((8U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x37U 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (8U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x2fU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (0x10U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((0x20U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x1fU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (0x20U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((1U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (1U 
                                                  & vlTOPp->io_in1));
    }
    if ((2U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (2U 
                                                  & vlTOPp->io_in1));
    }
    if ((4U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (4U 
                                                  & vlTOPp->io_in1));
    }
    if ((8U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (8U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x100U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x100U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x200U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x200U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x400U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x400U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x800U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x800U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x1000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x1000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x2000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x2000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x4000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x4000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x8000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x8000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x100000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x100000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x200000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x200000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x400000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x400000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x800000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x800000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x1000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x2000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x4000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x8000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((1U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (1U 
                                                  & vlTOPp->io_in2));
    }
    if ((2U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (2U 
                                                  & vlTOPp->io_in2));
    }
    if ((4U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (4U 
                                                  & vlTOPp->io_in2));
    }
    if ((8U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (8U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x100U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x100U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x200U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x200U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x400U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x400U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x800U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x800U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x1000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x1000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x2000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x2000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x4000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x4000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x8000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x8000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x100000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x100000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x200000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x200000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x400000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x400000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x800000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x800000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x1000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x2000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x4000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x8000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_in2));
    }
    vlTOPp->Top__DOT__or_result = (vlTOPp->io_in1 | vlTOPp->io_in2);
    vlTOPp->Top__DOT__and_result = (vlTOPp->io_in1 
                                    & vlTOPp->io_in2);
    vlTOPp->Top__DOT__xor_result = (vlTOPp->io_in1 
                                    ^ vlTOPp->io_in2);
    vlTOPp->Top__DOT__add_result = (0x1ffffffffULL 
                                    & ((QData)((IData)(vlTOPp->io_in1)) 
                                       + (QData)((IData)(
                                                         ((0x10U 
                                                           & (IData)(vlTOPp->io_opcode))
                                                           ? 
                                                          ((IData)(1U) 
                                                           + 
                                                           (~ vlTOPp->io_in2))
                                                           : vlTOPp->io_in2)))));
    if ((1U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffeU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (1U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((2U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffdU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (2U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((4U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffbU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (4U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((8U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffff7U 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (8U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffefU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffdfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffbfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffff7fU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffeffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x100U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffdffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x200U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffbffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x400U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffff7ffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x800U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffefffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x1000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffdfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x2000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffbfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x4000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffff7fffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x8000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffeffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffdffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffbffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfff7ffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffefffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x100000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffdfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x200000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffbfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x400000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xff7fffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x800000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfeffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x1000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfdffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x2000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfbffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x4000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xf7ffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x8000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xefffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xdfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xbfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0x7fffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((1U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((2U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((4U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((8U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((1U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((2U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((4U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((8U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((1U & ((~ (IData)((vlTOPp->Top__DOT__add_result 
                           >> 0x20U))) ^ vlTOPp->Top__DOT____Vtogcov__sltu_result))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->Top__DOT____Vtogcov__sltu_result = 
            (1U & (~ (IData)((vlTOPp->Top__DOT__add_result 
                              >> 0x20U))));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__add_result) 
               ^ (IData)(vlTOPp->Top__DOT____Vtogcov__add_result)))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffeULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | (IData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlTOPp->Top__DOT__add_result)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffdULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 1U))))) 
                                                      << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffbULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 2U))))) 
                                                      << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffff7ULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 3U))))) 
                                                      << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffefULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 4U))))) 
                                                      << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffdfULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 5U))))) 
                                                      << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffbfULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 6U))))) 
                                                      << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffff7fULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 7U))))) 
                                                      << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffeffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 8U))))) 
                                                      << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffdffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 9U))))) 
                                                      << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffbffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xaU))))) 
                                                      << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffff7ffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xbU))))) 
                                                      << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffefffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xcU))))) 
                                                      << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffdfffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xdU))))) 
                                                      << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffbfffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xeU))))) 
                                                      << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffff7fffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xfU))))) 
                                                      << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffeffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x10U))))) 
                                                      << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffdffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x11U))))) 
                                                      << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffbffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x12U))))) 
                                                      << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fff7ffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x13U))))) 
                                                      << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffefffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x14U))))) 
                                                      << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffdfffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x15U))))) 
                                                      << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffbfffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x16U))))) 
                                                      << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ff7fffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x17U))))) 
                                                      << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1feffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x18U))))) 
                                                      << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fdffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x19U))))) 
                                                      << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fbffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1aU))))) 
                                                      << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1f7ffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1bU))))) 
                                                      << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1efffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1cU))))) 
                                                      << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1dfffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1dU))))) 
                                                      << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1bfffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1eU))))) 
                                                      << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x17fffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1fU))))) 
                                                      << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0xffffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x20U))))) 
                                                      << 0x20U));
    }
    vlTOPp->Top__DOT__slt_result = (1U & ((vlTOPp->Top__DOT__xor_result 
                                           >> 0x1fU) 
                                          ^ (~ (IData)(
                                                       (vlTOPp->Top__DOT__add_result 
                                                        >> 0x20U)))));
    if (((IData)(vlTOPp->Top__DOT__slt_result) ^ vlTOPp->Top__DOT____Vtogcov__slt_result)) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->Top__DOT____Vtogcov__slt_result = vlTOPp->Top__DOT__slt_result;
    }
}

VL_INLINE_OPT void VTop::_sequent__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_sequent__TOP__4\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    ++(vlSymsp->__Vcoverage[237]);
    if (VL_LIKELY(vlTOPp->reset)) {
        ++(vlSymsp->__Vcoverage[236]);
    } else {
        ++(vlSymsp->__Vcoverage[235]);
        VL_FWRITEF(0x80000002U,"in1:%10# in2:%10# opcode:%x out:%10#\n",
                   32,vlTOPp->io_in1,32,vlTOPp->io_in2,
                   6,(IData)(vlTOPp->io_opcode),32,
                   vlTOPp->io_out);
    }
}

VL_INLINE_OPT void VTop::_combo__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_combo__TOP__5\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out = ((0x12U == (0x1fU & (IData)(vlTOPp->io_opcode)))
                       ? (1U & (~ (IData)((vlTOPp->Top__DOT__add_result 
                                           >> 0x20U))))
                       : ((0x11U == (0x1fU & (IData)(vlTOPp->io_opcode)))
                           ? (IData)(vlTOPp->Top__DOT__slt_result)
                           : ((1U == (1U & (IData)(vlTOPp->io_opcode)))
                               ? vlTOPp->Top__DOT__xor_result
                               : ((2U == (3U & (IData)(vlTOPp->io_opcode)))
                                   ? vlTOPp->Top__DOT__or_result
                                   : ((3U == (3U & (IData)(vlTOPp->io_opcode)))
                                       ? vlTOPp->Top__DOT__and_result
                                       : ((8U == (0xfU 
                                                  & (IData)(vlTOPp->io_opcode)))
                                           ? vlTOPp->io_in1
                                           : (IData)(vlTOPp->Top__DOT__add_result)))))));
    if ((1U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (1U 
                                                  & vlTOPp->io_out));
    }
    if ((2U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (2U 
                                                  & vlTOPp->io_out));
    }
    if ((4U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (4U 
                                                  & vlTOPp->io_out));
    }
    if ((8U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (8U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80U 
                                                  & vlTOPp->io_out));
    }
    if ((0x100U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x100U 
                                                  & vlTOPp->io_out));
    }
    if ((0x200U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x200U 
                                                  & vlTOPp->io_out));
    }
    if ((0x400U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x400U 
                                                  & vlTOPp->io_out));
    }
    if ((0x800U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x800U 
                                                  & vlTOPp->io_out));
    }
    if ((0x1000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x1000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x2000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x2000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x4000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x4000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x8000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x8000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x100000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x100000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x200000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x200000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x400000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x400000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x800000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x800000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x1000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x2000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x4000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x8000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_out));
    }
}

void VTop::_eval(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_eval\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
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
    if (VL_UNLIKELY((io_opcode & 0xc0U))) {
        Verilated::overWidthError("io_opcode");}
}
#endif  // VL_DEBUG
