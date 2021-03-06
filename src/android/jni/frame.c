#include <jni.h>
#include "error.h"
#include "../../../include/librealsense2/rs.h"
#include "../usb_host/android_debug.h"

JNIEXPORT void JNICALL
Java_com_intel_realsense_librealsense_Frame_nAddRef(JNIEnv *env, jclass type, jlong handle) {
    rs2_error *e = NULL;
    rs2_frame_add_ref((rs2_frame *) handle, &e);
    handle_error(env, e);
}

JNIEXPORT void JNICALL
Java_com_intel_realsense_librealsense_Frame_nRelease(JNIEnv *env, jclass type, jlong handle) {
    rs2_release_frame((rs2_frame *) handle);
}

JNIEXPORT void JNICALL
Java_com_intel_realsense_librealsense_Frame_nKeep(JNIEnv *env, jclass type, jlong handle) {
rs2_keep_frame((rs2_frame *) handle);
}

JNIEXPORT jlong JNICALL
Java_com_intel_realsense_librealsense_Frame_nGetStreamProfile(JNIEnv *env, jclass type, jlong handle) {
    rs2_error *e = NULL;
    const rs2_stream_profile *rv = rs2_get_frame_stream_profile((const rs2_frame *) handle, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT void JNICALL
Java_com_intel_realsense_librealsense_Frame_nGetData(JNIEnv *env, jclass type, jlong handle,
                                                     jbyteArray data_) {
    jsize length = (*env)->GetArrayLength(env, data_);
    rs2_error *e = NULL;
    (*env)->SetByteArrayRegion(env, data_, 0, length, rs2_get_frame_data((const rs2_frame *) handle, &e));
    handle_error(env, e);
}

JNIEXPORT void JNICALL
Java_com_intel_realsense_librealsense_Frame_nGetDataInt(JNIEnv *env, jclass type, jlong handle,
                                                                                jintArray data_) {
    jsize length = (*env)->GetArrayLength(env, data_);
    rs2_error *e = NULL;
    (*env)->SetIntArrayRegion(env, data_, 0, length, rs2_get_frame_data((const rs2_frame *) handle, &e));
    handle_error(env, e);
}

JNIEXPORT jboolean JNICALL
Java_com_intel_realsense_librealsense_Frame_nIsFrameExtendableTo(JNIEnv *env, jclass type,
                                                                 jlong handle, jint extension) {
    rs2_error *e = NULL;
    int rv = rs2_is_frame_extendable_to(handle, extension, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT jint JNICALL
Java_com_intel_realsense_librealsense_VideoFrame_nGetWidth(JNIEnv *env, jclass type, jlong handle) {
    rs2_error *e = NULL;
    int rv = rs2_get_frame_width(handle, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT jint JNICALL
Java_com_intel_realsense_librealsense_VideoFrame_nGetHeight(JNIEnv *env, jclass type, jlong handle) {
    rs2_error *e = NULL;
    int rv = rs2_get_frame_height(handle, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT jint JNICALL
Java_com_intel_realsense_librealsense_VideoFrame_nGetStride(JNIEnv *env, jclass type,
                                                            jlong handle) {
    rs2_error *e = NULL;
    int rv = rs2_get_frame_stride_in_bytes((const rs2_frame *) handle, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT jint JNICALL
Java_com_intel_realsense_librealsense_VideoFrame_nGetBitsPerPixel(JNIEnv *env, jclass type,
                                                                  jlong handle) {
    rs2_error *e = NULL;
    int rv = rs2_get_frame_bits_per_pixel((const rs2_frame *) handle, &e);
    handle_error(env, e);
    return rv;
}

JNIEXPORT jint JNICALL
Java_com_intel_realsense_librealsense_Frame_nGetNumber(JNIEnv *env, jclass type, jlong handle) {
    rs2_error *e = NULL;
    unsigned long long rv = rs2_get_frame_number((const rs2_frame *) handle, &e);
    handle_error(env, e);
    return rv;
}
