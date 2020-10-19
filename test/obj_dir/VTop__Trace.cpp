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
            tracep->chgCData(oldp+0,(vlTOPp->Top__DOT__idu_io_alu_op),6);
            tracep->chgQData(oldp+1,(vlTOPp->Top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+3,(vlTOPp->Top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+5,(vlTOPp->Top__DOT__alu_io_out),64);
            tracep->chgBit(oldp+7,((0ULL == vlTOPp->Top__DOT__alu_io_out)));
            tracep->chgIData(oldp+8,(vlTOPp->Top__DOT__inst),32);
            tracep->chgCData(oldp+9,(vlTOPp->Top__DOT__idu_io_br_type),4);
            tracep->chgCData(oldp+10,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
            tracep->chgCData(oldp+11,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
            tracep->chgCData(oldp+12,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
            tracep->chgBit(oldp+13,(vlTOPp->Top__DOT__idu_io_rf_wen));
            tracep->chgBit(oldp+14,(vlTOPp->Top__DOT__idu_io_mem_en));
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__idu_io_mem_fcn));
            tracep->chgCData(oldp+16,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
            tracep->chgBit(oldp+17,((0x6bU == (0x707fU 
                                               & vlTOPp->Top__DOT__inst))));
            tracep->chgCData(oldp+18,((0x1fU & (vlTOPp->Top__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgQData(oldp+19,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
            tracep->chgCData(oldp+21,((0x1fU & (vlTOPp->Top__DOT__inst 
                                                >> 0x14U))),5);
            tracep->chgQData(oldp+22,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
            tracep->chgCData(oldp+24,((0x1fU & (vlTOPp->Top__DOT__inst 
                                                >> 7U))),5);
            tracep->chgQData(oldp+25,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+27,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+29,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+31,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+33,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+35,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+37,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+39,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+41,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+43,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+45,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+47,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+49,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+51,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+53,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+55,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+57,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+59,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+61,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+63,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+65,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+67,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+69,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+71,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+73,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+75,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+77,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+79,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+81,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+83,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+85,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+87,(vlTOPp->Top__DOT__rf__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+89,(vlTOPp->Top__DOT__pc_reg),64);
            tracep->chgBit(oldp+91,(vlTOPp->Top__DOT__imem_req_r));
            tracep->chgSData(oldp+92,((0xfffU & (vlTOPp->Top__DOT__inst 
                                                 >> 0x14U))),12);
            tracep->chgCData(oldp+93,((0x7fU & (vlTOPp->Top__DOT__inst 
                                                >> 0x19U))),7);
            tracep->chgSData(oldp+94,(vlTOPp->Top__DOT__imm_s),12);
            tracep->chgBit(oldp+95,((1U & (vlTOPp->Top__DOT__inst 
                                           >> 0x1fU))));
            tracep->chgBit(oldp+96,((1U & (vlTOPp->Top__DOT__inst 
                                           >> 7U))));
            tracep->chgCData(oldp+97,((0x3fU & (vlTOPp->Top__DOT__inst 
                                                >> 0x19U))),6);
            tracep->chgCData(oldp+98,((0xfU & (vlTOPp->Top__DOT__inst 
                                               >> 8U))),4);
            tracep->chgSData(oldp+99,(vlTOPp->Top__DOT__imm_b),12);
            tracep->chgIData(oldp+100,((0xfffffU & 
                                        (vlTOPp->Top__DOT__inst 
                                         >> 0xcU))),20);
            tracep->chgCData(oldp+101,((0xffU & (vlTOPp->Top__DOT__inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+102,((1U & (vlTOPp->Top__DOT__inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+103,((0x3ffU & (vlTOPp->Top__DOT__inst 
                                                  >> 0x15U))),10);
            tracep->chgIData(oldp+104,(vlTOPp->Top__DOT__imm_j),20);
            tracep->chgIData(oldp+105,((0x1fU & (vlTOPp->Top__DOT__inst 
                                                 >> 0xfU))),32);
            tracep->chgQData(oldp+106,(((0x80000000U 
                                         & vlTOPp->Top__DOT__inst)
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+108,(vlTOPp->Top__DOT__imm_i_sext),64);
            tracep->chgQData(oldp+110,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_s))
                                         ? 0xfffffffffffffULL
                                         : 0ULL)),52);
            tracep->chgQData(oldp+112,(vlTOPp->Top__DOT__imm_s_sext),64);
            tracep->chgQData(oldp+114,(((0x800U & (IData)(vlTOPp->Top__DOT__imm_b))
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+116,(vlTOPp->Top__DOT__imm_b_sext),66);
            tracep->chgIData(oldp+119,(((0x800000U 
                                         & vlTOPp->Top__DOT__inst)
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+120,(vlTOPp->Top__DOT__imm_u_sext),64);
            tracep->chgQData(oldp+122,(((0x80000U & vlTOPp->Top__DOT__imm_j)
                                         ? 0x1fffffffffffffULL
                                         : 0ULL)),53);
            tracep->chgWData(oldp+124,(vlTOPp->Top__DOT__imm_j_sext),74);
            tracep->chgIData(oldp+127,(((IData)(4U) 
                                        + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
            tracep->chgWData(oldp+128,(vlTOPp->Top__DOT__br_target),66);
            tracep->chgWData(oldp+131,(vlTOPp->Top__DOT__jmp_target),74);
            tracep->chgQData(oldp+134,(vlTOPp->Top__DOT__jr_target),64);
            tracep->chgBit(oldp+136,(vlTOPp->Top__DOT__br_taken));
            tracep->chgIData(oldp+137,(vlTOPp->Top__DOT___pc_next_T_5[0U]),32);
            tracep->chgWData(oldp+138,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
            tracep->chgQData(oldp+141,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+143,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+145,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+147,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+148,(vlTOPp->Top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+149,((0x3fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),6);
            tracep->chgQData(oldp+150,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__alu__DOT___T_7[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__alu__DOT___T_7[0U])))),64);
            tracep->chgQData(oldp+152,(vlTOPp->Top__DOT__alu__DOT__sra_result),64);
            tracep->chgQData(oldp+154,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
            tracep->chgQData(oldp+156,((((QData)((IData)(
                                                         vlTOPp->Top__DOT__alu__DOT__add_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->Top__DOT__alu__DOT__add_result[0U])))),64);
            tracep->chgQData(oldp+158,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+160,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+162,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+164,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+166,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+168,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+170,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+172,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+174,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+176,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+178,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+180,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+182,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+184,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+186,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+188,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+190,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+192,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+194,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+196,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+198,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+200,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+202,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+204,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+206,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+208,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+210,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+212,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+214,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+216,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+218,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+220,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
            tracep->chgQData(oldp+222,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs1_data_MPORT_data),64);
            tracep->chgQData(oldp+224,(vlTOPp->Top__DOT__rf__DOT__regfile_io_rs2_data_MPORT_data),64);
        }
        tracep->chgBit(oldp+226,(vlTOPp->clock));
        tracep->chgBit(oldp+227,(vlTOPp->reset));
        tracep->chgBit(oldp+228,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+229,(vlTOPp->io_imem_req_valid));
        tracep->chgIData(oldp+230,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->chgIData(oldp+231,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+232,(vlTOPp->io_imem_req_bits_fcn));
        tracep->chgCData(oldp+233,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+234,(vlTOPp->io_imem_resp_ready));
        tracep->chgBit(oldp+235,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+236,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+237,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+238,(vlTOPp->io_dmem_req_valid));
        tracep->chgIData(oldp+239,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->chgQData(oldp+240,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+242,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->chgCData(oldp+243,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+244,(vlTOPp->io_dmem_resp_ready));
        tracep->chgBit(oldp+245,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+246,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgQData(oldp+248,(vlTOPp->io_debug_rf_0),64);
        tracep->chgQData(oldp+250,(vlTOPp->io_debug_rf_1),64);
        tracep->chgQData(oldp+252,(vlTOPp->io_debug_rf_2),64);
        tracep->chgQData(oldp+254,(vlTOPp->io_debug_rf_3),64);
        tracep->chgQData(oldp+256,(vlTOPp->io_debug_rf_4),64);
        tracep->chgQData(oldp+258,(vlTOPp->io_debug_rf_5),64);
        tracep->chgQData(oldp+260,(vlTOPp->io_debug_rf_6),64);
        tracep->chgQData(oldp+262,(vlTOPp->io_debug_rf_7),64);
        tracep->chgQData(oldp+264,(vlTOPp->io_debug_rf_8),64);
        tracep->chgQData(oldp+266,(vlTOPp->io_debug_rf_9),64);
        tracep->chgQData(oldp+268,(vlTOPp->io_debug_rf_10),64);
        tracep->chgQData(oldp+270,(vlTOPp->io_debug_rf_11),64);
        tracep->chgQData(oldp+272,(vlTOPp->io_debug_rf_12),64);
        tracep->chgQData(oldp+274,(vlTOPp->io_debug_rf_13),64);
        tracep->chgQData(oldp+276,(vlTOPp->io_debug_rf_14),64);
        tracep->chgQData(oldp+278,(vlTOPp->io_debug_rf_15),64);
        tracep->chgQData(oldp+280,(vlTOPp->io_debug_rf_16),64);
        tracep->chgQData(oldp+282,(vlTOPp->io_debug_rf_17),64);
        tracep->chgQData(oldp+284,(vlTOPp->io_debug_rf_18),64);
        tracep->chgQData(oldp+286,(vlTOPp->io_debug_rf_19),64);
        tracep->chgQData(oldp+288,(vlTOPp->io_debug_rf_20),64);
        tracep->chgQData(oldp+290,(vlTOPp->io_debug_rf_21),64);
        tracep->chgQData(oldp+292,(vlTOPp->io_debug_rf_22),64);
        tracep->chgQData(oldp+294,(vlTOPp->io_debug_rf_23),64);
        tracep->chgQData(oldp+296,(vlTOPp->io_debug_rf_24),64);
        tracep->chgQData(oldp+298,(vlTOPp->io_debug_rf_25),64);
        tracep->chgQData(oldp+300,(vlTOPp->io_debug_rf_26),64);
        tracep->chgQData(oldp+302,(vlTOPp->io_debug_rf_27),64);
        tracep->chgQData(oldp+304,(vlTOPp->io_debug_rf_28),64);
        tracep->chgQData(oldp+306,(vlTOPp->io_debug_rf_29),64);
        tracep->chgQData(oldp+308,(vlTOPp->io_debug_rf_30),64);
        tracep->chgQData(oldp+310,(vlTOPp->io_debug_rf_31),64);
        tracep->chgQData(oldp+312,(vlTOPp->io_debug_PC),64);
        tracep->chgBit(oldp+314,(vlTOPp->io_debug_stall));
        tracep->chgBit(oldp+315,(vlTOPp->io_debug_trap));
        tracep->chgQData(oldp+316,(vlTOPp->Top__DOT__rf_io_wdata),64);
        tracep->chgBit(oldp+318,(vlTOPp->Top__DOT__stall));
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
