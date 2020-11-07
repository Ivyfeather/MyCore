// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop__Syms.h"
#include "VTop.h"
#include "VTop_Endian.h"



// FUNCTIONS
VTop__Syms::VTop__Syms(VTop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_dumping(false)
    , __Vm_dumperp(nullptr)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__Soc__DOT__ram__DOT__ed1(Verilated::catName(topp->name(), "Soc.ram.ed1"))
    , TOP__Soc__DOT__ram__DOT__ed2(Verilated::catName(topp->name(), "Soc.ram.ed2"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__Soc__DOT__ram__DOT__ed1 = &TOP__Soc__DOT__ram__DOT__ed1;
    TOPp->__PVT__Soc__DOT__ram__DOT__ed2 = &TOP__Soc__DOT__ram__DOT__ed2;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__Soc__DOT__ram__DOT__ed1.__Vconfigure(this, true);
    TOP__Soc__DOT__ram__DOT__ed2.__Vconfigure(this, false);
}
