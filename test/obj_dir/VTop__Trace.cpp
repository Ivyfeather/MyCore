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
            tracep->chgCData(oldp+0,(vlTOPp->Top__DOT__rs1_addr),5);
            tracep->chgQData(oldp+1,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
            tracep->chgCData(oldp+3,(vlTOPp->Top__DOT__rs2_addr),5);
            tracep->chgQData(oldp+4,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
            tracep->chgCData(oldp+6,(vlTOPp->Top__DOT__waddr),5);
            tracep->chgQData(oldp+7,(vlTOPp->Top__DOT__wdata),64);
            tracep->chgBit(oldp+9,(vlTOPp->Top__DOT__wen));
            tracep->chgQData(oldp+10,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+12,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+14,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+16,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+18,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+20,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+22,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+24,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+26,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+28,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+30,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+32,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+34,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+36,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+38,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+40,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+42,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+44,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+46,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+48,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+50,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+52,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+54,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+56,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+58,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+60,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+62,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+64,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+66,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+68,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+70,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+72,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+74,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+76,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        }
        tracep->chgBit(oldp+78,(vlTOPp->clock));
        tracep->chgBit(oldp+79,(vlTOPp->reset));
        tracep->chgCData(oldp+80,(vlTOPp->io_rs1_addr),5);
        tracep->chgQData(oldp+81,(vlTOPp->io_rs1_data),64);
        tracep->chgCData(oldp+83,(vlTOPp->io_rs2_addr),5);
        tracep->chgQData(oldp+84,(vlTOPp->io_rs2_data),64);
        tracep->chgCData(oldp+86,(vlTOPp->io_waddr),5);
        tracep->chgQData(oldp+87,(vlTOPp->io_wdata),64);
        tracep->chgBit(oldp+89,(vlTOPp->io_wen));
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
