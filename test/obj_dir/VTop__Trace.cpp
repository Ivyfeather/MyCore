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
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->Soc__DOT__ram__DOT__j),32);
            tracep->chgIData(oldp+1,(vlTOPp->Soc__DOT__ram__DOT__mem_file),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+2,(vlTOPp->Soc__DOT__bridge_inst_addr_ok));
            tracep->chgBit(oldp+3,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__imem_req_r));
            tracep->chgQData(oldp+4,((0xfffffffffffffff8ULL 
                                      & vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__nextpc)),64);
            tracep->chgBit(oldp+6,(vlTOPp->Soc__DOT__bridge_inst_data_ok));
            tracep->chgQData(oldp+7,(vlSymsp->TOP__Soc__DOT__ram__DOT__ed1.out),64);
            tracep->chgBit(oldp+9,((1U & (~ (IData)(vlTOPp->Soc__DOT__bridge__DOT__do_req)))));
            tracep->chgBit(oldp+10,(vlTOPp->Soc__DOT__core__DOT__es_top_io_dmem_req_valid));
            tracep->chgQData(oldp+11,((0xfffffffffffffff8ULL 
                                       & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
            tracep->chgQData(oldp+13,((((QData)((IData)(
                                                        vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
            tracep->chgBit(oldp+15,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
            tracep->chgCData(oldp+16,((0xffU & vlTOPp->Soc__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
            tracep->chgBit(oldp+17,(vlTOPp->Soc__DOT__bridge_data_data_ok));
            tracep->chgQData(oldp+18,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+20,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+22,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+24,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+26,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+28,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+30,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+32,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+34,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+36,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+38,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+40,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+42,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+44,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+46,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+48,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+50,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+52,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+54,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+56,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+58,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+60,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+62,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+64,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+66,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+68,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+70,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+72,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+74,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+76,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+78,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+80,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+82,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC),64);
            tracep->chgBit(oldp+84,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__is_commit));
            tracep->chgBit(oldp+85,((0x6bU == (0x707fU 
                                               & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst))));
            tracep->chgQData(oldp+86,(vlTOPp->Soc__DOT__bridge__DOT__do_addr_r),64);
            tracep->chgBit(oldp+88,(vlTOPp->Soc__DOT__bridge_awvalid));
            tracep->chgBit(oldp+89,(vlTOPp->Soc__DOT__ram__DOT__awready_reg));
            tracep->chgQData(oldp+90,(vlTOPp->Soc__DOT__bridge__DOT__do_wdata_r),64);
            tracep->chgCData(oldp+92,(vlTOPp->Soc__DOT__bridge__DOT__do_size_r),8);
            tracep->chgBit(oldp+93,(vlTOPp->Soc__DOT__bridge_wvalid));
            tracep->chgBit(oldp+94,(vlTOPp->Soc__DOT__ram__DOT__wready_reg));
            tracep->chgCData(oldp+95,(vlTOPp->Soc__DOT__ram__DOT__bid_reg),8);
            tracep->chgBit(oldp+96,(vlTOPp->Soc__DOT__ram__DOT__bvalid_reg));
            tracep->chgBit(oldp+97,(vlTOPp->Soc__DOT__bridge_arvalid));
            tracep->chgBit(oldp+98,(vlTOPp->Soc__DOT__ram__DOT__arready_reg));
            tracep->chgCData(oldp+99,(vlTOPp->Soc__DOT__ram__DOT__rid_reg),8);
            tracep->chgBit(oldp+100,(vlTOPp->Soc__DOT__ram__DOT__rlast_reg));
            tracep->chgBit(oldp+101,(vlTOPp->Soc__DOT__ram__DOT__rvalid_reg));
            tracep->chgBit(oldp+102,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_pres_ready));
            tracep->chgBit(oldp+103,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_ready_go));
            tracep->chgQData(oldp+104,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc),64);
            tracep->chgBit(oldp+106,((1U & (IData)(
                                                   (vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                    >> 2U)))));
            tracep->chgBit(oldp+107,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__br_taken));
            tracep->chgQData(oldp+108,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05FPC),64);
            tracep->chgCData(oldp+110,((3U & (IData)(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___insts_sent_after_br_T_4))),2);
            tracep->chgQData(oldp+111,((((QData)((IData)(
                                                         vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Soc__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
            tracep->chgBit(oldp+113,(vlTOPp->Soc__DOT__core__DOT__ds_top_io_fs_ready));
            tracep->chgBit(oldp+114,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_valid));
            tracep->chgQData(oldp+115,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
            tracep->chgIData(oldp+117,(vlTOPp->Soc__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
            tracep->chgBit(oldp+118,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ds_ready));
            tracep->chgBit(oldp+119,(vlTOPp->Soc__DOT__core__DOT__ds_top_io_es_valid));
            tracep->chgIData(oldp+120,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst),32);
            tracep->chgCData(oldp+121,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
            tracep->chgCData(oldp+122,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
            tracep->chgCData(oldp+123,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
            tracep->chgCData(oldp+124,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
            tracep->chgBit(oldp+125,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
            tracep->chgBit(oldp+126,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
            tracep->chgBit(oldp+127,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
            tracep->chgCData(oldp+128,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
            tracep->chgQData(oldp+129,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+131,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+133,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
            tracep->chgCData(oldp+134,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
            tracep->chgQData(oldp+135,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
            tracep->chgBit(oldp+137,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
            tracep->chgCData(oldp+138,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
            tracep->chgQData(oldp+139,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
            tracep->chgBit(oldp+141,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
            tracep->chgCData(oldp+142,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 7U))),5);
            tracep->chgQData(oldp+143,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
            tracep->chgCData(oldp+145,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
            tracep->chgBit(oldp+146,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fes_ready));
            tracep->chgBit(oldp+147,(vlTOPp->Soc__DOT__core__DOT__es_top_io_ms_valid));
            tracep->chgQData(oldp+148,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
            tracep->chgCData(oldp+150,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
            tracep->chgCData(oldp+151,((7U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
            tracep->chgBit(oldp+152,(vlTOPp->Soc__DOT__core__DOT__ms_top_io___05Fws_valid));
            tracep->chgQData(oldp+153,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
            tracep->chgBit(oldp+155,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__buf_valid));
            tracep->chgQData(oldp+156,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__buf_npc),64);
            tracep->chgQData(oldp+158,((4ULL + vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
            tracep->chgQData(oldp+160,(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT__nextpc),64);
            tracep->chgQData(oldp+162,((0x3fffffffffffffffULL 
                                        & (vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___T_3 
                                           >> 2U))),64);
            tracep->chgBit(oldp+164,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
            tracep->chgBit(oldp+165,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__fs_ready_go));
            tracep->chgBit(oldp+166,(vlTOPp->Soc__DOT__core__DOT__fs_top__DOT__fs_valid));
            tracep->chgCData(oldp+167,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+168,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                 >> 0x14U))),5);
            tracep->chgBit(oldp+169,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
            tracep->chgCData(oldp+170,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
            tracep->chgBit(oldp+171,((1U & (~ (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
            tracep->chgBit(oldp+172,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__ds_valid));
            tracep->chgSData(oldp+173,((0xfffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+174,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+175,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                            >> 7U))));
            tracep->chgCData(oldp+176,((0x3fU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+177,((0xfU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                >> 8U))),4);
            tracep->chgSData(oldp+178,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b),12);
            tracep->chgCData(oldp+179,((0xffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+180,((1U & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+181,((0x3ffU & (vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+182,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j),20);
            tracep->chgQData(oldp+183,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__from_fs_r___05Finst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+185,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+187,(((0x800U & (IData)(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+189,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
            tracep->chgQData(oldp+192,(((0x80000U & vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+194,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
            tracep->chgWData(oldp+197,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__branch_target),66);
            tracep->chgWData(oldp+200,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jmp_target),74);
            tracep->chgQData(oldp+203,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__jr_target),64);
            tracep->chgBit(oldp+205,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_eq));
            tracep->chgBit(oldp+206,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_lt));
            tracep->chgBit(oldp+207,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf_ltu));
            tracep->chgBit(oldp+208,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_set));
            tracep->chgCData(oldp+209,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__flush_reg),2);
            tracep->chgBit(oldp+210,((1U & (IData)(vlTOPp->Soc__DOT__core__DOT__pre_top__DOT___insts_sent_after_br_T_4))));
            tracep->chgQData(oldp+211,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+213,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+215,((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
            tracep->chgQData(oldp+216,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+218,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+220,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+222,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+224,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+226,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+228,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+230,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+232,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+234,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+236,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+238,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+240,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+242,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+244,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+246,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+248,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+250,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+252,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+254,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+256,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+258,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+260,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+262,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+264,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+266,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+268,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+270,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+272,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+274,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+276,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+278,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+280,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+282,(vlTOPp->Soc__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
            tracep->chgCData(oldp+284,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
            tracep->chgQData(oldp+285,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+287,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+289,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out),64);
            tracep->chgIData(oldp+291,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
            tracep->chgCData(oldp+292,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
            tracep->chgCData(oldp+293,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
            tracep->chgBit(oldp+294,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
            tracep->chgQData(oldp+295,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
            tracep->chgQData(oldp+297,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
            tracep->chgBit(oldp+299,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__es_ready_go));
            tracep->chgBit(oldp+300,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__es_valid));
            tracep->chgSData(oldp+301,((0xfffU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+302,((0x7fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0x19U))),7);
            tracep->chgSData(oldp+303,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s),12);
            tracep->chgIData(oldp+304,((0xfffffU & 
                                        (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+305,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgIData(oldp+306,((0x1fU & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+307,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+309,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+311,(((0x800U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+313,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
            tracep->chgIData(oldp+315,(((0x800000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+316,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
            tracep->chgBit(oldp+318,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__dmem_req_r));
            tracep->chgCData(oldp+319,((7U & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
            tracep->chgCData(oldp+320,((0x38U & ((IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                                 << 3U))),7);
            tracep->chgQData(oldp+321,((0x1fffffffffffffffULL 
                                        & (vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_out 
                                           >> 3U))),61);
            tracep->chgQData(oldp+323,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
            tracep->chgWData(oldp+325,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
            tracep->chgQData(oldp+328,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+330,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+332,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+334,((1U & (~ vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+335,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+336,((0x3fU & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+337,((((QData)((IData)(
                                                         vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
            tracep->chgQData(oldp+339,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+341,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
            tracep->chgCData(oldp+343,((0x1fU & (IData)(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
            tracep->chgIData(oldp+344,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
            tracep->chgIData(oldp+345,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
            tracep->chgIData(oldp+346,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
            tracep->chgQData(oldp+347,((((QData)((IData)(
                                                         vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgIData(oldp+349,(vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
            tracep->chgIData(oldp+350,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+351,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+352,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+353,(((0x80000000U 
                                         & vlTOPp->Soc__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgCData(oldp+354,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
            tracep->chgBit(oldp+355,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
            tracep->chgCData(oldp+356,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
            tracep->chgQData(oldp+357,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
            tracep->chgCData(oldp+359,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
            tracep->chgBit(oldp+360,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__ms_valid));
            tracep->chgCData(oldp+361,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
            tracep->chgBit(oldp+362,((1U == (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
            tracep->chgBit(oldp+363,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__ms_ready_go));
            tracep->chgQData(oldp+364,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data),64);
            tracep->chgCData(oldp+366,((0xffU & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))),8);
            tracep->chgQData(oldp+367,(((1U & (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 7U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgSData(oldp+369,((0xffffU & (IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data))),16);
            tracep->chgQData(oldp+370,(((1U & (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0xfU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgIData(oldp+372,((IData)(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data)),32);
            tracep->chgIData(oldp+373,(((1U & (IData)(
                                                      (vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0x1fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+374,(vlTOPp->Soc__DOT__core__DOT__ms_top__DOT__load_final),64);
            tracep->chgBit(oldp+376,(vlTOPp->Soc__DOT__core__DOT__ws_top__DOT__REG));
            tracep->chgIData(oldp+377,((0xfffffU & (IData)(vlTOPp->Soc__DOT__bridge__DOT__do_addr_r))),20);
            tracep->chgBit(oldp+378,(vlTOPp->Soc__DOT__ram__DOT__read_state_reg));
            tracep->chgBit(oldp+379,(vlTOPp->Soc__DOT__ram__DOT__read_state_next));
            tracep->chgCData(oldp+380,(vlTOPp->Soc__DOT__ram__DOT__write_state_reg),2);
            tracep->chgCData(oldp+381,(vlTOPp->Soc__DOT__ram__DOT__write_state_next),2);
            tracep->chgBit(oldp+382,(vlTOPp->Soc__DOT__ram__DOT__mem_wr_en));
            tracep->chgBit(oldp+383,(vlTOPp->Soc__DOT__ram__DOT__mem_rd_en));
            tracep->chgCData(oldp+384,(vlTOPp->Soc__DOT__ram__DOT__read_id_reg),8);
            tracep->chgCData(oldp+385,(vlTOPp->Soc__DOT__ram__DOT__read_id_next),8);
            tracep->chgIData(oldp+386,(vlTOPp->Soc__DOT__ram__DOT__read_addr_reg),20);
            tracep->chgIData(oldp+387,(vlTOPp->Soc__DOT__ram__DOT__read_addr_next),20);
            tracep->chgCData(oldp+388,(vlTOPp->Soc__DOT__ram__DOT__read_count_reg),8);
            tracep->chgCData(oldp+389,(vlTOPp->Soc__DOT__ram__DOT__read_count_next),8);
            tracep->chgCData(oldp+390,(vlTOPp->Soc__DOT__ram__DOT__read_size_reg),3);
            tracep->chgCData(oldp+391,(vlTOPp->Soc__DOT__ram__DOT__read_size_next),3);
            tracep->chgCData(oldp+392,(vlTOPp->Soc__DOT__ram__DOT__read_burst_reg),2);
            tracep->chgCData(oldp+393,(vlTOPp->Soc__DOT__ram__DOT__read_burst_next),2);
            tracep->chgCData(oldp+394,(vlTOPp->Soc__DOT__ram__DOT__write_id_reg),8);
            tracep->chgCData(oldp+395,(vlTOPp->Soc__DOT__ram__DOT__write_id_next),8);
            tracep->chgIData(oldp+396,(vlTOPp->Soc__DOT__ram__DOT__write_addr_reg),20);
            tracep->chgIData(oldp+397,(vlTOPp->Soc__DOT__ram__DOT__write_addr_next),20);
            tracep->chgCData(oldp+398,(vlTOPp->Soc__DOT__ram__DOT__write_count_reg),8);
            tracep->chgCData(oldp+399,(vlTOPp->Soc__DOT__ram__DOT__write_count_next),8);
            tracep->chgCData(oldp+400,(vlTOPp->Soc__DOT__ram__DOT__write_size_reg),3);
            tracep->chgCData(oldp+401,(vlTOPp->Soc__DOT__ram__DOT__write_size_next),3);
            tracep->chgCData(oldp+402,(vlTOPp->Soc__DOT__ram__DOT__write_burst_reg),2);
            tracep->chgCData(oldp+403,(vlTOPp->Soc__DOT__ram__DOT__write_burst_next),2);
            tracep->chgBit(oldp+404,(vlTOPp->Soc__DOT__ram__DOT__awready_next));
            tracep->chgBit(oldp+405,(vlTOPp->Soc__DOT__ram__DOT__wready_next));
            tracep->chgCData(oldp+406,(vlTOPp->Soc__DOT__ram__DOT__bid_next),8);
            tracep->chgBit(oldp+407,(vlTOPp->Soc__DOT__ram__DOT__bvalid_next));
            tracep->chgBit(oldp+408,(vlTOPp->Soc__DOT__ram__DOT__arready_next));
            tracep->chgCData(oldp+409,(vlTOPp->Soc__DOT__ram__DOT__rid_next),8);
            tracep->chgQData(oldp+410,(vlTOPp->Soc__DOT__ram__DOT__rdata_reg),64);
            tracep->chgBit(oldp+412,(vlTOPp->Soc__DOT__ram__DOT__rlast_next));
            tracep->chgBit(oldp+413,(vlTOPp->Soc__DOT__ram__DOT__rvalid_next));
            tracep->chgCData(oldp+414,(vlTOPp->Soc__DOT__ram__DOT__rid_pipe_reg),8);
            tracep->chgQData(oldp+415,(vlTOPp->Soc__DOT__ram__DOT__rdata_pipe_reg),64);
            tracep->chgBit(oldp+417,(vlTOPp->Soc__DOT__ram__DOT__rlast_pipe_reg));
            tracep->chgBit(oldp+418,(vlTOPp->Soc__DOT__ram__DOT__rvalid_pipe_reg));
            tracep->chgIData(oldp+419,((0x1ffffU & (IData)(
                                                           (vlTOPp->Soc__DOT__bridge__DOT__do_addr_r 
                                                            >> 3U)))),17);
            tracep->chgIData(oldp+420,((0x1ffffU & 
                                        (vlTOPp->Soc__DOT__ram__DOT__read_addr_reg 
                                         >> 3U))),17);
            tracep->chgIData(oldp+421,((0x1ffffU & 
                                        (vlTOPp->Soc__DOT__ram__DOT__write_addr_reg 
                                         >> 3U))),17);
            tracep->chgIData(oldp+422,(vlTOPp->Soc__DOT__ram__DOT__i),32);
            tracep->chgQData(oldp+423,(vlSymsp->TOP__Soc__DOT__ram__DOT__ed2.out),64);
            tracep->chgCData(oldp+425,((0xfU & (IData)(vlTOPp->Soc__DOT__ram__DOT__rid_reg))),4);
            tracep->chgCData(oldp+426,((0xfU & (IData)(vlTOPp->Soc__DOT__ram__DOT__bid_reg))),4);
            tracep->chgBit(oldp+427,(vlTOPp->Soc__DOT__bridge__DOT__do_req));
            tracep->chgBit(oldp+428,(vlTOPp->Soc__DOT__bridge__DOT__do_req_or));
            tracep->chgBit(oldp+429,(vlTOPp->Soc__DOT__bridge__DOT__do_wr_r));
            tracep->chgBit(oldp+430,(vlTOPp->Soc__DOT__bridge__DOT__data_back));
            tracep->chgBit(oldp+431,(vlTOPp->Soc__DOT__bridge__DOT__addr_rcv));
            tracep->chgBit(oldp+432,(vlTOPp->Soc__DOT__bridge__DOT__wdata_rcv));
        }
        tracep->chgBit(oldp+433,(vlTOPp->clock));
        tracep->chgBit(oldp+434,(vlTOPp->reset));
        tracep->chgQData(oldp+435,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+437,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+439,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+441,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+443,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+445,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+447,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+449,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+451,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+453,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+455,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+457,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+459,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+461,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+463,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+465,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+467,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+469,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+471,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+473,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+475,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+477,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+479,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+481,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+483,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+485,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+487,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+489,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+491,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+493,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+495,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+497,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+499,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+501,(vlTOPp->io_debug_valid));
        tracep->chgBit(oldp+502,(vlTOPp->io_debug_trap));
        tracep->chgQData(oldp+503,(vlTOPp->io_debug_test),64);
        tracep->chgBit(oldp+505,((1U & (~ (IData)(vlTOPp->reset)))));
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
