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
        tracep->declBit(c+79,"clock", false,-1);
        tracep->declBit(c+80,"reset", false,-1);
        tracep->declBus(c+81,"io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+82,"io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+84,"io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+85,"io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+87,"io_waddr", false,-1, 4,0);
        tracep->declQuad(c+88,"io_wdata", false,-1, 63,0);
        tracep->declBit(c+90,"io_wen", false,-1);
        tracep->declBit(c+79,"Top clock", false,-1);
        tracep->declBit(c+80,"Top reset", false,-1);
        tracep->declBus(c+81,"Top io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+82,"Top io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+84,"Top io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+85,"Top io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+87,"Top io_waddr", false,-1, 4,0);
        tracep->declQuad(c+88,"Top io_wdata", false,-1, 63,0);
        tracep->declBit(c+90,"Top io_wen", false,-1);
        tracep->declBit(c+79,"Top rf_clock", false,-1);
        tracep->declBus(c+1,"Top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+2,"Top rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+4,"Top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+5,"Top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+7,"Top rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+8,"Top rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+10,"Top rf_io_wen", false,-1);
        tracep->declBus(c+1,"Top rs1_addr", false,-1, 4,0);
        tracep->declBus(c+4,"Top rs2_addr", false,-1, 4,0);
        tracep->declBus(c+7,"Top waddr", false,-1, 4,0);
        tracep->declQuad(c+8,"Top wdata", false,-1, 63,0);
        tracep->declBit(c+10,"Top wen", false,-1);
        tracep->declBit(c+79,"Top rf clock", false,-1);
        tracep->declBus(c+1,"Top rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+2,"Top rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+4,"Top rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+5,"Top rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+7,"Top rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+8,"Top rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+10,"Top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+11+i*2,"Top rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+75,"Top rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+1,"Top rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+77,"Top rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+4,"Top rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+8,"Top rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+7,"Top rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+91,"Top rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+10,"Top rf regfile_MPORT_en", false,-1);
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
        tracep->fullCData(oldp+1,(vlTOPp->Top__DOT__rs1_addr),5);
        tracep->fullQData(oldp+2,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
        tracep->fullCData(oldp+4,(vlTOPp->Top__DOT__rs2_addr),5);
        tracep->fullQData(oldp+5,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
        tracep->fullCData(oldp+7,(vlTOPp->Top__DOT__waddr),5);
        tracep->fullQData(oldp+8,(vlTOPp->Top__DOT__wdata),64);
        tracep->fullBit(oldp+10,(vlTOPp->Top__DOT__wen));
        tracep->fullQData(oldp+11,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+13,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+15,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+17,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+19,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+21,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+23,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+25,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+27,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+29,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+31,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+33,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+35,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+37,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+39,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+41,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+43,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+45,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+47,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+49,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+51,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+53,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+55,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+57,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+59,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+61,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+63,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+65,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+67,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+69,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+71,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+73,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+75,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+77,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullBit(oldp+79,(vlTOPp->clock));
        tracep->fullBit(oldp+80,(vlTOPp->reset));
        tracep->fullCData(oldp+81,(vlTOPp->io_rs1_addr),5);
        tracep->fullQData(oldp+82,(vlTOPp->io_rs1_data),64);
        tracep->fullCData(oldp+84,(vlTOPp->io_rs2_addr),5);
        tracep->fullQData(oldp+85,(vlTOPp->io_rs2_data),64);
        tracep->fullCData(oldp+87,(vlTOPp->io_waddr),5);
        tracep->fullQData(oldp+88,(vlTOPp->io_wdata),64);
        tracep->fullBit(oldp+90,(vlTOPp->io_wen));
        tracep->fullBit(oldp+91,(1U));
    }
}
