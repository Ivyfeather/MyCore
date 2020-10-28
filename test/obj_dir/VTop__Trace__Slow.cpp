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
        tracep->declBit(c+290,"clock", false,-1);
        tracep->declBit(c+291,"reset", false,-1);
        tracep->declBit(c+292,"io_imem_req_ready", false,-1);
        tracep->declBit(c+293,"io_imem_req_valid", false,-1);
        tracep->declQuad(c+294,"io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBus(c+296,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+297,"io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+298,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+299,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+300,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+301,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+302,"io_dmem_req_valid", false,-1);
        tracep->declQuad(c+303,"io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+305,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+307,"io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+308,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+309,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+310,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+312,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+314,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+316,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+318,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+320,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+322,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+324,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+326,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+328,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+330,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+332,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+334,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+336,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+338,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+340,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+342,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+344,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+346,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+348,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+350,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+352,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+354,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+356,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+358,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+360,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+362,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+364,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+366,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+368,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+370,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+372,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+374,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+376,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+378,"io_debug_stall", false,-1);
        tracep->declBit(c+379,"io_debug_trap", false,-1);
        tracep->declBus(c+380,"io_debug_inst", false,-1, 31,0);
        tracep->declBit(c+290,"Top clock", false,-1);
        tracep->declBit(c+291,"Top reset", false,-1);
        tracep->declBit(c+292,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+293,"Top io_imem_req_valid", false,-1);
        tracep->declQuad(c+294,"Top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBus(c+296,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+297,"Top io_imem_req_bits_wr", false,-1);
        tracep->declBus(c+298,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+299,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+300,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+301,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+302,"Top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+303,"Top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+305,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+307,"Top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+308,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+309,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+310,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+312,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+314,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+316,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+318,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+320,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+322,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+324,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+326,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+328,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+330,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+332,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+334,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+336,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+338,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+340,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+342,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+344,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+346,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+348,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+350,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+352,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+354,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+356,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+358,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+360,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+362,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+364,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+366,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+368,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+370,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+372,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+374,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+376,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+378,"Top io_debug_stall", false,-1);
        tracep->declBit(c+379,"Top io_debug_trap", false,-1);
        tracep->declBus(c+380,"Top io_debug_inst", false,-1, 31,0);
        tracep->declBit(c+290,"Top pre_top_clock", false,-1);
        tracep->declBit(c+291,"Top pre_top_reset", false,-1);
        tracep->declBit(c+1,"Top pre_top_io_fs_ready", false,-1);
        tracep->declBit(c+6,"Top pre_top_io_fs_valid", false,-1);
        tracep->declQuad(c+7,"Top pre_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+292,"Top pre_top_io_imem_req_ready", false,-1);
        tracep->declBit(c+9,"Top pre_top_io_imem_req_valid", false,-1);
        tracep->declQuad(c+7,"Top pre_top_io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+10,"Top pre_top_br_taken_0", false,-1);
        tracep->declQuad(c+11,"Top pre_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+290,"Top fs_top_clock", false,-1);
        tracep->declBit(c+291,"Top fs_top_reset", false,-1);
        tracep->declBit(c+1,"Top fs_top_io_pres_ready", false,-1);
        tracep->declBit(c+6,"Top fs_top_io_pres_valid", false,-1);
        tracep->declQuad(c+7,"Top fs_top_io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+2,"Top fs_top_io_ds_ready", false,-1);
        tracep->declBit(c+13,"Top fs_top_io_ds_valid", false,-1);
        tracep->declQuad(c+14,"Top fs_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+300,"Top fs_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+299,"Top fs_top_io_imem_resp_valid", false,-1);
        tracep->declBus(c+300,"Top fs_top_io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+290,"Top ds_top_clock", false,-1);
        tracep->declBit(c+291,"Top ds_top_reset", false,-1);
        tracep->declBit(c+2,"Top ds_top_io_fs_ready", false,-1);
        tracep->declBit(c+13,"Top ds_top_io_fs_valid", false,-1);
        tracep->declQuad(c+14,"Top ds_top_io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+300,"Top ds_top_io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+3,"Top ds_top_io_es_ready", false,-1);
        tracep->declBit(c+16,"Top ds_top_io_es_valid", false,-1);
        tracep->declQuad(c+17,"Top ds_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+19,"Top ds_top_io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+20,"Top ds_top_io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top ds_top_io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top ds_top_io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top ds_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+24,"Top ds_top_io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+25,"Top ds_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+26,"Top ds_top_io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+27,"Top ds_top_io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+29,"Top ds_top_io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+31,"Top ds_top_io_wb_rf_we", false,-1);
        tracep->declBus(c+32,"Top ds_top_io_wb_rf_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ds_top_io_wb_rf_data", false,-1, 63,0);
        tracep->declBit(c+35,"Top ds_top_is_trap", false,-1);
        tracep->declQuad(c+36,"Top ds_top__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+38,"Top ds_top__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+40,"Top ds_top__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+42,"Top ds_top__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+44,"Top ds_top__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+46,"Top ds_top__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+48,"Top ds_top__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+50,"Top ds_top__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+52,"Top ds_top__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+54,"Top ds_top__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+56,"Top ds_top__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+58,"Top ds_top__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+60,"Top ds_top__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+62,"Top ds_top__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+64,"Top ds_top__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+66,"Top ds_top__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+68,"Top ds_top__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+70,"Top ds_top__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+72,"Top ds_top__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+74,"Top ds_top__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+76,"Top ds_top__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+78,"Top ds_top__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+80,"Top ds_top__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+82,"Top ds_top__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+84,"Top ds_top__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+86,"Top ds_top__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+88,"Top ds_top__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+90,"Top ds_top__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+92,"Top ds_top__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+94,"Top ds_top__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+96,"Top ds_top__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+98,"Top ds_top__WIRE_0_31", false,-1, 63,0);
        tracep->declBit(c+10,"Top ds_top_br_taken_0", false,-1);
        tracep->declQuad(c+11,"Top ds_top_br_target_0", false,-1, 63,0);
        tracep->declBit(c+290,"Top es_top_clock", false,-1);
        tracep->declBit(c+291,"Top es_top_reset", false,-1);
        tracep->declBit(c+3,"Top es_top_io_ds_ready", false,-1);
        tracep->declBit(c+16,"Top es_top_io_ds_valid", false,-1);
        tracep->declQuad(c+17,"Top es_top_io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+19,"Top es_top_io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+20,"Top es_top_io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top es_top_io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top es_top_io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top es_top_io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+24,"Top es_top_io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+25,"Top es_top_io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+26,"Top es_top_io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+27,"Top es_top_io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+29,"Top es_top_io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+100,"Top es_top_io_ms_ready", false,-1);
        tracep->declBit(c+4,"Top es_top_io_ms_valid", false,-1);
        tracep->declQuad(c+101,"Top es_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+103,"Top es_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+104,"Top es_top_io_ms_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+105,"Top es_top_io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+107,"Top es_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+301,"Top es_top_io_dmem_req_ready", false,-1);
        tracep->declBit(c+108,"Top es_top_io_dmem_req_valid", false,-1);
        tracep->declQuad(c+105,"Top es_top_io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+109,"Top es_top_io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+104,"Top es_top_io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+111,"Top es_top_io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+290,"Top ms_top_clock", false,-1);
        tracep->declBit(c+291,"Top ms_top_reset", false,-1);
        tracep->declBit(c+100,"Top ms_top_io_es_ready", false,-1);
        tracep->declBit(c+4,"Top ms_top_io_es_valid", false,-1);
        tracep->declQuad(c+101,"Top ms_top_io_es_bits_PC", false,-1, 63,0);
        tracep->declBit(c+103,"Top ms_top_io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+104,"Top ms_top_io_es_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+105,"Top ms_top_io_es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+107,"Top ms_top_io_es_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top ms_top_io_ws_valid", false,-1);
        tracep->declQuad(c+113,"Top ms_top_io_ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+115,"Top ms_top_io_ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+116,"Top ms_top_io_ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top ms_top_io_ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+309,"Top ms_top_io_dmem_resp_valid", false,-1);
        tracep->declBit(c+290,"Top ws_top_clock", false,-1);
        tracep->declBit(c+291,"Top ws_top_reset", false,-1);
        tracep->declBit(c+381,"Top ws_top_io_ms_ready", false,-1);
        tracep->declBit(c+112,"Top ws_top_io_ms_valid", false,-1);
        tracep->declQuad(c+113,"Top ws_top_io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+115,"Top ws_top_io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+116,"Top ws_top_io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top ws_top_io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+31,"Top ws_top_io_rf_rf_we", false,-1);
        tracep->declBus(c+32,"Top ws_top_io_rf_rf_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ws_top_io_rf_rf_data", false,-1, 63,0);
        tracep->declQuad(c+119,"Top ws_top_from_ms_r_PC", false,-1, 63,0);
        tracep->declBit(c+290,"Top pre_top clock", false,-1);
        tracep->declBit(c+291,"Top pre_top reset", false,-1);
        tracep->declBit(c+1,"Top pre_top io_fs_ready", false,-1);
        tracep->declBit(c+6,"Top pre_top io_fs_valid", false,-1);
        tracep->declQuad(c+7,"Top pre_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBit(c+292,"Top pre_top io_imem_req_ready", false,-1);
        tracep->declBit(c+9,"Top pre_top io_imem_req_valid", false,-1);
        tracep->declQuad(c+7,"Top pre_top io_imem_req_bits_addr", false,-1, 63,0);
        tracep->declBit(c+10,"Top pre_top br_taken_0", false,-1);
        tracep->declQuad(c+11,"Top pre_top br_target_0", false,-1, 63,0);
        tracep->declBit(c+6,"Top pre_top pre_ready_go", false,-1);
        tracep->declQuad(c+121,"Top pre_top pre_pc", false,-1, 63,0);
        tracep->declBit(c+123,"Top pre_top buf_valid", false,-1);
        tracep->declQuad(c+124,"Top pre_top buf_npc", false,-1, 63,0);
        tracep->declQuad(c+126,"Top pre_top seq_pc", false,-1, 63,0);
        tracep->declBit(c+9,"Top pre_top imem_req_r", false,-1);
        tracep->declBit(c+290,"Top fs_top clock", false,-1);
        tracep->declBit(c+291,"Top fs_top reset", false,-1);
        tracep->declBit(c+1,"Top fs_top io_pres_ready", false,-1);
        tracep->declBit(c+6,"Top fs_top io_pres_valid", false,-1);
        tracep->declQuad(c+7,"Top fs_top io_pres_bits_PC", false,-1, 63,0);
        tracep->declBit(c+2,"Top fs_top io_ds_ready", false,-1);
        tracep->declBit(c+13,"Top fs_top io_ds_valid", false,-1);
        tracep->declQuad(c+14,"Top fs_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+300,"Top fs_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBit(c+299,"Top fs_top io_imem_resp_valid", false,-1);
        tracep->declBus(c+300,"Top fs_top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declQuad(c+14,"Top fs_top from_pre_r_PC", false,-1, 63,0);
        tracep->declBit(c+128,"Top fs_top fs_ready_go", false,-1);
        tracep->declBit(c+129,"Top fs_top fs_valid", false,-1);
        tracep->declBit(c+290,"Top ds_top clock", false,-1);
        tracep->declBit(c+291,"Top ds_top reset", false,-1);
        tracep->declBit(c+2,"Top ds_top io_fs_ready", false,-1);
        tracep->declBit(c+13,"Top ds_top io_fs_valid", false,-1);
        tracep->declQuad(c+14,"Top ds_top io_fs_bits_PC", false,-1, 63,0);
        tracep->declBus(c+300,"Top ds_top io_fs_bits_inst", false,-1, 31,0);
        tracep->declBit(c+3,"Top ds_top io_es_ready", false,-1);
        tracep->declBit(c+16,"Top ds_top io_es_valid", false,-1);
        tracep->declQuad(c+17,"Top ds_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBus(c+19,"Top ds_top io_es_bits_inst", false,-1, 31,0);
        tracep->declBus(c+20,"Top ds_top io_es_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top ds_top io_es_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top ds_top io_es_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top ds_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+24,"Top ds_top io_es_bits_decode_mem_en", false,-1);
        tracep->declBit(c+25,"Top ds_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+26,"Top ds_top io_es_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+27,"Top ds_top io_es_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+29,"Top ds_top io_es_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+31,"Top ds_top io_wb_rf_we", false,-1);
        tracep->declBus(c+32,"Top ds_top io_wb_rf_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ds_top io_wb_rf_data", false,-1, 63,0);
        tracep->declBit(c+35,"Top ds_top is_trap", false,-1);
        tracep->declBit(c+10,"Top ds_top br_taken_0", false,-1);
        tracep->declQuad(c+11,"Top ds_top br_target_0", false,-1, 63,0);
        tracep->declBus(c+19,"Top ds_top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+130,"Top ds_top idu_io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+20,"Top ds_top idu_io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top ds_top idu_io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top ds_top idu_io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top ds_top idu_io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+24,"Top ds_top idu_io_ctrl_mem_en", false,-1);
        tracep->declBit(c+25,"Top ds_top idu_io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+26,"Top ds_top idu_io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+35,"Top ds_top idu_is_trap_0", false,-1);
        tracep->declBit(c+290,"Top ds_top rf_clock", false,-1);
        tracep->declBus(c+131,"Top ds_top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"Top ds_top rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+132,"Top ds_top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"Top ds_top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+32,"Top ds_top rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ds_top rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+31,"Top ds_top rf_io_wen", false,-1);
        tracep->declQuad(c+36,"Top ds_top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+38,"Top ds_top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+40,"Top ds_top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+42,"Top ds_top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+44,"Top ds_top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+46,"Top ds_top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+48,"Top ds_top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+50,"Top ds_top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+52,"Top ds_top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+54,"Top ds_top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+56,"Top ds_top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+58,"Top ds_top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+60,"Top ds_top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+62,"Top ds_top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+64,"Top ds_top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+66,"Top ds_top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+68,"Top ds_top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+70,"Top ds_top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+72,"Top ds_top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+74,"Top ds_top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+76,"Top ds_top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+78,"Top ds_top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+80,"Top ds_top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+82,"Top ds_top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+84,"Top ds_top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+86,"Top ds_top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+88,"Top ds_top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+90,"Top ds_top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+92,"Top ds_top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+94,"Top ds_top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+96,"Top ds_top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+98,"Top ds_top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declQuad(c+17,"Top ds_top from_fs_r_PC", false,-1, 63,0);
        tracep->declBus(c+19,"Top ds_top from_fs_r_inst", false,-1, 31,0);
        tracep->declBit(c+16,"Top ds_top ds_valid", false,-1);
        tracep->declBus(c+133,"Top ds_top imm_i", false,-1, 11,0);
        tracep->declBit(c+134,"Top ds_top right_right", false,-1);
        tracep->declBit(c+135,"Top ds_top right_left", false,-1);
        tracep->declBus(c+136,"Top ds_top left_right", false,-1, 5,0);
        tracep->declBus(c+137,"Top ds_top left_left", false,-1, 3,0);
        tracep->declBus(c+138,"Top ds_top imm_b", false,-1, 11,0);
        tracep->declBus(c+139,"Top ds_top right_left_1", false,-1, 7,0);
        tracep->declBit(c+140,"Top ds_top left_right_1", false,-1);
        tracep->declBus(c+141,"Top ds_top left_left_1", false,-1, 9,0);
        tracep->declBus(c+142,"Top ds_top imm_j", false,-1, 19,0);
        tracep->declQuad(c+143,"Top ds_top right_2", false,-1, 51,0);
        tracep->declQuad(c+145,"Top ds_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+147,"Top ds_top right_right_2", false,-1, 52,0);
        tracep->declArray(c+149,"Top ds_top imm_b_sext", false,-1, 65,0);
        tracep->declQuad(c+152,"Top ds_top right_right_3", false,-1, 52,0);
        tracep->declArray(c+154,"Top ds_top imm_j_sext", false,-1, 73,0);
        tracep->declArray(c+157,"Top ds_top branch_target", false,-1, 65,0);
        tracep->declArray(c+160,"Top ds_top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+163,"Top ds_top jr_target", false,-1, 63,0);
        tracep->declBit(c+165,"Top ds_top rf_eq", false,-1);
        tracep->declBit(c+166,"Top ds_top rf_lt", false,-1);
        tracep->declBit(c+167,"Top ds_top rf_ltu", false,-1);
        tracep->declBit(c+10,"Top ds_top br_taken", false,-1);
        tracep->declQuad(c+11,"Top ds_top br_target", false,-1, 63,0);
        tracep->declBus(c+19,"Top ds_top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+130,"Top ds_top idu io_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+20,"Top ds_top idu io_ctrl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top ds_top idu io_ctrl_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top ds_top idu io_ctrl_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top ds_top idu io_ctrl_rf_wen", false,-1);
        tracep->declBit(c+24,"Top ds_top idu io_ctrl_mem_en", false,-1);
        tracep->declBit(c+25,"Top ds_top idu io_ctrl_mem_wr", false,-1);
        tracep->declBus(c+26,"Top ds_top idu io_ctrl_mem_msk", false,-1, 2,0);
        tracep->declBit(c+35,"Top ds_top idu is_trap_0", false,-1);
        tracep->declBit(c+35,"Top ds_top idu is_trap", false,-1);
        tracep->declBit(c+290,"Top ds_top rf clock", false,-1);
        tracep->declBus(c+131,"Top ds_top rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"Top ds_top rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+132,"Top ds_top rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"Top ds_top rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+32,"Top ds_top rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ds_top rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+31,"Top ds_top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+168+i*2,"Top ds_top rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+232,"Top ds_top rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+131,"Top ds_top rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+234,"Top ds_top rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+132,"Top ds_top rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+36,"Top ds_top rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+382,"Top ds_top rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+38,"Top ds_top rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+383,"Top ds_top rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+40,"Top ds_top rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+384,"Top ds_top rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+42,"Top ds_top rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+385,"Top ds_top rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+44,"Top ds_top rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+386,"Top ds_top rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+46,"Top ds_top rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+387,"Top ds_top rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+48,"Top ds_top rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+388,"Top ds_top rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+50,"Top ds_top rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+389,"Top ds_top rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+52,"Top ds_top rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+390,"Top ds_top rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+54,"Top ds_top rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+391,"Top ds_top rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+56,"Top ds_top rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+392,"Top ds_top rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+58,"Top ds_top rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+393,"Top ds_top rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+60,"Top ds_top rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+394,"Top ds_top rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+62,"Top ds_top rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+395,"Top ds_top rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+64,"Top ds_top rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+396,"Top ds_top rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+66,"Top ds_top rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+397,"Top ds_top rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"Top ds_top rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+398,"Top ds_top rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+70,"Top ds_top rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+399,"Top ds_top rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+72,"Top ds_top rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+400,"Top ds_top rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+74,"Top ds_top rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+401,"Top ds_top rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+76,"Top ds_top rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+402,"Top ds_top rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+78,"Top ds_top rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+403,"Top ds_top rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+80,"Top ds_top rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+404,"Top ds_top rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+82,"Top ds_top rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+405,"Top ds_top rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+84,"Top ds_top rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+406,"Top ds_top rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+86,"Top ds_top rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+407,"Top ds_top rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+88,"Top ds_top rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+408,"Top ds_top rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+90,"Top ds_top rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+409,"Top ds_top rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+92,"Top ds_top rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+410,"Top ds_top rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+94,"Top ds_top rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+411,"Top ds_top rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+96,"Top ds_top rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+412,"Top ds_top rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+98,"Top ds_top rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+413,"Top ds_top rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ds_top rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+32,"Top ds_top rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+381,"Top ds_top rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+31,"Top ds_top rf regfile_MPORT_en", false,-1);
        tracep->declBit(c+290,"Top es_top clock", false,-1);
        tracep->declBit(c+291,"Top es_top reset", false,-1);
        tracep->declBit(c+3,"Top es_top io_ds_ready", false,-1);
        tracep->declBit(c+16,"Top es_top io_ds_valid", false,-1);
        tracep->declQuad(c+17,"Top es_top io_ds_bits_PC", false,-1, 63,0);
        tracep->declBus(c+19,"Top es_top io_ds_bits_inst", false,-1, 31,0);
        tracep->declBus(c+20,"Top es_top io_ds_bits_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+21,"Top es_top io_ds_bits_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+22,"Top es_top io_ds_bits_decode_alu_op", false,-1, 5,0);
        tracep->declBit(c+23,"Top es_top io_ds_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+24,"Top es_top io_ds_bits_decode_mem_en", false,-1);
        tracep->declBit(c+25,"Top es_top io_ds_bits_decode_mem_wr", false,-1);
        tracep->declBus(c+26,"Top es_top io_ds_bits_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+27,"Top es_top io_ds_bits_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+29,"Top es_top io_ds_bits_rs2_data", false,-1, 63,0);
        tracep->declBit(c+100,"Top es_top io_ms_ready", false,-1);
        tracep->declBit(c+4,"Top es_top io_ms_valid", false,-1);
        tracep->declQuad(c+101,"Top es_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+103,"Top es_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+104,"Top es_top io_ms_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+105,"Top es_top io_ms_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+107,"Top es_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+301,"Top es_top io_dmem_req_ready", false,-1);
        tracep->declBit(c+108,"Top es_top io_dmem_req_valid", false,-1);
        tracep->declQuad(c+105,"Top es_top io_dmem_req_bits_addr", false,-1, 63,0);
        tracep->declQuad(c+109,"Top es_top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+104,"Top es_top io_dmem_req_bits_wr", false,-1);
        tracep->declBus(c+111,"Top es_top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBus(c+236,"Top es_top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+237,"Top es_top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+239,"Top es_top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+105,"Top es_top alu_io_out", false,-1, 63,0);
        tracep->declQuad(c+101,"Top es_top from_ds_r_PC", false,-1, 63,0);
        tracep->declBus(c+241,"Top es_top from_ds_r_inst", false,-1, 31,0);
        tracep->declBus(c+242,"Top es_top from_ds_r_decode_op1_sel", false,-1, 1,0);
        tracep->declBus(c+243,"Top es_top from_ds_r_decode_op2_sel", false,-1, 1,0);
        tracep->declBus(c+236,"Top es_top from_ds_r_decode_alu_op", false,-1, 5,0);
        tracep->declBit(c+103,"Top es_top from_ds_r_decode_rf_wen", false,-1);
        tracep->declBit(c+244,"Top es_top from_ds_r_decode_mem_en", false,-1);
        tracep->declBit(c+104,"Top es_top from_ds_r_decode_mem_wr", false,-1);
        tracep->declBus(c+111,"Top es_top from_ds_r_decode_mem_msk", false,-1, 2,0);
        tracep->declQuad(c+245,"Top es_top from_ds_r_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+109,"Top es_top from_ds_r_rs2_data", false,-1, 63,0);
        tracep->declBit(c+5,"Top es_top es_ready_go", false,-1);
        tracep->declBit(c+247,"Top es_top es_valid", false,-1);
        tracep->declBus(c+248,"Top es_top imm_i", false,-1, 11,0);
        tracep->declBus(c+249,"Top es_top right", false,-1, 6,0);
        tracep->declBus(c+107,"Top es_top left", false,-1, 4,0);
        tracep->declBus(c+250,"Top es_top imm_s", false,-1, 11,0);
        tracep->declBus(c+251,"Top es_top imm_u", false,-1, 19,0);
        tracep->declBus(c+252,"Top es_top left_3", false,-1, 4,0);
        tracep->declBus(c+253,"Top es_top imm_z", false,-1, 31,0);
        tracep->declQuad(c+254,"Top es_top right_4", false,-1, 51,0);
        tracep->declQuad(c+256,"Top es_top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+258,"Top es_top right_5", false,-1, 51,0);
        tracep->declQuad(c+260,"Top es_top imm_s_sext", false,-1, 63,0);
        tracep->declBus(c+262,"Top es_top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+263,"Top es_top imm_u_sext", false,-1, 63,0);
        tracep->declBit(c+265,"Top es_top dmem_req_r", false,-1);
        tracep->declBus(c+236,"Top es_top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+237,"Top es_top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+239,"Top es_top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+105,"Top es_top alu io_out", false,-1, 63,0);
        tracep->declArray(c+266,"Top es_top alu add_result", false,-1, 64,0);
        tracep->declQuad(c+269,"Top es_top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+271,"Top es_top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+273,"Top es_top alu and_result", false,-1, 63,0);
        tracep->declBit(c+275,"Top es_top alu sltu_result", false,-1);
        tracep->declBit(c+276,"Top es_top alu slt_result", false,-1);
        tracep->declBus(c+277,"Top es_top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+278,"Top es_top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+280,"Top es_top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+282,"Top es_top alu srl_result", false,-1, 63,0);
        tracep->declQuad(c+284,"Top es_top alu io_out_res", false,-1, 63,0);
        tracep->declBit(c+290,"Top ms_top clock", false,-1);
        tracep->declBit(c+291,"Top ms_top reset", false,-1);
        tracep->declBit(c+100,"Top ms_top io_es_ready", false,-1);
        tracep->declBit(c+4,"Top ms_top io_es_valid", false,-1);
        tracep->declQuad(c+101,"Top ms_top io_es_bits_PC", false,-1, 63,0);
        tracep->declBit(c+103,"Top ms_top io_es_bits_decode_rf_wen", false,-1);
        tracep->declBit(c+104,"Top ms_top io_es_bits_decode_mem_wr", false,-1);
        tracep->declQuad(c+105,"Top ms_top io_es_bits_alu_result", false,-1, 63,0);
        tracep->declBus(c+107,"Top ms_top io_es_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+112,"Top ms_top io_ws_valid", false,-1);
        tracep->declQuad(c+113,"Top ms_top io_ws_bits_PC", false,-1, 63,0);
        tracep->declBit(c+115,"Top ms_top io_ws_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+116,"Top ms_top io_ws_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top ms_top io_ws_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+309,"Top ms_top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+113,"Top ms_top from_es_r_PC", false,-1, 63,0);
        tracep->declBit(c+115,"Top ms_top from_es_r_decode_rf_wen", false,-1);
        tracep->declBit(c+286,"Top ms_top from_es_r_decode_mem_wr", false,-1);
        tracep->declQuad(c+116,"Top ms_top from_es_r_alu_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top ms_top from_es_r_rd_addr", false,-1, 4,0);
        tracep->declBit(c+287,"Top ms_top ms_valid", false,-1);
        tracep->declBus(c+288,"Top ms_top unfinished_store", false,-1, 3,0);
        tracep->declBit(c+289,"Top ms_top ms_ready_go", false,-1);
        tracep->declBit(c+290,"Top ws_top clock", false,-1);
        tracep->declBit(c+291,"Top ws_top reset", false,-1);
        tracep->declBit(c+381,"Top ws_top io_ms_ready", false,-1);
        tracep->declBit(c+112,"Top ws_top io_ms_valid", false,-1);
        tracep->declQuad(c+113,"Top ws_top io_ms_bits_PC", false,-1, 63,0);
        tracep->declBit(c+115,"Top ws_top io_ms_bits_decode_rf_wen", false,-1);
        tracep->declQuad(c+116,"Top ws_top io_ms_bits_final_result", false,-1, 63,0);
        tracep->declBus(c+118,"Top ws_top io_ms_bits_rd_addr", false,-1, 4,0);
        tracep->declBit(c+31,"Top ws_top io_rf_rf_we", false,-1);
        tracep->declBus(c+32,"Top ws_top io_rf_rf_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"Top ws_top io_rf_rf_data", false,-1, 63,0);
        tracep->declQuad(c+119,"Top ws_top from_ms_r_PC", false,-1, 63,0);
        tracep->declQuad(c+119,"Top ws_top from_ms_r__PC", false,-1, 63,0);
        tracep->declBit(c+31,"Top ws_top from_ms_r__decode_rf_wen", false,-1);
        tracep->declQuad(c+33,"Top ws_top from_ms_r__final_result", false,-1, 63,0);
        tracep->declBus(c+32,"Top ws_top from_ms_r__rd_addr", false,-1, 4,0);
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
        tracep->fullBit(oldp+1,(vlTOPp->Top__DOT__fs_top_io_pres_ready));
        tracep->fullBit(oldp+2,(vlTOPp->Top__DOT__ds_top_io_fs_ready));
        tracep->fullBit(oldp+3,(vlTOPp->Top__DOT__es_top_io_ds_ready));
        tracep->fullBit(oldp+4,(vlTOPp->Top__DOT__es_top_io_ms_valid));
        tracep->fullBit(oldp+5,(vlTOPp->Top__DOT__es_top__DOT__es_ready_go));
        tracep->fullBit(oldp+6,(vlTOPp->Top__DOT__pre_top__DOT__pre_ready_go));
        tracep->fullQData(oldp+7,(vlTOPp->Top__DOT__pre_top_io_fs_bits_PC),64);
        tracep->fullBit(oldp+9,(vlTOPp->Top__DOT__pre_top__DOT__imem_req_r));
        tracep->fullBit(oldp+10,(vlTOPp->Top__DOT__ds_top__DOT__br_taken));
        tracep->fullQData(oldp+11,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
        tracep->fullBit(oldp+13,(vlTOPp->Top__DOT__fs_top_io_ds_valid));
        tracep->fullQData(oldp+14,(vlTOPp->Top__DOT__fs_top__DOT__from_pre_r_PC),64);
        tracep->fullBit(oldp+16,(vlTOPp->Top__DOT__ds_top__DOT__ds_valid));
        tracep->fullQData(oldp+17,(vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_PC),64);
        tracep->fullIData(oldp+19,(vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst),32);
        tracep->fullCData(oldp+20,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
        tracep->fullCData(oldp+21,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
        tracep->fullCData(oldp+22,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
        tracep->fullBit(oldp+23,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
        tracep->fullBit(oldp+24,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
        tracep->fullBit(oldp+25,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
        tracep->fullCData(oldp+26,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
        tracep->fullQData(oldp+27,(vlTOPp->Top__DOT__ds_top__DOT__rf_io_rs1_data),64);
        tracep->fullQData(oldp+29,(vlTOPp->Top__DOT__ds_top__DOT__rf_io_rs2_data),64);
        tracep->fullBit(oldp+31,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
        tracep->fullCData(oldp+32,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
        tracep->fullQData(oldp+33,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
        tracep->fullBit(oldp+35,((0x6bU == (0x707fU 
                                            & vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst))));
        tracep->fullQData(oldp+36,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+38,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+40,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+42,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+44,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+46,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+48,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+50,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+52,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+54,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+56,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+58,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+60,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+62,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+64,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+66,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+68,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+70,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+72,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+74,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+76,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+78,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+80,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+82,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+84,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+86,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+88,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+90,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+92,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+94,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+96,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+98,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullBit(oldp+100,(vlTOPp->Top__DOT__ms_top_io_es_ready));
        tracep->fullQData(oldp+101,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_PC),64);
        tracep->fullBit(oldp+103,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
        tracep->fullBit(oldp+104,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
        tracep->fullQData(oldp+105,(vlTOPp->Top__DOT__es_top__DOT__alu_io_out),64);
        tracep->fullCData(oldp+107,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 7U))),5);
        tracep->fullBit(oldp+108,(vlTOPp->Top__DOT__es_top_io_dmem_req_valid));
        tracep->fullQData(oldp+109,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_rs2_data),64);
        tracep->fullCData(oldp+111,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
        tracep->fullBit(oldp+112,(vlTOPp->Top__DOT__ms_top_io_ws_valid));
        tracep->fullQData(oldp+113,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_PC),64);
        tracep->fullBit(oldp+115,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
        tracep->fullQData(oldp+116,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_alu_result),64);
        tracep->fullCData(oldp+118,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_rd_addr),5);
        tracep->fullQData(oldp+119,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05FPC),64);
        tracep->fullQData(oldp+121,(vlTOPp->Top__DOT__pre_top__DOT__pre_pc),64);
        tracep->fullBit(oldp+123,(vlTOPp->Top__DOT__pre_top__DOT__buf_valid));
        tracep->fullQData(oldp+124,(vlTOPp->Top__DOT__pre_top__DOT__buf_npc),64);
        tracep->fullQData(oldp+126,((4ULL + vlTOPp->Top__DOT__pre_top__DOT__pre_pc)),64);
        tracep->fullBit(oldp+128,(vlTOPp->Top__DOT__fs_top__DOT__fs_ready_go));
        tracep->fullBit(oldp+129,(vlTOPp->Top__DOT__fs_top__DOT__fs_valid));
        tracep->fullCData(oldp+130,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
        tracep->fullCData(oldp+131,((0x1fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+132,((0x1fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x14U))),5);
        tracep->fullSData(oldp+133,((0xfffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+134,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x1fU))));
        tracep->fullBit(oldp+135,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 7U))));
        tracep->fullCData(oldp+136,((0x3fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+137,((0xfU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                             >> 8U))),4);
        tracep->fullSData(oldp+138,(vlTOPp->Top__DOT__ds_top__DOT__imm_b),12);
        tracep->fullCData(oldp+139,((0xffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+140,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+141,((0x3ffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+142,(vlTOPp->Top__DOT__ds_top__DOT__imm_j),20);
        tracep->fullQData(oldp+143,(((0x80000000U & vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+145,(vlTOPp->Top__DOT__ds_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+147,(((0x800U & (IData)(vlTOPp->Top__DOT__ds_top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+149,(vlTOPp->Top__DOT__ds_top__DOT__imm_b_sext),66);
        tracep->fullQData(oldp+152,(((0x80000U & vlTOPp->Top__DOT__ds_top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+154,(vlTOPp->Top__DOT__ds_top__DOT__imm_j_sext),74);
        tracep->fullWData(oldp+157,(vlTOPp->Top__DOT__ds_top__DOT__branch_target),66);
        tracep->fullWData(oldp+160,(vlTOPp->Top__DOT__ds_top__DOT__jmp_target),74);
        tracep->fullQData(oldp+163,(vlTOPp->Top__DOT__ds_top__DOT__jr_target),64);
        tracep->fullBit(oldp+165,(vlTOPp->Top__DOT__ds_top__DOT__rf_eq));
        tracep->fullBit(oldp+166,(vlTOPp->Top__DOT__ds_top__DOT__rf_lt));
        tracep->fullBit(oldp+167,(vlTOPp->Top__DOT__ds_top__DOT__rf_ltu));
        tracep->fullQData(oldp+168,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+170,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+172,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+174,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+176,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+178,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+180,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+182,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+184,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+186,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+188,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+190,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+192,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+194,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+196,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+198,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+200,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+202,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+204,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+206,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+208,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+210,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+212,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+214,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+216,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+218,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+220,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+222,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+224,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+226,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+228,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+230,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+232,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+234,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullCData(oldp+236,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
        tracep->fullQData(oldp+237,(vlTOPp->Top__DOT__es_top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+239,(vlTOPp->Top__DOT__es_top__DOT__alu_io_in2),64);
        tracep->fullIData(oldp+241,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst),32);
        tracep->fullCData(oldp+242,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
        tracep->fullCData(oldp+243,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
        tracep->fullBit(oldp+244,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_en));
        tracep->fullQData(oldp+245,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_rs1_data),64);
        tracep->fullBit(oldp+247,(vlTOPp->Top__DOT__es_top__DOT__es_valid));
        tracep->fullSData(oldp+248,((0xfffU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                               >> 0x14U))),12);
        tracep->fullCData(oldp+249,((0x7fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0x19U))),7);
        tracep->fullSData(oldp+250,(vlTOPp->Top__DOT__es_top__DOT__imm_s),12);
        tracep->fullIData(oldp+251,((0xfffffU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+252,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),5);
        tracep->fullIData(oldp+253,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+254,(((0x80000000U & vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+256,(vlTOPp->Top__DOT__es_top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+258,(((0x800U & (IData)(vlTOPp->Top__DOT__es_top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+260,(vlTOPp->Top__DOT__es_top__DOT__imm_s_sext),64);
        tracep->fullIData(oldp+262,(((0x800000U & vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+263,(vlTOPp->Top__DOT__es_top__DOT__imm_u_sext),64);
        tracep->fullBit(oldp+265,(vlTOPp->Top__DOT__es_top__DOT__dmem_req_r));
        tracep->fullWData(oldp+266,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result),65);
        tracep->fullQData(oldp+269,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+271,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+273,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+275,((1U & (~ vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+276,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+277,((0x3fU & (IData)(vlTOPp->Top__DOT__es_top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+278,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__es_top__DOT__alu__DOT___T_7[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__es_top__DOT__alu__DOT___T_7[0U])))),64);
        tracep->fullQData(oldp+280,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+282,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__srl_result),64);
        tracep->fullQData(oldp+284,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullBit(oldp+286,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
        tracep->fullBit(oldp+287,(vlTOPp->Top__DOT__ms_top__DOT__ms_valid));
        tracep->fullCData(oldp+288,(vlTOPp->Top__DOT__ms_top__DOT__unfinished_store),4);
        tracep->fullBit(oldp+289,((0U == (IData)(vlTOPp->Top__DOT__ms_top__DOT__unfinished_store))));
        tracep->fullBit(oldp+290,(vlTOPp->clock));
        tracep->fullBit(oldp+291,(vlTOPp->reset));
        tracep->fullBit(oldp+292,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+293,(vlTOPp->io_imem_req_valid));
        tracep->fullQData(oldp+294,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->fullIData(oldp+296,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+297,(vlTOPp->io_imem_req_bits_wr));
        tracep->fullCData(oldp+298,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+299,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+300,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+301,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+302,(vlTOPp->io_dmem_req_valid));
        tracep->fullQData(oldp+303,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->fullQData(oldp+305,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+307,(vlTOPp->io_dmem_req_bits_wr));
        tracep->fullCData(oldp+308,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+309,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+310,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullQData(oldp+312,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+314,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+316,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+318,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+320,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+322,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+324,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+326,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+328,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+330,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+332,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+334,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+336,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+338,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+340,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+342,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+344,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+346,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+348,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+350,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+352,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+354,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+356,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+358,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+360,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+362,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+364,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+366,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+368,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+370,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+372,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+374,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+376,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+378,(vlTOPp->io_debug_stall));
        tracep->fullBit(oldp+379,(vlTOPp->io_debug_trap));
        tracep->fullIData(oldp+380,(vlTOPp->io_debug_inst),32);
        tracep->fullBit(oldp+381,(1U));
        tracep->fullCData(oldp+382,(0U),5);
        tracep->fullCData(oldp+383,(1U),5);
        tracep->fullCData(oldp+384,(2U),5);
        tracep->fullCData(oldp+385,(3U),5);
        tracep->fullCData(oldp+386,(4U),5);
        tracep->fullCData(oldp+387,(5U),5);
        tracep->fullCData(oldp+388,(6U),5);
        tracep->fullCData(oldp+389,(7U),5);
        tracep->fullCData(oldp+390,(8U),5);
        tracep->fullCData(oldp+391,(9U),5);
        tracep->fullCData(oldp+392,(0xaU),5);
        tracep->fullCData(oldp+393,(0xbU),5);
        tracep->fullCData(oldp+394,(0xcU),5);
        tracep->fullCData(oldp+395,(0xdU),5);
        tracep->fullCData(oldp+396,(0xeU),5);
        tracep->fullCData(oldp+397,(0xfU),5);
        tracep->fullCData(oldp+398,(0x10U),5);
        tracep->fullCData(oldp+399,(0x11U),5);
        tracep->fullCData(oldp+400,(0x12U),5);
        tracep->fullCData(oldp+401,(0x13U),5);
        tracep->fullCData(oldp+402,(0x14U),5);
        tracep->fullCData(oldp+403,(0x15U),5);
        tracep->fullCData(oldp+404,(0x16U),5);
        tracep->fullCData(oldp+405,(0x17U),5);
        tracep->fullCData(oldp+406,(0x18U),5);
        tracep->fullCData(oldp+407,(0x19U),5);
        tracep->fullCData(oldp+408,(0x1aU),5);
        tracep->fullCData(oldp+409,(0x1bU),5);
        tracep->fullCData(oldp+410,(0x1cU),5);
        tracep->fullCData(oldp+411,(0x1dU),5);
        tracep->fullCData(oldp+412,(0x1eU),5);
        tracep->fullCData(oldp+413,(0x1fU),5);
    }
}
