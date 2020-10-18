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
        tracep->declBit(c+216,"clock", false,-1);
        tracep->declBit(c+217,"reset", false,-1);
        tracep->declBit(c+218,"io_imem_req_ready", false,-1);
        tracep->declBit(c+219,"io_imem_req_valid", false,-1);
        tracep->declBus(c+220,"io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+221,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+222,"io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+223,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+224,"io_imem_resp_ready", false,-1);
        tracep->declBit(c+225,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+226,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+227,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+228,"io_dmem_req_valid", false,-1);
        tracep->declBus(c+229,"io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+230,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+232,"io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+233,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+234,"io_dmem_resp_ready", false,-1);
        tracep->declBit(c+235,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+236,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+238,"io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+240,"io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+242,"io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+244,"io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+246,"io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+248,"io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+250,"io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+252,"io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+254,"io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+256,"io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+258,"io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+260,"io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+262,"io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+264,"io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+266,"io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+268,"io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+270,"io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+272,"io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+274,"io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+276,"io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+278,"io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+280,"io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+282,"io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+284,"io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+286,"io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+288,"io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+290,"io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+292,"io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+294,"io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+296,"io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+298,"io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+300,"io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+302,"io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+304,"io_debug_stall", false,-1);
        tracep->declBit(c+216,"Top clock", false,-1);
        tracep->declBit(c+217,"Top reset", false,-1);
        tracep->declBit(c+218,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+219,"Top io_imem_req_valid", false,-1);
        tracep->declBus(c+220,"Top io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+221,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+222,"Top io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+223,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+224,"Top io_imem_resp_ready", false,-1);
        tracep->declBit(c+225,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+226,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+227,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+228,"Top io_dmem_req_valid", false,-1);
        tracep->declBus(c+229,"Top io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+230,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+232,"Top io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+233,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+234,"Top io_dmem_resp_ready", false,-1);
        tracep->declBit(c+235,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+236,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declQuad(c+238,"Top io_debug_rf_0", false,-1, 63,0);
        tracep->declQuad(c+240,"Top io_debug_rf_1", false,-1, 63,0);
        tracep->declQuad(c+242,"Top io_debug_rf_2", false,-1, 63,0);
        tracep->declQuad(c+244,"Top io_debug_rf_3", false,-1, 63,0);
        tracep->declQuad(c+246,"Top io_debug_rf_4", false,-1, 63,0);
        tracep->declQuad(c+248,"Top io_debug_rf_5", false,-1, 63,0);
        tracep->declQuad(c+250,"Top io_debug_rf_6", false,-1, 63,0);
        tracep->declQuad(c+252,"Top io_debug_rf_7", false,-1, 63,0);
        tracep->declQuad(c+254,"Top io_debug_rf_8", false,-1, 63,0);
        tracep->declQuad(c+256,"Top io_debug_rf_9", false,-1, 63,0);
        tracep->declQuad(c+258,"Top io_debug_rf_10", false,-1, 63,0);
        tracep->declQuad(c+260,"Top io_debug_rf_11", false,-1, 63,0);
        tracep->declQuad(c+262,"Top io_debug_rf_12", false,-1, 63,0);
        tracep->declQuad(c+264,"Top io_debug_rf_13", false,-1, 63,0);
        tracep->declQuad(c+266,"Top io_debug_rf_14", false,-1, 63,0);
        tracep->declQuad(c+268,"Top io_debug_rf_15", false,-1, 63,0);
        tracep->declQuad(c+270,"Top io_debug_rf_16", false,-1, 63,0);
        tracep->declQuad(c+272,"Top io_debug_rf_17", false,-1, 63,0);
        tracep->declQuad(c+274,"Top io_debug_rf_18", false,-1, 63,0);
        tracep->declQuad(c+276,"Top io_debug_rf_19", false,-1, 63,0);
        tracep->declQuad(c+278,"Top io_debug_rf_20", false,-1, 63,0);
        tracep->declQuad(c+280,"Top io_debug_rf_21", false,-1, 63,0);
        tracep->declQuad(c+282,"Top io_debug_rf_22", false,-1, 63,0);
        tracep->declQuad(c+284,"Top io_debug_rf_23", false,-1, 63,0);
        tracep->declQuad(c+286,"Top io_debug_rf_24", false,-1, 63,0);
        tracep->declQuad(c+288,"Top io_debug_rf_25", false,-1, 63,0);
        tracep->declQuad(c+290,"Top io_debug_rf_26", false,-1, 63,0);
        tracep->declQuad(c+292,"Top io_debug_rf_27", false,-1, 63,0);
        tracep->declQuad(c+294,"Top io_debug_rf_28", false,-1, 63,0);
        tracep->declQuad(c+296,"Top io_debug_rf_29", false,-1, 63,0);
        tracep->declQuad(c+298,"Top io_debug_rf_30", false,-1, 63,0);
        tracep->declQuad(c+300,"Top io_debug_rf_31", false,-1, 63,0);
        tracep->declQuad(c+302,"Top io_debug_PC", false,-1, 63,0);
        tracep->declBit(c+304,"Top io_debug_stall", false,-1);
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
        tracep->declBit(c+216,"Top rf_clock", false,-1);
        tracep->declBus(c+18,"Top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"Top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf_io_wen", false,-1);
        tracep->declQuad(c+84,"Top rf__WIRE_0_0", false,-1, 63,0);
        tracep->declQuad(c+86,"Top rf__WIRE_0_1", false,-1, 63,0);
        tracep->declQuad(c+88,"Top rf__WIRE_0_2", false,-1, 63,0);
        tracep->declQuad(c+90,"Top rf__WIRE_0_3", false,-1, 63,0);
        tracep->declQuad(c+92,"Top rf__WIRE_0_4", false,-1, 63,0);
        tracep->declQuad(c+94,"Top rf__WIRE_0_5", false,-1, 63,0);
        tracep->declQuad(c+96,"Top rf__WIRE_0_6", false,-1, 63,0);
        tracep->declQuad(c+98,"Top rf__WIRE_0_7", false,-1, 63,0);
        tracep->declQuad(c+100,"Top rf__WIRE_0_8", false,-1, 63,0);
        tracep->declQuad(c+102,"Top rf__WIRE_0_9", false,-1, 63,0);
        tracep->declQuad(c+104,"Top rf__WIRE_0_10", false,-1, 63,0);
        tracep->declQuad(c+106,"Top rf__WIRE_0_11", false,-1, 63,0);
        tracep->declQuad(c+108,"Top rf__WIRE_0_12", false,-1, 63,0);
        tracep->declQuad(c+110,"Top rf__WIRE_0_13", false,-1, 63,0);
        tracep->declQuad(c+112,"Top rf__WIRE_0_14", false,-1, 63,0);
        tracep->declQuad(c+114,"Top rf__WIRE_0_15", false,-1, 63,0);
        tracep->declQuad(c+116,"Top rf__WIRE_0_16", false,-1, 63,0);
        tracep->declQuad(c+118,"Top rf__WIRE_0_17", false,-1, 63,0);
        tracep->declQuad(c+120,"Top rf__WIRE_0_18", false,-1, 63,0);
        tracep->declQuad(c+122,"Top rf__WIRE_0_19", false,-1, 63,0);
        tracep->declQuad(c+124,"Top rf__WIRE_0_20", false,-1, 63,0);
        tracep->declQuad(c+126,"Top rf__WIRE_0_21", false,-1, 63,0);
        tracep->declQuad(c+128,"Top rf__WIRE_0_22", false,-1, 63,0);
        tracep->declQuad(c+130,"Top rf__WIRE_0_23", false,-1, 63,0);
        tracep->declQuad(c+132,"Top rf__WIRE_0_24", false,-1, 63,0);
        tracep->declQuad(c+134,"Top rf__WIRE_0_25", false,-1, 63,0);
        tracep->declQuad(c+136,"Top rf__WIRE_0_26", false,-1, 63,0);
        tracep->declQuad(c+138,"Top rf__WIRE_0_27", false,-1, 63,0);
        tracep->declQuad(c+140,"Top rf__WIRE_0_28", false,-1, 63,0);
        tracep->declQuad(c+142,"Top rf__WIRE_0_29", false,-1, 63,0);
        tracep->declQuad(c+144,"Top rf__WIRE_0_30", false,-1, 63,0);
        tracep->declQuad(c+146,"Top rf__WIRE_0_31", false,-1, 63,0);
        tracep->declQuad(c+148,"Top pc_reg", false,-1, 63,0);
        tracep->declBit(c+27,"Top stall", false,-1);
        tracep->declBit(c+150,"Top imem_req_r", false,-1);
        tracep->declBus(c+9,"Top inst", false,-1, 31,0);
        tracep->declBus(c+28,"Top imm_i", false,-1, 11,0);
        tracep->declBus(c+29,"Top right", false,-1, 6,0);
        tracep->declBus(c+24,"Top left", false,-1, 4,0);
        tracep->declBus(c+30,"Top imm_s", false,-1, 11,0);
        tracep->declBit(c+31,"Top right_right", false,-1);
        tracep->declBit(c+32,"Top right_left", false,-1);
        tracep->declBus(c+33,"Top left_right", false,-1, 5,0);
        tracep->declBus(c+34,"Top left_left", false,-1, 3,0);
        tracep->declBus(c+35,"Top imm_b", false,-1, 11,0);
        tracep->declBus(c+36,"Top imm_u", false,-1, 19,0);
        tracep->declBus(c+37,"Top right_left_1", false,-1, 7,0);
        tracep->declBit(c+38,"Top left_right_1", false,-1);
        tracep->declBus(c+39,"Top left_left_1", false,-1, 9,0);
        tracep->declBus(c+40,"Top imm_j", false,-1, 19,0);
        tracep->declBus(c+18,"Top left_3", false,-1, 4,0);
        tracep->declBus(c+41,"Top imm_z", false,-1, 31,0);
        tracep->declBus(c+42,"Top right_4", false,-1, 19,0);
        tracep->declBus(c+43,"Top imm_i_sext", false,-1, 31,0);
        tracep->declBus(c+44,"Top right_5", false,-1, 19,0);
        tracep->declBus(c+45,"Top imm_s_sext", false,-1, 31,0);
        tracep->declBus(c+46,"Top right_right_2", false,-1, 18,0);
        tracep->declBus(c+47,"Top imm_b_sext", false,-1, 31,0);
        tracep->declBus(c+48,"Top imm_u_sext", false,-1, 31,0);
        tracep->declBus(c+49,"Top right_right_3", false,-1, 10,0);
        tracep->declBus(c+50,"Top imm_j_sext", false,-1, 31,0);
        tracep->declBus(c+151,"Top pc_4", false,-1, 31,0);
        tracep->declQuad(c+51,"Top br_target", false,-1, 63,0);
        tracep->declQuad(c+53,"Top jmp_target", false,-1, 63,0);
        tracep->declQuad(c+55,"Top jr_target", false,-1, 63,0);
        tracep->declBit(c+57,"Top br_taken", false,-1);
        tracep->declBus(c+58,"Top pc_next", false,-1, 31,0);
        tracep->declBus(c+1,"Top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+2,"Top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+4,"Top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+6,"Top alu io_out", false,-1, 63,0);
        tracep->declBit(c+8,"Top alu io_zero", false,-1);
        tracep->declArray(c+59,"Top alu add_result", false,-1, 64,0);
        tracep->declQuad(c+62,"Top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+64,"Top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+66,"Top alu and_result", false,-1, 63,0);
        tracep->declBit(c+68,"Top alu sltu_result", false,-1);
        tracep->declBit(c+69,"Top alu slt_result", false,-1);
        tracep->declBus(c+70,"Top alu shamt", false,-1, 4,0);
        tracep->declQuad(c+71,"Top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+73,"Top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+75,"Top alu srl_result", false,-1, 63,0);
        tracep->declQuad(c+77,"Top alu io_out_res", false,-1, 63,0);
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
        tracep->declBus(c+79,"Top idu csignals_4", false,-1, 4,0);
        tracep->declBit(c+216,"Top rf clock", false,-1);
        tracep->declBus(c+18,"Top rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"Top rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+152+i*2,"Top rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+80,"Top rf regfile_io_rs1_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+18,"Top rf regfile_io_rs1_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+82,"Top rf regfile_io_rs2_data_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf regfile_io_rs2_data_MPORT_addr", false,-1, 4,0);
        tracep->declQuad(c+84,"Top rf regfile_MPORT_1_data", false,-1, 63,0);
        tracep->declBus(c+305,"Top rf regfile_MPORT_1_addr", false,-1, 4,0);
        tracep->declQuad(c+86,"Top rf regfile_MPORT_2_data", false,-1, 63,0);
        tracep->declBus(c+306,"Top rf regfile_MPORT_2_addr", false,-1, 4,0);
        tracep->declQuad(c+88,"Top rf regfile_MPORT_3_data", false,-1, 63,0);
        tracep->declBus(c+307,"Top rf regfile_MPORT_3_addr", false,-1, 4,0);
        tracep->declQuad(c+90,"Top rf regfile_MPORT_4_data", false,-1, 63,0);
        tracep->declBus(c+308,"Top rf regfile_MPORT_4_addr", false,-1, 4,0);
        tracep->declQuad(c+92,"Top rf regfile_MPORT_5_data", false,-1, 63,0);
        tracep->declBus(c+309,"Top rf regfile_MPORT_5_addr", false,-1, 4,0);
        tracep->declQuad(c+94,"Top rf regfile_MPORT_6_data", false,-1, 63,0);
        tracep->declBus(c+310,"Top rf regfile_MPORT_6_addr", false,-1, 4,0);
        tracep->declQuad(c+96,"Top rf regfile_MPORT_7_data", false,-1, 63,0);
        tracep->declBus(c+311,"Top rf regfile_MPORT_7_addr", false,-1, 4,0);
        tracep->declQuad(c+98,"Top rf regfile_MPORT_8_data", false,-1, 63,0);
        tracep->declBus(c+312,"Top rf regfile_MPORT_8_addr", false,-1, 4,0);
        tracep->declQuad(c+100,"Top rf regfile_MPORT_9_data", false,-1, 63,0);
        tracep->declBus(c+313,"Top rf regfile_MPORT_9_addr", false,-1, 4,0);
        tracep->declQuad(c+102,"Top rf regfile_MPORT_10_data", false,-1, 63,0);
        tracep->declBus(c+314,"Top rf regfile_MPORT_10_addr", false,-1, 4,0);
        tracep->declQuad(c+104,"Top rf regfile_MPORT_11_data", false,-1, 63,0);
        tracep->declBus(c+315,"Top rf regfile_MPORT_11_addr", false,-1, 4,0);
        tracep->declQuad(c+106,"Top rf regfile_MPORT_12_data", false,-1, 63,0);
        tracep->declBus(c+316,"Top rf regfile_MPORT_12_addr", false,-1, 4,0);
        tracep->declQuad(c+108,"Top rf regfile_MPORT_13_data", false,-1, 63,0);
        tracep->declBus(c+317,"Top rf regfile_MPORT_13_addr", false,-1, 4,0);
        tracep->declQuad(c+110,"Top rf regfile_MPORT_14_data", false,-1, 63,0);
        tracep->declBus(c+318,"Top rf regfile_MPORT_14_addr", false,-1, 4,0);
        tracep->declQuad(c+112,"Top rf regfile_MPORT_15_data", false,-1, 63,0);
        tracep->declBus(c+319,"Top rf regfile_MPORT_15_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"Top rf regfile_MPORT_16_data", false,-1, 63,0);
        tracep->declBus(c+320,"Top rf regfile_MPORT_16_addr", false,-1, 4,0);
        tracep->declQuad(c+116,"Top rf regfile_MPORT_17_data", false,-1, 63,0);
        tracep->declBus(c+321,"Top rf regfile_MPORT_17_addr", false,-1, 4,0);
        tracep->declQuad(c+118,"Top rf regfile_MPORT_18_data", false,-1, 63,0);
        tracep->declBus(c+322,"Top rf regfile_MPORT_18_addr", false,-1, 4,0);
        tracep->declQuad(c+120,"Top rf regfile_MPORT_19_data", false,-1, 63,0);
        tracep->declBus(c+323,"Top rf regfile_MPORT_19_addr", false,-1, 4,0);
        tracep->declQuad(c+122,"Top rf regfile_MPORT_20_data", false,-1, 63,0);
        tracep->declBus(c+324,"Top rf regfile_MPORT_20_addr", false,-1, 4,0);
        tracep->declQuad(c+124,"Top rf regfile_MPORT_21_data", false,-1, 63,0);
        tracep->declBus(c+325,"Top rf regfile_MPORT_21_addr", false,-1, 4,0);
        tracep->declQuad(c+126,"Top rf regfile_MPORT_22_data", false,-1, 63,0);
        tracep->declBus(c+326,"Top rf regfile_MPORT_22_addr", false,-1, 4,0);
        tracep->declQuad(c+128,"Top rf regfile_MPORT_23_data", false,-1, 63,0);
        tracep->declBus(c+327,"Top rf regfile_MPORT_23_addr", false,-1, 4,0);
        tracep->declQuad(c+130,"Top rf regfile_MPORT_24_data", false,-1, 63,0);
        tracep->declBus(c+328,"Top rf regfile_MPORT_24_addr", false,-1, 4,0);
        tracep->declQuad(c+132,"Top rf regfile_MPORT_25_data", false,-1, 63,0);
        tracep->declBus(c+329,"Top rf regfile_MPORT_25_addr", false,-1, 4,0);
        tracep->declQuad(c+134,"Top rf regfile_MPORT_26_data", false,-1, 63,0);
        tracep->declBus(c+330,"Top rf regfile_MPORT_26_addr", false,-1, 4,0);
        tracep->declQuad(c+136,"Top rf regfile_MPORT_27_data", false,-1, 63,0);
        tracep->declBus(c+331,"Top rf regfile_MPORT_27_addr", false,-1, 4,0);
        tracep->declQuad(c+138,"Top rf regfile_MPORT_28_data", false,-1, 63,0);
        tracep->declBus(c+332,"Top rf regfile_MPORT_28_addr", false,-1, 4,0);
        tracep->declQuad(c+140,"Top rf regfile_MPORT_29_data", false,-1, 63,0);
        tracep->declBus(c+333,"Top rf regfile_MPORT_29_addr", false,-1, 4,0);
        tracep->declQuad(c+142,"Top rf regfile_MPORT_30_data", false,-1, 63,0);
        tracep->declBus(c+334,"Top rf regfile_MPORT_30_addr", false,-1, 4,0);
        tracep->declQuad(c+144,"Top rf regfile_MPORT_31_data", false,-1, 63,0);
        tracep->declBus(c+335,"Top rf regfile_MPORT_31_addr", false,-1, 4,0);
        tracep->declQuad(c+146,"Top rf regfile_MPORT_32_data", false,-1, 63,0);
        tracep->declBus(c+336,"Top rf regfile_MPORT_32_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf regfile_MPORT_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf regfile_MPORT_addr", false,-1, 4,0);
        tracep->declBit(c+337,"Top rf regfile_MPORT_mask", false,-1);
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
        tracep->fullCData(oldp+1,(vlTOPp->Top__DOT__idu__DOT__csignals_4),6);
        tracep->fullQData(oldp+2,(vlTOPp->Top__DOT__alu_io_in1),64);
        tracep->fullQData(oldp+4,(vlTOPp->Top__DOT__alu_io_in2),64);
        tracep->fullQData(oldp+6,(vlTOPp->Top__DOT__alu_io_out),64);
        tracep->fullBit(oldp+8,((0ULL == vlTOPp->Top__DOT__alu_io_out)));
        tracep->fullIData(oldp+9,(vlTOPp->Top__DOT__idu_io_inst),32);
        tracep->fullCData(oldp+10,(vlTOPp->Top__DOT__idu_io_br_type),4);
        tracep->fullCData(oldp+11,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
        tracep->fullCData(oldp+12,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
        tracep->fullCData(oldp+13,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
        tracep->fullBit(oldp+14,(vlTOPp->Top__DOT__idu_io_rf_wen));
        tracep->fullBit(oldp+15,(vlTOPp->Top__DOT__idu_io_mem_en));
        tracep->fullBit(oldp+16,(vlTOPp->Top__DOT__idu_io_mem_fcn));
        tracep->fullCData(oldp+17,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
        tracep->fullCData(oldp+18,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xfU))),5);
        tracep->fullQData(oldp+19,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
        tracep->fullCData(oldp+21,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0x14U))),5);
        tracep->fullQData(oldp+22,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
        tracep->fullCData(oldp+24,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 7U))),5);
        tracep->fullQData(oldp+25,(vlTOPp->Top__DOT__rf_io_wdata),64);
        tracep->fullBit(oldp+27,(vlTOPp->Top__DOT__stall));
        tracep->fullSData(oldp+28,((0xfffU & (vlTOPp->Top__DOT__idu_io_inst 
                                              >> 0x14U))),12);
        tracep->fullCData(oldp+29,((0x7fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0x19U))),7);
        tracep->fullSData(oldp+30,(vlTOPp->Top__DOT__imm_s),12);
        tracep->fullBit(oldp+31,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+32,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                        >> 7U))));
        tracep->fullCData(oldp+33,((0x3fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0x19U))),6);
        tracep->fullCData(oldp+34,((0xfU & (vlTOPp->Top__DOT__idu_io_inst 
                                            >> 8U))),4);
        tracep->fullSData(oldp+35,(vlTOPp->Top__DOT__imm_b),12);
        tracep->fullIData(oldp+36,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xcU))),20);
        tracep->fullCData(oldp+37,((0xffU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xcU))),8);
        tracep->fullBit(oldp+38,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                        >> 0x14U))));
        tracep->fullSData(oldp+39,((0x3ffU & (vlTOPp->Top__DOT__idu_io_inst 
                                              >> 0x15U))),10);
        tracep->fullIData(oldp+40,(vlTOPp->Top__DOT__imm_j),20);
        tracep->fullIData(oldp+41,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xfU))),32);
        tracep->fullIData(oldp+42,(((0x80000000U & vlTOPp->Top__DOT__idu_io_inst)
                                     ? 0xfffffU : 0U)),20);
        tracep->fullIData(oldp+43,(vlTOPp->Top__DOT__imm_i_sext),32);
        tracep->fullIData(oldp+44,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_s))
                                     ? 0xfffffU : 0U)),20);
        tracep->fullIData(oldp+45,(vlTOPp->Top__DOT__imm_s_sext),32);
        tracep->fullIData(oldp+46,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_b))
                                     ? 0x7ffffU : 0U)),19);
        tracep->fullIData(oldp+47,(vlTOPp->Top__DOT__imm_b_sext),32);
        tracep->fullIData(oldp+48,((0xfffff000U & vlTOPp->Top__DOT__idu_io_inst)),32);
        tracep->fullSData(oldp+49,(((0x80000U & vlTOPp->Top__DOT__imm_j)
                                     ? 0x7ffU : 0U)),11);
        tracep->fullIData(oldp+50,(vlTOPp->Top__DOT__imm_j_sext),32);
        tracep->fullQData(oldp+51,(vlTOPp->Top__DOT__br_target),64);
        tracep->fullQData(oldp+53,(vlTOPp->Top__DOT__jmp_target),64);
        tracep->fullQData(oldp+55,(vlTOPp->Top__DOT__jr_target),64);
        tracep->fullBit(oldp+57,(vlTOPp->Top__DOT__br_taken));
        tracep->fullIData(oldp+58,((IData)(vlTOPp->Top__DOT___pc_next_T_5)),32);
        tracep->fullWData(oldp+59,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
        tracep->fullQData(oldp+62,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+64,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+66,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+68,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+69,(vlTOPp->Top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+70,((0x1fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),5);
        tracep->fullQData(oldp+71,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__alu__DOT___T_7[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__alu__DOT___T_7[0U])))),64);
        tracep->fullQData(oldp+73,(vlTOPp->Top__DOT__alu__DOT__sra_result),64);
        tracep->fullQData(oldp+75,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
        tracep->fullQData(oldp+77,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__alu__DOT__add_result[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__alu__DOT__add_result[0U])))),64);
        tracep->fullCData(oldp+79,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
        tracep->fullQData(oldp+80,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
        tracep->fullQData(oldp+82,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        tracep->fullQData(oldp+84,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+86,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+88,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+90,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+92,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+94,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+96,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+98,(vlTOPp->Top__DOT__rf__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+100,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [8U]),64);
        tracep->fullQData(oldp+102,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [9U]),64);
        tracep->fullQData(oldp+104,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xaU]),64);
        tracep->fullQData(oldp+106,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xbU]),64);
        tracep->fullQData(oldp+108,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xcU]),64);
        tracep->fullQData(oldp+110,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xdU]),64);
        tracep->fullQData(oldp+112,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xeU]),64);
        tracep->fullQData(oldp+114,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0xfU]),64);
        tracep->fullQData(oldp+116,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x10U]),64);
        tracep->fullQData(oldp+118,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x11U]),64);
        tracep->fullQData(oldp+120,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x12U]),64);
        tracep->fullQData(oldp+122,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x13U]),64);
        tracep->fullQData(oldp+124,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x14U]),64);
        tracep->fullQData(oldp+126,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x15U]),64);
        tracep->fullQData(oldp+128,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x16U]),64);
        tracep->fullQData(oldp+130,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x17U]),64);
        tracep->fullQData(oldp+132,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x18U]),64);
        tracep->fullQData(oldp+134,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x19U]),64);
        tracep->fullQData(oldp+136,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1aU]),64);
        tracep->fullQData(oldp+138,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1bU]),64);
        tracep->fullQData(oldp+140,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1cU]),64);
        tracep->fullQData(oldp+142,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1dU]),64);
        tracep->fullQData(oldp+144,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1eU]),64);
        tracep->fullQData(oldp+146,(vlTOPp->Top__DOT__rf__DOT__regfile
                                    [0x1fU]),64);
        tracep->fullQData(oldp+148,(vlTOPp->Top__DOT__pc_reg),64);
        tracep->fullBit(oldp+150,(vlTOPp->Top__DOT__imem_req_r));
        tracep->fullIData(oldp+151,(((IData)(4U) + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
        tracep->fullQData(oldp+152,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+154,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+156,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+158,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+160,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+162,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+164,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+166,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+168,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+170,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+172,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+174,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+176,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+178,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+180,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+182,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+184,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+186,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+188,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+190,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+192,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+194,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+196,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+198,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+200,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+202,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+204,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+206,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+208,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+210,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+212,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+214,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        tracep->fullBit(oldp+216,(vlTOPp->clock));
        tracep->fullBit(oldp+217,(vlTOPp->reset));
        tracep->fullBit(oldp+218,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+219,(vlTOPp->io_imem_req_valid));
        tracep->fullIData(oldp+220,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->fullIData(oldp+221,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+222,(vlTOPp->io_imem_req_bits_fcn));
        tracep->fullCData(oldp+223,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+224,(vlTOPp->io_imem_resp_ready));
        tracep->fullBit(oldp+225,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+226,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+227,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+228,(vlTOPp->io_dmem_req_valid));
        tracep->fullIData(oldp+229,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->fullQData(oldp+230,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+232,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->fullCData(oldp+233,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+234,(vlTOPp->io_dmem_resp_ready));
        tracep->fullBit(oldp+235,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+236,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullQData(oldp+238,(vlTOPp->io_debug_rf_0),64);
        tracep->fullQData(oldp+240,(vlTOPp->io_debug_rf_1),64);
        tracep->fullQData(oldp+242,(vlTOPp->io_debug_rf_2),64);
        tracep->fullQData(oldp+244,(vlTOPp->io_debug_rf_3),64);
        tracep->fullQData(oldp+246,(vlTOPp->io_debug_rf_4),64);
        tracep->fullQData(oldp+248,(vlTOPp->io_debug_rf_5),64);
        tracep->fullQData(oldp+250,(vlTOPp->io_debug_rf_6),64);
        tracep->fullQData(oldp+252,(vlTOPp->io_debug_rf_7),64);
        tracep->fullQData(oldp+254,(vlTOPp->io_debug_rf_8),64);
        tracep->fullQData(oldp+256,(vlTOPp->io_debug_rf_9),64);
        tracep->fullQData(oldp+258,(vlTOPp->io_debug_rf_10),64);
        tracep->fullQData(oldp+260,(vlTOPp->io_debug_rf_11),64);
        tracep->fullQData(oldp+262,(vlTOPp->io_debug_rf_12),64);
        tracep->fullQData(oldp+264,(vlTOPp->io_debug_rf_13),64);
        tracep->fullQData(oldp+266,(vlTOPp->io_debug_rf_14),64);
        tracep->fullQData(oldp+268,(vlTOPp->io_debug_rf_15),64);
        tracep->fullQData(oldp+270,(vlTOPp->io_debug_rf_16),64);
        tracep->fullQData(oldp+272,(vlTOPp->io_debug_rf_17),64);
        tracep->fullQData(oldp+274,(vlTOPp->io_debug_rf_18),64);
        tracep->fullQData(oldp+276,(vlTOPp->io_debug_rf_19),64);
        tracep->fullQData(oldp+278,(vlTOPp->io_debug_rf_20),64);
        tracep->fullQData(oldp+280,(vlTOPp->io_debug_rf_21),64);
        tracep->fullQData(oldp+282,(vlTOPp->io_debug_rf_22),64);
        tracep->fullQData(oldp+284,(vlTOPp->io_debug_rf_23),64);
        tracep->fullQData(oldp+286,(vlTOPp->io_debug_rf_24),64);
        tracep->fullQData(oldp+288,(vlTOPp->io_debug_rf_25),64);
        tracep->fullQData(oldp+290,(vlTOPp->io_debug_rf_26),64);
        tracep->fullQData(oldp+292,(vlTOPp->io_debug_rf_27),64);
        tracep->fullQData(oldp+294,(vlTOPp->io_debug_rf_28),64);
        tracep->fullQData(oldp+296,(vlTOPp->io_debug_rf_29),64);
        tracep->fullQData(oldp+298,(vlTOPp->io_debug_rf_30),64);
        tracep->fullQData(oldp+300,(vlTOPp->io_debug_rf_31),64);
        tracep->fullQData(oldp+302,(vlTOPp->io_debug_PC),64);
        tracep->fullBit(oldp+304,(vlTOPp->io_debug_stall));
        tracep->fullCData(oldp+305,(0U),5);
        tracep->fullCData(oldp+306,(1U),5);
        tracep->fullCData(oldp+307,(2U),5);
        tracep->fullCData(oldp+308,(3U),5);
        tracep->fullCData(oldp+309,(4U),5);
        tracep->fullCData(oldp+310,(5U),5);
        tracep->fullCData(oldp+311,(6U),5);
        tracep->fullCData(oldp+312,(7U),5);
        tracep->fullCData(oldp+313,(8U),5);
        tracep->fullCData(oldp+314,(9U),5);
        tracep->fullCData(oldp+315,(0xaU),5);
        tracep->fullCData(oldp+316,(0xbU),5);
        tracep->fullCData(oldp+317,(0xcU),5);
        tracep->fullCData(oldp+318,(0xdU),5);
        tracep->fullCData(oldp+319,(0xeU),5);
        tracep->fullCData(oldp+320,(0xfU),5);
        tracep->fullCData(oldp+321,(0x10U),5);
        tracep->fullCData(oldp+322,(0x11U),5);
        tracep->fullCData(oldp+323,(0x12U),5);
        tracep->fullCData(oldp+324,(0x13U),5);
        tracep->fullCData(oldp+325,(0x14U),5);
        tracep->fullCData(oldp+326,(0x15U),5);
        tracep->fullCData(oldp+327,(0x16U),5);
        tracep->fullCData(oldp+328,(0x17U),5);
        tracep->fullCData(oldp+329,(0x18U),5);
        tracep->fullCData(oldp+330,(0x19U),5);
        tracep->fullCData(oldp+331,(0x1aU),5);
        tracep->fullCData(oldp+332,(0x1bU),5);
        tracep->fullCData(oldp+333,(0x1cU),5);
        tracep->fullCData(oldp+334,(0x1dU),5);
        tracep->fullCData(oldp+335,(0x1eU),5);
        tracep->fullCData(oldp+336,(0x1fU),5);
        tracep->fullBit(oldp+337,(1U));
    }
}
