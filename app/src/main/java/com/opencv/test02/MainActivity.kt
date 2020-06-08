package com.opencv.test02

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.ImageView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private var image: ImageView? = null
    private var button: Button? = null
    private var bitmap: Bitmap? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initView()
    }

    private fun initView() {
        image = findViewById<ImageView>(R.id.image)
        button = findViewById<Button>(R.id.button)
        bitmap = BitmapFactory.decodeResource(resources, R.drawable.test)
        image?.setImageBitmap(bitmap)
        button?.setOnClickListener(View.OnClickListener {
            doJob(it)
        })
    }

    private fun doJob(view: View) {
        val w = bitmap!!.width
        val h = bitmap!!.height

        val pixels = IntArray(w * h)
        bitmap!!.getPixels(pixels, 0, w, 0, 0, w, h)

        val resultInt: IntArray = OpencvUtil.color2gray(pixels, w, h)

        val resultImg = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888)

        //(@ColorInt int[] pixels, int offset, int stride,int x, int y, int width, int height)

        //(@ColorInt int[] pixels, int offset, int stride,int x, int y, int width, int height)
        resultImg.setPixels(resultInt, 0, w, 0, 0, w, h)
        image!!.setImageBitmap(resultImg)
    }
}
