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
        tracep->declBit(c+65,"clock", false,-1);
        tracep->declBit(c+66,"reset", false,-1);
        tracep->declBus(c+67,"io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+70,"io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+73,"io_waddr", false,-1, 4,0);
        tracep->declQuad(c+74,"io_wdata", false,-1, 63,0);
        tracep->declBit(c+76,"io_wen", false,-1);
        tracep->declBit(c+65,"Top clock", false,-1);
        tracep->declBit(c+66,"Top reset", false,-1);
        tracep->declBus(c+67,"Top io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"Top io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+70,"Top io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"Top io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+73,"Top io_waddr", false,-1, 4,0);
        tracep->declQuad(c+74,"Top io_wdata", false,-1, 63,0);
        tracep->declBit(c+76,"Top io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+1+i*2,"Top rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+77,"Top rf__T_2_data", false,-1, 63,0);
        tracep->declBus(c+67,"Top rf__T_2_addr", false,-1, 4,0);
        tracep->declQuad(c+79,"Top rf__T_5_data", false,-1, 63,0);
        tracep->declBus(c+70,"Top rf__T_5_addr", false,-1, 4,0);
        tracep->declQuad(c+74,"Top rf__T_data", false,-1, 63,0);
        tracep->declBus(c+73,"Top rf__T_addr", false,-1, 4,0);
        tracep->declBit(c+81,"Top rf__T_mask", false,-1);
        tracep->declBit(c+76,"Top rf__T_en", false,-1);
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
        tracep->fullQData(oldp+1,(vlTOPp->Top__DOT__rf[0]),64);
        tracep->fullQData(oldp+3,(vlTOPp->Top__DOT__rf[1]),64);
        tracep->fullQData(oldp+5,(vlTOPp->Top__DOT__rf[2]),64);
        tracep->fullQData(oldp+7,(vlTOPp->Top__DOT__rf[3]),64);
        tracep->fullQData(oldp+9,(vlTOPp->Top__DOT__rf[4]),64);
        tracep->fullQData(oldp+11,(vlTOPp->Top__DOT__rf[5]),64);
        tracep->fullQData(oldp+13,(vlTOPp->Top__DOT__rf[6]),64);
        tracep->fullQData(oldp+15,(vlTOPp->Top__DOT__rf[7]),64);
        tracep->fullQData(oldp+17,(vlTOPp->Top__DOT__rf[8]),64);
        tracep->fullQData(oldp+19,(vlTOPp->Top__DOT__rf[9]),64);
        tracep->fullQData(oldp+21,(vlTOPp->Top__DOT__rf[10]),64);
        tracep->fullQData(oldp+23,(vlTOPp->Top__DOT__rf[11]),64);
        tracep->fullQData(oldp+25,(vlTOPp->Top__DOT__rf[12]),64);
        tracep->fullQData(oldp+27,(vlTOPp->Top__DOT__rf[13]),64);
        tracep->fullQData(oldp+29,(vlTOPp->Top__DOT__rf[14]),64);
        tracep->fullQData(oldp+31,(vlTOPp->Top__DOT__rf[15]),64);
        tracep->fullQData(oldp+33,(vlTOPp->Top__DOT__rf[16]),64);
        tracep->fullQData(oldp+35,(vlTOPp->Top__DOT__rf[17]),64);
        tracep->fullQData(oldp+37,(vlTOPp->Top__DOT__rf[18]),64);
        tracep->fullQData(oldp+39,(vlTOPp->Top__DOT__rf[19]),64);
        tracep->fullQData(oldp+41,(vlTOPp->Top__DOT__rf[20]),64);
        tracep->fullQData(oldp+43,(vlTOPp->Top__DOT__rf[21]),64);
        tracep->fullQData(oldp+45,(vlTOPp->Top__DOT__rf[22]),64);
        tracep->fullQData(oldp+47,(vlTOPp->Top__DOT__rf[23]),64);
        tracep->fullQData(oldp+49,(vlTOPp->Top__DOT__rf[24]),64);
        tracep->fullQData(oldp+51,(vlTOPp->Top__DOT__rf[25]),64);
        tracep->fullQData(oldp+53,(vlTOPp->Top__DOT__rf[26]),64);
        tracep->fullQData(oldp+55,(vlTOPp->Top__DOT__rf[27]),64);
        tracep->fullQData(oldp+57,(vlTOPp->Top__DOT__rf[28]),64);
        tracep->fullQData(oldp+59,(vlTOPp->Top__DOT__rf[29]),64);
        tracep->fullQData(oldp+61,(vlTOPp->Top__DOT__rf[30]),64);
        tracep->fullQData(oldp+63,(vlTOPp->Top__DOT__rf[31]),64);
        tracep->fullBit(oldp+65,(vlTOPp->clock));
        tracep->fullBit(oldp+66,(vlTOPp->reset));
        tracep->fullCData(oldp+67,(vlTOPp->io_rs1_addr),5);
        tracep->fullQData(oldp+68,(vlTOPp->io_rs1_data),64);
        tracep->fullCData(oldp+70,(vlTOPp->io_rs2_addr),5);
        tracep->fullQData(oldp+71,(vlTOPp->io_rs2_data),64);
        tracep->fullCData(oldp+73,(vlTOPp->io_waddr),5);
        tracep->fullQData(oldp+74,(vlTOPp->io_wdata),64);
        tracep->fullBit(oldp+76,(vlTOPp->io_wen));
        tracep->fullQData(oldp+77,(vlTOPp->Top__DOT__rf___05FT_2_data),64);
        tracep->fullQData(oldp+79,(vlTOPp->Top__DOT__rf___05FT_5_data),64);
        tracep->fullBit(oldp+81,(1U));
    }
}
