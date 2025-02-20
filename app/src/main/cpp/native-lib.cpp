#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "NDKExample"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

extern "C" JNIEXPORT jdouble JNICALL
Java_com_example_ndkpr_MainActivity_calculateAverage(JNIEnv *env, jobject, jintArray numbers) {
    // 배열을 가져오기
    jsize length = env->GetArrayLength(numbers);
    jint *arr = env->GetIntArrayElements(numbers, nullptr);

    // 평균 계산
    jint sum = 0;
    for (jsize i = 0; i < length; i++) {
        sum += arr[i];
    }

    // 평균 계산
    jdouble average = static_cast<jdouble>(sum) / length;

    // 메모리 해제
    env->ReleaseIntArrayElements(numbers, arr, JNI_ABORT);

    return average;
}