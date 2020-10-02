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
            tracep->chgIData(oldp+0,(vlTOPp->Top__DOT__rf[0]),32);
            tracep->chgIData(oldp+1,(vlTOPp->Top__DOT__rf[1]),32);
            tracep->chgIData(oldp+2,(vlTOPp->Top__DOT__rf[2]),32);
            tracep->chgIData(oldp+3,(vlTOPp->Top__DOT__rf[3]),32);
            tracep->chgIData(oldp+4,(vlTOPp->Top__DOT__rf[4]),32);
            tracep->chgIData(oldp+5,(vlTOPp->Top__DOT__rf[5]),32);
            tracep->chgIData(oldp+6,(vlTOPp->Top__DOT__rf[6]),32);
            tracep->chgIData(oldp+7,(vlTOPp->Top__DOT__rf[7]),32);
            tracep->chgIData(oldp+8,(vlTOPp->Top__DOT__rf[8]),32);
            tracep->chgIData(oldp+9,(vlTOPp->Top__DOT__rf[9]),32);
            tracep->chgIData(oldp+10,(vlTOPp->Top__DOT__rf[10]),32);
            tracep->chgIData(oldp+11,(vlTOPp->Top__DOT__rf[11]),32);
            tracep->chgIData(oldp+12,(vlTOPp->Top__DOT__rf[12]),32);
            tracep->chgIData(oldp+13,(vlTOPp->Top__DOT__rf[13]),32);
            tracep->chgIData(oldp+14,(vlTOPp->Top__DOT__rf[14]),32);
            tracep->chgIData(oldp+15,(vlTOPp->Top__DOT__rf[15]),32);
            tracep->chgIData(oldp+16,(vlTOPp->Top__DOT__rf[16]),32);
            tracep->chgIData(oldp+17,(vlTOPp->Top__DOT__rf[17]),32);
            tracep->chgIData(oldp+18,(vlTOPp->Top__DOT__rf[18]),32);
            tracep->chgIData(oldp+19,(vlTOPp->Top__DOT__rf[19]),32);
            tracep->chgIData(oldp+20,(vlTOPp->Top__DOT__rf[20]),32);
            tracep->chgIData(oldp+21,(vlTOPp->Top__DOT__rf[21]),32);
            tracep->chgIData(oldp+22,(vlTOPp->Top__DOT__rf[22]),32);
            tracep->chgIData(oldp+23,(vlTOPp->Top__DOT__rf[23]),32);
            tracep->chgIData(oldp+24,(vlTOPp->Top__DOT__rf[24]),32);
            tracep->chgIData(oldp+25,(vlTOPp->Top__DOT__rf[25]),32);
            tracep->chgIData(oldp+26,(vlTOPp->Top__DOT__rf[26]),32);
            tracep->chgIData(oldp+27,(vlTOPp->Top__DOT__rf[27]),32);
            tracep->chgIData(oldp+28,(vlTOPp->Top__DOT__rf[28]),32);
            tracep->chgIData(oldp+29,(vlTOPp->Top__DOT__rf[29]),32);
            tracep->chgIData(oldp+30,(vlTOPp->Top__DOT__rf[30]),32);
            tracep->chgIData(oldp+31,(vlTOPp->Top__DOT__rf[31]),32);
        }
        tracep->chgBit(oldp+32,(vlTOPp->clock));
        tracep->chgBit(oldp+33,(vlTOPp->reset));
        tracep->chgCData(oldp+34,(vlTOPp->io_rs1_addr),5);
        tracep->chgIData(oldp+35,(vlTOPp->io_rs1_data),32);
        tracep->chgCData(oldp+36,(vlTOPp->io_rs2_addr),5);
        tracep->chgIData(oldp+37,(vlTOPp->io_rs2_data),32);
        tracep->chgCData(oldp+38,(vlTOPp->io_waddr),5);
        tracep->chgIData(oldp+39,(vlTOPp->io_wdata),32);
        tracep->chgBit(oldp+40,(vlTOPp->io_wen));
        tracep->chgIData(oldp+41,(vlTOPp->Top__DOT__rf___05FT_24_data),32);
        tracep->chgIData(oldp+42,(vlTOPp->Top__DOT__rf___05FT_29_data),32);
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
