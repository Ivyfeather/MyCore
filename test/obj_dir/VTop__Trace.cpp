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
            tracep->chgQData(oldp+2,(vlTOPp->Top__DOT__core__DOT__pre_top_io_imem_req_bits_addr),64);
            tracep->chgBit(oldp+4,(vlTOPp->Top__DOT__imem_resp_valid));
            tracep->chgIData(oldp+5,(vlTOPp->Top__DOT__imem_resp_bits_data),32);
            tracep->chgBit(oldp+6,(vlTOPp->Top__DOT__dmem_req_ready));
            tracep->chgBit(oldp+7,(vlTOPp->Top__DOT__core__DOT__es_top_io_dmem_req_valid));
            tracep->chgQData(oldp+8,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_out),64);
            tracep->chgQData(oldp+10,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs2_data),64);
            tracep->chgBit(oldp+12,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
            tracep->chgCData(oldp+13,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
            tracep->chgBit(oldp+14,(vlTOPp->Top__DOT__dmem_resp_valid));
            tracep->chgQData(oldp+15,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+17,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+19,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+21,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+23,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+25,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+27,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+29,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+31,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+33,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+35,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+37,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+39,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+41,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+43,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+45,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+47,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+49,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+51,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+53,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+55,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+57,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+59,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+61,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+63,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+65,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+67,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+69,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+71,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+73,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+75,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+77,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+79,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05FPC),64);
            tracep->chgBit(oldp+81,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__is_commit));
            tracep->chgBit(oldp+82,((0x6bU == (0x707fU 
                                               & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst))));
            tracep->chgBit(oldp+83,(vlTOPp->Top__DOT__core__DOT__fs_top_io_pres_ready));
            tracep->chgBit(oldp+84,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_ready_go));
            tracep->chgQData(oldp+85,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc),64);
            tracep->chgBit(oldp+87,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__br_taken));
            tracep->chgQData(oldp+88,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__core__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
            tracep->chgBit(oldp+90,(vlTOPp->Top__DOT__core__DOT__ds_top_io_fs_ready));
            tracep->chgBit(oldp+91,(vlTOPp->Top__DOT__core__DOT__fs_top_io_ds_valid));
            tracep->chgQData(oldp+92,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__from_pre_r_PC),64);
            tracep->chgBit(oldp+94,(vlTOPp->Top__DOT__core__DOT__es_top_io_ds_ready));
            tracep->chgBit(oldp+95,(vlTOPp->Top__DOT__core__DOT__ds_top_io_es_valid));
            tracep->chgQData(oldp+96,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_PC),64);
            tracep->chgIData(oldp+98,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst),32);
            tracep->chgCData(oldp+99,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
            tracep->chgCData(oldp+100,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
            tracep->chgCData(oldp+101,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
            tracep->chgCData(oldp+102,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_wb_sel),2);
            tracep->chgBit(oldp+103,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
            tracep->chgBit(oldp+104,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
            tracep->chgBit(oldp+105,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
            tracep->chgCData(oldp+106,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
            tracep->chgQData(oldp+107,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+109,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+111,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
            tracep->chgCData(oldp+112,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
            tracep->chgQData(oldp+113,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
            tracep->chgBit(oldp+115,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
            tracep->chgCData(oldp+116,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_rd_addr),5);
            tracep->chgQData(oldp+117,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_alu_result),64);
            tracep->chgBit(oldp+119,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
            tracep->chgCData(oldp+120,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 7U))),5);
            tracep->chgQData(oldp+121,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_bits_alu_result),64);
            tracep->chgCData(oldp+123,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel),2);
            tracep->chgBit(oldp+124,(vlTOPp->Top__DOT__core__DOT__ms_top_io_es_ready));
            tracep->chgBit(oldp+125,(vlTOPp->Top__DOT__core__DOT__es_top_io_ms_valid));
            tracep->chgQData(oldp+126,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_PC),64);
            tracep->chgBit(oldp+128,(vlTOPp->Top__DOT__core__DOT__ms_top_io_ws_valid));
            tracep->chgQData(oldp+129,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_PC),64);
            tracep->chgBit(oldp+131,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_valid));
            tracep->chgQData(oldp+132,(vlTOPp->Top__DOT__core__DOT__pre_top__DOT__buf_npc),64);
            tracep->chgQData(oldp+134,((4ULL + vlTOPp->Top__DOT__core__DOT__pre_top__DOT__pre_pc)),64);
            tracep->chgBit(oldp+136,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_ready_go));
            tracep->chgBit(oldp+137,(vlTOPp->Top__DOT__core__DOT__fs_top__DOT__fs_valid));
            tracep->chgCData(oldp+138,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+139,((0x1fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x14U))),5);
            tracep->chgBit(oldp+140,((1U == (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
            tracep->chgCData(oldp+141,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
            tracep->chgBit(oldp+142,((1U != (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_wb_sel))));
            tracep->chgBit(oldp+143,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__ds_valid));
            tracep->chgSData(oldp+144,((0xfffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+145,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+146,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 7U))));
            tracep->chgCData(oldp+147,((0x3fU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+148,((0xfU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                >> 8U))),4);
            tracep->chgSData(oldp+149,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b),12);
            tracep->chgCData(oldp+150,((0xffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+151,((1U & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+152,((0x3ffU & (vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+153,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j),20);
            tracep->chgQData(oldp+154,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__from_fs_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+156,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+158,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+160,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_b_sext),66);
            tracep->chgQData(oldp+163,(((0x80000U & vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+165,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__imm_j_sext),74);
            tracep->chgWData(oldp+168,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__branch_target),66);
            tracep->chgWData(oldp+171,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jmp_target),74);
            tracep->chgQData(oldp+174,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__jr_target),64);
            tracep->chgBit(oldp+176,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_eq));
            tracep->chgBit(oldp+177,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_lt));
            tracep->chgBit(oldp+178,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf_ltu));
            tracep->chgCData(oldp+179,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__flush_reg),2);
            tracep->chgQData(oldp+180,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+182,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf_io_rs2_data),64);
            tracep->chgQData(oldp+184,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+186,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+188,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+190,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+192,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+194,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+196,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+198,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+200,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+202,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+204,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+206,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+208,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+210,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+212,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+214,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+216,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+218,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+220,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+222,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+224,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+226,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+228,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+230,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+232,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+234,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+236,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+238,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+240,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+242,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+244,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+246,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+248,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+250,(vlTOPp->Top__DOT__core__DOT__ds_top__DOT__rf__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
            tracep->chgCData(oldp+252,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
            tracep->chgQData(oldp+253,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+255,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2),64);
            tracep->chgIData(oldp+257,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst),32);
            tracep->chgCData(oldp+258,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
            tracep->chgCData(oldp+259,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
            tracep->chgBit(oldp+260,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_decode_mem_en));
            tracep->chgQData(oldp+261,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_rs1_data),64);
            tracep->chgBit(oldp+263,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_ready_go));
            tracep->chgBit(oldp+264,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__es_valid));
            tracep->chgSData(oldp+265,((0xfffU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+266,((0x7fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0x19U))),7);
            tracep->chgSData(oldp+267,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s),12);
            tracep->chgIData(oldp+268,((0xfffffU & 
                                        (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+269,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgIData(oldp+270,((0x1fU & (vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+271,(((0x80000000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+273,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+275,(((0x800U & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+277,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_s_sext),64);
            tracep->chgIData(oldp+279,(((0x800000U 
                                         & vlTOPp->Top__DOT__core__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+280,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__imm_u_sext),64);
            tracep->chgBit(oldp+282,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__dmem_req_r));
            tracep->chgWData(oldp+283,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result),65);
            tracep->chgQData(oldp+286,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+288,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+290,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+292,((1U & (~ vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+293,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+294,((0x3fU & (IData)(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+295,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_7[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT___T_7[0U])))),64);
            tracep->chgQData(oldp+297,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+299,(vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__srl_result),64);
            tracep->chgQData(oldp+301,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__core__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgCData(oldp+303,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_wb_sel),2);
            tracep->chgBit(oldp+304,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
            tracep->chgBit(oldp+305,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__ms_valid));
            tracep->chgCData(oldp+306,(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store),4);
            tracep->chgBit(oldp+307,((0U == (IData)(vlTOPp->Top__DOT__core__DOT__ms_top__DOT__unfinished_store))));
            tracep->chgBit(oldp+308,(vlTOPp->Top__DOT__core__DOT__ws_top__DOT__REG));
        }
        tracep->chgBit(oldp+309,(vlTOPp->clock));
        tracep->chgBit(oldp+310,(vlTOPp->reset));
        tracep->chgBit(oldp+311,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+312,(vlTOPp->io_imem_req_valid));
        tracep->chgQData(oldp+313,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->chgIData(oldp+315,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+316,(vlTOPp->io_imem_req_bits_wr));
        tracep->chgCData(oldp+317,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+318,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+319,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+320,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+321,(vlTOPp->io_dmem_req_valid));
        tracep->chgQData(oldp+322,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->chgQData(oldp+324,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+326,(vlTOPp->io_dmem_req_bits_wr));
        tracep->chgCData(oldp+327,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+328,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+329,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgQData(oldp+331,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+333,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+335,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+337,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+339,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+341,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+343,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+345,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+347,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+349,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+351,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+353,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+355,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+357,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+359,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+361,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+363,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+365,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+367,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+369,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+371,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+373,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+375,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+377,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+379,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+381,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+383,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+385,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+387,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+389,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+391,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+393,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+395,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+397,(vlTOPp->io_debug_valid));
        tracep->chgBit(oldp+398,(vlTOPp->io_debug_trap));
        tracep->chgIData(oldp+399,(vlTOPp->io_debug_inst),32);
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
