/* ------------------------------------------------------------------
 * Copyright (C) 1998-2010 PacketVideo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 * -------------------------------------------------------------------
 */
/*  Filename: dct_inline.h                                                      */
/*  Description: Implementation for in-line functions used in dct.cpp           */
/*  Modified:                                                                   */
/*********************************************************************************/
#ifndef _DCT_INLINE_H_
#define _DCT_INLINE_H_

#include "oscl_base_macros.h"// has integer values of PV_COMPILER

#if   ((PV_CPU_ARCH_VERSION >=5) && (PV_COMPILER == EPV_ARM_GNUC))/* ARM GNU COMPILER  */

__inline int32 mla724(int32 op1, int32 op2, int32 op3)
{
    register int32 out;
    register int32 aa = (int32)op1;
    register int32 bb = (int32)op2;
    register int32 cc = (int32)op3;

    asm volatile("smlabb %0, %1, %2, %3"
             : "=&r"(out)
                         : "r"(aa),
                         "r"(bb),
                         "r"(cc));
    return out;
}


__inline int32 mla392(int32 k0, int32 k14, int32 round)
{
    register int32 out;
    register int32 aa = (int32)k0;
    register int32 bb = (int32)k14;
    register int32 cc = (int32)round;

    asm volatile("smlabt %0, %1, %2, %3"
             : "=&r"(out)
                         : "r"(aa),
                         "r"(bb),
                         "r"(cc));

    return out;
}

__inline int32 mla554(int32 k4, int32 k12, int32 k1)
{
    register int32 out;
    register int32 aa = (int32)k4;
    register int32 bb = (int32)k12;
    register int32 cc = (int32)k1;

    asm volatile("smlabt %0, %1, %2, %3"
             : "=&r"(out)
                         : "r"(aa),
                         "r"(bb),
                         "r"(cc));

    return out;
}

__inline int32 mla1338(int32 k6, int32 k14, int32 k1)
{
    register int32 out;
    register int32 aa = (int32)k6;
    register int32 bb = (int32)k14;
    register int32 cc = (int32)k1;

    asm volatile("smlabb %0, %1, %2, %3"
             : "=&r"(out)
                         : "r"(aa),
                         "r"(bb),
                         "r"(cc));
    return out;
}

__inline int32 mla946(int32 k6, int32 k14, int32 k1)
{
    register int32 out;
    register int32 aa = (int32)k6;
    register int32 bb = (int32)k14;
    register int32 cc = (int32)k1;

    asm volatile("smlabb %0, %1, %2, %3"
             : "=&r"(out)
                         : "r"(aa),
                         "r"(bb),
                         "r"(cc));
    return out;
}

__inline int32 sum_abs(int32 k0, int32 k1, int32 k2, int32 k3,
                       int32 k4, int32 k5, int32 k6, int32 k7)
{
    register int32 carry;
    register int32 abs_sum;
    register int32 aa = (int32)k0;
    register int32 bb = (int32)k1;
    register int32 cc = (int32)k2;
    register int32 dd = (int32)k3;
    register int32 ee = (int32)k4;
    register int32 ff = (int32)k5;
    register int32 gg = (int32)k6;
    register int32 hh = (int32)k7;

    asm volatile("eor  %0, %2, %2, asr #31\n\t"
                 "eors %1, %3, %3, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %4, %4, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %5, %5, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %6, %6, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %7, %7, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %8, %8, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"
                 "eors %0, %9, %9, asr #31\n\t"
                 "adc  %1, %1, %0\n\t"

             : "=&r"(carry),
                 "=&r"(abs_sum):
                         "r"(aa),
                         "r"(bb),
                         "r"(cc),
                         "r"(dd),
                         "r"(ee),
                         "r"(ff),
                         "r"(gg),
                         "r"(hh));

    return abs_sum;
}
#else/*#else for #if (PV_CPU_ARCH_VERSION>=4 && PV_COMPILER==EPV_ARM_RVCT) */
/*C Equivalent code*/
#include "oscl_base_macros.h"

__inline int32 mla724(int32 op1, int32 op2, int32 op3)
{
    int32 out;

    OSCL_UNUSED_ARG(op2);

    out = op1 * 724 + op3; /* op2 is not used here */

    return out;
}

__inline int32 mla392(int32 k0, int32 k14, int32 round)
{
    int32 k1;

    OSCL_UNUSED_ARG(k14);

    k1 = k0 * 392 + round;

    return k1;
}

__inline int32 mla554(int32 k4, int32 k12, int32 k1)
{
    int32 k0;

    OSCL_UNUSED_ARG(k12);

    k0 = k4 * 554 + k1;

    return k0;
}

__inline int32 mla1338(int32 k6, int32 k14, int32 k1)
{
    int32 out;

    OSCL_UNUSED_ARG(k14);

    out = k6 * 1338 + k1;

    return out;
}

__inline int32 mla946(int32 k6, int32 k14, int32 k1)
{
    int32 out;

    OSCL_UNUSED_ARG(k14);

    out = k6 * 946 + k1;

    return out;
}

__inline int32 sum_abs(int32 k0, int32 k1, int32 k2, int32 k3,
                       int32 k4, int32 k5, int32 k6, int32 k7)
{
    int32 carry, abs_sum;

    carry = k0 >> 31;
    abs_sum = (k0 ^ carry);
    carry = k1 >> 31;
    abs_sum += (k1 ^ carry) - carry;
    carry = k2 >> 31;
    abs_sum += (k2 ^ carry) - carry;
    carry = k3 >> 31;
    abs_sum += (k3 ^ carry) - carry;
    carry = k4 >> 31;
    abs_sum += (k4 ^ carry) - carry;
    carry = k5 >> 31;
    abs_sum += (k5 ^ carry) - carry;
    carry = k6 >> 31;
    abs_sum += (k6 ^ carry) - carry;
    carry = k7 >> 31;
    abs_sum += (k7 ^ carry) - carry;

    return abs_sum;
}
#endif /*#endif for (PV_CPU_ARCH_VERSION>=4 && PV_COMPILER==EPV_ARM_RVCT) */

#endif //_DCT_INLINE_H_
