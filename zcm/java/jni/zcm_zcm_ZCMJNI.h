/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class zcm_zcm_ZCMJNI */

#ifndef _Included_zcm_zcm_ZCMJNI
#define _Included_zcm_zcm_ZCMJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     zcm_zcm_ZCMJNI
 * Method:    initializeNative
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_zcm_zcm_ZCMJNI_initializeNative
  (JNIEnv *, jobject, jstring);

/*
 * Class:     zcm_zcm_ZCMJNI
 * Method:    publish
 * Signature: (Ljava/lang/String;[BII)I
 */
JNIEXPORT jint JNICALL Java_zcm_zcm_ZCMJNI_publish
  (JNIEnv *, jobject, jstring, jbyteArray, jint, jint);

/*
 * Class:     zcm_zcm_ZCMJNI
 * Method:    subscribe
 * Signature: (Ljava/lang/String;Lzcm/zcm/ZCM;)I
 */
JNIEXPORT jint JNICALL Java_zcm_zcm_ZCMJNI_subscribe
  (JNIEnv *, jobject, jstring, jobject);

#ifdef __cplusplus
}
#endif
#endif
