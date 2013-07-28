//==============================================================================
// file: global_refs.cpp
// auth: Victor Schappert
// date: 20130624
// desc: Global references to Java classes and objects which remain valid
//       between JNI invocations (implementation file).
//==============================================================================

#include "global_refs.h"

#include "jni_util.h"

#include <cassert>

namespace jsdi {

//==============================================================================
//                               [ INTERNALS ]
//==============================================================================

static jobject globalize(JNIEnv * env, jobject object, const char * name)
{
    jobject global = env->NewGlobalRef(object);
    if (! global)
    {
        std::ostringstream() << __FUNCTION__ << "() failed to get a "
                                "global reference to '" << object
                             << "('" << name << "')"
                             << throw_cpp<jni_exception, JNIEnv *>(env);
    }
    return global;
}

static jclass globalize(JNIEnv * env, jclass clazz, const char * name)
{
    return static_cast<jclass>(
        globalize(env, static_cast<jobject>(clazz), name));
}

static jclass get_global_class_ref(JNIEnv * env, const char * class_name)
{   // NOTE: FindClass will force a load, and will return 0 if class not found
    jni_auto_local<jclass> clazz(env, class_name);
    if (!clazz)
    {
        std::ostringstream() << __FUNCTION__ << "() failed to load class name '"
                             << class_name << '\''
                             << throw_cpp<jni_exception, JNIEnv *>(env);
    }
    return globalize(env, clazz, class_name);
}

static jmethodID get_method_id(JNIEnv * env, jclass clazz,
                               const char * method_name, const char * signature)
{
    jmethodID method_id = env->GetMethodID(clazz, method_name, signature);
    if (! method_id)
    {
        std::ostringstream() << __FUNCTION__ << "() failed to get a method ID "
                                " for class " << clazz << ", method name '"
                             << method_name << "', signature=" << signature
                             << throw_cpp<jni_exception, JNIEnv *>(env);
    }
    return method_id;
}

static jfieldID get_static_field_id(JNIEnv * env, jclass clazz,
                                    const char * field_name,
                                    const char * signature)
{
    jfieldID field_id = env->GetStaticFieldID(clazz, field_name, signature);
    if (! field_id)
    {
        std::ostringstream() << __FUNCTION__ << "() failed to get a static "
                                "field ID for class " << clazz << ", field "
                                "name '" << field_name << "', signature="
                             << signature
                             << throw_cpp<jni_exception, JNIEnv *>(env);
    }
    return field_id;
}

static jobject get_static_field_value_object(JNIEnv * env, jclass clazz,
                                             jfieldID field_id,
                                             const char * name)
{
    jni_auto_local<jobject> value(env, clazz, field_id);
    if (! value)
    {
        std::ostringstream() << __FUNCTION__ << "() got null result for class "
                             << clazz << ", field id '" << field_id
                             << throw_cpp<jni_exception, JNIEnv *>(env);
    }
    return globalize(env, value, name);
}

//==============================================================================
//                            struct global_refs
//==============================================================================

global_refs const * global_refs::ptr(0);
global_refs global_refs_;

// NOTE: This function MUST be called once, and MAY ONLY be called once, prior
//       to the use of ANY JSDI functionality by ANY Java thread via JNI. This
//       can be easily managed by ensuring that this function is triggered by
//       the static constructor of a single 'factory' class on the Java side
//       and ensuring that only that factory class is able construct other JSDI
//       types.
void global_refs::init(JNIEnv * env) throw(jni_exception)
{
    assert(! ptr);
    //
    // Load the global references
    //

    global_refs * g = &global_refs_;

    // [BEGIN:GENERATED CODE last updated Fri Jun 28 17:56:42 PDT 2013]
    g->java_lang_Boolean_ = get_global_class_ref(env, "Ljava/lang/Boolean;");
    g->java_lang_Boolean__f_TRUE_ = get_static_field_id(env, g->java_lang_Boolean_, "TRUE", "Ljava/lang/Boolean;");
    g->java_lang_Boolean__f_FALSE_ = get_static_field_id(env, g->java_lang_Boolean_, "FALSE", "Ljava/lang/Boolean;");
    g->java_lang_Integer_ = get_global_class_ref(env, "Ljava/lang/Integer;");
    g->java_lang_Integer__init_ = get_method_id(env, g->java_lang_Integer_, "<init>", "(I)V");
    g->java_lang_Integer__m_intValue_ = get_method_id(env, g->java_lang_Integer_, "intValue", "()I");
    g->java_lang_Enum_ = get_global_class_ref(env, "Ljava/lang/Enum;");
    g->java_lang_Enum__m_ordinal_ = get_method_id(env, g->java_lang_Enum_, "ordinal", "()I");
    g->suneido_language_jsdi_type_BasicType_ = get_global_class_ref(env, "Lsuneido/language/jsdi/type/BasicType;");
    // [END:GENERATED CODE]

    g->TRUE_object_ = get_static_field_value_object(
        env, g->java_lang_Boolean_, g->java_lang_Boolean__f_TRUE_, "TRUE");
    g->FALSE_object_ = get_static_field_value_object(
        env, g->java_lang_Boolean_, g->java_lang_Boolean__f_FALSE_, "FALSE");
    jni_auto_local<jobject> zero(env, env->NewObject(g->java_lang_Integer_, g->java_lang_Integer__init_, 0));
    g->ZERO_object_ = globalize(env, zero, "zero");

    //
    // Make the global references available outside.
    //
    ptr = &global_refs_;
}

} // namespace jsdi
