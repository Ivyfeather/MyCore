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
            tracep->chgBit(oldp+0,(vlTOPp->Top__DOT__fs_top_io_pres_ready));
            tracep->chgBit(oldp+1,(vlTOPp->Top__DOT__ds_top_io_fs_ready));
            tracep->chgBit(oldp+2,(vlTOPp->Top__DOT__es_top_io_ds_ready));
            tracep->chgBit(oldp+3,(vlTOPp->Top__DOT__es_top_io_ms_valid));
            tracep->chgBit(oldp+4,(vlTOPp->Top__DOT__es_top__DOT__es_ready_go));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+5,(vlTOPp->Top__DOT__pre_top__DOT__pre_ready_go));
            tracep->chgQData(oldp+6,(vlTOPp->Top__DOT__pre_top_io_fs_bits_PC),64);
            tracep->chgBit(oldp+8,(vlTOPp->Top__DOT__pre_top__DOT__imem_req_r));
            tracep->chgBit(oldp+9,(vlTOPp->Top__DOT__ds_top__DOT__br_taken));
            tracep->chgQData(oldp+10,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__ds_top__DOT___br_target_T_3[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__ds_top__DOT___br_target_T_3[0U])))),64);
            tracep->chgBit(oldp+12,(vlTOPp->Top__DOT__fs_top_io_ds_valid));
            tracep->chgQData(oldp+13,(vlTOPp->Top__DOT__fs_top__DOT__from_pre_r_PC),64);
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__ds_top__DOT__ds_valid));
            tracep->chgQData(oldp+16,(vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_PC),64);
            tracep->chgIData(oldp+18,(vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst),32);
            tracep->chgCData(oldp+19,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_op1_sel),2);
            tracep->chgCData(oldp+20,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_op2_sel),2);
            tracep->chgCData(oldp+21,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_alu_op),6);
            tracep->chgBit(oldp+22,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_rf_wen));
            tracep->chgBit(oldp+23,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_en));
            tracep->chgBit(oldp+24,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_wr));
            tracep->chgCData(oldp+25,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_mem_msk),3);
            tracep->chgQData(oldp+26,(vlTOPp->Top__DOT__ds_top__DOT__rf_io_rs1_data),64);
            tracep->chgQData(oldp+28,(vlTOPp->Top__DOT__ds_top__DOT__rf_io_rs2_data),64);
            tracep->chgBit(oldp+30,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Fdecode_rf_wen));
            tracep->chgCData(oldp+31,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Frd_addr),5);
            tracep->chgQData(oldp+32,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05Ffinal_result),64);
            tracep->chgBit(oldp+34,((0x6bU == (0x707fU 
                                               & vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst))));
            tracep->chgQData(oldp+35,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+37,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+39,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+41,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+43,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+45,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+47,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+49,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+51,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+53,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+55,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+57,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+59,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+61,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+63,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+65,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+67,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+69,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+71,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+73,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+75,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+77,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+79,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+81,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+83,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+85,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+87,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+89,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+91,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+93,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+95,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+97,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgBit(oldp+99,(vlTOPp->Top__DOT__ms_top_io_es_ready));
            tracep->chgQData(oldp+100,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_PC),64);
            tracep->chgBit(oldp+102,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_rf_wen));
            tracep->chgBit(oldp+103,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_wr));
            tracep->chgQData(oldp+104,(vlTOPp->Top__DOT__es_top__DOT__alu_io_out),64);
            tracep->chgCData(oldp+106,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 7U))),5);
            tracep->chgBit(oldp+107,(vlTOPp->Top__DOT__es_top_io_dmem_req_valid));
            tracep->chgQData(oldp+108,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_rs2_data),64);
            tracep->chgCData(oldp+110,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_msk),3);
            tracep->chgBit(oldp+111,(vlTOPp->Top__DOT__ms_top_io_ws_valid));
            tracep->chgQData(oldp+112,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_PC),64);
            tracep->chgBit(oldp+114,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_decode_rf_wen));
            tracep->chgQData(oldp+115,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_alu_result),64);
            tracep->chgCData(oldp+117,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_rd_addr),5);
            tracep->chgQData(oldp+118,(vlTOPp->Top__DOT__ws_top__DOT__from_ms_r___05FPC),64);
            tracep->chgQData(oldp+120,(vlTOPp->Top__DOT__pre_top__DOT__pre_pc),64);
            tracep->chgBit(oldp+122,(vlTOPp->Top__DOT__pre_top__DOT__buf_valid));
            tracep->chgQData(oldp+123,(vlTOPp->Top__DOT__pre_top__DOT__buf_npc),64);
            tracep->chgQData(oldp+125,((4ULL + vlTOPp->Top__DOT__pre_top__DOT__pre_pc)),64);
            tracep->chgBit(oldp+127,(vlTOPp->Top__DOT__fs_top__DOT__fs_ready_go));
            tracep->chgBit(oldp+128,(vlTOPp->Top__DOT__fs_top__DOT__fs_valid));
            tracep->chgCData(oldp+129,(vlTOPp->Top__DOT__ds_top__DOT__idu_io_ctrl_br_type),4);
            tracep->chgCData(oldp+130,((0x1fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+131,((0x1fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x14U))),5);
            tracep->chgSData(oldp+132,((0xfffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+133,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x1fU))));
            tracep->chgBit(oldp+134,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 7U))));
            tracep->chgCData(oldp+135,((0x3fU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+136,((0xfU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                >> 8U))),4);
            tracep->chgSData(oldp+137,(vlTOPp->Top__DOT__ds_top__DOT__imm_b),12);
            tracep->chgCData(oldp+138,((0xffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+139,((1U & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+140,((0x3ffU & (vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+141,(vlTOPp->Top__DOT__ds_top__DOT__imm_j),20);
            tracep->chgQData(oldp+142,(((0x80000000U 
                                         & vlTOPp->Top__DOT__ds_top__DOT__from_fs_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+144,(vlTOPp->Top__DOT__ds_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+146,(((0x800U & (IData)(vlTOPp->Top__DOT__ds_top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+148,(vlTOPp->Top__DOT__ds_top__DOT__imm_b_sext),66);
            tracep->chgQData(oldp+151,(((0x80000U & vlTOPp->Top__DOT__ds_top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+153,(vlTOPp->Top__DOT__ds_top__DOT__imm_j_sext),74);
            tracep->chgWData(oldp+156,(vlTOPp->Top__DOT__ds_top__DOT__branch_target),66);
            tracep->chgWData(oldp+159,(vlTOPp->Top__DOT__ds_top__DOT__jmp_target),74);
            tracep->chgQData(oldp+162,(vlTOPp->Top__DOT__ds_top__DOT__jr_target),64);
            tracep->chgBit(oldp+164,(vlTOPp->Top__DOT__ds_top__DOT__rf_eq));
            tracep->chgBit(oldp+165,(vlTOPp->Top__DOT__ds_top__DOT__rf_lt));
            tracep->chgBit(oldp+166,(vlTOPp->Top__DOT__ds_top__DOT__rf_ltu));
            tracep->chgQData(oldp+167,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+169,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+171,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+173,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+175,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+177,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+179,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+181,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+183,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+185,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+187,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+189,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+191,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+193,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+195,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+197,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+199,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+201,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+203,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+205,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+207,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+209,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+211,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+213,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+215,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+217,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+219,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+221,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+223,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+225,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+227,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+229,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+231,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+233,(vlTOPp->Top__DOT__ds_top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
            tracep->chgCData(oldp+235,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_alu_op),6);
            tracep->chgQData(oldp+236,(vlTOPp->Top__DOT__es_top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+238,(vlTOPp->Top__DOT__es_top__DOT__alu_io_in2),64);
            tracep->chgIData(oldp+240,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst),32);
            tracep->chgCData(oldp+241,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_op1_sel),2);
            tracep->chgCData(oldp+242,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_op2_sel),2);
            tracep->chgBit(oldp+243,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_decode_mem_en));
            tracep->chgQData(oldp+244,(vlTOPp->Top__DOT__es_top__DOT__from_ds_r_rs1_data),64);
            tracep->chgBit(oldp+246,(vlTOPp->Top__DOT__es_top__DOT__es_valid));
            tracep->chgSData(oldp+247,((0xfffU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                  >> 0x14U))),12);
            tracep->chgCData(oldp+248,((0x7fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0x19U))),7);
            tracep->chgSData(oldp+249,(vlTOPp->Top__DOT__es_top__DOT__imm_s),12);
            tracep->chgIData(oldp+250,((0xfffffU & 
                                        (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+251,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),5);
            tracep->chgIData(oldp+252,((0x1fU & (vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+253,(((0x80000000U 
                                         & vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+255,(vlTOPp->Top__DOT__es_top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+257,(((0x800U & (IData)(vlTOPp->Top__DOT__es_top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+259,(vlTOPp->Top__DOT__es_top__DOT__imm_s_sext),64);
            tracep->chgIData(oldp+261,(((0x800000U 
                                         & vlTOPp->Top__DOT__es_top__DOT__from_ds_r_inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+262,(vlTOPp->Top__DOT__es_top__DOT__imm_u_sext),64);
            tracep->chgBit(oldp+264,(vlTOPp->Top__DOT__es_top__DOT__dmem_req_r));
            tracep->chgWData(oldp+265,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result),65);
            tracep->chgQData(oldp+268,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+270,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+272,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+274,((1U & (~ vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+275,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+276,((0x3fU & (IData)(vlTOPp->Top__DOT__es_top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+277,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__es_top__DOT__alu__DOT___T_7[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__es_top__DOT__alu__DOT___T_7[0U])))),64);
            tracep->chgQData(oldp+279,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+281,(vlTOPp->Top__DOT__es_top__DOT__alu__DOT__srl_result),64);
            tracep->chgQData(oldp+283,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__es_top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgBit(oldp+285,(vlTOPp->Top__DOT__ms_top__DOT__from_es_r_decode_mem_wr));
            tracep->chgBit(oldp+286,(vlTOPp->Top__DOT__ms_top__DOT__ms_valid));
            tracep->chgCData(oldp+287,(vlTOPp->Top__DOT__ms_top__DOT__unfinished_store),4);
            tracep->chgBit(oldp+288,((0U == (IData)(vlTOPp->Top__DOT__ms_top__DOT__unfinished_store))));
        }
        tracep->chgBit(oldp+289,(vlTOPp->clock));
        tracep->chgBit(oldp+290,(vlTOPp->reset));
        tracep->chgBit(oldp+291,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+292,(vlTOPp->io_imem_req_valid));
        tracep->chgQData(oldp+293,(vlTOPp->io_imem_req_bits_addr),64);
        tracep->chgIData(oldp+295,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+296,(vlTOPp->io_imem_req_bits_wr));
        tracep->chgCData(oldp+297,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+298,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+299,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+300,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+301,(vlTOPp->io_dmem_req_valid));
        tracep->chgQData(oldp+302,(vlTOPp->io_dmem_req_bits_addr),64);
        tracep->chgQData(oldp+304,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+306,(vlTOPp->io_dmem_req_bits_wr));
        tracep->chgCData(oldp+307,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+308,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+309,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgQData(oldp+311,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+313,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+315,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+317,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+319,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+321,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+323,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+325,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+327,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+329,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+331,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+333,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+335,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+337,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+339,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+341,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+343,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+345,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+347,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+349,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+351,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+353,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+355,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+357,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+359,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+361,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+363,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+365,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+367,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+369,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+371,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+373,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+375,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+377,(vlTOPp->io_debug_stall));
        tracep->chgBit(oldp+378,(vlTOPp->io_debug_trap));
        tracep->chgIData(oldp+379,(vlTOPp->io_debug_inst),32);
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
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
