#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdint.h>
#include <assert.h>

#ifdef __RV32__
    typedef uint32_t wlen_t;
#else
    typedef uint64_t wlen_t;
#endif

typedef uint32_t mask_t;

#define NUM_REGS 32
#define START_ADDR 0x80000000

#endif