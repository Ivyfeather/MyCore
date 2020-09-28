// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop.h"
#include "VTop__Syms.h"

//==========

VL_CTOR_IMP(VTop) {
    VTop__Syms* __restrict vlSymsp = __VlSymsp = new VTop__Syms(this, name());
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VTop::__Vconfigure(VTop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    _configure_coverage(vlSymsp, first);
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VTop::~VTop() {
#ifdef VM_TRACE
    if (VL_UNLIKELY(__VlSymsp->__Vm_dumping)) _traceDumpClose();
#endif  // VM_TRACE
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

// Coverage
void VTop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",std::string(name())+hierp,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}

void VTop::_initial__TOP__1(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_initial__TOP__1\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp1[5];
    // Body
    if (VL_UNLIKELY((0U != VL_TESTPLUSARGS_I("trace")))) {
        VL_WRITEF("[%0t] Tracing to logs/vlt_dump.vcd...\n\n",
                  64,VL_TIME_UNITED_Q(1));
        __Vtemp1[0U] = 0x2e766364U;
        __Vtemp1[1U] = 0x64756d70U;
        __Vtemp1[2U] = 0x766c745fU;
        __Vtemp1[3U] = 0x6f67732fU;
        __Vtemp1[4U] = 0x6cU;
        vl_dumpctl_filenamep(true, VL_CVT_PACK_STR_NW(5, __Vtemp1));
        vlSymsp->TOPp->_traceDumpOpen();
        ++(vlSymsp->__Vcoverage[238]);
    } else {
        ++(vlSymsp->__Vcoverage[239]);
    }
    VL_WRITEF("[%0t] Model running...\n\n",64,VL_TIME_UNITED_Q(1));
    ++(vlSymsp->__Vcoverage[240]);
}

void VTop::_settle__TOP__3(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_settle__TOP__3\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) ^ vlTOPp->Top__DOT____Vtogcov__clock)) {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->Top__DOT____Vtogcov__clock = vlTOPp->clock;
    }
    if (((IData)(vlTOPp->reset) ^ vlTOPp->Top__DOT____Vtogcov__reset)) {
        ++(vlSymsp->__Vcoverage[1]);
        vlTOPp->Top__DOT____Vtogcov__reset = vlTOPp->reset;
    }
    if ((1U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3eU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (1U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((2U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3dU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (2U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((4U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x3bU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (4U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((8U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x37U 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (8U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((0x10U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x2fU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (0x10U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((0x20U & ((IData)(vlTOPp->io_opcode) ^ vlTOPp->Top__DOT____Vtogcov__io_opcode))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlTOPp->Top__DOT____Vtogcov__io_opcode = ((0x1fU 
                                                   & (IData)(vlTOPp->Top__DOT____Vtogcov__io_opcode)) 
                                                  | (0x20U 
                                                     & (IData)(vlTOPp->io_opcode)));
    }
    if ((1U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (1U 
                                                  & vlTOPp->io_in1));
    }
    if ((2U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (2U 
                                                  & vlTOPp->io_in1));
    }
    if ((4U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (4U 
                                                  & vlTOPp->io_in1));
    }
    if ((8U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (8U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x100U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x100U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x200U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x200U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x400U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x400U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x800U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x800U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x1000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x1000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x2000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x2000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x4000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x4000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x8000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x8000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x100000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x100000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x200000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x200000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x400000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x400000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x800000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x800000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x1000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x2000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x4000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x8000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x10000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x20000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x40000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((0x80000000U & (vlTOPp->io_in1 ^ vlTOPp->Top__DOT____Vtogcov__io_in1))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlTOPp->Top__DOT____Vtogcov__io_in1 = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in1) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_in1));
    }
    if ((1U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (1U 
                                                  & vlTOPp->io_in2));
    }
    if ((2U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (2U 
                                                  & vlTOPp->io_in2));
    }
    if ((4U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (4U 
                                                  & vlTOPp->io_in2));
    }
    if ((8U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (8U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x100U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x100U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x200U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x200U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x400U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x400U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x800U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x800U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x1000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x1000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x2000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x2000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x4000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x4000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x8000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x8000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x100000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x100000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x200000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x200000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x400000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x400000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x800000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x800000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x1000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x2000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x4000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x8000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x10000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x20000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x40000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_in2));
    }
    if ((0x80000000U & (vlTOPp->io_in2 ^ vlTOPp->Top__DOT____Vtogcov__io_in2))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlTOPp->Top__DOT____Vtogcov__io_in2 = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_in2) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_in2));
    }
    vlTOPp->Top__DOT__or_result = (vlTOPp->io_in1 | vlTOPp->io_in2);
    vlTOPp->Top__DOT__and_result = (vlTOPp->io_in1 
                                    & vlTOPp->io_in2);
    vlTOPp->Top__DOT__xor_result = (vlTOPp->io_in1 
                                    ^ vlTOPp->io_in2);
    vlTOPp->Top__DOT__add_result = (0x1ffffffffULL 
                                    & ((QData)((IData)(vlTOPp->io_in1)) 
                                       + (QData)((IData)(
                                                         ((0x10U 
                                                           & (IData)(vlTOPp->io_opcode))
                                                           ? 
                                                          ((IData)(1U) 
                                                           + 
                                                           (~ vlTOPp->io_in2))
                                                           : vlTOPp->io_in2)))));
    if ((1U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffeU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (1U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((2U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffdU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (2U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((4U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffffbU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (4U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((8U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffff7U 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (8U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffefU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffdfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffffbfU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffff7fU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffeffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x100U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffdffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x200U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffffbffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x400U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffff7ffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x800U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffefffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x1000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffdfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x2000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffffbfffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x4000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffff7fffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x8000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffeffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffdffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfffbffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfff7ffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffefffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x100000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffdfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x200000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xffbfffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x400000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__or_result ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xff7fffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x800000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfeffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x1000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfdffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x2000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xfbffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x4000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__or_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xf7ffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x8000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xefffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x10000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xdfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x20000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0xbfffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x40000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__or_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__or_result))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlTOPp->Top__DOT____Vtogcov__or_result = ((0x7fffffffU 
                                                   & vlTOPp->Top__DOT____Vtogcov__or_result) 
                                                  | (0x80000000U 
                                                     & vlTOPp->Top__DOT__or_result));
    }
    if ((1U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((2U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((4U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((8U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__and_result ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__and_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__and_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__and_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__and_result))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlTOPp->Top__DOT____Vtogcov__and_result = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__and_result) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__and_result));
    }
    if ((1U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffeU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (1U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((2U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffdU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (2U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((4U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffffbU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (4U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((8U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffff7U 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (8U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffefU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffdfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffffbfU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffff7fU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x100U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffeffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x100U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x200U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffdffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x200U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x400U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffffbffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x400U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x800U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffff7ffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x800U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x1000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffefffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x1000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x2000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffdfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x2000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x4000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffffbfffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x4000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x8000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffff7fffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x8000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffeffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffdffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfffbffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80000U & (vlTOPp->Top__DOT__xor_result ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfff7ffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x100000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffefffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x100000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x200000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffdfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x200000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x400000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xffbfffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x400000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x800000U & (vlTOPp->Top__DOT__xor_result 
                      ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xff7fffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x800000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x1000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfeffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x1000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x2000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfdffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x2000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x4000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xfbffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x4000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x8000000U & (vlTOPp->Top__DOT__xor_result 
                       ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xf7ffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x8000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x10000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xefffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x10000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x20000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xdfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x20000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x40000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0xbfffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x40000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((0x80000000U & (vlTOPp->Top__DOT__xor_result 
                        ^ vlTOPp->Top__DOT____Vtogcov__xor_result))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlTOPp->Top__DOT____Vtogcov__xor_result = (
                                                   (0x7fffffffU 
                                                    & vlTOPp->Top__DOT____Vtogcov__xor_result) 
                                                   | (0x80000000U 
                                                      & vlTOPp->Top__DOT__xor_result));
    }
    if ((1U & ((~ (IData)((vlTOPp->Top__DOT__add_result 
                           >> 0x20U))) ^ vlTOPp->Top__DOT____Vtogcov__sltu_result))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlTOPp->Top__DOT____Vtogcov__sltu_result = 
            (1U & (~ (IData)((vlTOPp->Top__DOT__add_result 
                              >> 0x20U))));
    }
    if ((1U & ((IData)(vlTOPp->Top__DOT__add_result) 
               ^ (IData)(vlTOPp->Top__DOT____Vtogcov__add_result)))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffeULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | (IData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlTOPp->Top__DOT__add_result)))));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 1U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffdULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 1U))))) 
                                                      << 1U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 2U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffffbULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 2U))))) 
                                                      << 2U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 3U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffff7ULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 3U))))) 
                                                      << 3U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 4U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffefULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 4U))))) 
                                                      << 4U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 5U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffdfULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 5U))))) 
                                                      << 5U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 6U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffffbfULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 6U))))) 
                                                      << 6U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 7U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffff7fULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 7U))))) 
                                                      << 7U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 8U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffeffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 8U))))) 
                                                      << 8U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 9U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffdffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 9U))))) 
                                                      << 9U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xaU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffffbffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xaU))))) 
                                                      << 0xaU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xbU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffff7ffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xbU))))) 
                                                      << 0xbU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xcU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffefffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xcU))))) 
                                                      << 0xcU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xdU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffdfffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xdU))))) 
                                                      << 0xdU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xeU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffffbfffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xeU))))) 
                                                      << 0xeU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0xfU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffff7fffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0xfU))))) 
                                                      << 0xfU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x10U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffeffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x10U))))) 
                                                      << 0x10U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x11U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffdffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x11U))))) 
                                                      << 0x11U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x12U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fffbffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x12U))))) 
                                                      << 0x12U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x13U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fff7ffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x13U))))) 
                                                      << 0x13U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x14U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffefffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x14U))))) 
                                                      << 0x14U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x15U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffdfffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x15U))))) 
                                                      << 0x15U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x16U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ffbfffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x16U))))) 
                                                      << 0x16U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x17U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1ff7fffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x17U))))) 
                                                      << 0x17U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x18U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1feffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x18U))))) 
                                                      << 0x18U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x19U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fdffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x19U))))) 
                                                      << 0x19U));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1aU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1fbffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1aU))))) 
                                                      << 0x1aU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1bU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1f7ffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1bU))))) 
                                                      << 0x1bU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1cU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1efffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1cU))))) 
                                                      << 0x1cU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1dU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1dfffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1dU))))) 
                                                      << 0x1dU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1eU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x1bfffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1eU))))) 
                                                      << 0x1eU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x1fU)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0x17fffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x1fU))))) 
                                                      << 0x1fU));
    }
    if ((1U & ((IData)((vlTOPp->Top__DOT__add_result 
                        >> 0x20U)) ^ (IData)((vlTOPp->Top__DOT____Vtogcov__add_result 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlTOPp->Top__DOT____Vtogcov__add_result = (
                                                   (0xffffffffULL 
                                                    & vlTOPp->Top__DOT____Vtogcov__add_result) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlTOPp->Top__DOT__add_result 
                                                                                >> 0x20U))))) 
                                                      << 0x20U));
    }
    vlTOPp->Top__DOT__slt_result = (1U & ((vlTOPp->Top__DOT__xor_result 
                                           >> 0x1fU) 
                                          ^ (~ (IData)(
                                                       (vlTOPp->Top__DOT__add_result 
                                                        >> 0x20U)))));
    if (((IData)(vlTOPp->Top__DOT__slt_result) ^ vlTOPp->Top__DOT____Vtogcov__slt_result)) {
        ++(vlSymsp->__Vcoverage[234]);
        vlTOPp->Top__DOT____Vtogcov__slt_result = vlTOPp->Top__DOT__slt_result;
    }
    vlTOPp->io_out = ((0x12U == (0x1fU & (IData)(vlTOPp->io_opcode)))
                       ? (1U & (~ (IData)((vlTOPp->Top__DOT__add_result 
                                           >> 0x20U))))
                       : ((0x11U == (0x1fU & (IData)(vlTOPp->io_opcode)))
                           ? (IData)(vlTOPp->Top__DOT__slt_result)
                           : ((1U == (1U & (IData)(vlTOPp->io_opcode)))
                               ? vlTOPp->Top__DOT__xor_result
                               : ((2U == (3U & (IData)(vlTOPp->io_opcode)))
                                   ? vlTOPp->Top__DOT__or_result
                                   : ((3U == (3U & (IData)(vlTOPp->io_opcode)))
                                       ? vlTOPp->Top__DOT__and_result
                                       : ((8U == (0xfU 
                                                  & (IData)(vlTOPp->io_opcode)))
                                           ? vlTOPp->io_in1
                                           : (IData)(vlTOPp->Top__DOT__add_result)))))));
    if ((1U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffeU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (1U 
                                                  & vlTOPp->io_out));
    }
    if ((2U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffdU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (2U 
                                                  & vlTOPp->io_out));
    }
    if ((4U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffffbU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (4U 
                                                  & vlTOPp->io_out));
    }
    if ((8U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffff7U 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (8U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffefU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffdfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffffbfU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffff7fU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80U 
                                                  & vlTOPp->io_out));
    }
    if ((0x100U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffeffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x100U 
                                                  & vlTOPp->io_out));
    }
    if ((0x200U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffdffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x200U 
                                                  & vlTOPp->io_out));
    }
    if ((0x400U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffffbffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x400U 
                                                  & vlTOPp->io_out));
    }
    if ((0x800U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffff7ffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x800U 
                                                  & vlTOPp->io_out));
    }
    if ((0x1000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffefffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x1000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x2000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffdfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x2000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x4000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffffbfffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x4000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x8000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffff7fffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x8000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffeffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffdffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfffbffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfff7ffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x100000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffefffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x100000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x200000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffdfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x200000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x400000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xffbfffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x400000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x800000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xff7fffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x800000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x1000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfeffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x1000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x2000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfdffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x2000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x4000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xfbffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x4000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x8000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xf7ffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x8000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x10000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xefffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x10000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x20000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xdfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x20000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x40000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0xbfffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x40000000U 
                                                  & vlTOPp->io_out));
    }
    if ((0x80000000U & (vlTOPp->io_out ^ vlTOPp->Top__DOT____Vtogcov__io_out))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlTOPp->Top__DOT____Vtogcov__io_out = ((0x7fffffffU 
                                                & vlTOPp->Top__DOT____Vtogcov__io_out) 
                                               | (0x80000000U 
                                                  & vlTOPp->io_out));
    }
}

void VTop::_eval_initial(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_eval_initial\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VTop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::final\n"); );
    // Variables
    VTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VTop::_eval_settle(VTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_eval_settle\n"); );
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VTop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_opcode = VL_RAND_RESET_I(6);
    io_in1 = VL_RAND_RESET_I(32);
    io_in2 = VL_RAND_RESET_I(32);
    io_out = VL_RAND_RESET_I(32);
    Top__DOT__add_result = VL_RAND_RESET_Q(33);
    Top__DOT__xor_result = VL_RAND_RESET_I(32);
    Top__DOT__or_result = VL_RAND_RESET_I(32);
    Top__DOT__and_result = VL_RAND_RESET_I(32);
    Top__DOT__slt_result = VL_RAND_RESET_I(1);
    Top__DOT____Vtogcov__clock = VL_RAND_RESET_I(1);
    Top__DOT____Vtogcov__reset = VL_RAND_RESET_I(1);
    Top__DOT____Vtogcov__io_opcode = VL_RAND_RESET_I(6);
    Top__DOT____Vtogcov__io_in1 = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__io_in2 = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__io_out = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__add_result = VL_RAND_RESET_Q(33);
    Top__DOT____Vtogcov__xor_result = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__or_result = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__and_result = VL_RAND_RESET_I(32);
    Top__DOT____Vtogcov__sltu_result = VL_RAND_RESET_I(1);
    Top__DOT____Vtogcov__slt_result = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}

void VTop::_configure_coverage(VTop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop::_configure_coverage\n"); );
    // Body
    if (false && vlSymsp && first) {}  // Prevent unused
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "Top.v", 2, 17, ".Top", "v_toggle/Top", "clock", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "Top.v", 3, 17, ".Top", "v_toggle/Top", "reset", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "Top.v", 4, 17, ".Top", "v_toggle/Top", "io_opcode[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "Top.v", 5, 17, ".Top", "v_toggle/Top", "io_in1[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "Top.v", 6, 17, ".Top", "v_toggle/Top", "io_in2[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "Top.v", 7, 17, ".Top", "v_toggle/Top", "io_out[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[111]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[112]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[113]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[114]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[115]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[116]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[117]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[118]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[119]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[120]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[121]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[122]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[123]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[124]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[125]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[126]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[127]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[128]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[129]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[130]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[131]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[132]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[133]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[134]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[135]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[136]), first, "Top.v", 12, 15, ".Top", "v_toggle/Top", "add_result[32]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[137]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[138]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[139]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[140]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[141]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[142]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[143]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[144]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[145]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[146]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[147]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[148]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[149]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[150]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[151]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[152]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[153]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[154]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[155]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[156]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[157]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[158]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[159]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[160]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[161]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[162]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[163]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[164]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[165]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[166]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[167]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[168]), first, "Top.v", 13, 15, ".Top", "v_toggle/Top", "xor_result[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[169]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[170]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[171]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[172]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[173]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[174]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[175]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[176]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[177]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[178]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[179]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[180]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[181]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[182]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[183]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[184]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[185]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[186]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[187]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[188]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[189]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[190]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[191]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[192]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[193]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[194]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[195]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[196]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[197]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[198]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[199]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[200]), first, "Top.v", 14, 15, ".Top", "v_toggle/Top", "or_result[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[201]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[0]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[202]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[1]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[203]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[2]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[204]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[3]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[205]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[4]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[206]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[5]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[207]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[6]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[208]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[7]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[209]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[8]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[210]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[9]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[211]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[10]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[212]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[11]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[213]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[12]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[214]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[13]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[215]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[14]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[216]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[15]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[217]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[16]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[218]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[17]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[219]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[18]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[220]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[19]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[221]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[20]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[222]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[21]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[223]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[22]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[224]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[23]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[225]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[24]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[226]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[25]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[227]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[26]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[228]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[27]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[229]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[28]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[230]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[29]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[231]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[30]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[232]), first, "Top.v", 15, 15, ".Top", "v_toggle/Top", "and_result[31]", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[233]), first, "Top.v", 16, 9, ".Top", "v_toggle/Top", "sltu_result", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[234]), first, "Top.v", 17, 9, ".Top", "v_toggle/Top", "slt_result", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[235]), first, "Top.v", 42, 9, ".Top", "v_branch/Top", "if", "42-43");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[236]), first, "Top.v", 42, 10, ".Top", "v_branch/Top", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[237]), first, "Top.v", 37, 3, ".Top", "v_line/Top", "block", "37");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[238]), first, "Top.v", 51, 7, ".Top", "v_branch/Top", "if", "51-54");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[239]), first, "Top.v", 51, 8, ".Top", "v_branch/Top", "else", "");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[240]), first, "Top.v", 50, 4, ".Top", "v_line/Top", "block", "50,56");
}
