/* Copyright 2013 (c) Suneido Software Corp. All rights reserved.
 * Licensed under GPLv2.
 */

//==============================================================================
// file: heap.cpp
// auth: Victor Schappert
// date: 20130802
// desc: Implements C++ wrapper for a Win32 heap
//==============================================================================

#include "heap.h"

#include "jsdi_windows.h"

#include <cassert>
#include <memory>

namespace jsdi {

//==============================================================================
//                                  INTERNALS
//==============================================================================

namespace {

// For some reason, this flag isn't defined in many versions of windows.h
#ifndef HEAP_CREATE_ENABLE_EXECUTE
enum { HEAP_CREATE_ENABLE_EXECUTE = 0x00040000 };
#endif

inline DWORD flags(bool is_executable)
{ return is_executable ? HEAP_CREATE_ENABLE_EXECUTE : 0; }

} // anonymous namespace

//==============================================================================
//                                class heap
//==============================================================================

struct heap_impl
{
    HANDLE      d_hheap;
    std::string d_name;
};

heap::heap(const char * name, bool is_executable) : d_impl(nullptr)
{
    assert(name || !"heap name cannot be null");
    std::unique_ptr<heap_impl> tmp(new heap_impl);
    tmp->d_hheap = HeapCreate(
        flags(is_executable),
        0 /* default size */,
        0 /* growable */
    );
    if (! tmp->d_hheap) throw std::bad_alloc();
    tmp->d_name.assign(name);
    d_impl = tmp.release();
}

heap::~heap()
{
    assert(d_impl && d_impl->d_hheap);
#ifndef NDEBUG
    BOOL success =
#endif
    HeapDestroy(d_impl->d_hheap);
    delete d_impl;
    assert(success || !"failed to destroy Win32 heap");
}

const std::string& heap::name() const
{ return d_impl->d_name; }

void * heap::alloc(size_t n)
{
    assert(d_impl && d_impl->d_hheap);
    void * ptr = HeapAlloc(d_impl->d_hheap, 0, n);
    if (! ptr) throw std::bad_alloc();
    return ptr;
}

void heap::free(void * ptr) noexcept
{
    assert(d_impl && d_impl->d_hheap);
#ifndef NDEBUG
    BOOL success =
#endif
    HeapFree(d_impl->d_hheap, 0, ptr);
    assert(success || !"failed to free heap memory");
}

} // namespace jsdi

//==============================================================================
//                                  TESTS
//==============================================================================

#ifndef __NOTEST__

#include "test.h"

#include <cstring>

using namespace jsdi;

#if defined(_M_IX86)

// Calls the code block pointed to by 'code', which must simply copy the
// value 27 into the register 'eax' and return.
#ifdef __GNUC__
#define CALL_COPY_27(code, receives_27) \
    asm (                               \
        "call * %1"                     \
        : "=a" (receives_27)            \
        : "0" (code)                    \
        :                               \
    );
#elif defined(_MSC_VER)
#define CALL_COPY_27(code, receives_27) \
    __asm                               \
    {                                   \
        __asm mov  eax, code            \
        __asm call eax                  \
        __asm mov  receives_27, eax     \
    }
#else
#error replacement for inline assembler required
#endif

#endif // #if defined(_M_IX86)

TEST(heap_basic,
    heap h("my heap", false);
    char * str = reinterpret_cast<char *>(
                     h.alloc(std::strlen("bonjour monde") + 1));
    assert_true(str);
    std::strcpy(str, "bonjour monde");
    assert_equals(std::string("bonjour monde"), str);
    h.free(str);
);

#if defined(_M_IX86)

TEST(heap_exec_x86,
    constexpr unsigned char CODE[] =
    {
        0xb8, 0x1b, 0x00, 0x00, 0x00, // movl 0x0000001b, %eax
        0xc3                          // ret
    };
    heap h("exeheap", true);
    void * code = h.alloc(sizeof(CODE));
    std::memcpy(code, CODE, sizeof(CODE));
    int should_be_27(0xffffff00);
    CALL_COPY_27(code, should_be_27);
    assert_equals(27, should_be_27);
);

#endif // #if defined(_M_IX86)

#endif // #ifndef __NOTEST__
