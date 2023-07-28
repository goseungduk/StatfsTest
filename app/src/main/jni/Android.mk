LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

LOCAL_MODULE    := tester
LOCAL_SRC_FILES := tester.cpp

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)