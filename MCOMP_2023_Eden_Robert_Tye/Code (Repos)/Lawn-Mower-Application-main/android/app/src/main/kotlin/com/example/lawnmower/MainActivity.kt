package com.example.lawnmower

import android.app.Activity
import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.hardware.camera2.*
import android.os.Build
import android.os.Bundle
import androidx.annotation.NonNull
import androidx.annotation.RequiresApi
import io.flutter.embedding.android.FlutterActivity
import io.flutter.embedding.engine.FlutterEngine
import io.flutter.plugin.common.MethodChannel
import org.json.JSONObject
import java.util.*

private lateinit var sensorManager: SensorManager
private val accelerometerReading = FloatArray(3)
private val magnetometerReading = FloatArray(3)

private val rotationMatrix = FloatArray(9)
private val orientationAngles = FloatArray(3)


class SensorActivity : Activity(), SensorEventListener {


    public override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
    }

    override fun onResume() {
        super.onResume()

        sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)?.also { accelerometer ->
            sensorManager.registerListener(
                this,
                accelerometer,
                SensorManager.SENSOR_DELAY_NORMAL,
                SensorManager.SENSOR_DELAY_UI
            )
        }
        sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD)?.also { magneticField ->
            sensorManager.registerListener(
                this,
                magneticField,
                SensorManager.SENSOR_DELAY_NORMAL,
                SensorManager.SENSOR_DELAY_UI
            )
        }
    }

    override fun onPause() {
        super.onPause()

        // Don't receive any more updates from either sensor.
        sensorManager.unregisterListener(this)
    }

    // Get readings from accelerometer and magnetometer. To simplify calculations,
    // consider storing these readings as unit vectors.
    override fun onSensorChanged(event: SensorEvent) {
        if (event.sensor.type == Sensor.TYPE_ACCELEROMETER) {
            System.arraycopy(event.values, 0, accelerometerReading, 0, accelerometerReading.size)
        } else if (event.sensor.type == Sensor.TYPE_MAGNETIC_FIELD) {
            System.arraycopy(event.values, 0, magnetometerReading, 0, magnetometerReading.size)
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {
        TODO("Not yet implemented")
    }

    // Compute the three orientation angles based on the most recent readings from
    // the device's accelerometer and magnetometer.
    fun updateOrientationAngles() {
        // Update rotation matrix, which is needed to update orientation angles.
        SensorManager.getRotationMatrix(
            rotationMatrix,
            null,
            accelerometerReading,
            magnetometerReading
        )

        SensorManager.getOrientation(rotationMatrix, orientationAngles)
    }
}


class MainActivity: FlutterActivity() {

    @RequiresApi(Build.VERSION_CODES.LOLLIPOP)
    override fun configureFlutterEngine(@NonNull flutterEngine: FlutterEngine) {
        super.configureFlutterEngine(flutterEngine)
        MethodChannel(flutterEngine.dartExecutor.binaryMessenger, "camera_characteristics").setMethodCallHandler {
                call, result ->
            if(call.method == "getCameraCharacteristics") {
                val angles = orientationAngles.joinToString(prefix = "", postfix = "")

                val manager = context.getSystemService(Context.CAMERA_SERVICE) as CameraManager
                val characteristics = ArrayList<String>()

                val cameraCharacteristics = manager.getCameraCharacteristics("0")
                val focalLengths = cameraCharacteristics.get(CameraCharacteristics.LENS_INFO_AVAILABLE_FOCAL_LENGTHS)
                    ?.joinToString(prefix = "", postfix = "")

                val main = JSONObject()
                main.put(
                    "SENSOR_INFO_PHYSICAL_SIZE",
                    cameraCharacteristics.get(CameraCharacteristics.SENSOR_INFO_PHYSICAL_SIZE)
                ).toString()
                main.put(
                    "LENS_INFO_AVAILABLE_FOCAL_LENGTHS", focalLengths.toString()).toString()
                main.put("ORIENTATION", angles).toString()

                characteristics.add(main.toString())
                result.success(characteristics.toString())
            }
            else {
                result.notImplemented()
            }
        }
    }
}