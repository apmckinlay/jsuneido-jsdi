/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class suneido_jsdi_DllFactory */

#ifndef _Included_suneido_jsdi_DllFactory
#define _Included_suneido_jsdi_DllFactory
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     suneido_jsdi_DllFactory
 * Method:    loadLibrary
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_suneido_jsdi_DllFactory_loadLibrary
  (JNIEnv *, jclass, jstring);

/*
 * Class:     suneido_jsdi_DllFactory
 * Method:    freeLibrary
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_suneido_jsdi_DllFactory_freeLibrary
  (JNIEnv *, jclass, jlong);

/*
 * Class:     suneido_jsdi_DllFactory
 * Method:    getProcAddress
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_suneido_jsdi_DllFactory_getProcAddress
  (JNIEnv *, jclass, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
