#include "utils.h"

void throwException(JNIEnv *env, char *format, ...) {
    jclass exClass = (*env)->FindClass(env, "java/lang/UnsupportedOperationException");
    if (!exClass) {
        return;
	}
    char dest[256];
    va_list argptr;
    va_start(argptr, format);
    vsnprintf(dest, 256, format, argptr);
    /* promise, the result from vsprintf will never grow over 256 chars */
    va_end(argptr);
    (*env)->ThrowNew(env, exClass, dest);
}
