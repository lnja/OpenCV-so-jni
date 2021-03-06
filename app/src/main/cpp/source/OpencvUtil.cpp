#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/types_c.h"
#include <jni.h>

#ifndef _Included_com_opencv_test02_OpencvUtil
#define _Included_com_opencv_test02_OpencvUtil
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_opencv_test02_OpencvUtil
 * Method:    color2gray
 * Signature: ([III)[I
 */
JNIEXPORT jintArray JNICALL
Java_com_opencv_test02_OpencvUtil_color2gray(JNIEnv *, jclass clazz, jintArray, jint, jint);
#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jintArray JNICALL Java_com_opencv_test02_OpencvUtil_color2gray
        (JNIEnv *env, jclass clazz, jintArray pixels_, jint w, jint h) {
    jint *pixels = env->GetIntArrayElements(pixels_, NULL);
    if (pixels == NULL) {
        return 0;
    }

    //图片一进来时是ARGB  通过mat转换BGRA
    cv::Mat img(h, w, CV_8UC4, (uchar *) pixels);  //pixels 操作的是同一份数据

    cv::Mat temp;
    //转化为单通道灰度图，并打印信息
    cv::cvtColor(img, temp, CV_BGR2GRAY);

    //转化为四通道。特别注意：在调用ov图像处理函数时，一定要好好考虑一下图片的位数和通道.否则可能出现各种问题.
    cvtColor(temp, temp, CV_GRAY2BGRA);

    uchar *tempData = temp.data;

    //对应数据指针
    int size = w * h;
    jintArray result = env->NewIntArray(size);
    //env->SetIntArrayRegion(result,0,size,pixels);
    env->SetIntArrayRegion(result, 0, size, (const jint *) tempData);

    env->ReleaseIntArrayElements(pixels_, pixels, 0);

    return result;
}

#ifdef __cplusplus
}
#endif


