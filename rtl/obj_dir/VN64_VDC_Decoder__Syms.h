// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VN64_VDC_DECODER__SYMS_H_
#define _VN64_VDC_DECODER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VN64_VDC_Decoder.h"

// SYMS CLASS
class VN64_VDC_Decoder__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VN64_VDC_Decoder*              TOPp;
    
    // CREATORS
    VN64_VDC_Decoder__Syms(VN64_VDC_Decoder* topp, const char* namep);
    ~VN64_VDC_Decoder__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
