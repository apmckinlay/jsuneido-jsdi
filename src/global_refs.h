/* Copyright 2013 (c) Suneido Software Corp. All rights reserved.
 * Licensed under GPLv2.
 */

#ifndef __INCLUDED_GLOBAL_REFS_H__
#define __INCLUDED_GLOBAL_REFS_H__

/**
 * \file global_refs.h
 * \author Victor Schappert
 * \since 20130624
 * \brief Global references to Java classes, objects, and members which remain
 *        valid between JNI invocations.
 * \see java_enum.h
 *
 * This file contains some automatically-generated code.
 */

#include "jni_exception.h"

#include <jni.h>

namespace jsdi {

/**
 * \brief Contains gobal references to Java classes. <em>Must be properly
 *        initialized</em>!
 * \author Victor Schappert
 * \since 20130624
 *
 * \attention
 * Must be properly initialized &mdash;<em> once, and once only</em> &mdash; by
 * calling #init(JNIEnv *). Use only via the #GLOBAL_REFS pointer.
 *
 * \internal
 * \par
 * This class is set up using private members to \em contain the global
 * references and public inline functions to \em return the global references.
 * The reason for inserting the inline functions getter functions between the
 * private members and clients of this class is to facilitate static analysis
 * and determining whether a particular global reference is unused and should be
 * removed.
 *
 * \par
 * The idea is that all of the member variables are assigned to in the
 * init(JNIEnv *) member function so it will appear to a naive static analysis
 * tool that the members are being assigned to and it may not complain if the
 * member is never used anywhere else in the program. But the only way a client
 * can read the member variable value is by calling a public member function
 * and none of the public member functions are referred to in this translation
 * unit. Thus a static analysis tool should be able to determine whether any
 * public member functions are unused. You can then use that information to
 * eliminate unused global references.
 *
 * \par
 * \em eg <code>cppcheck --enable=unusedFunction</code>
 * \endinternal
 */
struct global_refs
{
    //
    // GLOBAL REFERENCES
    //

    // [BEGIN:GENERATED CODE last updated Fri Aug 01 03:45:11 PDT 2014]
    private:
        jclass java_lang_Object_;
    public:
        jclass java_lang_Object() const
        { return java_lang_Object_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Object</code>.
         * \return <code>java.lang.Object</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Object__m_toString_;
    public:
        jmethodID java_lang_Object__m_toString() const
        { return java_lang_Object__m_toString_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public java.lang.String java.lang.Object.toString()</code>.
         * \return <code>public java.lang.String java.lang.Object.toString()</code>
         * \see jclass java_lang_Object() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_Boolean_;
    public:
        jclass java_lang_Boolean() const
        { return java_lang_Boolean_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Boolean</code>.
         * \return <code>java.lang.Boolean</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Boolean__m_booleanValue_;
    public:
        jmethodID java_lang_Boolean__m_booleanValue() const
        { return java_lang_Boolean__m_booleanValue_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public boolean java.lang.Boolean.booleanValue()</code>.
         * \return <code>public boolean java.lang.Boolean.booleanValue()</code>
         * \see jclass java_lang_Boolean() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jfieldID java_lang_Boolean__f_TRUE_;
    public:
        jfieldID java_lang_Boolean__f_TRUE() const
        { return java_lang_Boolean__f_TRUE_; }
        /**<
         * \brief Returns a global reference to the static field <code>public static final java.lang.Boolean java.lang.Boolean.TRUE</code>.
         * \return <code>public static final java.lang.Boolean java.lang.Boolean.TRUE</code>
         * \see jclass java_lang_Boolean() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jfieldID java_lang_Boolean__f_FALSE_;
    public:
        jfieldID java_lang_Boolean__f_FALSE() const
        { return java_lang_Boolean__f_FALSE_; }
        /**<
         * \brief Returns a global reference to the static field <code>public static final java.lang.Boolean java.lang.Boolean.FALSE</code>.
         * \return <code>public static final java.lang.Boolean java.lang.Boolean.FALSE</code>
         * \see jclass java_lang_Boolean() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_Number_;
    public:
        jclass java_lang_Number() const
        { return java_lang_Number_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Number</code>.
         * \return <code>java.lang.Number</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_Integer_;
    public:
        jclass java_lang_Integer() const
        { return java_lang_Integer_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Integer</code>.
         * \return <code>java.lang.Integer</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Integer__init_;
    public:
        jmethodID java_lang_Integer__init() const
        { return java_lang_Integer__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>public java.lang.Integer(int)</code>.
         * \return <code>public java.lang.Integer(int)</code>
         * \see jclass java_lang_Integer() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Integer__m_intValue_;
    public:
        jmethodID java_lang_Integer__m_intValue() const
        { return java_lang_Integer__m_intValue_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public int java.lang.Integer.intValue()</code>.
         * \return <code>public int java.lang.Integer.intValue()</code>
         * \see jclass java_lang_Integer() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_Long_;
    public:
        jclass java_lang_Long() const
        { return java_lang_Long_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Long</code>.
         * \return <code>java.lang.Long</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Long__init_;
    public:
        jmethodID java_lang_Long__init() const
        { return java_lang_Long__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>public java.lang.Long(long)</code>.
         * \return <code>public java.lang.Long(long)</code>
         * \see jclass java_lang_Long() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Long__m_longValue_;
    public:
        jmethodID java_lang_Long__m_longValue() const
        { return java_lang_Long__m_longValue_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public long java.lang.Long.longValue()</code>.
         * \return <code>public long java.lang.Long.longValue()</code>
         * \see jclass java_lang_Long() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_math_BigDecimal_;
    public:
        jclass java_math_BigDecimal() const
        { return java_math_BigDecimal_; }
        /**<
         * \brief Returns a global reference to the class <code>java.math.BigDecimal</code>.
         * \return <code>java.math.BigDecimal</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_math_BigDecimal__init_;
    public:
        jmethodID java_math_BigDecimal__init() const
        { return java_math_BigDecimal__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>public java.math.BigDecimal(double,java.math.MathContext)</code>.
         * \return <code>public java.math.BigDecimal(double,java.math.MathContext)</code>
         * \see jclass java_math_BigDecimal() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_math_BigDecimal__m_doubleValue_;
    public:
        jmethodID java_math_BigDecimal__m_doubleValue() const
        { return java_math_BigDecimal__m_doubleValue_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public double java.math.BigDecimal.doubleValue()</code>.
         * \return <code>public double java.math.BigDecimal.doubleValue()</code>
         * \see jclass java_math_BigDecimal() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_CharSequence_;
    public:
        jclass java_lang_CharSequence() const
        { return java_lang_CharSequence_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.CharSequence</code>.
         * \return <code>java.lang.CharSequence</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_lang_Enum_;
    public:
        jclass java_lang_Enum() const
        { return java_lang_Enum_; }
        /**<
         * \brief Returns a global reference to the class <code>java.lang.Enum</code>.
         * \return <code>java.lang.Enum</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_lang_Enum__m_ordinal_;
    public:
        jmethodID java_lang_Enum__m_ordinal() const
        { return java_lang_Enum__m_ordinal_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final int java.lang.Enum.ordinal()</code>.
         * \return <code>public final int java.lang.Enum.ordinal()</code>
         * \see jclass java_lang_Enum() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass byte_ARRAY_;
    public:
        jclass byte_ARRAY() const
        { return byte_ARRAY_; }
        /**<
         * \brief Returns a global reference to the class <code>[B</code>.
         * \return <code>[B</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass java_util_Date_;
    public:
        jclass java_util_Date() const
        { return java_util_Date_; }
        /**<
         * \brief Returns a global reference to the class <code>java.util.Date</code>.
         * \return <code>java.util.Date</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_util_Date__init_;
    public:
        jmethodID java_util_Date__init() const
        { return java_util_Date__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>public java.util.Date(long)</code>.
         * \return <code>public java.util.Date(long)</code>
         * \see jclass java_util_Date() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID java_util_Date__m_getTime_;
    public:
        jmethodID java_util_Date__m_getTime() const
        { return java_util_Date__m_getTime_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public long java.util.Date.getTime()</code>.
         * \return <code>public long java.util.Date.getTime()</code>
         * \see jclass java_util_Date() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_jsdi_LogLevel_;
    public:
        jclass suneido_jsdi_LogLevel() const
        { return suneido_jsdi_LogLevel_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.jsdi.LogLevel</code>.
         * \return <code>suneido.jsdi.LogLevel</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_LogLevel__m_values_;
    public:
        jmethodID suneido_jsdi_LogLevel__m_values() const
        { return suneido_jsdi_LogLevel__m_values_; }
        /**<
         * \brief Returns a global reference to the static method <code>public static suneido.jsdi.LogLevel[] suneido.jsdi.LogLevel.values()</code>.
         * \return <code>public static suneido.jsdi.LogLevel[] suneido.jsdi.LogLevel.values()</code>
         * \see jclass suneido_jsdi_LogLevel() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_jsdi_type_Callback_;
    public:
        jclass suneido_jsdi_type_Callback() const
        { return suneido_jsdi_type_Callback_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.jsdi.type.Callback</code>.
         * \return <code>suneido.jsdi.type.Callback</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke() const
        { return suneido_jsdi_type_Callback__m_invoke_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invoke(suneido.SuValue,long[])</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invoke(suneido.SuValue,long[])</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invokeVariableIndirect_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invokeVariableIndirect() const
        { return suneido_jsdi_type_Callback__m_invokeVariableIndirect_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invokeVariableIndirect(suneido.SuValue,long[],java.lang.Object[])</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invokeVariableIndirect(suneido.SuValue,long[],java.lang.Object[])</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke0_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke0() const
        { return suneido_jsdi_type_Callback__m_invoke0_; }
        /**<
         * \brief Returns a global reference to the static method <code>public static final long suneido.jsdi.type.Callback.invoke0(suneido.SuValue)</code>.
         * \return <code>public static final long suneido.jsdi.type.Callback.invoke0(suneido.SuValue)</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke1_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke1() const
        { return suneido_jsdi_type_Callback__m_invoke1_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invoke1(suneido.SuValue,long)</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invoke1(suneido.SuValue,long)</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke2_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke2() const
        { return suneido_jsdi_type_Callback__m_invoke2_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invoke2(suneido.SuValue,long,long)</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invoke2(suneido.SuValue,long,long)</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke3_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke3() const
        { return suneido_jsdi_type_Callback__m_invoke3_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invoke3(suneido.SuValue,long,long,long)</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invoke3(suneido.SuValue,long,long,long)</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_type_Callback__m_invoke4_;
    public:
        jmethodID suneido_jsdi_type_Callback__m_invoke4() const
        { return suneido_jsdi_type_Callback__m_invoke4_; }
        /**<
         * \brief Returns a global reference to the instance method <code>public final long suneido.jsdi.type.Callback.invoke4(suneido.SuValue,long,long,long,long)</code>.
         * \return <code>public final long suneido.jsdi.type.Callback.invoke4(suneido.SuValue,long,long,long,long)</code>
         * \see jclass suneido_jsdi_type_Callback() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_jsdi_com_COMobject_;
    public:
        jclass suneido_jsdi_com_COMobject() const
        { return suneido_jsdi_com_COMobject_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.jsdi.com.COMobject</code>.
         * \return <code>suneido.jsdi.com.COMobject</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_com_COMobject__init_;
    public:
        jmethodID suneido_jsdi_com_COMobject__init() const
        { return suneido_jsdi_com_COMobject__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>suneido.jsdi.com.COMobject(java.lang.String,long,boolean)</code>.
         * \return <code>suneido.jsdi.com.COMobject(java.lang.String,long,boolean)</code>
         * \see jclass suneido_jsdi_com_COMobject() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_com_COMobject__m_isDispatch_;
    public:
        jmethodID suneido_jsdi_com_COMobject__m_isDispatch() const
        { return suneido_jsdi_com_COMobject__m_isDispatch_; }
        /**<
         * \brief Returns a global reference to the instance method <code>private boolean suneido.jsdi.com.COMobject.isDispatch()</code>.
         * \return <code>private boolean suneido.jsdi.com.COMobject.isDispatch()</code>
         * \see jclass suneido_jsdi_com_COMobject() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_com_COMobject__m_verifyNotReleased_;
    public:
        jmethodID suneido_jsdi_com_COMobject__m_verifyNotReleased() const
        { return suneido_jsdi_com_COMobject__m_verifyNotReleased_; }
        /**<
         * \brief Returns a global reference to the instance method <code>private void suneido.jsdi.com.COMobject.verifyNotReleased()</code>.
         * \return <code>private void suneido.jsdi.com.COMobject.verifyNotReleased()</code>
         * \see jclass suneido_jsdi_com_COMobject() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jfieldID suneido_jsdi_com_COMobject__f_ptr_;
    public:
        jfieldID suneido_jsdi_com_COMobject__f_ptr() const
        { return suneido_jsdi_com_COMobject__f_ptr_; }
        /**<
         * \brief Returns a global reference to the instance field <code>private final long suneido.jsdi.com.COMobject.ptr</code>.
         * \return <code>private final long suneido.jsdi.com.COMobject.ptr</code>
         * \see jclass suneido_jsdi_com_COMobject() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_jsdi_com_COMException_;
    public:
        jclass suneido_jsdi_com_COMException() const
        { return suneido_jsdi_com_COMException_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.jsdi.com.COMException</code>.
         * \return <code>suneido.jsdi.com.COMException</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_com_COMException__init_;
    public:
        jmethodID suneido_jsdi_com_COMException__init() const
        { return suneido_jsdi_com_COMException__init_; }
        /**<
         * \brief Returns a global reference to the constructor <code>public suneido.jsdi.com.COMException(java.lang.String)</code>.
         * \return <code>public suneido.jsdi.com.COMException(java.lang.String)</code>
         * \see jclass suneido_jsdi_com_COMException() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_jsdi_suneido_protocol_InternetProtocol_;
    public:
        jclass suneido_jsdi_suneido_protocol_InternetProtocol() const
        { return suneido_jsdi_suneido_protocol_InternetProtocol_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.jsdi.suneido_protocol.InternetProtocol</code>.
         * \return <code>suneido.jsdi.suneido_protocol.InternetProtocol</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_jsdi_suneido_protocol_InternetProtocol__m_start_;
    public:
        jmethodID suneido_jsdi_suneido_protocol_InternetProtocol__m_start() const
        { return suneido_jsdi_suneido_protocol_InternetProtocol__m_start_; }
        /**<
         * \brief Returns a global reference to the static method <code>public static byte[] suneido.jsdi.suneido_protocol.InternetProtocol.start(java.lang.String)</code>.
         * \return <code>public static byte[] suneido.jsdi.suneido_protocol.InternetProtocol.start(java.lang.String)</code>
         * \see jclass suneido_jsdi_suneido_protocol_InternetProtocol() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jclass suneido_language_Numbers_;
    public:
        jclass suneido_language_Numbers() const
        { return suneido_language_Numbers_; }
        /**<
         * \brief Returns a global reference to the class <code>suneido.language.Numbers</code>.
         * \return <code>suneido.language.Numbers</code>
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jmethodID suneido_language_Numbers__m_narrow_;
    public:
        jmethodID suneido_language_Numbers__m_narrow() const
        { return suneido_language_Numbers__m_narrow_; }
        /**<
         * \brief Returns a global reference to the static method <code>public static java.lang.Number suneido.language.Numbers.narrow(java.lang.Number)</code>.
         * \return <code>public static java.lang.Number suneido.language.Numbers.narrow(java.lang.Number)</code>
         * \see jclass suneido_language_Numbers() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    private:
        jfieldID suneido_language_Numbers__f_MC_;
    public:
        jfieldID suneido_language_Numbers__f_MC() const
        { return suneido_language_Numbers__f_MC_; }
        /**<
         * \brief Returns a global reference to the static field <code>public static final java.math.MathContext suneido.language.Numbers.MC</code>.
         * \return <code>public static final java.math.MathContext suneido.language.Numbers.MC</code>
         * \see jclass suneido_language_Numbers() const
         *
         * Auto-generated by <code>suneido.jsdi.tools.GenerateGlobalReferences</code>.
         */
    // [END:GENERATED CODE]

    //
    // NON-GENERATED GLOBAL REFERENCES
    //

    private:
        jobject TRUE_object_;
        jobject FALSE_object_;
        jobject ZERO_object_;
        jstring EMPTY_STRING_object_;
    public:
        /**
         * \brief Returns a global reference corresponding to
         *        <code>java.lang.Boolean.TRUE</code>.
         * \return <code>java.lang.Boolean.TRUE</code>
         * \see #FALSE_object() const
         * \see #ZERO_object() const
         */
        jobject TRUE_object() const
        { return TRUE_object_; }
        /**
         * \brief Returns a global reference corresponding to
         *        <code>java.lang.Boolean.FALSE</code>.
         * \return <code>java.lang.Boolean.FALSE</code>
         * \see #TRUE_object() const
         * \see #ZERO_object() const
         */
        jobject FALSE_object() const
        { return FALSE_object_; }
        /**
         * \brief Returns a global reference to a Java <code>Integer</code>
         *        which contains the value 0.
         * \return A <code>java.lang.Integer</code> equal to zero
         * \see #TRUE_object() const
         * \see #FALSE_object() const
         * \see #EMPTY_STRING_object() const
         */
        jobject ZERO_object() const
        { return ZERO_object_; }
        /**
         * \brief Returns a global reference to a Java <code>String</code> which
         *        contains the empty string.
         * \return A <code>java.lang.String</code> equal to <code>""</code>.
         * \see #ZERO_object() const
         */
        jstring EMPTY_STRING_object() const
        { return EMPTY_STRING_object_; }

    //
    // INITIALIZATION
    //

    /**
     * \brief Initializes #GLOBAL_REFS
     * \param env Valid pointer to the JNI environment
     * \throws jni_exception If a JNI error occurs initializing any global
     *         reference.
     *
     * Call this function once, and once only, before the first use of the
     * global references. After initialization, the #GLOBAL_REFS pointer may
     * validly be used to access global references.
     */
    static void init(JNIEnv * env);
};


/**
 * \brief Global pointer to the global global_refs structure
 *
 * Do not use until global_refs::init(JNIEnv *) has been called!
 */
extern global_refs const * const GLOBAL_REFS;

} // namespace jsdi

#endif // __INCLUDED_GLOBAL_REFS_H__
