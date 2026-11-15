LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := HDReflection

LOCAL_SRC_FILES := \
    main.cpp \
    mod/logger.cpp

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_CFLAGS += -O2 -DNDEBUG
LOCAL_CPPFLAGS += -std=c++17 -Wall -Wextra -Wno-unused-parameter

LOCAL_C_INCLUDES += $(LOCAL_PATH) $(LOCAL_PATH)/plugin-sdk

LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
