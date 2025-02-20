package com.example.ndkpr

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.ndkpr.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val numbers = intArrayOf(10, 20, 30, 40, 50)
        val avg = calculateAverage(numbers)
        println("평균: $avg")  // 예상 출력: 30.0
    }

    /**
     * A native method that is implemented by the 'ndkpr' native library,
     * which is packaged with this application.
     */
    external fun calculateAverage(numers: IntArray): Double

    companion object {
        // Used to load the 'ndkpr' library on application startup.
        init {
            System.loadLibrary("ndkpr")
        }
    }
}