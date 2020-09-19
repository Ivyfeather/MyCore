// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

void VTop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTop* t = (VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VTop::traceChgThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTop::traceChgThis__2(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgArray(c+1,(vlTOPp->Top__DOT__add_result),65);
        vcdp->chgQuad(c+25,(vlTOPp->Top__DOT__xor_result),64);
        vcdp->chgQuad(c+41,(vlTOPp->Top__DOT__or_result),64);
        vcdp->chgQuad(c+57,(vlTOPp->Top__DOT__and_result),64);
        vcdp->chgBit(c+73,((1U & (~ vlTOPp->Top__DOT__add_result[2U]))));
        vcdp->chgBit(c+81,(vlTOPp->Top__DOT__slt_result));
    }
}

void VTop::traceChgThis__3(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+89,(vlTOPp->clock));
        vcdp->chgBit(c+97,(vlTOPp->reset));
        vcdp->chgBus(c+105,(vlTOPp->io_opcode),6);
        vcdp->chgQuad(c+113,(vlTOPp->io_in1),64);
        vcdp->chgQuad(c+129,(vlTOPp->io_in2),64);
        vcdp->chgQuad(c+145,(vlTOPp->io_out),64);
    }
}
