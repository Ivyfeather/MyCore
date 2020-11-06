// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VTop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->Top__DOT__imem_req_ready));
            tracep->chgBit(oldp+1,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__imem_req_r));
            tracep->chgQData(oldp+2,((0xfffffffffffffff8ULL 
                                      & vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc)),64);
            tracep->chgBit(oldp+4,(vlTOPp->Top__DOT__imem_resp_valid));
            tracep->chgQData(oldp+5,(vlTOPp->Top__DOT__imem_resp_bits_data),64);
            tracep->chgBit(oldp+7,(vlTOPp->Top__DOT__dmem_req_ready));
            tracep->chgBit(oldp+8,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
            tracep->chgQData(oldp+9,((0xfffffffffffffff8ULL 
                                      & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
            tracep->chgQData(oldp+11,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
            tracep->chgBit(oldp+13,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
            tracep->chgCData(oldp+14,((0xffU & vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__dmem_resp_valid));
            tracep->chgQData(oldp+16,(vlTOPp->Top__DOT__dmem_resp_bits_data),64);
            tracep->chgQData(oldp+18,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+20,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+22,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+24,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+26,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+28,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+30,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+32,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+34,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+36,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+38,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+40,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+42,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+44,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+46,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+48,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+50,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+52,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+54,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+56,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+58,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+60,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+62,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+64,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+66,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+68,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+70,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+72,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+74,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+76,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+78,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+80,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+82,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC),64);
            tracep->chgBit(oldp+84,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__is_commit));
            tracep->chgBit(oldp+85,((0x6bU == (0x707fU 
                                               & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst))));
            tracep->chgBit(oldp+86,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
            tracep->chgBit(oldp+87,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
            tracep->chgQData(oldp+88,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
            tracep->chgBit(oldp+90,((1U & (IData)((vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                   >> 2U)))));
            tracep->chgBit(oldp+91,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
            tracep->chgQData(oldp+92,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
            tracep->chgBit(oldp+94,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
            tracep->chgBit(oldp+95,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
            tracep->chgQData(oldp+96,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
            tracep->chgIData(oldp+98,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
            tracep->chgBit(oldp+99,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
            tracep->chgBit(oldp+100,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
            tracep->chgQData(oldp+101,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
            tracep->chgIData(oldp+103,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
            tracep->chgCData(oldp+104,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
            tracep->chgCData(oldp+105,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
            tracep->chgCData(oldp+106,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
            tracep->chgCData(oldp+107,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
            tracep->chgBit(oldp+108,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
            tracep->chgBit(oldp+109,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
            tracep->chgBit(oldp+110,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
            tracep->chgCData(oldp+111,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
            tracep->chgQData(oldp+112,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+114,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+116,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
            tracep->chgCData(oldp+117,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
            tracep->chgQData(oldp+118,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
            tracep->chgBit(oldp+120,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
            tracep->chgCData(oldp+121,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
            tracep->chgQData(oldp+122,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
            tracep->chgBit(oldp+124,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
            tracep->chgCData(oldp+125,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 7U))),5);
            tracep->chgQData(oldp+126,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
            tracep->chgCData(oldp+128,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
            tracep->chgBit(oldp+129,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fes_ready));
            tracep->chgBit(oldp+130,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
            tracep->chgQData(oldp+131,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
            tracep->chgCData(oldp+133,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
            tracep->chgCData(oldp+134,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
            tracep->chgBit(oldp+135,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_valid));
            tracep->chgQData(oldp+136,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
            tracep->chgBit(oldp+138,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
            tracep->chgQData(oldp+139,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
            tracep->chgQData(oldp+141,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
            tracep->chgQData(oldp+143,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc),64);
            tracep->chgBit(oldp+145,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
            tracep->chgBit(oldp+146,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
            tracep->chgBit(oldp+147,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
            tracep->chgCData(oldp+148,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+149,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x14U))),5);
            tracep->chgBit(oldp+150,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
            tracep->chgCData(oldp+151,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
            tracep->chgBit(oldp+152,((1U & (~ (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
            tracep->chgBit(oldp+153,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
            tracep->chgSData(oldp+154,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+155,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+156,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 7U))));
            tracep->chgCData(oldp+157,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+158,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                >> 8U))),4);
            tracep->chgSData(oldp+159,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
            tracep->chgCData(oldp+160,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+161,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+162,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+163,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
            tracep->chgQData(oldp+164,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+166,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+168,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+170,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
            tracep->chgQData(oldp+173,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+175,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
            tracep->chgWData(oldp+178,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
            tracep->chgWData(oldp+181,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
            tracep->chgQData(oldp+184,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
            tracep->chgBit(oldp+186,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
            tracep->chgBit(oldp+187,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
            tracep->chgBit(oldp+188,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
            tracep->chgCData(oldp+189,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
            tracep->chgQData(oldp+190,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+192,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+194,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
            tracep->chgQData(oldp+195,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+197,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+199,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+201,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+203,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+205,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+207,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+209,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+211,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+213,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+215,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+217,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+219,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+221,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+223,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+225,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+227,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+229,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+231,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+233,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+235,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+237,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+239,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+241,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+243,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+245,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+247,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+249,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+251,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+253,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+255,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+257,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+259,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+261,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
            tracep->chgCData(oldp+263,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
            tracep->chgQData(oldp+264,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+266,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+268,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
            tracep->chgIData(oldp+270,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
            tracep->chgCData(oldp+271,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
            tracep->chgCData(oldp+272,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
            tracep->chgBit(oldp+273,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
            tracep->chgQData(oldp+274,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
            tracep->chgQData(oldp+276,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
            tracep->chgBit(oldp+278,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
            tracep->chgBit(oldp+279,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
            tracep->chgSData(oldp+280,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+281,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0x19U))),7);
            tracep->chgSData(oldp+282,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
            tracep->chgIData(oldp+283,((0xfffffU & 
                                        (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+284,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgIData(oldp+285,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+286,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+288,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+290,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+292,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
            tracep->chgIData(oldp+294,(((0x800000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+295,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
            tracep->chgBit(oldp+297,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
            tracep->chgCData(oldp+298,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
            tracep->chgCData(oldp+299,((0x38U & ((IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                                 << 3U))),7);
            tracep->chgQData(oldp+300,((0x1fffffffffffffffULL 
                                        & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out 
                                           >> 3U))),61);
            tracep->chgQData(oldp+302,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
            tracep->chgWData(oldp+304,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
            tracep->chgQData(oldp+307,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+309,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+311,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+313,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+314,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+315,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+316,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
            tracep->chgQData(oldp+318,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+320,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
            tracep->chgCData(oldp+322,((0x1fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
            tracep->chgIData(oldp+323,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
            tracep->chgIData(oldp+324,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
            tracep->chgIData(oldp+325,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
            tracep->chgQData(oldp+326,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgIData(oldp+328,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
            tracep->chgIData(oldp+329,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+330,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+331,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+332,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgCData(oldp+333,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
            tracep->chgBit(oldp+334,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
            tracep->chgCData(oldp+335,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
            tracep->chgQData(oldp+336,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
            tracep->chgCData(oldp+338,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
            tracep->chgBit(oldp+339,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
            tracep->chgCData(oldp+340,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
            tracep->chgBit(oldp+341,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
            tracep->chgBit(oldp+342,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_ready_go));
            tracep->chgQData(oldp+343,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data),64);
            tracep->chgCData(oldp+345,((0xffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),8);
            tracep->chgQData(oldp+346,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 7U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgSData(oldp+348,((0xffffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),16);
            tracep->chgQData(oldp+349,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0xfU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgIData(oldp+351,((IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data)),32);
            tracep->chgIData(oldp+352,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0x1fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+353,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__load_final),64);
            tracep->chgBit(oldp+355,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
        }
        tracep->chgBit(oldp+356,(vlTOPp->clock));
        tracep->chgBit(oldp+357,(vlTOPp->reset));
        tracep->chgBit(oldp+358,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+359,(vlTOPp->io_imem_req_valid));
        tracep->chgQData(oldp+360,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->chgQData(oldp+362,(vlTOPp->io_imem_req_bits_data),64);
        tracep->chgBit(oldp+364,(vlTOPp->io_imem_req_bits_wr));
        tracep->chgCData(oldp+365,(vlTOPp->io_imem_req_bits_msk),8);
        tracep->chgBit(oldp+366,(vlTOPp->io_imem_resp_valid));
        tracep->chgQData(oldp+367,(vlTOPp->io_imem_resp_bits_data),64);
        tracep->chgBit(oldp+369,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+370,(vlTOPp->io_dmem_req_valid));
        tracep->chgQData(oldp+371,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->chgQData(oldp+373,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+375,(vlTOPp->io_dmem_req_bits_wr));
        tracep->chgCData(oldp+376,(vlTOPp->io_dmem_req_bits_msk),8);
        tracep->chgBit(oldp+377,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+378,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgQData(oldp+380,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+382,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+384,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+386,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+388,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+390,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+392,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+394,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+396,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+398,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+400,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+402,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+404,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+406,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+408,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+410,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+412,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+414,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+416,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+418,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+420,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+422,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+424,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+426,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+428,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+430,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+432,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+434,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+436,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+438,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+440,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+442,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+444,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+446,(vlTOPp->io_debug_valid));
        tracep->chgBit(oldp+447,(vlTOPp->io_debug_trap));
        tracep->chgQData(oldp+448,(vlTOPp->io_debug_test),64);
    }
}

void VTop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
