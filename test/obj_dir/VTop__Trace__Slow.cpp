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
        tracep->declBit(c+33,"clock", false,-1);
        tracep->declBit(c+34,"reset", false,-1);
        tracep->declBus(c+35,"io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+36,"io_rs1_data", false,-1, 31,0);
        tracep->declBus(c+37,"io_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+38,"io_rs2_data", false,-1, 31,0);
        tracep->declBus(c+39,"io_waddr", false,-1, 4,0);
        tracep->declBus(c+40,"io_wdata", false,-1, 31,0);
        tracep->declBit(c+41,"io_wen", false,-1);
        tracep->declBit(c+33,"Top clock", false,-1);
        tracep->declBit(c+34,"Top reset", false,-1);
        tracep->declBus(c+35,"Top io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+36,"Top io_rs1_data", false,-1, 31,0);
        tracep->declBus(c+37,"Top io_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+38,"Top io_rs2_data", false,-1, 31,0);
        tracep->declBus(c+39,"Top io_waddr", false,-1, 4,0);
        tracep->declBus(c+40,"Top io_wdata", false,-1, 31,0);
        tracep->declBit(c+41,"Top io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+1+i*1,"Top rf", true,(i+0), 31,0);}}
        tracep->declBus(c+42,"Top rf__T_24_data", false,-1, 31,0);
        tracep->declBus(c+35,"Top rf__T_24_addr", false,-1, 4,0);
        tracep->declBus(c+43,"Top rf__T_29_data", false,-1, 31,0);
        tracep->declBus(c+37,"Top rf__T_29_addr", false,-1, 4,0);
        tracep->declBus(c+40,"Top rf__T_21_data", false,-1, 31,0);
        tracep->declBus(c+39,"Top rf__T_21_addr", false,-1, 4,0);
        tracep->declBit(c+44,"Top rf__T_21_mask", false,-1);
        tracep->declBit(c+41,"Top rf__T_21_en", false,-1);
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
        tracep->fullIData(oldp+1,(vlTOPp->Top__DOT__rf[0]),32);
        tracep->fullIData(oldp+2,(vlTOPp->Top__DOT__rf[1]),32);
        tracep->fullIData(oldp+3,(vlTOPp->Top__DOT__rf[2]),32);
        tracep->fullIData(oldp+4,(vlTOPp->Top__DOT__rf[3]),32);
        tracep->fullIData(oldp+5,(vlTOPp->Top__DOT__rf[4]),32);
        tracep->fullIData(oldp+6,(vlTOPp->Top__DOT__rf[5]),32);
        tracep->fullIData(oldp+7,(vlTOPp->Top__DOT__rf[6]),32);
        tracep->fullIData(oldp+8,(vlTOPp->Top__DOT__rf[7]),32);
        tracep->fullIData(oldp+9,(vlTOPp->Top__DOT__rf[8]),32);
        tracep->fullIData(oldp+10,(vlTOPp->Top__DOT__rf[9]),32);
        tracep->fullIData(oldp+11,(vlTOPp->Top__DOT__rf[10]),32);
        tracep->fullIData(oldp+12,(vlTOPp->Top__DOT__rf[11]),32);
        tracep->fullIData(oldp+13,(vlTOPp->Top__DOT__rf[12]),32);
        tracep->fullIData(oldp+14,(vlTOPp->Top__DOT__rf[13]),32);
        tracep->fullIData(oldp+15,(vlTOPp->Top__DOT__rf[14]),32);
        tracep->fullIData(oldp+16,(vlTOPp->Top__DOT__rf[15]),32);
        tracep->fullIData(oldp+17,(vlTOPp->Top__DOT__rf[16]),32);
        tracep->fullIData(oldp+18,(vlTOPp->Top__DOT__rf[17]),32);
        tracep->fullIData(oldp+19,(vlTOPp->Top__DOT__rf[18]),32);
        tracep->fullIData(oldp+20,(vlTOPp->Top__DOT__rf[19]),32);
        tracep->fullIData(oldp+21,(vlTOPp->Top__DOT__rf[20]),32);
        tracep->fullIData(oldp+22,(vlTOPp->Top__DOT__rf[21]),32);
        tracep->fullIData(oldp+23,(vlTOPp->Top__DOT__rf[22]),32);
        tracep->fullIData(oldp+24,(vlTOPp->Top__DOT__rf[23]),32);
        tracep->fullIData(oldp+25,(vlTOPp->Top__DOT__rf[24]),32);
        tracep->fullIData(oldp+26,(vlTOPp->Top__DOT__rf[25]),32);
        tracep->fullIData(oldp+27,(vlTOPp->Top__DOT__rf[26]),32);
        tracep->fullIData(oldp+28,(vlTOPp->Top__DOT__rf[27]),32);
        tracep->fullIData(oldp+29,(vlTOPp->Top__DOT__rf[28]),32);
        tracep->fullIData(oldp+30,(vlTOPp->Top__DOT__rf[29]),32);
        tracep->fullIData(oldp+31,(vlTOPp->Top__DOT__rf[30]),32);
        tracep->fullIData(oldp+32,(vlTOPp->Top__DOT__rf[31]),32);
        tracep->fullBit(oldp+33,(vlTOPp->clock));
        tracep->fullBit(oldp+34,(vlTOPp->reset));
        tracep->fullCData(oldp+35,(vlTOPp->io_rs1_addr),5);
        tracep->fullIData(oldp+36,(vlTOPp->io_rs1_data),32);
        tracep->fullCData(oldp+37,(vlTOPp->io_rs2_addr),5);
        tracep->fullIData(oldp+38,(vlTOPp->io_rs2_data),32);
        tracep->fullCData(oldp+39,(vlTOPp->io_waddr),5);
        tracep->fullIData(oldp+40,(vlTOPp->io_wdata),32);
        tracep->fullBit(oldp+41,(vlTOPp->io_wen));
        tracep->fullIData(oldp+42,(vlTOPp->Top__DOT__rf___05FT_24_data),32);
        tracep->fullIData(oldp+43,(vlTOPp->Top__DOT__rf___05FT_29_data),32);
        tracep->fullBit(oldp+44,(1U));
    }
}
