package com.opencv.test02;

public class OpencvUtil {
    static {
        System.loadLibrary("opencvutil");
    }

    public static native int[] color2gray(int[] pixels, int w, int h);
}
