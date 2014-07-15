/* Copyright 2014 (c) Suneido Software Corp. All rights reserved.
 * Licensed under GPLv2.
 */

//==============================================================================
// file: invoke64.cpp
// auth: Victor Schappert
// date: 20140707
// desc: Windows x64 ABI invocation translation unit
//==============================================================================

#include "invoke64.h"

#ifndef __NOTEST__

#include "test.h"
#include "test_exports.h"

#include "jsdi_windows.h"
#include "util.h"

namespace {

// HELPER FUNCTIONS

template <typename T>
static bool copy_to(const T& src, uint64_t * dst, size_t capacity /* in uint64_t */)
{
    if (sizeof(src) <= sizeof(uint64_t) * capacity)
    {
        std::memcpy(dst, &src, sizeof(src));
        return true;
    }
    return false;
}

// EXTRA TEST FUNCTIONS

int32_t sum_string_byval(Recursive_StringSum x)
{ return TestSumString(&x); }

uint64_t divide(uint64_t a, uint64_t b)
{ return a / b; /* if b == 0, raises EXCEPTION_INT_DIVIDE_BY_ZERO */ }

} // anonymous namespace 

TEST(basic_int8,
    int8_t x = static_cast<int8_t>('J');
    uint64_t a;
    assert_true(copy_to(x, &a, 1));
    int8_t result = static_cast<int8_t>(invoke64_basic(sizeof(a), &a, TestInt8));
    assert_equals(result, static_cast<int8_t>('J'));
);

TEST(basic_int32,
    constexpr size_t N = 9;
    void * f[] = { TestInt32, TestSumTwoInt32s, TestSumThreeInt32s,
                   TestSumFourInt32s, TestSumFiveInt32s, TestSumSixInt32s,
                   TestSumSevenInt32s, TestSumEightInt32s, TestSumNineInt32s };
    uint64_t a[N];
    uint64_t sum;
    for (size_t i = 0; i < N; ++i)
    {
        sum = 0;
        for (size_t j = 0; j <= i; ++j)
        {
            a[j] = i + j;
            sum += a[j];
        }
        int32_t result = static_cast<int32_t>(invoke64_basic(
                                              (i + 1) * sizeof(uint64_t), &a, f[i]));
        assert_equals(static_cast<int32_t>(sum), result);
    }
);

TEST(basic_swap,
    // Simple test passing one argument by pointer.
    Swap_StringInt32Int32 s, * ps(&s);
    s.str = nullptr;
    s.a = 33;
    s.b = 33;
    assert_true(static_cast<int32_t>(invoke64_basic(sizeof(ps), &ps, TestSwap)));
    assert_equals(33, s.a);
    assert_equals(33, s.b);
    assert_equals(std::string("="), s.str);
    ++s.b;
    assert_false(static_cast<int32_t>(invoke64_basic(sizeof(ps), &ps, TestSwap)));
    assert_equals(34, s.a);
    assert_equals(33, s.b);
    assert_equals(std::string("!="), s.str);
);

TEST(basic_aligned_byval,
    // Pass an "aligned" struct by value. Because the size is a power of 2 and
    // it is 8 bytes or less, it actually goes by value.
    Packed_Int8Int8Int16Int32 a = { -1, -2, -3, -4 };
    static_assert(8 == sizeof(a), "test assumes wrong structure size");
    uint64_t b(0);
    assert_true(copy_to(a, &b, 1));
    int32_t result = static_cast<int32_t>(invoke64_basic(sizeof(b), &b,
                                          TestSumPackedInt8Int8Int16Int32));
    assert_equals(result, -10);
);

TEST(basic_unaligned_byval,
    // Pass an "unaligned" struct by value.  Because the size is not a power of
    // 2, it secretly has to be passed by pointer according to the x64 ABI.
    Packed_Int8x3 u = { -5, 13, -1 }, *pu(&u);
    static_assert(3 == sizeof(u), "test assumes wrong structure size");
    int32_t result = static_cast<int32_t>(invoke64_basic(sizeof(pu), &pu,
                                                         TestSumPackedInt8x3));
    assert_equals(result, 7);
);

TEST(basic_oversize_byval,
    // Pass an "oversized" struct by value. Because the size is greater than 8,
    // it secretly has to be passed by pointer according to the x64 ABI.
    Recursive_StringSum r, * pr(&r);
    static_assert(48 == sizeof(r), "test assumes wrong structure size");
    char buffer[16];
    r.x[0].a = 10; r.x[0].b =  20; r.x[0].c =  30; r.x[0].d =  40;
    r.x[1].a = -5; r.x[1].b = -15; r.x[1].c = -25; r.x[1].d = -35;
    r.str = "-45";
    r.buffer = buffer;
    r.len = jsdi::array_length(buffer);
    r.inner = nullptr;
    int32_t result = static_cast<int32_t>(invoke64_basic(sizeof(pr), &pr,
                                                         sum_string_byval));
    assert_equals(-25, result);
    assert_equals(std::string("-25"), buffer);
);

TEST(basic_comprehensive,
    // This test has a number of purposes:
    //     1) It tests the potential boundary condition of 9 arguments.
    //     2) It tests pass-by-value structs both in the four register slots
    //        and in the stack slots.
    //     3) Of the pass-by-value structs, it tests both types that go on the
    //        stack and those that go by pointer.
    int8_t a(0);
    int16_t b(1);
    int32_t c(2);
    Swap_StringInt32Int32 d = { nullptr, -1, 1 }, * pd(&d); // This contributes 0 to sum
    int64_t e(3);
    Packed_Int8Int8Int16Int32 f = { 4, 5, 6, 7 };
    Packed_Int8x3 g = { 8, 9, 10 }, * pg(&g);
    Recursive_StringSum h = { { { 11, 12, 13, 14 }, { 15, 16, 17, 18 } }, "19", nullptr, 0, nullptr }, * ph(&h);
    Recursive_StringSum i = { { { 20, 21, 22, 23 }, { 24, 25, 26, 27 } }, "28", nullptr, 0, nullptr }, * pi(&i);
    uint64_t args[9];
    assert_true(copy_to(a,  &args[0], 1));
    assert_true(copy_to(b,  &args[1], 1));
    assert_true(copy_to(c,  &args[2], 1));
    static_assert(16 == sizeof(d), "test assumes wrong structure size");
    assert_true(copy_to(pd, &args[3], 1)); // Pointer because > 8 bytes
    assert_true(copy_to(e,  &args[4], 1));
    assert_true(copy_to(f,  &args[5], 1));
    static_assert(3 == sizeof(g), "test assumes wrong structure size");
    assert_true(copy_to(pg, &args[6], 1)); // Pointer because size not power of 2
    static_assert(48 == sizeof(h), "test assumes wrong structure size");
    assert_true(copy_to(ph, &args[7], 1)); // Pointer because > 8 bytes
    assert_true(copy_to(pi, &args[8], 1)); // Pointer because parameter is pass by pointer
    int64_t result = static_cast<int64_t>(invoke64_basic(sizeof(args), args,
                                                         TestSumManyInts));
    assert_equals(406, result);
);

TEST(basic_seh,
    // This test ensures that on a basic level, the invoke64_basic() function
    // works with Windows structured exception handling.
    uint64_t a[] = { 0, 0 };
    bool caught = false;
    __try
    { invoke64_basic(sizeof(a), a, divide); } 
    __except(GetExceptionCode() == EXCEPTION_INT_DIVIDE_BY_ZERO ? 
             EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    { caught = true; }
    assert_true(caught);
);

#endif // __NOTEST__