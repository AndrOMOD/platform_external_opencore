LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
 	src/pvmfdownloadnodereg.cpp


LOCAL_MODULE := libpvdownloadreginterface

LOCAL_CFLAGS := -DPV_CPU_ARCH_VERSION=0  $(PV_CFLAGS)


LOCAL_STATIC_LIBRARIES := 

LOCAL_SHARED_LIBRARIES := 

LOCAL_C_INCLUDES := \
	$(PV_TOP)/modules/linux_download/node_registry/src \
 	$(PV_TOP)/modules/linux_download/node_registry/src \
 	$(PV_INCLUDES)

LOCAL_COPY_HEADERS_TO := $(PV_COPY_HEADERS_TO)

LOCAL_COPY_HEADERS := \
 	

include $(BUILD_STATIC_LIBRARY)
