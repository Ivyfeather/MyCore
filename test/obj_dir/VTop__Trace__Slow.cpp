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
        tracep->declBit(c+137,"clock", false,-1);
        tracep->declBit(c+138,"reset", false,-1);
        tracep->declBit(c+139,"io_imem_req_ready", false,-1);
        tracep->declBit(c+140,"io_imem_req_valid", false,-1);
        tracep->declBus(c+141,"io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+142,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+143,"io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+144,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+145,"io_imem_resp_ready", false,-1);
        tracep->declBit(c+146,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+147,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+148,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+149,"io_dmem_req_valid", false,-1);
        tracep->declBus(c+150,"io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+151,"io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+153,"io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+154,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+155,"io_dmem_resp_ready", false,-1);
        tracep->declBit(c+156,"io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+157,"io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+159,"io_debug_io_wen", false,-1);
        tracep->declBus(c+160,"io_debug_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+161,"io_debug_io_wdata", false,-1, 63,0);
        tracep->declQuad(c+163,"io_debug_io_PC", false,-1, 63,0);
        tracep->declBit(c+165,"io_debug_io_stall", false,-1);
        tracep->declBit(c+137,"Top clock", false,-1);
        tracep->declBit(c+138,"Top reset", false,-1);
        tracep->declBit(c+139,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+140,"Top io_imem_req_valid", false,-1);
        tracep->declBus(c+141,"Top io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+142,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+143,"Top io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+144,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+145,"Top io_imem_resp_ready", false,-1);
        tracep->declBit(c+146,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+147,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+148,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+149,"Top io_dmem_req_valid", false,-1);
        tracep->declBus(c+150,"Top io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declQuad(c+151,"Top io_dmem_req_bits_data", false,-1, 63,0);
        tracep->declBit(c+153,"Top io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+154,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+155,"Top io_dmem_resp_ready", false,-1);
        tracep->declBit(c+156,"Top io_dmem_resp_valid", false,-1);
        tracep->declQuad(c+157,"Top io_dmem_resp_bits_data", false,-1, 63,0);
        tracep->declBit(c+159,"Top io_debug_io_wen", false,-1);
        tracep->declBus(c+160,"Top io_debug_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+161,"Top io_debug_io_wdata", false,-1, 63,0);
        tracep->declQuad(c+163,"Top io_debug_io_PC", false,-1, 63,0);
        tracep->declBit(c+165,"Top io_debug_io_stall", false,-1);
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
        tracep->declBit(c+137,"Top rf_clock", false,-1);
        tracep->declBus(c+18,"Top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top rf_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"Top rf_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf_io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf_io_wen", false,-1);
        tracep->declQuad(c+70,"Top pc_reg", false,-1, 63,0);
        tracep->declBus(c+9,"Top inst", false,-1, 31,0);
        tracep->declBit(c+27,"Top stall", false,-1);
        tracep->declBus(c+28,"Top imm_i", false,-1, 11,0);
        tracep->declBus(c+29,"Top imm_s", false,-1, 11,0);
        tracep->declBus(c+30,"Top imm_b", false,-1, 11,0);
        tracep->declBus(c+31,"Top imm_u", false,-1, 19,0);
        tracep->declBus(c+32,"Top imm_j", false,-1, 19,0);
        tracep->declBus(c+33,"Top imm_z", false,-1, 31,0);
        tracep->declBus(c+34,"Top imm_i_sext", false,-1, 31,0);
        tracep->declBus(c+35,"Top imm_s_sext", false,-1, 31,0);
        tracep->declBus(c+36,"Top imm_b_sext", false,-1, 31,0);
        tracep->declBus(c+37,"Top imm_u_sext", false,-1, 31,0);
        tracep->declBus(c+38,"Top imm_j_sext", false,-1, 31,0);
        tracep->declBus(c+72,"Top pc_4", false,-1, 31,0);
        tracep->declQuad(c+39,"Top br_target", false,-1, 63,0);
        tracep->declQuad(c+41,"Top jmp_target", false,-1, 63,0);
        tracep->declQuad(c+43,"Top jr_target", false,-1, 63,0);
        tracep->declBit(c+45,"Top br_taken", false,-1);
        tracep->declBus(c+46,"Top pc_next", false,-1, 31,0);
        tracep->declBus(c+1,"Top alu io_opcode", false,-1, 5,0);
        tracep->declQuad(c+2,"Top alu io_in1", false,-1, 63,0);
        tracep->declQuad(c+4,"Top alu io_in2", false,-1, 63,0);
        tracep->declQuad(c+6,"Top alu io_out", false,-1, 63,0);
        tracep->declBit(c+8,"Top alu io_zero", false,-1);
        tracep->declArray(c+47,"Top alu add_result", false,-1, 64,0);
        tracep->declQuad(c+50,"Top alu xor_result", false,-1, 63,0);
        tracep->declQuad(c+52,"Top alu or_result", false,-1, 63,0);
        tracep->declQuad(c+54,"Top alu and_result", false,-1, 63,0);
        tracep->declBit(c+56,"Top alu sltu_result", false,-1);
        tracep->declBit(c+57,"Top alu slt_result", false,-1);
        tracep->declBus(c+58,"Top alu shamt", false,-1, 4,0);
        tracep->declQuad(c+59,"Top alu sll_result", false,-1, 63,0);
        tracep->declQuad(c+61,"Top alu sra_result", false,-1, 63,0);
        tracep->declQuad(c+63,"Top alu srl_result", false,-1, 63,0);
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
        tracep->declBus(c+65,"Top idu csignals_4", false,-1, 4,0);
        tracep->declBit(c+137,"Top rf clock", false,-1);
        tracep->declBus(c+18,"Top rf io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"Top rf io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"Top rf io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf io_waddr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf io_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"Top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+73+i*2,"Top rf regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+66,"Top rf regfile__T_24_data", false,-1, 63,0);
        tracep->declBus(c+18,"Top rf regfile__T_24_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"Top rf regfile__T_29_data", false,-1, 63,0);
        tracep->declBus(c+21,"Top rf regfile__T_29_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"Top rf regfile__T_21_data", false,-1, 63,0);
        tracep->declBus(c+24,"Top rf regfile__T_21_addr", false,-1, 4,0);
        tracep->declBit(c+166,"Top rf regfile__T_21_mask", false,-1);
        tracep->declBit(c+14,"Top rf regfile__T_21_en", false,-1);
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
        tracep->fullSData(oldp+29,(vlTOPp->Top__DOT__imm_s),12);
        tracep->fullSData(oldp+30,(vlTOPp->Top__DOT__imm_b),12);
        tracep->fullIData(oldp+31,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xcU))),20);
        tracep->fullIData(oldp+32,(vlTOPp->Top__DOT__imm_j),20);
        tracep->fullIData(oldp+33,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xfU))),32);
        tracep->fullIData(oldp+34,(vlTOPp->Top__DOT__imm_i_sext),32);
        tracep->fullIData(oldp+35,(vlTOPp->Top__DOT__imm_s_sext),32);
        tracep->fullIData(oldp+36,((vlTOPp->Top__DOT___T_151 
                                    << 1U)),32);
        tracep->fullIData(oldp+37,((0xfffff000U & vlTOPp->Top__DOT__idu_io_inst)),32);
        tracep->fullIData(oldp+38,((vlTOPp->Top__DOT___T_163 
                                    << 1U)),32);
        tracep->fullQData(oldp+39,((((QData)((IData)(
                                                     vlTOPp->Top__DOT___T_188[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT___T_188[0U])))),64);
        tracep->fullQData(oldp+41,((((QData)((IData)(
                                                     vlTOPp->Top__DOT___T_189[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT___T_189[0U])))),64);
        tracep->fullQData(oldp+43,((((QData)((IData)(
                                                     vlTOPp->Top__DOT___T_190[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT___T_190[0U])))),64);
        tracep->fullBit(oldp+45,(vlTOPp->Top__DOT__br_taken));
        tracep->fullIData(oldp+46,((IData)(vlTOPp->Top__DOT___T_231)),32);
        tracep->fullWData(oldp+47,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
        tracep->fullQData(oldp+50,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
        tracep->fullQData(oldp+52,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
        tracep->fullQData(oldp+54,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
        tracep->fullBit(oldp+56,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
        tracep->fullBit(oldp+57,(vlTOPp->Top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+58,((0x1fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),5);
        tracep->fullQData(oldp+59,((((QData)((IData)(
                                                     vlTOPp->Top__DOT__alu__DOT___T_23[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->Top__DOT__alu__DOT___T_23[0U])))),64);
        tracep->fullQData(oldp+61,(vlTOPp->Top__DOT__alu__DOT___T_25),64);
        tracep->fullQData(oldp+63,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
        tracep->fullCData(oldp+65,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
        tracep->fullQData(oldp+66,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data),64);
        tracep->fullQData(oldp+68,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data),64);
        tracep->fullQData(oldp+70,(vlTOPp->Top__DOT__pc_reg),64);
        tracep->fullIData(oldp+72,(((IData)(4U) + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
        tracep->fullQData(oldp+73,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
        tracep->fullQData(oldp+75,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
        tracep->fullQData(oldp+77,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
        tracep->fullQData(oldp+79,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
        tracep->fullQData(oldp+81,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
        tracep->fullQData(oldp+83,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
        tracep->fullQData(oldp+85,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
        tracep->fullQData(oldp+87,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
        tracep->fullQData(oldp+89,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
        tracep->fullQData(oldp+91,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
        tracep->fullQData(oldp+93,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
        tracep->fullQData(oldp+95,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
        tracep->fullQData(oldp+97,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
        tracep->fullQData(oldp+99,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
        tracep->fullQData(oldp+101,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
        tracep->fullQData(oldp+103,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
        tracep->fullQData(oldp+105,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
        tracep->fullQData(oldp+107,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
        tracep->fullQData(oldp+109,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
        tracep->fullQData(oldp+111,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
        tracep->fullQData(oldp+113,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
        tracep->fullQData(oldp+115,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
        tracep->fullQData(oldp+117,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
        tracep->fullQData(oldp+119,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
        tracep->fullQData(oldp+121,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
        tracep->fullQData(oldp+123,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
        tracep->fullQData(oldp+125,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
        tracep->fullQData(oldp+127,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
        tracep->fullQData(oldp+129,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
        tracep->fullQData(oldp+131,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
        tracep->fullQData(oldp+133,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
        tracep->fullQData(oldp+135,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        tracep->fullBit(oldp+137,(vlTOPp->clock));
        tracep->fullBit(oldp+138,(vlTOPp->reset));
        tracep->fullBit(oldp+139,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+140,(vlTOPp->io_imem_req_valid));
        tracep->fullIData(oldp+141,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->fullIData(oldp+142,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+143,(vlTOPp->io_imem_req_bits_fcn));
        tracep->fullCData(oldp+144,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+145,(vlTOPp->io_imem_resp_ready));
        tracep->fullBit(oldp+146,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+147,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+148,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+149,(vlTOPp->io_dmem_req_valid));
        tracep->fullIData(oldp+150,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->fullQData(oldp+151,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->fullBit(oldp+153,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->fullCData(oldp+154,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+155,(vlTOPp->io_dmem_resp_ready));
        tracep->fullBit(oldp+156,(vlTOPp->io_dmem_resp_valid));
        tracep->fullQData(oldp+157,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->fullBit(oldp+159,(vlTOPp->io_debug_io_wen));
        tracep->fullCData(oldp+160,(vlTOPp->io_debug_io_waddr),5);
        tracep->fullQData(oldp+161,(vlTOPp->io_debug_io_wdata),64);
        tracep->fullQData(oldp+163,(vlTOPp->io_debug_io_PC),64);
        tracep->fullBit(oldp+165,(vlTOPp->io_debug_io_stall));
        tracep->fullBit(oldp+166,(1U));
    }
}
