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
            tracep->chgQData(oldp+0,(vlTOPp->Top__DOT__add_result),33);
            tracep->chgIData(oldp+2,(vlTOPp->Top__DOT__xor_result),32);
            tracep->chgIData(oldp+3,(vlTOPp->Top__DOT__or_result),32);
            tracep->chgIData(oldp+4,(vlTOPp->Top__DOT__and_result),32);
            tracep->chgBit(oldp+5,((1U & (~ (IData)(
                                                    (vlTOPp->Top__DOT__add_result 
                                                     >> 0x20U))))));
            tracep->chgBit(oldp+6,(vlTOPp->Top__DOT__slt_result));
        }
        tracep->chgBit(oldp+7,(vlTOPp->clock));
        tracep->chgBit(oldp+8,(vlTOPp->reset));
        tracep->chgCData(oldp+9,(vlTOPp->io_opcode),6);
        tracep->chgIData(oldp+10,(vlTOPp->io_in1),32);
        tracep->chgIData(oldp+11,(vlTOPp->io_in2),32);
        tracep->chgIData(oldp+12,(vlTOPp->io_out),32);
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
