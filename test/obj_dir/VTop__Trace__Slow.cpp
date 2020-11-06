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
        tracep->declBit(c+357,"clock", false,-1);
        tracep->declBit(c+358,"reset", false,-1);
        tracep->declBit(c+359,"io_imem_req_ready", false,-1);
        tracep->declBit(c+360,"io_imem_req_valid", false,-1);
        tracep->declQuad(c+361,"io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+363,"io_imem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+365,"io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+366,"io_imem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+367,"io_imem_resp_valid", false,-1);
        tracep->declQuad(c+368,"io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+370,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+371,"io_dmem_req_valid", false,-1);
        tracep->declQuad(c+372,"io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+374,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+376,"io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+377,"io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+378,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+379,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+381,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+383,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+385,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+387,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+389,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+391,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+393,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+395,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+397,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+399,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+401,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+403,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+405,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+407,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+409,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+411,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+413,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+415,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+417,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+419,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+421,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+423,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+425,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+427,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+429,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+431,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+433,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+435,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+437,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+439,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+441,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+443,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+445,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+447,"io_debug_valid", false,-1);
        tracep->declBit(c+448,"io_debug_trap", false,-1);
        tracep->declQuad(c+449,"io_debug_test", false,-1, 63,0);
        tracep->declBit(c+357,"Top clock", false,-1);
        tracep->declBit(c+358,"Top reset", false,-1);
        tracep->declBit(c+359,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+360,"Top io_imem_req_valid", false,-1);
        tracep->declQuad(c+361,"Top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+363,"Top io_imem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+365,"Top io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+366,"Top io_imem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+367,"Top io_imem_resp_valid", false,-1);
        tracep->declQuad(c+368,"Top io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+370,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+371,"Top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+372,"Top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+374,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+376,"Top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+377,"Top io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+378,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+379,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+381,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+383,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+385,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+387,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+389,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+391,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+393,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+395,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+397,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+399,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+401,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+403,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+405,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+407,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+409,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+411,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+413,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+415,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+417,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+419,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+421,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+423,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+425,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+427,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+429,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+431,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+433,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+435,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+437,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+439,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+441,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+443,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+445,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+447,"Top io_debug_valid", false,-1);
        tracep->declBit(c+448,"Top io_debug_trap", false,-1);
        tracep->declQuad(c+449,"Top io_debug_test", false,-1, 63,0);
        tracep->declBit(c+357,"Top core_clock", false,-1);
        tracep->declBit(c+358,"Top core_reset", false,-1);
        tracep->declBit(c+1,"Top core_io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core_io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+5,"Top core_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+6,"Top core_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+8,"Top core_io_dmem_req_ready", false,-1);
        tracep->declBit(c+9,"Top core_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+10,"Top core_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+12,"Top core_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+14,"Top core_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+15,"Top core_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+16,"Top core_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+17,"Top core_io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+19,"Top core_io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Top core_io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Top core_io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Top core_io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Top core_io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Top core_io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Top core_io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Top core_io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Top core_io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Top core_io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Top core_io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Top core_io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Top core_io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Top core_io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Top core_io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Top core_io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Top core_io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Top core_io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Top core_io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Top core_io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Top core_io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Top core_io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Top core_io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Top core_io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Top core_io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Top core_io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Top core_io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Top core_io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Top core_io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Top core_io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Top core_io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Top core_io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core_io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core_io_debug_valid", false,-1);
        tracep->declBit(c+86,"Top core_io_debug_trap", false,-1);
        tracep->declBit(c+1,"Top imem_req_ready", false,-1);
        tracep->declBit(c+5,"Top imem_resp_valid", false,-1);
        tracep->declQuad(c+6,"Top imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+8,"Top dmem_req_ready", false,-1);
        tracep->declBit(c+16,"Top dmem_resp_valid", false,-1);
        tracep->declQuad(c+17,"Top dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+357,"Top core clock", false,-1);
        tracep->declBit(c+358,"Top core reset", false,-1);
        tracep->declBit(c+1,"Top core io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+5,"Top core io_imem_resp_valid", false,-1);
        tracep->declQuad(c+6,"Top core io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+8,"Top core io_dmem_req_ready", false,-1);
        tracep->declBit(c+9,"Top core io_dmem_req_valid", false,-1);
        tracep->declQuad(c+10,"Top core io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+12,"Top core io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+14,"Top core io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+15,"Top core io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+16,"Top core io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+17,"Top core io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+19,"Top core io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Top core io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Top core io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Top core io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Top core io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Top core io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Top core io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Top core io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Top core io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Top core io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Top core io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Top core io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Top core io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Top core io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Top core io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Top core io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Top core io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Top core io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Top core io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Top core io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Top core io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Top core io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Top core io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Top core io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Top core io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Top core io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Top core io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Top core io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Top core io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Top core io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Top core io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Top core io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core io_debug_valid", false,-1);
        tracep->declBit(c+86,"Top core io_debug_trap", false,-1);
        tracep->declBit(c+357,"Top core pre_top_clock", false,-1);
        tracep->declBit(c+358,"Top core pre_top_reset", false,-1);
        tracep->declBit(c+87,"Top core pre_top_io_fs_ready", false,-1);
        tracep->declBit(c+88,"Top core pre_top_io_fs_valid", false,-1);
        tracep->declQuad(c+89,"Top core pre_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core pre_top_io_fs_bits_offset", false,-1);
        tracep->declBit(c+1,"Top core pre_top_io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core pre_top_io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core pre_top_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+92,"Top core pre_top_br_taken_0", false,-1);
        tracep->declQuad(c+93,"Top core pre_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+357,"Top core fs_top_clock", false,-1);
        tracep->declBit(c+358,"Top core fs_top_reset", false,-1);
        tracep->declBit(c+87,"Top core fs_top_io_pres_ready", false,-1);
        tracep->declBit(c+88,"Top core fs_top_io_pres_valid", false,-1);
        tracep->declQuad(c+89,"Top core fs_top_io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core fs_top_io_pres_bits_offset", false,-1);
        tracep->declBit(c+95,"Top core fs_top_io_ds_ready", false,-1);
        tracep->declBit(c+96,"Top core fs_top_io_ds_valid", false,-1);
        tracep->declQuad(c+97,"Top core fs_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core fs_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+5,"Top core fs_top_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+6,"Top core fs_top_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+357,"Top core ds_top_clock", false,-1);
        tracep->declBit(c+358,"Top core ds_top_reset", false,-1);
        tracep->declBit(c+95,"Top core ds_top_io_fs_ready", false,-1);
        tracep->declBit(c+96,"Top core ds_top_io_fs_valid", false,-1);
        tracep->declQuad(c+97,"Top core ds_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core ds_top_io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+100,"Top core ds_top_io_es_ready", false,-1);
        tracep->declBit(c+101,"Top core ds_top_io_es_valid", false,-1);
        tracep->declQuad(c+102,"Top core ds_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+104,"Top core ds_top_io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+105,"Top core ds_top_io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core ds_top_io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core ds_top_io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core ds_top_io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core ds_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core ds_top_io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+111,"Top core ds_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core ds_top_io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+113,"Top core ds_top_io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core ds_top_io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+117,"Top core ds_top_io_wb_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ds_top_io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top_io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ds_top_ms_res_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ds_top_ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ds_top_ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ds_top_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+19,"Top core ds_top__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Top core ds_top__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Top core ds_top__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Top core ds_top__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Top core ds_top__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Top core ds_top__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Top core ds_top__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Top core ds_top__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Top core ds_top__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Top core ds_top__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Top core ds_top__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Top core ds_top__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Top core ds_top__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Top core ds_top__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Top core ds_top__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Top core ds_top__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Top core ds_top__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Top core ds_top__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Top core ds_top__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Top core ds_top__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Top core ds_top__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Top core ds_top__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Top core ds_top__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Top core ds_top__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Top core ds_top__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Top core ds_top__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Top core ds_top__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Top core ds_top__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Top core ds_top__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Top core ds_top__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Top core ds_top__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Top core ds_top__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+86,"Top core ds_top_is_trap", false,-1);
        tracep->declBit(c+92,"Top core ds_top_br_taken_0", false,-1);
        tracep->declBit(c+125,"Top core ds_top_es_res_rf_we", false,-1);
        tracep->declBus(c+126,"Top core ds_top_es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core ds_top_es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ds_top_es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+93,"Top core ds_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+357,"Top core es_top_clock", false,-1);
        tracep->declBit(c+358,"Top core es_top_reset", false,-1);
        tracep->declBit(c+100,"Top core es_top_io_ds_ready", false,-1);
        tracep->declBit(c+101,"Top core es_top_io_ds_valid", false,-1);
        tracep->declQuad(c+102,"Top core es_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+104,"Top core es_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+105,"Top core es_top_io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core es_top_io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core es_top_io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core es_top_io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core es_top_io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core es_top_io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+111,"Top core es_top_io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core es_top_io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+113,"Top core es_top_io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core es_top_io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+130,"Top core es_top_io_ms_ready", false,-1);
        tracep->declBit(c+131,"Top core es_top_io_ms_valid", false,-1);
        tracep->declQuad(c+132,"Top core es_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+129,"Top core es_top_io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core es_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+14,"Top core es_top_io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+134,"Top core es_top_io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+127,"Top core es_top_io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+126,"Top core es_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+135,"Top core es_top_io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+8,"Top core es_top_io_dmem_req_ready", false,-1);
        tracep->declBit(c+9,"Top core es_top_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+10,"Top core es_top_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+12,"Top core es_top_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+14,"Top core es_top_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+15,"Top core es_top_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+125,"Top core es_top_es_res_0_rf_we", false,-1);
        tracep->declBus(c+126,"Top core es_top_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core es_top_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core es_top_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+357,"Top core ms_top_clock", false,-1);
        tracep->declBit(c+358,"Top core ms_top_reset", false,-1);
        tracep->declBit(c+130,"Top core ms_top_io__es_ready", false,-1);
        tracep->declBit(c+131,"Top core ms_top_io__es_valid", false,-1);
        tracep->declQuad(c+132,"Top core ms_top_io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ms_top_io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ms_top_io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+14,"Top core ms_top_io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+134,"Top core ms_top_io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+127,"Top core ms_top_io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+126,"Top core ms_top_io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+135,"Top core ms_top_io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+136,"Top core ms_top_io__ws_valid", false,-1);
        tracep->declQuad(c+137,"Top core ms_top_io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ms_top_io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+123,"Top core ms_top_io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+122,"Top core ms_top_io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+16,"Top core ms_top_io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+17,"Top core ms_top_io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ms_top_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ms_top_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ms_top_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ms_top_io_dmem_resp_valid", false,-1);
        tracep->declBit(c+357,"Top core ws_top_clock", false,-1);
        tracep->declBit(c+358,"Top core ws_top_reset", false,-1);
        tracep->declBit(c+451,"Top core ws_top_io_ms_ready", false,-1);
        tracep->declBit(c+136,"Top core ws_top_io_ms_valid", false,-1);
        tracep->declQuad(c+137,"Top core ws_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ws_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+123,"Top core ws_top_io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+122,"Top core ws_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+117,"Top core ws_top_io_rf_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ws_top_io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ws_top_io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core ws_top_from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core ws_top_is_commit_0", false,-1);
        tracep->declBit(c+357,"Top core pre_top clock", false,-1);
        tracep->declBit(c+358,"Top core pre_top reset", false,-1);
        tracep->declBit(c+87,"Top core pre_top io_fs_ready", false,-1);
        tracep->declBit(c+88,"Top core pre_top io_fs_valid", false,-1);
        tracep->declQuad(c+89,"Top core pre_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core pre_top io_fs_bits_offset", false,-1);
        tracep->declBit(c+1,"Top core pre_top io_imem_req_ready", false,-1);
        tracep->declBit(c+2,"Top core pre_top io_imem_req_valid", false,-1);
        tracep->declQuad(c+3,"Top core pre_top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+92,"Top core pre_top br_taken_0", false,-1);
        tracep->declQuad(c+93,"Top core pre_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+88,"Top core pre_top pre_ready_go", false,-1);
        tracep->declQuad(c+89,"Top core pre_top pre_pc", false,-1, 63,0);
        tracep->declBit(c+139,"Top core pre_top buf_valid", false,-1);
        tracep->declQuad(c+140,"Top core pre_top buf_npc", false,-1, 63,0);
        tracep->declQuad(c+142,"Top core pre_top seq_pc", false,-1, 63,0);
        tracep->declQuad(c+144,"Top core pre_top nextpc", false,-1, 63,0);
        tracep->declBit(c+2,"Top core pre_top imem_req_r", false,-1);
        tracep->declBit(c+357,"Top core fs_top clock", false,-1);
        tracep->declBit(c+358,"Top core fs_top reset", false,-1);
        tracep->declBit(c+87,"Top core fs_top io_pres_ready", false,-1);
        tracep->declBit(c+88,"Top core fs_top io_pres_valid", false,-1);
        tracep->declQuad(c+89,"Top core fs_top io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+91,"Top core fs_top io_pres_bits_offset", false,-1);
        tracep->declBit(c+95,"Top core fs_top io_ds_ready", false,-1);
        tracep->declBit(c+96,"Top core fs_top io_ds_valid", false,-1);
        tracep->declQuad(c+97,"Top core fs_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core fs_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+5,"Top core fs_top io_imem_resp_valid", false,-1);
        tracep->declQuad(c+6,"Top core fs_top io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+97,"Top core fs_top from_pre_r_PC", false,-1, 63,0);
        tracep->declBit(c+146,"Top core fs_top from_pre_r_offset", false,-1);
        tracep->declBit(c+147,"Top core fs_top fs_ready_go", false,-1);
        tracep->declBit(c+148,"Top core fs_top fs_valid", false,-1);
        tracep->declBit(c+357,"Top core ds_top clock", false,-1);
        tracep->declBit(c+358,"Top core ds_top reset", false,-1);
        tracep->declBit(c+95,"Top core ds_top io_fs_ready", false,-1);
        tracep->declBit(c+96,"Top core ds_top io_fs_valid", false,-1);
        tracep->declQuad(c+97,"Top core ds_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+99,"Top core ds_top io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+100,"Top core ds_top io_es_ready", false,-1);
        tracep->declBit(c+101,"Top core ds_top io_es_valid", false,-1);
        tracep->declQuad(c+102,"Top core ds_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+104,"Top core ds_top io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+105,"Top core ds_top io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core ds_top io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core ds_top io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core ds_top io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core ds_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core ds_top io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+111,"Top core ds_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core ds_top io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+113,"Top core ds_top io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core ds_top io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+117,"Top core ds_top io_wb_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ds_top io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ds_top ms_res_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ds_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ds_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ds_top io_dmem_resp_valid", false,-1);
        tracep->declBit(c+86,"Top core ds_top is_trap", false,-1);
        tracep->declBit(c+92,"Top core ds_top br_taken_0", false,-1);
        tracep->declBit(c+125,"Top core ds_top es_res_rf_we", false,-1);
        tracep->declBus(c+126,"Top core ds_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core ds_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ds_top es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+93,"Top core ds_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+357,"Top core ds_top rf_clock", false,-1);
        tracep->declBus(c+149,"Top core ds_top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+150,"Top core ds_top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+117,"Top core ds_top rf_io_ws_res_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ds_top rf_io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top rf_io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+113,"Top core ds_top rf_io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core ds_top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+151,"Top core ds_top rf_io_wr_stall", false,-1);
        tracep->declBit(c+121,"Top core ds_top rf_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ds_top rf_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ds_top rf_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ds_top rf_load_data_returned", false,-1);
        tracep->declQuad(c+19,"Top core ds_top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Top core ds_top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Top core ds_top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Top core ds_top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Top core ds_top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Top core ds_top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Top core ds_top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Top core ds_top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Top core ds_top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Top core ds_top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Top core ds_top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Top core ds_top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Top core ds_top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Top core ds_top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Top core ds_top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Top core ds_top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Top core ds_top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Top core ds_top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Top core ds_top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Top core ds_top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Top core ds_top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Top core ds_top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Top core ds_top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Top core ds_top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Top core ds_top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Top core ds_top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Top core ds_top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Top core ds_top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Top core ds_top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Top core ds_top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Top core ds_top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Top core ds_top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+125,"Top core ds_top rf_es_res_0_rf_we", false,-1);
        tracep->declBus(c+126,"Top core ds_top rf_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core ds_top rf_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ds_top rf_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+104,"Top core ds_top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+152,"Top core ds_top idu_io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+105,"Top core ds_top idu_io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core ds_top idu_io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core ds_top idu_io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core ds_top idu_io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core ds_top idu_io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core ds_top idu_io_ctrl_mem_en", false,-1);
        tracep->declBit(c+111,"Top core ds_top idu_io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core ds_top idu_io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Top core ds_top idu_is_trap_0", false,-1);
        tracep->declQuad(c+102,"Top core ds_top from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+104,"Top core ds_top from_fs_r_inst", false,-1, 31,0);
        tracep->declBit(c+153,"Top core ds_top ds_ready_go", false,-1);
        tracep->declBit(c+154,"Top core ds_top ds_valid", false,-1);
        tracep->declBus(c+155,"Top core ds_top imm_i", false,-1, 11,0);
        tracep->declBit(c+156,"Top core ds_top right_right", false,-1);
        tracep->declBit(c+157,"Top core ds_top right_left", false,-1);
        tracep->declBus(c+158,"Top core ds_top left_right", false,-1, 5,0);
        tracep->declBus(c+159,"Top core ds_top left_left", false,-1, 3,0);
        tracep->declBus(c+160,"Top core ds_top imm_b", false,-1, 11,0);
        tracep->declBus(c+161,"Top core ds_top right_left_1", false,-1, 7,0);
        tracep->declBit(c+162,"Top core ds_top left_right_1", false,-1);
        tracep->declBus(c+163,"Top core ds_top left_left_1", false,-1, 9,0);
        tracep->declBus(c+164,"Top core ds_top imm_j", false,-1, 19,0);
        tracep->declQuad(c+165,"Top core ds_top right_2", false,-1, 51,0);
        tracep->declQuad(c+167,"Top core ds_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+169,"Top core ds_top right_right_2", false,-1, 52,0);
        tracep->declArray(c+171,"Top core ds_top imm_b_sext", false,-1, 65,0);
        tracep->declQuad(c+174,"Top core ds_top right_right_3", false,-1, 52,0);
        tracep->declArray(c+176,"Top core ds_top imm_j_sext", false,-1, 73,0);
        tracep->declArray(c+179,"Top core ds_top branch_target", false,-1, 65,0);
        tracep->declArray(c+182,"Top core ds_top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+185,"Top core ds_top jr_target", false,-1, 63,0);
        tracep->declBit(c+187,"Top core ds_top rf_eq", false,-1);
        tracep->declBit(c+188,"Top core ds_top rf_lt", false,-1);
        tracep->declBit(c+189,"Top core ds_top rf_ltu", false,-1);
        tracep->declBus(c+190,"Top core ds_top flush_reg", false,-1, 1,0);
        tracep->declBit(c+92,"Top core ds_top br_taken", false,-1);
        tracep->declQuad(c+93,"Top core ds_top br_target", false,-1, 63,0);
        tracep->declBit(c+357,"Top core ds_top rf clock", false,-1);
        tracep->declBus(c+149,"Top core ds_top rf io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+150,"Top core ds_top rf io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+117,"Top core ds_top rf io_ws_res_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ds_top rf io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top rf io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+113,"Top core ds_top rf io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core ds_top rf io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+151,"Top core ds_top rf io_wr_stall", false,-1);
        tracep->declBit(c+121,"Top core ds_top rf ms_res_0_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ds_top rf ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ds_top rf ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ds_top rf load_data_returned", false,-1);
        tracep->declBit(c+125,"Top core ds_top rf es_res_0_rf_we", false,-1);
        tracep->declBus(c+126,"Top core ds_top rf es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core ds_top rf es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ds_top rf es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+357,"Top core ds_top rf rf_clock", false,-1);
        tracep->declBus(c+149,"Top core ds_top rf rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+191,"Top core ds_top rf rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+150,"Top core ds_top rf rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+193,"Top core ds_top rf rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+118,"Top core ds_top rf rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top rf rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+117,"Top core ds_top rf rf_io_wen", false,-1);
        tracep->declQuad(c+19,"Top core ds_top rf rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Top core ds_top rf rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Top core ds_top rf rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Top core ds_top rf rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Top core ds_top rf rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Top core ds_top rf rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Top core ds_top rf rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Top core ds_top rf rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Top core ds_top rf rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Top core ds_top rf rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Top core ds_top rf rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Top core ds_top rf rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Top core ds_top rf rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Top core ds_top rf rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Top core ds_top rf rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Top core ds_top rf rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Top core ds_top rf rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Top core ds_top rf rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Top core ds_top rf rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Top core ds_top rf rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Top core ds_top rf rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Top core ds_top rf rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Top core ds_top rf rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Top core ds_top rf rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Top core ds_top rf rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Top core ds_top rf rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Top core ds_top rf rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Top core ds_top rf rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Top core ds_top rf rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Top core ds_top rf rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Top core ds_top rf rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Top core ds_top rf rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+195,"Top core ds_top rf is_load", false,-1);
        tracep->declBit(c+357,"Top core ds_top rf rf clock", false,-1);
        tracep->declBus(c+149,"Top core ds_top rf rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+191,"Top core ds_top rf rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+150,"Top core ds_top rf rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+193,"Top core ds_top rf rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+118,"Top core ds_top rf rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top rf rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+117,"Top core ds_top rf rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+196+i*2,"Top core ds_top rf rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+260,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+149,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+262,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+150,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top core ds_top rf rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+452,"Top core ds_top rf rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+21,"Top core ds_top rf rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+453,"Top core ds_top rf rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"Top core ds_top rf rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+454,"Top core ds_top rf rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top core ds_top rf rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+455,"Top core ds_top rf rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"Top core ds_top rf rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+456,"Top core ds_top rf rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"Top core ds_top rf rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+457,"Top core ds_top rf rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+31,"Top core ds_top rf rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+458,"Top core ds_top rf rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top core ds_top rf rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+459,"Top core ds_top rf rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+35,"Top core ds_top rf rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+460,"Top core ds_top rf rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+37,"Top core ds_top rf rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+461,"Top core ds_top rf rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+39,"Top core ds_top rf rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+462,"Top core ds_top rf rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+41,"Top core ds_top rf rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+463,"Top core ds_top rf rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+43,"Top core ds_top rf rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+464,"Top core ds_top rf rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+45,"Top core ds_top rf rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+465,"Top core ds_top rf rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+47,"Top core ds_top rf rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+466,"Top core ds_top rf rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+49,"Top core ds_top rf rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+467,"Top core ds_top rf rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+51,"Top core ds_top rf rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+468,"Top core ds_top rf rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+53,"Top core ds_top rf rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+469,"Top core ds_top rf rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+55,"Top core ds_top rf rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+470,"Top core ds_top rf rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+57,"Top core ds_top rf rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+471,"Top core ds_top rf rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+59,"Top core ds_top rf rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+472,"Top core ds_top rf rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+61,"Top core ds_top rf rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+473,"Top core ds_top rf rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+63,"Top core ds_top rf rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+474,"Top core ds_top rf rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"Top core ds_top rf rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+475,"Top core ds_top rf rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+67,"Top core ds_top rf rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+476,"Top core ds_top rf rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+69,"Top core ds_top rf rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+477,"Top core ds_top rf rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"Top core ds_top rf rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+478,"Top core ds_top rf rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+73,"Top core ds_top rf rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+479,"Top core ds_top rf rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+75,"Top core ds_top rf rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+480,"Top core ds_top rf rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+77,"Top core ds_top rf rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+481,"Top core ds_top rf rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+79,"Top core ds_top rf rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+482,"Top core ds_top rf rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+81,"Top core ds_top rf rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+483,"Top core ds_top rf rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ds_top rf rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+118,"Top core ds_top rf rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+451,"Top core ds_top rf rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+117,"Top core ds_top rf rf regfile_MPORT_en", false,-1);
        tracep->declBus(c+104,"Top core ds_top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+152,"Top core ds_top idu io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+105,"Top core ds_top idu io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core ds_top idu io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core ds_top idu io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core ds_top idu io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core ds_top idu io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core ds_top idu io_ctrl_mem_en", false,-1);
        tracep->declBit(c+111,"Top core ds_top idu io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core ds_top idu io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Top core ds_top idu is_trap_0", false,-1);
        tracep->declBit(c+86,"Top core ds_top idu is_trap", false,-1);
        tracep->declBit(c+357,"Top core es_top clock", false,-1);
        tracep->declBit(c+358,"Top core es_top reset", false,-1);
        tracep->declBit(c+100,"Top core es_top io_ds_ready", false,-1);
        tracep->declBit(c+101,"Top core es_top io_ds_valid", false,-1);
        tracep->declQuad(c+102,"Top core es_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+104,"Top core es_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+105,"Top core es_top io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+106,"Top core es_top io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+107,"Top core es_top io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+108,"Top core es_top io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+109,"Top core es_top io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+110,"Top core es_top io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+111,"Top core es_top io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+112,"Top core es_top io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+113,"Top core es_top io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+115,"Top core es_top io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+130,"Top core es_top io_ms_ready", false,-1);
        tracep->declBit(c+131,"Top core es_top io_ms_valid", false,-1);
        tracep->declQuad(c+132,"Top core es_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+129,"Top core es_top io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core es_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+14,"Top core es_top io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+134,"Top core es_top io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+127,"Top core es_top io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+126,"Top core es_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+135,"Top core es_top io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+8,"Top core es_top io_dmem_req_ready", false,-1);
        tracep->declBit(c+9,"Top core es_top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+10,"Top core es_top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+12,"Top core es_top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+14,"Top core es_top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+15,"Top core es_top io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+125,"Top core es_top es_res_0_rf_we", false,-1);
        tracep->declBus(c+126,"Top core es_top es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core es_top es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core es_top es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+264,"Top core es_top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+265,"Top core es_top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+267,"Top core es_top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+269,"Top core es_top alu_io_out", false,-1, 63,0);
        tracep->declQuad(c+132,"Top core es_top from_ds_r_PC", false,-1, 63,0);
        tracep->declBus(c+271,"Top core es_top from_ds_r_inst", false,-1, 31,0);
        tracep->declBus(c+272,"Top core es_top from_ds_r_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+273,"Top core es_top from_ds_r_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+264,"Top core es_top from_ds_r_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+129,"Top core es_top from_ds_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core es_top from_ds_r_decode_rf_wen", false,-1);
        tracep->declBit(c+274,"Top core es_top from_ds_r_decode_mem_en", false,-1);
        tracep->declBit(c+14,"Top core es_top from_ds_r_decode_mem_wr", false,-1);
        tracep->declBus(c+134,"Top core es_top from_ds_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+275,"Top core es_top from_ds_r_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+277,"Top core es_top from_ds_r_rs2_data", false,-1, 63,0);
        tracep->declBit(c+279,"Top core es_top es_ready_go", false,-1);
        tracep->declBit(c+280,"Top core es_top es_valid", false,-1);
        tracep->declBus(c+281,"Top core es_top imm_i", false,-1, 11,0);
        tracep->declBus(c+282,"Top core es_top right", false,-1, 6,0);
        tracep->declBus(c+126,"Top core es_top left", false,-1, 4,0);
        tracep->declBus(c+283,"Top core es_top imm_s", false,-1, 11,0);
        tracep->declBus(c+284,"Top core es_top imm_u", false,-1, 19,0);
        tracep->declBus(c+285,"Top core es_top left_3", false,-1, 4,0);
        tracep->declBus(c+286,"Top core es_top imm_z", false,-1, 31,0);
        tracep->declQuad(c+287,"Top core es_top right_4", false,-1, 51,0);
        tracep->declQuad(c+289,"Top core es_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+291,"Top core es_top right_5", false,-1, 51,0);
        tracep->declQuad(c+293,"Top core es_top imm_s_sext", false,-1, 63,0);
        tracep->declBus(c+295,"Top core es_top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+296,"Top core es_top imm_u_sext", false,-1, 63,0);
        tracep->declBit(c+298,"Top core es_top dmem_req_r", false,-1);
        tracep->declBus(c+299,"Top core es_top offset", false,-1, 3,0);
        tracep->declBus(c+300,"Top core es_top offset_8", false,-1, 6,0);
        tracep->declQuad(c+301,"Top core es_top io_dmem_req_bits_addr_right", false,-1, 60,0);
        tracep->declBit(c+125,"Top core es_top es_res_rf_we", false,-1);
        tracep->declBus(c+126,"Top core es_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+127,"Top core es_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+129,"Top core es_top es_res_wb_sel", false,-1, 1,0);
        tracep->declBus(c+264,"Top core es_top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+265,"Top core es_top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+267,"Top core es_top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+269,"Top core es_top alu io_out", false,-1, 63,0);
        tracep->declQuad(c+303,"Top core es_top alu add2", false,-1, 63,0);
        tracep->declArray(c+305,"Top core es_top alu add_result", false,-1, 65,0);
        tracep->declQuad(c+308,"Top core es_top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+310,"Top core es_top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+312,"Top core es_top alu and_result", false,-1, 63,0);
        tracep->declBit(c+314,"Top core es_top alu sltu_result", false,-1);
        tracep->declBit(c+315,"Top core es_top alu slt_result", false,-1);
        tracep->declBus(c+316,"Top core es_top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+317,"Top core es_top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+319,"Top core es_top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+321,"Top core es_top alu srl_result", false,-1, 63,0);
        tracep->declBus(c+323,"Top core es_top alu shamt5", false,-1, 4,0);
        tracep->declBus(c+324,"Top core es_top alu sllw_result", false,-1, 31,0);
        tracep->declBus(c+325,"Top core es_top alu sraw_result", false,-1, 31,0);
        tracep->declBus(c+326,"Top core es_top alu srlw_result", false,-1, 31,0);
        tracep->declQuad(c+327,"Top core es_top alu io_out_res", false,-1, 63,0);
        tracep->declBus(c+329,"Top core es_top alu io_out_left", false,-1, 31,0);
        tracep->declBus(c+330,"Top core es_top alu io_out_right", false,-1, 31,0);
        tracep->declBus(c+331,"Top core es_top alu io_out_right_2", false,-1, 31,0);
        tracep->declBus(c+332,"Top core es_top alu io_out_right_3", false,-1, 31,0);
        tracep->declBus(c+333,"Top core es_top alu io_out_right_4", false,-1, 31,0);
        tracep->declBit(c+357,"Top core ms_top clock", false,-1);
        tracep->declBit(c+358,"Top core ms_top reset", false,-1);
        tracep->declBit(c+130,"Top core ms_top io__es_ready", false,-1);
        tracep->declBit(c+131,"Top core ms_top io__es_valid", false,-1);
        tracep->declQuad(c+132,"Top core ms_top io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+129,"Top core ms_top io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ms_top io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+14,"Top core ms_top io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+134,"Top core ms_top io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+127,"Top core ms_top io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+126,"Top core ms_top io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+135,"Top core ms_top io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+136,"Top core ms_top io__ws_valid", false,-1);
        tracep->declQuad(c+137,"Top core ms_top io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ms_top io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+123,"Top core ms_top io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+122,"Top core ms_top io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+16,"Top core ms_top io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+17,"Top core ms_top io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ms_top ms_res_0_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ms_top ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ms_top ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core ms_top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+137,"Top core ms_top from_es_r_PC", false,-1, 63,0);
        tracep->declBus(c+334,"Top core ms_top from_es_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+121,"Top core ms_top from_es_r_decode_rf_wen", false,-1);
        tracep->declBit(c+335,"Top core ms_top from_es_r_decode_mem_wr", false,-1);
        tracep->declBus(c+336,"Top core ms_top from_es_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+337,"Top core ms_top from_es_r_alu_result", false,-1, 63,0);
        tracep->declBus(c+122,"Top core ms_top from_es_r_rd_addr", false,-1, 4,0);
        tracep->declBus(c+339,"Top core ms_top from_es_r_load_offset", false,-1, 2,0);
        tracep->declBit(c+340,"Top core ms_top ms_valid", false,-1);
        tracep->declBus(c+341,"Top core ms_top unfinished_store", false,-1, 3,0);
        tracep->declBit(c+342,"Top core ms_top res_from_mem", false,-1);
        tracep->declBit(c+343,"Top core ms_top ms_ready_go", false,-1);
        tracep->declQuad(c+344,"Top core ms_top data", false,-1, 63,0);
        tracep->declBus(c+346,"Top core ms_top byte_", false,-1, 7,0);
        tracep->declQuad(c+347,"Top core ms_top right", false,-1, 55,0);
        tracep->declBus(c+349,"Top core ms_top half", false,-1, 15,0);
        tracep->declQuad(c+350,"Top core ms_top right_1", false,-1, 47,0);
        tracep->declBus(c+352,"Top core ms_top word", false,-1, 31,0);
        tracep->declBus(c+353,"Top core ms_top right_2", false,-1, 31,0);
        tracep->declQuad(c+354,"Top core ms_top load_final", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ms_top ms_res_rf_we", false,-1);
        tracep->declBus(c+122,"Top core ms_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+123,"Top core ms_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+334,"Top core ms_top ms_res_wb_sel", false,-1, 1,0);
        tracep->declBit(c+357,"Top core ws_top clock", false,-1);
        tracep->declBit(c+358,"Top core ws_top reset", false,-1);
        tracep->declBit(c+451,"Top core ws_top io_ms_ready", false,-1);
        tracep->declBit(c+136,"Top core ws_top io_ms_valid", false,-1);
        tracep->declQuad(c+137,"Top core ws_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+121,"Top core ws_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+123,"Top core ws_top io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+122,"Top core ws_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+117,"Top core ws_top io_rf_rf_we", false,-1);
        tracep->declBus(c+118,"Top core ws_top io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+119,"Top core ws_top io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core ws_top from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core ws_top is_commit_0", false,-1);
        tracep->declQuad(c+83,"Top core ws_top from_ms_r__PC", false,-1, 63,0);
        tracep->declBit(c+117,"Top core ws_top from_ms_r__decode_rf_wen", false,-1);
        tracep->declQuad(c+119,"Top core ws_top from_ms_r__final_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top core ws_top from_ms_r__rd_addr", false,-1, 4,0);
        tracep->declBit(c+85,"Top core ws_top is_commit", false,-1);
        tracep->declBit(c+356,"Top core ws_top REG", false,-1);
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
        tracep->fullQData(oldp+3,((0xfffffffffffffff8ULL 
                                   & vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc)),64);
        tracep->fullBit(oldp+5,(vlTOPp->Top__DOT__imem_resp_valid));
        tracep->fullQData(oldp+6,(vlTOPp->Top__DOT__imem_resp_bits_data),64);
        tracep->fullBit(oldp+8,(vlTOPp->Top__DOT__dmem_req_ready));
        tracep->fullBit(oldp+9,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
        tracep->fullQData(oldp+10,((0xfffffffffffffff8ULL 
                                    & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
        tracep->fullQData(oldp+12,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
        tracep->fullBit(oldp+14,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
        tracep->fullCData(oldp+15,((0xffU & vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
        tracep->fullBit(oldp+16,(vlTOPp->Top__DOT__dmem_resp_valid));
        tracep->fullQData(oldp+17,(vlTOPp->Top__DOT__dmem_resp_bits_data),64);
        tracep->fullQData(oldp+19,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+21,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+23,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+25,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+27,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+29,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+31,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+33,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+35,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+37,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+39,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+41,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+43,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+45,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+47,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+49,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+51,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+53,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+55,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+57,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+59,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+61,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+63,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+65,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+67,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+69,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+71,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+73,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+75,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+77,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+79,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+81,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+83,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC),64);
        tracep->fullBit(oldp+85,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__is_commit));
        tracep->fullBit(oldp+86,((0x6bU == (0x707fU 
                                            & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst))));
        tracep->fullBit(oldp+87,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
        tracep->fullBit(oldp+88,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
        tracep->fullQData(oldp+89,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
        tracep->fullBit(oldp+91,((1U & (IData)((vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                >> 2U)))));
        tracep->fullBit(oldp+92,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
        tracep->fullQData(oldp+93,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
        tracep->fullBit(oldp+95,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
        tracep->fullBit(oldp+96,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
        tracep->fullQData(oldp+97,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
        tracep->fullIData(oldp+99,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
        tracep->fullBit(oldp+100,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
        tracep->fullBit(oldp+101,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
        tracep->fullQData(oldp+102,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
        tracep->fullIData(oldp+104,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
        tracep->fullCData(oldp+105,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
        tracep->fullCData(oldp+106,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
        tracep->fullCData(oldp+107,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
        tracep->fullCData(oldp+108,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
        tracep->fullBit(oldp+109,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
        tracep->fullBit(oldp+110,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
        tracep->fullBit(oldp+111,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
        tracep->fullCData(oldp+112,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
        tracep->fullQData(oldp+113,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+115,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+117,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
        tracep->fullCData(oldp+118,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
        tracep->fullQData(oldp+119,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
        tracep->fullBit(oldp+121,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
        tracep->fullCData(oldp+122,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
        tracep->fullQData(oldp+123,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
        tracep->fullBit(oldp+125,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
        tracep->fullCData(oldp+126,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 7U))),5);
        tracep->fullQData(oldp+127,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
        tracep->fullCData(oldp+129,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
        tracep->fullBit(oldp+130,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fes_ready));
        tracep->fullBit(oldp+131,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
        tracep->fullQData(oldp+132,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
        tracep->fullCData(oldp+134,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
        tracep->fullCData(oldp+135,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
        tracep->fullBit(oldp+136,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_valid));
        tracep->fullQData(oldp+137,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
        tracep->fullBit(oldp+139,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
        tracep->fullQData(oldp+140,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
        tracep->fullQData(oldp+142,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
        tracep->fullQData(oldp+144,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc),64);
        tracep->fullBit(oldp+146,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
        tracep->fullBit(oldp+147,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
        tracep->fullBit(oldp+148,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
        tracep->fullCData(oldp+149,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+150,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x14U))),5);
        tracep->fullBit(oldp+151,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
        tracep->fullCData(oldp+152,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
        tracep->fullBit(oldp+153,((1U & (~ (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
        tracep->fullBit(oldp+154,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
        tracep->fullSData(oldp+155,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+156,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+157,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 7U))));
        tracep->fullCData(oldp+158,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+159,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                             >> 8U))),4);
        tracep->fullSData(oldp+160,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
        tracep->fullCData(oldp+161,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+162,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+163,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+164,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
        tracep->fullQData(oldp+165,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+167,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+169,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+171,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
        tracep->fullQData(oldp+174,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+176,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
        tracep->fullWData(oldp+179,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
        tracep->fullWData(oldp+182,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
        tracep->fullQData(oldp+185,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
        tracep->fullBit(oldp+187,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
        tracep->fullBit(oldp+188,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
        tracep->fullBit(oldp+189,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
        tracep->fullCData(oldp+190,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
        tracep->fullQData(oldp+191,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+193,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+195,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
        tracep->fullQData(oldp+196,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+198,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+200,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+202,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+204,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+206,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+208,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+210,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+212,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+214,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+216,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+218,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+220,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+222,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+224,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+226,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+228,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+230,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+232,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+234,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+236,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+238,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+240,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+242,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+244,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+246,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+248,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+250,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+252,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+254,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+256,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+258,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+260,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+262,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullCData(oldp+264,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
        tracep->fullQData(oldp+265,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+267,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
        tracep->fullQData(oldp+269,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
        tracep->fullIData(oldp+271,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
        tracep->fullCData(oldp+272,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
        tracep->fullCData(oldp+273,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
        tracep->fullBit(oldp+274,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
        tracep->fullQData(oldp+275,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
        tracep->fullQData(oldp+277,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
        tracep->fullBit(oldp+279,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
        tracep->fullBit(oldp+280,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
        tracep->fullSData(oldp+281,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+282,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0x19U))),7);
        tracep->fullSData(oldp+283,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
        tracep->fullIData(oldp+284,((0xfffffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+285,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),5);
        tracep->fullIData(oldp+286,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+287,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+289,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+291,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+293,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
        tracep->fullIData(oldp+295,(((0x800000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+296,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
        tracep->fullBit(oldp+298,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
        tracep->fullCData(oldp+299,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
        tracep->fullCData(oldp+300,((0x38U & ((IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                              << 3U))),7);
        tracep->fullQData(oldp+301,((0x1fffffffffffffffULL 
                                     & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out 
                                        >> 3U))),61);
        tracep->fullQData(oldp+303,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
        tracep->fullWData(oldp+305,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
        tracep->fullQData(oldp+308,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+310,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+312,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+314,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+315,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+316,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+317,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
        tracep->fullQData(oldp+319,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+321,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
        tracep->fullCData(oldp+323,((0x1fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
        tracep->fullIData(oldp+324,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
        tracep->fullIData(oldp+325,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
        tracep->fullIData(oldp+326,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
        tracep->fullQData(oldp+327,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullIData(oldp+329,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
        tracep->fullIData(oldp+330,(((0x80000000U & 
                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+331,(((0x80000000U & 
                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+332,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+333,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullCData(oldp+334,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
        tracep->fullBit(oldp+335,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
        tracep->fullCData(oldp+336,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
        tracep->fullQData(oldp+337,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
        tracep->fullCData(oldp+339,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
        tracep->fullBit(oldp+340,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
        tracep->fullCData(oldp+341,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
        tracep->fullBit(oldp+342,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
        tracep->fullBit(oldp+343,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_ready_go));
        tracep->fullQData(oldp+344,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data),64);
        tracep->fullCData(oldp+346,((0xffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),8);
        tracep->fullQData(oldp+347,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 7U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullSData(oldp+349,((0xffffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),16);
        tracep->fullQData(oldp+350,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0xfU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullIData(oldp+352,((IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data)),32);
        tracep->fullIData(oldp+353,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0x1fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+354,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__load_final),64);
        tracep->fullBit(oldp+356,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
        tracep->fullBit(oldp+357,(vlTOPp->clock));
        tracep->fullBit(oldp+358,(vlTOPp->reset));
        tracep->fullBit(oldp+359,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+360,(vlTOPp->io_imem_req_valid));
        tracep->fullQData(oldp+361,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->fullQData(oldp+363,(vlTOPp->io_imem_req_bits_data),64);
        tracep->fullBit(oldp+365,(vlTOPp->io_imem_req_bits_wr));
        tracep->fullCData(oldp+366,(vlTOPp->io_imem_req_bits_msk),8);
        tracep->fullBit(oldp+367,(vlTOPp->io_imem_resp_valid));
        tracep->fullQData(oldp+368,(vlTOPp->io_imem_resp_bits_data),64);
        tracep->fullBit(oldp+370,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+371,(vlTOPp->io_dmem_req_valid));
        tracep->fullQData(oldp+372,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->fullQData(oldp+374,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+376,(vlTOPp->io_dmem_req_bits_wr));
        tracep->fullCData(oldp+377,(vlTOPp->io_dmem_req_bits_msk),8);
        tracep->fullBit(oldp+378,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+379,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullQData(oldp+381,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+383,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+385,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+387,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+389,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+391,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+393,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+395,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+397,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+399,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+401,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+403,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+405,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+407,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+409,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+411,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+413,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+415,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+417,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+419,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+421,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+423,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+425,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+427,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+429,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+431,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+433,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+435,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+437,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+439,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+441,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+443,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+445,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+447,(vlTOPp->io_debug_valid));
        tracep->fullBit(oldp+448,(vlTOPp->io_debug_trap));
        tracep->fullQData(oldp+449,(vlTOPp->io_debug_test),64);
        tracep->fullBit(oldp+451,(1U));
        tracep->fullCData(oldp+452,(0U),5);
        tracep->fullCData(oldp+453,(1U),5);
        tracep->fullCData(oldp+454,(2U),5);
        tracep->fullCData(oldp+455,(3U),5);
        tracep->fullCData(oldp+456,(4U),5);
        tracep->fullCData(oldp+457,(5U),5);
        tracep->fullCData(oldp+458,(6U),5);
        tracep->fullCData(oldp+459,(7U),5);
        tracep->fullCData(oldp+460,(8U),5);
        tracep->fullCData(oldp+461,(9U),5);
        tracep->fullCData(oldp+462,(0xaU),5);
        tracep->fullCData(oldp+463,(0xbU),5);
        tracep->fullCData(oldp+464,(0xcU),5);
        tracep->fullCData(oldp+465,(0xdU),5);
        tracep->fullCData(oldp+466,(0xeU),5);
        tracep->fullCData(oldp+467,(0xfU),5);
        tracep->fullCData(oldp+468,(0x10U),5);
        tracep->fullCData(oldp+469,(0x11U),5);
        tracep->fullCData(oldp+470,(0x12U),5);
        tracep->fullCData(oldp+471,(0x13U),5);
        tracep->fullCData(oldp+472,(0x14U),5);
        tracep->fullCData(oldp+473,(0x15U),5);
        tracep->fullCData(oldp+474,(0x16U),5);
        tracep->fullCData(oldp+475,(0x17U),5);
        tracep->fullCData(oldp+476,(0x18U),5);
        tracep->fullCData(oldp+477,(0x19U),5);
        tracep->fullCData(oldp+478,(0x1aU),5);
        tracep->fullCData(oldp+479,(0x1bU),5);
        tracep->fullCData(oldp+480,(0x1cU),5);
        tracep->fullCData(oldp+481,(0x1dU),5);
        tracep->fullCData(oldp+482,(0x1eU),5);
        tracep->fullCData(oldp+483,(0x1fU),5);
    }
}
