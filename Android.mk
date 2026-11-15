LOCAL_PATH := $(call my-dir)LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_MODULE := HDReflection

LOCAL_SRC_FILES := \
    main.cpp \
    mod/logger.cpp

LOCAL_CFLAGS += -O2 -DNDEBUG -std=c++17
LOCAL_CPPFLAGS += -Wall -Wextra -Wno-unused-parameter -fvisibility=hidden -fvisibility-inlines-hidden

LOCAL_C_INCLUDES += $(LOCAL_PATH) $(LOCAL_PATH)/plugin-sdk
LOCAL_LDLIBS += -llog
LOCAL_LDFLAGS += -Wl,--exclude-libs,ALL

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .ccLOCAL_MODULE := HDReflection
LOCAL_SRC_FILES := main.cpp
LOCAL_CFLAGS += -O2 -DNDEBUG -std=c++17
LOCAL_CPPFLAGS += -Wall -Wextra -Wno-unused-parameter -fvisibility=hidden -fvisibility-inlines-hidden
LOCAL_C_INCLUDES += $(LOCAL_PATH) $(LOCAL_PATH)/plugin-sdk
LOCAL_LDLIBS += -llog
LOCAL_LDFLAGS += -Wl,--exclude-libs,ALL
include $(BUILD_SHARED_LIBRARY)
