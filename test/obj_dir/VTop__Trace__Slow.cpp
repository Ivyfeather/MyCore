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
        tracep->declBit(c+425,"clock", false,-1);
        tracep->declBit(c+426,"reset", false,-1);
        tracep->declQuad(c+427,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+429,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+431,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+433,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+435,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+437,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+439,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+441,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+443,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+445,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+447,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+449,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+451,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+453,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+455,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+457,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+459,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+461,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+463,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+465,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+467,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+469,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+471,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+473,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+475,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+477,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+479,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+481,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+483,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+485,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+487,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+489,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+491,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+493,"io_debug_valid", false,-1);
        tracep->declBit(c+494,"io_debug_trap", false,-1);
        tracep->declQuad(c+495,"io_debug_test", false,-1, 63,0);
        tracep->declBit(c+425,"Top clock", false,-1);
        tracep->declBit(c+426,"Top reset", false,-1);
        tracep->declQuad(c+427,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+429,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+431,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+433,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+435,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+437,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+439,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+441,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+443,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+445,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+447,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+449,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+451,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+453,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+455,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+457,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+459,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+461,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+463,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+465,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+467,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+469,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+471,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+473,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+475,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+477,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+479,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+481,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+483,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+485,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+487,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+489,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+491,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+493,"Top io_debug_valid", false,-1);
        tracep->declBit(c+494,"Top io_debug_trap", false,-1);
        tracep->declQuad(c+495,"Top io_debug_test", false,-1, 63,0);
        tracep->declBit(c+425,"Top core_clock", false,-1);
        tracep->declBit(c+426,"Top core_reset", false,-1);
        tracep->declBit(c+3,"Top core_io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Top core_io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Top core_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+7,"Top core_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+10,"Top core_io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Top core_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Top core_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top core_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Top core_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+18,"Top core_io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core_io_dmem_resp_bits_data", false,-1, 63,0);
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
        tracep->declBus(c+498,"Top ram_awid", false,-1, 7,0);
        tracep->declQuad(c+87,"Top ram_awaddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top ram_awlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top ram_awsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top ram_awburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top ram_awlock", false,-1);
        tracep->declBus(c+502,"Top ram_awcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top ram_awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Top ram_awvalid", false,-1);
        tracep->declBit(c+90,"Top ram_awready", false,-1);
        tracep->declBus(c+498,"Top ram_wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Top ram_wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Top ram_wstrb", false,-1, 7,0);
        tracep->declBit(c+504,"Top ram_wlast", false,-1);
        tracep->declBit(c+94,"Top ram_wvalid", false,-1);
        tracep->declBit(c+95,"Top ram_wready", false,-1);
        tracep->declBus(c+96,"Top ram_bid", false,-1, 7,0);
        tracep->declBus(c+500,"Top ram_bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Top ram_bvalid", false,-1);
        tracep->declBit(c+504,"Top ram_bready", false,-1);
        tracep->declBus(c+498,"Top ram_arid", false,-1, 7,0);
        tracep->declQuad(c+87,"Top ram_araddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top ram_arlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top ram_arsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top ram_arburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top ram_arlock", false,-1);
        tracep->declBus(c+502,"Top ram_arcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top ram_arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Top ram_arvalid", false,-1);
        tracep->declBit(c+99,"Top ram_arready", false,-1);
        tracep->declBus(c+100,"Top ram_rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Top ram_rdata", false,-1, 63,0);
        tracep->declBus(c+500,"Top ram_rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Top ram_rlast", false,-1);
        tracep->declBit(c+102,"Top ram_rvalid", false,-1);
        tracep->declBit(c+504,"Top ram_rready", false,-1);
        tracep->declBit(c+425,"Top ram_clock", false,-1);
        tracep->declBit(c+426,"Top ram_reset", false,-1);
        tracep->declBus(c+498,"Top bridge_awid", false,-1, 7,0);
        tracep->declQuad(c+87,"Top bridge_awaddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top bridge_awlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top bridge_awsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top bridge_awburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top bridge_awlock", false,-1);
        tracep->declBus(c+502,"Top bridge_awcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top bridge_awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Top bridge_awvalid", false,-1);
        tracep->declBit(c+90,"Top bridge_awready", false,-1);
        tracep->declBus(c+498,"Top bridge_wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Top bridge_wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Top bridge_wstrb", false,-1, 7,0);
        tracep->declBit(c+504,"Top bridge_wlast", false,-1);
        tracep->declBit(c+94,"Top bridge_wvalid", false,-1);
        tracep->declBit(c+95,"Top bridge_wready", false,-1);
        tracep->declBus(c+96,"Top bridge_bid", false,-1, 7,0);
        tracep->declBus(c+500,"Top bridge_bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Top bridge_bvalid", false,-1);
        tracep->declBit(c+504,"Top bridge_bready", false,-1);
        tracep->declBus(c+498,"Top bridge_arid", false,-1, 7,0);
        tracep->declQuad(c+87,"Top bridge_araddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top bridge_arlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top bridge_arsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top bridge_arburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top bridge_arlock", false,-1);
        tracep->declBus(c+502,"Top bridge_arcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top bridge_arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Top bridge_arvalid", false,-1);
        tracep->declBit(c+99,"Top bridge_arready", false,-1);
        tracep->declBus(c+100,"Top bridge_rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Top bridge_rdata", false,-1, 63,0);
        tracep->declBus(c+500,"Top bridge_rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Top bridge_rlast", false,-1);
        tracep->declBit(c+102,"Top bridge_rvalid", false,-1);
        tracep->declBit(c+504,"Top bridge_rready", false,-1);
        tracep->declBit(c+425,"Top bridge_clock", false,-1);
        tracep->declBit(c+426,"Top bridge_reset", false,-1);
        tracep->declBit(c+4,"Top bridge_inst_req", false,-1);
        tracep->declBit(c+501,"Top bridge_inst_wr", false,-1);
        tracep->declBus(c+505,"Top bridge_inst_size", false,-1, 7,0);
        tracep->declQuad(c+5,"Top bridge_inst_addr", false,-1, 63,0);
        tracep->declQuad(c+506,"Top bridge_inst_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Top bridge_inst_rdata", false,-1, 63,0);
        tracep->declBit(c+3,"Top bridge_inst_addr_ok", false,-1);
        tracep->declBit(c+7,"Top bridge_inst_data_ok", false,-1);
        tracep->declBit(c+11,"Top bridge_data_req", false,-1);
        tracep->declBit(c+16,"Top bridge_data_wr", false,-1);
        tracep->declBus(c+17,"Top bridge_data_size", false,-1, 7,0);
        tracep->declQuad(c+12,"Top bridge_data_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top bridge_data_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Top bridge_data_rdata", false,-1, 63,0);
        tracep->declBit(c+10,"Top bridge_data_addr_ok", false,-1);
        tracep->declBit(c+18,"Top bridge_data_data_ok", false,-1);
        tracep->declBit(c+425,"Top core clock", false,-1);
        tracep->declBit(c+426,"Top core reset", false,-1);
        tracep->declBit(c+3,"Top core io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Top core io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Top core io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+7,"Top core io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+10,"Top core io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Top core io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Top core io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top core io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Top core io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+18,"Top core io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core io_dmem_resp_bits_data", false,-1, 63,0);
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
        tracep->declBit(c+425,"Top core pre_top_clock", false,-1);
        tracep->declBit(c+426,"Top core pre_top_reset", false,-1);
        tracep->declBit(c+103,"Top core pre_top_io_fs_ready", false,-1);
        tracep->declBit(c+104,"Top core pre_top_io_fs_valid", false,-1);
        tracep->declQuad(c+105,"Top core pre_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Top core pre_top_io_fs_bits_offset", false,-1);
        tracep->declBit(c+3,"Top core pre_top_io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Top core pre_top_io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Top core pre_top_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+108,"Top core pre_top_br_taken_0", false,-1);
        tracep->declQuad(c+109,"Top core pre_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+425,"Top core fs_top_clock", false,-1);
        tracep->declBit(c+426,"Top core fs_top_reset", false,-1);
        tracep->declBit(c+103,"Top core fs_top_io_pres_ready", false,-1);
        tracep->declBit(c+104,"Top core fs_top_io_pres_valid", false,-1);
        tracep->declQuad(c+105,"Top core fs_top_io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Top core fs_top_io_pres_bits_offset", false,-1);
        tracep->declBit(c+111,"Top core fs_top_io_ds_ready", false,-1);
        tracep->declBit(c+112,"Top core fs_top_io_ds_valid", false,-1);
        tracep->declQuad(c+113,"Top core fs_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+115,"Top core fs_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+7,"Top core fs_top_io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core fs_top_io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+425,"Top core ds_top_clock", false,-1);
        tracep->declBit(c+426,"Top core ds_top_reset", false,-1);
        tracep->declBit(c+111,"Top core ds_top_io_fs_ready", false,-1);
        tracep->declBit(c+112,"Top core ds_top_io_fs_valid", false,-1);
        tracep->declQuad(c+113,"Top core ds_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+115,"Top core ds_top_io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+116,"Top core ds_top_io_es_ready", false,-1);
        tracep->declBit(c+117,"Top core ds_top_io_es_valid", false,-1);
        tracep->declQuad(c+118,"Top core ds_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+120,"Top core ds_top_io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+121,"Top core ds_top_io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core ds_top_io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core ds_top_io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core ds_top_io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ds_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core ds_top_io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+127,"Top core ds_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core ds_top_io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+129,"Top core ds_top_io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core ds_top_io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+133,"Top core ds_top_io_wb_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ds_top_io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top_io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ds_top_ms_res_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ds_top_ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ds_top_ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ds_top_io_dmem_resp_valid", false,-1);
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
        tracep->declBit(c+108,"Top core ds_top_br_taken_0", false,-1);
        tracep->declBit(c+141,"Top core ds_top_es_res_rf_we", false,-1);
        tracep->declBus(c+142,"Top core ds_top_es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core ds_top_es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ds_top_es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+109,"Top core ds_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+425,"Top core es_top_clock", false,-1);
        tracep->declBit(c+426,"Top core es_top_reset", false,-1);
        tracep->declBit(c+116,"Top core es_top_io_ds_ready", false,-1);
        tracep->declBit(c+117,"Top core es_top_io_ds_valid", false,-1);
        tracep->declQuad(c+118,"Top core es_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+120,"Top core es_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+121,"Top core es_top_io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core es_top_io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core es_top_io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core es_top_io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core es_top_io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core es_top_io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+127,"Top core es_top_io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core es_top_io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+129,"Top core es_top_io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core es_top_io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+146,"Top core es_top_io_ms_ready", false,-1);
        tracep->declBit(c+147,"Top core es_top_io_ms_valid", false,-1);
        tracep->declQuad(c+148,"Top core es_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+145,"Top core es_top_io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+141,"Top core es_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Top core es_top_io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+150,"Top core es_top_io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+143,"Top core es_top_io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+142,"Top core es_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+151,"Top core es_top_io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+10,"Top core es_top_io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Top core es_top_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Top core es_top_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top core es_top_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core es_top_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Top core es_top_io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+141,"Top core es_top_es_res_0_rf_we", false,-1);
        tracep->declBus(c+142,"Top core es_top_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core es_top_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core es_top_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+425,"Top core ms_top_clock", false,-1);
        tracep->declBit(c+426,"Top core ms_top_reset", false,-1);
        tracep->declBit(c+146,"Top core ms_top_io__es_ready", false,-1);
        tracep->declBit(c+147,"Top core ms_top_io__es_valid", false,-1);
        tracep->declQuad(c+148,"Top core ms_top_io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ms_top_io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+141,"Top core ms_top_io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Top core ms_top_io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+150,"Top core ms_top_io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+143,"Top core ms_top_io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+142,"Top core ms_top_io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+151,"Top core ms_top_io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+152,"Top core ms_top_io__ws_valid", false,-1);
        tracep->declQuad(c+153,"Top core ms_top_io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ms_top_io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+139,"Top core ms_top_io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+138,"Top core ms_top_io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+18,"Top core ms_top_io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core ms_top_io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ms_top_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ms_top_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ms_top_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ms_top_io_dmem_resp_valid", false,-1);
        tracep->declBit(c+425,"Top core ws_top_clock", false,-1);
        tracep->declBit(c+426,"Top core ws_top_reset", false,-1);
        tracep->declBit(c+504,"Top core ws_top_io_ms_ready", false,-1);
        tracep->declBit(c+152,"Top core ws_top_io_ms_valid", false,-1);
        tracep->declQuad(c+153,"Top core ws_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ws_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+139,"Top core ws_top_io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+138,"Top core ws_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+133,"Top core ws_top_io_rf_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ws_top_io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ws_top_io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core ws_top_from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core ws_top_is_commit_0", false,-1);
        tracep->declBit(c+425,"Top core pre_top clock", false,-1);
        tracep->declBit(c+426,"Top core pre_top reset", false,-1);
        tracep->declBit(c+103,"Top core pre_top io_fs_ready", false,-1);
        tracep->declBit(c+104,"Top core pre_top io_fs_valid", false,-1);
        tracep->declQuad(c+105,"Top core pre_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Top core pre_top io_fs_bits_offset", false,-1);
        tracep->declBit(c+3,"Top core pre_top io_imem_req_ready", false,-1);
        tracep->declBit(c+4,"Top core pre_top io_imem_req_valid", false,-1);
        tracep->declQuad(c+5,"Top core pre_top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+108,"Top core pre_top br_taken_0", false,-1);
        tracep->declQuad(c+109,"Top core pre_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+104,"Top core pre_top pre_ready_go", false,-1);
        tracep->declQuad(c+105,"Top core pre_top pre_pc", false,-1, 63,0);
        tracep->declBit(c+155,"Top core pre_top buf_valid", false,-1);
        tracep->declQuad(c+156,"Top core pre_top buf_npc", false,-1, 63,0);
        tracep->declQuad(c+158,"Top core pre_top seq_pc", false,-1, 63,0);
        tracep->declQuad(c+160,"Top core pre_top nextpc", false,-1, 63,0);
        tracep->declBit(c+4,"Top core pre_top imem_req_r", false,-1);
        tracep->declBit(c+425,"Top core fs_top clock", false,-1);
        tracep->declBit(c+426,"Top core fs_top reset", false,-1);
        tracep->declBit(c+103,"Top core fs_top io_pres_ready", false,-1);
        tracep->declBit(c+104,"Top core fs_top io_pres_valid", false,-1);
        tracep->declQuad(c+105,"Top core fs_top io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+107,"Top core fs_top io_pres_bits_offset", false,-1);
        tracep->declBit(c+111,"Top core fs_top io_ds_ready", false,-1);
        tracep->declBit(c+112,"Top core fs_top io_ds_valid", false,-1);
        tracep->declQuad(c+113,"Top core fs_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+115,"Top core fs_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+7,"Top core fs_top io_imem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core fs_top io_imem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+113,"Top core fs_top from_pre_r_PC", false,-1, 63,0);
        tracep->declBit(c+162,"Top core fs_top from_pre_r_offset", false,-1);
        tracep->declBit(c+163,"Top core fs_top fs_ready_go", false,-1);
        tracep->declBit(c+164,"Top core fs_top fs_valid", false,-1);
        tracep->declBit(c+425,"Top core ds_top clock", false,-1);
        tracep->declBit(c+426,"Top core ds_top reset", false,-1);
        tracep->declBit(c+111,"Top core ds_top io_fs_ready", false,-1);
        tracep->declBit(c+112,"Top core ds_top io_fs_valid", false,-1);
        tracep->declQuad(c+113,"Top core ds_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+115,"Top core ds_top io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+116,"Top core ds_top io_es_ready", false,-1);
        tracep->declBit(c+117,"Top core ds_top io_es_valid", false,-1);
        tracep->declQuad(c+118,"Top core ds_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+120,"Top core ds_top io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+121,"Top core ds_top io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core ds_top io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core ds_top io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core ds_top io_es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ds_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core ds_top io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+127,"Top core ds_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core ds_top io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+129,"Top core ds_top io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core ds_top io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+133,"Top core ds_top io_wb_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ds_top io_wb_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top io_wb_wr_data", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ds_top ms_res_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ds_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ds_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ds_top io_dmem_resp_valid", false,-1);
        tracep->declBit(c+86,"Top core ds_top is_trap", false,-1);
        tracep->declBit(c+108,"Top core ds_top br_taken_0", false,-1);
        tracep->declBit(c+141,"Top core ds_top es_res_rf_we", false,-1);
        tracep->declBus(c+142,"Top core ds_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core ds_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ds_top es_res_wb_sel", false,-1, 1,0);
        tracep->declQuad(c+109,"Top core ds_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+425,"Top core ds_top rf_clock", false,-1);
        tracep->declBus(c+165,"Top core ds_top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+166,"Top core ds_top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+133,"Top core ds_top rf_io_ws_res_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ds_top rf_io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top rf_io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+129,"Top core ds_top rf_io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core ds_top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+167,"Top core ds_top rf_io_wr_stall", false,-1);
        tracep->declBit(c+137,"Top core ds_top rf_ms_res_0_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ds_top rf_ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ds_top rf_ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ds_top rf_load_data_returned", false,-1);
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
        tracep->declBit(c+141,"Top core ds_top rf_es_res_0_rf_we", false,-1);
        tracep->declBus(c+142,"Top core ds_top rf_es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core ds_top rf_es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ds_top rf_es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+120,"Top core ds_top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+168,"Top core ds_top idu_io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+121,"Top core ds_top idu_io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core ds_top idu_io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core ds_top idu_io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core ds_top idu_io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ds_top idu_io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core ds_top idu_io_ctrl_mem_en", false,-1);
        tracep->declBit(c+127,"Top core ds_top idu_io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core ds_top idu_io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Top core ds_top idu_is_trap_0", false,-1);
        tracep->declQuad(c+118,"Top core ds_top from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+120,"Top core ds_top from_fs_r_inst", false,-1, 31,0);
        tracep->declBit(c+169,"Top core ds_top ds_ready_go", false,-1);
        tracep->declBit(c+170,"Top core ds_top ds_valid", false,-1);
        tracep->declBus(c+171,"Top core ds_top imm_i", false,-1, 11,0);
        tracep->declBit(c+172,"Top core ds_top right_right", false,-1);
        tracep->declBit(c+173,"Top core ds_top right_left", false,-1);
        tracep->declBus(c+174,"Top core ds_top left_right", false,-1, 5,0);
        tracep->declBus(c+175,"Top core ds_top left_left", false,-1, 3,0);
        tracep->declBus(c+176,"Top core ds_top imm_b", false,-1, 11,0);
        tracep->declBus(c+177,"Top core ds_top right_left_1", false,-1, 7,0);
        tracep->declBit(c+178,"Top core ds_top left_right_1", false,-1);
        tracep->declBus(c+179,"Top core ds_top left_left_1", false,-1, 9,0);
        tracep->declBus(c+180,"Top core ds_top imm_j", false,-1, 19,0);
        tracep->declQuad(c+181,"Top core ds_top right_2", false,-1, 51,0);
        tracep->declQuad(c+183,"Top core ds_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+185,"Top core ds_top right_right_2", false,-1, 52,0);
        tracep->declArray(c+187,"Top core ds_top imm_b_sext", false,-1, 65,0);
        tracep->declQuad(c+190,"Top core ds_top right_right_3", false,-1, 52,0);
        tracep->declArray(c+192,"Top core ds_top imm_j_sext", false,-1, 73,0);
        tracep->declArray(c+195,"Top core ds_top branch_target", false,-1, 65,0);
        tracep->declArray(c+198,"Top core ds_top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+201,"Top core ds_top jr_target", false,-1, 63,0);
        tracep->declBit(c+203,"Top core ds_top rf_eq", false,-1);
        tracep->declBit(c+204,"Top core ds_top rf_lt", false,-1);
        tracep->declBit(c+205,"Top core ds_top rf_ltu", false,-1);
        tracep->declBus(c+206,"Top core ds_top flush_reg", false,-1, 1,0);
        tracep->declBit(c+108,"Top core ds_top br_taken", false,-1);
        tracep->declQuad(c+109,"Top core ds_top br_target", false,-1, 63,0);
        tracep->declBit(c+425,"Top core ds_top rf clock", false,-1);
        tracep->declBus(c+165,"Top core ds_top rf io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+166,"Top core ds_top rf io_rs2_addr", false,-1, 4,0);
        tracep->declBit(c+133,"Top core ds_top rf io_ws_res_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ds_top rf io_ws_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top rf io_ws_res_wr_data", false,-1, 63,0);
        tracep->declQuad(c+129,"Top core ds_top rf io_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core ds_top rf io_rs2_data", false,-1, 63,0);
        tracep->declBit(c+167,"Top core ds_top rf io_wr_stall", false,-1);
        tracep->declBit(c+137,"Top core ds_top rf ms_res_0_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ds_top rf ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ds_top rf ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ds_top rf load_data_returned", false,-1);
        tracep->declBit(c+141,"Top core ds_top rf es_res_0_rf_we", false,-1);
        tracep->declBus(c+142,"Top core ds_top rf es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core ds_top rf es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ds_top rf es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBit(c+425,"Top core ds_top rf rf_clock", false,-1);
        tracep->declBus(c+165,"Top core ds_top rf rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+207,"Top core ds_top rf rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+166,"Top core ds_top rf rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+209,"Top core ds_top rf rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+134,"Top core ds_top rf rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top rf rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+133,"Top core ds_top rf rf_io_wen", false,-1);
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
        tracep->declBit(c+211,"Top core ds_top rf is_load", false,-1);
        tracep->declBit(c+425,"Top core ds_top rf rf clock", false,-1);
        tracep->declBus(c+165,"Top core ds_top rf rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+207,"Top core ds_top rf rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+166,"Top core ds_top rf rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+209,"Top core ds_top rf rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+134,"Top core ds_top rf rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top rf rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+133,"Top core ds_top rf rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+212+i*2,"Top core ds_top rf rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+276,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+165,"Top core ds_top rf rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+278,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+166,"Top core ds_top rf rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top core ds_top rf rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+508,"Top core ds_top rf rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+21,"Top core ds_top rf rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+509,"Top core ds_top rf rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"Top core ds_top rf rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+510,"Top core ds_top rf rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top core ds_top rf rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+511,"Top core ds_top rf rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"Top core ds_top rf rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+512,"Top core ds_top rf rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"Top core ds_top rf rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+513,"Top core ds_top rf rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+31,"Top core ds_top rf rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+514,"Top core ds_top rf rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top core ds_top rf rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+515,"Top core ds_top rf rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+35,"Top core ds_top rf rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+516,"Top core ds_top rf rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+37,"Top core ds_top rf rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+517,"Top core ds_top rf rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+39,"Top core ds_top rf rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+518,"Top core ds_top rf rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+41,"Top core ds_top rf rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+519,"Top core ds_top rf rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+43,"Top core ds_top rf rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+520,"Top core ds_top rf rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+45,"Top core ds_top rf rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+521,"Top core ds_top rf rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+47,"Top core ds_top rf rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+522,"Top core ds_top rf rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+49,"Top core ds_top rf rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+523,"Top core ds_top rf rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+51,"Top core ds_top rf rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+524,"Top core ds_top rf rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+53,"Top core ds_top rf rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+525,"Top core ds_top rf rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+55,"Top core ds_top rf rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+526,"Top core ds_top rf rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+57,"Top core ds_top rf rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+527,"Top core ds_top rf rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+59,"Top core ds_top rf rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+528,"Top core ds_top rf rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+61,"Top core ds_top rf rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+529,"Top core ds_top rf rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+63,"Top core ds_top rf rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+530,"Top core ds_top rf rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"Top core ds_top rf rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+531,"Top core ds_top rf rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+67,"Top core ds_top rf rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+532,"Top core ds_top rf rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+69,"Top core ds_top rf rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+533,"Top core ds_top rf rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"Top core ds_top rf rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+534,"Top core ds_top rf rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+73,"Top core ds_top rf rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+535,"Top core ds_top rf rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+75,"Top core ds_top rf rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+536,"Top core ds_top rf rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+77,"Top core ds_top rf rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+537,"Top core ds_top rf rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+79,"Top core ds_top rf rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+538,"Top core ds_top rf rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+81,"Top core ds_top rf rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+539,"Top core ds_top rf rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ds_top rf rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+134,"Top core ds_top rf rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+504,"Top core ds_top rf rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+133,"Top core ds_top rf rf regfile_MPORT_en", false,-1);
        tracep->declBus(c+120,"Top core ds_top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+168,"Top core ds_top idu io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+121,"Top core ds_top idu io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core ds_top idu io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core ds_top idu io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core ds_top idu io_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core ds_top idu io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core ds_top idu io_ctrl_mem_en", false,-1);
        tracep->declBit(c+127,"Top core ds_top idu io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core ds_top idu io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Top core ds_top idu is_trap_0", false,-1);
        tracep->declBit(c+86,"Top core ds_top idu is_trap", false,-1);
        tracep->declBit(c+425,"Top core es_top clock", false,-1);
        tracep->declBit(c+426,"Top core es_top reset", false,-1);
        tracep->declBit(c+116,"Top core es_top io_ds_ready", false,-1);
        tracep->declBit(c+117,"Top core es_top io_ds_valid", false,-1);
        tracep->declQuad(c+118,"Top core es_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+120,"Top core es_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+121,"Top core es_top io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+122,"Top core es_top io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+123,"Top core es_top io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+124,"Top core es_top io_ds_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+125,"Top core es_top io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+126,"Top core es_top io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+127,"Top core es_top io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+128,"Top core es_top io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+129,"Top core es_top io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+131,"Top core es_top io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+146,"Top core es_top io_ms_ready", false,-1);
        tracep->declBit(c+147,"Top core es_top io_ms_valid", false,-1);
        tracep->declQuad(c+148,"Top core es_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBus(c+145,"Top core es_top io_ms_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+141,"Top core es_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Top core es_top io_ms_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+150,"Top core es_top io_ms_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+143,"Top core es_top io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+142,"Top core es_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+151,"Top core es_top io_ms_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+10,"Top core es_top io_dmem_req_ready", false,-1);
        tracep->declBit(c+11,"Top core es_top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+12,"Top core es_top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top core es_top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+16,"Top core es_top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+17,"Top core es_top io_dmem_req_bits_msk", false,-1, 7,0);
        tracep->declBit(c+141,"Top core es_top es_res_0_rf_we", false,-1);
        tracep->declBus(c+142,"Top core es_top es_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core es_top es_res_0_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core es_top es_res_0_wb_sel", false,-1, 1,0);
        tracep->declBus(c+280,"Top core es_top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+281,"Top core es_top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+283,"Top core es_top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+285,"Top core es_top alu_io_out", false,-1, 63,0);
        tracep->declQuad(c+148,"Top core es_top from_ds_r_PC", false,-1, 63,0);
        tracep->declBus(c+287,"Top core es_top from_ds_r_inst", false,-1, 31,0);
        tracep->declBus(c+288,"Top core es_top from_ds_r_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+289,"Top core es_top from_ds_r_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+280,"Top core es_top from_ds_r_decode_alu_op", false,-1, 5,0);
        tracep->declBus(c+145,"Top core es_top from_ds_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+141,"Top core es_top from_ds_r_decode_rf_wen", false,-1);
        tracep->declBit(c+290,"Top core es_top from_ds_r_decode_mem_en", false,-1);
        tracep->declBit(c+16,"Top core es_top from_ds_r_decode_mem_wr", false,-1);
        tracep->declBus(c+150,"Top core es_top from_ds_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+291,"Top core es_top from_ds_r_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+293,"Top core es_top from_ds_r_rs2_data", false,-1, 63,0);
        tracep->declBit(c+295,"Top core es_top es_ready_go", false,-1);
        tracep->declBit(c+296,"Top core es_top es_valid", false,-1);
        tracep->declBus(c+297,"Top core es_top imm_i", false,-1, 11,0);
        tracep->declBus(c+298,"Top core es_top right", false,-1, 6,0);
        tracep->declBus(c+142,"Top core es_top left", false,-1, 4,0);
        tracep->declBus(c+299,"Top core es_top imm_s", false,-1, 11,0);
        tracep->declBus(c+300,"Top core es_top imm_u", false,-1, 19,0);
        tracep->declBus(c+301,"Top core es_top left_3", false,-1, 4,0);
        tracep->declBus(c+302,"Top core es_top imm_z", false,-1, 31,0);
        tracep->declQuad(c+303,"Top core es_top right_4", false,-1, 51,0);
        tracep->declQuad(c+305,"Top core es_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+307,"Top core es_top right_5", false,-1, 51,0);
        tracep->declQuad(c+309,"Top core es_top imm_s_sext", false,-1, 63,0);
        tracep->declBus(c+311,"Top core es_top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+312,"Top core es_top imm_u_sext", false,-1, 63,0);
        tracep->declBit(c+314,"Top core es_top dmem_req_r", false,-1);
        tracep->declBus(c+315,"Top core es_top offset", false,-1, 3,0);
        tracep->declBus(c+316,"Top core es_top offset_8", false,-1, 6,0);
        tracep->declQuad(c+317,"Top core es_top io_dmem_req_bits_addr_right", false,-1, 60,0);
        tracep->declBit(c+141,"Top core es_top es_res_rf_we", false,-1);
        tracep->declBus(c+142,"Top core es_top es_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+143,"Top core es_top es_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+145,"Top core es_top es_res_wb_sel", false,-1, 1,0);
        tracep->declBus(c+280,"Top core es_top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+281,"Top core es_top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+283,"Top core es_top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+285,"Top core es_top alu io_out", false,-1, 63,0);
        tracep->declQuad(c+319,"Top core es_top alu add2", false,-1, 63,0);
        tracep->declArray(c+321,"Top core es_top alu add_result", false,-1, 65,0);
        tracep->declQuad(c+324,"Top core es_top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+326,"Top core es_top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+328,"Top core es_top alu and_result", false,-1, 63,0);
        tracep->declBit(c+330,"Top core es_top alu sltu_result", false,-1);
        tracep->declBit(c+331,"Top core es_top alu slt_result", false,-1);
        tracep->declBus(c+332,"Top core es_top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+333,"Top core es_top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+335,"Top core es_top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+337,"Top core es_top alu srl_result", false,-1, 63,0);
        tracep->declBus(c+339,"Top core es_top alu shamt5", false,-1, 4,0);
        tracep->declBus(c+340,"Top core es_top alu sllw_result", false,-1, 31,0);
        tracep->declBus(c+341,"Top core es_top alu sraw_result", false,-1, 31,0);
        tracep->declBus(c+342,"Top core es_top alu srlw_result", false,-1, 31,0);
        tracep->declQuad(c+343,"Top core es_top alu io_out_res", false,-1, 63,0);
        tracep->declBus(c+345,"Top core es_top alu io_out_left", false,-1, 31,0);
        tracep->declBus(c+346,"Top core es_top alu io_out_right", false,-1, 31,0);
        tracep->declBus(c+347,"Top core es_top alu io_out_right_2", false,-1, 31,0);
        tracep->declBus(c+348,"Top core es_top alu io_out_right_3", false,-1, 31,0);
        tracep->declBus(c+349,"Top core es_top alu io_out_right_4", false,-1, 31,0);
        tracep->declBit(c+425,"Top core ms_top clock", false,-1);
        tracep->declBit(c+426,"Top core ms_top reset", false,-1);
        tracep->declBit(c+146,"Top core ms_top io__es_ready", false,-1);
        tracep->declBit(c+147,"Top core ms_top io__es_valid", false,-1);
        tracep->declQuad(c+148,"Top core ms_top io__es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+145,"Top core ms_top io__es_bits_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+141,"Top core ms_top io__es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+16,"Top core ms_top io__es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+150,"Top core ms_top io__es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+143,"Top core ms_top io__es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+142,"Top core ms_top io__es_bits_rd_addr", false,-1, 4,0);
        tracep->declBus(c+151,"Top core ms_top io__es_bits_load_offset", false,-1, 2,0);
        tracep->declBit(c+152,"Top core ms_top io__ws_valid", false,-1);
        tracep->declQuad(c+153,"Top core ms_top io__ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ms_top io__ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+139,"Top core ms_top io__ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+138,"Top core ms_top io__ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+18,"Top core ms_top io__dmem_resp_valid", false,-1);
        tracep->declQuad(c+8,"Top core ms_top io__dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ms_top ms_res_0_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ms_top ms_res_0_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ms_top ms_res_0_wr_data", false,-1, 63,0);
        tracep->declBit(c+18,"Top core ms_top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+153,"Top core ms_top from_es_r_PC", false,-1, 63,0);
        tracep->declBus(c+350,"Top core ms_top from_es_r_decode_wb_sel", false,-1, 1,0);
        tracep->declBit(c+137,"Top core ms_top from_es_r_decode_rf_wen", false,-1);
        tracep->declBit(c+351,"Top core ms_top from_es_r_decode_mem_wr", false,-1);
        tracep->declBus(c+352,"Top core ms_top from_es_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+353,"Top core ms_top from_es_r_alu_result", false,-1, 63,0);
        tracep->declBus(c+138,"Top core ms_top from_es_r_rd_addr", false,-1, 4,0);
        tracep->declBus(c+355,"Top core ms_top from_es_r_load_offset", false,-1, 2,0);
        tracep->declBit(c+356,"Top core ms_top ms_valid", false,-1);
        tracep->declBus(c+357,"Top core ms_top unfinished_store", false,-1, 3,0);
        tracep->declBit(c+358,"Top core ms_top res_from_mem", false,-1);
        tracep->declBit(c+359,"Top core ms_top ms_ready_go", false,-1);
        tracep->declQuad(c+360,"Top core ms_top data", false,-1, 63,0);
        tracep->declBus(c+362,"Top core ms_top byte_", false,-1, 7,0);
        tracep->declQuad(c+363,"Top core ms_top right", false,-1, 55,0);
        tracep->declBus(c+365,"Top core ms_top half", false,-1, 15,0);
        tracep->declQuad(c+366,"Top core ms_top right_1", false,-1, 47,0);
        tracep->declBus(c+368,"Top core ms_top word", false,-1, 31,0);
        tracep->declBus(c+369,"Top core ms_top right_2", false,-1, 31,0);
        tracep->declQuad(c+370,"Top core ms_top load_final", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ms_top ms_res_rf_we", false,-1);
        tracep->declBus(c+138,"Top core ms_top ms_res_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+139,"Top core ms_top ms_res_wr_data", false,-1, 63,0);
        tracep->declBus(c+350,"Top core ms_top ms_res_wb_sel", false,-1, 1,0);
        tracep->declBit(c+425,"Top core ws_top clock", false,-1);
        tracep->declBit(c+426,"Top core ws_top reset", false,-1);
        tracep->declBit(c+504,"Top core ws_top io_ms_ready", false,-1);
        tracep->declBit(c+152,"Top core ws_top io_ms_valid", false,-1);
        tracep->declQuad(c+153,"Top core ws_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+137,"Top core ws_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+139,"Top core ws_top io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+138,"Top core ws_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+133,"Top core ws_top io_rf_rf_we", false,-1);
        tracep->declBus(c+134,"Top core ws_top io_rf_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+135,"Top core ws_top io_rf_wr_data", false,-1, 63,0);
        tracep->declQuad(c+83,"Top core ws_top from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+85,"Top core ws_top is_commit_0", false,-1);
        tracep->declQuad(c+83,"Top core ws_top from_ms_r__PC", false,-1, 63,0);
        tracep->declBit(c+133,"Top core ws_top from_ms_r__decode_rf_wen", false,-1);
        tracep->declQuad(c+135,"Top core ws_top from_ms_r__final_result", false,-1, 63,0);
        tracep->declBus(c+134,"Top core ws_top from_ms_r__rd_addr", false,-1, 4,0);
        tracep->declBit(c+85,"Top core ws_top is_commit", false,-1);
        tracep->declBit(c+372,"Top core ws_top REG", false,-1);
        tracep->declBus(c+540,"Top ram DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+541,"Top ram ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+542,"Top ram STRB_WIDTH", false,-1, 31,0);
        tracep->declBus(c+542,"Top ram ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+543,"Top ram PIPELINE_OUTPUT", false,-1, 31,0);
        tracep->declBit(c+425,"Top ram clock", false,-1);
        tracep->declBit(c+426,"Top ram reset", false,-1);
        tracep->declBus(c+498,"Top ram awid", false,-1, 7,0);
        tracep->declBus(c+373,"Top ram awaddr", false,-1, 19,0);
        tracep->declBus(c+498,"Top ram awlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top ram awsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top ram awburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top ram awlock", false,-1);
        tracep->declBus(c+502,"Top ram awcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top ram awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Top ram awvalid", false,-1);
        tracep->declBit(c+90,"Top ram awready", false,-1);
        tracep->declBus(c+498,"Top ram wid", false,-1, 7,0);
        tracep->declQuad(c+91,"Top ram wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Top ram wstrb", false,-1, 7,0);
        tracep->declBit(c+504,"Top ram wlast", false,-1);
        tracep->declBit(c+94,"Top ram wvalid", false,-1);
        tracep->declBit(c+95,"Top ram wready", false,-1);
        tracep->declBus(c+96,"Top ram bid", false,-1, 7,0);
        tracep->declBus(c+500,"Top ram bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Top ram bvalid", false,-1);
        tracep->declBit(c+504,"Top ram bready", false,-1);
        tracep->declBus(c+498,"Top ram arid", false,-1, 7,0);
        tracep->declBus(c+373,"Top ram araddr", false,-1, 19,0);
        tracep->declBus(c+498,"Top ram arlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top ram arsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top ram arburst", false,-1, 1,0);
        tracep->declBit(c+501,"Top ram arlock", false,-1);
        tracep->declBus(c+502,"Top ram arcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top ram arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Top ram arvalid", false,-1);
        tracep->declBit(c+99,"Top ram arready", false,-1);
        tracep->declBus(c+100,"Top ram rid", false,-1, 7,0);
        tracep->declQuad(c+8,"Top ram rdata", false,-1, 63,0);
        tracep->declBus(c+500,"Top ram rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Top ram rlast", false,-1);
        tracep->declBit(c+102,"Top ram rvalid", false,-1);
        tracep->declBit(c+504,"Top ram rready", false,-1);
        tracep->declBus(c+544,"Top ram VALID_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+542,"Top ram WORD_WIDTH", false,-1, 31,0);
        tracep->declBus(c+542,"Top ram WORD_SIZE", false,-1, 31,0);
        tracep->declBus(c+545,"Top ram READ_STATE_IDLE", false,-1, 0,0);
        tracep->declBus(c+546,"Top ram READ_STATE_BURST", false,-1, 0,0);
        tracep->declBus(c+374,"Top ram read_state_reg", false,-1, 0,0);
        tracep->declBus(c+375,"Top ram read_state_next", false,-1, 0,0);
        tracep->declBus(c+500,"Top ram WRITE_STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+547,"Top ram WRITE_STATE_BURST", false,-1, 1,0);
        tracep->declBus(c+548,"Top ram WRITE_STATE_RESP", false,-1, 1,0);
        tracep->declBus(c+376,"Top ram write_state_reg", false,-1, 1,0);
        tracep->declBus(c+377,"Top ram write_state_next", false,-1, 1,0);
        tracep->declBit(c+378,"Top ram mem_wr_en", false,-1);
        tracep->declBit(c+379,"Top ram mem_rd_en", false,-1);
        tracep->declBus(c+380,"Top ram read_id_reg", false,-1, 7,0);
        tracep->declBus(c+381,"Top ram read_id_next", false,-1, 7,0);
        tracep->declBus(c+382,"Top ram read_addr_reg", false,-1, 19,0);
        tracep->declBus(c+383,"Top ram read_addr_next", false,-1, 19,0);
        tracep->declBus(c+384,"Top ram read_count_reg", false,-1, 7,0);
        tracep->declBus(c+385,"Top ram read_count_next", false,-1, 7,0);
        tracep->declBus(c+386,"Top ram read_size_reg", false,-1, 2,0);
        tracep->declBus(c+387,"Top ram read_size_next", false,-1, 2,0);
        tracep->declBus(c+388,"Top ram read_burst_reg", false,-1, 1,0);
        tracep->declBus(c+389,"Top ram read_burst_next", false,-1, 1,0);
        tracep->declBus(c+390,"Top ram write_id_reg", false,-1, 7,0);
        tracep->declBus(c+391,"Top ram write_id_next", false,-1, 7,0);
        tracep->declBus(c+392,"Top ram write_addr_reg", false,-1, 19,0);
        tracep->declBus(c+393,"Top ram write_addr_next", false,-1, 19,0);
        tracep->declBus(c+394,"Top ram write_count_reg", false,-1, 7,0);
        tracep->declBus(c+395,"Top ram write_count_next", false,-1, 7,0);
        tracep->declBus(c+396,"Top ram write_size_reg", false,-1, 2,0);
        tracep->declBus(c+397,"Top ram write_size_next", false,-1, 2,0);
        tracep->declBus(c+398,"Top ram write_burst_reg", false,-1, 1,0);
        tracep->declBus(c+399,"Top ram write_burst_next", false,-1, 1,0);
        tracep->declBit(c+90,"Top ram awready_reg", false,-1);
        tracep->declBit(c+400,"Top ram awready_next", false,-1);
        tracep->declBit(c+95,"Top ram wready_reg", false,-1);
        tracep->declBit(c+401,"Top ram wready_next", false,-1);
        tracep->declBus(c+96,"Top ram bid_reg", false,-1, 7,0);
        tracep->declBus(c+402,"Top ram bid_next", false,-1, 7,0);
        tracep->declBit(c+97,"Top ram bvalid_reg", false,-1);
        tracep->declBit(c+403,"Top ram bvalid_next", false,-1);
        tracep->declBit(c+99,"Top ram arready_reg", false,-1);
        tracep->declBit(c+404,"Top ram arready_next", false,-1);
        tracep->declBus(c+100,"Top ram rid_reg", false,-1, 7,0);
        tracep->declBus(c+405,"Top ram rid_next", false,-1, 7,0);
        tracep->declQuad(c+8,"Top ram rdata_reg", false,-1, 63,0);
        tracep->declQuad(c+549,"Top ram rdata_next", false,-1, 63,0);
        tracep->declBit(c+101,"Top ram rlast_reg", false,-1);
        tracep->declBit(c+406,"Top ram rlast_next", false,-1);
        tracep->declBit(c+102,"Top ram rvalid_reg", false,-1);
        tracep->declBit(c+407,"Top ram rvalid_next", false,-1);
        tracep->declBus(c+408,"Top ram rid_pipe_reg", false,-1, 7,0);
        tracep->declQuad(c+409,"Top ram rdata_pipe_reg", false,-1, 63,0);
        tracep->declBit(c+411,"Top ram rlast_pipe_reg", false,-1);
        tracep->declBit(c+412,"Top ram rvalid_pipe_reg", false,-1);
        tracep->declBus(c+413,"Top ram awaddr_valid", false,-1, 16,0);
        tracep->declBus(c+413,"Top ram araddr_valid", false,-1, 16,0);
        tracep->declBus(c+414,"Top ram read_addr_valid", false,-1, 16,0);
        tracep->declBus(c+415,"Top ram write_addr_valid", false,-1, 16,0);
        tracep->declBus(c+416,"Top ram i", false,-1, 31,0);
        tracep->declBus(c+1,"Top ram j", false,-1, 31,0);
        tracep->declBus(c+2,"Top ram mem_file", false,-1, 31,0);
        tracep->declBit(c+425,"Top bridge clock", false,-1);
        tracep->declBit(c+426,"Top bridge reset", false,-1);
        tracep->declBit(c+4,"Top bridge inst_req", false,-1);
        tracep->declBit(c+501,"Top bridge inst_wr", false,-1);
        tracep->declBus(c+505,"Top bridge inst_size", false,-1, 7,0);
        tracep->declQuad(c+5,"Top bridge inst_addr", false,-1, 63,0);
        tracep->declQuad(c+506,"Top bridge inst_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Top bridge inst_rdata", false,-1, 63,0);
        tracep->declBit(c+3,"Top bridge inst_addr_ok", false,-1);
        tracep->declBit(c+7,"Top bridge inst_data_ok", false,-1);
        tracep->declBit(c+11,"Top bridge data_req", false,-1);
        tracep->declBit(c+16,"Top bridge data_wr", false,-1);
        tracep->declBus(c+17,"Top bridge data_size", false,-1, 7,0);
        tracep->declQuad(c+12,"Top bridge data_addr", false,-1, 63,0);
        tracep->declQuad(c+14,"Top bridge data_wdata", false,-1, 63,0);
        tracep->declQuad(c+8,"Top bridge data_rdata", false,-1, 63,0);
        tracep->declBit(c+10,"Top bridge data_addr_ok", false,-1);
        tracep->declBit(c+18,"Top bridge data_data_ok", false,-1);
        tracep->declBus(c+502,"Top bridge arid", false,-1, 3,0);
        tracep->declQuad(c+87,"Top bridge araddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top bridge arlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top bridge arsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top bridge arburst", false,-1, 1,0);
        tracep->declBus(c+500,"Top bridge arlock", false,-1, 1,0);
        tracep->declBus(c+502,"Top bridge arcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top bridge arprot", false,-1, 2,0);
        tracep->declBit(c+98,"Top bridge arvalid", false,-1);
        tracep->declBit(c+99,"Top bridge arready", false,-1);
        tracep->declBus(c+417,"Top bridge rid", false,-1, 3,0);
        tracep->declQuad(c+8,"Top bridge rdata", false,-1, 63,0);
        tracep->declBus(c+500,"Top bridge rresp", false,-1, 1,0);
        tracep->declBit(c+101,"Top bridge rlast", false,-1);
        tracep->declBit(c+102,"Top bridge rvalid", false,-1);
        tracep->declBit(c+504,"Top bridge rready", false,-1);
        tracep->declBus(c+502,"Top bridge awid", false,-1, 3,0);
        tracep->declQuad(c+87,"Top bridge awaddr", false,-1, 63,0);
        tracep->declBus(c+498,"Top bridge awlen", false,-1, 7,0);
        tracep->declBus(c+499,"Top bridge awsize", false,-1, 2,0);
        tracep->declBus(c+500,"Top bridge awburst", false,-1, 1,0);
        tracep->declBus(c+500,"Top bridge awlock", false,-1, 1,0);
        tracep->declBus(c+502,"Top bridge awcache", false,-1, 3,0);
        tracep->declBus(c+503,"Top bridge awprot", false,-1, 2,0);
        tracep->declBit(c+89,"Top bridge awvalid", false,-1);
        tracep->declBit(c+90,"Top bridge awready", false,-1);
        tracep->declBus(c+502,"Top bridge wid", false,-1, 3,0);
        tracep->declQuad(c+91,"Top bridge wdata", false,-1, 63,0);
        tracep->declBus(c+93,"Top bridge wstrb", false,-1, 7,0);
        tracep->declBit(c+504,"Top bridge wlast", false,-1);
        tracep->declBit(c+94,"Top bridge wvalid", false,-1);
        tracep->declBit(c+95,"Top bridge wready", false,-1);
        tracep->declBus(c+418,"Top bridge bid", false,-1, 3,0);
        tracep->declBus(c+500,"Top bridge bresp", false,-1, 1,0);
        tracep->declBit(c+97,"Top bridge bvalid", false,-1);
        tracep->declBit(c+504,"Top bridge bready", false,-1);
        tracep->declBit(c+497,"Top bridge resetn", false,-1);
        tracep->declBit(c+419,"Top bridge do_req", false,-1);
        tracep->declBit(c+420,"Top bridge do_req_or", false,-1);
        tracep->declBit(c+421,"Top bridge do_wr_r", false,-1);
        tracep->declBus(c+93,"Top bridge do_size_r", false,-1, 7,0);
        tracep->declQuad(c+87,"Top bridge do_addr_r", false,-1, 63,0);
        tracep->declQuad(c+91,"Top bridge do_wdata_r", false,-1, 63,0);
        tracep->declBit(c+422,"Top bridge data_back", false,-1);
        tracep->declBit(c+423,"Top bridge addr_rcv", false,-1);
        tracep->declBit(c+424,"Top bridge wdata_rcv", false,-1);
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
        tracep->fullIData(oldp+1,(vlTOPp->Top__DOT__ram__DOT__j),32);
        tracep->fullIData(oldp+2,(vlTOPp->Top__DOT__ram__DOT__mem_file),32);
        tracep->fullBit(oldp+3,(vlTOPp->Top__DOT__bridge_inst_addr_ok));
        tracep->fullBit(oldp+4,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__imem_req_r));
        tracep->fullQData(oldp+5,((0xfffffffffffffff8ULL 
                                   & vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc)),64);
        tracep->fullBit(oldp+7,(vlTOPp->Top__DOT__bridge_inst_data_ok));
        tracep->fullQData(oldp+8,(vlTOPp->Top__DOT__ram__DOT__rdata_reg),64);
        tracep->fullBit(oldp+10,((1U & (~ (IData)(vlTOPp->Top__DOT__bridge__DOT__do_req)))));
        tracep->fullBit(oldp+11,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
        tracep->fullQData(oldp+12,((0xfffffffffffffff8ULL 
                                    & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
        tracep->fullQData(oldp+14,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
        tracep->fullBit(oldp+16,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
        tracep->fullCData(oldp+17,((0xffU & vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
        tracep->fullBit(oldp+18,(vlTOPp->Top__DOT__bridge_data_data_ok));
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
        tracep->fullQData(oldp+87,(vlTOPp->Top__DOT__bridge__DOT__do_addr_r),64);
        tracep->fullBit(oldp+89,(vlTOPp->Top__DOT__bridge_awvalid));
        tracep->fullBit(oldp+90,(vlTOPp->Top__DOT__ram__DOT__awready_reg));
        tracep->fullQData(oldp+91,(vlTOPp->Top__DOT__bridge__DOT__do_wdata_r),64);
        tracep->fullCData(oldp+93,(vlTOPp->Top__DOT__bridge__DOT__do_size_r),8);
        tracep->fullBit(oldp+94,(vlTOPp->Top__DOT__bridge_wvalid));
        tracep->fullBit(oldp+95,(vlTOPp->Top__DOT__ram__DOT__wready_reg));
        tracep->fullCData(oldp+96,(vlTOPp->Top__DOT__ram__DOT__bid_reg),8);
        tracep->fullBit(oldp+97,(vlTOPp->Top__DOT__ram__DOT__bvalid_reg));
        tracep->fullBit(oldp+98,(vlTOPp->Top__DOT__bridge_arvalid));
        tracep->fullBit(oldp+99,(vlTOPp->Top__DOT__ram__DOT__arready_reg));
        tracep->fullCData(oldp+100,(vlTOPp->Top__DOT__ram__DOT__rid_reg),8);
        tracep->fullBit(oldp+101,(vlTOPp->Top__DOT__ram__DOT__rlast_reg));
        tracep->fullBit(oldp+102,(vlTOPp->Top__DOT__ram__DOT__rvalid_reg));
        tracep->fullBit(oldp+103,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
        tracep->fullBit(oldp+104,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
        tracep->fullQData(oldp+105,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
        tracep->fullBit(oldp+107,((1U & (IData)((vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                 >> 2U)))));
        tracep->fullBit(oldp+108,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
        tracep->fullQData(oldp+109,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
        tracep->fullBit(oldp+111,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
        tracep->fullBit(oldp+112,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
        tracep->fullQData(oldp+113,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
        tracep->fullIData(oldp+115,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
        tracep->fullBit(oldp+116,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
        tracep->fullBit(oldp+117,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
        tracep->fullQData(oldp+118,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
        tracep->fullIData(oldp+120,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
        tracep->fullCData(oldp+121,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
        tracep->fullCData(oldp+122,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
        tracep->fullCData(oldp+123,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
        tracep->fullCData(oldp+124,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
        tracep->fullBit(oldp+125,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
        tracep->fullBit(oldp+126,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
        tracep->fullBit(oldp+127,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
        tracep->fullCData(oldp+128,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
        tracep->fullQData(oldp+129,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+131,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+133,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
        tracep->fullCData(oldp+134,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
        tracep->fullQData(oldp+135,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
        tracep->fullBit(oldp+137,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
        tracep->fullCData(oldp+138,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
        tracep->fullQData(oldp+139,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
        tracep->fullBit(oldp+141,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
        tracep->fullCData(oldp+142,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 7U))),5);
        tracep->fullQData(oldp+143,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
        tracep->fullCData(oldp+145,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
        tracep->fullBit(oldp+146,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fes_ready));
        tracep->fullBit(oldp+147,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
        tracep->fullQData(oldp+148,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
        tracep->fullCData(oldp+150,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
        tracep->fullCData(oldp+151,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
        tracep->fullBit(oldp+152,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_valid));
        tracep->fullQData(oldp+153,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
        tracep->fullBit(oldp+155,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
        tracep->fullQData(oldp+156,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
        tracep->fullQData(oldp+158,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
        tracep->fullQData(oldp+160,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc),64);
        tracep->fullBit(oldp+162,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
        tracep->fullBit(oldp+163,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
        tracep->fullBit(oldp+164,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
        tracep->fullCData(oldp+165,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+166,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x14U))),5);
        tracep->fullBit(oldp+167,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
        tracep->fullCData(oldp+168,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
        tracep->fullBit(oldp+169,((1U & (~ (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
        tracep->fullBit(oldp+170,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
        tracep->fullSData(oldp+171,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+172,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+173,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 7U))));
        tracep->fullCData(oldp+174,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+175,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                             >> 8U))),4);
        tracep->fullSData(oldp+176,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
        tracep->fullCData(oldp+177,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+178,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+179,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+180,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
        tracep->fullQData(oldp+181,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+183,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+185,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+187,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
        tracep->fullQData(oldp+190,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+192,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
        tracep->fullWData(oldp+195,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
        tracep->fullWData(oldp+198,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
        tracep->fullQData(oldp+201,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
        tracep->fullBit(oldp+203,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
        tracep->fullBit(oldp+204,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
        tracep->fullBit(oldp+205,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
        tracep->fullCData(oldp+206,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
        tracep->fullQData(oldp+207,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+209,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+211,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
        tracep->fullQData(oldp+212,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+214,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+216,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+218,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+220,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+222,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+224,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+226,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+228,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+230,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+232,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+234,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+236,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+238,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+240,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+242,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+244,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+246,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+248,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+250,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+252,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+254,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+256,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+258,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+260,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+262,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+264,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+266,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+268,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+270,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+272,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+274,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+276,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+278,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullCData(oldp+280,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
        tracep->fullQData(oldp+281,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+283,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
        tracep->fullQData(oldp+285,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
        tracep->fullIData(oldp+287,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
        tracep->fullCData(oldp+288,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
        tracep->fullCData(oldp+289,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
        tracep->fullBit(oldp+290,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
        tracep->fullQData(oldp+291,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
        tracep->fullQData(oldp+293,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
        tracep->fullBit(oldp+295,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
        tracep->fullBit(oldp+296,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
        tracep->fullSData(oldp+297,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+298,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0x19U))),7);
        tracep->fullSData(oldp+299,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
        tracep->fullIData(oldp+300,((0xfffffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+301,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),5);
        tracep->fullIData(oldp+302,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+303,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+305,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+307,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+309,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
        tracep->fullIData(oldp+311,(((0x800000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+312,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
        tracep->fullBit(oldp+314,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
        tracep->fullCData(oldp+315,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
        tracep->fullCData(oldp+316,((0x38U & ((IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                              << 3U))),7);
        tracep->fullQData(oldp+317,((0x1fffffffffffffffULL 
                                     & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out 
                                        >> 3U))),61);
        tracep->fullQData(oldp+319,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
        tracep->fullWData(oldp+321,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
        tracep->fullQData(oldp+324,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+326,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+328,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+330,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+331,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+332,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+333,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
        tracep->fullQData(oldp+335,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+337,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
        tracep->fullCData(oldp+339,((0x1fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
        tracep->fullIData(oldp+340,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
        tracep->fullIData(oldp+341,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
        tracep->fullIData(oldp+342,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
        tracep->fullQData(oldp+343,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullIData(oldp+345,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
        tracep->fullIData(oldp+346,(((0x80000000U & 
                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+347,(((0x80000000U & 
                                      vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+348,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+349,(((0x80000000U & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullCData(oldp+350,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
        tracep->fullBit(oldp+351,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
        tracep->fullCData(oldp+352,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
        tracep->fullQData(oldp+353,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
        tracep->fullCData(oldp+355,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
        tracep->fullBit(oldp+356,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
        tracep->fullCData(oldp+357,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
        tracep->fullBit(oldp+358,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
        tracep->fullBit(oldp+359,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_ready_go));
        tracep->fullQData(oldp+360,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data),64);
        tracep->fullCData(oldp+362,((0xffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),8);
        tracep->fullQData(oldp+363,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 7U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullSData(oldp+365,((0xffffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),16);
        tracep->fullQData(oldp+366,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0xfU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullIData(oldp+368,((IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data)),32);
        tracep->fullIData(oldp+369,(((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                    >> 0x1fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+370,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__load_final),64);
        tracep->fullBit(oldp+372,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
        tracep->fullIData(oldp+373,((0xfffffU & (IData)(vlTOPp->Top__DOT__bridge__DOT__do_addr_r))),20);
        tracep->fullBit(oldp+374,(vlTOPp->Top__DOT__ram__DOT__read_state_reg));
        tracep->fullBit(oldp+375,(vlTOPp->Top__DOT__ram__DOT__read_state_next));
        tracep->fullCData(oldp+376,(vlTOPp->Top__DOT__ram__DOT__write_state_reg),2);
        tracep->fullCData(oldp+377,(vlTOPp->Top__DOT__ram__DOT__write_state_next),2);
        tracep->fullBit(oldp+378,(vlTOPp->Top__DOT__ram__DOT__mem_wr_en));
        tracep->fullBit(oldp+379,(vlTOPp->Top__DOT__ram__DOT__mem_rd_en));
        tracep->fullCData(oldp+380,(vlTOPp->Top__DOT__ram__DOT__read_id_reg),8);
        tracep->fullCData(oldp+381,(vlTOPp->Top__DOT__ram__DOT__read_id_next),8);
        tracep->fullIData(oldp+382,(vlTOPp->Top__DOT__ram__DOT__read_addr_reg),20);
        tracep->fullIData(oldp+383,(vlTOPp->Top__DOT__ram__DOT__read_addr_next),20);
        tracep->fullCData(oldp+384,(vlTOPp->Top__DOT__ram__DOT__read_count_reg),8);
        tracep->fullCData(oldp+385,(vlTOPp->Top__DOT__ram__DOT__read_count_next),8);
        tracep->fullCData(oldp+386,(vlTOPp->Top__DOT__ram__DOT__read_size_reg),3);
        tracep->fullCData(oldp+387,(vlTOPp->Top__DOT__ram__DOT__read_size_next),3);
        tracep->fullCData(oldp+388,(vlTOPp->Top__DOT__ram__DOT__read_burst_reg),2);
        tracep->fullCData(oldp+389,(vlTOPp->Top__DOT__ram__DOT__read_burst_next),2);
        tracep->fullCData(oldp+390,(vlTOPp->Top__DOT__ram__DOT__write_id_reg),8);
        tracep->fullCData(oldp+391,(vlTOPp->Top__DOT__ram__DOT__write_id_next),8);
        tracep->fullIData(oldp+392,(vlTOPp->Top__DOT__ram__DOT__write_addr_reg),20);
        tracep->fullIData(oldp+393,(vlTOPp->Top__DOT__ram__DOT__write_addr_next),20);
        tracep->fullCData(oldp+394,(vlTOPp->Top__DOT__ram__DOT__write_count_reg),8);
        tracep->fullCData(oldp+395,(vlTOPp->Top__DOT__ram__DOT__write_count_next),8);
        tracep->fullCData(oldp+396,(vlTOPp->Top__DOT__ram__DOT__write_size_reg),3);
        tracep->fullCData(oldp+397,(vlTOPp->Top__DOT__ram__DOT__write_size_next),3);
        tracep->fullCData(oldp+398,(vlTOPp->Top__DOT__ram__DOT__write_burst_reg),2);
        tracep->fullCData(oldp+399,(vlTOPp->Top__DOT__ram__DOT__write_burst_next),2);
        tracep->fullBit(oldp+400,(vlTOPp->Top__DOT__ram__DOT__awready_next));
        tracep->fullBit(oldp+401,(vlTOPp->Top__DOT__ram__DOT__wready_next));
        tracep->fullCData(oldp+402,(vlTOPp->Top__DOT__ram__DOT__bid_next),8);
        tracep->fullBit(oldp+403,(vlTOPp->Top__DOT__ram__DOT__bvalid_next));
        tracep->fullBit(oldp+404,(vlTOPp->Top__DOT__ram__DOT__arready_next));
        tracep->fullCData(oldp+405,(vlTOPp->Top__DOT__ram__DOT__rid_next),8);
        tracep->fullBit(oldp+406,(vlTOPp->Top__DOT__ram__DOT__rlast_next));
        tracep->fullBit(oldp+407,(vlTOPp->Top__DOT__ram__DOT__rvalid_next));
        tracep->fullCData(oldp+408,(vlTOPp->Top__DOT__ram__DOT__rid_pipe_reg),8);
        tracep->fullQData(oldp+409,(vlTOPp->Top__DOT__ram__DOT__rdata_pipe_reg),64);
        tracep->fullBit(oldp+411,(vlTOPp->Top__DOT__ram__DOT__rlast_pipe_reg));
        tracep->fullBit(oldp+412,(vlTOPp->Top__DOT__ram__DOT__rvalid_pipe_reg));
        tracep->fullIData(oldp+413,((0x1ffffU & (IData)(
                                                        (vlTOPp->Top__DOT__bridge__DOT__do_addr_r 
                                                         >> 3U)))),17);
        tracep->fullIData(oldp+414,((0x1ffffU & (vlTOPp->Top__DOT__ram__DOT__read_addr_reg 
                                                 >> 3U))),17);
        tracep->fullIData(oldp+415,((0x1ffffU & (vlTOPp->Top__DOT__ram__DOT__write_addr_reg 
                                                 >> 3U))),17);
        tracep->fullIData(oldp+416,(vlTOPp->Top__DOT__ram__DOT__i),32);
        tracep->fullCData(oldp+417,((0xfU & (IData)(vlTOPp->Top__DOT__ram__DOT__rid_reg))),4);
        tracep->fullCData(oldp+418,((0xfU & (IData)(vlTOPp->Top__DOT__ram__DOT__bid_reg))),4);
        tracep->fullBit(oldp+419,(vlTOPp->Top__DOT__bridge__DOT__do_req));
        tracep->fullBit(oldp+420,(vlTOPp->Top__DOT__bridge__DOT__do_req_or));
        tracep->fullBit(oldp+421,(vlTOPp->Top__DOT__bridge__DOT__do_wr_r));
        tracep->fullBit(oldp+422,(vlTOPp->Top__DOT__bridge__DOT__data_back));
        tracep->fullBit(oldp+423,(vlTOPp->Top__DOT__bridge__DOT__addr_rcv));
        tracep->fullBit(oldp+424,(vlTOPp->Top__DOT__bridge__DOT__wdata_rcv));
        tracep->fullBit(oldp+425,(vlTOPp->clock));
        tracep->fullBit(oldp+426,(vlTOPp->reset));
        tracep->fullQData(oldp+427,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+429,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+431,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+433,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+435,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+437,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+439,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+441,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+443,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+445,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+447,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+449,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+451,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+453,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+455,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+457,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+459,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+461,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+463,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+465,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+467,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+469,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+471,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+473,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+475,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+477,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+479,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+481,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+483,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+485,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+487,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+489,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+491,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+493,(vlTOPp->io_debug_valid));
        tracep->fullBit(oldp+494,(vlTOPp->io_debug_trap));
        tracep->fullQData(oldp+495,(vlTOPp->io_debug_test),64);
        tracep->fullBit(oldp+497,((1U & (~ (IData)(vlTOPp->reset)))));
        tracep->fullCData(oldp+498,(0U),8);
        tracep->fullCData(oldp+499,(3U),3);
        tracep->fullCData(oldp+500,(0U),2);
        tracep->fullBit(oldp+501,(0U));
        tracep->fullCData(oldp+502,(0U),4);
        tracep->fullCData(oldp+503,(0U),3);
        tracep->fullBit(oldp+504,(1U));
        tracep->fullCData(oldp+505,(0xffU),8);
        tracep->fullQData(oldp+506,(0ULL),64);
        tracep->fullCData(oldp+508,(0U),5);
        tracep->fullCData(oldp+509,(1U),5);
        tracep->fullCData(oldp+510,(2U),5);
        tracep->fullCData(oldp+511,(3U),5);
        tracep->fullCData(oldp+512,(4U),5);
        tracep->fullCData(oldp+513,(5U),5);
        tracep->fullCData(oldp+514,(6U),5);
        tracep->fullCData(oldp+515,(7U),5);
        tracep->fullCData(oldp+516,(8U),5);
        tracep->fullCData(oldp+517,(9U),5);
        tracep->fullCData(oldp+518,(0xaU),5);
        tracep->fullCData(oldp+519,(0xbU),5);
        tracep->fullCData(oldp+520,(0xcU),5);
        tracep->fullCData(oldp+521,(0xdU),5);
        tracep->fullCData(oldp+522,(0xeU),5);
        tracep->fullCData(oldp+523,(0xfU),5);
        tracep->fullCData(oldp+524,(0x10U),5);
        tracep->fullCData(oldp+525,(0x11U),5);
        tracep->fullCData(oldp+526,(0x12U),5);
        tracep->fullCData(oldp+527,(0x13U),5);
        tracep->fullCData(oldp+528,(0x14U),5);
        tracep->fullCData(oldp+529,(0x15U),5);
        tracep->fullCData(oldp+530,(0x16U),5);
        tracep->fullCData(oldp+531,(0x17U),5);
        tracep->fullCData(oldp+532,(0x18U),5);
        tracep->fullCData(oldp+533,(0x19U),5);
        tracep->fullCData(oldp+534,(0x1aU),5);
        tracep->fullCData(oldp+535,(0x1bU),5);
        tracep->fullCData(oldp+536,(0x1cU),5);
        tracep->fullCData(oldp+537,(0x1dU),5);
        tracep->fullCData(oldp+538,(0x1eU),5);
        tracep->fullCData(oldp+539,(0x1fU),5);
        tracep->fullIData(oldp+540,(0x40U),32);
        tracep->fullIData(oldp+541,(0x14U),32);
        tracep->fullIData(oldp+542,(8U),32);
        tracep->fullIData(oldp+543,(0U),32);
        tracep->fullIData(oldp+544,(0x11U),32);
        tracep->fullBit(oldp+545,(0U));
        tracep->fullBit(oldp+546,(1U));
        tracep->fullCData(oldp+547,(1U),2);
        tracep->fullCData(oldp+548,(2U),2);
        tracep->fullQData(oldp+549,(vlTOPp->Top__DOT__ram__DOT__rdata_next),64);
    }
}
