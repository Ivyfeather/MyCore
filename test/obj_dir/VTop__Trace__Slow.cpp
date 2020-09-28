// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

void VTop::_traceDump() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumperp->dump(VL_TIME_Q());
}
void VTop::_traceDumpOpen() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    if (VL_UNLIKELY(!__VlSymsp->__Vm_dumperp)) {
        __VlSymsp->__Vm_dumperp = new VerilatedVcdC();
        const char* cp = vl_dumpctl_filenamep();
        trace(__VlSymsp->__Vm_dumperp, 0, 0);
        __VlSymsp->__Vm_dumperp->open(vl_dumpctl_filenamep());
        __VlSymsp->__Vm_dumperp->changeThread();
        __VlSymsp->__Vm_dumping = true;
    }
}
void VTop::_traceDumpClose() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumping = false;
    VL_DO_CLEAR(delete __VlSymsp->__Vm_dumperp, __VlSymsp->__Vm_dumperp = nullptr);
}
void VTop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VTop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VTop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VTop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VTop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+8,"clock", false,-1);
        tracep->declBit(c+9,"reset", false,-1);
        tracep->declBus(c+10,"io_opcode", false,-1, 5,0);
        tracep->declBus(c+11,"io_in1", false,-1, 31,0);
        tracep->declBus(c+12,"io_in2", false,-1, 31,0);
        tracep->declBus(c+13,"io_out", false,-1, 31,0);
        tracep->declBit(c+8,"Top clock", false,-1);
        tracep->declBit(c+9,"Top reset", false,-1);
        tracep->declBus(c+10,"Top io_opcode", false,-1, 5,0);
        tracep->declBus(c+11,"Top io_in1", false,-1, 31,0);
        tracep->declBus(c+12,"Top io_in2", false,-1, 31,0);
        tracep->declBus(c+13,"Top io_out", false,-1, 31,0);
        tracep->declQuad(c+1,"Top add_result", false,-1, 32,0);
        tracep->declBus(c+3,"Top xor_result", false,-1, 31,0);
        tracep->declBus(c+4,"Top or_result", false,-1, 31,0);
        tracep->declBus(c+5,"Top and_result", false,-1, 31,0);
        tracep->declBit(c+6,"Top sltu_result", false,-1);
        tracep->declBit(c+7,"Top slt_result", false,-1);
    }
}

void VTop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VTop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VTop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlTOPp->Top__DOT__add_result),33);
        tracep->fullIData(oldp+3,(vlTOPp->Top__DOT__xor_result),32);
        tracep->fullIData(oldp+4,(vlTOPp->Top__DOT__or_result),32);
        tracep->fullIData(oldp+5,(vlTOPp->Top__DOT__and_result),32);
        tracep->fullBit(oldp+6,((1U & (~ (IData)((vlTOPp->Top__DOT__add_result 
                                                  >> 0x20U))))));
        tracep->fullBit(oldp+7,(vlTOPp->Top__DOT__slt_result));
        tracep->fullBit(oldp+8,(vlTOPp->clock));
        tracep->fullBit(oldp+9,(vlTOPp->reset));
        tracep->fullCData(oldp+10,(vlTOPp->io_opcode),6);
        tracep->fullIData(oldp+11,(vlTOPp->io_in1),32);
        tracep->fullIData(oldp+12,(vlTOPp->io_in2),32);
        tracep->fullIData(oldp+13,(vlTOPp->io_out),32);
    }
}
