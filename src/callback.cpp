/* Copyright 2013 (c) Suneido Software Corp. All rights reserved.
 * Licensed under GPLv2.
 */

//==============================================================================
// file: callback.cpp
// auth: Victor Schappert
// date: 20130804
// desc: Implementation of generic interface for a callback function
//==============================================================================

#include "callback.h"

namespace jsdi {

callback::callback(jint size_direct, jint size_total, jint const * ptr_array,
                   jint ptr_array_size, jint vi_count)
    : d_ptr_array(ptr_array, ptr_array + ptr_array_size)
    , d_size_direct(size_direct)
    , d_size_total_bytes(size_total)
    , d_size_total_words(marshalling_util::num_whole_words_exact(size_total))
    , d_vi_count(vi_count)
{
    assert(0 < size_direct || !"direct size must be positive");
    assert(size_direct <= size_total || !"direct size can't exceed total size");
    assert(0 <= ptr_array_size || !"pointer array size cannot be negative");
    assert(0 <= vi_count || !"variable indirect count cannot be negative");
}

} // namespace jsdi
