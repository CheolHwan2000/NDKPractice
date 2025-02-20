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

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_ndkpr_MainActivity_toUpperCase(JNIEnv *env, jobject, jstring input) {
    // 1. jstring을 C 문자열(const char*)로 변환
    const char *cStr = env->GetStringUTFChars(input, nullptr);
    if (cStr == nullptr) {
        return nullptr; // 메모리 할당 실패 시 예외 처리
    }

    // 2. C++ std::string으로 변환
    std::string str(cStr);

    // 3. std::toupper()를 사용하여 문자열을 대문자로 변환
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    // 4. 변환된 문자열을 jstring으로 변환
    jstring result = env->NewStringUTF(str.c_str());

    // 5. 메모리 해제
    env->ReleaseStringUTFChars(input, cStr);

    return result;
}