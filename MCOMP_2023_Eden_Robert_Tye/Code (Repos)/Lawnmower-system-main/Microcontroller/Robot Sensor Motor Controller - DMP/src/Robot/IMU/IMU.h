#ifndef IMU_H
#define IMU_H

#include <Arduino.h>

#include "ICM_20948.h"
// #include "Adafruit_Sensor_Calibration.h"
// #include "Adafruit_AHRS.h"

#include "Robot/Orientation.h"
#include "Robot/RobotConfig.h"

//#define EEPROM_LOAD_CALIBRATION
#define DEBUG_MESSAGES

// namespace ImuConfig
// {
//     extern int32_t FILTER_UPDATE_RATE_HZ;
// }

/// @brief Definitions for IMU related code for setting up and interacting with our robots IMU and access data and information from it. Additionally, it contains the code for obtaining the robot orientation with the AHRS fusion algorithms and the IMU's data.

namespace IMU
{
    // extern Adafruit_Mahony fusionFilter;

    //I2C prep for IMU
    #define WIRE_PORT Wire // desired Wire port.
    // The value of the last bit of the I2C address.
    // On the SparkFun 9DoF IMU breakout the default is 1, and when the ADR jumper is closed the value becomes 0
    #define AD0_VAL 1
    extern ICM_20948_I2C imu;
    
    //private values/functions of the namespace that should not be used unless ABSOLUTELY needed
    // namespace{
        // Adafruit_Sensor_Calibration_EEPROM imuCalibration; // (READ ONLY if needed)
        // float FILTER_UPDATE_RATE_HZ = 100;
        // uint32_t timestamp; // (DO NOT EDIT) used to help get the defined filter's sample rate
        //
        // float gx, gy, gz; // (READ ONLY if needed) deg value versions for the gyro
        //
        // sensors_event_t mag_event, gyro_event, accel_event; // (READ ONLY if needed)
        //
        // (READ ONLY if needed) These could be "Public" if more access to raw data is needed
        // Adafruit_Sensor *accelerometer, *gyroscope, *magnetometer; 
        //
        //(Load Calibration) Reads the Magnetometer Calibration data from the EEPROM of the MCU
        // extern void loadCalibrationEEPROM(); // DO NOT USE outside of lib
        // extern void loadCalibration(const float mag_hardiron[3], const float mag_softiron[9], const float mag_field);
        // extern void setupFusionFilter(float _sampleFrequency=100);  // DO NOT USE outside of lib
    // }

    //raw quaternion data 
    extern icm_20948_DMP_data_t imuDMPData;
    //quaternion data
    extern  Quaternion quat;
    //IMU sensor Data
    extern float accelData[3]; // x, y, z
    extern float gyroData[3]; // x, y, z   
    
    //Robot's orientation values based on the IMU readings
    extern EulerAngles orientationAngles; 
    extern EulerAngles orientationAngles_rad;

    extern void setupIMU(float _sampleFrequency=100, bool load_cal_from_EEPROM=true);
    extern void updateIMU(); // Must be in main loop for IMU to beable to orientate it self
    extern void getOrientationAngles(EulerAngles* _angles); //get the Orientation angles given by the IMU
    extern void getEKFData(Quaternion* _quat, float* ax, float* ay, float* az, float* gx, float* gy, float* gz); //get the IMU data needed for the EKF fusion with the RTK data
    //extern void getImuRawData();
    
    extern void calcEulerOrientationAngles_rad();
    extern void calcEulerAnglesDeg();
}

#endif