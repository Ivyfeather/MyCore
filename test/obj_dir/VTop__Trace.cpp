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
            tracep->chgIData(oldp+0,(vlTOPp->Top__DOT__ram__DOT__j),32);
            tracep->chgIData(oldp+1,(vlTOPp->Top__DOT__ram__DOT__mem_file),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+2,(vlTOPp->Top__DOT__bridge_inst_addr_ok));
            tracep->chgBit(oldp+3,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__imem_req_r));
            tracep->chgQData(oldp+4,((0xfffffffffffffff8ULL 
                                      & vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc)),64);
            tracep->chgBit(oldp+6,(vlTOPp->Top__DOT__bridge_inst_data_ok));
            tracep->chgQData(oldp+7,(vlTOPp->Top__DOT__ram__DOT__rdata_reg),64);
            tracep->chgBit(oldp+9,((1U & (~ (IData)(vlTOPp->Top__DOT__bridge__DOT__do_req)))));
            tracep->chgBit(oldp+10,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
            tracep->chgQData(oldp+11,((0xfffffffffffffff8ULL 
                                       & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out)),64);
            tracep->chgQData(oldp+13,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_data_T[0U])))),64);
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
            tracep->chgCData(oldp+16,((0xffU & vlTOPp->Top__DOT__core__DOT__es_top__DOT___io_dmem_req_bits_msk_T_8)),8);
            tracep->chgBit(oldp+17,(vlTOPp->Top__DOT__bridge_data_data_ok));
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
            tracep->chgQData(oldp+86,(vlTOPp->Top__DOT__bridge__DOT__do_addr_r),64);
            tracep->chgBit(oldp+88,(vlTOPp->Top__DOT__bridge_awvalid));
            tracep->chgBit(oldp+89,(vlTOPp->Top__DOT__ram__DOT__awready_reg));
            tracep->chgQData(oldp+90,(vlTOPp->Top__DOT__bridge__DOT__do_wdata_r),64);
            tracep->chgCData(oldp+92,(vlTOPp->Top__DOT__bridge__DOT__do_size_r),8);
            tracep->chgBit(oldp+93,(vlTOPp->Top__DOT__bridge_wvalid));
            tracep->chgBit(oldp+94,(vlTOPp->Top__DOT__ram__DOT__wready_reg));
            tracep->chgCData(oldp+95,(vlTOPp->Top__DOT__ram__DOT__bid_reg),8);
            tracep->chgBit(oldp+96,(vlTOPp->Top__DOT__ram__DOT__bvalid_reg));
            tracep->chgBit(oldp+97,(vlTOPp->Top__DOT__bridge_arvalid));
            tracep->chgBit(oldp+98,(vlTOPp->Top__DOT__ram__DOT__arready_reg));
            tracep->chgCData(oldp+99,(vlTOPp->Top__DOT__ram__DOT__rid_reg),8);
            tracep->chgBit(oldp+100,(vlTOPp->Top__DOT__ram__DOT__rlast_reg));
            tracep->chgBit(oldp+101,(vlTOPp->Top__DOT__ram__DOT__rvalid_reg));
            tracep->chgBit(oldp+102,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
            tracep->chgBit(oldp+103,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
            tracep->chgQData(oldp+104,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
            tracep->chgBit(oldp+106,((1U & (IData)(
                                                   (vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc 
                                                    >> 2U)))));
            tracep->chgBit(oldp+107,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
            tracep->chgQData(oldp+108,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
            tracep->chgBit(oldp+110,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
            tracep->chgBit(oldp+111,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
            tracep->chgQData(oldp+112,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
            tracep->chgIData(oldp+114,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_bits_inst),32);
            tracep->chgBit(oldp+115,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
            tracep->chgBit(oldp+116,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
            tracep->chgQData(oldp+117,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
            tracep->chgIData(oldp+119,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
            tracep->chgCData(oldp+120,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
            tracep->chgCData(oldp+121,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
            tracep->chgCData(oldp+122,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
            tracep->chgCData(oldp+123,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
            tracep->chgBit(oldp+124,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
            tracep->chgBit(oldp+125,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
            tracep->chgBit(oldp+126,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
            tracep->chgCData(oldp+127,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
            tracep->chgQData(oldp+128,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+130,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+132,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
            tracep->chgCData(oldp+133,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
            tracep->chgQData(oldp+134,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
            tracep->chgBit(oldp+136,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
            tracep->chgCData(oldp+137,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
            tracep->chgQData(oldp+138,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_bits_final_result),64);
            tracep->chgBit(oldp+140,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
            tracep->chgCData(oldp+141,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 7U))),5);
            tracep->chgQData(oldp+142,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
            tracep->chgCData(oldp+144,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
            tracep->chgBit(oldp+145,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fes_ready));
            tracep->chgBit(oldp+146,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
            tracep->chgQData(oldp+147,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
            tracep->chgCData(oldp+149,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
            tracep->chgCData(oldp+150,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),3);
            tracep->chgBit(oldp+151,(vlTOPp->Top__DOT__core__DOT__ms_top_io___05Fws_valid));
            tracep->chgQData(oldp+152,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
            tracep->chgBit(oldp+154,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
            tracep->chgQData(oldp+155,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
            tracep->chgQData(oldp+157,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
            tracep->chgQData(oldp+159,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__nextpc),64);
            tracep->chgBit(oldp+161,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_offset));
            tracep->chgBit(oldp+162,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
            tracep->chgBit(oldp+163,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
            tracep->chgCData(oldp+164,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+165,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x14U))),5);
            tracep->chgBit(oldp+166,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall));
            tracep->chgCData(oldp+167,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
            tracep->chgBit(oldp+168,((1U & (~ (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_wr_stall)))));
            tracep->chgBit(oldp+169,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
            tracep->chgSData(oldp+170,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+171,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+172,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 7U))));
            tracep->chgCData(oldp+173,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+174,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                >> 8U))),4);
            tracep->chgSData(oldp+175,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
            tracep->chgCData(oldp+176,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+177,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+178,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+179,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
            tracep->chgQData(oldp+180,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+182,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+184,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+186,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
            tracep->chgQData(oldp+189,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+191,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
            tracep->chgWData(oldp+194,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
            tracep->chgWData(oldp+197,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
            tracep->chgQData(oldp+200,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
            tracep->chgBit(oldp+202,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
            tracep->chgBit(oldp+203,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
            tracep->chgBit(oldp+204,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
            tracep->chgCData(oldp+205,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
            tracep->chgQData(oldp+206,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+208,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+210,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
            tracep->chgQData(oldp+211,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+213,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+215,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+217,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+219,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+221,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+223,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+225,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+227,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+229,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+231,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+233,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+235,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+237,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+239,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+241,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+243,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+245,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+247,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+249,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+251,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+253,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+255,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+257,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+259,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+261,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+263,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+265,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+267,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+269,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+271,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+273,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+275,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+277,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
            tracep->chgCData(oldp+279,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
            tracep->chgQData(oldp+280,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+282,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+284,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
            tracep->chgIData(oldp+286,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
            tracep->chgCData(oldp+287,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
            tracep->chgCData(oldp+288,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
            tracep->chgBit(oldp+289,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
            tracep->chgQData(oldp+290,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
            tracep->chgQData(oldp+292,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
            tracep->chgBit(oldp+294,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
            tracep->chgBit(oldp+295,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
            tracep->chgSData(oldp+296,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+297,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0x19U))),7);
            tracep->chgSData(oldp+298,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
            tracep->chgIData(oldp+299,((0xfffffU & 
                                        (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+300,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgIData(oldp+301,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+302,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+304,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+306,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+308,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
            tracep->chgIData(oldp+310,(((0x800000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+311,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
            tracep->chgBit(oldp+313,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
            tracep->chgCData(oldp+314,((7U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out))),4);
            tracep->chgCData(oldp+315,((0x38U & ((IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out) 
                                                 << 3U))),7);
            tracep->chgQData(oldp+316,((0x1fffffffffffffffULL 
                                        & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out 
                                           >> 3U))),61);
            tracep->chgQData(oldp+318,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add2),64);
            tracep->chgWData(oldp+320,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),66);
            tracep->chgQData(oldp+323,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+325,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+327,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+329,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+330,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+331,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+332,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_6[0U])))),64);
            tracep->chgQData(oldp+334,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+336,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
            tracep->chgCData(oldp+338,((0x1fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),5);
            tracep->chgIData(oldp+339,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U]),32);
            tracep->chgIData(oldp+340,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result),32);
            tracep->chgIData(oldp+341,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result),32);
            tracep->chgQData(oldp+342,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgIData(oldp+344,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U]),32);
            tracep->chgIData(oldp+345,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+346,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_9[0U])
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+347,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sraw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+348,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srlw_result)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgCData(oldp+349,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
            tracep->chgBit(oldp+350,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
            tracep->chgCData(oldp+351,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_msk),3);
            tracep->chgQData(oldp+352,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
            tracep->chgCData(oldp+354,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_load_offset),3);
            tracep->chgBit(oldp+355,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
            tracep->chgCData(oldp+356,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
            tracep->chgBit(oldp+357,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel))));
            tracep->chgBit(oldp+358,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_ready_go));
            tracep->chgQData(oldp+359,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data),64);
            tracep->chgCData(oldp+361,((0xffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),8);
            tracep->chgQData(oldp+362,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 7U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgSData(oldp+364,((0xffffU & (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data))),16);
            tracep->chgQData(oldp+365,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0xfU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgIData(oldp+367,((IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data)),32);
            tracep->chgIData(oldp+368,(((1U & (IData)(
                                                      (vlTOPp->Top__DOT__core__DOT__ms_top__DOT__data 
                                                       >> 0x1fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+369,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__load_final),64);
            tracep->chgBit(oldp+371,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
            tracep->chgIData(oldp+372,((0xfffffU & (IData)(vlTOPp->Top__DOT__bridge__DOT__do_addr_r))),20);
            tracep->chgBit(oldp+373,(vlTOPp->Top__DOT__ram__DOT__read_state_reg));
            tracep->chgBit(oldp+374,(vlTOPp->Top__DOT__ram__DOT__read_state_next));
            tracep->chgCData(oldp+375,(vlTOPp->Top__DOT__ram__DOT__write_state_reg),2);
            tracep->chgCData(oldp+376,(vlTOPp->Top__DOT__ram__DOT__write_state_next),2);
            tracep->chgBit(oldp+377,(vlTOPp->Top__DOT__ram__DOT__mem_wr_en));
            tracep->chgBit(oldp+378,(vlTOPp->Top__DOT__ram__DOT__mem_rd_en));
            tracep->chgCData(oldp+379,(vlTOPp->Top__DOT__ram__DOT__read_id_reg),8);
            tracep->chgCData(oldp+380,(vlTOPp->Top__DOT__ram__DOT__read_id_next),8);
            tracep->chgIData(oldp+381,(vlTOPp->Top__DOT__ram__DOT__read_addr_reg),20);
            tracep->chgIData(oldp+382,(vlTOPp->Top__DOT__ram__DOT__read_addr_next),20);
            tracep->chgCData(oldp+383,(vlTOPp->Top__DOT__ram__DOT__read_count_reg),8);
            tracep->chgCData(oldp+384,(vlTOPp->Top__DOT__ram__DOT__read_count_next),8);
            tracep->chgCData(oldp+385,(vlTOPp->Top__DOT__ram__DOT__read_size_reg),3);
            tracep->chgCData(oldp+386,(vlTOPp->Top__DOT__ram__DOT__read_size_next),3);
            tracep->chgCData(oldp+387,(vlTOPp->Top__DOT__ram__DOT__read_burst_reg),2);
            tracep->chgCData(oldp+388,(vlTOPp->Top__DOT__ram__DOT__read_burst_next),2);
            tracep->chgCData(oldp+389,(vlTOPp->Top__DOT__ram__DOT__write_id_reg),8);
            tracep->chgCData(oldp+390,(vlTOPp->Top__DOT__ram__DOT__write_id_next),8);
            tracep->chgIData(oldp+391,(vlTOPp->Top__DOT__ram__DOT__write_addr_reg),20);
            tracep->chgIData(oldp+392,(vlTOPp->Top__DOT__ram__DOT__write_addr_next),20);
            tracep->chgCData(oldp+393,(vlTOPp->Top__DOT__ram__DOT__write_count_reg),8);
            tracep->chgCData(oldp+394,(vlTOPp->Top__DOT__ram__DOT__write_count_next),8);
            tracep->chgCData(oldp+395,(vlTOPp->Top__DOT__ram__DOT__write_size_reg),3);
            tracep->chgCData(oldp+396,(vlTOPp->Top__DOT__ram__DOT__write_size_next),3);
            tracep->chgCData(oldp+397,(vlTOPp->Top__DOT__ram__DOT__write_burst_reg),2);
            tracep->chgCData(oldp+398,(vlTOPp->Top__DOT__ram__DOT__write_burst_next),2);
            tracep->chgBit(oldp+399,(vlTOPp->Top__DOT__ram__DOT__awready_next));
            tracep->chgBit(oldp+400,(vlTOPp->Top__DOT__ram__DOT__wready_next));
            tracep->chgCData(oldp+401,(vlTOPp->Top__DOT__ram__DOT__bid_next),8);
            tracep->chgBit(oldp+402,(vlTOPp->Top__DOT__ram__DOT__bvalid_next));
            tracep->chgBit(oldp+403,(vlTOPp->Top__DOT__ram__DOT__arready_next));
            tracep->chgCData(oldp+404,(vlTOPp->Top__DOT__ram__DOT__rid_next),8);
            tracep->chgBit(oldp+405,(vlTOPp->Top__DOT__ram__DOT__rlast_next));
            tracep->chgBit(oldp+406,(vlTOPp->Top__DOT__ram__DOT__rvalid_next));
            tracep->chgCData(oldp+407,(vlTOPp->Top__DOT__ram__DOT__rid_pipe_reg),8);
            tracep->chgQData(oldp+408,(vlTOPp->Top__DOT__ram__DOT__rdata_pipe_reg),64);
            tracep->chgBit(oldp+410,(vlTOPp->Top__DOT__ram__DOT__rlast_pipe_reg));
            tracep->chgBit(oldp+411,(vlTOPp->Top__DOT__ram__DOT__rvalid_pipe_reg));
            tracep->chgIData(oldp+412,((0x1ffffU & (IData)(
                                                           (vlTOPp->Top__DOT__bridge__DOT__do_addr_r 
                                                            >> 3U)))),17);
            tracep->chgIData(oldp+413,((0x1ffffU & 
                                        (vlTOPp->Top__DOT__ram__DOT__read_addr_reg 
                                         >> 3U))),17);
            tracep->chgIData(oldp+414,((0x1ffffU & 
                                        (vlTOPp->Top__DOT__ram__DOT__write_addr_reg 
                                         >> 3U))),17);
            tracep->chgIData(oldp+415,(vlTOPp->Top__DOT__ram__DOT__i),32);
            tracep->chgCData(oldp+416,((0xfU & (IData)(vlTOPp->Top__DOT__ram__DOT__rid_reg))),4);
            tracep->chgCData(oldp+417,((0xfU & (IData)(vlTOPp->Top__DOT__ram__DOT__bid_reg))),4);
            tracep->chgBit(oldp+418,(vlTOPp->Top__DOT__bridge__DOT__do_req));
            tracep->chgBit(oldp+419,(vlTOPp->Top__DOT__bridge__DOT__do_req_or));
            tracep->chgBit(oldp+420,(vlTOPp->Top__DOT__bridge__DOT__do_wr_r));
            tracep->chgBit(oldp+421,(vlTOPp->Top__DOT__bridge__DOT__data_back));
            tracep->chgBit(oldp+422,(vlTOPp->Top__DOT__bridge__DOT__addr_rcv));
            tracep->chgBit(oldp+423,(vlTOPp->Top__DOT__bridge__DOT__wdata_rcv));
        }
        tracep->chgBit(oldp+424,(vlTOPp->clock));
        tracep->chgBit(oldp+425,(vlTOPp->reset));
        tracep->chgQData(oldp+426,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+428,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+430,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+432,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+434,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+436,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+438,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+440,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+442,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+444,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+446,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+448,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+450,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+452,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+454,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+456,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+458,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+460,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+462,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+464,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+466,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+468,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+470,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+472,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+474,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+476,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+478,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+480,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+482,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+484,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+486,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+488,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+490,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+492,(vlTOPp->io_debug_valid));
        tracep->chgBit(oldp+493,(vlTOPp->io_debug_trap));
        tracep->chgQData(oldp+494,(vlTOPp->io_debug_test),64);
        tracep->chgBit(oldp+496,((1U & (~ (IData)(vlTOPp->reset)))));
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
