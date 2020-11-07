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
        tracep->declBit(c+436,"clock", false,-1);
        tracep->declBit(c+437,"reset", false,-1);
        tracep->declQuad(c+438,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+440,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+442,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+444,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+446,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+448,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+450,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+452,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+454,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+456,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+458,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+460,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+462,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+464,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+466,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+468,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+470,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+472,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+474,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+476,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+478,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+480,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+482,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+484,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+486,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+488,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+490,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+492,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+494,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+496,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+498,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+500,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+502,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+504,"io_debug_valid", false,-1);
        tracep->declBit(c+505,"io_debug_trap", false,-1);
        tracep->declQuad(c+506,"io_debug_test", false,-1, 63,0);
        tracep->declBit(c+436,"Soc clock", false,-1);
        tracep->declBit(c+437,"Soc reset", false,-1);
        tracep->declQuad(c+438,"Soc io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+440,"Soc io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+442,"Soc io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+444,"Soc io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+446,"Soc io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+448,"Soc io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+450,"Soc io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+452,"Soc io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+454,"Soc io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+456,"Soc io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+458,"Soc io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+460,"Soc io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+462,"Soc io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+464,"Soc io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+466,"Soc io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+468,"Soc io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+470,"Soc io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+472,"Soc io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+474,"Soc io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+476,"Soc io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+478,"Soc io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+480,"Soc io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+482,"Soc io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+484,"Soc io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+486,"Soc io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+488,"Soc io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+490,"Soc io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+492,"Soc io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+494,"Soc io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+496,"Soc io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+498,"Soc io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+500,"Soc io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+502,"Soc io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+504,"Soc io_debug_valid", false,-1);
        tracep->declBit(c+505,"Soc io_debug_trap", false,-1);
        tracep->declQuad(c+506,"Soc io_debug_test", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core_clock", false,-1);
        tracep->declBit(c+437,"Soc core_reset", false,-1);
        tracep->declBit(c+3,"Soc core_io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Soc core_io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Soc core_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+7,"Soc core_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+10,"Soc core_io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Soc core_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Soc core_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc core_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Soc core_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Soc core_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+18,"Soc core_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core_io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+19,"Soc core_io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Soc core_io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Soc core_io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Soc core_io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Soc core_io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Soc core_io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Soc core_io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Soc core_io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Soc core_io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Soc core_io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Soc core_io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Soc core_io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Soc core_io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Soc core_io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Soc core_io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Soc core_io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Soc core_io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Soc core_io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Soc core_io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Soc core_io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Soc core_io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Soc core_io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Soc core_io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Soc core_io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Soc core_io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Soc core_io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Soc core_io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Soc core_io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Soc core_io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Soc core_io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Soc core_io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Soc core_io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+83,"Soc core_io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Soc core_io_debug_valid", false,-1);
        tracep->declBit(c+86,"Soc core_io_debug_trap", false,-1);
        tracep->declBus(c+509,"Soc ram_awid", false,-1, 7,0);
        tracep->declQuad(c+87,"Soc ram_awaddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc ram_awlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc ram_awsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc ram_awburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc ram_awlock", false,-1);
        tracep->declBus(c+513,"Soc ram_awcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc ram_awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Soc ram_awvalid", false,-1);
        tracep->declBit(c+90,"Soc ram_awready", false,-1);
        tracep->declBus(c+509,"Soc ram_wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Soc ram_wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Soc ram_wstrb", false,-1, 7,0);
        tracep->declBit(c+515,"Soc ram_wlast", false,-1);
        tracep->declBit(c+94,"Soc ram_wvalid", false,-1);
        tracep->declBit(c+95,"Soc ram_wready", false,-1);
        tracep->declBus(c+96,"Soc ram_bid", false,-1, 7,0);
        tracep->declBus(c+511,"Soc ram_bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Soc ram_bvalid", false,-1);
        tracep->declBit(c+515,"Soc ram_bready", false,-1);
        tracep->declBus(c+509,"Soc ram_arid", false,-1, 7,0);
        tracep->declQuad(c+87,"Soc ram_araddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc ram_arlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc ram_arsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc ram_arburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc ram_arlock", false,-1);
        tracep->declBus(c+513,"Soc ram_arcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc ram_arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Soc ram_arvalid", false,-1);
        tracep->declBit(c+99,"Soc ram_arready", false,-1);
        tracep->declBus(c+100,"Soc ram_rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Soc ram_rdata", false,-1, 63,0);
        tracep->declBus(c+511,"Soc ram_rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Soc ram_rlast", false,-1);
        tracep->declBit(c+102,"Soc ram_rvalid", false,-1);
        tracep->declBit(c+515,"Soc ram_rready", false,-1);
        tracep->declBit(c+436,"Soc ram_clock", false,-1);
        tracep->declBit(c+437,"Soc ram_reset", false,-1);
        tracep->declBus(c+509,"Soc bridge_awid", false,-1, 7,0);
        tracep->declQuad(c+87,"Soc bridge_awaddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc bridge_awlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc bridge_awsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc bridge_awburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc bridge_awlock", false,-1);
        tracep->declBus(c+513,"Soc bridge_awcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc bridge_awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Soc bridge_awvalid", false,-1);
        tracep->declBit(c+90,"Soc bridge_awready", false,-1);
        tracep->declBus(c+509,"Soc bridge_wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Soc bridge_wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Soc bridge_wstrb", false,-1, 7,0);
        tracep->declBit(c+515,"Soc bridge_wlast", false,-1);
        tracep->declBit(c+94,"Soc bridge_wvalid", false,-1);
        tracep->declBit(c+95,"Soc bridge_wready", false,-1);
        tracep->declBus(c+96,"Soc bridge_bid", false,-1, 7,0);
        tracep->declBus(c+511,"Soc bridge_bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Soc bridge_bvalid", false,-1);
        tracep->declBit(c+515,"Soc bridge_bready", false,-1);
        tracep->declBus(c+509,"Soc bridge_arid", false,-1, 7,0);
        tracep->declQuad(c+87,"Soc bridge_araddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc bridge_arlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc bridge_arsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc bridge_arburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc bridge_arlock", false,-1);
        tracep->declBus(c+513,"Soc bridge_arcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc bridge_arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Soc bridge_arvalid", false,-1);
        tracep->declBit(c+99,"Soc bridge_arready", false,-1);
        tracep->declBus(c+100,"Soc bridge_rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Soc bridge_rdata", false,-1, 63,0);
        tracep->declBus(c+511,"Soc bridge_rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Soc bridge_rlast", false,-1);
        tracep->declBit(c+102,"Soc bridge_rvalid", false,-1);
        tracep->declBit(c+515,"Soc bridge_rready", false,-1);
        tracep->declBit(c+436,"Soc bridge_clock", false,-1);
        tracep->declBit(c+437,"Soc bridge_reset", false,-1);
        tracep->declBit(c+4,"Soc bridge_inst_req", false,-1);
        tracep->declBit(c+512,"Soc bridge_inst_wr", false,-1);
        tracep->declBus(c+516,"Soc bridge_inst_size", false,-1, 7,0);
        tracep->declQuad(c+5,"Soc bridge_inst_addr", false,-1, 63,0);
        tracep->declQuad(c+517,"Soc bridge_inst_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Soc bridge_inst_rdata", false,-1, 63,0);
        tracep->declBit(c+3,"Soc bridge_inst_addr_ok", false,-1);
        tracep->declBit(c+7,"Soc bridge_inst_data_ok", false,-1);
        tracep->declBit(c+11,"Soc bridge_data_req", false,-1);
        tracep->declBit(c+16,"Soc bridge_data_wr", false,-1);
        tracep->declBus(c+17,"Soc bridge_data_size", false,-1, 7,0);
        tracep->declQuad(c+12,"Soc bridge_data_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc bridge_data_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Soc bridge_data_rdata", false,-1, 63,0);
        tracep->declBit(c+10,"Soc bridge_data_addr_ok", false,-1);
        tracep->declBit(c+18,"Soc bridge_data_data_ok", false,-1);
        tracep->declBit(c+436,"Soc core clock", false,-1);
        tracep->declBit(c+437,"Soc core reset", false,-1);
        tracep->declBit(c+3,"Soc core io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Soc core io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Soc core io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+7,"Soc core io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+10,"Soc core io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Soc core io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Soc core io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc core io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Soc core io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Soc core io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+18,"Soc core io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+19,"Soc core io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Soc core io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Soc core io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Soc core io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Soc core io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Soc core io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Soc core io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Soc core io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Soc core io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Soc core io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Soc core io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Soc core io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Soc core io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Soc core io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Soc core io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Soc core io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Soc core io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Soc core io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Soc core io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Soc core io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Soc core io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Soc core io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Soc core io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Soc core io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Soc core io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Soc core io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Soc core io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Soc core io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Soc core io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Soc core io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Soc core io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Soc core io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+83,"Soc core io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Soc core io_debug_valid", false,-1);
        tracep->declBit(c+86,"Soc core io_debug_trap", false,-1);
        tracep->declBit(c+436,"Soc core pre_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core pre_top_reset", false,-1);
        tracep->declBit(c+103,"Soc core pre_top_io_fs_ready", false,-1);
        tracep->declBit(c+104,"Soc core pre_top_io_fs_valid", false,-1);
        tracep->declQuad(c+105,"Soc core pre_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Soc core pre_top_io_fs_bits_offset", false,-1);
        tracep->declBit(c+3,"Soc core pre_top_io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Soc core pre_top_io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Soc core pre_top_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+108,"Soc core pre_top_br_taken_0", false,-1);
        tracep->declQuad(c+109,"Soc core pre_top_br_old_PC_0", false,-1, 63,0);
        tracep->declBus(c+111,"Soc core pre_top_insts_sent_after_br_0", false,-1, 1,0);
        tracep->declQuad(c+112,"Soc core pre_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core fs_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core fs_top_reset", false,-1);
        tracep->declBit(c+103,"Soc core fs_top_io_pres_ready", false,-1);
        tracep->declBit(c+104,"Soc core fs_top_io_pres_valid", false,-1);
        tracep->declQuad(c+105,"Soc core fs_top_io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Soc core fs_top_io_pres_bits_offset", false,-1);
        tracep->declBit(c+114,"Soc core fs_top_io_ds_ready", false,-1);
        tracep->declBit(c+115,"Soc core fs_top_io_ds_valid", false,-1);
        tracep->declQuad(c+116,"Soc core fs_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+118,"Soc core fs_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+7,"Soc core fs_top_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core fs_top_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core ds_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core ds_top_reset", false,-1);
        tracep->declBit(c+114,"Soc core ds_top_io_fs_ready", false,-1);
        tracep->declBit(c+115,"Soc core ds_top_io_fs_valid", false,-1);
        tracep->declQuad(c+116,"Soc core ds_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+118,"Soc core ds_top_io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+119,"Soc core ds_top_io_es_ready", false,-1);
        tracep->declBit(c+120,"Soc core ds_top_io_es_valid", false,-1);
        tracep->declQuad(c+109,"Soc core ds_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+121,"Soc core ds_top_io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+122,"Soc core ds_top_io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core ds_top_io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core ds_top_io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core ds_top_io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core ds_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core ds_top_io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core ds_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core ds_top_io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+130,"Soc core ds_top_io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core ds_top_io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+134,"Soc core ds_top_io_wb_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ds_top_io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top_io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ds_top_ms_res_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ds_top_ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ds_top_ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ds_top_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+19,"Soc core ds_top__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Soc core ds_top__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Soc core ds_top__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Soc core ds_top__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Soc core ds_top__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Soc core ds_top__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Soc core ds_top__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Soc core ds_top__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Soc core ds_top__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Soc core ds_top__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Soc core ds_top__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Soc core ds_top__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Soc core ds_top__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Soc core ds_top__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Soc core ds_top__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Soc core ds_top__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Soc core ds_top__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Soc core ds_top__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Soc core ds_top__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Soc core ds_top__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Soc core ds_top__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Soc core ds_top__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Soc core ds_top__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Soc core ds_top__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Soc core ds_top__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Soc core ds_top__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Soc core ds_top__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Soc core ds_top__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Soc core ds_top__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Soc core ds_top__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Soc core ds_top__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Soc core ds_top__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+86,"Soc core ds_top_is_trap", false,-1);
        tracep->declBit(c+108,"Soc core ds_top_br_taken_0", false,-1);
        tracep->declQuad(c+109,"Soc core ds_top_from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+111,"Soc core ds_top_insts_sent_after_br_0", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core ds_top_es_res_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core ds_top_es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core ds_top_es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ds_top_es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+112,"Soc core ds_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core es_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core es_top_reset", false,-1);
        tracep->declBit(c+119,"Soc core es_top_io_ds_ready", false,-1);
        tracep->declBit(c+120,"Soc core es_top_io_ds_valid", false,-1);
        tracep->declQuad(c+109,"Soc core es_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+121,"Soc core es_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+122,"Soc core es_top_io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core es_top_io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core es_top_io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core es_top_io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core es_top_io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core es_top_io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core es_top_io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core es_top_io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+130,"Soc core es_top_io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core es_top_io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+147,"Soc core es_top_io_ms_ready", false,-1);
        tracep->declBit(c+148,"Soc core es_top_io_ms_valid", false,-1);
        tracep->declQuad(c+149,"Soc core es_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core es_top_io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core es_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Soc core es_top_io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+151,"Soc core es_top_io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+144,"Soc core es_top_io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+143,"Soc core es_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+152,"Soc core es_top_io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+10,"Soc core es_top_io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Soc core es_top_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Soc core es_top_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc core es_top_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Soc core es_top_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Soc core es_top_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+142,"Soc core es_top_es_res_0_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core es_top_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core es_top_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core es_top_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+436,"Soc core ms_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core ms_top_reset", false,-1);
        tracep->declBit(c+147,"Soc core ms_top_io__es_ready", false,-1);
        tracep->declBit(c+148,"Soc core ms_top_io__es_valid", false,-1);
        tracep->declQuad(c+149,"Soc core ms_top_io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ms_top_io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core ms_top_io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Soc core ms_top_io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+151,"Soc core ms_top_io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+144,"Soc core ms_top_io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+143,"Soc core ms_top_io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+152,"Soc core ms_top_io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+153,"Soc core ms_top_io__ws_valid", false,-1);
        tracep->declQuad(c+154,"Soc core ms_top_io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ms_top_io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+140,"Soc core ms_top_io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+139,"Soc core ms_top_io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+18,"Soc core ms_top_io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core ms_top_io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ms_top_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ms_top_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ms_top_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ms_top_io_dmem_resp_valid", false,-1);
        tracep->declBit(c+436,"Soc core ws_top_clock", false,-1);
        tracep->declBit(c+437,"Soc core ws_top_reset", false,-1);
        tracep->declBit(c+515,"Soc core ws_top_io_ms_ready", false,-1);
        tracep->declBit(c+153,"Soc core ws_top_io_ms_valid", false,-1);
        tracep->declQuad(c+154,"Soc core ws_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ws_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+140,"Soc core ws_top_io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+139,"Soc core ws_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+134,"Soc core ws_top_io_rf_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ws_top_io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ws_top_io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Soc core ws_top_REG_1_0", false,-1, 63,0);
        tracep->declBit(c+85,"Soc core ws_top_REG_0", false,-1);
        tracep->declBit(c+436,"Soc core pre_top clock", false,-1);
        tracep->declBit(c+437,"Soc core pre_top reset", false,-1);
        tracep->declBit(c+103,"Soc core pre_top io_fs_ready", false,-1);
        tracep->declBit(c+104,"Soc core pre_top io_fs_valid", false,-1);
        tracep->declQuad(c+105,"Soc core pre_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Soc core pre_top io_fs_bits_offset", false,-1);
        tracep->declBit(c+3,"Soc core pre_top io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Soc core pre_top io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Soc core pre_top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+108,"Soc core pre_top br_taken_0", false,-1);
        tracep->declQuad(c+109,"Soc core pre_top br_old_PC_0", false,-1, 63,0);
        tracep->declBus(c+111,"Soc core pre_top insts_sent_after_br_0", false,-1, 1,0);
        tracep->declQuad(c+112,"Soc core pre_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+104,"Soc core pre_top pre_ready_go", false,-1);
        tracep->declQuad(c+105,"Soc core pre_top pre_pc", false,-1, 63,0);
        tracep->declBit(c+156,"Soc core pre_top buf_valid", false,-1);
        tracep->declQuad(c+157,"Soc core pre_top buf_npc", false,-1, 63,0);
        tracep->declQuad(c+159,"Soc core pre_top seq_pc", false,-1, 63,0);
        tracep->declQuad(c+161,"Soc core pre_top nextpc", false,-1, 63,0);
        tracep->declBit(c+4,"Soc core pre_top imem_req_r", false,-1);
        tracep->declQuad(c+163,"Soc core pre_top diff", false,-1, 63,0);
        tracep->declBus(c+111,"Soc core pre_top insts_sent_after_br", false,-1, 1,0);
        tracep->declBit(c+436,"Soc core fs_top clock", false,-1);
        tracep->declBit(c+437,"Soc core fs_top reset", false,-1);
        tracep->declBit(c+103,"Soc core fs_top io_pres_ready", false,-1);
        tracep->declBit(c+104,"Soc core fs_top io_pres_valid", false,-1);
        tracep->declQuad(c+105,"Soc core fs_top io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Soc core fs_top io_pres_bits_offset", false,-1);
        tracep->declBit(c+114,"Soc core fs_top io_ds_ready", false,-1);
        tracep->declBit(c+115,"Soc core fs_top io_ds_valid", false,-1);
        tracep->declQuad(c+116,"Soc core fs_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+118,"Soc core fs_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+7,"Soc core fs_top io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core fs_top io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+116,"Soc core fs_top from_pre_r_PC", false,-1, 63,0);
        tracep->declBit(c+165,"Soc core fs_top from_pre_r_offset", false,-1);
        tracep->declBit(c+166,"Soc core fs_top fs_ready_go", false,-1);
        tracep->declBit(c+167,"Soc core fs_top fs_valid", false,-1);
        tracep->declBit(c+436,"Soc core ds_top clock", false,-1);
        tracep->declBit(c+437,"Soc core ds_top reset", false,-1);
        tracep->declBit(c+114,"Soc core ds_top io_fs_ready", false,-1);
        tracep->declBit(c+115,"Soc core ds_top io_fs_valid", false,-1);
        tracep->declQuad(c+116,"Soc core ds_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+118,"Soc core ds_top io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+119,"Soc core ds_top io_es_ready", false,-1);
        tracep->declBit(c+120,"Soc core ds_top io_es_valid", false,-1);
        tracep->declQuad(c+109,"Soc core ds_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+121,"Soc core ds_top io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+122,"Soc core ds_top io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core ds_top io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core ds_top io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core ds_top io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core ds_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core ds_top io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core ds_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core ds_top io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+130,"Soc core ds_top io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core ds_top io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+134,"Soc core ds_top io_wb_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ds_top io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ds_top ms_res_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ds_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ds_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ds_top io_dmem_resp_valid", false,-1);
        tracep->declBit(c+86,"Soc core ds_top is_trap", false,-1);
        tracep->declBit(c+108,"Soc core ds_top br_taken_0", false,-1);
        tracep->declQuad(c+109,"Soc core ds_top from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+111,"Soc core ds_top insts_sent_after_br_0", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core ds_top es_res_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core ds_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core ds_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ds_top es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+112,"Soc core ds_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core ds_top rf_clock", false,-1);
        tracep->declBus(c+168,"Soc core ds_top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+169,"Soc core ds_top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+134,"Soc core ds_top rf_io_ws_res_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ds_top rf_io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top rf_io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+130,"Soc core ds_top rf_io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core ds_top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+170,"Soc core ds_top rf_io_wr_stall", false,-1);
        tracep->declBit(c+138,"Soc core ds_top rf_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ds_top rf_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ds_top rf_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ds_top rf_load_data_returned", false,-1);
        tracep->declQuad(c+19,"Soc core ds_top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Soc core ds_top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Soc core ds_top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Soc core ds_top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Soc core ds_top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Soc core ds_top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Soc core ds_top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Soc core ds_top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Soc core ds_top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Soc core ds_top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Soc core ds_top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Soc core ds_top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Soc core ds_top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Soc core ds_top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Soc core ds_top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Soc core ds_top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Soc core ds_top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Soc core ds_top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Soc core ds_top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Soc core ds_top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Soc core ds_top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Soc core ds_top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Soc core ds_top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Soc core ds_top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Soc core ds_top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Soc core ds_top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Soc core ds_top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Soc core ds_top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Soc core ds_top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Soc core ds_top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Soc core ds_top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Soc core ds_top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+142,"Soc core ds_top rf_es_res_0_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core ds_top rf_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core ds_top rf_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ds_top rf_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+121,"Soc core ds_top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+171,"Soc core ds_top idu_io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+122,"Soc core ds_top idu_io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core ds_top idu_io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core ds_top idu_io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core ds_top idu_io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core ds_top idu_io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core ds_top idu_io_ctrl_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core ds_top idu_io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core ds_top idu_io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Soc core ds_top idu_is_trap_0", false,-1);
        tracep->declQuad(c+109,"Soc core ds_top from_fs_r__PC", false,-1, 63,0);
        tracep->declBus(c+121,"Soc core ds_top from_fs_r__inst", false,-1, 31,0);
        tracep->declBit(c+172,"Soc core ds_top ds_ready_go", false,-1);
        tracep->declBit(c+173,"Soc core ds_top ds_valid", false,-1);
        tracep->declBus(c+174,"Soc core ds_top imm_i", false,-1, 11,0);
        tracep->declBit(c+175,"Soc core ds_top right_right", false,-1);
        tracep->declBit(c+176,"Soc core ds_top right_left", false,-1);
        tracep->declBus(c+177,"Soc core ds_top left_right", false,-1, 5,0);
        tracep->declBus(c+178,"Soc core ds_top left_left", false,-1, 3,0);
        tracep->declBus(c+179,"Soc core ds_top imm_b", false,-1, 11,0);
        tracep->declBus(c+180,"Soc core ds_top right_left_1", false,-1, 7,0);
        tracep->declBit(c+181,"Soc core ds_top left_right_1", false,-1);
        tracep->declBus(c+182,"Soc core ds_top left_left_1", false,-1, 9,0);
        tracep->declBus(c+183,"Soc core ds_top imm_j", false,-1, 19,0);
        tracep->declQuad(c+184,"Soc core ds_top right_2", false,-1, 51,0);
        tracep->declQuad(c+186,"Soc core ds_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+188,"Soc core ds_top right_right_2", false,-1, 52,0);
        tracep->declArray(c+190,"Soc core ds_top imm_b_sext", false,-1, 65,0);
        tracep->declQuad(c+193,"Soc core ds_top right_right_3", false,-1, 52,0);
        tracep->declArray(c+195,"Soc core ds_top imm_j_sext", false,-1, 73,0);
        tracep->declArray(c+198,"Soc core ds_top branch_target", false,-1, 65,0);
        tracep->declArray(c+201,"Soc core ds_top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+204,"Soc core ds_top jr_target", false,-1, 63,0);
        tracep->declBit(c+206,"Soc core ds_top rf_eq", false,-1);
        tracep->declBit(c+207,"Soc core ds_top rf_lt", false,-1);
        tracep->declBit(c+208,"Soc core ds_top rf_ltu", false,-1);
        tracep->declBit(c+209,"Soc core ds_top flush_set", false,-1);
        tracep->declBus(c+210,"Soc core ds_top flush_reg", false,-1, 1,0);
        tracep->declBit(c+108,"Soc core ds_top br_taken", false,-1);
        tracep->declBit(c+211,"Soc core ds_top insts_sent_after_br", false,-1);
        tracep->declQuad(c+112,"Soc core ds_top br_target", false,-1, 63,0);
        tracep->declBit(c+436,"Soc core ds_top rf clock", false,-1);
        tracep->declBus(c+168,"Soc core ds_top rf io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+169,"Soc core ds_top rf io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+134,"Soc core ds_top rf io_ws_res_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ds_top rf io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top rf io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+130,"Soc core ds_top rf io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core ds_top rf io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+170,"Soc core ds_top rf io_wr_stall", false,-1);
        tracep->declBit(c+138,"Soc core ds_top rf ms_res_0_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ds_top rf ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ds_top rf ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ds_top rf load_data_returned", false,-1);
        tracep->declBit(c+142,"Soc core ds_top rf es_res_0_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core ds_top rf es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core ds_top rf es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ds_top rf es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+436,"Soc core ds_top rf rf_clock", false,-1);
        tracep->declBus(c+168,"Soc core ds_top rf rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+212,"Soc core ds_top rf rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+169,"Soc core ds_top rf rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+214,"Soc core ds_top rf rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+135,"Soc core ds_top rf rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top rf rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+134,"Soc core ds_top rf rf_io_wen", false,-1);
        tracep->declQuad(c+19,"Soc core ds_top rf rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+21,"Soc core ds_top rf rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+23,"Soc core ds_top rf rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+25,"Soc core ds_top rf rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+27,"Soc core ds_top rf rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+29,"Soc core ds_top rf rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+31,"Soc core ds_top rf rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+33,"Soc core ds_top rf rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+35,"Soc core ds_top rf rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+37,"Soc core ds_top rf rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+39,"Soc core ds_top rf rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+41,"Soc core ds_top rf rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+43,"Soc core ds_top rf rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+45,"Soc core ds_top rf rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+47,"Soc core ds_top rf rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+49,"Soc core ds_top rf rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+51,"Soc core ds_top rf rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+53,"Soc core ds_top rf rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+55,"Soc core ds_top rf rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+57,"Soc core ds_top rf rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+59,"Soc core ds_top rf rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+61,"Soc core ds_top rf rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+63,"Soc core ds_top rf rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+65,"Soc core ds_top rf rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+67,"Soc core ds_top rf rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+69,"Soc core ds_top rf rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+71,"Soc core ds_top rf rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+73,"Soc core ds_top rf rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+75,"Soc core ds_top rf rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+77,"Soc core ds_top rf rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+79,"Soc core ds_top rf rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+81,"Soc core ds_top rf rf__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+216,"Soc core ds_top rf is_load", false,-1);
        tracep->declBit(c+436,"Soc core ds_top rf rf clock", false,-1);
        tracep->declBus(c+168,"Soc core ds_top rf rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+212,"Soc core ds_top rf rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+169,"Soc core ds_top rf rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+214,"Soc core ds_top rf rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+135,"Soc core ds_top rf rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top rf rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+134,"Soc core ds_top rf rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+217+i*2,"Soc core ds_top rf rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+281,"Soc core ds_top rf rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+168,"Soc core ds_top rf rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+283,"Soc core ds_top rf rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+169,"Soc core ds_top rf rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Soc core ds_top rf rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+519,"Soc core ds_top rf rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+21,"Soc core ds_top rf rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+520,"Soc core ds_top rf rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"Soc core ds_top rf rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+521,"Soc core ds_top rf rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"Soc core ds_top rf rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+522,"Soc core ds_top rf rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"Soc core ds_top rf rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+523,"Soc core ds_top rf rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"Soc core ds_top rf rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+524,"Soc core ds_top rf rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+31,"Soc core ds_top rf rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+525,"Soc core ds_top rf rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Soc core ds_top rf rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+526,"Soc core ds_top rf rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+35,"Soc core ds_top rf rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+527,"Soc core ds_top rf rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+37,"Soc core ds_top rf rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+528,"Soc core ds_top rf rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+39,"Soc core ds_top rf rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+529,"Soc core ds_top rf rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+41,"Soc core ds_top rf rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+530,"Soc core ds_top rf rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+43,"Soc core ds_top rf rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+531,"Soc core ds_top rf rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+45,"Soc core ds_top rf rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+532,"Soc core ds_top rf rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+47,"Soc core ds_top rf rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+533,"Soc core ds_top rf rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+49,"Soc core ds_top rf rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+534,"Soc core ds_top rf rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+51,"Soc core ds_top rf rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+535,"Soc core ds_top rf rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+53,"Soc core ds_top rf rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+536,"Soc core ds_top rf rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+55,"Soc core ds_top rf rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+537,"Soc core ds_top rf rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+57,"Soc core ds_top rf rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+538,"Soc core ds_top rf rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+59,"Soc core ds_top rf rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+539,"Soc core ds_top rf rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+61,"Soc core ds_top rf rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+540,"Soc core ds_top rf rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+63,"Soc core ds_top rf rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+541,"Soc core ds_top rf rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"Soc core ds_top rf rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+542,"Soc core ds_top rf rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+67,"Soc core ds_top rf rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+543,"Soc core ds_top rf rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+69,"Soc core ds_top rf rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+544,"Soc core ds_top rf rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"Soc core ds_top rf rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+545,"Soc core ds_top rf rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+73,"Soc core ds_top rf rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+546,"Soc core ds_top rf rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+75,"Soc core ds_top rf rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+547,"Soc core ds_top rf rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+77,"Soc core ds_top rf rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+548,"Soc core ds_top rf rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+79,"Soc core ds_top rf rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+549,"Soc core ds_top rf rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+81,"Soc core ds_top rf rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+550,"Soc core ds_top rf rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ds_top rf rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+135,"Soc core ds_top rf rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+515,"Soc core ds_top rf rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+134,"Soc core ds_top rf rf regfile_MPORT_en", false,-1);
        tracep->declBus(c+121,"Soc core ds_top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+171,"Soc core ds_top idu io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+122,"Soc core ds_top idu io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core ds_top idu io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core ds_top idu io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core ds_top idu io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core ds_top idu io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core ds_top idu io_ctrl_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core ds_top idu io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core ds_top idu io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Soc core ds_top idu is_trap_0", false,-1);
        tracep->declBit(c+86,"Soc core ds_top idu is_trap", false,-1);
        tracep->declBit(c+436,"Soc core es_top clock", false,-1);
        tracep->declBit(c+437,"Soc core es_top reset", false,-1);
        tracep->declBit(c+119,"Soc core es_top io_ds_ready", false,-1);
        tracep->declBit(c+120,"Soc core es_top io_ds_valid", false,-1);
        tracep->declQuad(c+109,"Soc core es_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+121,"Soc core es_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+122,"Soc core es_top io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Soc core es_top io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+124,"Soc core es_top io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+125,"Soc core es_top io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+126,"Soc core es_top io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+127,"Soc core es_top io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+128,"Soc core es_top io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+129,"Soc core es_top io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+130,"Soc core es_top io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+132,"Soc core es_top io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+147,"Soc core es_top io_ms_ready", false,-1);
        tracep->declBit(c+148,"Soc core es_top io_ms_valid", false,-1);
        tracep->declQuad(c+149,"Soc core es_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core es_top io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core es_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Soc core es_top io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+151,"Soc core es_top io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+144,"Soc core es_top io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+143,"Soc core es_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+152,"Soc core es_top io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+10,"Soc core es_top io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Soc core es_top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Soc core es_top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc core es_top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Soc core es_top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Soc core es_top io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+142,"Soc core es_top es_res_0_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core es_top es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core es_top es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core es_top es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+285,"Soc core es_top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+286,"Soc core es_top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+288,"Soc core es_top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+290,"Soc core es_top alu_io_out", false,-1, 63,0);
        tracep->declQuad(c+149,"Soc core es_top from_ds_r_PC", false,-1, 63,0);
        tracep->declBus(c+292,"Soc core es_top from_ds_r_inst", false,-1, 31,0);
        tracep->declBus(c+293,"Soc core es_top from_ds_r_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+294,"Soc core es_top from_ds_r_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+285,"Soc core es_top from_ds_r_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+146,"Soc core es_top from_ds_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core es_top from_ds_r_decode_rf_wen", false,-1);
        tracep->declBit(c+295,"Soc core es_top from_ds_r_decode_mem_en", false,-1);
        tracep->declBit(c+16,"Soc core es_top from_ds_r_decode_mem_wr", false,-1);
        tracep->declBus(c+151,"Soc core es_top from_ds_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+296,"Soc core es_top from_ds_r_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+298,"Soc core es_top from_ds_r_rs2_data", false,-1, 63,0);
        tracep->declBit(c+300,"Soc core es_top es_ready_go", false,-1);
        tracep->declBit(c+301,"Soc core es_top es_valid", false,-1);
        tracep->declBus(c+302,"Soc core es_top imm_i", false,-1, 11,0);
        tracep->declBus(c+303,"Soc core es_top right", false,-1, 6,0);
        tracep->declBus(c+143,"Soc core es_top left", false,-1, 4,0);
        tracep->declBus(c+304,"Soc core es_top imm_s", false,-1, 11,0);
        tracep->declBus(c+305,"Soc core es_top imm_u", false,-1, 19,0);
        tracep->declBus(c+306,"Soc core es_top left_3", false,-1, 4,0);
        tracep->declBus(c+307,"Soc core es_top imm_z", false,-1, 31,0);
        tracep->declQuad(c+308,"Soc core es_top right_4", false,-1, 51,0);
        tracep->declQuad(c+310,"Soc core es_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+312,"Soc core es_top right_5", false,-1, 51,0);
        tracep->declQuad(c+314,"Soc core es_top imm_s_sext", false,-1, 63,0);
        tracep->declBus(c+316,"Soc core es_top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+317,"Soc core es_top imm_u_sext", false,-1, 63,0);
        tracep->declBit(c+319,"Soc core es_top dmem_req_r", false,-1);
        tracep->declBus(c+320,"Soc core es_top offset", false,-1, 3,0);
        tracep->declBus(c+321,"Soc core es_top offset_8", false,-1, 6,0);
        tracep->declQuad(c+322,"Soc core es_top io_dmem_req_bits_addr_right", false,-1, 60,0);
        tracep->declBit(c+142,"Soc core es_top es_res_rf_we", false,-1);
        tracep->declBus(c+143,"Soc core es_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Soc core es_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core es_top es_res_wb_sel", false,-1, 1,0);
        tracep->declBus(c+285,"Soc core es_top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+286,"Soc core es_top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+288,"Soc core es_top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+290,"Soc core es_top alu io_out", false,-1, 63,0);
        tracep->declQuad(c+324,"Soc core es_top alu add2", false,-1, 63,0);
        tracep->declArray(c+326,"Soc core es_top alu add_result", false,-1, 65,0);
        tracep->declQuad(c+329,"Soc core es_top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+331,"Soc core es_top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+333,"Soc core es_top alu and_result", false,-1, 63,0);
        tracep->declBit(c+335,"Soc core es_top alu sltu_result", false,-1);
        tracep->declBit(c+336,"Soc core es_top alu slt_result", false,-1);
        tracep->declBus(c+337,"Soc core es_top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+338,"Soc core es_top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+340,"Soc core es_top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+342,"Soc core es_top alu srl_result", false,-1, 63,0);
        tracep->declBus(c+344,"Soc core es_top alu shamt5", false,-1, 4,0);
        tracep->declBus(c+345,"Soc core es_top alu sllw_result", false,-1, 31,0);
        tracep->declBus(c+346,"Soc core es_top alu sraw_result", false,-1, 31,0);
        tracep->declBus(c+347,"Soc core es_top alu srlw_result", false,-1, 31,0);
        tracep->declQuad(c+348,"Soc core es_top alu io_out_res", false,-1, 63,0);
        tracep->declBus(c+350,"Soc core es_top alu io_out_left", false,-1, 31,0);
        tracep->declBus(c+351,"Soc core es_top alu io_out_right", false,-1, 31,0);
        tracep->declBus(c+352,"Soc core es_top alu io_out_right_2", false,-1, 31,0);
        tracep->declBus(c+353,"Soc core es_top alu io_out_right_3", false,-1, 31,0);
        tracep->declBus(c+354,"Soc core es_top alu io_out_right_4", false,-1, 31,0);
        tracep->declBit(c+436,"Soc core ms_top clock", false,-1);
        tracep->declBit(c+437,"Soc core ms_top reset", false,-1);
        tracep->declBit(c+147,"Soc core ms_top io__es_ready", false,-1);
        tracep->declBit(c+148,"Soc core ms_top io__es_valid", false,-1);
        tracep->declQuad(c+149,"Soc core ms_top io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+146,"Soc core ms_top io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+142,"Soc core ms_top io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Soc core ms_top io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+151,"Soc core ms_top io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+144,"Soc core ms_top io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+143,"Soc core ms_top io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+152,"Soc core ms_top io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+153,"Soc core ms_top io__ws_valid", false,-1);
        tracep->declQuad(c+154,"Soc core ms_top io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ms_top io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+140,"Soc core ms_top io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+139,"Soc core ms_top io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+18,"Soc core ms_top io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Soc core ms_top io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ms_top ms_res_0_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ms_top ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ms_top ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Soc core ms_top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+154,"Soc core ms_top from_es_r_PC", false,-1, 63,0);
        tracep->declBus(c+355,"Soc core ms_top from_es_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+138,"Soc core ms_top from_es_r_decode_rf_wen", false,-1);
        tracep->declBit(c+356,"Soc core ms_top from_es_r_decode_mem_wr", false,-1);
        tracep->declBus(c+357,"Soc core ms_top from_es_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+358,"Soc core ms_top from_es_r_alu_result", false,-1, 63,0);
        tracep->declBus(c+139,"Soc core ms_top from_es_r_rd_addr", false,-1, 4,0);
        tracep->declBus(c+360,"Soc core ms_top from_es_r_load_offset", false,-1, 2,0);
        tracep->declBit(c+361,"Soc core ms_top ms_valid", false,-1);
        tracep->declBus(c+362,"Soc core ms_top unfinished_store", false,-1, 3,0);
        tracep->declBit(c+363,"Soc core ms_top res_from_mem", false,-1);
        tracep->declBit(c+364,"Soc core ms_top ms_ready_go", false,-1);
        tracep->declQuad(c+365,"Soc core ms_top data", false,-1, 63,0);
        tracep->declBus(c+367,"Soc core ms_top byte_", false,-1, 7,0);
        tracep->declQuad(c+368,"Soc core ms_top right", false,-1, 55,0);
        tracep->declBus(c+370,"Soc core ms_top half", false,-1, 15,0);
        tracep->declQuad(c+371,"Soc core ms_top right_1", false,-1, 47,0);
        tracep->declBus(c+373,"Soc core ms_top word", false,-1, 31,0);
        tracep->declBus(c+374,"Soc core ms_top right_2", false,-1, 31,0);
        tracep->declQuad(c+375,"Soc core ms_top load_final", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ms_top ms_res_rf_we", false,-1);
        tracep->declBus(c+139,"Soc core ms_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Soc core ms_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+355,"Soc core ms_top ms_res_wb_sel", false,-1, 1,0);
        tracep->declBit(c+436,"Soc core ws_top clock", false,-1);
        tracep->declBit(c+437,"Soc core ws_top reset", false,-1);
        tracep->declBit(c+515,"Soc core ws_top io_ms_ready", false,-1);
        tracep->declBit(c+153,"Soc core ws_top io_ms_valid", false,-1);
        tracep->declQuad(c+154,"Soc core ws_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+138,"Soc core ws_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+140,"Soc core ws_top io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+139,"Soc core ws_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+134,"Soc core ws_top io_rf_rf_we", false,-1);
        tracep->declBus(c+135,"Soc core ws_top io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Soc core ws_top io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Soc core ws_top REG_1_0", false,-1, 63,0);
        tracep->declBit(c+85,"Soc core ws_top REG_0", false,-1);
        tracep->declQuad(c+377,"Soc core ws_top from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+134,"Soc core ws_top from_ms_r_decode_rf_wen", false,-1);
        tracep->declQuad(c+136,"Soc core ws_top from_ms_r_final_result", false,-1, 63,0);
        tracep->declBus(c+135,"Soc core ws_top from_ms_r_rd_addr", false,-1, 4,0);
        tracep->declBit(c+379,"Soc core ws_top is_commit", false,-1);
        tracep->declBit(c+85,"Soc core ws_top REG", false,-1);
        tracep->declQuad(c+83,"Soc core ws_top REG_1", false,-1, 63,0);
        tracep->declBus(c+551,"Soc ram DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+552,"Soc ram ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+553,"Soc ram STRB_WIDTH", false,-1, 31,0);
        tracep->declBus(c+553,"Soc ram ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+554,"Soc ram PIPELINE_OUTPUT", false,-1, 31,0);
        tracep->declBit(c+436,"Soc ram clock", false,-1);
        tracep->declBit(c+437,"Soc ram reset", false,-1);
        tracep->declBus(c+509,"Soc ram awid", false,-1, 7,0);
        tracep->declBus(c+380,"Soc ram awaddr", false,-1, 19,0);
        tracep->declBus(c+509,"Soc ram awlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc ram awsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc ram awburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc ram awlock", false,-1);
        tracep->declBus(c+513,"Soc ram awcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc ram awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Soc ram awvalid", false,-1);
        tracep->declBit(c+90,"Soc ram awready", false,-1);
        tracep->declBus(c+509,"Soc ram wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Soc ram wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Soc ram wstrb", false,-1, 7,0);
        tracep->declBit(c+515,"Soc ram wlast", false,-1);
        tracep->declBit(c+94,"Soc ram wvalid", false,-1);
        tracep->declBit(c+95,"Soc ram wready", false,-1);
        tracep->declBus(c+96,"Soc ram bid", false,-1, 7,0);
        tracep->declBus(c+511,"Soc ram bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Soc ram bvalid", false,-1);
        tracep->declBit(c+515,"Soc ram bready", false,-1);
        tracep->declBus(c+509,"Soc ram arid", false,-1, 7,0);
        tracep->declBus(c+380,"Soc ram araddr", false,-1, 19,0);
        tracep->declBus(c+509,"Soc ram arlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc ram arsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc ram arburst", false,-1, 1,0);
        tracep->declBit(c+512,"Soc ram arlock", false,-1);
        tracep->declBus(c+513,"Soc ram arcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc ram arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Soc ram arvalid", false,-1);
        tracep->declBit(c+99,"Soc ram arready", false,-1);
        tracep->declBus(c+100,"Soc ram rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Soc ram rdata", false,-1, 63,0);
        tracep->declBus(c+511,"Soc ram rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Soc ram rlast", false,-1);
        tracep->declBit(c+102,"Soc ram rvalid", false,-1);
        tracep->declBit(c+515,"Soc ram rready", false,-1);
        tracep->declBus(c+555,"Soc ram VALID_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+553,"Soc ram WORD_WIDTH", false,-1, 31,0);
        tracep->declBus(c+553,"Soc ram WORD_SIZE", false,-1, 31,0);
        tracep->declBus(c+556,"Soc ram READ_STATE_IDLE", false,-1, 0,0);
        tracep->declBus(c+557,"Soc ram READ_STATE_BURST", false,-1, 0,0);
        tracep->declBus(c+381,"Soc ram read_state_reg", false,-1, 0,0);
        tracep->declBus(c+382,"Soc ram read_state_next", false,-1, 0,0);
        tracep->declBus(c+511,"Soc ram WRITE_STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+558,"Soc ram WRITE_STATE_BURST", false,-1, 1,0);
        tracep->declBus(c+559,"Soc ram WRITE_STATE_RESP", false,-1, 1,0);
        tracep->declBus(c+383,"Soc ram write_state_reg", false,-1, 1,0);
        tracep->declBus(c+384,"Soc ram write_state_next", false,-1, 1,0);
        tracep->declBit(c+385,"Soc ram mem_wr_en", false,-1);
        tracep->declBit(c+386,"Soc ram mem_rd_en", false,-1);
        tracep->declBus(c+387,"Soc ram read_id_reg", false,-1, 7,0);
        tracep->declBus(c+388,"Soc ram read_id_next", false,-1, 7,0);
        tracep->declBus(c+389,"Soc ram read_addr_reg", false,-1, 19,0);
        tracep->declBus(c+390,"Soc ram read_addr_next", false,-1, 19,0);
        tracep->declBus(c+391,"Soc ram read_count_reg", false,-1, 7,0);
        tracep->declBus(c+392,"Soc ram read_count_next", false,-1, 7,0);
        tracep->declBus(c+393,"Soc ram read_size_reg", false,-1, 2,0);
        tracep->declBus(c+394,"Soc ram read_size_next", false,-1, 2,0);
        tracep->declBus(c+395,"Soc ram read_burst_reg", false,-1, 1,0);
        tracep->declBus(c+396,"Soc ram read_burst_next", false,-1, 1,0);
        tracep->declBus(c+397,"Soc ram write_id_reg", false,-1, 7,0);
        tracep->declBus(c+398,"Soc ram write_id_next", false,-1, 7,0);
        tracep->declBus(c+399,"Soc ram write_addr_reg", false,-1, 19,0);
        tracep->declBus(c+400,"Soc ram write_addr_next", false,-1, 19,0);
        tracep->declBus(c+401,"Soc ram write_count_reg", false,-1, 7,0);
        tracep->declBus(c+402,"Soc ram write_count_next", false,-1, 7,0);
        tracep->declBus(c+403,"Soc ram write_size_reg", false,-1, 2,0);
        tracep->declBus(c+404,"Soc ram write_size_next", false,-1, 2,0);
        tracep->declBus(c+405,"Soc ram write_burst_reg", false,-1, 1,0);
        tracep->declBus(c+406,"Soc ram write_burst_next", false,-1, 1,0);
        tracep->declBit(c+90,"Soc ram awready_reg", false,-1);
        tracep->declBit(c+407,"Soc ram awready_next", false,-1);
        tracep->declBit(c+95,"Soc ram wready_reg", false,-1);
        tracep->declBit(c+408,"Soc ram wready_next", false,-1);
        tracep->declBus(c+96,"Soc ram bid_reg", false,-1, 7,0);
        tracep->declBus(c+409,"Soc ram bid_next", false,-1, 7,0);
        tracep->declBit(c+97,"Soc ram bvalid_reg", false,-1);
        tracep->declBit(c+410,"Soc ram bvalid_next", false,-1);
        tracep->declBit(c+99,"Soc ram arready_reg", false,-1);
        tracep->declBit(c+411,"Soc ram arready_next", false,-1);
        tracep->declBus(c+100,"Soc ram rid_reg", false,-1, 7,0);
        tracep->declBus(c+412,"Soc ram rid_next", false,-1, 7,0);
        tracep->declQuad(c+413,"Soc ram rdata_reg", false,-1, 63,0);
        tracep->declQuad(c+560,"Soc ram rdata_next", false,-1, 63,0);
        tracep->declBit(c+101,"Soc ram rlast_reg", false,-1);
        tracep->declBit(c+415,"Soc ram rlast_next", false,-1);
        tracep->declBit(c+102,"Soc ram rvalid_reg", false,-1);
        tracep->declBit(c+416,"Soc ram rvalid_next", false,-1);
        tracep->declBus(c+417,"Soc ram rid_pipe_reg", false,-1, 7,0);
        tracep->declQuad(c+418,"Soc ram rdata_pipe_reg", false,-1, 63,0);
        tracep->declBit(c+420,"Soc ram rlast_pipe_reg", false,-1);
        tracep->declBit(c+421,"Soc ram rvalid_pipe_reg", false,-1);
        tracep->declBus(c+422,"Soc ram awaddr_valid", false,-1, 16,0);
        tracep->declBus(c+422,"Soc ram araddr_valid", false,-1, 16,0);
        tracep->declBus(c+423,"Soc ram read_addr_valid", false,-1, 16,0);
        tracep->declBus(c+424,"Soc ram write_addr_valid", false,-1, 16,0);
        tracep->declQuad(c+413,"Soc ram rdata_big", false,-1, 63,0);
        tracep->declBus(c+425,"Soc ram i", false,-1, 31,0);
        tracep->declBus(c+1,"Soc ram j", false,-1, 31,0);
        tracep->declBus(c+2,"Soc ram mem_file", false,-1, 31,0);
        tracep->declQuad(c+426,"Soc ram wdata_big", false,-1, 63,0);
        tracep->declBit(c+436,"Soc bridge clock", false,-1);
        tracep->declBit(c+437,"Soc bridge reset", false,-1);
        tracep->declBit(c+4,"Soc bridge inst_req", false,-1);
        tracep->declBit(c+512,"Soc bridge inst_wr", false,-1);
        tracep->declBus(c+516,"Soc bridge inst_size", false,-1, 7,0);
        tracep->declQuad(c+5,"Soc bridge inst_addr", false,-1, 63,0);
        tracep->declQuad(c+517,"Soc bridge inst_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Soc bridge inst_rdata", false,-1, 63,0);
        tracep->declBit(c+3,"Soc bridge inst_addr_ok", false,-1);
        tracep->declBit(c+7,"Soc bridge inst_data_ok", false,-1);
        tracep->declBit(c+11,"Soc bridge data_req", false,-1);
        tracep->declBit(c+16,"Soc bridge data_wr", false,-1);
        tracep->declBus(c+17,"Soc bridge data_size", false,-1, 7,0);
        tracep->declQuad(c+12,"Soc bridge data_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Soc bridge data_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Soc bridge data_rdata", false,-1, 63,0);
        tracep->declBit(c+10,"Soc bridge data_addr_ok", false,-1);
        tracep->declBit(c+18,"Soc bridge data_data_ok", false,-1);
        tracep->declBus(c+513,"Soc bridge arid", false,-1, 3,0);
        tracep->declQuad(c+87,"Soc bridge araddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc bridge arlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc bridge arsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc bridge arburst", false,-1, 1,0);
        tracep->declBus(c+511,"Soc bridge arlock", false,-1, 1,0);
        tracep->declBus(c+513,"Soc bridge arcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc bridge arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Soc bridge arvalid", false,-1);
        tracep->declBit(c+99,"Soc bridge arready", false,-1);
        tracep->declBus(c+428,"Soc bridge rid", false,-1, 3,0);
        tracep->declQuad(c+8,"Soc bridge rdata", false,-1, 63,0);
        tracep->declBus(c+511,"Soc bridge rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Soc bridge rlast", false,-1);
        tracep->declBit(c+102,"Soc bridge rvalid", false,-1);
        tracep->declBit(c+515,"Soc bridge rready", false,-1);
        tracep->declBus(c+513,"Soc bridge awid", false,-1, 3,0);
        tracep->declQuad(c+87,"Soc bridge awaddr", false,-1, 63,0);
        tracep->declBus(c+509,"Soc bridge awlen", false,-1, 7,0);
        tracep->declBus(c+510,"Soc bridge awsize", false,-1, 2,0);
        tracep->declBus(c+511,"Soc bridge awburst", false,-1, 1,0);
        tracep->declBus(c+511,"Soc bridge awlock", false,-1, 1,0);
        tracep->declBus(c+513,"Soc bridge awcache", false,-1, 3,0);
        tracep->declBus(c+514,"Soc bridge awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Soc bridge awvalid", false,-1);
        tracep->declBit(c+90,"Soc bridge awready", false,-1);
        tracep->declBus(c+513,"Soc bridge wid", false,-1, 3,0);
        tracep->declQuad(c+91,"Soc bridge wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Soc bridge wstrb", false,-1, 7,0);
        tracep->declBit(c+515,"Soc bridge wlast", false,-1);
        tracep->declBit(c+94,"Soc bridge wvalid", false,-1);
        tracep->declBit(c+95,"Soc bridge wready", false,-1);
        tracep->declBus(c+429,"Soc bridge bid", false,-1, 3,0);
        tracep->declBus(c+511,"Soc bridge bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Soc bridge bvalid", false,-1);
        tracep->declBit(c+515,"Soc bridge bready", false,-1);
        tracep->declBit(c+508,"Soc bridge resetn", false,-1);
        tracep->declBit(c+430,"Soc bridge do_req", false,-1);
        tracep->declBit(c+431,"Soc bridge do_req_or", false,-1);
        tracep->declBit(c+432,"Soc bridge do_wr_r", false,-1);
        tracep->declBus(c+93,"Soc bridge do_size_r", false,-1, 7,0);
        tracep->declQuad(c+87,"Soc bridge do_addr_r", false,-1, 63,0);
        tracep->declQuad(c+91,"Soc bridge do_wdata_r", false,-1, 63,0);
        tracep->declBit(c+433,"Soc bridge data_back", false,-1);
        tracep->declBit(c+434,"Soc bridge addr_rcv", false,-1);
        tracep->declBit(c+435,"Soc bridge wdata_rcv", false,-1);
        tracep->declQuad(c+413,"Soc ram ed1 in", false,-1, 63,0);
        tracep->declQuad(c+8,"Soc ram ed1 out", false,-1, 63,0);
        tracep->declQuad(c+91,"Soc ram ed2 in", false,-1, 63,0);
        tracep->declQuad(c+426,"Soc ram ed2 out", false,-1, 63,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->Soc__DOT__ram__DOT__j),32);
        tracep->fullIData(oldp+2,(vlTOPp->Soc__DOT__ram__DOT__mem_file),32);
        tracep->fullBit(oldp+3,(vlTOPp->Soc__DOT__bridge_inst_addr_ok));
        tracep->fullBit(oldp+4,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__imem_req_r));
        tracep->fullQData(oldp+5,((0xfffffffffffffff8ULL 
                                   & vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__nextpc)),64);
        tracep->fullBit(oldp+7,(vlTOPp->Soc__DOT__bridge_inst_data_ok));
        tracep->fullQData(oldp+8,(vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out),64);
        tracep->fullBit(oldp+10,((1U & (~ (IData)(vlTOPp->Soc__DOT__bridge__DOT__do_req)))));
        tracep->fullBit(oldp+11,(vlTOPp->Soc__DOT__core__DOT__es_top_io_dmem_req_valid));
        tracep->fullQData(oldp+12,((0xfffffffffffffff8ULL 
                                    & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
        tracep->fullQData(oldp+14,((((QData)((IData)(
                                                     vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
        tracep->fullBit(oldp+16,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
        tracep->fullCData(oldp+17,((0xffU & vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
        tracep->fullBit(oldp+18,(vlTOPp->Soc__DOT__bridge_data_data_ok));
        tracep->fullQData(oldp+19,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+21,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+23,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+25,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+27,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+29,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+31,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+33,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+35,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+37,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+39,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+41,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+43,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+45,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+47,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+49,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+51,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+53,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+55,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+57,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+59,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+61,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+63,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+65,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+67,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+69,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+71,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+73,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+75,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+77,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+79,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+81,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+83,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__REG_1),64);
        tracep->fullBit(oldp+85,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__REG));
        tracep->fullBit(oldp+86,((0x6bU == (0x707fU 
                                            & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst))));
        tracep->fullQData(oldp+87,(vlTOPp->Soc__DOT__bridge__DOT__do_addr_r),64);
        tracep->fullBit(oldp+89,(vlTOPp->Soc__DOT__bridge_awvalid));
        tracep->fullBit(oldp+90,(vlTOPp->Soc__DOT__ram__DOT__awready_reg));
        tracep->fullQData(oldp+91,(vlTOPp->Soc__DOT__bridge__DOT__do_wdata_r),64);
        tracep->fullCData(oldp+93,(vlTOPp->Soc__DOT__bridge__DOT__do_size_r),8);
        tracep->fullBit(oldp+94,(vlTOPp->Soc__DOT__bridge_wvalid));
        tracep->fullBit(oldp+95,(vlTOPp->Soc__DOT__ram__DOT__wready_reg));
        tracep->fullCData(oldp+96,(vlTOPp->Soc__DOT__ram__DOT__bid_reg),8);
        tracep->fullBit(oldp+97,(vlTOPp->Soc__DOT__ram__DOT__bvalid_reg));
        tracep->fullBit(oldp+98,(vlTOPp->Soc__DOT__bridge_arvalid));
        tracep->fullBit(oldp+99,(vlTOPp->Soc__DOT__ram__DOT__arready_reg));
        tracep->fullCData(oldp+100,(vlTOPp->Soc__DOT__ram__DOT__rid_reg),8);
        tracep->fullBit(oldp+101,(vlTOPp->Soc__DOT__ram__DOT__rlast_reg));
        tracep->fullBit(oldp+102,(vlTOPp->Soc__DOT__ram__DOT__rvalid_reg));
        tracep->fullBit(oldp+103,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_pres_ready));
        tracep->fullBit(oldp+104,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_ready_go));
        tracep->fullQData(oldp+105,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc),64);
        tracep->fullBit(oldp+107,((1U & (IData)((vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                 >> 2U)))));
        tracep->fullBit(oldp+108,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken));
        tracep->fullQData(oldp+109,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05FPC),64);
        tracep->fullCData(oldp+111,((3U & (IData)(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___insts_sent_after_br_T_4))),2);
        tracep->fullQData(oldp+112,((((QData)((IData)(
                                                      vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
        tracep->fullBit(oldp+114,(vlTOPp->Soc__DOT__core__DOT__ds_top_io_fs_ready));
        tracep->fullBit(oldp+115,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_valid));
        tracep->fullQData(oldp+116,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
        tracep->fullIData(oldp+118,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
        tracep->fullBit(oldp+119,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ds_ready));
        tracep->fullBit(oldp+120,(vlTOPp->Soc__DOT__core__DOT__ds_top_io_es_valid));
        tracep->fullIData(oldp+121,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst),32);
        tracep->fullCData(oldp+122,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
        tracep->fullCData(oldp+123,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
        tracep->fullCData(oldp+124,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
        tracep->fullCData(oldp+125,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
        tracep->fullBit(oldp+126,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
        tracep->fullBit(oldp+127,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
        tracep->fullBit(oldp+128,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
        tracep->fullCData(oldp+129,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
        tracep->fullQData(oldp+130,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+132,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+134,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_decode_rf_wen));
        tracep->fullCData(oldp+135,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_rd_addr),5);
        tracep->fullQData(oldp+136,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_final_result),64);
        tracep->fullBit(oldp+138,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
        tracep->fullCData(oldp+139,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
        tracep->fullQData(oldp+140,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
        tracep->fullBit(oldp+142,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
        tracep->fullCData(oldp+143,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 7U))),5);
        tracep->fullQData(oldp+144,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
        tracep->fullCData(oldp+146,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
        tracep->fullBit(oldp+147,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fes_ready));
        tracep->fullBit(oldp+148,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_valid));
        tracep->fullQData(oldp+149,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
        tracep->fullCData(oldp+151,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
        tracep->fullCData(oldp+152,((7U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
        tracep->fullBit(oldp+153,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_valid));
        tracep->fullQData(oldp+154,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
        tracep->fullBit(oldp+156,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__buf_valid));
        tracep->fullQData(oldp+157,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__buf_npc),64);
        tracep->fullQData(oldp+159,((4ULL + vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
        tracep->fullQData(oldp+161,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__nextpc),64);
        tracep->fullQData(oldp+163,((0x3fffffffffffffffULL 
                                     & (vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___T_3 
                                        >> 2U))),64);
        tracep->fullBit(oldp+165,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
        tracep->fullBit(oldp+166,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__fs_ready_go));
        tracep->fullBit(oldp+167,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__fs_valid));
        tracep->fullCData(oldp+168,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+169,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                              >> 0x14U))),5);
        tracep->fullBit(oldp+170,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
        tracep->fullCData(oldp+171,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
        tracep->fullBit(oldp+172,((1U & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
        tracep->fullBit(oldp+173,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__ds_valid));
        tracep->fullSData(oldp+174,((0xfffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+175,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+176,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                         >> 7U))));
        tracep->fullCData(oldp+177,((0x3fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+178,((0xfU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                             >> 8U))),4);
        tracep->fullSData(oldp+179,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b),12);
        tracep->fullCData(oldp+180,((0xffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+181,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+182,((0x3ffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+183,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j),20);
        tracep->fullQData(oldp+184,(((0x80000000U & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+186,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+188,(((0x800U & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+190,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
        tracep->fullQData(oldp+193,(((0x80000U & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+195,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
        tracep->fullWData(oldp+198,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__branch_target),66);
        tracep->fullWData(oldp+201,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jmp_target),74);
        tracep->fullQData(oldp+204,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target),64);
        tracep->fullBit(oldp+206,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq));
        tracep->fullBit(oldp+207,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt));
        tracep->fullBit(oldp+208,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu));
        tracep->fullBit(oldp+209,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set));
        tracep->fullCData(oldp+210,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_reg),2);
        tracep->fullBit(oldp+211,((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___insts_sent_after_br_T_4))));
        tracep->fullQData(oldp+212,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+214,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+216,((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
        tracep->fullQData(oldp+217,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+219,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+221,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+223,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+225,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+227,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+229,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+231,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+233,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+235,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+237,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+239,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+241,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+243,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+245,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+247,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+249,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+251,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+253,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+255,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+257,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+259,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+261,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+263,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+265,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+267,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+269,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+271,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+273,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+275,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+277,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+279,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+281,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+283,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullCData(oldp+285,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
        tracep->fullQData(oldp+286,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+288,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
        tracep->fullQData(oldp+290,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out),64);
        tracep->fullIData(oldp+292,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
        tracep->fullCData(oldp+293,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
        tracep->fullCData(oldp+294,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
        tracep->fullBit(oldp+295,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
        tracep->fullQData(oldp+296,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
        tracep->fullQData(oldp+298,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
        tracep->fullBit(oldp+300,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__es_ready_go));
        tracep->fullBit(oldp+301,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__es_valid));
        tracep->fullSData(oldp+302,((0xfffU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+303,((0x7fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0x19U))),7);
        tracep->fullSData(oldp+304,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s),12);
        tracep->fullIData(oldp+305,((0xfffffU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+306,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),5);
        tracep->fullIData(oldp+307,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+308,(((0x80000000U & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+310,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+312,(((0x800U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+314,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
        tracep->fullIData(oldp+316,(((0x800000U & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+317,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
        tracep->fullBit(oldp+319,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__dmem_req_r));
        tracep->fullCData(oldp+320,((7U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
        tracep->fullCData(oldp+321,((0x38U & ((IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                              << 3U))),7);
        tracep->fullQData(oldp+322,((0x1fffffffffffffffULL 
                                     & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out 
                                        >> 3U))),61);
        tracep->fullQData(oldp+324,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
        tracep->fullWData(oldp+326,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
        tracep->fullQData(oldp+329,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+331,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+333,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+335,((1U & (~ vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+336,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+337,((0x3fU & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+338,((((QData)((IData)(
                                                      vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
        tracep->fullQData(oldp+340,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+342,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
        tracep->fullCData(oldp+344,((0x1fU & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
        tracep->fullIData(oldp+345,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
        tracep->fullIData(oldp+346,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
        tracep->fullIData(oldp+347,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
        tracep->fullQData(oldp+348,((((QData)((IData)(
                                                      vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullIData(oldp+350,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
        tracep->fullIData(oldp+351,(((0x80000000U & 
                                      vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+352,(((0x80000000U & 
                                      vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+353,(((0x80000000U & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+354,(((0x80000000U & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullCData(oldp+355,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
        tracep->fullBit(oldp+356,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
        tracep->fullCData(oldp+357,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
        tracep->fullQData(oldp+358,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
        tracep->fullCData(oldp+360,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
        tracep->fullBit(oldp+361,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__ms_valid));
        tracep->fullCData(oldp+362,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
        tracep->fullBit(oldp+363,((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
        tracep->fullBit(oldp+364,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__ms_ready_go));
        tracep->fullQData(oldp+365,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data),64);
        tracep->fullCData(oldp+367,((0xffU & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))),8);
        tracep->fullQData(oldp+368,(((1U & (IData)(
                                                   (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 7U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullSData(oldp+370,((0xffffU & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))),16);
        tracep->fullQData(oldp+371,(((1U & (IData)(
                                                   (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0xfU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullIData(oldp+373,((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)),32);
        tracep->fullIData(oldp+374,(((1U & (IData)(
                                                   (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0x1fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+375,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final),64);
        tracep->fullQData(oldp+377,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r_PC),64);
        tracep->fullBit(oldp+379,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__is_commit));
        tracep->fullIData(oldp+380,((0xfffffU & (IData)(vlTOPp->Soc__DOT__bridge__DOT__do_addr_r))),20);
        tracep->fullBit(oldp+381,(vlTOPp->Soc__DOT__ram__DOT__read_state_reg));
        tracep->fullBit(oldp+382,(vlTOPp->Soc__DOT__ram__DOT__read_state_next));
        tracep->fullCData(oldp+383,(vlTOPp->Soc__DOT__ram__DOT__write_state_reg),2);
        tracep->fullCData(oldp+384,(vlTOPp->Soc__DOT__ram__DOT__write_state_next),2);
        tracep->fullBit(oldp+385,(vlTOPp->Soc__DOT__ram__DOT__mem_wr_en));
        tracep->fullBit(oldp+386,(vlTOPp->Soc__DOT__ram__DOT__mem_rd_en));
        tracep->fullCData(oldp+387,(vlTOPp->Soc__DOT__ram__DOT__read_id_reg),8);
        tracep->fullCData(oldp+388,(vlTOPp->Soc__DOT__ram__DOT__read_id_next),8);
        tracep->fullIData(oldp+389,(vlTOPp->Soc__DOT__ram__DOT__read_addr_reg),20);
        tracep->fullIData(oldp+390,(vlTOPp->Soc__DOT__ram__DOT__read_addr_next),20);
        tracep->fullCData(oldp+391,(vlTOPp->Soc__DOT__ram__DOT__read_count_reg),8);
        tracep->fullCData(oldp+392,(vlTOPp->Soc__DOT__ram__DOT__read_count_next),8);
        tracep->fullCData(oldp+393,(vlTOPp->Soc__DOT__ram__DOT__read_size_reg),3);
        tracep->fullCData(oldp+394,(vlTOPp->Soc__DOT__ram__DOT__read_size_next),3);
        tracep->fullCData(oldp+395,(vlTOPp->Soc__DOT__ram__DOT__read_burst_reg),2);
        tracep->fullCData(oldp+396,(vlTOPp->Soc__DOT__ram__DOT__read_burst_next),2);
        tracep->fullCData(oldp+397,(vlTOPp->Soc__DOT__ram__DOT__write_id_reg),8);
        tracep->fullCData(oldp+398,(vlTOPp->Soc__DOT__ram__DOT__write_id_next),8);
        tracep->fullIData(oldp+399,(vlTOPp->Soc__DOT__ram__DOT__write_addr_reg),20);
        tracep->fullIData(oldp+400,(vlTOPp->Soc__DOT__ram__DOT__write_addr_next),20);
        tracep->fullCData(oldp+401,(vlTOPp->Soc__DOT__ram__DOT__write_count_reg),8);
        tracep->fullCData(oldp+402,(vlTOPp->Soc__DOT__ram__DOT__write_count_next),8);
        tracep->fullCData(oldp+403,(vlTOPp->Soc__DOT__ram__DOT__write_size_reg),3);
        tracep->fullCData(oldp+404,(vlTOPp->Soc__DOT__ram__DOT__write_size_next),3);
        tracep->fullCData(oldp+405,(vlTOPp->Soc__DOT__ram__DOT__write_burst_reg),2);
        tracep->fullCData(oldp+406,(vlTOPp->Soc__DOT__ram__DOT__write_burst_next),2);
        tracep->fullBit(oldp+407,(vlTOPp->Soc__DOT__ram__DOT__awready_next));
        tracep->fullBit(oldp+408,(vlTOPp->Soc__DOT__ram__DOT__wready_next));
        tracep->fullCData(oldp+409,(vlTOPp->Soc__DOT__ram__DOT__bid_next),8);
        tracep->fullBit(oldp+410,(vlTOPp->Soc__DOT__ram__DOT__bvalid_next));
        tracep->fullBit(oldp+411,(vlTOPp->Soc__DOT__ram__DOT__arready_next));
        tracep->fullCData(oldp+412,(vlTOPp->Soc__DOT__ram__DOT__rid_next),8);
        tracep->fullQData(oldp+413,(vlTOPp->Soc__DOT__ram__DOT__rdata_reg),64);
        tracep->fullBit(oldp+415,(vlTOPp->Soc__DOT__ram__DOT__rlast_next));
        tracep->fullBit(oldp+416,(vlTOPp->Soc__DOT__ram__DOT__rvalid_next));
        tracep->fullCData(oldp+417,(vlTOPp->Soc__DOT__ram__DOT__rid_pipe_reg),8);
        tracep->fullQData(oldp+418,(vlTOPp->Soc__DOT__ram__DOT__rdata_pipe_reg),64);
        tracep->fullBit(oldp+420,(vlTOPp->Soc__DOT__ram__DOT__rlast_pipe_reg));
        tracep->fullBit(oldp+421,(vlTOPp->Soc__DOT__ram__DOT__rvalid_pipe_reg));
        tracep->fullIData(oldp+422,((0x1ffffU & (IData)(
                                                        (vlTOPp->Soc__DOT__bridge__DOT__do_addr_r 
                                                         >> 3U)))),17);
        tracep->fullIData(oldp+423,((0x1ffffU & (vlTOPp->Soc__DOT__ram__DOT__read_addr_reg 
                                                 >> 3U))),17);
        tracep->fullIData(oldp+424,((0x1ffffU & (vlTOPp->Soc__DOT__ram__DOT__write_addr_reg 
                                                 >> 3U))),17);
        tracep->fullIData(oldp+425,(vlTOPp->Soc__DOT__ram__DOT__i),32);
        tracep->fullQData(oldp+426,(vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out),64);
        tracep->fullCData(oldp+428,((0xfU & (IData)(vlTOPp->Soc__DOT__ram__DOT__rid_reg))),4);
        tracep->fullCData(oldp+429,((0xfU & (IData)(vlTOPp->Soc__DOT__ram__DOT__bid_reg))),4);
        tracep->fullBit(oldp+430,(vlTOPp->Soc__DOT__bridge__DOT__do_req));
        tracep->fullBit(oldp+431,(vlTOPp->Soc__DOT__bridge__DOT__do_req_or));
        tracep->fullBit(oldp+432,(vlTOPp->Soc__DOT__bridge__DOT__do_wr_r));
        tracep->fullBit(oldp+433,(vlTOPp->Soc__DOT__bridge__DOT__data_back));
        tracep->fullBit(oldp+434,(vlTOPp->Soc__DOT__bridge__DOT__addr_rcv));
        tracep->fullBit(oldp+435,(vlTOPp->Soc__DOT__bridge__DOT__wdata_rcv));
        tracep->fullBit(oldp+436,(vlTOPp->clock));
        tracep->fullBit(oldp+437,(vlTOPp->reset));
        tracep->fullQData(oldp+438,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+440,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+442,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+444,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+446,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+448,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+450,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+452,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+454,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+456,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+458,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+460,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+462,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+464,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+466,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+468,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+470,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+472,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+474,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+476,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+478,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+480,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+482,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+484,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+486,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+488,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+490,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+492,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+494,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+496,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+498,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+500,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+502,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+504,(vlTOPp->io_debug_valid));
        tracep->fullBit(oldp+505,(vlTOPp->io_debug_trap));
        tracep->fullQData(oldp+506,(vlTOPp->io_debug_test),64);
        tracep->fullBit(oldp+508,((1U & (~ (IData)(vlTOPp->reset)))));
        tracep->fullCData(oldp+509,(0U),8);
        tracep->fullCData(oldp+510,(3U),3);
        tracep->fullCData(oldp+511,(0U),2);
        tracep->fullBit(oldp+512,(0U));
        tracep->fullCData(oldp+513,(0U),4);
        tracep->fullCData(oldp+514,(0U),3);
        tracep->fullBit(oldp+515,(1U));
        tracep->fullCData(oldp+516,(0xffU),8);
        tracep->fullQData(oldp+517,(0ULL),64);
        tracep->fullCData(oldp+519,(0U),5);
        tracep->fullCData(oldp+520,(1U),5);
        tracep->fullCData(oldp+521,(2U),5);
        tracep->fullCData(oldp+522,(3U),5);
        tracep->fullCData(oldp+523,(4U),5);
        tracep->fullCData(oldp+524,(5U),5);
        tracep->fullCData(oldp+525,(6U),5);
        tracep->fullCData(oldp+526,(7U),5);
        tracep->fullCData(oldp+527,(8U),5);
        tracep->fullCData(oldp+528,(9U),5);
        tracep->fullCData(oldp+529,(0xaU),5);
        tracep->fullCData(oldp+530,(0xbU),5);
        tracep->fullCData(oldp+531,(0xcU),5);
        tracep->fullCData(oldp+532,(0xdU),5);
        tracep->fullCData(oldp+533,(0xeU),5);
        tracep->fullCData(oldp+534,(0xfU),5);
        tracep->fullCData(oldp+535,(0x10U),5);
        tracep->fullCData(oldp+536,(0x11U),5);
        tracep->fullCData(oldp+537,(0x12U),5);
        tracep->fullCData(oldp+538,(0x13U),5);
        tracep->fullCData(oldp+539,(0x14U),5);
        tracep->fullCData(oldp+540,(0x15U),5);
        tracep->fullCData(oldp+541,(0x16U),5);
        tracep->fullCData(oldp+542,(0x17U),5);
        tracep->fullCData(oldp+543,(0x18U),5);
        tracep->fullCData(oldp+544,(0x19U),5);
        tracep->fullCData(oldp+545,(0x1aU),5);
        tracep->fullCData(oldp+546,(0x1bU),5);
        tracep->fullCData(oldp+547,(0x1cU),5);
        tracep->fullCData(oldp+548,(0x1dU),5);
        tracep->fullCData(oldp+549,(0x1eU),5);
        tracep->fullCData(oldp+550,(0x1fU),5);
        tracep->fullIData(oldp+551,(0x40U),32);
        tracep->fullIData(oldp+552,(0x14U),32);
        tracep->fullIData(oldp+553,(8U),32);
        tracep->fullIData(oldp+554,(0U),32);
        tracep->fullIData(oldp+555,(0x11U),32);
        tracep->fullBit(oldp+556,(0U));
        tracep->fullBit(oldp+557,(1U));
        tracep->fullCData(oldp+558,(1U),2);
        tracep->fullCData(oldp+559,(2U),2);
        tracep->fullQData(oldp+560,(vlTOPp->Soc__DOT__ram__DOT__rdata_next),64);
    }
}
