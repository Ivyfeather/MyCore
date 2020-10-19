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
        tracep->declBit(c+227,"clock", false,-1);
        tracep->declBit(c+228,"reset", false,-1);
        tracep->declBit(c+229,"io_imem_req_ready", false,-1);
        tracep->declBit(c+230,"io_imem_req_valid", false,-1);
        tracep->declBus(c+231,"io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+232,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+233,"io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+234,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+235,"io_imem_resp_ready", false,-1);
        tracep->declBit(c+236,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+237,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+238,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+239,"io_dmem_req_valid", false,-1);
        tracep->declBus(c+240,"io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+241,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+243,"io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+244,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+245,"io_dmem_resp_ready", false,-1);
        tracep->declBit(c+246,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+247,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+249,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+251,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+253,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+255,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+257,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+259,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+261,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+263,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+265,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+267,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+269,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+271,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+273,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+275,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+277,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+279,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+281,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+283,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+285,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+287,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+289,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+291,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+293,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+295,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+297,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+299,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+301,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+303,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+305,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+307,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+309,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+311,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+313,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+315,"io_debug_stall", false,-1);
        tracep->declBit(c+316,"io_debug_trap", false,-1);
        tracep->declBit(c+227,"Top clock", false,-1);
        tracep->declBit(c+228,"Top reset", false,-1);
        tracep->declBit(c+229,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+230,"Top io_imem_req_valid", false,-1);
        tracep->declBus(c+231,"Top io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+232,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+233,"Top io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+234,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+235,"Top io_imem_resp_ready", false,-1);
        tracep->declBit(c+236,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+237,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+238,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+239,"Top io_dmem_req_valid", false,-1);
        tracep->declBus(c+240,"Top io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+241,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+243,"Top io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+244,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+245,"Top io_dmem_resp_ready", false,-1);
        tracep->declBit(c+246,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+247,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+249,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+251,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+253,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+255,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+257,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+259,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+261,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+263,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+265,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+267,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+269,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+271,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+273,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+275,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+277,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+279,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+281,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+283,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+285,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+287,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+289,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+291,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+293,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+295,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+297,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+299,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+301,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+303,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+305,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+307,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+309,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+311,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+313,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+315,"Top io_debug_stall", false,-1);
        tracep->declBit(c+316,"Top io_debug_trap", false,-1);
        tracep->declBus(c+1,"Top alu_io_opcode", false,-1, 5,0);
        tracep->declQuad(c+2,"Top alu_io_in1", false,-1, 63,0);
        tracep->declQuad(c+4,"Top alu_io_in2", false,-1, 63,0);
        tracep->declQuad(c+6,"Top alu_io_out", false,-1, 63,0);
        tracep->declBit(c+8,"Top alu_io_zero", false,-1);
        tracep->declBus(c+9,"Top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+10,"Top idu_io_br_type", false,-1, 3,0);
        tracep->declBus(c+11,"Top idu_io_op1_sel", false,-1, 1,0);
        tracep->declBus(c+12,"Top idu_io_op2_sel", false,-1, 1,0);
        tracep->declBus(c+1,"Top idu_io_alu_op", false,-1, 5,0);
        tracep->declBus(c+13,"Top idu_io_wb_sel", false,-1, 1,0);
        tracep->declBit(c+14,"Top idu_io_rf_wen", false,-1);
        tracep->declBit(c+15,"Top idu_io_mem_en", false,-1);
        tracep->declBit(c+16,"Top idu_io_mem_fcn", false,-1);
        tracep->declBus(c+17,"Top idu_io_mem_msk", false,-1, 2,0);
        tracep->declBit(c+18,"Top idu_is_trap_0", false,-1);
        tracep->declBit(c+227,"Top rf_clock", false,-1);
        tracep->declBus(c+19,"Top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+20,"Top rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+22,"Top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"Top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+25,"Top rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+317,"Top rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf_io_wen", false,-1);
        tracep->declQuad(c+26,"Top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+28,"Top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+30,"Top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+32,"Top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+34,"Top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+36,"Top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+38,"Top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+40,"Top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+42,"Top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+44,"Top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+46,"Top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+48,"Top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+50,"Top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+52,"Top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+54,"Top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+56,"Top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+58,"Top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+60,"Top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+62,"Top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+64,"Top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+66,"Top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+68,"Top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+70,"Top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+72,"Top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+74,"Top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+76,"Top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+78,"Top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+80,"Top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+82,"Top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+84,"Top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+86,"Top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+88,"Top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declQuad(c+90,"Top pc_reg", false,-1, 63,0);
        tracep->declBit(c+319,"Top stall", false,-1);
        tracep->declBit(c+92,"Top imem_req_r", false,-1);
        tracep->declBus(c+9,"Top inst", false,-1, 31,0);
        tracep->declBus(c+93,"Top imm_i", false,-1, 11,0);
        tracep->declBus(c+94,"Top right", false,-1, 6,0);
        tracep->declBus(c+25,"Top left", false,-1, 4,0);
        tracep->declBus(c+95,"Top imm_s", false,-1, 11,0);
        tracep->declBit(c+96,"Top right_right", false,-1);
        tracep->declBit(c+97,"Top right_left", false,-1);
        tracep->declBus(c+98,"Top left_right", false,-1, 5,0);
        tracep->declBus(c+99,"Top left_left", false,-1, 3,0);
        tracep->declBus(c+100,"Top imm_b", false,-1, 11,0);
        tracep->declBus(c+101,"Top imm_u", false,-1, 19,0);
        tracep->declBus(c+102,"Top right_left_1", false,-1, 7,0);
        tracep->declBit(c+103,"Top left_right_1", false,-1);
        tracep->declBus(c+104,"Top left_left_1", false,-1, 9,0);
        tracep->declBus(c+105,"Top imm_j", false,-1, 19,0);
        tracep->declBus(c+19,"Top left_3", false,-1, 4,0);
        tracep->declBus(c+106,"Top imm_z", false,-1, 31,0);
        tracep->declQuad(c+107,"Top right_4", false,-1, 51,0);
        tracep->declQuad(c+109,"Top imm_i_sext", false,-1, 63,0);
        tracep->declQuad(c+111,"Top right_5", false,-1, 51,0);
        tracep->declQuad(c+113,"Top imm_s_sext", false,-1, 63,0);
        tracep->declQuad(c+115,"Top right_right_2", false,-1, 52,0);
        tracep->declArray(c+117,"Top imm_b_sext", false,-1, 65,0);
        tracep->declBus(c+120,"Top right_right_3", false,-1, 31,0);
        tracep->declQuad(c+121,"Top imm_u_sext", false,-1, 63,0);
        tracep->declQuad(c+123,"Top right_right_4", false,-1, 52,0);
        tracep->declArray(c+125,"Top imm_j_sext", false,-1, 73,0);
        tracep->declBus(c+128,"Top pc_4", false,-1, 31,0);
        tracep->declArray(c+129,"Top br_target", false,-1, 65,0);
        tracep->declArray(c+132,"Top jmp_target", false,-1, 73,0);
        tracep->declQuad(c+135,"Top jr_target", false,-1, 63,0);
        tracep->declBit(c+137,"Top br_taken", false,-1);
        tracep->declBus(c+138,"Top pc_next", false,-1, 31,0);
        tracep->declBus(c+1,"Top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+2,"Top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+4,"Top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+6,"Top alu io_out", false,-1, 63,0);
        tracep->declBit(c+8,"Top alu io_zero", false,-1);
        tracep->declArray(c+139,"Top alu add_result", false,-1, 64,0);
        tracep->declQuad(c+142,"Top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+144,"Top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+146,"Top alu and_result", false,-1, 63,0);
        tracep->declBit(c+148,"Top alu sltu_result", false,-1);
        tracep->declBit(c+149,"Top alu slt_result", false,-1);
        tracep->declBus(c+150,"Top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+151,"Top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+153,"Top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+155,"Top alu srl_result", false,-1, 63,0);
        tracep->declQuad(c+157,"Top alu io_out_res", false,-1, 63,0);
        tracep->declBus(c+9,"Top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+10,"Top idu io_br_type", false,-1, 3,0);
        tracep->declBus(c+11,"Top idu io_op1_sel", false,-1, 1,0);
        tracep->declBus(c+12,"Top idu io_op2_sel", false,-1, 1,0);
        tracep->declBus(c+1,"Top idu io_alu_op", false,-1, 5,0);
        tracep->declBus(c+13,"Top idu io_wb_sel", false,-1, 1,0);
        tracep->declBit(c+14,"Top idu io_rf_wen", false,-1);
        tracep->declBit(c+15,"Top idu io_mem_en", false,-1);
        tracep->declBit(c+16,"Top idu io_mem_fcn", false,-1);
        tracep->declBus(c+17,"Top idu io_mem_msk", false,-1, 2,0);
        tracep->declBit(c+18,"Top idu is_trap_0", false,-1);
        tracep->declBit(c+18,"Top idu is_trap", false,-1);
        tracep->declBit(c+227,"Top rf clock", false,-1);
        tracep->declBus(c+19,"Top rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+20,"Top rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+22,"Top rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"Top rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+25,"Top rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+317,"Top rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+159+i*2,"Top rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+223,"Top rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+19,"Top rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+225,"Top rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+22,"Top rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+26,"Top rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+320,"Top rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+28,"Top rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+321,"Top rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+30,"Top rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+322,"Top rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+32,"Top rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+323,"Top rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+34,"Top rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+324,"Top rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+36,"Top rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+325,"Top rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+38,"Top rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+326,"Top rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+40,"Top rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+327,"Top rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+42,"Top rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+328,"Top rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+44,"Top rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+329,"Top rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+46,"Top rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+330,"Top rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+48,"Top rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+331,"Top rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+50,"Top rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+332,"Top rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+52,"Top rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+333,"Top rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+54,"Top rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+334,"Top rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+56,"Top rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+335,"Top rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+58,"Top rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+336,"Top rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+60,"Top rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+337,"Top rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+62,"Top rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+338,"Top rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+64,"Top rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+339,"Top rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+66,"Top rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+340,"Top rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"Top rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+341,"Top rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+70,"Top rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+342,"Top rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+72,"Top rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+343,"Top rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+74,"Top rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+344,"Top rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+76,"Top rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+345,"Top rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+78,"Top rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+346,"Top rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+80,"Top rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+347,"Top rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+82,"Top rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+348,"Top rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+84,"Top rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+349,"Top rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+86,"Top rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+350,"Top rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+88,"Top rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+351,"Top rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+317,"Top rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+25,"Top rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+352,"Top rf regfile_MPORT_mask", false,-1);
        tracep->declBit(c+14,"Top rf regfile_MPORT_en", false,-1);
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
        tracep->fullCData(oldp+1,(vlTOPp->Top__DOT__idu_io_alu_op),6);
        tracep->fullQData(oldp+2,(vlTOPp->Top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+4,(vlTOPp->Top__DOT__alu_io_in2),64);
        tracep->fullQData(oldp+6,(vlTOPp->Top__DOT__alu_io_out),64);
        tracep->fullBit(oldp+8,((0ULL == vlTOPp->Top__DOT__alu_io_out)));
        tracep->fullIData(oldp+9,(vlTOPp->Top__DOT__inst),32);
        tracep->fullCData(oldp+10,(vlTOPp->Top__DOT__idu_io_br_type),4);
        tracep->fullCData(oldp+11,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
        tracep->fullCData(oldp+12,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
        tracep->fullCData(oldp+13,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
        tracep->fullBit(oldp+14,(vlTOPp->Top__DOT__idu_io_rf_wen));
        tracep->fullBit(oldp+15,(vlTOPp->Top__DOT__idu_io_mem_en));
        tracep->fullBit(oldp+16,(vlTOPp->Top__DOT__idu_io_mem_fcn));
        tracep->fullCData(oldp+17,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
        tracep->fullBit(oldp+18,((0x6bU == (0x707fU 
                                            & vlTOPp->Top__DOT__inst))));
        tracep->fullCData(oldp+19,((0x1fU & (vlTOPp->Top__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullQData(oldp+20,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
        tracep->fullCData(oldp+22,((0x1fU & (vlTOPp->Top__DOT__inst 
                                             >> 0x14U))),5);
        tracep->fullQData(oldp+23,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
        tracep->fullCData(oldp+25,((0x1fU & (vlTOPp->Top__DOT__inst 
                                             >> 7U))),5);
        tracep->fullQData(oldp+26,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+28,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+30,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+32,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+34,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+36,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+38,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+40,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+42,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+44,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+46,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+48,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+50,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+52,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+54,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+56,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+58,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+60,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+62,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+64,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+66,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+68,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+70,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+72,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+74,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+76,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+78,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+80,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+82,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+84,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+86,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+88,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+90,(vlTOPp->Top__DOT__pc_reg),64);
        tracep->fullBit(oldp+92,(vlTOPp->Top__DOT__imem_req_r));
        tracep->fullSData(oldp+93,((0xfffU & (vlTOPp->Top__DOT__inst 
                                              >> 0x14U))),12);
        tracep->fullCData(oldp+94,((0x7fU & (vlTOPp->Top__DOT__inst 
                                             >> 0x19U))),7);
        tracep->fullSData(oldp+95,(vlTOPp->Top__DOT__imm_s),12);
        tracep->fullBit(oldp+96,((1U & (vlTOPp->Top__DOT__inst 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+97,((1U & (vlTOPp->Top__DOT__inst 
                                        >> 7U))));
        tracep->fullCData(oldp+98,((0x3fU & (vlTOPp->Top__DOT__inst 
                                             >> 0x19U))),6);
        tracep->fullCData(oldp+99,((0xfU & (vlTOPp->Top__DOT__inst 
                                            >> 8U))),4);
        tracep->fullSData(oldp+100,(vlTOPp->Top__DOT__imm_b),12);
        tracep->fullIData(oldp+101,((0xfffffU & (vlTOPp->Top__DOT__inst 
                                                 >> 0xcU))),20);
        tracep->fullCData(oldp+102,((0xffU & (vlTOPp->Top__DOT__inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+103,((1U & (vlTOPp->Top__DOT__inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+104,((0x3ffU & (vlTOPp->Top__DOT__inst 
                                               >> 0x15U))),10);
        tracep->fullIData(oldp+105,(vlTOPp->Top__DOT__imm_j),20);
        tracep->fullIData(oldp+106,((0x1fU & (vlTOPp->Top__DOT__inst 
                                              >> 0xfU))),32);
        tracep->fullQData(oldp+107,(((0x80000000U & vlTOPp->Top__DOT__inst)
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+109,(vlTOPp->Top__DOT__imm_i_sext),64);
        tracep->fullQData(oldp+111,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_s))
                                      ? 0xfffffffffffffULL
                                      : 0ULL)),52);
        tracep->fullQData(oldp+113,(vlTOPp->Top__DOT__imm_s_sext),64);
        tracep->fullQData(oldp+115,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_b))
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+117,(vlTOPp->Top__DOT__imm_b_sext),66);
        tracep->fullIData(oldp+120,(((0x800000U & vlTOPp->Top__DOT__inst)
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+121,(vlTOPp->Top__DOT__imm_u_sext),64);
        tracep->fullQData(oldp+123,(((0x80000U & vlTOPp->Top__DOT__imm_j)
                                      ? 0x1fffffffffffffULL
                                      : 0ULL)),53);
        tracep->fullWData(oldp+125,(vlTOPp->Top__DOT__imm_j_sext),74);
        tracep->fullIData(oldp+128,(((IData)(4U) + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
        tracep->fullWData(oldp+129,(vlTOPp->Top__DOT__br_target),66);
        tracep->fullWData(oldp+132,(vlTOPp->Top__DOT__jmp_target),74);
        tracep->fullQData(oldp+135,(vlTOPp->Top__DOT__jr_target),64);
        tracep->fullBit(oldp+137,(vlTOPp->Top__DOT__br_taken));
        tracep->fullIData(oldp+138,(vlTOPp->Top__DOT___pc_next_T_5[0U]),32);
        tracep->fullWData(oldp+139,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
        tracep->fullQData(oldp+142,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+144,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+146,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+148,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+149,(vlTOPp->Top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+150,((0x3fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),6);
        tracep->fullQData(oldp+151,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__alu__DOT___T_7[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__alu__DOT___T_7[0U])))),64);
        tracep->fullQData(oldp+153,(vlTOPp->Top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+155,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
        tracep->fullQData(oldp+157,((((QData)((IData)(
                                                      vlTOPp->Top__DOT__alu__DOT__add_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->Top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullQData(oldp+159,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+161,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+163,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+165,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+167,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+169,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+171,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+173,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+175,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+177,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+179,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+181,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+183,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+185,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+187,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+189,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+191,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+193,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+195,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+197,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+199,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+201,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+203,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+205,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+207,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+209,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+211,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+213,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+215,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+217,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+219,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+221,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        tracep->fullQData(oldp+223,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+225,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullBit(oldp+227,(vlTOPp->clock));
        tracep->fullBit(oldp+228,(vlTOPp->reset));
        tracep->fullBit(oldp+229,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+230,(vlTOPp->io_imem_req_valid));
        tracep->fullIData(oldp+231,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->fullIData(oldp+232,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+233,(vlTOPp->io_imem_req_bits_fcn));
        tracep->fullCData(oldp+234,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+235,(vlTOPp->io_imem_resp_ready));
        tracep->fullBit(oldp+236,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+237,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+238,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+239,(vlTOPp->io_dmem_req_valid));
        tracep->fullIData(oldp+240,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->fullQData(oldp+241,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+243,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->fullCData(oldp+244,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+245,(vlTOPp->io_dmem_resp_ready));
        tracep->fullBit(oldp+246,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+247,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullQData(oldp+249,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+251,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+253,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+255,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+257,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+259,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+261,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+263,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+265,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+267,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+269,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+271,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+273,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+275,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+277,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+279,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+281,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+283,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+285,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+287,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+289,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+291,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+293,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+295,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+297,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+299,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+301,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+303,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+305,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+307,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+309,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+311,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+313,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+315,(vlTOPp->io_debug_stall));
        tracep->fullBit(oldp+316,(vlTOPp->io_debug_trap));
        tracep->fullQData(oldp+317,(vlTOPp->Top__DOT__rf_io_wdata),64);
        tracep->fullBit(oldp+319,(vlTOPp->Top__DOT__stall));
        tracep->fullCData(oldp+320,(0U),5);
        tracep->fullCData(oldp+321,(1U),5);
        tracep->fullCData(oldp+322,(2U),5);
        tracep->fullCData(oldp+323,(3U),5);
        tracep->fullCData(oldp+324,(4U),5);
        tracep->fullCData(oldp+325,(5U),5);
        tracep->fullCData(oldp+326,(6U),5);
        tracep->fullCData(oldp+327,(7U),5);
        tracep->fullCData(oldp+328,(8U),5);
        tracep->fullCData(oldp+329,(9U),5);
        tracep->fullCData(oldp+330,(0xaU),5);
        tracep->fullCData(oldp+331,(0xbU),5);
        tracep->fullCData(oldp+332,(0xcU),5);
        tracep->fullCData(oldp+333,(0xdU),5);
        tracep->fullCData(oldp+334,(0xeU),5);
        tracep->fullCData(oldp+335,(0xfU),5);
        tracep->fullCData(oldp+336,(0x10U),5);
        tracep->fullCData(oldp+337,(0x11U),5);
        tracep->fullCData(oldp+338,(0x12U),5);
        tracep->fullCData(oldp+339,(0x13U),5);
        tracep->fullCData(oldp+340,(0x14U),5);
        tracep->fullCData(oldp+341,(0x15U),5);
        tracep->fullCData(oldp+342,(0x16U),5);
        tracep->fullCData(oldp+343,(0x17U),5);
        tracep->fullCData(oldp+344,(0x18U),5);
        tracep->fullCData(oldp+345,(0x19U),5);
        tracep->fullCData(oldp+346,(0x1aU),5);
        tracep->fullCData(oldp+347,(0x1bU),5);
        tracep->fullCData(oldp+348,(0x1cU),5);
        tracep->fullCData(oldp+349,(0x1dU),5);
        tracep->fullCData(oldp+350,(0x1eU),5);
        tracep->fullCData(oldp+351,(0x1fU),5);
        tracep->fullBit(oldp+352,(1U));
    }
}
