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
            VL_FATAL_MT("../Top.v", 86, "",
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
            VL_FATAL_MT("../Top.v", 86, "",
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
        ++(vlSymsp->__Vcoverage[209]);
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
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (1U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((2U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (2U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((4U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (4U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((8U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (8U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_rs2_addr) ^ vlTOPp->Top__DOT____Vtogcov__io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_addr = 
            ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_addr)) 
             | (0x10U & (IData)(vlTOPp->io_rs2_addr)));
    }
    if ((1U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1eU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (1U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((2U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1dU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (2U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((4U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x1bU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (4U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((8U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0x17U 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (8U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_waddr))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->Top__DOT____Vtogcov__io_waddr = ((0xfU 
                                                  & (IData)(vlTOPp->Top__DOT____Vtogcov__io_waddr)) 
                                                 | (0x10U 
                                                    & (IData)(vlTOPp->io_waddr)));
    }
    if ((1U & ((IData)(vlTOPp->io_wdata) ^ (IData)(vlTOPp->Top__DOT____Vtogcov__io_wdata)))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffffeULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | (IData)((IData)(
                                                                   (1U 
                                                                    & (IData)(vlTOPp->io_wdata)))));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 1U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 1U))))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffffdULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 1U))))) 
                                                    << 1U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 2U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 2U))))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffffbULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 2U))))) 
                                                    << 2U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 3U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 3U))))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffff7ULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 3U))))) 
                                                    << 3U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 4U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 4U))))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffffefULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 4U))))) 
                                                    << 4U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 5U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 5U))))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffffdfULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 5U))))) 
                                                    << 5U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 6U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 6U))))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffffbfULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 6U))))) 
                                                    << 6U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 7U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 7U))))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffff7fULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 7U))))) 
                                                    << 7U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 8U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 8U))))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffeffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 8U))))) 
                                                    << 8U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 9U)) ^ (IData)(
                                                           (vlTOPp->Top__DOT____Vtogcov__io_wdata 
                                                            >> 9U))))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffdffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 9U))))) 
                                                    << 9U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xaU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffffbffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xaU))))) 
                                                    << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xbU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffff7ffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xbU))))) 
                                                    << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xcU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffefffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xcU))))) 
                                                    << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xdU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffdfffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xdU))))) 
                                                    << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xeU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffffbfffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xeU))))) 
                                                    << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0xfU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffff7fffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0xfU))))) 
                                                    << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x10U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffeffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x10U))))) 
                                                    << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x11U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffdffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x11U))))) 
                                                    << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x12U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffffbffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x12U))))) 
                                                    << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x13U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffff7ffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x13U))))) 
                                                    << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x14U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffefffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x14U))))) 
                                                    << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x15U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffdfffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x15U))))) 
                                                    << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x16U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffffbfffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x16U))))) 
                                                    << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x17U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffff7fffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x17U))))) 
                                                    << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x18U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffeffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x18U))))) 
                                                    << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x19U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffdffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x19U))))) 
                                                    << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffffbffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1aU))))) 
                                                    << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffff7ffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1bU))))) 
                                                    << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffefffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1cU))))) 
                                                    << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffdfffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1dU))))) 
                                                    << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffffbfffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1eU))))) 
                                                    << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x1fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffff7fffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x1fU))))) 
                                                    << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x20U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffeffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x20U))))) 
                                                    << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x21U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffdffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x21U))))) 
                                                    << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x22U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffffbffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x22U))))) 
                                                    << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x23U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffff7ffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x23U))))) 
                                                    << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x24U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffefffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x24U))))) 
                                                    << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x25U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffdfffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x25U))))) 
                                                    << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x26U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffffbfffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x26U))))) 
                                                    << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x27U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffff7fffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x27U))))) 
                                                    << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x28U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffeffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x28U))))) 
                                                    << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x29U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffdffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x29U))))) 
                                                    << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffffbffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2aU))))) 
                                                    << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffff7ffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2bU))))) 
                                                    << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffefffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2cU))))) 
                                                    << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffdfffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2dU))))) 
                                                    << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffffbfffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2eU))))) 
                                                    << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x2fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffff7fffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x2fU))))) 
                                                    << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x30U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffeffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x30U))))) 
                                                    << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x31U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffdffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x31U))))) 
                                                    << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x32U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfffbffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x32U))))) 
                                                    << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x33U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfff7ffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x33U))))) 
                                                    << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x34U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffefffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x34U))))) 
                                                    << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x35U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffdfffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x35U))))) 
                                                    << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x36U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xffbfffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x36U))))) 
                                                    << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x37U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xff7fffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x37U))))) 
                                                    << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x38U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfeffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x38U))))) 
                                                    << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x39U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfdffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x39U))))) 
                                                    << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xfbffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3aU))))) 
                                                    << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xf7ffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3bU))))) 
                                                    << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xefffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3cU))))) 
                                                    << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xdfffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3dU))))) 
                                                    << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0xbfffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3eU))))) 
                                                    << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->io_wdata >> 0x3fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_wdata 
                          >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->Top__DOT____Vtogcov__io_wdata = ((0x7fffffffffffffffULL 
                                                  & vlTOPp->Top__DOT____Vtogcov__io_wdata) 
                                                 | ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlTOPp->io_wdata 
                                                                                >> 0x3fU))))) 
                                                    << 0x3fU));
    }
}

VL_INLINE_OPT void VTop::_sequent__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_sequent__TOP__4\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__rf__DOT__regfile__v0;
    QData/*63:0*/ __Vdlyvval__Top__DOT__rf__DOT__regfile__v0;
    // Body
    __Vdlyvset__Top__DOT__rf__DOT__regfile__v0 = 0U;
    ++(vlSymsp->__Vcoverage[554]);
    if (vlTOPp->Top__DOT__wen) {
        ++(vlSymsp->__Vcoverage[552]);
        __Vdlyvval__Top__DOT__rf__DOT__regfile__v0 
            = vlTOPp->Top__DOT__wdata;
        __Vdlyvset__Top__DOT__rf__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0 
            = vlTOPp->Top__DOT__waddr;
    } else {
        ++(vlSymsp->__Vcoverage[553]);
    }
    if (__Vdlyvset__Top__DOT__rf__DOT__regfile__v0) {
        vlTOPp->Top__DOT__rf__DOT__regfile[__Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0] 
            = __Vdlyvval__Top__DOT__rf__DOT__regfile__v0;
    }
    ++(vlSymsp->__Vcoverage[418]);
    vlTOPp->Top__DOT__rs1_addr = vlTOPp->io_rs1_addr;
    vlTOPp->Top__DOT__rs2_addr = vlTOPp->io_rs2_addr;
    vlTOPp->Top__DOT__waddr = vlTOPp->io_waddr;
    vlTOPp->Top__DOT__wdata = vlTOPp->io_wdata;
    vlTOPp->Top__DOT__wen = vlTOPp->io_wen;
    if (((IData)(vlTOPp->Top__DOT__wen) ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wen)) {
        ++(vlSymsp->__Vcoverage[417]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wen = vlTOPp->Top__DOT__wen;
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__waddr) ^ vlTOPp->Top__DOT____Vtogcov__rf_io_waddr))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_waddr = 
            ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_waddr)) 
             | (1U & (IData)(vlTOPp->Top__DOT__waddr)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__waddr) ^ vlTOPp->Top__DOT____Vtogcov__rf_io_waddr))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_waddr = 
            ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_waddr)) 
             | (2U & (IData)(vlTOPp->Top__DOT__waddr)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__waddr) ^ vlTOPp->Top__DOT____Vtogcov__rf_io_waddr))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_waddr = 
            ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_waddr)) 
             | (4U & (IData)(vlTOPp->Top__DOT__waddr)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__waddr) ^ vlTOPp->Top__DOT____Vtogcov__rf_io_waddr))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_waddr = 
            ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_waddr)) 
             | (8U & (IData)(vlTOPp->Top__DOT__waddr)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__waddr) 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_waddr))) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_waddr = 
            ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_waddr)) 
             | (0x10U & (IData)(vlTOPp->Top__DOT__waddr)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__wdata) ^ (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_wdata)))) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffffeULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__wdata)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 1U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 1U))))) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffffdULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 1U))))) 
                << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 2U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 2U))))) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffffbULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 2U))))) 
                << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 3U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 3U))))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 3U))))) 
                << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 4U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 4U))))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffffefULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 4U))))) 
                << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 5U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 5U))))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffffdfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 5U))))) 
                << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 6U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 6U))))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffffbfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 6U))))) 
                << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 7U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 7U))))) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffff7fULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 7U))))) 
                << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 8U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 8U))))) {
        ++(vlSymsp->__Vcoverage[361]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffeffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 8U))))) 
                << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 9U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 9U))))) {
        ++(vlSymsp->__Vcoverage[362]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffdffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 9U))))) 
                << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xaU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[363]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffffbffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xaU))))) 
                << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xbU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[364]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xbU))))) 
                << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xcU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[365]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffefffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xcU))))) 
                << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xdU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[366]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffdfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xdU))))) 
                << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xeU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[367]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffffbfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xeU))))) 
                << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0xfU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[368]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffff7fffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0xfU))))) 
                << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x10U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[369]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffeffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x10U))))) 
                << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x11U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[370]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffdffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x11U))))) 
                << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x12U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[371]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffffbffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x12U))))) 
                << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x13U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[372]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x13U))))) 
                << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x14U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[373]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffefffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x14U))))) 
                << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x15U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[374]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffdfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x15U))))) 
                << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x16U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[375]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffffbfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x16U))))) 
                << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x17U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[376]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffff7fffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x17U))))) 
                << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x18U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[377]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffeffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x18U))))) 
                << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x19U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[378]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffdffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x19U))))) 
                << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[379]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffffbffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1aU))))) 
                << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[380]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1bU))))) 
                << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[381]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffefffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1cU))))) 
                << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[382]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffdfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1dU))))) 
                << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[383]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffffbfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1eU))))) 
                << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x1fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[384]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffff7fffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x1fU))))) 
                << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x20U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[385]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffeffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x20U))))) 
                << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x21U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[386]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffdffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x21U))))) 
                << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x22U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[387]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffbffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x22U))))) 
                << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x23U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[388]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x23U))))) 
                << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x24U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[389]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffefffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x24U))))) 
                << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x25U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[390]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffdfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x25U))))) 
                << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x26U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[391]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffbfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x26U))))) 
                << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x27U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[392]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffff7fffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x27U))))) 
                << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x28U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[393]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffeffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x28U))))) 
                << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x29U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[394]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffdffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x29U))))) 
                << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[395]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffbffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2aU))))) 
                << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[396]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2bU))))) 
                << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[397]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffefffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2cU))))) 
                << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[398]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffdfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2dU))))) 
                << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[399]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffbfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2eU))))) 
                << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x2fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[400]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffff7fffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x2fU))))) 
                << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x30U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[401]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffeffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x30U))))) 
                << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x31U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[402]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffdffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x31U))))) 
                << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x32U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[403]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffbffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x32U))))) 
                << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x33U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[404]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x33U))))) 
                << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x34U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[405]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffefffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x34U))))) 
                << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x35U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[406]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffdfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x35U))))) 
                << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x36U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[407]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffbfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x36U))))) 
                << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x37U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[408]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xff7fffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x37U))))) 
                << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x38U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfeffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x38U))))) 
                << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x39U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfdffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x39U))))) 
                << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfbffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3aU))))) 
                << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3bU))))) 
                << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xefffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3cU))))) 
                << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xdfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3dU))))) 
                << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xbfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3eU))))) 
                << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__wdata >> 0x3fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_wdata 
                          >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0x7fffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__wdata 
                                               >> 0x3fU))))) 
                << 0x3fU));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__rs1_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr 
            = ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr)) 
               | (1U & (IData)(vlTOPp->Top__DOT__rs1_addr)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__rs1_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr 
            = ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr)) 
               | (2U & (IData)(vlTOPp->Top__DOT__rs1_addr)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__rs1_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr 
            = ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr)) 
               | (4U & (IData)(vlTOPp->Top__DOT__rs1_addr)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__rs1_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr 
            = ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr)) 
               | (8U & (IData)(vlTOPp->Top__DOT__rs1_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__rs1_addr) 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr 
            = ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_addr)) 
               | (0x10U & (IData)(vlTOPp->Top__DOT__rs1_addr)));
    }
    vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
        = vlTOPp->Top__DOT__rf__DOT__regfile[vlTOPp->Top__DOT__rs1_addr];
    if ((1U & ((IData)(vlTOPp->Top__DOT__rs2_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr 
            = ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr)) 
               | (1U & (IData)(vlTOPp->Top__DOT__rs2_addr)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__rs2_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr 
            = ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr)) 
               | (2U & (IData)(vlTOPp->Top__DOT__rs2_addr)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__rs2_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr 
            = ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr)) 
               | (4U & (IData)(vlTOPp->Top__DOT__rs2_addr)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__rs2_addr) 
               ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr 
            = ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr)) 
               | (8U & (IData)(vlTOPp->Top__DOT__rs2_addr)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__rs2_addr) 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr 
            = ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_addr)) 
               | (0x10U & (IData)(vlTOPp->Top__DOT__rs2_addr)));
    }
    vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
        = vlTOPp->Top__DOT__rf__DOT__regfile[vlTOPp->Top__DOT__rs2_addr];
    if ((1U & ((IData)(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data) 
               ^ (IData)(vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data)))) {
        ++(vlSymsp->__Vcoverage[423]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[424]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[425]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[426]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[427]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffffefULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[428]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[429]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[430]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[431]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[432]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[433]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[434]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[435]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffefffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[436]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[437]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[438]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[439]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[440]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[441]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[442]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[443]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffefffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[444]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[445]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[446]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[447]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[448]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[449]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[450]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[451]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffefffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[452]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[453]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[454]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[455]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[456]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[457]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[458]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffefffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffefffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffefffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xefffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs1_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Top__DOT__rf_io_rs1_data = ((0U != (IData)(vlTOPp->Top__DOT__rs1_addr))
                                         ? vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data
                                         : 0ULL);
    if ((1U & ((IData)(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data) 
               ^ (IData)(vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data)))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffffefULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[495]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[496]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[497]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[498]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[499]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffefffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[500]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[501]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[502]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[503]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[504]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[505]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[506]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[507]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffefffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[508]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[509]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[510]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[511]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[512]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[513]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[514]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[515]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffefffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[516]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[517]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[518]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[519]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[520]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[521]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[522]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[523]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffefffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[524]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[525]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[526]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[527]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[528]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[529]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[530]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[531]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffefffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[532]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[533]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[534]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[535]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[536]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[537]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[538]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[539]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffefffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[540]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[541]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[542]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[543]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[544]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[545]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[546]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[547]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xefffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[548]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[549]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[550]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile_io_rs2_data_MPORT_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Top__DOT__rf_io_rs2_data = ((0U != (IData)(vlTOPp->Top__DOT__rs2_addr))
                                         ? vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data
                                         : 0ULL);
    if ((1U & ((IData)(vlTOPp->Top__DOT__rf_io_rs1_data) 
               ^ (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data)))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__rf_io_rs1_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffffefULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffefffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffefffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffefffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffefffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffefffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffefffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xefffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs1_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->io_rs1_data = vlTOPp->Top__DOT__rf_io_rs1_data;
    if ((1U & ((IData)(vlTOPp->Top__DOT__rf_io_rs2_data) 
               ^ (IData)(vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data)))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__rf_io_rs2_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffffefULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffefffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffefffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffefffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffefffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffefffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffefffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xefffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__rf_io_rs2_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->io_rs2_data = vlTOPp->Top__DOT__rf_io_rs2_data;
    if ((1U & ((IData)(vlTOPp->io_rs1_data) ^ (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs1_data)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffffeULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | (IData)((IData)((1U & (IData)(vlTOPp->io_rs1_data)))));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 1U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 1U))))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffffdULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 1U))))) 
                << 1U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 2U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 2U))))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffffbULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 2U))))) 
                << 2U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 3U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 3U))))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 3U))))) 
                << 3U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 4U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 4U))))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffffefULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 4U))))) 
                << 4U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 5U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 5U))))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffffdfULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 5U))))) 
                << 5U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 6U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 6U))))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffffbfULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 6U))))) 
                << 6U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 7U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 7U))))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffff7fULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 7U))))) 
                << 7U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 8U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 8U))))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffeffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 8U))))) 
                << 8U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 9U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 9U))))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffdffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 9U))))) 
                << 9U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xaU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffffbffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xaU))))) 
                << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xbU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xbU))))) 
                << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xcU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffefffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xcU))))) 
                << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xdU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffdfffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xdU))))) 
                << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xeU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffffbfffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xeU))))) 
                << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0xfU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffff7fffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0xfU))))) 
                << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x10U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffeffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x10U))))) 
                << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x11U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffdffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x11U))))) 
                << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x12U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffffbffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x12U))))) 
                << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x13U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x13U))))) 
                << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x14U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffefffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x14U))))) 
                << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x15U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffdfffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x15U))))) 
                << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x16U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffffbfffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x16U))))) 
                << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x17U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffff7fffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x17U))))) 
                << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x18U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffeffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x18U))))) 
                << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x19U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffdffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x19U))))) 
                << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffffbffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1aU))))) 
                << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1bU))))) 
                << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffefffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1cU))))) 
                << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffdfffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1dU))))) 
                << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffffbfffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1eU))))) 
                << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x1fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffff7fffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x1fU))))) 
                << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x20U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffeffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x20U))))) 
                << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x21U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffdffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x21U))))) 
                << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x22U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffffbffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x22U))))) 
                << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x23U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x23U))))) 
                << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x24U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffefffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x24U))))) 
                << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x25U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffdfffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x25U))))) 
                << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x26U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffffbfffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x26U))))) 
                << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x27U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffff7fffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x27U))))) 
                << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x28U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffeffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x28U))))) 
                << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x29U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffdffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x29U))))) 
                << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffffbffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2aU))))) 
                << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2bU))))) 
                << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffefffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2cU))))) 
                << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffdfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2dU))))) 
                << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffffbfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2eU))))) 
                << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x2fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffff7fffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x2fU))))) 
                << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x30U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffeffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x30U))))) 
                << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x31U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffdffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x31U))))) 
                << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x32U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfffbffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x32U))))) 
                << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x33U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x33U))))) 
                << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x34U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffefffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x34U))))) 
                << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x35U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffdfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x35U))))) 
                << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x36U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xffbfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x36U))))) 
                << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x37U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xff7fffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x37U))))) 
                << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x38U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfeffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x38U))))) 
                << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x39U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfdffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x39U))))) 
                << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xfbffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3aU))))) 
                << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3bU))))) 
                << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xefffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3cU))))) 
                << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xdfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3dU))))) 
                << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0xbfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3eU))))) 
                << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs1_data >> 0x3fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs1_data 
                          >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->Top__DOT____Vtogcov__io_rs1_data = 
            ((0x7fffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs1_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs1_data 
                                               >> 0x3fU))))) 
                << 0x3fU));
    }
    if ((1U & ((IData)(vlTOPp->io_rs2_data) ^ (IData)(vlTOPp->Top__DOT____Vtogcov__io_rs2_data)))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffffeULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | (IData)((IData)((1U & (IData)(vlTOPp->io_rs2_data)))));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 1U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 1U))))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffffdULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 1U))))) 
                << 1U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 2U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 2U))))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffffbULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 2U))))) 
                << 2U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 3U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 3U))))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffff7ULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 3U))))) 
                << 3U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 4U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 4U))))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffffefULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 4U))))) 
                << 4U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 5U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 5U))))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffffdfULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 5U))))) 
                << 5U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 6U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 6U))))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffffbfULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 6U))))) 
                << 6U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 7U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 7U))))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffff7fULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 7U))))) 
                << 7U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 8U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 8U))))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffeffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 8U))))) 
                << 8U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 9U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 9U))))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffdffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 9U))))) 
                << 9U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xaU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffffbffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xaU))))) 
                << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xbU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffff7ffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xbU))))) 
                << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xcU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffefffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xcU))))) 
                << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xdU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffdfffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xdU))))) 
                << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xeU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffffbfffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xeU))))) 
                << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0xfU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffff7fffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0xfU))))) 
                << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x10U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffeffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x10U))))) 
                << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x11U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffdffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x11U))))) 
                << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x12U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffffbffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x12U))))) 
                << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x13U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffff7ffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x13U))))) 
                << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x14U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffefffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x14U))))) 
                << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x15U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffdfffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x15U))))) 
                << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x16U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffffbfffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x16U))))) 
                << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x17U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffff7fffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x17U))))) 
                << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x18U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffeffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x18U))))) 
                << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x19U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffdffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x19U))))) 
                << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffffbffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1aU))))) 
                << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffff7ffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1bU))))) 
                << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffefffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1cU))))) 
                << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffdfffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1dU))))) 
                << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffffbfffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1eU))))) 
                << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x1fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffff7fffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x1fU))))) 
                << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x20U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffeffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x20U))))) 
                << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x21U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffdffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x21U))))) 
                << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x22U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffffbffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x22U))))) 
                << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x23U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffff7ffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x23U))))) 
                << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x24U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffefffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x24U))))) 
                << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x25U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffdfffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x25U))))) 
                << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x26U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffffbfffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x26U))))) 
                << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x27U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffff7fffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x27U))))) 
                << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x28U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffeffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x28U))))) 
                << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x29U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffdffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x29U))))) 
                << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffffbffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2aU))))) 
                << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffff7ffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2bU))))) 
                << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffefffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2cU))))) 
                << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffdfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2dU))))) 
                << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffffbfffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2eU))))) 
                << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x2fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffff7fffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x2fU))))) 
                << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x30U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffeffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x30U))))) 
                << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x31U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffdffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x31U))))) 
                << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x32U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfffbffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x32U))))) 
                << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x33U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfff7ffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x33U))))) 
                << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x34U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffefffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x34U))))) 
                << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x35U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffdfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x35U))))) 
                << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x36U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xffbfffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x36U))))) 
                << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x37U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xff7fffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x37U))))) 
                << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x38U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfeffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x38U))))) 
                << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x39U)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfdffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x39U))))) 
                << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3aU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xfbffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3aU))))) 
                << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3bU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xf7ffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3bU))))) 
                << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3cU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xefffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3cU))))) 
                << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3dU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xdfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3dU))))) 
                << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3eU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0xbfffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3eU))))) 
                << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->io_rs2_data >> 0x3fU)) 
               ^ (IData)((vlTOPp->Top__DOT____Vtogcov__io_rs2_data 
                          >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->Top__DOT____Vtogcov__io_rs2_data = 
            ((0x7fffffffffffffffULL & vlTOPp->Top__DOT____Vtogcov__io_rs2_data) 
             | ((QData)((IData)((1U & (IData)((vlTOPp->io_rs2_data 
                                               >> 0x3fU))))) 
                << 0x3fU));
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
