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
        tracep->declBit(c+310,"clock", false,-1);
        tracep->declBit(c+311,"reset", false,-1);
        tracep->declBit(c+312,"io_imem_req_ready", false,-1);
        tracep->declBit(c+313,"io_imem_req_valid", false,-1);
        tracep->declQuad(c+314,"io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBus(c+316,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+317,"io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+318,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+319,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+320,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+321,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+322,"io_dmem_req_valid", false,-1);
        tracep->declQuad(c+323,"io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+325,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+327,"io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+328,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+329,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+330,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+332,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+334,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+336,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+338,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+340,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+342,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+344,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+346,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+348,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+350,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+352,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+354,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+356,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+358,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+360,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+362,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+364,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+366,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+368,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+370,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+372,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+374,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+376,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+378,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+380,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+382,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+384,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+386,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+388,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+390,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+392,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+394,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+396,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+398,"io_debug_valid", false,-1);
        tracep->declBit(c+399,"io_debug_trap", false,-1);
        tracep->declBus(c+400,"io_debug_inst", false,-1, 31,0);
        tracep->declBit(c+310,"Top clock", false,-1);
        tracep->declBit(c+311,"Top reset", false,-1);
        tracep->declBit(c+312,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+313,"Top io_imem_req_valid", false,-1);
        tracep->declQuad(c+314,"Top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBus(c+316,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+317,"Top io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+318,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+319,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+320,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+321,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+322,"Top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+323,"Top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+325,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+327,"Top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+328,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+329,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+330,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+332,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+334,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+336,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+338,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+340,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+342,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+344,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+346,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+348,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+350,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+352,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+354,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+356,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+358,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+360,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+362,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+364,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+366,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+368,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+370,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+372,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+374,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+376,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+378,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+380,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+382,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+384,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+386,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+388,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+390,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+392,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+394,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+396,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+398,"Top io_debug_valid", false,-1);
        tracep->declBit(c+399,"Top io_debug_trap", false,-1);
        tracep->declBus(c+400,"Top io_debug_inst", false,-1, 31,0);
        tracep->declBit(c+310,"Top core_clock", false,-1);
        tracep->declBit(c+311,"Top core_reset", false,-1);
        tracep->declBit(c+1,"Top core_io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core_io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+5,"Top core_io_imem_resp_valid", false,-1);
        tracep->declBus(c+6,"Top core_io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+7,"Top core_io_dmem_req_ready", false,-1);
        tracep->declBit(c+8,"Top core_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+9,"Top core_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+11,"Top core_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+13,"Top core_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+14,"Top core_io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+15,"Top core_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+16,"Top core_io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+18,"Top core_io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+20,"Top core_io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+22,"Top core_io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+24,"Top core_io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+26,"Top core_io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+28,"Top core_io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+30,"Top core_io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+32,"Top core_io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+34,"Top core_io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+36,"Top core_io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+38,"Top core_io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+40,"Top core_io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+42,"Top core_io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+44,"Top core_io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+46,"Top core_io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+48,"Top core_io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+50,"Top core_io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+52,"Top core_io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+54,"Top core_io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+56,"Top core_io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+58,"Top core_io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+60,"Top core_io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+62,"Top core_io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+64,"Top core_io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+66,"Top core_io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+68,"Top core_io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+70,"Top core_io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+72,"Top core_io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+74,"Top core_io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+76,"Top core_io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+78,"Top core_io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+80,"Top core_io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+82,"Top core_io_debug_valid", false,-1);
        tracep->declBit(c+83,"Top core_io_debug_trap", false,-1);
        tracep->declBit(c+1,"Top imem_req_ready", false,-1);
        tracep->declBit(c+5,"Top imem_resp_valid", false,-1);
        tracep->declBus(c+6,"Top imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+7,"Top dmem_req_ready", false,-1);
        tracep->declBit(c+15,"Top dmem_resp_valid", false,-1);
        tracep->declBit(c+310,"Top core clock", false,-1);
        tracep->declBit(c+311,"Top core reset", false,-1);
        tracep->declBit(c+1,"Top core io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+5,"Top core io_imem_resp_valid", false,-1);
        tracep->declBus(c+6,"Top core io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+7,"Top core io_dmem_req_ready", false,-1);
        tracep->declBit(c+8,"Top core io_dmem_req_valid", false,-1);
        tracep->declQuad(c+9,"Top core io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+11,"Top core io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+13,"Top core io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+14,"Top core io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+15,"Top core io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+16,"Top core io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+18,"Top core io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+20,"Top core io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+22,"Top core io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+24,"Top core io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+26,"Top core io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+28,"Top core io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+30,"Top core io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+32,"Top core io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+34,"Top core io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+36,"Top core io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+38,"Top core io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+40,"Top core io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+42,"Top core io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+44,"Top core io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+46,"Top core io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+48,"Top core io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+50,"Top core io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+52,"Top core io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+54,"Top core io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+56,"Top core io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+58,"Top core io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+60,"Top core io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+62,"Top core io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+64,"Top core io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+66,"Top core io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+68,"Top core io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+70,"Top core io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+72,"Top core io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+74,"Top core io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+76,"Top core io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+78,"Top core io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+80,"Top core io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+82,"Top core io_debug_valid", false,-1);
        tracep->declBit(c+83,"Top core io_debug_trap", false,-1);
        tracep->declBit(c+310,"Top core pre_top_clock", false,-1);
        tracep->declBit(c+311,"Top core pre_top_reset", false,-1);
        tracep->declBit(c+84,"Top core pre_top_io_fs_ready", false,-1);
        tracep->declBit(c+85,"Top core pre_top_io_fs_valid", false,-1);
        tracep->declQuad(c+86,"Top core pre_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+1,"Top core pre_top_io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core pre_top_io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core pre_top_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+88,"Top core pre_top_br_taken_0", false,-1);
        tracep->declQuad(c+89,"Top core pre_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+310,"Top core fs_top_clock", false,-1);
        tracep->declBit(c+311,"Top core fs_top_reset", false,-1);
        tracep->declBit(c+84,"Top core fs_top_io_pres_ready", false,-1);
        tracep->declBit(c+85,"Top core fs_top_io_pres_valid", false,-1);
        tracep->declQuad(c+86,"Top core fs_top_io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core fs_top_io_ds_ready", false,-1);
        tracep->declBit(c+92,"Top core fs_top_io_ds_valid", false,-1);
        tracep->declQuad(c+93,"Top core fs_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+6,"Top core fs_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+5,"Top core fs_top_io_imem_resp_valid", false,-1);
        tracep->declBus(c+6,"Top core fs_top_io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+310,"Top core ds_top_clock", false,-1);
        tracep->declBit(c+311,"Top core ds_top_reset", false,-1);
        tracep->declBit(c+91,"Top core ds_top_io_fs_ready", false,-1);
        tracep->declBit(c+92,"Top core ds_top_io_fs_valid", false,-1);
        tracep->declQuad(c+93,"Top core ds_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+6,"Top core ds_top_io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+95,"Top core ds_top_io_es_ready", false,-1);
        tracep->declBit(c+96,"Top core ds_top_io_es_valid", false,-1);
        tracep->declQuad(c+97,"Top core ds_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core ds_top_io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+100,"Top core ds_top_io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core ds_top_io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core ds_top_io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core ds_top_io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core ds_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core ds_top_io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+106,"Top core ds_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core ds_top_io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+108,"Top core ds_top_io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core ds_top_io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+112,"Top core ds_top_io_wb_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ds_top_io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top_io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ds_top_ms_res_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ds_top_ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ds_top_ms_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+16,"Top core ds_top__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+18,"Top core ds_top__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+20,"Top core ds_top__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+22,"Top core ds_top__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+24,"Top core ds_top__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+26,"Top core ds_top__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+28,"Top core ds_top__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+30,"Top core ds_top__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+32,"Top core ds_top__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+34,"Top core ds_top__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+36,"Top core ds_top__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+38,"Top core ds_top__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+40,"Top core ds_top__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+42,"Top core ds_top__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+44,"Top core ds_top__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+46,"Top core ds_top__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+48,"Top core ds_top__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+50,"Top core ds_top__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+52,"Top core ds_top__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+54,"Top core ds_top__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+56,"Top core ds_top__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+58,"Top core ds_top__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+60,"Top core ds_top__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+62,"Top core ds_top__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+64,"Top core ds_top__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+66,"Top core ds_top__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+68,"Top core ds_top__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+70,"Top core ds_top__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+72,"Top core ds_top__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+74,"Top core ds_top__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+76,"Top core ds_top__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+78,"Top core ds_top__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+83,"Top core ds_top_is_trap", false,-1);
        tracep->declBit(c+88,"Top core ds_top_br_taken_0", false,-1);
        tracep->declBit(c+120,"Top core ds_top_es_res_rf_we", false,-1);
        tracep->declBus(c+121,"Top core ds_top_es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core ds_top_es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ds_top_es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+89,"Top core ds_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+310,"Top core es_top_clock", false,-1);
        tracep->declBit(c+311,"Top core es_top_reset", false,-1);
        tracep->declBit(c+95,"Top core es_top_io_ds_ready", false,-1);
        tracep->declBit(c+96,"Top core es_top_io_ds_valid", false,-1);
        tracep->declQuad(c+97,"Top core es_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core es_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+100,"Top core es_top_io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core es_top_io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core es_top_io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core es_top_io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core es_top_io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core es_top_io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+106,"Top core es_top_io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core es_top_io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+108,"Top core es_top_io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core es_top_io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+125,"Top core es_top_io_ms_ready", false,-1);
        tracep->declBit(c+126,"Top core es_top_io_ms_valid", false,-1);
        tracep->declQuad(c+127,"Top core es_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+124,"Top core es_top_io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+120,"Top core es_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+13,"Top core es_top_io_ms_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+122,"Top core es_top_io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+121,"Top core es_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+7,"Top core es_top_io_dmem_req_ready", false,-1);
        tracep->declBit(c+8,"Top core es_top_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+9,"Top core es_top_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+11,"Top core es_top_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+13,"Top core es_top_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+14,"Top core es_top_io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+120,"Top core es_top_es_res_0_rf_we", false,-1);
        tracep->declBus(c+121,"Top core es_top_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core es_top_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core es_top_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+310,"Top core ms_top_clock", false,-1);
        tracep->declBit(c+311,"Top core ms_top_reset", false,-1);
        tracep->declBit(c+125,"Top core ms_top_io_es_ready", false,-1);
        tracep->declBit(c+126,"Top core ms_top_io_es_valid", false,-1);
        tracep->declQuad(c+127,"Top core ms_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ms_top_io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+120,"Top core ms_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+13,"Top core ms_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+122,"Top core ms_top_io_es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+121,"Top core ms_top_io_es_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+129,"Top core ms_top_io_ws_valid", false,-1);
        tracep->declQuad(c+130,"Top core ms_top_io_ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ms_top_io_ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+118,"Top core ms_top_io_ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+117,"Top core ms_top_io_ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+15,"Top core ms_top_io_dmem_resp_valid", false,-1);
        tracep->declBit(c+116,"Top core ms_top_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ms_top_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ms_top_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+310,"Top core ws_top_clock", false,-1);
        tracep->declBit(c+311,"Top core ws_top_reset", false,-1);
        tracep->declBit(c+401,"Top core ws_top_io_ms_ready", false,-1);
        tracep->declBit(c+129,"Top core ws_top_io_ms_valid", false,-1);
        tracep->declQuad(c+130,"Top core ws_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ws_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+118,"Top core ws_top_io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+117,"Top core ws_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top core ws_top_io_rf_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ws_top_io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ws_top_io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+80,"Top core ws_top_from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+82,"Top core ws_top_is_commit_0", false,-1);
        tracep->declBit(c+310,"Top core pre_top clock", false,-1);
        tracep->declBit(c+311,"Top core pre_top reset", false,-1);
        tracep->declBit(c+84,"Top core pre_top io_fs_ready", false,-1);
        tracep->declBit(c+85,"Top core pre_top io_fs_valid", false,-1);
        tracep->declQuad(c+86,"Top core pre_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+1,"Top core pre_top io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core pre_top io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core pre_top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+88,"Top core pre_top br_taken_0", false,-1);
        tracep->declQuad(c+89,"Top core pre_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+85,"Top core pre_top pre_ready_go", false,-1);
        tracep->declQuad(c+86,"Top core pre_top pre_pc", false,-1, 63,0);
        tracep->declBit(c+132,"Top core pre_top buf_valid", false,-1);
        tracep->declQuad(c+133,"Top core pre_top buf_npc", false,-1, 63,0);
        tracep->declQuad(c+135,"Top core pre_top seq_pc", false,-1, 63,0);
        tracep->declBit(c+2,"Top core pre_top imem_req_r", false,-1);
        tracep->declBit(c+310,"Top core fs_top clock", false,-1);
        tracep->declBit(c+311,"Top core fs_top reset", false,-1);
        tracep->declBit(c+84,"Top core fs_top io_pres_ready", false,-1);
        tracep->declBit(c+85,"Top core fs_top io_pres_valid", false,-1);
        tracep->declQuad(c+86,"Top core fs_top io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core fs_top io_ds_ready", false,-1);
        tracep->declBit(c+92,"Top core fs_top io_ds_valid", false,-1);
        tracep->declQuad(c+93,"Top core fs_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+6,"Top core fs_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+5,"Top core fs_top io_imem_resp_valid", false,-1);
        tracep->declBus(c+6,"Top core fs_top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declQuad(c+93,"Top core fs_top from_pre_r_PC", false,-1, 63,0);
        tracep->declBit(c+137,"Top core fs_top fs_ready_go", false,-1);
        tracep->declBit(c+138,"Top core fs_top fs_valid", false,-1);
        tracep->declBit(c+310,"Top core ds_top clock", false,-1);
        tracep->declBit(c+311,"Top core ds_top reset", false,-1);
        tracep->declBit(c+91,"Top core ds_top io_fs_ready", false,-1);
        tracep->declBit(c+92,"Top core ds_top io_fs_valid", false,-1);
        tracep->declQuad(c+93,"Top core ds_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+6,"Top core ds_top io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+95,"Top core ds_top io_es_ready", false,-1);
        tracep->declBit(c+96,"Top core ds_top io_es_valid", false,-1);
        tracep->declQuad(c+97,"Top core ds_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core ds_top io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+100,"Top core ds_top io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core ds_top io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core ds_top io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core ds_top io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core ds_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core ds_top io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+106,"Top core ds_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core ds_top io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+108,"Top core ds_top io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core ds_top io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+112,"Top core ds_top io_wb_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ds_top io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ds_top ms_res_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ds_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ds_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+83,"Top core ds_top is_trap", false,-1);
        tracep->declBit(c+88,"Top core ds_top br_taken_0", false,-1);
        tracep->declBit(c+120,"Top core ds_top es_res_rf_we", false,-1);
        tracep->declBus(c+121,"Top core ds_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core ds_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ds_top es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+89,"Top core ds_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+310,"Top core ds_top rf_clock", false,-1);
        tracep->declBus(c+139,"Top core ds_top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"Top core ds_top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top core ds_top rf_io_ws_res_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ds_top rf_io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top rf_io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+108,"Top core ds_top rf_io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core ds_top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+141,"Top core ds_top rf_io_wr_stall", false,-1);
        tracep->declBit(c+116,"Top core ds_top rf_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ds_top rf_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ds_top rf_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declQuad(c+16,"Top core ds_top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+18,"Top core ds_top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+20,"Top core ds_top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+22,"Top core ds_top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+24,"Top core ds_top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+26,"Top core ds_top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+28,"Top core ds_top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+30,"Top core ds_top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+32,"Top core ds_top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+34,"Top core ds_top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+36,"Top core ds_top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+38,"Top core ds_top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+40,"Top core ds_top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+42,"Top core ds_top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+44,"Top core ds_top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+46,"Top core ds_top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+48,"Top core ds_top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+50,"Top core ds_top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+52,"Top core ds_top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+54,"Top core ds_top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+56,"Top core ds_top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+58,"Top core ds_top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+60,"Top core ds_top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+62,"Top core ds_top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+64,"Top core ds_top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+66,"Top core ds_top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+68,"Top core ds_top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+70,"Top core ds_top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+72,"Top core ds_top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+74,"Top core ds_top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+76,"Top core ds_top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+78,"Top core ds_top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+120,"Top core ds_top rf_es_res_0_rf_we", false,-1);
        tracep->declBus(c+121,"Top core ds_top rf_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core ds_top rf_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ds_top rf_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+99,"Top core ds_top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+142,"Top core ds_top idu_io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+100,"Top core ds_top idu_io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core ds_top idu_io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core ds_top idu_io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core ds_top idu_io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core ds_top idu_io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core ds_top idu_io_ctrl_mem_en", false,-1);
        tracep->declBit(c+106,"Top core ds_top idu_io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core ds_top idu_io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+83,"Top core ds_top idu_is_trap_0", false,-1);
        tracep->declQuad(c+97,"Top core ds_top from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core ds_top from_fs_r_inst", false,-1, 31,0);
        tracep->declBit(c+143,"Top core ds_top ds_ready_go", false,-1);
        tracep->declBit(c+144,"Top core ds_top ds_valid", false,-1);
        tracep->declBus(c+145,"Top core ds_top imm_i", false,-1, 11,0);
        tracep->declBit(c+146,"Top core ds_top right_right", false,-1);
        tracep->declBit(c+147,"Top core ds_top right_left", false,-1);
        tracep->declBus(c+148,"Top core ds_top left_right", false,-1, 5,0);
        tracep->declBus(c+149,"Top core ds_top left_left", false,-1, 3,0);
        tracep->declBus(c+150,"Top core ds_top imm_b", false,-1, 11,0);
        tracep->declBus(c+151,"Top core ds_top right_left_1", false,-1, 7,0);
        tracep->declBit(c+152,"Top core ds_top left_right_1", false,-1);
        tracep->declBus(c+153,"Top core ds_top left_left_1", false,-1, 9,0);
        tracep->declBus(c+154,"Top core ds_top imm_j", false,-1, 19,0);
        tracep->declQuad(c+155,"Top core ds_top right_2", false,-1, 51,0);
        tracep->declQuad(c+157,"Top core ds_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+159,"Top core ds_top right_right_2", false,-1, 52,0);
        tracep->declArray(c+161,"Top core ds_top imm_b_sext", false,-1, 65,0);
        tracep->declQuad(c+164,"Top core ds_top right_right_3", false,-1, 52,0);
        tracep->declArray(c+166,"Top core ds_top imm_j_sext", false,-1, 73,0);
        tracep->declArray(c+169,"Top core ds_top branch_target", false,-1, 65,0);
        tracep->declArray(c+172,"Top core ds_top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+175,"Top core ds_top jr_target", false,-1, 63,0);
        tracep->declBit(c+177,"Top core ds_top rf_eq", false,-1);
        tracep->declBit(c+178,"Top core ds_top rf_lt", false,-1);
        tracep->declBit(c+179,"Top core ds_top rf_ltu", false,-1);
        tracep->declBus(c+180,"Top core ds_top flush_reg", false,-1, 1,0);
        tracep->declBit(c+88,"Top core ds_top br_taken", false,-1);
        tracep->declQuad(c+89,"Top core ds_top br_target", false,-1, 63,0);
        tracep->declBit(c+310,"Top core ds_top rf clock", false,-1);
        tracep->declBus(c+139,"Top core ds_top rf io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+140,"Top core ds_top rf io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top core ds_top rf io_ws_res_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ds_top rf io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top rf io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+108,"Top core ds_top rf io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core ds_top rf io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+141,"Top core ds_top rf io_wr_stall", false,-1);
        tracep->declBit(c+116,"Top core ds_top rf ms_res_0_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ds_top rf ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ds_top rf ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+120,"Top core ds_top rf es_res_0_rf_we", false,-1);
        tracep->declBus(c+121,"Top core ds_top rf es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core ds_top rf es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ds_top rf es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+310,"Top core ds_top rf rf_clock", false,-1);
        tracep->declBus(c+139,"Top core ds_top rf rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+181,"Top core ds_top rf rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+140,"Top core ds_top rf rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+183,"Top core ds_top rf rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+113,"Top core ds_top rf rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top rf rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+112,"Top core ds_top rf rf_io_wen", false,-1);
        tracep->declQuad(c+16,"Top core ds_top rf rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+18,"Top core ds_top rf rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+20,"Top core ds_top rf rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+22,"Top core ds_top rf rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+24,"Top core ds_top rf rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+26,"Top core ds_top rf rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+28,"Top core ds_top rf rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+30,"Top core ds_top rf rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+32,"Top core ds_top rf rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+34,"Top core ds_top rf rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+36,"Top core ds_top rf rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+38,"Top core ds_top rf rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+40,"Top core ds_top rf rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+42,"Top core ds_top rf rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+44,"Top core ds_top rf rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+46,"Top core ds_top rf rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+48,"Top core ds_top rf rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+50,"Top core ds_top rf rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+52,"Top core ds_top rf rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+54,"Top core ds_top rf rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+56,"Top core ds_top rf rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+58,"Top core ds_top rf rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+60,"Top core ds_top rf rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+62,"Top core ds_top rf rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+64,"Top core ds_top rf rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+66,"Top core ds_top rf rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+68,"Top core ds_top rf rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+70,"Top core ds_top rf rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+72,"Top core ds_top rf rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+74,"Top core ds_top rf rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+76,"Top core ds_top rf rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+78,"Top core ds_top rf rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+310,"Top core ds_top rf rf clock", false,-1);
        tracep->declBus(c+139,"Top core ds_top rf rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+181,"Top core ds_top rf rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+140,"Top core ds_top rf rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+183,"Top core ds_top rf rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+113,"Top core ds_top rf rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top rf rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+112,"Top core ds_top rf rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+185+i*2,"Top core ds_top rf rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+249,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+139,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+251,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+140,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+16,"Top core ds_top rf rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+402,"Top core ds_top rf rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+18,"Top core ds_top rf rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+403,"Top core ds_top rf rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+20,"Top core ds_top rf rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+404,"Top core ds_top rf rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"Top core ds_top rf rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+405,"Top core ds_top rf rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+24,"Top core ds_top rf rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+406,"Top core ds_top rf rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+26,"Top core ds_top rf rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+407,"Top core ds_top rf rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+28,"Top core ds_top rf rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+408,"Top core ds_top rf rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+30,"Top core ds_top rf rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+409,"Top core ds_top rf rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+32,"Top core ds_top rf rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+410,"Top core ds_top rf rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+34,"Top core ds_top rf rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+411,"Top core ds_top rf rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+36,"Top core ds_top rf rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+412,"Top core ds_top rf rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+38,"Top core ds_top rf rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+413,"Top core ds_top rf rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+40,"Top core ds_top rf rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+414,"Top core ds_top rf rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+42,"Top core ds_top rf rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+415,"Top core ds_top rf rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+44,"Top core ds_top rf rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+416,"Top core ds_top rf rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+46,"Top core ds_top rf rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+417,"Top core ds_top rf rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+48,"Top core ds_top rf rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+418,"Top core ds_top rf rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+50,"Top core ds_top rf rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+419,"Top core ds_top rf rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+52,"Top core ds_top rf rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+420,"Top core ds_top rf rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+54,"Top core ds_top rf rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+421,"Top core ds_top rf rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+56,"Top core ds_top rf rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+422,"Top core ds_top rf rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+58,"Top core ds_top rf rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+423,"Top core ds_top rf rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+60,"Top core ds_top rf rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+424,"Top core ds_top rf rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+62,"Top core ds_top rf rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+425,"Top core ds_top rf rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+64,"Top core ds_top rf rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+426,"Top core ds_top rf rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+66,"Top core ds_top rf rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+427,"Top core ds_top rf rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"Top core ds_top rf rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+428,"Top core ds_top rf rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+70,"Top core ds_top rf rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+429,"Top core ds_top rf rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+72,"Top core ds_top rf rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+430,"Top core ds_top rf rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+74,"Top core ds_top rf rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+431,"Top core ds_top rf rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+76,"Top core ds_top rf rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+432,"Top core ds_top rf rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+78,"Top core ds_top rf rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+433,"Top core ds_top rf rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ds_top rf rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+113,"Top core ds_top rf rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+401,"Top core ds_top rf rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+112,"Top core ds_top rf rf regfile_MPORT_en", false,-1);
        tracep->declBus(c+99,"Top core ds_top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+142,"Top core ds_top idu io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+100,"Top core ds_top idu io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core ds_top idu io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core ds_top idu io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core ds_top idu io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core ds_top idu io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core ds_top idu io_ctrl_mem_en", false,-1);
        tracep->declBit(c+106,"Top core ds_top idu io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core ds_top idu io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+83,"Top core ds_top idu is_trap_0", false,-1);
        tracep->declBit(c+83,"Top core ds_top idu is_trap", false,-1);
        tracep->declBit(c+310,"Top core es_top clock", false,-1);
        tracep->declBit(c+311,"Top core es_top reset", false,-1);
        tracep->declBit(c+95,"Top core es_top io_ds_ready", false,-1);
        tracep->declBit(c+96,"Top core es_top io_ds_valid", false,-1);
        tracep->declQuad(c+97,"Top core es_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core es_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+100,"Top core es_top io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+101,"Top core es_top io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+102,"Top core es_top io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+103,"Top core es_top io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+104,"Top core es_top io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+105,"Top core es_top io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+106,"Top core es_top io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+107,"Top core es_top io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+108,"Top core es_top io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+110,"Top core es_top io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+125,"Top core es_top io_ms_ready", false,-1);
        tracep->declBit(c+126,"Top core es_top io_ms_valid", false,-1);
        tracep->declQuad(c+127,"Top core es_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+124,"Top core es_top io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+120,"Top core es_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+13,"Top core es_top io_ms_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+122,"Top core es_top io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+121,"Top core es_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+7,"Top core es_top io_dmem_req_ready", false,-1);
        tracep->declBit(c+8,"Top core es_top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+9,"Top core es_top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+11,"Top core es_top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+13,"Top core es_top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+14,"Top core es_top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+120,"Top core es_top es_res_0_rf_we", false,-1);
        tracep->declBus(c+121,"Top core es_top es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core es_top es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core es_top es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+253,"Top core es_top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+254,"Top core es_top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+256,"Top core es_top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+9,"Top core es_top alu_io_out", false,-1, 63,0);
        tracep->declQuad(c+127,"Top core es_top from_ds_r_PC", false,-1, 63,0);
        tracep->declBus(c+258,"Top core es_top from_ds_r_inst", false,-1, 31,0);
        tracep->declBus(c+259,"Top core es_top from_ds_r_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+260,"Top core es_top from_ds_r_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+253,"Top core es_top from_ds_r_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core es_top from_ds_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+120,"Top core es_top from_ds_r_decode_rf_wen", false,-1);
        tracep->declBit(c+261,"Top core es_top from_ds_r_decode_mem_en", false,-1);
        tracep->declBit(c+13,"Top core es_top from_ds_r_decode_mem_wr", false,-1);
        tracep->declBus(c+14,"Top core es_top from_ds_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+262,"Top core es_top from_ds_r_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+11,"Top core es_top from_ds_r_rs2_data", false,-1, 63,0);
        tracep->declBit(c+264,"Top core es_top es_ready_go", false,-1);
        tracep->declBit(c+265,"Top core es_top es_valid", false,-1);
        tracep->declBus(c+266,"Top core es_top imm_i", false,-1, 11,0);
        tracep->declBus(c+267,"Top core es_top right", false,-1, 6,0);
        tracep->declBus(c+121,"Top core es_top left", false,-1, 4,0);
        tracep->declBus(c+268,"Top core es_top imm_s", false,-1, 11,0);
        tracep->declBus(c+269,"Top core es_top imm_u", false,-1, 19,0);
        tracep->declBus(c+270,"Top core es_top left_3", false,-1, 4,0);
        tracep->declBus(c+271,"Top core es_top imm_z", false,-1, 31,0);
        tracep->declQuad(c+272,"Top core es_top right_4", false,-1, 51,0);
        tracep->declQuad(c+274,"Top core es_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+276,"Top core es_top right_5", false,-1, 51,0);
        tracep->declQuad(c+278,"Top core es_top imm_s_sext", false,-1, 63,0);
        tracep->declBus(c+280,"Top core es_top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+281,"Top core es_top imm_u_sext", false,-1, 63,0);
        tracep->declBit(c+283,"Top core es_top dmem_req_r", false,-1);
        tracep->declBit(c+120,"Top core es_top es_res_rf_we", false,-1);
        tracep->declBus(c+121,"Top core es_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top core es_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+124,"Top core es_top es_res_wb_sel", false,-1, 1,0);
        tracep->declBus(c+253,"Top core es_top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+254,"Top core es_top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+256,"Top core es_top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+9,"Top core es_top alu io_out", false,-1, 63,0);
        tracep->declArray(c+284,"Top core es_top alu add_result", false,-1, 64,0);
        tracep->declQuad(c+287,"Top core es_top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+289,"Top core es_top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+291,"Top core es_top alu and_result", false,-1, 63,0);
        tracep->declBit(c+293,"Top core es_top alu sltu_result", false,-1);
        tracep->declBit(c+294,"Top core es_top alu slt_result", false,-1);
        tracep->declBus(c+295,"Top core es_top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+296,"Top core es_top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+298,"Top core es_top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+300,"Top core es_top alu srl_result", false,-1, 63,0);
        tracep->declQuad(c+302,"Top core es_top alu io_out_res", false,-1, 63,0);
        tracep->declBit(c+310,"Top core ms_top clock", false,-1);
        tracep->declBit(c+311,"Top core ms_top reset", false,-1);
        tracep->declBit(c+125,"Top core ms_top io_es_ready", false,-1);
        tracep->declBit(c+126,"Top core ms_top io_es_valid", false,-1);
        tracep->declQuad(c+127,"Top core ms_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+124,"Top core ms_top io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+120,"Top core ms_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+13,"Top core ms_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+122,"Top core ms_top io_es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+121,"Top core ms_top io_es_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+129,"Top core ms_top io_ws_valid", false,-1);
        tracep->declQuad(c+130,"Top core ms_top io_ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ms_top io_ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+118,"Top core ms_top io_ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+117,"Top core ms_top io_ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+15,"Top core ms_top io_dmem_resp_valid", false,-1);
        tracep->declBit(c+116,"Top core ms_top ms_res_0_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ms_top ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ms_top ms_res_0_wr_data", false,-1, 63,0);
        tracep->declQuad(c+130,"Top core ms_top from_es_r_PC", false,-1, 63,0);
        tracep->declBus(c+304,"Top core ms_top from_es_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+116,"Top core ms_top from_es_r_decode_rf_wen", false,-1);
        tracep->declBit(c+305,"Top core ms_top from_es_r_decode_mem_wr", false,-1);
        tracep->declQuad(c+118,"Top core ms_top from_es_r_alu_result", false,-1, 63,0);
        tracep->declBus(c+117,"Top core ms_top from_es_r_rd_addr", false,-1, 4,0);
        tracep->declBit(c+306,"Top core ms_top ms_valid", false,-1);
        tracep->declBus(c+307,"Top core ms_top unfinished_store", false,-1, 3,0);
        tracep->declBit(c+308,"Top core ms_top ms_ready_go", false,-1);
        tracep->declBit(c+116,"Top core ms_top ms_res_rf_we", false,-1);
        tracep->declBus(c+117,"Top core ms_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top core ms_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+304,"Top core ms_top ms_res_wb_sel", false,-1, 1,0);
        tracep->declBit(c+310,"Top core ws_top clock", false,-1);
        tracep->declBit(c+311,"Top core ws_top reset", false,-1);
        tracep->declBit(c+401,"Top core ws_top io_ms_ready", false,-1);
        tracep->declBit(c+129,"Top core ws_top io_ms_valid", false,-1);
        tracep->declQuad(c+130,"Top core ws_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+116,"Top core ws_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+118,"Top core ws_top io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+117,"Top core ws_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top core ws_top io_rf_rf_we", false,-1);
        tracep->declBus(c+113,"Top core ws_top io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top core ws_top io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+80,"Top core ws_top from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+82,"Top core ws_top is_commit_0", false,-1);
        tracep->declQuad(c+80,"Top core ws_top from_ms_r__PC", false,-1, 63,0);
        tracep->declBit(c+112,"Top core ws_top from_ms_r__decode_rf_wen", false,-1);
        tracep->declQuad(c+114,"Top core ws_top from_ms_r__final_result", false,-1, 63,0);
        tracep->declBus(c+113,"Top core ws_top from_ms_r__rd_addr", false,-1, 4,0);
        tracep->declBit(c+82,"Top core ws_top is_commit", false,-1);
        tracep->declBit(c+309,"Top core ws_top REG", false,-1);
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
        tracep->fullBit(oldp+1,(vlTOPp->Top__DOT__imem_req_ready));
        tracep->fullBit(oldp+2,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__imem_req_r));
        tracep->fullQData(oldp+3,(vlTOPp->Top__DOT__core__DOT__pre_top_io_imem_req_bits_addr),64);
        tracep->fullBit(oldp+5,(vlTOPp->Top__DOT__imem_resp_valid));
        tracep->fullIData(oldp+6,(vlTOPp->Top__DOT__imem_resp_bits_data),32);
        tracep->fullBit(oldp+7,(vlTOPp->Top__DOT__dmem_req_ready));
        tracep->fullBit(oldp+8,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
        tracep->fullQData(oldp+9,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
        tracep->fullQData(oldp+11,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
        tracep->fullBit(oldp+13,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
        tracep->fullCData(oldp+14,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
        tracep->fullBit(oldp+15,(vlTOPp->Top__DOT__dmem_resp_valid));
        tracep->fullQData(oldp+16,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+18,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+20,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+22,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+24,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+26,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+28,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+30,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+32,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+34,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+36,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+38,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+40,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+42,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+44,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+46,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+48,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+50,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+52,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+54,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+56,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+58,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+60,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+62,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+64,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+66,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+68,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+70,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+72,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+74,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+76,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+78,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+80,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC),64);
        tracep->fullBit(oldp+82,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__is_commit));
        tracep->fullBit(oldp+83,((0x6bU == (0x707fU 
                                            & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst))));
        tracep->fullBit(oldp+84,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
        tracep->fullBit(oldp+85,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
        tracep->fullQData(oldp+86,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
        tracep->fullBit(oldp+88,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
        tracep->fullQData(oldp+89,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
        tracep->fullBit(oldp+91,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
        tracep->fullBit(oldp+92,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
        tracep->fullQData(oldp+93,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
        tracep->fullBit(oldp+95,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
        tracep->fullBit(oldp+96,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
        tracep->fullQData(oldp+97,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
        tracep->fullIData(oldp+99,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
        tracep->fullCData(oldp+100,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
        tracep->fullCData(oldp+101,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
        tracep->fullCData(oldp+102,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
        tracep->fullCData(oldp+103,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
        tracep->fullBit(oldp+104,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
        tracep->fullBit(oldp+105,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
        tracep->fullBit(oldp+106,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
        tracep->fullCData(oldp+107,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
        tracep->fullQData(oldp+108,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+110,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+112,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
        tracep->fullCData(oldp+113,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
        tracep->fullQData(oldp+114,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
        tracep->fullBit(oldp+116,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
        tracep->fullCData(oldp+117,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
        tracep->fullQData(oldp+118,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
        tracep->fullBit(oldp+120,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
        tracep->fullCData(oldp+121,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 7U))),5);
        tracep->fullQData(oldp+122,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
        tracep->fullCData(oldp+124,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
        tracep->fullBit(oldp+125,(vlTOPp->Top__DOT__core__DOT__ms_top_io_es_ready));
        tracep->fullBit(oldp+126,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
        tracep->fullQData(oldp+127,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
        tracep->fullBit(oldp+129,(vlTOPp->Top__DOT__core__DOT__ms_top_io_ws_valid));
        tracep->fullQData(oldp+130,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
        tracep->fullBit(oldp+132,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
        tracep->fullQData(oldp+133,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
        tracep->fullQData(oldp+135,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
        tracep->fullBit(oldp+137,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
        tracep->fullBit(oldp+138,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
        tracep->fullCData(oldp+139,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+140,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x14U))),5);
        tracep->fullBit(oldp+141,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
        tracep->fullCData(oldp+142,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
        tracep->fullBit(oldp+143,((1U != (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
        tracep->fullBit(oldp+144,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
        tracep->fullSData(oldp+145,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+146,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+147,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 7U))));
        tracep->fullCData(oldp+148,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+149,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                             >> 8U))),4);
        tracep->fullSData(oldp+150,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
        tracep->fullCData(oldp+151,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+152,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+153,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+154,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
        tracep->fullQData(oldp+155,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+157,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+159,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+161,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
        tracep->fullQData(oldp+164,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+166,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
        tracep->fullWData(oldp+169,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
        tracep->fullWData(oldp+172,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
        tracep->fullQData(oldp+175,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
        tracep->fullBit(oldp+177,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
        tracep->fullBit(oldp+178,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
        tracep->fullBit(oldp+179,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
        tracep->fullCData(oldp+180,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
        tracep->fullQData(oldp+181,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+183,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
        tracep->fullQData(oldp+185,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+187,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+189,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+191,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+193,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+195,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+197,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+199,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+201,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+203,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+205,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+207,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+209,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+211,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+213,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+215,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+217,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+219,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+221,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+223,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+225,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+227,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+229,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+231,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+233,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+235,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+237,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+239,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+241,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+243,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+245,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+247,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+249,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+251,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullCData(oldp+253,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
        tracep->fullQData(oldp+254,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+256,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
        tracep->fullIData(oldp+258,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
        tracep->fullCData(oldp+259,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
        tracep->fullCData(oldp+260,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
        tracep->fullBit(oldp+261,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
        tracep->fullQData(oldp+262,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
        tracep->fullBit(oldp+264,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
        tracep->fullBit(oldp+265,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
        tracep->fullSData(oldp+266,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+267,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0x19U))),7);
        tracep->fullSData(oldp+268,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
        tracep->fullIData(oldp+269,((0xfffffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+270,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),5);
        tracep->fullIData(oldp+271,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+272,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+274,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+276,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+278,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
        tracep->fullIData(oldp+280,(((0x800000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+281,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
        tracep->fullBit(oldp+283,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
        tracep->fullWData(oldp+284,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),65);
        tracep->fullQData(oldp+287,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+289,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+291,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+293,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+294,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+295,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+296,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_7[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_7[0U])))),64);
        tracep->fullQData(oldp+298,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+300,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
        tracep->fullQData(oldp+302,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullCData(oldp+304,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
        tracep->fullBit(oldp+305,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
        tracep->fullBit(oldp+306,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
        tracep->fullCData(oldp+307,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
        tracep->fullBit(oldp+308,((0U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store))));
        tracep->fullBit(oldp+309,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
        tracep->fullBit(oldp+310,(vlTOPp->clock));
        tracep->fullBit(oldp+311,(vlTOPp->reset));
        tracep->fullBit(oldp+312,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+313,(vlTOPp->io_imem_req_valid));
        tracep->fullQData(oldp+314,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->fullIData(oldp+316,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+317,(vlTOPp->io_imem_req_bits_wr));
        tracep->fullCData(oldp+318,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+319,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+320,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+321,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+322,(vlTOPp->io_dmem_req_valid));
        tracep->fullQData(oldp+323,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->fullQData(oldp+325,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+327,(vlTOPp->io_dmem_req_bits_wr));
        tracep->fullCData(oldp+328,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+329,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+330,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullQData(oldp+332,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+334,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+336,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+338,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+340,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+342,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+344,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+346,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+348,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+350,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+352,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+354,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+356,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+358,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+360,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+362,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+364,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+366,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+368,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+370,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+372,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+374,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+376,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+378,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+380,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+382,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+384,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+386,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+388,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+390,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+392,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+394,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+396,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+398,(vlTOPp->io_debug_valid));
        tracep->fullBit(oldp+399,(vlTOPp->io_debug_trap));
        tracep->fullIData(oldp+400,(vlTOPp->io_debug_inst),32);
        tracep->fullBit(oldp+401,(1U));
        tracep->fullCData(oldp+402,(0U),5);
        tracep->fullCData(oldp+403,(1U),5);
        tracep->fullCData(oldp+404,(2U),5);
        tracep->fullCData(oldp+405,(3U),5);
        tracep->fullCData(oldp+406,(4U),5);
        tracep->fullCData(oldp+407,(5U),5);
        tracep->fullCData(oldp+408,(6U),5);
        tracep->fullCData(oldp+409,(7U),5);
        tracep->fullCData(oldp+410,(8U),5);
        tracep->fullCData(oldp+411,(9U),5);
        tracep->fullCData(oldp+412,(0xaU),5);
        tracep->fullCData(oldp+413,(0xbU),5);
        tracep->fullCData(oldp+414,(0xcU),5);
        tracep->fullCData(oldp+415,(0xdU),5);
        tracep->fullCData(oldp+416,(0xeU),5);
        tracep->fullCData(oldp+417,(0xfU),5);
        tracep->fullCData(oldp+418,(0x10U),5);
        tracep->fullCData(oldp+419,(0x11U),5);
        tracep->fullCData(oldp+420,(0x12U),5);
        tracep->fullCData(oldp+421,(0x13U),5);
        tracep->fullCData(oldp+422,(0x14U),5);
        tracep->fullCData(oldp+423,(0x15U),5);
        tracep->fullCData(oldp+424,(0x16U),5);
        tracep->fullCData(oldp+425,(0x17U),5);
        tracep->fullCData(oldp+426,(0x18U),5);
        tracep->fullCData(oldp+427,(0x19U),5);
        tracep->fullCData(oldp+428,(0x1aU),5);
        tracep->fullCData(oldp+429,(0x1bU),5);
        tracep->fullCData(oldp+430,(0x1cU),5);
        tracep->fullCData(oldp+431,(0x1dU),5);
        tracep->fullCData(oldp+432,(0x1eU),5);
        tracep->fullCData(oldp+433,(0x1fU),5);
    }
}
