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
            VL_FATAL_MT("../Top.v", 3345, "",
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
            VL_FATAL_MT("../Top.v", 3345, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VTop::_settle__TOP__7(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_settle__TOP__7\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp37[3];
    WData/*95:0*/ __Vtemp39[3];
    WData/*95:0*/ __Vtemp40[3];
    // Body
    if ((1U & ((IData)(vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out) 
               ^ (IData)(vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big)))) {
        ++(vlSymsp->__Vcoverage[9028]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | (IData)((IData)((1U & (IData)(vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out)))));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[9029]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[9030]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[9031]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[9032]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[9033]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[9034]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[9035]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[9036]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[9037]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[9038]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[9039]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[9040]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[9041]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[9042]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[9043]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[9044]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[9045]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[9046]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[9047]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[9048]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[9049]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[9050]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[9051]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[9052]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[9053]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[9054]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[9055]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[9056]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[9057]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[9058]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[9059]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[9060]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[9061]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[9062]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[9063]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[9064]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[9065]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[9066]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[9067]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[9068]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[9069]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[9070]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[9071]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[9072]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[9073]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[9074]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[9075]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[9076]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[9077]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[9078]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[9079]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[9080]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[9081]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[9082]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[9083]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[9084]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[9085]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[9086]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[9087]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[9088]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[9089]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[9090]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[9091]);
        vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__ram__DOT____Vtogcov__wdata_big) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    if ((1U & ((IData)(vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out) 
               ^ (IData)(vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data)))) {
        ++(vlSymsp->__Vcoverage[2183]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | (IData)((IData)((1U & (IData)(vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out)))));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[2184]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[2185]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[2186]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[2187]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[2188]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[2189]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[2190]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[2191]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[2192]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[2193]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[2194]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[2195]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[2196]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[2197]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[2198]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[2199]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[2200]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[2201]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[2202]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[2203]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[2204]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[2205]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[2206]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[2207]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[2208]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[2209]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[2210]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[2211]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[2212]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[2213]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[2214]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[2215]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[2216]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[2217]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[2218]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[2219]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[2220]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[2221]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[2222]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[2223]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[2224]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[2225]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[2226]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[2227]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[2228]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[2229]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[2230]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[2231]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[2232]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[2233]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[2234]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[2235]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[2236]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[2237]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[2238]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[2239]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[2240]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[2241]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[2242]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[2243]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[2244]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[2245]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[2246]);
        vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT____Vtogcov__core_io_imem_resp_bits_data) 
               | ((QData)((IData)((1U & (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
        = (vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
           >> ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset) 
               << 3U));
    vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
        = ((IData)(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__from_pre_r_offset)
            ? (IData)((vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out 
                       >> 0x20U)) : (IData)(vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out));
    if ((1U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                               >> 0x1fU))) ? 0xffffffffU
                 : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8374]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffffeU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 1U : 0U));
    }
    if ((2U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                               >> 0x1fU))) ? 0xffffffffU
                 : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8375]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffffdU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 2U : 0U));
    }
    if ((4U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                               >> 0x1fU))) ? 0xffffffffU
                 : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8376]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffffbU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 4U : 0U));
    }
    if ((8U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                               >> 0x1fU))) ? 0xffffffffU
                 : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8377]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffff7U & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 8U : 0U));
    }
    if ((0x10U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                  >> 0x1fU))) ? 0xffffffffU
                    : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8378]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffffefU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x10U
                   : 0U));
    }
    if ((0x20U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                  >> 0x1fU))) ? 0xffffffffU
                    : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8379]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffffdfU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x20U
                   : 0U));
    }
    if ((0x40U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                  >> 0x1fU))) ? 0xffffffffU
                    : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8380]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffffbfU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x40U
                   : 0U));
    }
    if ((0x80U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                  >> 0x1fU))) ? 0xffffffffU
                    : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8381]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffff7fU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x80U
                   : 0U));
    }
    if ((0x100U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                   >> 0x1fU))) ? 0xffffffffU
                     : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8382]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffeffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x100U
                   : 0U));
    }
    if ((0x200U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                   >> 0x1fU))) ? 0xffffffffU
                     : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8383]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffdffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x200U
                   : 0U));
    }
    if ((0x400U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                   >> 0x1fU))) ? 0xffffffffU
                     : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8384]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffffbffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x400U
                   : 0U));
    }
    if ((0x800U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                   >> 0x1fU))) ? 0xffffffffU
                     : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8385]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffff7ffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x800U
                   : 0U));
    }
    if ((0x1000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                    >> 0x1fU))) ? 0xffffffffU
                      : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8386]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffefffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x1000U
                   : 0U));
    }
    if ((0x2000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                    >> 0x1fU))) ? 0xffffffffU
                      : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8387]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffdfffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x2000U
                   : 0U));
    }
    if ((0x4000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                    >> 0x1fU))) ? 0xffffffffU
                      : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8388]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffffbfffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x4000U
                   : 0U));
    }
    if ((0x8000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                    >> 0x1fU))) ? 0xffffffffU
                      : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8389]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffff7fffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x8000U
                   : 0U));
    }
    if ((0x10000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                     >> 0x1fU))) ? 0xffffffffU
                       : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8390]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffeffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x10000U
                   : 0U));
    }
    if ((0x20000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                     >> 0x1fU))) ? 0xffffffffU
                       : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8391]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffdffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x20000U
                   : 0U));
    }
    if ((0x40000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                     >> 0x1fU))) ? 0xffffffffU
                       : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8392]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfffbffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x40000U
                   : 0U));
    }
    if ((0x80000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                     >> 0x1fU))) ? 0xffffffffU
                       : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8393]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfff7ffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x80000U
                   : 0U));
    }
    if ((0x100000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                      >> 0x1fU))) ? 0xffffffffU
                        : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8394]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffefffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x100000U
                   : 0U));
    }
    if ((0x200000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                      >> 0x1fU))) ? 0xffffffffU
                        : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8395]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffdfffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x200000U
                   : 0U));
    }
    if ((0x400000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                      >> 0x1fU))) ? 0xffffffffU
                        : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8396]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xffbfffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x400000U
                   : 0U));
    }
    if ((0x800000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                      >> 0x1fU))) ? 0xffffffffU
                        : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8397]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xff7fffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x800000U
                   : 0U));
    }
    if ((0x1000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 0x1fU))) ? 0xffffffffU
                         : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8398]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfeffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x1000000U
                   : 0U));
    }
    if ((0x2000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 0x1fU))) ? 0xffffffffU
                         : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8399]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfdffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x2000000U
                   : 0U));
    }
    if ((0x4000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 0x1fU))) ? 0xffffffffU
                         : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8400]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xfbffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x4000000U
                   : 0U));
    }
    if ((0x8000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 0x1fU))) ? 0xffffffffU
                         : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8401]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xf7ffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x8000000U
                   : 0U));
    }
    if ((0x10000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0x1fU)))
                          ? 0xffffffffU : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8402]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xefffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x10000000U
                   : 0U));
    }
    if ((0x20000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0x1fU)))
                          ? 0xffffffffU : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8403]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xdfffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x20000000U
                   : 0U));
    }
    if ((0x40000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0x1fU)))
                          ? 0xffffffffU : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8404]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0xbfffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x40000000U
                   : 0U));
    }
    if ((0x80000000U & (((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0x1fU)))
                          ? 0xffffffffU : 0U) ^ vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2))) {
        ++(vlSymsp->__Vcoverage[8405]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2 
            = ((0x7fffffffU & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_2) 
               | ((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                 >> 0x1fU))) ? 0x80000000U
                   : 0U));
    }
    if ((1U & ((IData)(((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 0xfU))) ? 0xffffffffffffULL
                         : 0ULL)) ^ (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1)))) {
        ++(vlSymsp->__Vcoverage[8326]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffffeULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | (IData)((IData)((1U & (IData)(((1U 
                                                 & (IData)(
                                                           (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                            >> 0xfU)))
                                                 ? 0xffffffffffffULL
                                                 : 0ULL))))));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 1U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 1U))))) {
        ++(vlSymsp->__Vcoverage[8327]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffffdULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 2U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 2U))))) {
        ++(vlSymsp->__Vcoverage[8328]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffffbULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 3U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8329]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 4U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 4U))))) {
        ++(vlSymsp->__Vcoverage[8330]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffffefULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 5U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 5U))))) {
        ++(vlSymsp->__Vcoverage[8331]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 6U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 6U))))) {
        ++(vlSymsp->__Vcoverage[8332]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 7U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 7U))))) {
        ++(vlSymsp->__Vcoverage[8333]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 8U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 8U))))) {
        ++(vlSymsp->__Vcoverage[8334]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffeffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 9U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                     >> 9U))))) {
        ++(vlSymsp->__Vcoverage[8335]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffdffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xaU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[8336]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffffbffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xbU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[8337]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xcU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[8338]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffefffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xdU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[8339]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xeU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[8340]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0xfU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                       >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[8341]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x10U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[8342]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffeffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x11U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[8343]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffdffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x12U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[8344]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffffbffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x13U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[8345]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x14U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[8346]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffefffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x15U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[8347]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x16U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[8348]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x17U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[8349]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x18U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[8350]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffeffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x19U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[8351]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffdffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1aU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[8352]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffffbffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1bU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[8353]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1cU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[8354]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffefffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1dU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[8355]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1eU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[8356]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x1fU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[8357]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x20U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[8358]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffeffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x21U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[8359]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffdffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x22U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[8360]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfffbffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x23U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[8361]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x24U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[8362]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffefffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x25U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[8363]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x26U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[8364]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x27U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[8365]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x28U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[8366]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfeffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x29U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[8367]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfdffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2aU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[8368]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xfbffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2bU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[8369]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xf7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2cU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[8370]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xefffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2dU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[8371]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2eU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[8372]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0xbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) >> 0x2fU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
                                                        >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[8373]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1 
            = ((0x7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right_1) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 0xfU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)(((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                       >> 7U))) ? 0xffffffffffffffULL
                         : 0ULL)) ^ (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right)))) {
        ++(vlSymsp->__Vcoverage[8270]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | (IData)((IData)((1U & (IData)(((1U 
                                                 & (IData)(
                                                           (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                            >> 7U)))
                                                 ? 0xffffffffffffffULL
                                                 : 0ULL))))));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 1U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 1U))))) {
        ++(vlSymsp->__Vcoverage[8271]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 2U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 2U))))) {
        ++(vlSymsp->__Vcoverage[8272]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 3U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8273]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 4U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 4U))))) {
        ++(vlSymsp->__Vcoverage[8274]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 5U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 5U))))) {
        ++(vlSymsp->__Vcoverage[8275]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 6U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 6U))))) {
        ++(vlSymsp->__Vcoverage[8276]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 7U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 7U))))) {
        ++(vlSymsp->__Vcoverage[8277]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 8U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 8U))))) {
        ++(vlSymsp->__Vcoverage[8278]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 9U)) ^ (IData)(
                                                    (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                     >> 9U))))) {
        ++(vlSymsp->__Vcoverage[8279]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xaU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[8280]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xbU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[8281]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xcU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[8282]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xdU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[8283]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xeU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[8284]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0xfU)) ^ (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                       >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[8285]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x10U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[8286]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x11U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[8287]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x12U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[8288]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x13U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[8289]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x14U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[8290]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x15U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[8291]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x16U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[8292]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x17U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[8293]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x18U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[8294]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x19U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[8295]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1aU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[8296]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1bU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[8297]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1cU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[8298]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1dU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[8299]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1eU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[8300]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x1fU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[8301]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x20U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[8302]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x21U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[8303]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x22U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[8304]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x23U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[8305]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x24U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[8306]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x25U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[8307]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x26U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[8308]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x27U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[8309]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x28U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[8310]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x29U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[8311]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2aU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[8312]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2bU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[8313]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2cU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[8314]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2dU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[8315]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2eU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[8316]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x2fU)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[8317]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x30U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[8318]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x31U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[8319]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x32U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[8320]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xfbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x33U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[8321]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xf7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x34U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[8322]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x35U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[8323]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x36U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[8324]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0xbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 7U))) ? 0xffffffffffffffULL
                          : 0ULL) >> 0x37U)) ^ (IData)(
                                                       (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
                                                        >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[8325]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right 
            = ((0x7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__right) 
               | ((QData)((IData)((1U & (IData)((((1U 
                                                   & (IData)(
                                                             (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                              >> 7U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data)))) {
        ++(vlSymsp->__Vcoverage[8206]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[8207]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[8208]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8209]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[8210]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[8211]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[8212]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[8213]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[8214]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[8215]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[8216]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[8217]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[8218]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[8219]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[8220]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[8221]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[8222]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[8223]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[8224]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[8225]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[8226]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[8227]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[8228]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[8229]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[8230]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[8231]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[8232]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[8233]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[8234]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[8235]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[8236]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[8237]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[8238]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[8239]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[8240]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[8241]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[8242]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[8243]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[8244]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[8245]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[8246]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[8247]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[8248]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[8249]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[8250]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[8251]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[8252]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[8253]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[8254]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[8255]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[8256]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[8257]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[8258]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[8259]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[8260]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[8261]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[8262]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[8263]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[8264]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[8265]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[8266]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[8267]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[8268]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[8269]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
        = ((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
            ? ((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                >> 7U))) ? 0xffffffffffffffULL
                  : 0ULL) << 8U) | (QData)((IData)(
                                                   (0xffU 
                                                    & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)))))
            : ((5U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
                ? (QData)((IData)((0xffU & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))))
                : ((2U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
                    ? ((((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                        >> 0xfU))) ? 0xffffffffffffULL
                          : 0ULL) << 0x10U) | (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)))))
                    : ((6U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
                        ? (QData)((IData)((0xffffU 
                                           & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))))
                        : ((3U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
                            ? (((QData)((IData)(((1U 
                                                  & (IData)(
                                                            (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                             >> 0x1fU)))
                                                  ? 0xffffffffU
                                                  : 0U))) 
                                << 0x20U) | (QData)((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)))
                            : ((7U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk))
                                ? (QData)((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))
                                : vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out))))));
    if ((1U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
               ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4927]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffffeU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (1U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((2U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
               ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4928]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffffdU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (2U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((4U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
               ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4929]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffffbU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (4U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((8U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
               ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4930]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffff7U & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (8U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x10U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                  ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4931]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffffefU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x10U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x20U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                  ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4932]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffffdfU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x20U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x40U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                  ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4933]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffffbfU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x40U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x80U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                  ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4934]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffff7fU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x80U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x100U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                   ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4935]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffeffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x100U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x200U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                   ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4936]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffdffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x200U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x400U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                   ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4937]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffffbffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x400U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x800U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                   ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4938]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffff7ffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x800U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x1000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                    ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4939]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffefffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x1000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x2000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                    ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4940]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffdfffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x2000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x4000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                    ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4941]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffffbfffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x4000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x8000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                    ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4942]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffff7fffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x8000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x10000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                     ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4943]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffeffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x10000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x20000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                     ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4944]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffdffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x20000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x40000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                     ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4945]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfffbffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x40000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x80000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                     ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4946]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfff7ffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x80000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x100000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                      ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4947]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffefffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x100000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x200000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                      ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4948]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffdfffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x200000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x400000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                      ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4949]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xffbfffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x400000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x800000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                      ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4950]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xff7fffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x800000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x1000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                       ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4951]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfeffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x1000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x2000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                       ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4952]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfdffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x2000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x4000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                       ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4953]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xfbffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x4000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x8000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                       ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4954]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xf7ffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x8000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x10000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                        ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4955]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xefffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x10000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x20000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                        ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4956]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xdfffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x20000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x40000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                        ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4957]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0xbfffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x40000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((0x80000000U & (vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst 
                        ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst))) {
        ++(vlSymsp->__Vcoverage[4958]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst 
            = ((0x7fffffffU & vlTOPp->Soc__DOT__core__DOT____Vtogcov__fs_top_io_ds_bits_inst) 
               | (0x80000000U & vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst));
    }
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final)))) {
        ++(vlSymsp->__Vcoverage[8406]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[8407]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[8408]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[8409]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[8410]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[8411]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[8412]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[8413]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[8414]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[8415]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[8416]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[8417]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[8418]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[8419]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[8420]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[8421]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[8422]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[8423]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[8424]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[8425]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[8426]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[8427]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[8428]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[8429]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[8430]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[8431]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[8432]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[8433]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[8434]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[8435]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[8436]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[8437]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[8438]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[8439]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[8440]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[8441]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[8442]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[8443]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[8444]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[8445]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[8446]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[8447]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[8448]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[8449]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[8450]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[8451]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[8452]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[8453]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[8454]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[8455]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[8456]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[8457]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[8458]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[8459]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[8460]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[8461]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[8462]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[8463]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[8464]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[8465]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[8466]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[8467]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[8468]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[8469]);
        vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ms_top__DOT____Vtogcov__load_final) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
        = ((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))
            ? vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final
            : vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result);
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data)))) {
        ++(vlSymsp->__Vcoverage[5215]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[5216]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[5217]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[5218]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[5219]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[5220]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[5221]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[5222]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[5223]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[5224]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[5225]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[5226]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[5227]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[5228]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[5229]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[5230]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[5231]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[5232]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[5233]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[5234]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[5235]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[5236]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[5237]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[5238]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[5239]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[5240]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[5241]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[5242]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[5243]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[5244]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[5245]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[5246]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[5247]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[5248]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[5249]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[5250]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[5251]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[5252]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[5253]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[5254]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[5255]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[5256]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[5257]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[5258]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[5259]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[5260]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[5261]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[5262]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[5263]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[5264]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[5265]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[5266]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[5267]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[5268]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[5269]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[5270]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[5271]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[5272]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[5273]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[5274]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[5275]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[5276]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[5277]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[5278]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_ms_res_wr_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
        = ((((IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen) 
             & ((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                          >> 7U)) == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                               >> 0x14U)))) 
            & (1U != (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel)))
            ? vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_bits_alu_result
            : (((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen) 
                & ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr) 
                   == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                >> 0x14U)))) ? vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result
                : (((IData)(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_decode_rf_wen) 
                    & ((IData)(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_rd_addr) 
                       == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                    >> 0x14U)))) ? vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_final_result
                    : vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data)));
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
        = ((((IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen) 
             & ((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                          >> 7U)) == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                               >> 0xfU)))) 
            & (1U != (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel)))
            ? vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_bits_alu_result
            : (((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen) 
                & ((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr) 
                   == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                >> 0xfU)))) ? vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result
                : (((IData)(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_decode_rf_wen) 
                    & ((IData)(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_rd_addr) 
                       == (0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                    >> 0xfU)))) ? vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_final_result
                    : vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data)));
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data)))) {
        ++(vlSymsp->__Vcoverage[5075]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[5076]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[5077]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[5078]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[5079]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[5080]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[5081]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[5082]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[5083]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[5084]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[5085]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[5086]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[5087]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[5088]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[5089]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[5090]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[5091]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[5092]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[5093]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[5094]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[5095]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[5096]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[5097]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[5098]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[5099]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[5100]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[5101]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[5102]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[5103]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[5104]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[5105]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[5106]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[5107]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[5108]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[5109]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[5110]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[5111]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[5112]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[5113]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[5114]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[5115]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[5116]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[5117]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[5118]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[5119]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[5120]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[5121]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[5122]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[5123]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[5124]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[5125]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[5126]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[5127]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[5128]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[5129]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[5130]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[5131]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[5132]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[5133]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[5134]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[5135]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[5136]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[5137]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[5138]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs2_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq 
        = (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
           == vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data);
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt 
        = VL_LTS_IQQ(1,64,64, vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data, vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data);
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu 
        = (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
           < vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data);
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data)))) {
        ++(vlSymsp->__Vcoverage[5011]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[5012]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[5013]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[5014]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[5015]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[5016]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[5017]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[5018]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[5019]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[5020]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[5021]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[5022]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[5023]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[5024]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[5025]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[5026]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[5027]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[5028]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[5029]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[5030]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[5031]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[5032]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[5033]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[5034]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[5035]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[5036]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[5037]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[5038]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[5039]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[5040]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[5041]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[5042]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[5043]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[5044]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[5045]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[5046]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[5047]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[5048]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[5049]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[5050]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[5051]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[5052]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[5053]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[5054]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[5055]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[5056]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[5057]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[5058]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[5059]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[5060]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[5061]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[5062]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[5063]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[5064]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[5065]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[5066]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[5067]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[5068]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[5069]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[5070]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[5071]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[5072]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[5073]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[5074]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__ds_top_io_es_bits_rs1_data) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
        = (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data 
           + vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_i_sext);
    if (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq) 
         ^ vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_eq)) {
        ++(vlSymsp->__Vcoverage[6384]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_eq 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq;
    }
    if (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt) 
         ^ vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_lt)) {
        ++(vlSymsp->__Vcoverage[6385]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_lt 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt;
    }
    if (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu) 
         ^ vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_ltu)) {
        ++(vlSymsp->__Vcoverage[6386]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__rf_ltu 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu;
    }
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken 
        = (((2U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
            & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq)) 
           | (((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
               & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq))) 
              | (((3U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
                  & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt))) 
                 | (((4U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
                     & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu))) 
                    | (((5U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
                        & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt)) 
                       | (((6U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
                           & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu)) 
                          | ((7U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)) 
                             | (8U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type)))))))));
    if ((1U & ((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target) 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target)))) {
        ++(vlSymsp->__Vcoverage[6320]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target)))));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 1U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[6321]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 2U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[6322]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 3U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[6323]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 4U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[6324]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 5U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[6325]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 6U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[6326]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 7U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[6327]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 8U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[6328]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 9U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[6329]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xaU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[6330]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xbU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[6331]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xcU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[6332]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xdU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[6333]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xeU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[6334]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0xfU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[6335]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x10U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[6336]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x11U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[6337]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x12U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[6338]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x13U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[6339]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x14U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[6340]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x15U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[6341]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x16U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[6342]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x17U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[6343]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x18U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[6344]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x19U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[6345]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[6346]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[6347]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[6348]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[6349]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[6350]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[6351]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x20U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[6352]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x21U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[6353]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x21U))))) 
                  << 0x21U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x22U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[6354]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x22U))))) 
                  << 0x22U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x23U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[6355]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x23U))))) 
                  << 0x23U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x24U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[6356]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x24U))))) 
                  << 0x24U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x25U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[6357]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x25U))))) 
                  << 0x25U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x26U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[6358]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x26U))))) 
                  << 0x26U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x27U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[6359]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x27U))))) 
                  << 0x27U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x28U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[6360]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x28U))))) 
                  << 0x28U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x29U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[6361]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x29U))))) 
                  << 0x29U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[6362]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2aU))))) 
                  << 0x2aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[6363]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2bU))))) 
                  << 0x2bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[6364]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2cU))))) 
                  << 0x2cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[6365]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2dU))))) 
                  << 0x2dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[6366]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2eU))))) 
                  << 0x2eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x2fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[6367]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x2fU))))) 
                  << 0x2fU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x30U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[6368]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x30U))))) 
                  << 0x30U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x31U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[6369]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x31U))))) 
                  << 0x31U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x32U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[6370]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x32U))))) 
                  << 0x32U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x33U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[6371]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x33U))))) 
                  << 0x33U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x34U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[6372]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x34U))))) 
                  << 0x34U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x35U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[6373]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x35U))))) 
                  << 0x35U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x36U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[6374]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x36U))))) 
                  << 0x36U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x37U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[6375]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x37U))))) 
                  << 0x37U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x38U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[6376]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x38U))))) 
                  << 0x38U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x39U)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[6377]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x39U))))) 
                  << 0x39U));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3aU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[6378]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3aU))))) 
                  << 0x3aU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3bU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[6379]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3bU))))) 
                  << 0x3bU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3cU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[6380]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3cU))))) 
                  << 0x3cU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3dU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[6381]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3dU))))) 
                  << 0x3dU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3eU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[6382]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3eU))))) 
                  << 0x3eU));
    }
    if ((1U & ((IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                        >> 0x3fU)) ^ (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
                                              >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[6383]);
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT____Vtogcov__jr_target) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target 
                                                 >> 0x3fU))))) 
                  << 0x3fU));
    }
    VL_EXTEND_WQ(66,64, __Vtemp37, vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target);
    if ((8U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type))) {
        __Vtemp39[0U] = __Vtemp37[0U];
        __Vtemp39[1U] = __Vtemp37[1U];
        __Vtemp39[2U] = __Vtemp37[2U];
    } else {
        __Vtemp39[0U] = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__branch_target[0U];
        __Vtemp39[1U] = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__branch_target[1U];
        __Vtemp39[2U] = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__branch_target[2U];
    }
    VL_EXTEND_WW(74,66, __Vtemp40, __Vtemp39);
    if ((7U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type))) {
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jmp_target[0U];
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jmp_target[1U];
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[2U] 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jmp_target[2U];
    } else {
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
            = __Vtemp40[0U];
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
            = __Vtemp40[1U];
        vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[2U] 
            = __Vtemp40[2U];
    }
    if (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken) 
         ^ vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_taken_0)) {
        ++(vlSymsp->__Vcoverage[4730]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_taken_0 
            = vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken;
    }
    vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___GEN_6 
        = ((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken) 
           | (IData)(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__buf_valid));
    vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___GEN_9 
        = (((((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken) 
              & (IData)(vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_valid)) 
             & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top_io_fs_ready)) 
            & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set))) 
           | (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken) 
               & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set))) 
              | (((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___T) 
                  & (0U < (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_reg)))
                  ? ((0U != (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_reg)) 
                     & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set))
                  : ((~ ((IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___T) 
                         & (0U == (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_reg)))) 
                     & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set)))));
    if ((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
               ^ (IData)(vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0)))) {
        ++(vlSymsp->__Vcoverage[4797]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffffeULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | (IData)((IData)((1U & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U]))));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 1U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 1U))))) {
        ++(vlSymsp->__Vcoverage[4798]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffffdULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 2U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 2U))))) {
        ++(vlSymsp->__Vcoverage[4799]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffffbULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 3U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 3U))))) {
        ++(vlSymsp->__Vcoverage[4800]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffff7ULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 3U)))) 
                  << 3U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 4U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 4U))))) {
        ++(vlSymsp->__Vcoverage[4801]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffffefULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 4U)))) 
                  << 4U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 5U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 5U))))) {
        ++(vlSymsp->__Vcoverage[4802]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffffdfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 5U)))) 
                  << 5U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 6U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 6U))))) {
        ++(vlSymsp->__Vcoverage[4803]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffffbfULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 6U)))) 
                  << 6U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 7U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 7U))))) {
        ++(vlSymsp->__Vcoverage[4804]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffff7fULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 7U)))) 
                  << 7U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 8U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 8U))))) {
        ++(vlSymsp->__Vcoverage[4805]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffeffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 8U)))) 
                  << 8U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 9U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 9U))))) {
        ++(vlSymsp->__Vcoverage[4806]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffdffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 9U)))) 
                  << 9U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xaU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[4807]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffffbffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xaU)))) 
                  << 0xaU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xbU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[4808]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffff7ffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xbU)))) 
                  << 0xbU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xcU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[4809]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffefffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xcU)))) 
                  << 0xcU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xdU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[4810]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffdfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xdU)))) 
                  << 0xdU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xeU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[4811]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffffbfffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xeU)))) 
                  << 0xeU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0xfU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[4812]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffff7fffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0xfU)))) 
                  << 0xfU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x10U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[4813]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffeffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x10U)))) 
                  << 0x10U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x11U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[4814]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffdffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x11U)))) 
                  << 0x11U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x12U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[4815]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffffbffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x12U)))) 
                  << 0x12U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x13U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[4816]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffff7ffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x13U)))) 
                  << 0x13U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x14U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[4817]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffefffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x14U)))) 
                  << 0x14U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x15U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[4818]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffdfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x15U)))) 
                  << 0x15U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x16U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[4819]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffffbfffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x16U)))) 
                  << 0x16U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x17U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[4820]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffff7fffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x17U)))) 
                  << 0x17U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x18U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[4821]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffeffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x18U)))) 
                  << 0x18U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x19U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[4822]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffdffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x19U)))) 
                  << 0x19U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1aU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[4823]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffffbffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1aU)))) 
                  << 0x1aU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1bU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[4824]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffff7ffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1bU)))) 
                  << 0x1bU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1cU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[4825]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffefffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1cU)))) 
                  << 0x1cU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1dU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[4826]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffdfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1dU)))) 
                  << 0x1dU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1eU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[4827]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffffbfffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1eU)))) 
                  << 0x1eU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                >> 0x1fU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[4828]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffff7fffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U] 
                                         >> 0x1fU)))) 
                  << 0x1fU));
    }
    if ((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
               ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                          >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[4829]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffeffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U]))) 
                  << 0x20U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 1U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[4830]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffdffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 1U)))) 
                  << 0x21U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 2U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[4831]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffffbffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 2U)))) 
                  << 0x22U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 3U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[4832]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffff7ffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 3U)))) 
                  << 0x23U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 4U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[4833]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffefffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 4U)))) 
                  << 0x24U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 5U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[4834]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffdfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 5U)))) 
                  << 0x25U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 6U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[4835]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffffbfffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 6U)))) 
                  << 0x26U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 7U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[4836]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffff7fffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 7U)))) 
                  << 0x27U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 8U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[4837]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffeffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 8U)))) 
                  << 0x28U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 9U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                  >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[4838]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffdffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 9U)))) 
                  << 0x29U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xaU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[4839]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffffbffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xaU)))) 
                  << 0x2aU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xbU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[4840]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffff7ffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xbU)))) 
                  << 0x2bU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xcU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[4841]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffefffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xcU)))) 
                  << 0x2cU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xdU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[4842]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffdfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xdU)))) 
                  << 0x2dU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xeU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[4843]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffffbfffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xeU)))) 
                  << 0x2eU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0xfU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                    >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[4844]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffff7fffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0xfU)))) 
                  << 0x2fU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x10U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[4845]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffeffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x10U)))) 
                  << 0x30U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x11U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[4846]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffdffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x11U)))) 
                  << 0x31U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x12U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[4847]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfffbffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x12U)))) 
                  << 0x32U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x13U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[4848]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfff7ffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x13U)))) 
                  << 0x33U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x14U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[4849]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffefffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x14U)))) 
                  << 0x34U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x15U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[4850]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffdfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x15U)))) 
                  << 0x35U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x16U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[4851]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xffbfffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x16U)))) 
                  << 0x36U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x17U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[4852]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xff7fffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x17U)))) 
                  << 0x37U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x18U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[4853]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfeffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x18U)))) 
                  << 0x38U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x19U) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[4854]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfdffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x19U)))) 
                  << 0x39U));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1aU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[4855]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xfbffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1aU)))) 
                  << 0x3aU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1bU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[4856]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xf7ffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1bU)))) 
                  << 0x3bU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1cU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[4857]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xefffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1cU)))) 
                  << 0x3cU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1dU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[4858]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xdfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1dU)))) 
                  << 0x3dU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1eU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[4859]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0xbfffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1eU)))) 
                  << 0x3eU));
    }
    if ((1U & ((vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                >> 0x1fU) ^ (IData)((vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
                                     >> 0x3fU))))) {
        ++(vlSymsp->__Vcoverage[4860]);
        vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0 
            = ((0x7fffffffffffffffULL & vlTOPp->Soc__DOT__core__DOT____Vtogcov__pre_top_br_target_0) 
               | ((QData)((IData)((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U] 
                                         >> 0x1fU)))) 
                  << 0x3fU));
    }
}
