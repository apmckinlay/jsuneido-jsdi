/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class suneido_language_jsdi_abi_x86_StructureX86 */

#ifndef _Included_suneido_language_jsdi_abi_x86_StructureX86
#define _Included_suneido_language_jsdi_abi_x86_StructureX86
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     suneido_language_jsdi_abi_x86_StructureX86
 * Method:    copyOutDirect
 * Signature: (J[BI)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_abi_x86_StructureX86_copyOutDirect
  (JNIEnv *, jclass, jlong, jbyteArray, jint);

/*
 * Class:     suneido_language_jsdi_abi_x86_StructureX86
 * Method:    copyOutIndirect
 * Signature: (J[BI[I)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_abi_x86_StructureX86_copyOutIndirect
  (JNIEnv *, jclass, jlong, jbyteArray, jint, jintArray);

/*
 * Class:     suneido_language_jsdi_abi_x86_StructureX86
 * Method:    copyOutVariableIndirect
 * Signature: (J[BI[I[Ljava/lang/Object;[I)V
 */
JNIEXPORT void JNICALL Java_suneido_language_jsdi_abi_x86_StructureX86_copyOutVariableIndirect
  (JNIEnv *, jclass, jlong, jbyteArray, jint, jintArray, jobjectArray, jintArray);

#ifdef __cplusplus
}
#endif
#endif
