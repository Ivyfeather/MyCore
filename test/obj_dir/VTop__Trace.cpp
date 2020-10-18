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
            tracep->chgCData(oldp+0,(vlTOPp->Top__DOT__idu__DOT__csignals_4),6);
            tracep->chgQData(oldp+1,(vlTOPp->Top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+3,(vlTOPp->Top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+5,(vlTOPp->Top__DOT__alu_io_out),64);
            tracep->chgBit(oldp+7,((0ULL == vlTOPp->Top__DOT__alu_io_out)));
            tracep->chgIData(oldp+8,(vlTOPp->Top__DOT__idu_io_inst),32);
            tracep->chgCData(oldp+9,(vlTOPp->Top__DOT__idu_io_br_type),4);
            tracep->chgCData(oldp+10,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
            tracep->chgCData(oldp+11,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
            tracep->chgCData(oldp+12,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
            tracep->chgBit(oldp+13,(vlTOPp->Top__DOT__idu_io_rf_wen));
            tracep->chgBit(oldp+14,(vlTOPp->Top__DOT__idu_io_mem_en));
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__idu_io_mem_fcn));
            tracep->chgCData(oldp+16,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
            tracep->chgCData(oldp+17,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),5);
            tracep->chgQData(oldp+18,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
            tracep->chgCData(oldp+20,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0x14U))),5);
            tracep->chgQData(oldp+21,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
            tracep->chgCData(oldp+23,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 7U))),5);
            tracep->chgQData(oldp+24,(vlTOPp->Top__DOT__rf_io_wdata),64);
            tracep->chgBit(oldp+26,(vlTOPp->Top__DOT__stall));
            tracep->chgSData(oldp+27,((0xfffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0x14U))),12);
            tracep->chgCData(oldp+28,((0x7fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0x19U))),7);
            tracep->chgSData(oldp+29,(vlTOPp->Top__DOT__imm_s),12);
            tracep->chgBit(oldp+30,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                           >> 0x1fU))));
            tracep->chgBit(oldp+31,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                           >> 7U))));
            tracep->chgCData(oldp+32,((0x3fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0x19U))),6);
            tracep->chgCData(oldp+33,((0xfU & (vlTOPp->Top__DOT__idu_io_inst 
                                               >> 8U))),4);
            tracep->chgSData(oldp+34,(vlTOPp->Top__DOT__imm_b),12);
            tracep->chgIData(oldp+35,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0xcU))),20);
            tracep->chgCData(oldp+36,((0xffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xcU))),8);
            tracep->chgBit(oldp+37,((1U & (vlTOPp->Top__DOT__idu_io_inst 
                                           >> 0x14U))));
            tracep->chgSData(oldp+38,((0x3ffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0x15U))),10);
            tracep->chgIData(oldp+39,(vlTOPp->Top__DOT__imm_j),20);
            tracep->chgIData(oldp+40,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),32);
            tracep->chgIData(oldp+41,(((0x80000000U 
                                        & vlTOPp->Top__DOT__idu_io_inst)
                                        ? 0xfffffU : 0U)),20);
            tracep->chgIData(oldp+42,(vlTOPp->Top__DOT__imm_i_sext),32);
            tracep->chgIData(oldp+43,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_s))
                                        ? 0xfffffU : 0U)),20);
            tracep->chgIData(oldp+44,(vlTOPp->Top__DOT__imm_s_sext),32);
            tracep->chgIData(oldp+45,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_b))
                                        ? 0x7ffffU : 0U)),19);
            tracep->chgIData(oldp+46,(vlTOPp->Top__DOT__imm_b_sext),32);
            tracep->chgIData(oldp+47,((0xfffff000U 
                                       & vlTOPp->Top__DOT__idu_io_inst)),32);
            tracep->chgSData(oldp+48,(((0x80000U & vlTOPp->Top__DOT__imm_j)
                                        ? 0x7ffU : 0U)),11);
            tracep->chgIData(oldp+49,(vlTOPp->Top__DOT__imm_j_sext),32);
            tracep->chgQData(oldp+50,(vlTOPp->Top__DOT__br_target),64);
            tracep->chgQData(oldp+52,(vlTOPp->Top__DOT__jmp_target),64);
            tracep->chgQData(oldp+54,(vlTOPp->Top__DOT__jr_target),64);
            tracep->chgBit(oldp+56,(vlTOPp->Top__DOT__br_taken));
            tracep->chgIData(oldp+57,((IData)(vlTOPp->Top__DOT___pc_next_T_5)),32);
            tracep->chgWData(oldp+58,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
            tracep->chgQData(oldp+61,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+63,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+65,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+67,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+68,(vlTOPp->Top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+69,((0x1fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),5);
            tracep->chgQData(oldp+70,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__alu__DOT___T_7[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__alu__DOT___T_7[0U])))),64);
            tracep->chgQData(oldp+72,(vlTOPp->Top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+74,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
            tracep->chgQData(oldp+76,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__alu__DOT__add_result[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgCData(oldp+78,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
            tracep->chgQData(oldp+79,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+81,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+83,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+85,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+87,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+89,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+91,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+93,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+95,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+97,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+99,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+101,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [9U]),64);
            tracep->chgQData(oldp+103,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xaU]),64);
            tracep->chgQData(oldp+105,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xbU]),64);
            tracep->chgQData(oldp+107,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xcU]),64);
            tracep->chgQData(oldp+109,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xdU]),64);
            tracep->chgQData(oldp+111,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xeU]),64);
            tracep->chgQData(oldp+113,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0xfU]),64);
            tracep->chgQData(oldp+115,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x10U]),64);
            tracep->chgQData(oldp+117,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x11U]),64);
            tracep->chgQData(oldp+119,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x12U]),64);
            tracep->chgQData(oldp+121,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x13U]),64);
            tracep->chgQData(oldp+123,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x14U]),64);
            tracep->chgQData(oldp+125,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x15U]),64);
            tracep->chgQData(oldp+127,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x16U]),64);
            tracep->chgQData(oldp+129,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x17U]),64);
            tracep->chgQData(oldp+131,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x18U]),64);
            tracep->chgQData(oldp+133,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x19U]),64);
            tracep->chgQData(oldp+135,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1aU]),64);
            tracep->chgQData(oldp+137,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1bU]),64);
            tracep->chgQData(oldp+139,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1cU]),64);
            tracep->chgQData(oldp+141,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1dU]),64);
            tracep->chgQData(oldp+143,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1eU]),64);
            tracep->chgQData(oldp+145,(vlTOPp->Top__DOT__rf__DOT__regfile
                                       [0x1fU]),64);
            tracep->chgQData(oldp+147,(vlTOPp->Top__DOT__pc_reg),64);
            tracep->chgBit(oldp+149,(vlTOPp->Top__DOT__imem_req_r));
            tracep->chgIData(oldp+150,(((IData)(4U) 
                                        + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
            tracep->chgQData(oldp+151,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+153,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+155,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+157,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+159,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+161,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+163,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+165,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+167,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+169,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+171,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+173,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+175,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+177,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+179,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+181,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+183,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+185,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+187,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+189,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+191,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+193,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+195,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+197,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+199,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+201,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+203,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+205,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+207,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+209,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+211,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+213,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        }
        tracep->chgBit(oldp+215,(vlTOPp->clock));
        tracep->chgBit(oldp+216,(vlTOPp->reset));
        tracep->chgBit(oldp+217,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+218,(vlTOPp->io_imem_req_valid));
        tracep->chgIData(oldp+219,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->chgIData(oldp+220,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+221,(vlTOPp->io_imem_req_bits_fcn));
        tracep->chgCData(oldp+222,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+223,(vlTOPp->io_imem_resp_ready));
        tracep->chgBit(oldp+224,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+225,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+226,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+227,(vlTOPp->io_dmem_req_valid));
        tracep->chgIData(oldp+228,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->chgQData(oldp+229,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+231,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->chgCData(oldp+232,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+233,(vlTOPp->io_dmem_resp_ready));
        tracep->chgBit(oldp+234,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+235,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgQData(oldp+237,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+239,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+241,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+243,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+245,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+247,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+249,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+251,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+253,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+255,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+257,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+259,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+261,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+263,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+265,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+267,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+269,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+271,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+273,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+275,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+277,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+279,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+281,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+283,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+285,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+287,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+289,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+291,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+293,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+295,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+297,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+299,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+301,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+303,(vlTOPp->io_debug_stall));
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
