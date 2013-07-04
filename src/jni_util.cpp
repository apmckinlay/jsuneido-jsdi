//==============================================================================
// file: jni_util.cpp
// auth: Victor Schappert
// date: 20130627
// desc: Implementation of utility functions to simplify working with JNI.
//==============================================================================

#include "jni_util.h"

namespace jsdi {

//==============================================================================
//                      class jni_utf8_output_streambuf
//==============================================================================

jni_utf8_output_streambuf::jni_utf8_output_streambuf(JNIEnv * env,
                                                     size_t capacity)
    : d_env(env)
    , d_buf(capacity + 1)    // leave one character at the end for NUL
{
    char * base = &d_buf.front();
    setp(base, base + d_buf.size() - 1);
}

jni_utf8_output_streambuf::int_type jni_utf8_output_streambuf::overflow(
    int_type ch)
{
    if (traits_type::eof() != ch)
    {
        if (pptr() < epptr())
        {
            size_t size = d_buf.size();
            d_buf.resize(2 * size);
            char * base = &d_buf.front();
            setp(base, base + size - 1);
            pbump(size);
        }
        *pptr() = traits_type::to_char_type(ch);
        pbump(1);
        return ch;
    }
    else return traits_type::eof();
}

} // namespace jsdi
