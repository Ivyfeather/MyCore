// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VTop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlTOPp->Top__DOT__rf[0]),64);
            tracep->chgQData(oldp+2,(vlTOPp->Top__DOT__rf[1]),64);
            tracep->chgQData(oldp+4,(vlTOPp->Top__DOT__rf[2]),64);
            tracep->chgQData(oldp+6,(vlTOPp->Top__DOT__rf[3]),64);
            tracep->chgQData(oldp+8,(vlTOPp->Top__DOT__rf[4]),64);
            tracep->chgQData(oldp+10,(vlTOPp->Top__DOT__rf[5]),64);
            tracep->chgQData(oldp+12,(vlTOPp->Top__DOT__rf[6]),64);
            tracep->chgQData(oldp+14,(vlTOPp->Top__DOT__rf[7]),64);
            tracep->chgQData(oldp+16,(vlTOPp->Top__DOT__rf[8]),64);
            tracep->chgQData(oldp+18,(vlTOPp->Top__DOT__rf[9]),64);
            tracep->chgQData(oldp+20,(vlTOPp->Top__DOT__rf[10]),64);
            tracep->chgQData(oldp+22,(vlTOPp->Top__DOT__rf[11]),64);
            tracep->chgQData(oldp+24,(vlTOPp->Top__DOT__rf[12]),64);
            tracep->chgQData(oldp+26,(vlTOPp->Top__DOT__rf[13]),64);
            tracep->chgQData(oldp+28,(vlTOPp->Top__DOT__rf[14]),64);
            tracep->chgQData(oldp+30,(vlTOPp->Top__DOT__rf[15]),64);
            tracep->chgQData(oldp+32,(vlTOPp->Top__DOT__rf[16]),64);
            tracep->chgQData(oldp+34,(vlTOPp->Top__DOT__rf[17]),64);
            tracep->chgQData(oldp+36,(vlTOPp->Top__DOT__rf[18]),64);
            tracep->chgQData(oldp+38,(vlTOPp->Top__DOT__rf[19]),64);
            tracep->chgQData(oldp+40,(vlTOPp->Top__DOT__rf[20]),64);
            tracep->chgQData(oldp+42,(vlTOPp->Top__DOT__rf[21]),64);
            tracep->chgQData(oldp+44,(vlTOPp->Top__DOT__rf[22]),64);
            tracep->chgQData(oldp+46,(vlTOPp->Top__DOT__rf[23]),64);
            tracep->chgQData(oldp+48,(vlTOPp->Top__DOT__rf[24]),64);
            tracep->chgQData(oldp+50,(vlTOPp->Top__DOT__rf[25]),64);
            tracep->chgQData(oldp+52,(vlTOPp->Top__DOT__rf[26]),64);
            tracep->chgQData(oldp+54,(vlTOPp->Top__DOT__rf[27]),64);
            tracep->chgQData(oldp+56,(vlTOPp->Top__DOT__rf[28]),64);
            tracep->chgQData(oldp+58,(vlTOPp->Top__DOT__rf[29]),64);
            tracep->chgQData(oldp+60,(vlTOPp->Top__DOT__rf[30]),64);
            tracep->chgQData(oldp+62,(vlTOPp->Top__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+64,(vlTOPp->clock));
        tracep->chgBit(oldp+65,(vlTOPp->reset));
        tracep->chgCData(oldp+66,(vlTOPp->io_rs1_addr),5);
        tracep->chgQData(oldp+67,(vlTOPp->io_rs1_data),64);
        tracep->chgCData(oldp+69,(vlTOPp->io_rs2_addr),5);
        tracep->chgQData(oldp+70,(vlTOPp->io_rs2_data),64);
        tracep->chgCData(oldp+72,(vlTOPp->io_waddr),5);
        tracep->chgQData(oldp+73,(vlTOPp->io_wdata),64);
        tracep->chgBit(oldp+75,(vlTOPp->io_wen));
        tracep->chgQData(oldp+76,(vlTOPp->Top__DOT__rf___05FT_2_data),64);
        tracep->chgQData(oldp+78,(vlTOPp->Top__DOT__rf___05FT_5_data),64);
    }
}

void VTop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
