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
            VL_FATAL_MT("Top.v", 852, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
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
            VL_FATAL_MT("Top.v", 852, "",
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
    if (((IData)(vlTOPp->io_imem_req_ready) ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_ready)) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_ready 
            = vlTOPp->io_imem_req_ready;
    }
    if (((IData)(vlTOPp->io_imem_resp_valid) ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_valid)) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_valid 
            = vlTOPp->io_imem_resp_valid;
    }
    if (((IData)(vlTOPp->io_dmem_req_ready) ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_ready)) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_ready 
            = vlTOPp->io_dmem_req_ready;
    }
    if (((IData)(vlTOPp->io_dmem_resp_valid) ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_valid)) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_valid 
            = vlTOPp->io_dmem_resp_valid;
    }
    if ((1U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (1U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((2U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (2U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((4U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (4U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((8U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (8U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x10U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x10U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x20U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x20U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x40U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x40U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x80U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x80U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x100U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x100U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x200U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x200U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x400U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x400U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x800U & (vlTOPp->io_imem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x800U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x1000U & (vlTOPp->io_imem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x1000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x2000U & (vlTOPp->io_imem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x2000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x4000U & (vlTOPp->io_imem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x4000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x8000U & (vlTOPp->io_imem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x8000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x10000U & (vlTOPp->io_imem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x10000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x20000U & (vlTOPp->io_imem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x20000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x40000U & (vlTOPp->io_imem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x40000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x80000U & (vlTOPp->io_imem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x80000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x100000U & (vlTOPp->io_imem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x100000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x200000U & (vlTOPp->io_imem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x200000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x400000U & (vlTOPp->io_imem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x400000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x800000U & (vlTOPp->io_imem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x800000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x1000000U & (vlTOPp->io_imem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x1000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x2000000U & (vlTOPp->io_imem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x2000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x4000000U & (vlTOPp->io_imem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x4000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x8000000U & (vlTOPp->io_imem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x8000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x10000000U & (vlTOPp->io_imem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x10000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x20000000U & (vlTOPp->io_imem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x20000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x40000000U & (vlTOPp->io_imem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x40000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((0x80000000U & (vlTOPp->io_imem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_resp_bits_data) 
               | (0x80000000U & vlTOPp->io_imem_resp_bits_data));
    }
    if ((1U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (1U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((2U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (2U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((4U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (4U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((8U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (8U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x10U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x10U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x20U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x20U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x40U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x40U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x80U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x80U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x100U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x100U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x200U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x200U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x400U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x400U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x800U & (vlTOPp->io_dmem_resp_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x800U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x1000U & (vlTOPp->io_dmem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x1000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x2000U & (vlTOPp->io_dmem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x2000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x4000U & (vlTOPp->io_dmem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x4000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x8000U & (vlTOPp->io_dmem_resp_bits_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x8000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x10000U & (vlTOPp->io_dmem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x10000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x20000U & (vlTOPp->io_dmem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x20000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x40000U & (vlTOPp->io_dmem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x40000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x80000U & (vlTOPp->io_dmem_resp_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x80000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x100000U & (vlTOPp->io_dmem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x100000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x200000U & (vlTOPp->io_dmem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x200000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x400000U & (vlTOPp->io_dmem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x400000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x800000U & (vlTOPp->io_dmem_resp_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x800000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x1000000U & (vlTOPp->io_dmem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x1000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x2000000U & (vlTOPp->io_dmem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x2000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x4000000U & (vlTOPp->io_dmem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x4000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x8000000U & (vlTOPp->io_dmem_resp_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x8000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x10000000U & (vlTOPp->io_dmem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x10000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x20000000U & (vlTOPp->io_dmem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x20000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x40000000U & (vlTOPp->io_dmem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x40000000U & vlTOPp->io_dmem_resp_bits_data));
    }
    if ((0x80000000U & (vlTOPp->io_dmem_resp_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_resp_bits_data) 
               | (0x80000000U & vlTOPp->io_dmem_resp_bits_data));
    }
}

VL_INLINE_OPT void VTop::_sequent__TOP__4(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_sequent__TOP__4\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__rf__DOT__regfile__v0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__rf__DOT__regfile__v0;
    // Body
    __Vdlyvset__Top__DOT__rf__DOT__regfile__v0 = 0U;
    ++(vlSymsp->__Vcoverage[896]);
    if (vlTOPp->reset) {
        ++(vlSymsp->__Vcoverage[894]);
        vlTOPp->Top__DOT__pc_reg = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[895]);
        if (vlTOPp->Top__DOT__stall) {
            ++(vlSymsp->__Vcoverage[893]);
        } else {
            ++(vlSymsp->__Vcoverage[892]);
            if (vlTOPp->Top__DOT__br_taken) {
                ++(vlSymsp->__Vcoverage[890]);
                vlTOPp->Top__DOT__pc_reg = (IData)(vlTOPp->Top__DOT___T_187);
            } else {
                ++(vlSymsp->__Vcoverage[891]);
                if ((7U == (IData)(vlTOPp->Top__DOT__idu_io_br_type))) {
                    ++(vlSymsp->__Vcoverage[888]);
                    vlTOPp->Top__DOT__pc_reg = (IData)(vlTOPp->Top__DOT___T_188);
                } else {
                    ++(vlSymsp->__Vcoverage[889]);
                    if ((8U == (IData)(vlTOPp->Top__DOT__idu_io_br_type))) {
                        ++(vlSymsp->__Vcoverage[886]);
                        vlTOPp->Top__DOT__pc_reg = (IData)(vlTOPp->Top__DOT___T_189);
                    } else {
                        ++(vlSymsp->__Vcoverage[887]);
                        vlTOPp->Top__DOT__pc_reg = vlTOPp->Top__DOT__pc_4;
                    }
                }
            }
        }
    }
    ++(vlSymsp->__Vcoverage[1195]);
    if (vlTOPp->Top__DOT__idu_io_rf_wen) {
        ++(vlSymsp->__Vcoverage[1193]);
        __Vdlyvval__Top__DOT__rf__DOT__regfile__v0 
            = vlTOPp->Top__DOT__rf_io_wdata;
        __Vdlyvset__Top__DOT__rf__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0 
            = (0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                        >> 7U));
    } else {
        ++(vlSymsp->__Vcoverage[1194]);
    }
    if (__Vdlyvset__Top__DOT__rf__DOT__regfile__v0) {
        vlTOPp->Top__DOT__rf__DOT__regfile[__Vdlyvdim0__Top__DOT__rf__DOT__regfile__v0] 
            = __Vdlyvval__Top__DOT__rf__DOT__regfile__v0;
    }
    vlTOPp->Top__DOT__pc_4 = ((IData)(4U) + vlTOPp->Top__DOT__pc_reg);
    if ((2U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
               ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[523]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffffdU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (2U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((4U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
               ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[524]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffffbU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (4U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((8U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
               ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[525]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffff7U 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (8U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x10U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                  ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[526]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffffefU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x10U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x20U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                  ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[527]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffffdfU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x20U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x40U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                  ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[528]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffffbfU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x40U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x80U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                  ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[529]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffff7fU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x80U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x100U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                   ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[530]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffeffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x100U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x200U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                   ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[531]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffdffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x200U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x400U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                   ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[532]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffffbffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x400U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x800U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                   ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[533]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffff7ffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x800U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x1000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                    ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[534]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffefffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x1000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x2000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                    ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[535]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffdfffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x2000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x4000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                    ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[536]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffffbfffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x4000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x8000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                    ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[537]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffff7fffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x8000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x10000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                     ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[538]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffeffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x10000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x20000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                     ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[539]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffdffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x20000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x40000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                     ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[540]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfffbffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x40000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x80000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                     ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[541]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfff7ffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x80000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x100000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                      ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[542]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffefffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x100000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x200000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                      ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[543]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffdfffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x200000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x400000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                      ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[544]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xffbfffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x400000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x800000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                      ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[545]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xff7fffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x800000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x1000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                       ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[546]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfeffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x1000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x2000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                       ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[547]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfdffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x2000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x4000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                       ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[548]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xfbffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x4000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x8000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                       ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[549]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xf7ffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x8000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x10000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                        ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[550]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xefffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x10000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x20000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                        ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[551]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xdfffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x20000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x40000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                        ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[552]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0xbfffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x40000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((0x80000000U & (((IData)(4U) + vlTOPp->Top__DOT__pc_reg) 
                        ^ vlTOPp->Top__DOT____Vtogcov__pc_4))) {
        ++(vlSymsp->__Vcoverage[553]);
        vlTOPp->Top__DOT____Vtogcov__pc_4 = ((0x7fffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__pc_4) 
                                             | (0x80000000U 
                                                & ((IData)(4U) 
                                                   + vlTOPp->Top__DOT__pc_reg)));
    }
    if ((1U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[491]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (1U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((2U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[492]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (2U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((4U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[493]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (4U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((8U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[494]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (8U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x10U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[495]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x10U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x20U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[496]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x20U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x40U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[497]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x40U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x80U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[498]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x80U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x100U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[499]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x100U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x200U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[500]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x200U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x400U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[501]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x400U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x800U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[502]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x800U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[503]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x1000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[504]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x2000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[505]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x4000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[506]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x8000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[507]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x10000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[508]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x20000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[509]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x40000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[510]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x80000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[511]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x100000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[512]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x200000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[513]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x400000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[514]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x800000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[515]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x1000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[516]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x2000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[517]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x4000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[518]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x8000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[519]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x10000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[520]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x20000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[521]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x40000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__pc_reg ^ vlTOPp->Top__DOT____Vtogcov__pc_reg))) {
        ++(vlSymsp->__Vcoverage[522]);
        vlTOPp->Top__DOT____Vtogcov__pc_reg = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__pc_reg) 
                                               | (0x80000000U 
                                                  & vlTOPp->Top__DOT__pc_reg));
    }
    vlTOPp->io_imem_req_bits_addr = vlTOPp->Top__DOT__pc_reg;
    vlTOPp->io_debug_io_PC = vlTOPp->Top__DOT__pc_reg;
    if ((1U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (1U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((2U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (2U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((4U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (4U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((8U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (8U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x10U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x10U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x20U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x20U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x40U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x40U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x80U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x80U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x100U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x100U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x200U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x200U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x400U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x400U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x800U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x800U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x1000U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x1000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x2000U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x2000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x4000U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x4000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x8000U & (vlTOPp->io_imem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x8000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x10000U & (vlTOPp->io_imem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x10000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x20000U & (vlTOPp->io_imem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x20000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x40000U & (vlTOPp->io_imem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x40000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x80000U & (vlTOPp->io_imem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x80000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x100000U & (vlTOPp->io_imem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x100000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x200000U & (vlTOPp->io_imem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x200000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x400000U & (vlTOPp->io_imem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x400000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x800000U & (vlTOPp->io_imem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x800000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x1000000U & (vlTOPp->io_imem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x1000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x2000000U & (vlTOPp->io_imem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x2000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x4000000U & (vlTOPp->io_imem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x4000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x8000000U & (vlTOPp->io_imem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x8000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x10000000U & (vlTOPp->io_imem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x10000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x20000000U & (vlTOPp->io_imem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x20000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x40000000U & (vlTOPp->io_imem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x40000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((0x80000000U & (vlTOPp->io_imem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_imem_req_bits_addr) 
               | (0x80000000U & vlTOPp->io_imem_req_bits_addr));
    }
    if ((1U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (1U & vlTOPp->io_debug_io_PC));
    }
    if ((2U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (2U & vlTOPp->io_debug_io_PC));
    }
    if ((4U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (4U & vlTOPp->io_debug_io_PC));
    }
    if ((8U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (8U & vlTOPp->io_debug_io_PC));
    }
    if ((0x10U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x10U & vlTOPp->io_debug_io_PC));
    }
    if ((0x20U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x20U & vlTOPp->io_debug_io_PC));
    }
    if ((0x40U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x40U & vlTOPp->io_debug_io_PC));
    }
    if ((0x80U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x80U & vlTOPp->io_debug_io_PC));
    }
    if ((0x100U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x100U & vlTOPp->io_debug_io_PC));
    }
    if ((0x200U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x200U & vlTOPp->io_debug_io_PC));
    }
    if ((0x400U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x400U & vlTOPp->io_debug_io_PC));
    }
    if ((0x800U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x800U & vlTOPp->io_debug_io_PC));
    }
    if ((0x1000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x1000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x2000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x2000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x4000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x4000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x8000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x8000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x10000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x10000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x20000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x20000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x40000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x40000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x80000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x80000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x100000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x100000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x200000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x200000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x400000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x400000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x800000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x800000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x1000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x1000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x2000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x2000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x4000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x4000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x8000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x8000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x10000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x10000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x20000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x20000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x40000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x40000000U & vlTOPp->io_debug_io_PC));
    }
    if ((0x80000000U & (vlTOPp->io_debug_io_PC ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_PC) 
               | (0x80000000U & vlTOPp->io_debug_io_PC));
    }
}

VL_INLINE_OPT void VTop::_combo__TOP__5(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_combo__TOP__5\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Top__DOT__idu_io_inst = ((IData)(vlTOPp->io_imem_resp_valid)
                                      ? vlTOPp->io_imem_resp_bits_data
                                      : 0x4033U);
    vlTOPp->Top__DOT__idu_io_mem_fcn = ((0x2003U != 
                                         (0x707fU & vlTOPp->Top__DOT__idu_io_inst)) 
                                        & ((3U != (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst)) 
                                           & ((0x4003U 
                                               != (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst)) 
                                              & ((0x5003U 
                                                  != 
                                                  (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst)) 
                                                 & ((0x2023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst)) 
                                                    | ((0x23U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst)) 
                                                       | (0x1023U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))))))));
    if ((1U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[347]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (1U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((2U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[348]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (2U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((4U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[349]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (4U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((8U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[350]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (8U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x10U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[351]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x10U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x20U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[352]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x20U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x40U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[353]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x40U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x80U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[354]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x80U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x100U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[355]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x100U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x200U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[356]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x200U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x400U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[357]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x400U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x800U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[358]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x800U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[359]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x1000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[360]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x2000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[361]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x4000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__idu_io_inst ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[362]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x8000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__idu_io_inst 
                     ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[363]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x10000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__idu_io_inst 
                     ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[364]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x20000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__idu_io_inst 
                     ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[365]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x40000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__idu_io_inst 
                     ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[366]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x80000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__idu_io_inst 
                      ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[367]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x100000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__idu_io_inst 
                      ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[368]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x200000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__idu_io_inst 
                      ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[369]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x400000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__idu_io_inst 
                      ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[370]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x800000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__idu_io_inst 
                       ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[371]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x1000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__idu_io_inst 
                       ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[372]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x2000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__idu_io_inst 
                       ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[373]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x4000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__idu_io_inst 
                       ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[374]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x8000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__idu_io_inst 
                        ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[375]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x10000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__idu_io_inst 
                        ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[376]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x20000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__idu_io_inst 
                        ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[377]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x40000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__idu_io_inst 
                        ^ vlTOPp->Top__DOT____Vtogcov__idu_io_inst))) {
        ++(vlSymsp->__Vcoverage[378]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_inst = 
            ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__idu_io_inst) 
             | (0x80000000U & vlTOPp->Top__DOT__idu_io_inst));
    }
    if ((1U & ((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                         >> 0xfU)) ^ vlTOPp->Top__DOT____Vtogcov__imm_z))) {
        ++(vlSymsp->__Vcoverage[599]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = ((0xfffffffeU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_z) 
                                              | (1U 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0xfU)));
    }
    if ((1U & ((0xfU & (vlTOPp->Top__DOT__idu_io_inst 
                        >> 0x10U)) ^ (vlTOPp->Top__DOT____Vtogcov__imm_z 
                                      >> 1U)))) {
        ++(vlSymsp->__Vcoverage[600]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = ((0xfffffffdU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_z) 
                                              | (2U 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0xfU)));
    }
    if ((1U & ((7U & (vlTOPp->Top__DOT__idu_io_inst 
                      >> 0x11U)) ^ (vlTOPp->Top__DOT____Vtogcov__imm_z 
                                    >> 2U)))) {
        ++(vlSymsp->__Vcoverage[601]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = ((0xfffffffbU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_z) 
                                              | (4U 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0xfU)));
    }
    if ((1U & ((3U & (vlTOPp->Top__DOT__idu_io_inst 
                      >> 0x12U)) ^ (vlTOPp->Top__DOT____Vtogcov__imm_z 
                                    >> 3U)))) {
        ++(vlSymsp->__Vcoverage[602]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = ((0xfffffff7U 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_z) 
                                              | (8U 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0xfU)));
    }
    if ((1U & ((1U & (vlTOPp->Top__DOT__idu_io_inst 
                      >> 0x13U)) ^ (vlTOPp->Top__DOT____Vtogcov__imm_z 
                                    >> 4U)))) {
        ++(vlSymsp->__Vcoverage[603]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = ((0xffffffefU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_z) 
                                              | (0x10U 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0xfU)));
    }
    if ((0x20U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[604]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffffdfU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x40U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[605]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffffbfU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x80U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[606]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffff7fU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x100U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[607]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffffeffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x200U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[608]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffffdffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x400U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[609]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffffbffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x800U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[610]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffff7ffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x1000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[611]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffefffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x2000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[612]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffdfffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x4000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[613]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffffbfffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x8000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[614]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffff7fffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x10000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[615]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffeffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x20000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[616]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffdffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x40000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[617]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfffbffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x80000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[618]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfff7ffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x100000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[619]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffefffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x200000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[620]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffdfffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x400000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[621]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xffbfffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x800000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[622]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xff7fffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x1000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[623]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfeffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x2000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[624]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfdffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x4000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[625]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xfbffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x8000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[626]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xf7ffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x10000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[627]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xefffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x20000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[628]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xdfffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x40000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[629]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0xbfffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    if ((0x80000000U & vlTOPp->Top__DOT____Vtogcov__imm_z)) {
        ++(vlSymsp->__Vcoverage[630]);
        vlTOPp->Top__DOT____Vtogcov__imm_z = (0x7fffffffU 
                                              & vlTOPp->Top__DOT____Vtogcov__imm_z);
    }
    vlTOPp->io_debug_io_waddr = (0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                          >> 7U));
    vlTOPp->Top__DOT__idu_io_mem_msk = ((0x2003U == 
                                         (0x707fU & vlTOPp->Top__DOT__idu_io_inst))
                                         ? 3U : ((3U 
                                                  == 
                                                  (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                                  ? 1U
                                                  : 
                                                 ((0x4003U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 5U
                                                   : 
                                                  ((0x5003U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 6U
                                                    : 
                                                   ((0x2023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 3U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 1U
                                                      : 
                                                     ((0x1023U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 2U
                                                       : 0U)))))));
    vlTOPp->Top__DOT__idu__DOT___T_594 = ((0x6033U 
                                           == (0xfe00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst)) 
                                          | ((0x4033U 
                                              == (0xfe00707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             | ((0x40005033U 
                                                 == 
                                                 (0xfe00707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                | ((0x5033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   | ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      | ((0x67U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         | ((0x63U 
                                                             != 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst)) 
                                                            & ((0x1063U 
                                                                != 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst)) 
                                                               & ((0x5063U 
                                                                   != 
                                                                   (0x707fU 
                                                                    & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                  & ((0x7063U 
                                                                      != 
                                                                      (0x707fU 
                                                                       & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                     & ((0x4063U 
                                                                         != 
                                                                         (0x707fU 
                                                                          & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                        & ((0x6063U 
                                                                            != 
                                                                            (0x707fU 
                                                                             & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                           & ((0x5073U 
                                                                               == 
                                                                               (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                              | ((0x6073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x7073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x1073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x2073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | (0x3073U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)))))))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_636 = ((0x63U != 
                                           (0x707fU 
                                            & vlTOPp->Top__DOT__idu_io_inst)) 
                                          & ((0x1063U 
                                              != (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             & ((0x5063U 
                                                 != 
                                                 (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                & ((0x7063U 
                                                    != 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   & ((0x4063U 
                                                       != 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      & ((0x6063U 
                                                          != 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         & ((0x5073U 
                                                             != 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst)) 
                                                            & ((0x6073U 
                                                                != 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst)) 
                                                               & ((0x7073U 
                                                                   != 
                                                                   (0x707fU 
                                                                    & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                  & ((0x1073U 
                                                                      != 
                                                                      (0x707fU 
                                                                       & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                     & ((0x2073U 
                                                                         != 
                                                                         (0x707fU 
                                                                          & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                        & ((0x3073U 
                                                                            != 
                                                                            (0x707fU 
                                                                             & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                           & ((0x73U 
                                                                               != vlTOPp->Top__DOT__idu_io_inst) 
                                                                              & ((0x30200073U 
                                                                                != vlTOPp->Top__DOT__idu_io_inst) 
                                                                                & ((0x7b200073U 
                                                                                != vlTOPp->Top__DOT__idu_io_inst) 
                                                                                & ((0x100073U 
                                                                                != vlTOPp->Top__DOT__idu_io_inst) 
                                                                                & ((0x10500073U 
                                                                                != vlTOPp->Top__DOT__idu_io_inst) 
                                                                                & ((0x100fU 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                & (0xfU 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst))))))))))))))))))));
    vlTOPp->Top__DOT__imm_b = (((0x800U & (vlTOPp->Top__DOT__idu_io_inst 
                                           >> 0x14U)) 
                                | (0x400U & (vlTOPp->Top__DOT__idu_io_inst 
                                             << 3U))) 
                               | ((0x3f0U & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0x15U)) 
                                  | (0xfU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 8U))));
    vlTOPp->Top__DOT__imm_j = (((0x80000U & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xcU)) 
                                | (0x7f800U & (vlTOPp->Top__DOT__idu_io_inst 
                                               >> 1U))) 
                               | ((0x400U & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xaU)) 
                                  | (0x3ffU & (vlTOPp->Top__DOT__idu_io_inst 
                                               >> 0x15U))));
    vlTOPp->Top__DOT__idu__DOT___T_543 = ((0x5033U 
                                           == (0xfe00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 2U
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x1063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x5063U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x7063U 
                                                         == 
                                                         (0x707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x4063U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x6063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x5073U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 3U
                                                            : 
                                                           ((0x6073U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 3U
                                                             : 
                                                            ((0x7073U 
                                                              == 
                                                              (0x707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 3U
                                                              : 
                                                             ((0x1073U 
                                                               == 
                                                               (0x707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 3U
                                                               : 
                                                              ((0x2073U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 3U
                                                                : 
                                                               ((0x3073U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 3U
                                                                 : 0U)))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_357 = ((0x2033U 
                                           == (0xfe00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x3033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x7033U 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x6033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x4033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x40005033U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x5033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x6fU 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 7U
                                                          : 
                                                         ((0x67U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 8U
                                                           : 
                                                          ((0x63U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 2U
                                                            : 
                                                           ((0x1063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 1U
                                                             : 
                                                            ((0x5063U 
                                                              == 
                                                              (0x707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 3U
                                                              : 
                                                             ((0x7063U 
                                                               == 
                                                               (0x707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 4U
                                                               : 
                                                              ((0x4063U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 5U
                                                                : 
                                                               ((0x6063U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 6U
                                                                 : 0U)))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_495 = ((0x5033U 
                                           == (0xfe00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 5U : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0x10U
                                                      : 
                                                     ((0x1063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0x10U
                                                       : 
                                                      ((0x5063U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0x11U
                                                        : 
                                                       ((0x7063U 
                                                         == 
                                                         (0x707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0x12U
                                                         : 
                                                        ((0x4063U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0x11U
                                                          : 
                                                         ((0x6063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0x12U
                                                           : 
                                                          ((0x5073U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 8U
                                                            : 
                                                           ((0x6073U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 8U
                                                             : 
                                                            ((0x7073U 
                                                              == 
                                                              (0x707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 8U
                                                              : 
                                                             ((0x1073U 
                                                               == 
                                                               (0x707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 8U
                                                               : 
                                                              ((0x2073U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 8U
                                                                : 
                                                               ((0x3073U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 8U
                                                                 : 0U)))))))))))))));
    vlTOPp->Top__DOT__imm_i_sext = ((((0x80000000U 
                                       & vlTOPp->Top__DOT__idu_io_inst)
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | (0xfffU 
                                                 & (vlTOPp->Top__DOT__idu_io_inst 
                                                    >> 0x14U)));
    vlTOPp->Top__DOT__idu__DOT___T_459 = ((0x1013U 
                                           == (0xfc00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 1U : (
                                                   (0x40005013U 
                                                    == 
                                                    (0xfc00707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 1U
                                                    : 
                                                   ((0x5013U 
                                                     == 
                                                     (0xfc00707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 1U
                                                     : 
                                                    ((0x1033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x33U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x40000033U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x2033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x3033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x7033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x6033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0U
                                                             : 
                                                            ((0x40005033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 0U
                                                              : 
                                                             ((0x5033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 0U
                                                               : 
                                                              ((0x6fU 
                                                                == 
                                                                (0x7fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 0U
                                                                : 
                                                               ((0x67U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 1U
                                                                 : 0U)))))))))))))));
    vlTOPp->Top__DOT__imm_s = ((0xfe0U & (vlTOPp->Top__DOT__idu_io_inst 
                                          >> 0x14U)) 
                               | (0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                           >> 7U)));
    vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
        = vlTOPp->Top__DOT__rf__DOT__regfile[(0x1fU 
                                              & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0x14U))];
    vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
        = vlTOPp->Top__DOT__rf__DOT__regfile[(0x1fU 
                                              & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0xfU))];
    vlTOPp->Top__DOT__idu__DOT___T_402 = ((0x6033U 
                                           == (0xfe00707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x4033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x40005033U 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x5033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x67U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x63U 
                                                         == 
                                                         (0x707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x1063U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x5063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x7063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0U
                                                             : 
                                                            ((0x6063U 
                                                              == 
                                                              (0x707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 0U
                                                              : 
                                                             ((0x5073U 
                                                               == 
                                                               (0x707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 2U
                                                               : 
                                                              ((0x6073U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 2U
                                                                : 
                                                               ((0x7073U 
                                                                 == 
                                                                 (0x707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 2U
                                                                 : 0U)))))))))))))));
    if (((IData)(vlTOPp->Top__DOT__idu_io_mem_fcn) 
         ^ vlTOPp->Top__DOT____Vtogcov__idu_io_mem_fcn)) {
        ++(vlSymsp->__Vcoverage[391]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_mem_fcn 
            = vlTOPp->Top__DOT__idu_io_mem_fcn;
    }
    vlTOPp->io_dmem_req_bits_fcn = vlTOPp->Top__DOT__idu_io_mem_fcn;
    if ((1U & ((IData)(vlTOPp->io_debug_io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr 
            = ((0x1eU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr)) 
               | (1U & (IData)(vlTOPp->io_debug_io_waddr)));
    }
    if ((2U & ((IData)(vlTOPp->io_debug_io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr 
            = ((0x1dU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr)) 
               | (2U & (IData)(vlTOPp->io_debug_io_waddr)));
    }
    if ((4U & ((IData)(vlTOPp->io_debug_io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr 
            = ((0x1bU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr)) 
               | (4U & (IData)(vlTOPp->io_debug_io_waddr)));
    }
    if ((8U & ((IData)(vlTOPp->io_debug_io_waddr) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr 
            = ((0x17U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr)) 
               | (8U & (IData)(vlTOPp->io_debug_io_waddr)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_debug_io_waddr) 
                  ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr 
            = ((0xfU & (IData)(vlTOPp->Top__DOT____Vtogcov__io_debug_io_waddr)) 
               | (0x10U & (IData)(vlTOPp->io_debug_io_waddr)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu_io_mem_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk))) {
        ++(vlSymsp->__Vcoverage[392]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk 
            = ((6U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu_io_mem_msk)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu_io_mem_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk))) {
        ++(vlSymsp->__Vcoverage[393]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk 
            = ((5U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu_io_mem_msk)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__idu_io_mem_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk))) {
        ++(vlSymsp->__Vcoverage[394]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk 
            = ((3U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_mem_msk)) 
               | (4U & (IData)(vlTOPp->Top__DOT__idu_io_mem_msk)));
    }
    vlTOPp->io_dmem_req_bits_msk = vlTOPp->Top__DOT__idu_io_mem_msk;
    vlTOPp->Top__DOT__idu__DOT___T_611 = ((0x17U == 
                                           (0x7fU & vlTOPp->Top__DOT__idu_io_inst)) 
                                          | ((0x37U 
                                              == (0x7fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             | ((0x13U 
                                                 == 
                                                 (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                | ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   | ((0x6013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      | ((0x4013U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         | ((0x2013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst)) 
                                                            | ((0x3013U 
                                                                == 
                                                                (0x707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst)) 
                                                               | ((0x1013U 
                                                                   == 
                                                                   (0xfc00707fU 
                                                                    & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                  | ((0x40005013U 
                                                                      == 
                                                                      (0xfc00707fU 
                                                                       & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                     | ((0x5013U 
                                                                         == 
                                                                         (0xfc00707fU 
                                                                          & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                        | ((0x1033U 
                                                                            == 
                                                                            (0xfe00707fU 
                                                                             & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                           | ((0x33U 
                                                                               == 
                                                                               (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                              | ((0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x2033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x3033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | ((0x7033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                | (IData)(vlTOPp->Top__DOT__idu__DOT___T_594))))))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_653 = ((0x2013U 
                                           != (0x707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst)) 
                                          & ((0x3013U 
                                              != (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             & ((0x1013U 
                                                 != 
                                                 (0xfc00707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                & ((0x40005013U 
                                                    != 
                                                    (0xfc00707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   & ((0x5013U 
                                                       != 
                                                       (0xfc00707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      & ((0x1033U 
                                                          != 
                                                          (0xfe00707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         & ((0x33U 
                                                             != 
                                                             (0xfe00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst)) 
                                                            & ((0x40000033U 
                                                                != 
                                                                (0xfe00707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst)) 
                                                               & ((0x2033U 
                                                                   != 
                                                                   (0xfe00707fU 
                                                                    & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                  & ((0x3033U 
                                                                      != 
                                                                      (0xfe00707fU 
                                                                       & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                     & ((0x7033U 
                                                                         != 
                                                                         (0xfe00707fU 
                                                                          & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                        & ((0x6033U 
                                                                            != 
                                                                            (0xfe00707fU 
                                                                             & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                           & ((0x4033U 
                                                                               != 
                                                                               (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                              & ((0x40005033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                & ((0x5033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                & ((0x6fU 
                                                                                != 
                                                                                (0x7fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                & ((0x67U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                                & (IData)(vlTOPp->Top__DOT__idu__DOT___T_636))))))))))))))))));
    if ((1U & ((IData)(vlTOPp->Top__DOT__imm_b) ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[567]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xffeU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__imm_b) ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[568]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xffdU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (2U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__imm_b) ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[569]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xffbU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (4U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__imm_b) ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[570]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xff7U 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (8U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[571]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xfefU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x10U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x20U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[572]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xfdfU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x20U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x40U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[573]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xfbfU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x40U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x80U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[574]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xf7fU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x80U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x100U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[575]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xeffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x100U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x200U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[576]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xdffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x200U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x400U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[577]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0xbffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x400U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    if ((0x800U & ((IData)(vlTOPp->Top__DOT__imm_b) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_b))) {
        ++(vlSymsp->__Vcoverage[578]);
        vlTOPp->Top__DOT____Vtogcov__imm_b = ((0x7ffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_b)) 
                                              | (0x800U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_b)));
    }
    vlTOPp->Top__DOT___T_150 = ((((0x800U & (IData)(vlTOPp->Top__DOT__imm_b))
                                   ? 0x7ffffU : 0U) 
                                 << 0xcU) | (IData)(vlTOPp->Top__DOT__imm_b));
    if ((1U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[579]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffffeU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (1U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((2U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[580]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffffdU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (2U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((4U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[581]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffffbU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (4U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((8U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[582]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffff7U 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (8U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x10U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[583]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfffefU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x10U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x20U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[584]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfffdfU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x20U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x40U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[585]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfffbfU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x40U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x80U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[586]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfff7fU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x80U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x100U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[587]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffeffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x100U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x200U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[588]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffdffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x200U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x400U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[589]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xffbffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x400U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x800U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[590]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xff7ffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x800U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[591]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfefffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x1000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[592]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfdfffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x2000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[593]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xfbfffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x4000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[594]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xf7fffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x8000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[595]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xeffffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x10000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[596]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xdffffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x20000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[597]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0xbffffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x40000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__imm_j ^ vlTOPp->Top__DOT____Vtogcov__imm_j))) {
        ++(vlSymsp->__Vcoverage[598]);
        vlTOPp->Top__DOT____Vtogcov__imm_j = ((0x7ffffU 
                                               & vlTOPp->Top__DOT____Vtogcov__imm_j) 
                                              | (0x80000U 
                                                 & vlTOPp->Top__DOT__imm_j));
    }
    vlTOPp->Top__DOT___T_162 = ((((0x80000U & vlTOPp->Top__DOT__imm_j)
                                   ? 0x7ffU : 0U) << 0x14U) 
                                | vlTOPp->Top__DOT__imm_j);
    vlTOPp->Top__DOT__idu__DOT___T_558 = ((0x4013U 
                                           == (0x707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x2013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x3013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x1013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x5013U 
                                                        == 
                                                        (0xfc00707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x1033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x33U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x40000033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x2033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x3033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0U
                                                             : 
                                                            ((0x7033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 0U
                                                              : 
                                                             ((0x6033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 0U
                                                               : 
                                                              ((0x4033U 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 0U
                                                                : 
                                                               ((0x40005033U 
                                                                 == 
                                                                 (0xfe00707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 0U
                                                                 : (IData)(vlTOPp->Top__DOT__idu__DOT___T_543))))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_372 = ((0x1023U 
                                           == (0x707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x13U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x7013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x6013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x4013U 
                                                         == 
                                                         (0x707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x2013U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x3013U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x1013U 
                                                            == 
                                                            (0xfc00707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x40005013U 
                                                             == 
                                                             (0xfc00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0U
                                                             : 
                                                            ((0x5013U 
                                                              == 
                                                              (0xfc00707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 0U
                                                              : 
                                                             ((0x1033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 0U
                                                               : 
                                                              ((0x33U 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 0U
                                                                : 
                                                               ((0x40000033U 
                                                                 == 
                                                                 (0xfe00707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 0U
                                                                 : (IData)(vlTOPp->Top__DOT__idu__DOT___T_357))))))))))))))));
    vlTOPp->Top__DOT__idu__DOT___T_510 = ((0x4013U 
                                           == (0x707fU 
                                               & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 1U : (
                                                   (0x2013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0x11U
                                                    : 
                                                   ((0x3013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0x12U
                                                     : 
                                                    ((0x1013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 4U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 6U
                                                       : 
                                                      ((0x5013U 
                                                        == 
                                                        (0xfc00707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 5U
                                                        : 
                                                       ((0x1033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 4U
                                                         : 
                                                        ((0x33U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x40000033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0x10U
                                                           : 
                                                          ((0x2033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0x11U
                                                            : 
                                                           ((0x3033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0x12U
                                                             : 
                                                            ((0x7033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 3U
                                                              : 
                                                             ((0x6033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 2U
                                                               : 
                                                              ((0x4033U 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 1U
                                                                : 
                                                               ((0x40005033U 
                                                                 == 
                                                                 (0xfe00707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 6U
                                                                 : (IData)(vlTOPp->Top__DOT__idu__DOT___T_495))))))))))))))));
    if ((1U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[631]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((2U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[632]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((4U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[633]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((8U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[634]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x10U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[635]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x20U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[636]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x40U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[637]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x80U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[638]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x100U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[639]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x200U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[640]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x400U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[641]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x800U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[642]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[643]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[644]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[645]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[646]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[647]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[648]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[649]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__imm_i_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[650]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__imm_i_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[651]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__imm_i_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[652]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__imm_i_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[653]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__imm_i_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[654]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__imm_i_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[655]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__imm_i_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[656]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__imm_i_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[657]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__imm_i_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[658]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__imm_i_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[659]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__imm_i_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[660]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__imm_i_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[661]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__imm_i_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_i_sext))) {
        ++(vlSymsp->__Vcoverage[662]);
        vlTOPp->Top__DOT____Vtogcov__imm_i_sext = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_i_sext) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__imm_i_sext));
    }
    vlTOPp->Top__DOT__idu_io_op2_sel = ((0x2003U == 
                                         (0x707fU & vlTOPp->Top__DOT__idu_io_inst))
                                         ? 1U : ((3U 
                                                  == 
                                                  (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                                  ? 1U
                                                  : 
                                                 ((0x4003U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 1U
                                                   : 
                                                  ((0x5003U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 1U
                                                    : 
                                                   ((0x2023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 2U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 2U
                                                      : 
                                                     ((0x1023U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 2U
                                                       : 
                                                      ((0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 3U
                                                        : 
                                                       ((0x37U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x13U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 1U
                                                          : 
                                                         ((0x7013U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 1U
                                                           : 
                                                          ((0x6013U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 1U
                                                            : 
                                                           ((0x4013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 1U
                                                             : 
                                                            ((0x2013U 
                                                              == 
                                                              (0x707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 1U
                                                              : 
                                                             ((0x3013U 
                                                               == 
                                                               (0x707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 1U
                                                               : (IData)(vlTOPp->Top__DOT__idu__DOT___T_459))))))))))))))));
    if ((1U & ((IData)(vlTOPp->Top__DOT__imm_s) ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[555]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xffeU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (1U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__imm_s) ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[556]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xffdU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (2U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__imm_s) ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[557]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xffbU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (4U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__imm_s) ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[558]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xff7U 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (8U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[559]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xfefU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x10U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x20U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[560]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xfdfU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x20U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x40U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[561]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xfbfU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x40U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x80U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                  ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[562]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xf7fU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x80U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x100U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[563]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xeffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x100U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x200U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[564]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xdffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x200U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x400U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[565]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0xbffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x400U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    if ((0x800U & ((IData)(vlTOPp->Top__DOT__imm_s) 
                   ^ vlTOPp->Top__DOT____Vtogcov__imm_s))) {
        ++(vlSymsp->__Vcoverage[566]);
        vlTOPp->Top__DOT____Vtogcov__imm_s = ((0x7ffU 
                                               & (IData)(vlTOPp->Top__DOT____Vtogcov__imm_s)) 
                                              | (0x800U 
                                                 & (IData)(vlTOPp->Top__DOT__imm_s)));
    }
    vlTOPp->Top__DOT__imm_s_sext = ((((0x800U & (IData)(vlTOPp->Top__DOT__imm_s))
                                       ? 0xfffffU : 0U) 
                                     << 0xcU) | (IData)(vlTOPp->Top__DOT__imm_s));
    if ((1U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1161]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (1U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1162]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (2U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1163]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (4U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1164]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (8U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1165]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffffefU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x10U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1166]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x20U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1167]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x40U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1168]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x80U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1169]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x100U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1170]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x200U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1171]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x400U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1172]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x800U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1173]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffefffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1174]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1175]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1176]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1177]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1178]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1179]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1180]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1181]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffefffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1182]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1183]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1184]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1185]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1186]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1187]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1188]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1189]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xefffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1190]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1191]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data))) {
        ++(vlSymsp->__Vcoverage[1192]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_29_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data));
    }
    vlTOPp->Top__DOT__rf_io_rs2_data = ((0U != (0x1fU 
                                                & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0x14U)))
                                         ? vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data
                                         : 0U);
    if ((1U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1129]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (1U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1130]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (2U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1131]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (4U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
               ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1132]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (8U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1133]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffffefU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x10U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1134]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x20U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1135]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x40U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                  ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1136]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x80U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1137]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x100U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1138]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x200U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1139]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x400U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                   ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1140]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x800U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1141]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffefffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1142]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1143]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                    ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1144]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1145]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1146]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1147]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                     ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1148]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1149]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffefffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1150]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1151]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                      ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1152]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1153]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1154]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1155]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                       ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1156]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1157]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xefffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1158]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1159]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data 
                        ^ vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data))) {
        ++(vlSymsp->__Vcoverage[1160]);
        vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT__rf__DOT____Vtogcov__regfile___05FT_24_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data));
    }
    vlTOPp->Top__DOT__rf_io_rs1_data = ((0U != (0x1fU 
                                                & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0xfU)))
                                         ? vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data
                                         : 0U);
    vlTOPp->Top__DOT__idu__DOT___T_417 = ((0x13U == 
                                           (0x707fU 
                                            & vlTOPp->Top__DOT__idu_io_inst))
                                           ? 0U : (
                                                   (0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x6013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x4013U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x3013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x1013U 
                                                         == 
                                                         (0xfc00707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x40005013U 
                                                          == 
                                                          (0xfc00707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x5013U 
                                                           == 
                                                           (0xfc00707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x1033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x33U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 0U
                                                             : 
                                                            ((0x40000033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlTOPp->Top__DOT__idu_io_inst))
                                                              ? 0U
                                                              : 
                                                             ((0x2033U 
                                                               == 
                                                               (0xfe00707fU 
                                                                & vlTOPp->Top__DOT__idu_io_inst))
                                                               ? 0U
                                                               : 
                                                              ((0x3033U 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                                                ? 0U
                                                                : 
                                                               ((0x7033U 
                                                                 == 
                                                                 (0xfe00707fU 
                                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                                                 ? 0U
                                                                 : (IData)(vlTOPp->Top__DOT__idu__DOT___T_402))))))))))))))));
    if (((IData)(vlTOPp->io_dmem_req_bits_fcn) ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_fcn)) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_fcn 
            = vlTOPp->io_dmem_req_bits_fcn;
    }
    if ((1U & ((IData)(vlTOPp->io_dmem_req_bits_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk 
            = ((6U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk)) 
               | (1U & (IData)(vlTOPp->io_dmem_req_bits_msk)));
    }
    if ((2U & ((IData)(vlTOPp->io_dmem_req_bits_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk 
            = ((5U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk)) 
               | (2U & (IData)(vlTOPp->io_dmem_req_bits_msk)));
    }
    if ((4U & ((IData)(vlTOPp->io_dmem_req_bits_msk) 
               ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk 
            = ((3U & (IData)(vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_msk)) 
               | (4U & (IData)(vlTOPp->io_dmem_req_bits_msk)));
    }
    vlTOPp->Top__DOT__idu_io_rf_wen = ((0x2003U == 
                                        (0x707fU & vlTOPp->Top__DOT__idu_io_inst)) 
                                       | ((3U == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                          | ((0x4003U 
                                              == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             | ((0x5003U 
                                                 == 
                                                 (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                | ((0x2023U 
                                                    != 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   & ((0x23U 
                                                       != 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      & ((0x1023U 
                                                          != 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         & (IData)(vlTOPp->Top__DOT__idu__DOT___T_611))))))));
    vlTOPp->Top__DOT__idu_io_mem_en = ((0x2003U == 
                                        (0x707fU & vlTOPp->Top__DOT__idu_io_inst)) 
                                       | ((3U == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                          | ((0x4003U 
                                              == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                             | ((0x5003U 
                                                 == 
                                                 (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst)) 
                                                | ((0x2023U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst)) 
                                                   | ((0x23U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst)) 
                                                      | ((0x1023U 
                                                          == 
                                                          (0x707fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst)) 
                                                         | ((0x17U 
                                                             != 
                                                             (0x7fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst)) 
                                                            & ((0x37U 
                                                                != 
                                                                (0x7fU 
                                                                 & vlTOPp->Top__DOT__idu_io_inst)) 
                                                               & ((0x13U 
                                                                   != 
                                                                   (0x707fU 
                                                                    & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                  & ((0x7013U 
                                                                      != 
                                                                      (0x707fU 
                                                                       & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                     & ((0x6013U 
                                                                         != 
                                                                         (0x707fU 
                                                                          & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                        & ((0x4013U 
                                                                            != 
                                                                            (0x707fU 
                                                                             & vlTOPp->Top__DOT__idu_io_inst)) 
                                                                           & (IData)(vlTOPp->Top__DOT__idu__DOT___T_653))))))))))))));
    if ((1U & (vlTOPp->Top__DOT___T_150 ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                           >> 1U)))) {
        ++(vlSymsp->__Vcoverage[695]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (2U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 1U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 2U)))) {
        ++(vlSymsp->__Vcoverage[696]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (4U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 2U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 3U)))) {
        ++(vlSymsp->__Vcoverage[697]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (8U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 3U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 4U)))) {
        ++(vlSymsp->__Vcoverage[698]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x10U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 4U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 5U)))) {
        ++(vlSymsp->__Vcoverage[699]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x20U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 5U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 6U)))) {
        ++(vlSymsp->__Vcoverage[700]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x40U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 6U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 7U)))) {
        ++(vlSymsp->__Vcoverage[701]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x80U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 7U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 8U)))) {
        ++(vlSymsp->__Vcoverage[702]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x100U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 8U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 9U)))) {
        ++(vlSymsp->__Vcoverage[703]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x200U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 9U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                                                   >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[704]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x400U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xaU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[705]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x800U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xbU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[706]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x1000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xcU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[707]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x2000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xdU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[708]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x4000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xeU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[709]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x8000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0xfU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[710]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x10000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x10U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[711]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x20000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x11U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[712]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x40000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x12U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[713]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x80000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x13U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[714]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x100000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x14U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[715]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x200000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x15U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[716]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x400000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x16U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[717]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x800000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x17U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[718]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x1000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x18U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[719]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x2000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x19U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[720]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x4000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x1aU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[721]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x8000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x1bU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[722]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x10000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x1cU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[723]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x20000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x1dU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[724]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x40000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_150 >> 0x1eU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_b_sext 
                  >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[725]);
        vlTOPp->Top__DOT____Vtogcov__imm_b_sext = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_b_sext) 
                                                   | (0x80000000U 
                                                      & (vlTOPp->Top__DOT___T_150 
                                                         << 1U)));
    }
    vlTOPp->Top__DOT___T_187 = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->Top__DOT__pc_reg)) 
                                                  + (QData)((IData)(
                                                                    (vlTOPp->Top__DOT___T_150 
                                                                     << 1U)))));
    if ((1U & (vlTOPp->Top__DOT___T_162 ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                           >> 1U)))) {
        ++(vlSymsp->__Vcoverage[726]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (2U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 1U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 2U)))) {
        ++(vlSymsp->__Vcoverage[727]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (4U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 2U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 3U)))) {
        ++(vlSymsp->__Vcoverage[728]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (8U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 3U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 4U)))) {
        ++(vlSymsp->__Vcoverage[729]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x10U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 4U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 5U)))) {
        ++(vlSymsp->__Vcoverage[730]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x20U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 5U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 6U)))) {
        ++(vlSymsp->__Vcoverage[731]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x40U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 6U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 7U)))) {
        ++(vlSymsp->__Vcoverage[732]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x80U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 7U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 8U)))) {
        ++(vlSymsp->__Vcoverage[733]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x100U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 8U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 9U)))) {
        ++(vlSymsp->__Vcoverage[734]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x200U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 9U) ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                                                   >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[735]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x400U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xaU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[736]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x800U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xbU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[737]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x1000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xcU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[738]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x2000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xdU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[739]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x4000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xeU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[740]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x8000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0xfU) ^ 
               (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[741]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x10000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x10U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[742]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x20000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x11U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[743]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x40000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x12U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[744]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x80000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x13U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[745]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x100000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x14U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[746]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x200000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x15U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[747]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x400000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x16U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[748]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x800000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x17U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[749]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x1000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x18U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[750]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x2000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x19U) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[751]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x4000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x1aU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[752]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x8000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x1bU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[753]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x10000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x1cU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[754]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x20000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x1dU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[755]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x40000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    if ((1U & ((vlTOPp->Top__DOT___T_162 >> 0x1eU) 
               ^ (vlTOPp->Top__DOT____Vtogcov__imm_j_sext 
                  >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[756]);
        vlTOPp->Top__DOT____Vtogcov__imm_j_sext = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_j_sext) 
                                                   | (0x80000000U 
                                                      & (vlTOPp->Top__DOT___T_162 
                                                         << 1U)));
    }
    vlTOPp->Top__DOT___T_188 = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->Top__DOT__pc_reg)) 
                                                  + (QData)((IData)(
                                                                    (vlTOPp->Top__DOT___T_162 
                                                                     << 1U)))));
    if ((0x2003U == (0x707fU & vlTOPp->Top__DOT__idu_io_inst))) {
        vlTOPp->Top__DOT__idu_io_wb_sel = 1U;
        vlTOPp->Top__DOT__idu_io_br_type = 0U;
        vlTOPp->Top__DOT__idu__DOT__csignals_4 = 0U;
    } else {
        vlTOPp->Top__DOT__idu_io_wb_sel = ((3U == (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                            ? 1U : 
                                           ((0x4003U 
                                             == (0x707fU 
                                                 & vlTOPp->Top__DOT__idu_io_inst))
                                             ? 1U : 
                                            ((0x5003U 
                                              == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                              ? 1U : 
                                             ((0x2023U 
                                               == (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                               ? 0U
                                               : ((0x23U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 0U
                                                   : 
                                                  ((0x1023U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x13U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x7013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x6013U 
                                                         == 
                                                         (0x707fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : (IData)(vlTOPp->Top__DOT__idu__DOT___T_558))))))))))));
        vlTOPp->Top__DOT__idu_io_br_type = ((3U == 
                                             (0x707fU 
                                              & vlTOPp->Top__DOT__idu_io_inst))
                                             ? 0U : 
                                            ((0x4003U 
                                              == (0x707fU 
                                                  & vlTOPp->Top__DOT__idu_io_inst))
                                              ? 0U : 
                                             ((0x5003U 
                                               == (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                               ? 0U
                                               : ((0x2023U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 0U
                                                   : 
                                                  ((0x23U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : (IData)(vlTOPp->Top__DOT__idu__DOT___T_372))))));
        vlTOPp->Top__DOT__idu__DOT__csignals_4 = ((3U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 0U
                                                   : 
                                                  ((0x4003U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5003U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2023U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x23U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x1023U 
                                                        == 
                                                        (0x707fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x17U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x37U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->Top__DOT__idu_io_inst))
                                                          ? 8U
                                                          : 
                                                         ((0x13U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->Top__DOT__idu_io_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x7013U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->Top__DOT__idu_io_inst))
                                                            ? 3U
                                                            : 
                                                           ((0x6013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->Top__DOT__idu_io_inst))
                                                             ? 2U
                                                             : (IData)(vlTOPp->Top__DOT__idu__DOT___T_510))))))))))));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu_io_op2_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel))) {
        ++(vlSymsp->__Vcoverage[385]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel 
            = ((2U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu_io_op2_sel)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu_io_op2_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel))) {
        ++(vlSymsp->__Vcoverage[386]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel 
            = ((1U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_op2_sel)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu_io_op2_sel)));
    }
    if ((1U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[663]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((2U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[664]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((4U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[665]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((8U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[666]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x10U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[667]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x20U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[668]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x40U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[669]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x80U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[670]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x100U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[671]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x200U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[672]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x400U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[673]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x800U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[674]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[675]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[676]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[677]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[678]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[679]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[680]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[681]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__imm_s_sext ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[682]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__imm_s_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[683]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__imm_s_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[684]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__imm_s_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[685]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__imm_s_sext 
                      ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[686]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__imm_s_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[687]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__imm_s_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[688]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__imm_s_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[689]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__imm_s_sext 
                       ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[690]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__imm_s_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[691]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__imm_s_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[692]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__imm_s_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[693]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__imm_s_sext 
                        ^ vlTOPp->Top__DOT____Vtogcov__imm_s_sext))) {
        ++(vlSymsp->__Vcoverage[694]);
        vlTOPp->Top__DOT____Vtogcov__imm_s_sext = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__imm_s_sext) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__imm_s_sext));
    }
    if ((1U & (vlTOPp->Top__DOT__rf_io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[427]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (1U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf_io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[428]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (2U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf_io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[429]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (4U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf_io_rs2_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[430]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (8U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[431]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x10U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[432]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x20U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[433]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x40U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[434]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x80U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[435]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x100U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[436]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x200U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[437]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x400U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[438]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x800U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[439]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[440]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[441]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[442]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[443]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[444]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[445]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[446]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[447]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[448]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[449]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[450]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[451]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[452]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[453]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[454]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[455]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[456]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[457]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf_io_rs2_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data))) {
        ++(vlSymsp->__Vcoverage[458]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs2_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf_io_rs2_data));
    }
    vlTOPp->io_dmem_req_bits_data = vlTOPp->Top__DOT__rf_io_rs2_data;
    vlTOPp->Top__DOT__alu_io_in2 = ((0U == (IData)(vlTOPp->Top__DOT__idu_io_op2_sel))
                                     ? vlTOPp->Top__DOT__rf_io_rs2_data
                                     : ((1U == (IData)(vlTOPp->Top__DOT__idu_io_op2_sel))
                                         ? vlTOPp->Top__DOT__imm_i_sext
                                         : ((2U == (IData)(vlTOPp->Top__DOT__idu_io_op2_sel))
                                             ? vlTOPp->Top__DOT__imm_s_sext
                                             : ((3U 
                                                 == (IData)(vlTOPp->Top__DOT__idu_io_op2_sel))
                                                 ? vlTOPp->Top__DOT__pc_reg
                                                 : vlTOPp->Top__DOT__rf_io_rs2_data))));
    if ((1U & (vlTOPp->Top__DOT__rf_io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[395]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (1U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((2U & (vlTOPp->Top__DOT__rf_io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[396]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (2U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((4U & (vlTOPp->Top__DOT__rf_io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[397]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (4U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((8U & (vlTOPp->Top__DOT__rf_io_rs1_data ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[398]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (8U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[399]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x10U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[400]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x20U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[401]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x40U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                  ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[402]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x80U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[403]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x100U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[404]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x200U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[405]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x400U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                   ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[406]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x800U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[407]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x1000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[408]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x2000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[409]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x4000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                    ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[410]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x8000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[411]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x10000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[412]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x20000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[413]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x40000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[414]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x80000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[415]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x100000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[416]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x200000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[417]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x400000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[418]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x800000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[419]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x1000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[420]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x2000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[421]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x4000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[422]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x8000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[423]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x10000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[424]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x20000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[425]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x40000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf_io_rs1_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data))) {
        ++(vlSymsp->__Vcoverage[426]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_rs1_data) 
               | (0x80000000U & vlTOPp->Top__DOT__rf_io_rs1_data));
    }
    vlTOPp->Top__DOT___T_189 = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->Top__DOT__rf_io_rs1_data)) 
                                                  + (QData)((IData)(vlTOPp->Top__DOT__imm_i_sext))));
    vlTOPp->Top__DOT__idu_io_op1_sel = ((0x2003U == 
                                         (0x707fU & vlTOPp->Top__DOT__idu_io_inst))
                                         ? 0U : ((3U 
                                                  == 
                                                  (0x707fU 
                                                   & vlTOPp->Top__DOT__idu_io_inst))
                                                  ? 0U
                                                  : 
                                                 ((0x4003U 
                                                   == 
                                                   (0x707fU 
                                                    & vlTOPp->Top__DOT__idu_io_inst))
                                                   ? 0U
                                                   : 
                                                  ((0x5003U 
                                                    == 
                                                    (0x707fU 
                                                     & vlTOPp->Top__DOT__idu_io_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x2023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlTOPp->Top__DOT__idu_io_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x707fU 
                                                       & vlTOPp->Top__DOT__idu_io_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x1023U 
                                                       == 
                                                       (0x707fU 
                                                        & vlTOPp->Top__DOT__idu_io_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->Top__DOT__idu_io_inst))
                                                        ? 1U
                                                        : 
                                                       ((0x37U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->Top__DOT__idu_io_inst))
                                                         ? 1U
                                                         : (IData)(vlTOPp->Top__DOT__idu__DOT___T_417))))))))));
    if (((IData)(vlTOPp->Top__DOT__idu_io_rf_wen) ^ vlTOPp->Top__DOT____Vtogcov__idu_io_rf_wen)) {
        ++(vlSymsp->__Vcoverage[389]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_rf_wen 
            = vlTOPp->Top__DOT__idu_io_rf_wen;
    }
    vlTOPp->io_debug_io_wen = vlTOPp->Top__DOT__idu_io_rf_wen;
    if (((IData)(vlTOPp->Top__DOT__idu_io_mem_en) ^ vlTOPp->Top__DOT____Vtogcov__idu_io_mem_en)) {
        ++(vlSymsp->__Vcoverage[390]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_mem_en 
            = vlTOPp->Top__DOT__idu_io_mem_en;
    }
    vlTOPp->io_dmem_req_valid = vlTOPp->Top__DOT__idu_io_mem_en;
    vlTOPp->Top__DOT___T_111 = (1U & (((IData)(vlTOPp->Top__DOT__idu_io_mem_en) 
                                       & (IData)(vlTOPp->io_dmem_resp_valid)) 
                                      | (~ (IData)(vlTOPp->Top__DOT__idu_io_mem_en))));
    if ((1U & ((IData)(vlTOPp->Top__DOT___T_187) ^ vlTOPp->Top__DOT____Vtogcov__br_target))) {
        ++(vlSymsp->__Vcoverage[757]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffffeU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->Top__DOT___T_187)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 1U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[758]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffffdU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (2U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 1U)) 
                                                        << 1U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 2U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 2U)))) {
        ++(vlSymsp->__Vcoverage[759]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffffbU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (4U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 2U)) 
                                                        << 2U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 3U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 3U)))) {
        ++(vlSymsp->__Vcoverage[760]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffff7U 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (8U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 3U)) 
                                                        << 3U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 4U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 4U)))) {
        ++(vlSymsp->__Vcoverage[761]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffffefU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x10U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 4U)) 
                                                        << 4U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 5U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 5U)))) {
        ++(vlSymsp->__Vcoverage[762]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffffdfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x20U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 5U)) 
                                                        << 5U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 6U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 6U)))) {
        ++(vlSymsp->__Vcoverage[763]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffffbfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x40U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 6U)) 
                                                        << 6U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 7U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 7U)))) {
        ++(vlSymsp->__Vcoverage[764]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffff7fU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x80U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 7U)) 
                                                        << 7U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 8U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 8U)))) {
        ++(vlSymsp->__Vcoverage[765]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffeffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x100U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 8U)) 
                                                        << 8U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 9U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 9U)))) {
        ++(vlSymsp->__Vcoverage[766]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffdffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x200U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 9U)) 
                                                        << 9U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xaU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[767]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffffbffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x400U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xaU)) 
                                                        << 0xaU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xbU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[768]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffff7ffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x800U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xbU)) 
                                                        << 0xbU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xcU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[769]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffefffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x1000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xcU)) 
                                                        << 0xcU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xdU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[770]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffdfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x2000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xdU)) 
                                                        << 0xdU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xeU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[771]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffffbfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x4000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xeU)) 
                                                        << 0xeU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0xfU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[772]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffff7fffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x8000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0xfU)) 
                                                        << 0xfU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x10U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[773]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffeffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x10000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x10U)) 
                                                        << 0x10U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x11U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[774]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffdffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x20000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x11U)) 
                                                        << 0x11U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x12U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[775]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfffbffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x40000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x12U)) 
                                                        << 0x12U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x13U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[776]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfff7ffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x80000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x13U)) 
                                                        << 0x13U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x14U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[777]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffefffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x100000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x14U)) 
                                                        << 0x14U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x15U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[778]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffdfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x200000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x15U)) 
                                                        << 0x15U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x16U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[779]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xffbfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x400000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x16U)) 
                                                        << 0x16U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x17U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[780]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xff7fffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x800000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x17U)) 
                                                        << 0x17U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x18U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[781]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfeffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x1000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x18U)) 
                                                        << 0x18U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x19U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[782]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfdffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x2000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x19U)) 
                                                        << 0x19U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1aU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[783]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xfbffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x4000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1aU)) 
                                                        << 0x1aU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1bU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[784]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xf7ffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x8000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1bU)) 
                                                        << 0x1bU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1cU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[785]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xefffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x10000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1cU)) 
                                                        << 0x1cU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1dU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[786]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xdfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x20000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1dU)) 
                                                        << 0x1dU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1eU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[787]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0xbfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x40000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1eU)) 
                                                        << 0x1eU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_187 >> 0x1fU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__br_target 
                  >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[788]);
        vlTOPp->Top__DOT____Vtogcov__br_target = ((0x7fffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__br_target) 
                                                  | (0x80000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_187 
                                                                 >> 0x1fU)) 
                                                        << 0x1fU)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT___T_188) ^ vlTOPp->Top__DOT____Vtogcov__jmp_target))) {
        ++(vlSymsp->__Vcoverage[789]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (1U 
                                                      & (IData)(vlTOPp->Top__DOT___T_188)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 1U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[790]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (2U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 1U)) 
                                                         << 1U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 2U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 2U)))) {
        ++(vlSymsp->__Vcoverage[791]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (4U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 2U)) 
                                                         << 2U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 3U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 3U)))) {
        ++(vlSymsp->__Vcoverage[792]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (8U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 3U)) 
                                                         << 3U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 4U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 4U)))) {
        ++(vlSymsp->__Vcoverage[793]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x10U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 4U)) 
                                                         << 4U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 5U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 5U)))) {
        ++(vlSymsp->__Vcoverage[794]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x20U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 5U)) 
                                                         << 5U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 6U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 6U)))) {
        ++(vlSymsp->__Vcoverage[795]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x40U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 6U)) 
                                                         << 6U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 7U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 7U)))) {
        ++(vlSymsp->__Vcoverage[796]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x80U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 7U)) 
                                                         << 7U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 8U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 8U)))) {
        ++(vlSymsp->__Vcoverage[797]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x100U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 8U)) 
                                                         << 8U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 9U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 9U)))) {
        ++(vlSymsp->__Vcoverage[798]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x200U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 9U)) 
                                                         << 9U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xaU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[799]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x400U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xaU)) 
                                                         << 0xaU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xbU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[800]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x800U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xbU)) 
                                                         << 0xbU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xcU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[801]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x1000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xcU)) 
                                                         << 0xcU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xdU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[802]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x2000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xdU)) 
                                                         << 0xdU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xeU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[803]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x4000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xeU)) 
                                                         << 0xeU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0xfU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[804]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x8000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0xfU)) 
                                                         << 0xfU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x10U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[805]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x10000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x10U)) 
                                                         << 0x10U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x11U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[806]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x20000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x11U)) 
                                                         << 0x11U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x12U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[807]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x40000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x12U)) 
                                                         << 0x12U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x13U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[808]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x80000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x13U)) 
                                                         << 0x13U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x14U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[809]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x100000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x14U)) 
                                                         << 0x14U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x15U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[810]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x200000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x15U)) 
                                                         << 0x15U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x16U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[811]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x400000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x16U)) 
                                                         << 0x16U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x17U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[812]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x800000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x17U)) 
                                                         << 0x17U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x18U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[813]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x1000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x18U)) 
                                                         << 0x18U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x19U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[814]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x2000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x19U)) 
                                                         << 0x19U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1aU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[815]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x4000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1aU)) 
                                                         << 0x1aU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1bU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[816]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x8000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1bU)) 
                                                         << 0x1bU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1cU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[817]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x10000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1cU)) 
                                                         << 0x1cU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1dU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[818]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x20000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1dU)) 
                                                         << 0x1dU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1eU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[819]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x40000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1eU)) 
                                                         << 0x1eU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_188 >> 0x1fU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jmp_target 
                  >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[820]);
        vlTOPp->Top__DOT____Vtogcov__jmp_target = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__jmp_target) 
                                                   | (0x80000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->Top__DOT___T_188 
                                                                  >> 0x1fU)) 
                                                         << 0x1fU)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu_io_wb_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel))) {
        ++(vlSymsp->__Vcoverage[387]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel 
            = ((2U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu_io_wb_sel)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu_io_wb_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel))) {
        ++(vlSymsp->__Vcoverage[388]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel 
            = ((1U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_wb_sel)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu_io_wb_sel)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu_io_br_type) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_br_type))) {
        ++(vlSymsp->__Vcoverage[379]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_br_type 
            = ((0xeU & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_br_type)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu_io_br_type)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu_io_br_type) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_br_type))) {
        ++(vlSymsp->__Vcoverage[380]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_br_type 
            = ((0xdU & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_br_type)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu_io_br_type)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__idu_io_br_type) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_br_type))) {
        ++(vlSymsp->__Vcoverage[381]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_br_type 
            = ((0xbU & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_br_type)) 
               | (4U & (IData)(vlTOPp->Top__DOT__idu_io_br_type)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__idu_io_br_type) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_br_type))) {
        ++(vlSymsp->__Vcoverage[382]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_br_type 
            = ((7U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_br_type)) 
               | (8U & (IData)(vlTOPp->Top__DOT__idu_io_br_type)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4))) {
        ++(vlSymsp->__Vcoverage[1124]);
        vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4 
            = ((0x1eU & (IData)(vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4))) {
        ++(vlSymsp->__Vcoverage[1125]);
        vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4 
            = ((0x1dU & (IData)(vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4))) {
        ++(vlSymsp->__Vcoverage[1126]);
        vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4 
            = ((0x1bU & (IData)(vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4)) 
               | (4U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4))) {
        ++(vlSymsp->__Vcoverage[1127]);
        vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4 
            = ((0x17U & (IData)(vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4)) 
               | (8U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
                  ^ vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4))) {
        ++(vlSymsp->__Vcoverage[1128]);
        vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4 
            = ((0xfU & (IData)(vlTOPp->Top__DOT__idu__DOT____Vtogcov__csignals_4)) 
               | (0x10U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x3eU & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x3dU & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((4U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x3bU & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (4U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((8U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
               ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x37U & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (8U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((0x10U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
                  ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x2fU & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (0x10U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((0x20U & ((IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4) 
                  ^ vlTOPp->Top__DOT____Vtogcov__alu_io_opcode))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_opcode 
            = ((0x1fU & (IData)(vlTOPp->Top__DOT____Vtogcov__alu_io_opcode)) 
               | (0x20U & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4)));
    }
    if ((1U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (1U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((2U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (2U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((4U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (4U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((8U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (8U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x10U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x10U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x20U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x20U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x40U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x40U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x80U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x80U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x100U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x100U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x200U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x200U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x400U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x400U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x800U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x800U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x1000U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x1000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x2000U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x2000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x4000U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x4000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x8000U & (vlTOPp->io_dmem_req_bits_data ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x8000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x10000U & (vlTOPp->io_dmem_req_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x10000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x20000U & (vlTOPp->io_dmem_req_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x20000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x40000U & (vlTOPp->io_dmem_req_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x40000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x80000U & (vlTOPp->io_dmem_req_bits_data 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x80000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x100000U & (vlTOPp->io_dmem_req_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x100000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x200000U & (vlTOPp->io_dmem_req_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x200000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x400000U & (vlTOPp->io_dmem_req_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x400000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x800000U & (vlTOPp->io_dmem_req_bits_data 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x800000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x1000000U & (vlTOPp->io_dmem_req_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x1000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x2000000U & (vlTOPp->io_dmem_req_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x2000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x4000000U & (vlTOPp->io_dmem_req_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x4000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x8000000U & (vlTOPp->io_dmem_req_bits_data 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x8000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x10000000U & (vlTOPp->io_dmem_req_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x10000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x20000000U & (vlTOPp->io_dmem_req_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x20000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x40000000U & (vlTOPp->io_dmem_req_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x40000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((0x80000000U & (vlTOPp->io_dmem_req_bits_data 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_data) 
               | (0x80000000U & vlTOPp->io_dmem_req_bits_data));
    }
    if ((1U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((2U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((4U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((8U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu_io_in2 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu_io_in2 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu_io_in2 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu_io_in2 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu_io_in2 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu_io_in2 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu_io_in2 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu_io_in2 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu_io_in2 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu_io_in2 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu_io_in2 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu_io_in2 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu_io_in2 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in2))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in2 = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in2) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in2));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT___T_189) ^ vlTOPp->Top__DOT____Vtogcov__jr_target))) {
        ++(vlSymsp->__Vcoverage[821]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffffeU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->Top__DOT___T_189)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 1U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 1U)))) {
        ++(vlSymsp->__Vcoverage[822]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffffdU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (2U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 1U)) 
                                                        << 1U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 2U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 2U)))) {
        ++(vlSymsp->__Vcoverage[823]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffffbU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (4U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 2U)) 
                                                        << 2U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 3U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 3U)))) {
        ++(vlSymsp->__Vcoverage[824]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffff7U 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (8U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 3U)) 
                                                        << 3U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 4U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 4U)))) {
        ++(vlSymsp->__Vcoverage[825]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffffefU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x10U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 4U)) 
                                                        << 4U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 5U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 5U)))) {
        ++(vlSymsp->__Vcoverage[826]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffffdfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x20U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 5U)) 
                                                        << 5U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 6U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 6U)))) {
        ++(vlSymsp->__Vcoverage[827]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffffbfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x40U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 6U)) 
                                                        << 6U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 7U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 7U)))) {
        ++(vlSymsp->__Vcoverage[828]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffff7fU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x80U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 7U)) 
                                                        << 7U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 8U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 8U)))) {
        ++(vlSymsp->__Vcoverage[829]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffeffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x100U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 8U)) 
                                                        << 8U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 9U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 9U)))) {
        ++(vlSymsp->__Vcoverage[830]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffdffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x200U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 9U)) 
                                                        << 9U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xaU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[831]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffffbffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x400U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xaU)) 
                                                        << 0xaU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xbU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[832]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffff7ffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x800U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xbU)) 
                                                        << 0xbU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xcU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[833]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffefffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x1000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xcU)) 
                                                        << 0xcU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xdU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[834]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffdfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x2000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xdU)) 
                                                        << 0xdU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xeU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[835]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffffbfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x4000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xeU)) 
                                                        << 0xeU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0xfU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[836]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffff7fffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x8000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0xfU)) 
                                                        << 0xfU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x10U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[837]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffeffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x10000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x10U)) 
                                                        << 0x10U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x11U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[838]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffdffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x20000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x11U)) 
                                                        << 0x11U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x12U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[839]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfffbffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x40000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x12U)) 
                                                        << 0x12U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x13U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[840]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfff7ffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x80000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x13U)) 
                                                        << 0x13U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x14U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[841]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffefffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x100000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x14U)) 
                                                        << 0x14U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x15U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[842]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffdfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x200000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x15U)) 
                                                        << 0x15U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x16U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[843]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xffbfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x400000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x16U)) 
                                                        << 0x16U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x17U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[844]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xff7fffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x800000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x17U)) 
                                                        << 0x17U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x18U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[845]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfeffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x1000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x18U)) 
                                                        << 0x18U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x19U)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[846]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfdffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x2000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x19U)) 
                                                        << 0x19U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1aU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[847]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xfbffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x4000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1aU)) 
                                                        << 0x1aU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1bU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[848]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xf7ffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x8000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1bU)) 
                                                        << 0x1bU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1cU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[849]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xefffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x10000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1cU)) 
                                                        << 0x1cU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1dU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[850]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xdfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x20000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1dU)) 
                                                        << 0x1dU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1eU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[851]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0xbfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x40000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1eU)) 
                                                        << 0x1eU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT___T_189 >> 0x1fU)) 
               ^ (vlTOPp->Top__DOT____Vtogcov__jr_target 
                  >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[852]);
        vlTOPp->Top__DOT____Vtogcov__jr_target = ((0x7fffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__jr_target) 
                                                  | (0x80000000U 
                                                     & ((IData)(
                                                                (vlTOPp->Top__DOT___T_189 
                                                                 >> 0x1fU)) 
                                                        << 0x1fU)));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__idu_io_op1_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel))) {
        ++(vlSymsp->__Vcoverage[383]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel 
            = ((2U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel)) 
               | (1U & (IData)(vlTOPp->Top__DOT__idu_io_op1_sel)));
    }
    if ((2U & ((IData)(vlTOPp->Top__DOT__idu_io_op1_sel) 
               ^ vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel))) {
        ++(vlSymsp->__Vcoverage[384]);
        vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel 
            = ((1U & (IData)(vlTOPp->Top__DOT____Vtogcov__idu_io_op1_sel)) 
               | (2U & (IData)(vlTOPp->Top__DOT__idu_io_op1_sel)));
    }
    vlTOPp->Top__DOT__alu_io_in1 = ((0U == (IData)(vlTOPp->Top__DOT__idu_io_op1_sel))
                                     ? vlTOPp->Top__DOT__rf_io_rs1_data
                                     : ((1U == (IData)(vlTOPp->Top__DOT__idu_io_op1_sel))
                                         ? (0xfffff000U 
                                            & vlTOPp->Top__DOT__idu_io_inst)
                                         : ((2U == (IData)(vlTOPp->Top__DOT__idu_io_op1_sel))
                                             ? (0x1fU 
                                                & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0xfU))
                                             : vlTOPp->Top__DOT__rf_io_rs1_data)));
    if (((IData)(vlTOPp->io_debug_io_wen) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wen)) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wen 
            = vlTOPp->io_debug_io_wen;
    }
    if (((IData)(vlTOPp->io_dmem_req_valid) ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_valid)) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_valid 
            = vlTOPp->io_dmem_req_valid;
    }
    vlTOPp->Top__DOT__stall = (1U & ((~ (IData)(vlTOPp->io_imem_resp_valid)) 
                                     | (~ (IData)(vlTOPp->Top__DOT___T_111))));
    vlTOPp->io_debug_io_stall = (1U & ((~ (IData)(vlTOPp->io_imem_resp_valid)) 
                                       | (~ (IData)(vlTOPp->Top__DOT___T_111))));
    if ((1U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((2U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((4U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((8U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu_io_in1 ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu_io_in1 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[270]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu_io_in1 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu_io_in1 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu_io_in1 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu_io_in1 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu_io_in1 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu_io_in1 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu_io_in1 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu_io_in1 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu_io_in1 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu_io_in1 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu_io_in1 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_in1))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_in1 = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_in1) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__alu_io_in1));
    }
    vlTOPp->Top__DOT__alu__DOT__or_result = (vlTOPp->Top__DOT__alu_io_in1 
                                             | vlTOPp->Top__DOT__alu_io_in2);
    vlTOPp->Top__DOT__alu__DOT__and_result = (vlTOPp->Top__DOT__alu_io_in1 
                                              & vlTOPp->Top__DOT__alu_io_in2);
    vlTOPp->Top__DOT__alu__DOT___T_23 = (0x7fffffffffffffffULL 
                                         & ((QData)((IData)(vlTOPp->Top__DOT__alu_io_in1)) 
                                            << (0x1fU 
                                                & vlTOPp->Top__DOT__alu_io_in2)));
    vlTOPp->Top__DOT__alu__DOT___T_25 = VL_SHIFTRS_III(32,32,5, vlTOPp->Top__DOT__alu_io_in1, 
                                                       (0x1fU 
                                                        & vlTOPp->Top__DOT__alu_io_in2));
    vlTOPp->Top__DOT__alu__DOT__srl_result = (vlTOPp->Top__DOT__alu_io_in1 
                                              >> (0x1fU 
                                                  & vlTOPp->Top__DOT__alu_io_in2));
    vlTOPp->Top__DOT__alu__DOT__xor_result = (vlTOPp->Top__DOT__alu_io_in1 
                                              ^ vlTOPp->Top__DOT__alu_io_in2);
    vlTOPp->Top__DOT__alu__DOT__add_result = (0x1ffffffffULL 
                                              & ((QData)((IData)(vlTOPp->Top__DOT__alu_io_in1)) 
                                                 + (QData)((IData)(
                                                                   ((0x10U 
                                                                     & (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                                     ? 
                                                                    ((IData)(1U) 
                                                                     + 
                                                                     (~ vlTOPp->Top__DOT__alu_io_in2))
                                                                     : vlTOPp->Top__DOT__alu_io_in2)))));
    if (((IData)(vlTOPp->Top__DOT__stall) ^ vlTOPp->Top__DOT____Vtogcov__stall)) {
        ++(vlSymsp->__Vcoverage[554]);
        vlTOPp->Top__DOT____Vtogcov__stall = vlTOPp->Top__DOT__stall;
    }
    if (((IData)(vlTOPp->io_debug_io_stall) ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_stall)) {
        ++(vlSymsp->__Vcoverage[243]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_stall 
            = vlTOPp->io_debug_io_stall;
    }
    if ((1U & (vlTOPp->Top__DOT__alu__DOT__or_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[962]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (1U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((2U & (vlTOPp->Top__DOT__alu__DOT__or_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[963]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (2U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((4U & (vlTOPp->Top__DOT__alu__DOT__or_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[964]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (4U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((8U & (vlTOPp->Top__DOT__alu__DOT__or_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[965]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (8U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[966]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x10U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[967]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x20U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[968]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x40U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[969]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x80U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[970]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x100U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[971]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x200U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[972]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x400U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[973]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x800U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[974]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x1000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[975]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x2000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[976]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x4000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[977]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x8000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[978]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x10000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[979]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x20000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[980]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x40000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[981]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x80000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[982]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x100000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[983]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x200000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[984]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x400000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[985]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x800000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[986]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x1000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[987]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x2000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[988]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x4000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[989]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x8000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[990]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x10000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[991]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x20000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[992]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x40000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu__DOT__or_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[993]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__or_result) 
               | (0x80000000U & vlTOPp->Top__DOT__alu__DOT__or_result));
    }
    if ((1U & (vlTOPp->Top__DOT__alu__DOT__and_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[994]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (1U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((2U & (vlTOPp->Top__DOT__alu__DOT__and_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[995]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (2U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((4U & (vlTOPp->Top__DOT__alu__DOT__and_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[996]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (4U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((8U & (vlTOPp->Top__DOT__alu__DOT__and_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[997]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (8U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[998]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x10U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[999]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x20U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1000]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x40U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1001]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x80U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1002]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x100U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1003]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x200U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1004]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x400U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1005]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x800U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1006]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x1000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1007]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x2000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1008]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x4000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1009]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x8000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1010]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x10000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1011]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x20000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1012]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x40000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1013]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x80000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1014]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x100000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1015]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x200000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1016]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x400000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1017]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x800000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1018]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x1000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1019]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x2000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1020]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x4000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1021]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x8000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1022]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x10000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1023]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x20000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1024]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x40000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu__DOT__and_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[1025]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__and_result) 
               | (0x80000000U & vlTOPp->Top__DOT__alu__DOT__and_result));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__alu__DOT___T_23) 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result))) {
        ++(vlSymsp->__Vcoverage[1028]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (1U & (IData)(vlTOPp->Top__DOT__alu__DOT___T_23)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 1U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 1U)))) {
        ++(vlSymsp->__Vcoverage[1029]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (2U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                 >> 1U)) << 1U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 2U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 2U)))) {
        ++(vlSymsp->__Vcoverage[1030]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (4U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                 >> 2U)) << 2U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 3U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 3U)))) {
        ++(vlSymsp->__Vcoverage[1031]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (8U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                 >> 3U)) << 3U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 4U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 4U)))) {
        ++(vlSymsp->__Vcoverage[1032]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x10U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                    >> 4U)) << 4U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 5U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 5U)))) {
        ++(vlSymsp->__Vcoverage[1033]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x20U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                    >> 5U)) << 5U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 6U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 6U)))) {
        ++(vlSymsp->__Vcoverage[1034]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x40U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                    >> 6U)) << 6U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 7U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 7U)))) {
        ++(vlSymsp->__Vcoverage[1035]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x80U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                    >> 7U)) << 7U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 8U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 8U)))) {
        ++(vlSymsp->__Vcoverage[1036]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x100U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                     >> 8U)) << 8U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 9U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                   >> 9U)))) {
        ++(vlSymsp->__Vcoverage[1037]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x200U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                     >> 9U)) << 9U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xaU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xaU)))) {
        ++(vlSymsp->__Vcoverage[1038]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x400U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                     >> 0xaU)) << 0xaU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xbU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xbU)))) {
        ++(vlSymsp->__Vcoverage[1039]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x800U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                     >> 0xbU)) << 0xbU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xcU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xcU)))) {
        ++(vlSymsp->__Vcoverage[1040]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x1000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                      >> 0xcU)) << 0xcU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xdU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xdU)))) {
        ++(vlSymsp->__Vcoverage[1041]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x2000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                      >> 0xdU)) << 0xdU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xeU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xeU)))) {
        ++(vlSymsp->__Vcoverage[1042]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x4000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                      >> 0xeU)) << 0xeU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0xfU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                     >> 0xfU)))) {
        ++(vlSymsp->__Vcoverage[1043]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x8000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                      >> 0xfU)) << 0xfU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x10U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x10U)))) {
        ++(vlSymsp->__Vcoverage[1044]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x10000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                       >> 0x10U)) << 0x10U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x11U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x11U)))) {
        ++(vlSymsp->__Vcoverage[1045]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x20000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                       >> 0x11U)) << 0x11U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x12U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x12U)))) {
        ++(vlSymsp->__Vcoverage[1046]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x40000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                       >> 0x12U)) << 0x12U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x13U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x13U)))) {
        ++(vlSymsp->__Vcoverage[1047]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x80000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                       >> 0x13U)) << 0x13U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x14U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x14U)))) {
        ++(vlSymsp->__Vcoverage[1048]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x100000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                        >> 0x14U)) 
                               << 0x14U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x15U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x15U)))) {
        ++(vlSymsp->__Vcoverage[1049]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x200000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                        >> 0x15U)) 
                               << 0x15U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x16U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x16U)))) {
        ++(vlSymsp->__Vcoverage[1050]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x400000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                        >> 0x16U)) 
                               << 0x16U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x17U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x17U)))) {
        ++(vlSymsp->__Vcoverage[1051]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x800000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                        >> 0x17U)) 
                               << 0x17U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x18U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x18U)))) {
        ++(vlSymsp->__Vcoverage[1052]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x1000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                         >> 0x18U)) 
                                << 0x18U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x19U)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x19U)))) {
        ++(vlSymsp->__Vcoverage[1053]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x2000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                         >> 0x19U)) 
                                << 0x19U)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1aU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1aU)))) {
        ++(vlSymsp->__Vcoverage[1054]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x4000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                         >> 0x1aU)) 
                                << 0x1aU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1bU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1bU)))) {
        ++(vlSymsp->__Vcoverage[1055]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x8000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                         >> 0x1bU)) 
                                << 0x1bU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1cU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1cU)))) {
        ++(vlSymsp->__Vcoverage[1056]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x10000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                          >> 0x1cU)) 
                                 << 0x1cU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1dU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1dU)))) {
        ++(vlSymsp->__Vcoverage[1057]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x20000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                          >> 0x1dU)) 
                                 << 0x1dU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1eU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1eU)))) {
        ++(vlSymsp->__Vcoverage[1058]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x40000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                          >> 0x1eU)) 
                                 << 0x1eU)));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                        >> 0x1fU)) ^ (vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
                                      >> 0x1fU)))) {
        ++(vlSymsp->__Vcoverage[1059]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sll_result) 
               | (0x80000000U & ((IData)((vlTOPp->Top__DOT__alu__DOT___T_23 
                                          >> 0x1fU)) 
                                 << 0x1fU)));
    }
    if ((1U & (vlTOPp->Top__DOT__alu__DOT___T_25 ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1060]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (1U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((2U & (vlTOPp->Top__DOT__alu__DOT___T_25 ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1061]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (2U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((4U & (vlTOPp->Top__DOT__alu__DOT___T_25 ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1062]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (4U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((8U & (vlTOPp->Top__DOT__alu__DOT___T_25 ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1063]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (8U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1064]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x10U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1065]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x20U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1066]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x40U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1067]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x80U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1068]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x100U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1069]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x200U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1070]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x400U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1071]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x800U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1072]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x1000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1073]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x2000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1074]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x4000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1075]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x8000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1076]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x10000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1077]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x20000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1078]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x40000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1079]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x80000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1080]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x100000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1081]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x200000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1082]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x400000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1083]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x800000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1084]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x1000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1085]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x2000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1086]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x4000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1087]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x8000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1088]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x10000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1089]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x20000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1090]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x40000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu__DOT___T_25 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result))) {
        ++(vlSymsp->__Vcoverage[1091]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__sra_result) 
               | (0x80000000U & vlTOPp->Top__DOT__alu__DOT___T_25));
    }
    if ((1U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1092]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (1U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((2U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1093]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (2U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((4U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1094]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (4U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((8U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1095]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (8U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1096]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x10U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1097]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x20U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1098]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x40U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1099]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x80U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1100]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x100U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1101]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x200U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1102]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x400U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1103]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x800U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1104]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x1000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1105]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x2000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1106]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x4000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1107]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x8000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1108]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x10000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1109]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x20000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1110]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x40000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1111]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x80000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1112]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x100000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1113]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x200000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1114]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x400000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1115]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x800000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1116]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x1000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1117]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x2000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1118]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x4000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1119]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x8000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1120]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x10000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1121]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x20000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1122]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x40000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu__DOT__srl_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result))) {
        ++(vlSymsp->__Vcoverage[1123]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__srl_result) 
               | (0x80000000U & vlTOPp->Top__DOT__alu__DOT__srl_result));
    }
    if ((1U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[930]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffffeU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (1U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((2U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[931]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffffdU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (2U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((4U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[932]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffffbU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (4U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((8U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
               ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[933]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffff7U & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (8U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[934]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffffefU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x10U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[935]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffffdfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x20U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[936]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffffbfU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x40U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                  ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[937]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffff7fU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x80U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[938]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffeffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x100U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[939]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffdffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x200U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[940]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffffbffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x400U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                   ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[941]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffff7ffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x800U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[942]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffefffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x1000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[943]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffdfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x2000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[944]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffffbfffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x4000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                    ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[945]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffff7fffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x8000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[946]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffeffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x10000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[947]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffdffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x20000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[948]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfffbffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x40000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                     ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[949]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfff7ffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x80000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[950]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffefffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x100000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[951]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffdfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x200000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[952]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xffbfffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x400000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                      ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[953]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xff7fffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x800000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[954]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfeffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x1000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[955]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfdffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x2000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[956]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xfbffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x4000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                       ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[957]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xf7ffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x8000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[958]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xefffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x10000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[959]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xdfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x20000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[960]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0xbfffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x40000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu__DOT__xor_result 
                        ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[961]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result 
            = ((0x7fffffffU & vlTOPp->Top__DOT__alu__DOT____Vtogcov__xor_result) 
               | (0x80000000U & vlTOPp->Top__DOT__alu__DOT__xor_result));
    }
    if ((1U & ((~ (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                           >> 0x20U))) ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__sltu_result))) {
        ++(vlSymsp->__Vcoverage[1026]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__sltu_result 
            = (1U & (~ (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                >> 0x20U))));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__alu__DOT__add_result) 
               ^ (IData)(vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result)))) {
        ++(vlSymsp->__Vcoverage[897]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffffeULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | (IData)((IData)((1U & (IData)(vlTOPp->Top__DOT__alu__DOT__add_result)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[898]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffffdULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[899]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffffbULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[900]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffff7ULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[901]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffffefULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[902]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffffdfULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[903]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffffbfULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 6U))))) 
                  << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[904]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffff7fULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 7U))))) 
                  << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[905]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffeffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 8U))))) 
                  << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[906]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffdffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 9U))))) 
                  << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[907]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffffbffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xaU))))) 
                  << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[908]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffff7ffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xbU))))) 
                  << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[909]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffefffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xcU))))) 
                  << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[910]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffdfffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xdU))))) 
                  << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[911]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffffbfffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xeU))))) 
                  << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[912]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffff7fffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0xfU))))) 
                  << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[913]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffeffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x10U))))) 
                  << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[914]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffdffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x11U))))) 
                  << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[915]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fffbffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x12U))))) 
                  << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[916]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fff7ffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x13U))))) 
                  << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[917]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffefffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x14U))))) 
                  << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[918]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffdfffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x15U))))) 
                  << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[919]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ffbfffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x16U))))) 
                  << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[920]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1ff7fffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x17U))))) 
                  << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[921]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1feffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x18U))))) 
                  << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[922]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fdffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x19U))))) 
                  << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[923]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1fbffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1aU))))) 
                  << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[924]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1f7ffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1bU))))) 
                  << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[925]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1efffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1cU))))) 
                  << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[926]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1dfffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1dU))))) 
                  << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[927]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x1bfffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1eU))))) 
                  << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[928]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0x17fffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x1fU))))) 
                  << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[929]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result 
            = ((0xffffffffULL & vlTOPp->Top__DOT__alu__DOT____Vtogcov__add_result) 
               | ((QData)((IData)((1U & (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                 >> 0x20U))))) 
                  << 0x20U));
    }
    vlTOPp->Top__DOT__alu__DOT__slt_result = (1U & 
                                              ((vlTOPp->Top__DOT__alu__DOT__xor_result 
                                                >> 0x1fU) 
                                               ^ (~ (IData)(
                                                            (vlTOPp->Top__DOT__alu__DOT__add_result 
                                                             >> 0x20U)))));
    if (((IData)(vlTOPp->Top__DOT__alu__DOT__slt_result) 
         ^ vlTOPp->Top__DOT__alu__DOT____Vtogcov__slt_result)) {
        ++(vlSymsp->__Vcoverage[1027]);
        vlTOPp->Top__DOT__alu__DOT____Vtogcov__slt_result 
            = vlTOPp->Top__DOT__alu__DOT__slt_result;
    }
    vlTOPp->Top__DOT__alu_io_out = ((0x12U == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                     ? (1U & (~ (IData)(
                                                        (vlTOPp->Top__DOT__alu__DOT__add_result 
                                                         >> 0x20U))))
                                     : ((0x11U == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                         ? (IData)(vlTOPp->Top__DOT__alu__DOT__slt_result)
                                         : ((1U == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                             ? vlTOPp->Top__DOT__alu__DOT__xor_result
                                             : ((2U 
                                                 == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                 ? vlTOPp->Top__DOT__alu__DOT__or_result
                                                 : 
                                                ((3U 
                                                  == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                  ? vlTOPp->Top__DOT__alu__DOT__and_result
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                   ? (IData)(vlTOPp->Top__DOT__alu__DOT___T_23)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                    ? vlTOPp->Top__DOT__alu__DOT___T_25
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                     ? vlTOPp->Top__DOT__alu__DOT__srl_result
                                                     : 
                                                    ((8U 
                                                      == (IData)(vlTOPp->Top__DOT__idu__DOT__csignals_4))
                                                      ? vlTOPp->Top__DOT__alu_io_in1
                                                      : (IData)(vlTOPp->Top__DOT__alu__DOT__add_result))))))))));
    if (((0U == vlTOPp->Top__DOT__alu_io_out) ^ vlTOPp->Top__DOT____Vtogcov__alu_io_zero)) {
        ++(vlSymsp->__Vcoverage[346]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_zero = 
            (0U == vlTOPp->Top__DOT__alu_io_out);
    }
    if ((1U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((2U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((4U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((8U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x10U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x20U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x40U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x80U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x100U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x200U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x400U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x800U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__alu_io_out ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__alu_io_out 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__alu_io_out 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__alu_io_out 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[336]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__alu_io_out 
                      ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__alu_io_out 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__alu_io_out 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[339]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__alu_io_out 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[340]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__alu_io_out 
                       ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[341]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__alu_io_out 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[342]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__alu_io_out 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[343]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__alu_io_out 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[344]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__alu_io_out 
                        ^ vlTOPp->Top__DOT____Vtogcov__alu_io_out))) {
        ++(vlSymsp->__Vcoverage[345]);
        vlTOPp->Top__DOT____Vtogcov__alu_io_out = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__alu_io_out) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__alu_io_out));
    }
    vlTOPp->io_dmem_req_bits_addr = vlTOPp->Top__DOT__alu_io_out;
    vlTOPp->Top__DOT__br_taken = (((2U == (IData)(vlTOPp->Top__DOT__idu_io_br_type)) 
                                   & (0U == vlTOPp->Top__DOT__alu_io_out)) 
                                  | (((1U == (IData)(vlTOPp->Top__DOT__idu_io_br_type)) 
                                      & (0U != vlTOPp->Top__DOT__alu_io_out)) 
                                     | (((3U == (IData)(vlTOPp->Top__DOT__idu_io_br_type)) 
                                         & (~ vlTOPp->Top__DOT__alu_io_out)) 
                                        | (((4U == (IData)(vlTOPp->Top__DOT__idu_io_br_type)) 
                                            & (~ vlTOPp->Top__DOT__alu_io_out)) 
                                           | (((5U 
                                                == (IData)(vlTOPp->Top__DOT__idu_io_br_type)) 
                                               | (6U 
                                                  == (IData)(vlTOPp->Top__DOT__idu_io_br_type))) 
                                              & vlTOPp->Top__DOT__alu_io_out)))));
    vlTOPp->Top__DOT__rf_io_wdata = ((0U == (IData)(vlTOPp->Top__DOT__idu_io_wb_sel))
                                      ? vlTOPp->Top__DOT__alu_io_out
                                      : ((1U == (IData)(vlTOPp->Top__DOT__idu_io_wb_sel))
                                          ? vlTOPp->io_dmem_resp_bits_data
                                          : ((2U == (IData)(vlTOPp->Top__DOT__idu_io_wb_sel))
                                              ? ((IData)(4U) 
                                                 + vlTOPp->Top__DOT__pc_reg)
                                              : vlTOPp->Top__DOT__alu_io_out)));
    if ((1U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (1U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((2U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (2U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((4U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (4U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((8U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (8U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x10U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x10U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x20U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x20U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x40U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x40U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x80U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x80U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x100U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x100U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x200U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x200U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x400U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x400U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x800U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x800U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x1000U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x1000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x2000U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x2000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x4000U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x4000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x8000U & (vlTOPp->io_dmem_req_bits_addr ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x8000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x10000U & (vlTOPp->io_dmem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x10000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x20000U & (vlTOPp->io_dmem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x20000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x40000U & (vlTOPp->io_dmem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x40000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x80000U & (vlTOPp->io_dmem_req_bits_addr 
                     ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x80000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x100000U & (vlTOPp->io_dmem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x100000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x200000U & (vlTOPp->io_dmem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x200000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x400000U & (vlTOPp->io_dmem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x400000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x800000U & (vlTOPp->io_dmem_req_bits_addr 
                      ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x800000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x1000000U & (vlTOPp->io_dmem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x1000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x2000000U & (vlTOPp->io_dmem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x2000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x4000000U & (vlTOPp->io_dmem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x4000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x8000000U & (vlTOPp->io_dmem_req_bits_addr 
                       ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x8000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x10000000U & (vlTOPp->io_dmem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x10000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x20000000U & (vlTOPp->io_dmem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x20000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x40000000U & (vlTOPp->io_dmem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x40000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if ((0x80000000U & (vlTOPp->io_dmem_req_bits_addr 
                        ^ vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_dmem_req_bits_addr) 
               | (0x80000000U & vlTOPp->io_dmem_req_bits_addr));
    }
    if (((IData)(vlTOPp->Top__DOT__br_taken) ^ vlTOPp->Top__DOT____Vtogcov__br_taken)) {
        ++(vlSymsp->__Vcoverage[853]);
        vlTOPp->Top__DOT____Vtogcov__br_taken = vlTOPp->Top__DOT__br_taken;
    }
    vlTOPp->Top__DOT__pc_next = ((IData)(vlTOPp->Top__DOT__br_taken)
                                  ? (IData)(vlTOPp->Top__DOT___T_187)
                                  : ((7U == (IData)(vlTOPp->Top__DOT__idu_io_br_type))
                                      ? (IData)(vlTOPp->Top__DOT___T_188)
                                      : ((8U == (IData)(vlTOPp->Top__DOT__idu_io_br_type))
                                          ? (IData)(vlTOPp->Top__DOT___T_189)
                                          : ((IData)(4U) 
                                             + vlTOPp->Top__DOT__pc_reg))));
    if ((1U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[459]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (1U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((2U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[460]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (2U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((4U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[461]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (4U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((8U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[462]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (8U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x10U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[463]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x10U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x20U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[464]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x20U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x40U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[465]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x40U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x80U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[466]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x80U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x100U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[467]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x100U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x200U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[468]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x200U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x400U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[469]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x400U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x800U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[470]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x800U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[471]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x1000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[472]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x2000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[473]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x4000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__rf_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[474]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x8000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__rf_io_wdata 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[475]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x10000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__rf_io_wdata 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[476]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x20000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__rf_io_wdata 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[477]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x40000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__rf_io_wdata 
                     ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[478]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x80000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__rf_io_wdata 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[479]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x100000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__rf_io_wdata 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[480]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x200000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__rf_io_wdata 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[481]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x400000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__rf_io_wdata 
                      ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[482]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x800000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[483]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x1000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[484]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x2000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[485]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x4000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                       ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[486]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x8000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[487]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x10000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[488]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x20000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[489]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x40000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__rf_io_wdata 
                        ^ vlTOPp->Top__DOT____Vtogcov__rf_io_wdata))) {
        ++(vlSymsp->__Vcoverage[490]);
        vlTOPp->Top__DOT____Vtogcov__rf_io_wdata = 
            ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__rf_io_wdata) 
             | (0x80000000U & vlTOPp->Top__DOT__rf_io_wdata));
    }
    vlTOPp->io_debug_io_wdata = vlTOPp->Top__DOT__rf_io_wdata;
    if ((1U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[854]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffffeU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (1U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((2U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[855]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffffdU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (2U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((4U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[856]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffffbU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (4U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((8U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[857]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffff7U 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (8U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x10U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[858]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffffefU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x10U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x20U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[859]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffffdfU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x20U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x40U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[860]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffffbfU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x40U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x80U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[861]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffff7fU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x80U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x100U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[862]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffeffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x100U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x200U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[863]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffdffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x200U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x400U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[864]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffffbffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x400U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x800U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[865]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffff7ffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x800U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[866]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffefffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x1000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[867]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffdfffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x2000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[868]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffffbfffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x4000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[869]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffff7fffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x8000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[870]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffeffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x10000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[871]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffdffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x20000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[872]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfffbffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x40000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[873]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfff7ffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x80000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[874]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffefffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x100000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[875]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffdfffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x200000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[876]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xffbfffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x400000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[877]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xff7fffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x800000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[878]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfeffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x1000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[879]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfdffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x2000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[880]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xfbffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x4000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[881]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xf7ffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x8000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[882]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xefffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x10000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[883]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xdfffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x20000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[884]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0xbfffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x40000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__pc_next ^ vlTOPp->Top__DOT____Vtogcov__pc_next))) {
        ++(vlSymsp->__Vcoverage[885]);
        vlTOPp->Top__DOT____Vtogcov__pc_next = ((0x7fffffffU 
                                                 & vlTOPp->Top__DOT____Vtogcov__pc_next) 
                                                | (0x80000000U 
                                                   & vlTOPp->Top__DOT__pc_next));
    }
    if ((1U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffffeU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (1U & vlTOPp->io_debug_io_wdata));
    }
    if ((2U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffffdU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (2U & vlTOPp->io_debug_io_wdata));
    }
    if ((4U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffffbU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (4U & vlTOPp->io_debug_io_wdata));
    }
    if ((8U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffff7U & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (8U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x10U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffffefU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x10U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x20U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffffdfU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x20U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x40U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffffbfU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x40U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x80U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffff7fU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x80U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x100U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffeffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x100U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x200U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffdffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x200U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x400U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffffbffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x400U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x800U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffff7ffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x800U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x1000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffefffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x1000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x2000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffdfffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x2000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x4000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffffbfffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x4000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x8000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffff7fffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x8000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x10000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffeffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x10000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x20000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffdffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x20000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x40000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfffbffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x40000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x80000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfff7ffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x80000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x100000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffefffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x100000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x200000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffdfffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x200000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x400000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xffbfffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x400000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x800000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xff7fffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x800000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x1000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfeffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x1000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x2000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfdffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x2000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x4000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xfbffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x4000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x8000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xf7ffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x8000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x10000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xefffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x10000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x20000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xdfffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x20000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x40000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0xbfffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x40000000U & vlTOPp->io_debug_io_wdata));
    }
    if ((0x80000000U & (vlTOPp->io_debug_io_wdata ^ vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata 
            = ((0x7fffffffU & vlTOPp->Top__DOT____Vtogcov__io_debug_io_wdata) 
               | (0x80000000U & vlTOPp->io_debug_io_wdata));
    }
}
