#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/vfs.h>
#include <android/log.h>
#include <jni.h>
enum daLogType {
    daDEBUG = 3,
    daERROR = 6,
    daINFO = 4,
    daWARN = 5
};
#define  TAG    "NDK_TEST"
#define LOGD(...) ((void)__android_log_print(daDEBUG, TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(daERROR, TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(daINFO,  TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(daWARN,  TAG, __VA_ARGS__))

extern "C" {
    JNIEXPORT jstring JNICALL Java_com_example_statfstest_MainActivity_tester(JNIEnv *env, jobject clazz) {
        struct statfs lstatfs;
        const char* path = "/data/downloads/com.bluestacks.launcher/oat/x86_64/com.bluestacks.launcher.odex";
        LOGI("[+] Start statfs Test");
        int result = statfs(path, &lstatfs);
        if(result == 0){
            LOGI("[+] statfs success for \"%s\"", path);
        }
        else {
            LOGE("[-] statfs failed for \"%s\"", path);
        }
        return env->NewStringUTF("statfs test");
    }
}
