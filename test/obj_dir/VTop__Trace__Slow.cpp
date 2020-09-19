// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

void VTop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VTop::traceInit, &VTop::traceFull, &VTop::traceChg, this);
}
void VTop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VTop* t = (VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VTop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VTop* t = (VTop*)userthis;
    VTop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VTop::traceInitThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VTop::traceFullThis(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VTop::traceInitThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+89,"clock", false,-1);
        vcdp->declBit(c+97,"reset", false,-1);
        vcdp->declBus(c+105,"io_opcode", false,-1, 5,0);
        vcdp->declQuad(c+113,"io_in1", false,-1, 63,0);
        vcdp->declQuad(c+129,"io_in2", false,-1, 63,0);
        vcdp->declQuad(c+145,"io_out", false,-1, 63,0);
        vcdp->declBit(c+89,"Top clock", false,-1);
        vcdp->declBit(c+97,"Top reset", false,-1);
        vcdp->declBus(c+105,"Top io_opcode", false,-1, 5,0);
        vcdp->declQuad(c+113,"Top io_in1", false,-1, 63,0);
        vcdp->declQuad(c+129,"Top io_in2", false,-1, 63,0);
        vcdp->declQuad(c+145,"Top io_out", false,-1, 63,0);
        vcdp->declArray(c+1,"Top add_result", false,-1, 64,0);
        vcdp->declQuad(c+25,"Top xor_result", false,-1, 63,0);
        vcdp->declQuad(c+41,"Top or_result", false,-1, 63,0);
        vcdp->declQuad(c+57,"Top and_result", false,-1, 63,0);
        vcdp->declBit(c+73,"Top sltu_result", false,-1);
        vcdp->declBit(c+81,"Top slt_result", false,-1);
    }
}

void VTop::traceFullThis__1(VTop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VTop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullArray(c+1,(vlTOPp->Top__DOT__add_result),65);
        vcdp->fullQuad(c+25,(vlTOPp->Top__DOT__xor_result),64);
        vcdp->fullQuad(c+41,(vlTOPp->Top__DOT__or_result),64);
        vcdp->fullQuad(c+57,(vlTOPp->Top__DOT__and_result),64);
        vcdp->fullBit(c+73,((1U & (~ vlTOPp->Top__DOT__add_result[2U]))));
        vcdp->fullBit(c+81,(vlTOPp->Top__DOT__slt_result));
        vcdp->fullBit(c+89,(vlTOPp->clock));
        vcdp->fullBit(c+97,(vlTOPp->reset));
        vcdp->fullBus(c+105,(vlTOPp->io_opcode),6);
        vcdp->fullQuad(c+113,(vlTOPp->io_in1),64);
        vcdp->fullQuad(c+129,(vlTOPp->io_in2),64);
        vcdp->fullQuad(c+145,(vlTOPp->io_out),64);
    }
}
