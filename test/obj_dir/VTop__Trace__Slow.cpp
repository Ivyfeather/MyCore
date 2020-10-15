// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


//======================

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
        tracep->declBit(c+86,"clock", false,-1);
        tracep->declBit(c+87,"reset", false,-1);
        tracep->declBit(c+88,"io_imem_req_ready", false,-1);
        tracep->declBit(c+89,"io_imem_req_valid", false,-1);
        tracep->declBus(c+90,"io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+91,"io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+92,"io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+93,"io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+94,"io_imem_resp_ready", false,-1);
        tracep->declBit(c+95,"io_imem_resp_valid", false,-1);
        tracep->declBus(c+96,"io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+97,"io_dmem_req_ready", false,-1);
        tracep->declBit(c+98,"io_dmem_req_valid", false,-1);
        tracep->declBus(c+99,"io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+100,"io_dmem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+101,"io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+102,"io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+103,"io_dmem_resp_ready", false,-1);
        tracep->declBit(c+104,"io_dmem_resp_valid", false,-1);
        tracep->declBus(c+105,"io_dmem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+106,"io_debug_io_wen", false,-1);
        tracep->declBus(c+107,"io_debug_io_waddr", false,-1, 4,0);
        tracep->declBus(c+108,"io_debug_io_wdata", false,-1, 31,0);
        tracep->declBus(c+109,"io_debug_io_PC", false,-1, 31,0);
        tracep->declBit(c+110,"io_debug_io_stall", false,-1);
        tracep->declBit(c+86,"Top clock", false,-1);
        tracep->declBit(c+87,"Top reset", false,-1);
        tracep->declBit(c+88,"Top io_imem_req_ready", false,-1);
        tracep->declBit(c+89,"Top io_imem_req_valid", false,-1);
        tracep->declBus(c+90,"Top io_imem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+91,"Top io_imem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+92,"Top io_imem_req_bits_fcn", false,-1);
        tracep->declBus(c+93,"Top io_imem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+94,"Top io_imem_resp_ready", false,-1);
        tracep->declBit(c+95,"Top io_imem_resp_valid", false,-1);
        tracep->declBus(c+96,"Top io_imem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+97,"Top io_dmem_req_ready", false,-1);
        tracep->declBit(c+98,"Top io_dmem_req_valid", false,-1);
        tracep->declBus(c+99,"Top io_dmem_req_bits_addr", false,-1, 31,0);
        tracep->declBus(c+100,"Top io_dmem_req_bits_data", false,-1, 31,0);
        tracep->declBit(c+101,"Top io_dmem_req_bits_fcn", false,-1);
        tracep->declBus(c+102,"Top io_dmem_req_bits_msk", false,-1, 2,0);
        tracep->declBit(c+103,"Top io_dmem_resp_ready", false,-1);
        tracep->declBit(c+104,"Top io_dmem_resp_valid", false,-1);
        tracep->declBus(c+105,"Top io_dmem_resp_bits_data", false,-1, 31,0);
        tracep->declBit(c+106,"Top io_debug_io_wen", false,-1);
        tracep->declBus(c+107,"Top io_debug_io_waddr", false,-1, 4,0);
        tracep->declBus(c+108,"Top io_debug_io_wdata", false,-1, 31,0);
        tracep->declBus(c+109,"Top io_debug_io_PC", false,-1, 31,0);
        tracep->declBit(c+110,"Top io_debug_io_stall", false,-1);
        tracep->declBus(c+1,"Top alu_io_opcode", false,-1, 5,0);
        tracep->declBus(c+2,"Top alu_io_in1", false,-1, 31,0);
        tracep->declBus(c+3,"Top alu_io_in2", false,-1, 31,0);
        tracep->declBus(c+4,"Top alu_io_out", false,-1, 31,0);
        tracep->declBit(c+5,"Top alu_io_zero", false,-1);
        tracep->declBus(c+6,"Top idu_io_inst", false,-1, 31,0);
        tracep->declBus(c+7,"Top idu_io_br_type", false,-1, 3,0);
        tracep->declBus(c+8,"Top idu_io_op1_sel", false,-1, 1,0);
        tracep->declBus(c+9,"Top idu_io_op2_sel", false,-1, 1,0);
        tracep->declBus(c+1,"Top idu_io_alu_op", false,-1, 5,0);
        tracep->declBus(c+10,"Top idu_io_wb_sel", false,-1, 1,0);
        tracep->declBit(c+11,"Top idu_io_rf_wen", false,-1);
        tracep->declBit(c+12,"Top idu_io_mem_en", false,-1);
        tracep->declBit(c+13,"Top idu_io_mem_fcn", false,-1);
        tracep->declBus(c+14,"Top idu_io_mem_msk", false,-1, 2,0);
        tracep->declBit(c+86,"Top rf_clock", false,-1);
        tracep->declBus(c+15,"Top rf_io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+16,"Top rf_io_rs1_data", false,-1, 31,0);
        tracep->declBus(c+17,"Top rf_io_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+18,"Top rf_io_rs2_data", false,-1, 31,0);
        tracep->declBus(c+19,"Top rf_io_waddr", false,-1, 4,0);
        tracep->declBus(c+20,"Top rf_io_wdata", false,-1, 31,0);
        tracep->declBit(c+11,"Top rf_io_wen", false,-1);
        tracep->declBus(c+52,"Top pc_reg", false,-1, 31,0);
        tracep->declBus(c+53,"Top pc_4", false,-1, 31,0);
        tracep->declBus(c+6,"Top inst", false,-1, 31,0);
        tracep->declBit(c+21,"Top stall", false,-1);
        tracep->declBus(c+22,"Top imm_i", false,-1, 11,0);
        tracep->declBus(c+23,"Top imm_s", false,-1, 11,0);
        tracep->declBus(c+24,"Top imm_b", false,-1, 11,0);
        tracep->declBus(c+25,"Top imm_u", false,-1, 19,0);
        tracep->declBus(c+26,"Top imm_j", false,-1, 19,0);
        tracep->declBus(c+27,"Top imm_z", false,-1, 31,0);
        tracep->declBus(c+28,"Top imm_i_sext", false,-1, 31,0);
        tracep->declBus(c+29,"Top imm_s_sext", false,-1, 31,0);
        tracep->declBus(c+30,"Top imm_b_sext", false,-1, 31,0);
        tracep->declBus(c+31,"Top imm_u_sext", false,-1, 31,0);
        tracep->declBus(c+32,"Top imm_j_sext", false,-1, 31,0);
        tracep->declBus(c+33,"Top br_target", false,-1, 31,0);
        tracep->declBus(c+34,"Top jmp_target", false,-1, 31,0);
        tracep->declBus(c+35,"Top jr_target", false,-1, 31,0);
        tracep->declBit(c+36,"Top br_taken", false,-1);
        tracep->declBus(c+37,"Top pc_next", false,-1, 31,0);
        tracep->declBus(c+1,"Top alu io_opcode", false,-1, 5,0);
        tracep->declBus(c+2,"Top alu io_in1", false,-1, 31,0);
        tracep->declBus(c+3,"Top alu io_in2", false,-1, 31,0);
        tracep->declBus(c+4,"Top alu io_out", false,-1, 31,0);
        tracep->declBit(c+5,"Top alu io_zero", false,-1);
        tracep->declQuad(c+38,"Top alu add_result", false,-1, 32,0);
        tracep->declBus(c+40,"Top alu xor_result", false,-1, 31,0);
        tracep->declBus(c+41,"Top alu or_result", false,-1, 31,0);
        tracep->declBus(c+42,"Top alu and_result", false,-1, 31,0);
        tracep->declBit(c+43,"Top alu sltu_result", false,-1);
        tracep->declBit(c+44,"Top alu slt_result", false,-1);
        tracep->declBus(c+45,"Top alu shamt", false,-1, 4,0);
        tracep->declBus(c+46,"Top alu sll_result", false,-1, 31,0);
        tracep->declBus(c+47,"Top alu sra_result", false,-1, 31,0);
        tracep->declBus(c+48,"Top alu srl_result", false,-1, 31,0);
        tracep->declBus(c+6,"Top idu io_inst", false,-1, 31,0);
        tracep->declBus(c+7,"Top idu io_br_type", false,-1, 3,0);
        tracep->declBus(c+8,"Top idu io_op1_sel", false,-1, 1,0);
        tracep->declBus(c+9,"Top idu io_op2_sel", false,-1, 1,0);
        tracep->declBus(c+1,"Top idu io_alu_op", false,-1, 5,0);
        tracep->declBus(c+10,"Top idu io_wb_sel", false,-1, 1,0);
        tracep->declBit(c+11,"Top idu io_rf_wen", false,-1);
        tracep->declBit(c+12,"Top idu io_mem_en", false,-1);
        tracep->declBit(c+13,"Top idu io_mem_fcn", false,-1);
        tracep->declBus(c+14,"Top idu io_mem_msk", false,-1, 2,0);
        tracep->declBus(c+49,"Top idu csignals_4", false,-1, 4,0);
        tracep->declBit(c+86,"Top rf clock", false,-1);
        tracep->declBus(c+15,"Top rf io_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+16,"Top rf io_rs1_data", false,-1, 31,0);
        tracep->declBus(c+17,"Top rf io_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+18,"Top rf io_rs2_data", false,-1, 31,0);
        tracep->declBus(c+19,"Top rf io_waddr", false,-1, 4,0);
        tracep->declBus(c+20,"Top rf io_wdata", false,-1, 31,0);
        tracep->declBit(c+11,"Top rf io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+54+i*1,"Top rf regfile", true,(i+0), 31,0);}}
        tracep->declBus(c+50,"Top rf regfile__T_24_data", false,-1, 31,0);
        tracep->declBus(c+15,"Top rf regfile__T_24_addr", false,-1, 4,0);
        tracep->declBus(c+51,"Top rf regfile__T_29_data", false,-1, 31,0);
        tracep->declBus(c+17,"Top rf regfile__T_29_addr", false,-1, 4,0);
        tracep->declBus(c+20,"Top rf regfile__T_21_data", false,-1, 31,0);
        tracep->declBus(c+19,"Top rf regfile__T_21_addr", false,-1, 4,0);
        tracep->declBit(c+111,"Top rf regfile__T_21_mask", false,-1);
        tracep->declBit(c+11,"Top rf regfile__T_21_en", false,-1);
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
        tracep->fullIData(oldp+2,(vlTOPp->Top__DOT__alu_io_in1),32);
        tracep->fullIData(oldp+3,(vlTOPp->Top__DOT__alu_io_in2),32);
        tracep->fullIData(oldp+4,(vlTOPp->Top__DOT__alu_io_out),32);
        tracep->fullBit(oldp+5,((0U == vlTOPp->Top__DOT__alu_io_out)));
        tracep->fullIData(oldp+6,(vlTOPp->Top__DOT__idu_io_inst),32);
        tracep->fullCData(oldp+7,(vlTOPp->Top__DOT__idu_io_br_type),4);
        tracep->fullCData(oldp+8,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
        tracep->fullCData(oldp+9,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
        tracep->fullCData(oldp+10,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
        tracep->fullBit(oldp+11,(vlTOPp->Top__DOT__idu_io_rf_wen));
        tracep->fullBit(oldp+12,(vlTOPp->Top__DOT__idu_io_mem_en));
        tracep->fullBit(oldp+13,(vlTOPp->Top__DOT__idu_io_mem_fcn));
        tracep->fullCData(oldp+14,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
        tracep->fullCData(oldp+15,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xfU))),5);
        tracep->fullIData(oldp+16,(vlTOPp->Top__DOT__rf_io_rs1_data),32);
        tracep->fullCData(oldp+17,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0x14U))),5);
        tracep->fullIData(oldp+18,(vlTOPp->Top__DOT__rf_io_rs2_data),32);
        tracep->fullCData(oldp+19,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 7U))),5);
        tracep->fullIData(oldp+20,(vlTOPp->Top__DOT__rf_io_wdata),32);
        tracep->fullBit(oldp+21,(vlTOPp->Top__DOT__stall));
        tracep->fullSData(oldp+22,((0xfffU & (vlTOPp->Top__DOT__idu_io_inst 
                                              >> 0x14U))),12);
        tracep->fullSData(oldp+23,(vlTOPp->Top__DOT__imm_s),12);
        tracep->fullSData(oldp+24,(vlTOPp->Top__DOT__imm_b),12);
        tracep->fullIData(oldp+25,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xcU))),20);
        tracep->fullIData(oldp+26,(vlTOPp->Top__DOT__imm_j),20);
        tracep->fullIData(oldp+27,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                             >> 0xfU))),32);
        tracep->fullIData(oldp+28,(vlTOPp->Top__DOT__imm_i_sext),32);
        tracep->fullIData(oldp+29,(vlTOPp->Top__DOT__imm_s_sext),32);
        tracep->fullIData(oldp+30,((vlTOPp->Top__DOT___T_150 
                                    << 1U)),32);
        tracep->fullIData(oldp+31,((0xfffff000U & vlTOPp->Top__DOT__idu_io_inst)),32);
        tracep->fullIData(oldp+32,((vlTOPp->Top__DOT___T_162 
                                    << 1U)),32);
        tracep->fullIData(oldp+33,((IData)(vlTOPp->Top__DOT___T_187)),32);
        tracep->fullIData(oldp+34,((IData)(vlTOPp->Top__DOT___T_188)),32);
        tracep->fullIData(oldp+35,((IData)(vlTOPp->Top__DOT___T_189)),32);
        tracep->fullBit(oldp+36,(vlTOPp->Top__DOT__br_taken));
        tracep->fullIData(oldp+37,(vlTOPp->Top__DOT__pc_next),32);
        tracep->fullQData(oldp+38,(vlTOPp->Top__DOT__alu__DOT__add_result),33);
        tracep->fullIData(oldp+40,(vlTOPp->Top__DOT__alu__DOT__xor_result),32);
        tracep->fullIData(oldp+41,(vlTOPp->Top__DOT__alu__DOT__or_result),32);
        tracep->fullIData(oldp+42,(vlTOPp->Top__DOT__alu__DOT__and_result),32);
        tracep->fullBit(oldp+43,((1U & (~ (IData)((vlTOPp->Top__DOT__alu__DOT__add_result 
                                                   >> 0x20U))))));
        tracep->fullBit(oldp+44,(vlTOPp->Top__DOT__alu__DOT__slt_result));
        tracep->fullCData(oldp+45,((0x1fU & vlTOPp->Top__DOT__alu_io_in2)),5);
        tracep->fullIData(oldp+46,((IData)(vlTOPp->Top__DOT__alu__DOT___T_23)),32);
        tracep->fullIData(oldp+47,(vlTOPp->Top__DOT__alu__DOT___T_25),32);
        tracep->fullIData(oldp+48,(vlTOPp->Top__DOT__alu__DOT__srl_result),32);
        tracep->fullCData(oldp+49,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
        tracep->fullIData(oldp+50,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data),32);
        tracep->fullIData(oldp+51,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data),32);
        tracep->fullIData(oldp+52,(vlTOPp->Top__DOT__pc_reg),32);
        tracep->fullIData(oldp+53,(((IData)(4U) + vlTOPp->Top__DOT__pc_reg)),32);
        tracep->fullIData(oldp+54,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),32);
        tracep->fullIData(oldp+55,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),32);
        tracep->fullIData(oldp+56,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),32);
        tracep->fullIData(oldp+57,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),32);
        tracep->fullIData(oldp+58,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),32);
        tracep->fullIData(oldp+59,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),32);
        tracep->fullIData(oldp+60,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),32);
        tracep->fullIData(oldp+61,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),32);
        tracep->fullIData(oldp+62,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),32);
        tracep->fullIData(oldp+63,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),32);
        tracep->fullIData(oldp+64,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),32);
        tracep->fullIData(oldp+65,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),32);
        tracep->fullIData(oldp+66,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),32);
        tracep->fullIData(oldp+67,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),32);
        tracep->fullIData(oldp+68,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),32);
        tracep->fullIData(oldp+69,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),32);
        tracep->fullIData(oldp+70,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),32);
        tracep->fullIData(oldp+71,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),32);
        tracep->fullIData(oldp+72,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),32);
        tracep->fullIData(oldp+73,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),32);
        tracep->fullIData(oldp+74,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),32);
        tracep->fullIData(oldp+75,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),32);
        tracep->fullIData(oldp+76,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),32);
        tracep->fullIData(oldp+77,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),32);
        tracep->fullIData(oldp+78,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),32);
        tracep->fullIData(oldp+79,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),32);
        tracep->fullIData(oldp+80,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),32);
        tracep->fullIData(oldp+81,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),32);
        tracep->fullIData(oldp+82,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),32);
        tracep->fullIData(oldp+83,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),32);
        tracep->fullIData(oldp+84,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),32);
        tracep->fullIData(oldp+85,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),32);
        tracep->fullBit(oldp+86,(vlTOPp->clock));
        tracep->fullBit(oldp+87,(vlTOPp->reset));
        tracep->fullBit(oldp+88,(vlTOPp->io_imem_req_ready));
        tracep->fullBit(oldp+89,(vlTOPp->io_imem_req_valid));
        tracep->fullIData(oldp+90,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->fullIData(oldp+91,(vlTOPp->io_imem_req_bits_data),32);
        tracep->fullBit(oldp+92,(vlTOPp->io_imem_req_bits_fcn));
        tracep->fullCData(oldp+93,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->fullBit(oldp+94,(vlTOPp->io_imem_resp_ready));
        tracep->fullBit(oldp+95,(vlTOPp->io_imem_resp_valid));
        tracep->fullIData(oldp+96,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->fullBit(oldp+97,(vlTOPp->io_dmem_req_ready));
        tracep->fullBit(oldp+98,(vlTOPp->io_dmem_req_valid));
        tracep->fullIData(oldp+99,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->fullIData(oldp+100,(vlTOPp->io_dmem_req_bits_data),32);
        tracep->fullBit(oldp+101,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->fullCData(oldp+102,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->fullBit(oldp+103,(vlTOPp->io_dmem_resp_ready));
        tracep->fullBit(oldp+104,(vlTOPp->io_dmem_resp_valid));
        tracep->fullIData(oldp+105,(vlTOPp->io_dmem_resp_bits_data),32);
        tracep->fullBit(oldp+106,(vlTOPp->io_debug_io_wen));
        tracep->fullCData(oldp+107,(vlTOPp->io_debug_io_waddr),5);
        tracep->fullIData(oldp+108,(vlTOPp->io_debug_io_wdata),32);
        tracep->fullIData(oldp+109,(vlTOPp->io_debug_io_PC),32);
        tracep->fullBit(oldp+110,(vlTOPp->io_debug_io_stall));
        tracep->fullBit(oldp+111,(1U));
    }
}
