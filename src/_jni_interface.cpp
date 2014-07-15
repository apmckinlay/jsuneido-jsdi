/* Copyright 2013 (c) Suneido Software Corp. All rights reserved.
 * Licensed under GPLv2.
 */

//==============================================================================
// file: _jni_interface.cpp
// auth: Victor Schappert
// date: 20130618
// desc: JVM's interface, via JNI, into the JSDI DLL.
//       (This translation unit contains general functions available regardless
//       of what ABI the DLL is compiled for.)
//==============================================================================

#include "com.h"
#include "global_refs.h"
#include "log.h"
#include "jni_exception.h"
#include "jni_util.h"
#include "jsdi_windows.h"
#include "suneido_protocol.h"
#include "version.h"

#include <cassert>

using namespace jsdi;

//==============================================================================
//                                INTERNALS
//==============================================================================

/* TODO: do we need to be able to handle Win32 exceptions? If so, we'll want
 *       to wrap things in SEH code *at some level*. But do we want that
 *       overhead around every DLL call, regardless of whether it is expected
 *       to throw an exception? [See NOTES A-D in jsdi_callback.cpp]
 */

namespace {

void check_array_atleast(jsize size, const char * array_name, JNIEnv * env,
                         jarray array)
{
    if (env->GetArrayLength(array) < size)
    {
        std::ostringstream() << array_name << " must have length at least "
                             << size << throw_cpp<std::runtime_error>();
    }
}

void check_array_atleast_1(const char * array_name, JNIEnv * env, jarray array)
{ check_array_atleast(1, array_name, env, array); }

} // anonymous namespace

extern "C" {

//==============================================================================
//                  JAVA CLASS: suneido.language.jsdi.JSDI
//==============================================================================

#include "gen/suneido_language_jsdi_JSDI.h"
    // This #include isn't strictly necessary -- the only caller of these
    // functions is the JVM. However, it is useful to have the generated code
    // around. Also, because you can only have one extern "C" symbol with the
    // same name, including the header allows the compiler to find prototype
    // declaration/definition conflicts.

JNIEXPORT void JNICALL Java_suneido_language_jsdi_JSDI_init
  (JNIEnv * env, jclass)
{
    JNI_EXCEPTION_SAFE_BEGIN;
    log_manager::instance().set_path(std::string("jsdi.log"));
    LOG_TRACE("Initializing JSDI library built " << version::BUILD_DATE);
    JavaVM * vm(nullptr);
    if (JNI_OK == env->GetJavaVM(&vm))
    {
        global_refs::init(env);
        suneido_protocol::register_handler(vm);
        // TODO: presently no-one is calling suneido_protocol::unregister_handler()
    }
    else throw std::runtime_error("Failed to obtain JavaVM in JSDI.init()");
    LOG_TRACE("JSDI library initialized OK");
    JNI_EXCEPTION_SAFE_END(env);
}

JNIEXPORT jstring JNICALL Java_suneido_language_jsdi_JSDI_when
  (JNIEnv * env, jclass)
{
    jstring result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    jni_utf16_ostream o(env);
    o << version::BUILD_DATE;
    result = o.jstr();
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

//==============================================================================
//             JAVA CLASS: suneido.language.jsdi.dll.DllFactory
//==============================================================================

#include "gen/suneido_language_jsdi_dll_DllFactory.h"
    // This #include isn't strictly necessary -- the only caller of these
    // functions is the JVM. However, it is useful to have the generated code
    // around. Also, because you can only have one extern "C" symbol with the
    // same name, including the header allows the compiler to find prototype
    // declaration/definition conflicts.

/*
 * Class:     suneido_language_jsdi_dll_DllFactory
 * Method:    loadLibrary
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_suneido_language_jsdi_dll_DllFactory_loadLibrary
  (JNIEnv * env, jclass, jstring libraryName)
{
    jlong result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    jni_utf16_string_region libraryName_(env, libraryName);
    HMODULE hmodule = LoadLibraryW(libraryName_.wstr());
    result = reinterpret_cast<jlong>(hmodule);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

/*
 * Class:     suneido_language_jsdi_dll_DllFactory
 * Method:    freeLibrary
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_dll_DllFactory_freeLibrary
  (JNIEnv * env, jclass, jlong hModule)
{
    FreeLibrary(reinterpret_cast<HMODULE>(hModule));
}

/*
 * Class:     suneido_language_jsdi_dll_DllFactory
 * Method:    getProcAddress
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_suneido_language_jsdi_dll_DllFactory_getProcAddress
  (JNIEnv * env, jclass, jlong hModule, jstring procName)
{
    jlong result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    jni_utf8_string_region procName_(env, procName);
    FARPROC addr = GetProcAddress(reinterpret_cast<HMODULE>(hModule),
        procName_.str());
        // NOTE: There is no GetProcAddressW... GetProcAddress() only accepts
        //       ANSI strings.
    result = reinterpret_cast<jlong>(addr);
    LOG_DEBUG("GetProcAddress('" << procName_.str() << "') => " << addr);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

//==============================================================================
//             JAVA CLASS: suneido.language.jsdi.com.COMobject
//==============================================================================

#include "gen/suneido_language_jsdi_com_COMobject.h"
    // This #include isn't strictly necessary -- the only caller of these
    // functions is the JVM. However, it is useful to have the generated code
    // around. Also, because you can only have one extern "C" symbol with the
    // same name, including the header allows the compiler to find prototype
    // declaration/definition conflicts.

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    queryIDispatchAndProgId
 * Signature: (J[Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_suneido_language_jsdi_com_COMobject_queryIDispatchAndProgId(
    JNIEnv * env, jclass, jlong ptrToIUnknown,
    jobjectArray /* String[] */ progid)
{
    IUnknown * iunk(reinterpret_cast<IUnknown *>(ptrToIUnknown));
    IDispatch * idisp(0);
    JNI_EXCEPTION_SAFE_BEGIN
    check_array_atleast_1("progid", env, progid); // check first, as may throw
    idisp = com::query_for_dispatch(iunk);
    if (idisp)
    {
        jni_auto_local<jstring> progid_jstr(env, com::get_progid(idisp, env));
        env->SetObjectArrayElement(progid, 0,
                                   static_cast<jstring>(progid_jstr));
    }
    JNI_EXCEPTION_SAFE_END(env);
    return reinterpret_cast<jlong>(idisp);
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    coCreateFromProgId
 * Signature: (Ljava/lang/String;[J)Z
 */
JNIEXPORT jboolean JNICALL Java_suneido_language_jsdi_com_COMobject_coCreateFromProgId(
    JNIEnv * env, jclass, jstring progid, jlongArray ptrPair)
{
    jboolean did_create_object(false);
    JNI_EXCEPTION_SAFE_BEGIN
    IUnknown * iunk(0);
    IDispatch * idisp(0);
    check_array_atleast(2, "ptrPair", env, ptrPair); // check before creating
    if (com::create_from_progid(env, progid, iunk, idisp))
    {
        assert(iunk || idisp);
        const jlong ptrs[2] =
        {
            reinterpret_cast<jlong>(idisp),
            reinterpret_cast<jlong>(iunk),
        };
        env->SetLongArrayRegion(ptrPair, 0, 2, ptrs);
        did_create_object = true;
    }
    JNI_EXCEPTION_SAFE_END(env);
    return did_create_object;
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    release
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_com_COMobject_release
 (JNIEnv * env, jclass, jlong ptrToIDispatch, jlong ptrToIUnknown)
{
    JNI_EXCEPTION_SAFE_BEGIN
    if (ptrToIDispatch)
        reinterpret_cast<IDispatch *>(ptrToIDispatch)->Release();
    if (ptrToIUnknown)
        reinterpret_cast<IUnknown *>(ptrToIUnknown)->Release();
    JNI_EXCEPTION_SAFE_END(env);
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    getPropertyByName
 * Signature: (JLjava/lang/String;[I)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_suneido_language_jsdi_com_COMobject_getPropertyByName(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jstring name, jintArray dispid)
{
    jobject result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    DISPID dispid_(com::get_dispid_of_name(idisp, env, name));
    // Check the dispid array before getting the property so that we don't throw
    // an exception while we have a local reference to be freed...
    check_array_atleast_1("dispid", env, dispid);
    env->SetIntArrayRegion(dispid, 0, 1,
                           reinterpret_cast<const jint *>(&dispid_));
    result = com::property_get(idisp, dispid_, env);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    getPropertyByDispId
 * Signature: (JI)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_suneido_language_jsdi_com_COMobject_getPropertyByDispId(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jint dispid)
{
    jobject result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    result = com::property_get(idisp, static_cast<DISPID>(dispid), env);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    putPropertyByName
 * Signature: (JLjava/lang/String;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_suneido_language_jsdi_com_COMobject_putPropertyByName(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jstring name, jobject value)
{
    DISPID dispid(0);
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    dispid = com::get_dispid_of_name(idisp, env, name);
    com::property_put(idisp, dispid, env, value);
    JNI_EXCEPTION_SAFE_END(env);
    return dispid;
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    putPropertyByDispId
 * Signature: (JILjava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_com_COMobject_putPropertyByDispId(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jint dispid, jobject value)
{
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    com::property_put(idisp, static_cast<DISPID>(dispid), env, value);
    JNI_EXCEPTION_SAFE_END(env);
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    callMethodByName
 * Signature: (JLjava/lang/String;[Ljava/lang/Object;[I)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_suneido_language_jsdi_com_COMobject_callMethodByName(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jstring name, jobjectArray args,
    jintArray dispid)
{
    jobject result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    DISPID dispid_(com::get_dispid_of_name(idisp, env, name));
    // Check the dispid array before calling the method so that we don't throw
    // an exception while we have a local reference to be freed...
    check_array_atleast_1("dispid", env, dispid);
    env->SetIntArrayRegion(dispid, 0, 1,
                           reinterpret_cast<const jint *>(&dispid_));
    result = com::call_method(idisp, dispid_, env, args);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

/*
 * Class:     suneido_language_jsdi_com_COMobject
 * Method:    callMethodByDispId
 * Signature: (JI[Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_suneido_language_jsdi_com_COMobject_callMethodByDispId(
    JNIEnv * env, jclass, jlong ptrToIDispatch, jint dispid, jobjectArray args)
{
    jobject result(0);
    JNI_EXCEPTION_SAFE_BEGIN
    IDispatch * idisp(reinterpret_cast<IDispatch *>(ptrToIDispatch));
    result = com::call_method(idisp, static_cast<DISPID>(dispid), env, args);
    JNI_EXCEPTION_SAFE_END(env);
    return result;
}

} // extern "C"