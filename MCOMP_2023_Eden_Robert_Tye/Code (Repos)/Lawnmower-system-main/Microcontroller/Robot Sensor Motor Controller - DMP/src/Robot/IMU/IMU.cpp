#include "IMU.h"

namespace IMU
{
    // Filter declaration and tuning parameters (Kp - proportional gain, Ki - integral gain)
    // Adafruit_Mahony fusionFilter(5, 0);
    ICM_20948_I2C imu;
    //raw quaternion data 
    icm_20948_DMP_data_t imuDMPData;
    //quaternion data
    Quaternion quat;
    //IMU sensor Data
    float accelData[3]; // x, y, z acceleration data in m/s^2
    float gyroData[3]; // x, y, z  gyro angular velocity data in degrees per second

    //Robot's orientation values based on the IMU readings
    EulerAngles orientationAngles; 
    EulerAngles orientationAngles_rad;

    //private values/functions of the namespace
    // namespace{
    //     /// @brief Call function to load the IMU's calibration data from the microcontroller's EEPROM
    //     void loadCalibrationEEPROM(){
    //             if (!imuCalibration.begin()) {
    //                 #ifdef DEBUG_MESSAGES
    //                 Serial.println("Failed to initialize calibration helper");
    //                 #endif
    //                 while (1) delay(10);
    //             }
    //
    //             #ifdef DEBUG_MESSAGES
    //             Serial.print("Has EEPROM: "); Serial.println(imuCalibration.hasEEPROM());
    //             Serial.print("Has FLASH: "); Serial.println(imuCalibration.hasFLASH());
    //             #endif
    //
    //             if (!imuCalibration.loadCalibration()) {
    //                 #ifdef DEBUG_MESSAGES
    //                 Serial.println("**WARNING** No calibration loaded/found");
    //                 #endif
    //                 while (1) delay(10);
    //             }
    //
    //             #ifdef DEBUG_MESSAGES
    //             imuCalibration.printSavedCalibration();
    //
    //             Serial.println("Calibrations found: ");
    //             Serial.print("\tMagnetic Hard Offset: ");
    //             for (int i=0; i<3; i++) {
    //                 Serial.print(imuCalibration.mag_hardiron[i]); 
    //                 if (i != 2) Serial.print(", ");
    //             }
    //             Serial.println();
    //
    //             Serial.print("\tMagnetic Soft Offset: ");
    //             for (int i=0; i<9; i++) {
    //                 Serial.print(imuCalibration.mag_softiron[i]); 
    //                 if (i != 8) Serial.print(", ");
    //             }
    //             Serial.println();
    //
    //             Serial.print("\tMagnetic Field Magnitude: ");
    //             Serial.println(imuCalibration.mag_field);
    //
    //             Serial.print("\tGyro Zero Rate Offset: ");
    //             for (int i=0; i<3; i++) {
    //                 Serial.print(imuCalibration.gyro_zerorate[i]); 
    //                 if (i != 2) Serial.print(", ");
    //             }
    //             Serial.println();
    //
    //             Serial.print("\tAccel Zero G Offset: ");
    //             for (int i=0; i<3; i++) {
    //                 Serial.print(imuCalibration.accel_zerog[i]); 
    //                 if (i != 2) Serial.print(", ");
    //             }
    //             Serial.println();
    //             #endif
    //     }
    //
    //     /// @brief Call function to load the IMU's calibration data in from the passed parameters
    //     /// @param mag_hardiron // Array of 3 floats representing the magnetic calibration values for hard iron materials to reduce the error due to their interference.
    //     /// @param mag_softiron // Array of 9 floats representing the magnetic calibration values for soft iron materials to reduce the error due to their interference.
    //     /// @param mag_field // The measures magnetic field after calibrating the IMU sebnsor
    //     void loadCalibration(const float mag_hardiron[3], const float mag_softiron[9], const float mag_field){
    //         if (!imuCalibration.begin()) {
    //             #ifdef DEBUG_MESSAGES
    //             Serial.println("Failed to initialize calibration helper");
    //             #endif
    //             while (1) delay(10);
    //         }
    //
    //         imuCalibration.mag_hardiron[0] = mag_hardiron[0];
    //         imuCalibration.mag_hardiron[1] = mag_hardiron[1];
    //         imuCalibration.mag_hardiron[2] = mag_hardiron[2];
    //
    //         imuCalibration.mag_field = mag_field;
    //
    //         imuCalibration.mag_softiron[0] = mag_softiron[0];
    //         imuCalibration.mag_softiron[1] = mag_softiron[1];
    //         imuCalibration.mag_softiron[2] = mag_softiron[2];
    //         imuCalibration.mag_softiron[3] = mag_softiron[3];
    //         imuCalibration.mag_softiron[4] = mag_softiron[4];
    //         imuCalibration.mag_softiron[5] = mag_softiron[5];
    //         imuCalibration.mag_softiron[6] = mag_softiron[6];
    //         imuCalibration.mag_softiron[7] = mag_softiron[7];
    //         imuCalibration.mag_softiron[8] = mag_softiron[8];
    //
    //         #ifdef DEBUG_MESSAGES
    //         imuCalibration.printSavedCalibration();
    //
    //         Serial.println("Calibrations found: ");
    //         Serial.print("\tMagnetic Hard Offset: ");
    //         for (int i=0; i<3; i++) {
    //             Serial.print(imuCalibration.mag_hardiron[i]); 
    //             if (i != 2) Serial.print(", ");
    //         }
    //         Serial.println();
    //
    //         Serial.print("\tMagnetic Soft Offset: ");
    //         for (int i=0; i<9; i++) {
    //             Serial.print(imuCalibration.mag_softiron[i]); 
    //             if (i != 8) Serial.print(", ");
    //         }
    //         Serial.println();
    //
    //         Serial.print("\tMagnetic Field Magnitude: ");
    //         Serial.println(imuCalibration.mag_field);
    //
    //         Serial.print("\tGyro Zero Rate Offset: ");
    //         for (int i=0; i<3; i++) {
    //             Serial.print(imuCalibration.gyro_zerorate[i]); 
    //             if (i != 2) Serial.print(", ");
    //         }
    //         Serial.println();
    //
    //         Serial.print("\tAccel Zero G Offset: ");
    //         for (int i=0; i<3; i++) {
    //             Serial.print(imuCalibration.accel_zerog[i]); 
    //             if (i != 2) Serial.print(", ");
    //         }
    //         Serial.println();
    //         #endif
    //     }
    //
    //     /// @brief Fuction to call for setting up the IMU's Fusion algorithm ready for so that we can calculate the robot's orientation
    //     /// @param _sampleFrequency set the sample frequency of the fusion algorithm filter can update
    //     void setupFusionFilter(float _sampleFrequency){
    //         FILTER_UPDATE_RATE_HZ = _sampleFrequency;
    //         fusionFilter.begin(FILTER_UPDATE_RATE_HZ); // start the fusion filter at the requested frequency
    //         timestamp = millis();
    //     }
    // }

    void setupIMU(float _sampleFrequency, bool load_cal_from_EEPROM)
    {
    #ifdef DEBUG_MESSAGES
        imu.enableDebugging();
        Serial.println("Connecting to IMU...");
    #endif
    //initialise the IMU
    WIRE_PORT.begin();
    WIRE_PORT.setClock(400000);
    do{
        // With DMP is enabled, .begin performs a minimal startup so need to configure the sample mode etc... manually
        imu.begin(WIRE_PORT, AD0_VAL); 
        delay(500);
    } while(imu.status != ICM_20948_Stat_Ok);
    
    #ifdef DEBUG_MESSAGES
        Serial.println("IMU Connected.");
    #endif

    // Do a SW reset to make sure the device starts in a known state
    imu.swReset();
    if (imu.status != ICM_20948_Stat_Ok)
    {
        #ifdef DEBUG_MESSAGES
        Serial.print(F("Software Reset returned: "));
        Serial.println(imu.statusString());
        #endif
    }
    delay(250);
    // wake the sensor up
    imu.sleep(false);
    imu.lowPower(false);

    //start up the Magnetometer
    imu.startupMagnetometer();
    if (imu.status != ICM_20948_Stat_Ok)
    {
        #ifdef DEBUG_MESSAGES
        Serial.print(F("startupMagnetometer returned: "));
        Serial.println(imu.statusString());
        #endif
    }

    //configure the sample mode, etc...

    bool success = true; // Use success to show if the DMP configuration was successful
    // Initialize the DMP. initializeDMP is a weak function. You can overwrite it if you want to e.g. to change the sample rate
    success &= (imu.initializeDMP() == ICM_20948_Stat_Ok);

    // DMP sensor options are defined in ICM_20948_DMP.h
    //    INV_ICM20948_SENSOR_ACCELEROMETER               (16-bit accel)
    //    INV_ICM20948_SENSOR_GYROSCOPE                   (16-bit gyro + 32-bit calibrated gyro)
    //    INV_ICM20948_SENSOR_RAW_ACCELEROMETER           (16-bit accel)
    //    INV_ICM20948_SENSOR_RAW_GYROSCOPE               (16-bit gyro + 32-bit calibrated gyro)
    //    INV_ICM20948_SENSOR_MAGNETIC_FIELD_UNCALIBRATED (16-bit compass)
    //    INV_ICM20948_SENSOR_GYROSCOPE_UNCALIBRATED      (16-bit gyro)
    //    INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR        (32-bit 6-axis quaternion)
    //    INV_ICM20948_SENSOR_ROTATION_VECTOR             (32-bit 9-axis quaternion + heading accuracy)
    //    INV_ICM20948_SENSOR_GEOMAGNETIC_ROTATION_VECTOR (32-bit Geomag RV + heading accuracy)
    //    INV_ICM20948_SENSOR_GEOMAGNETIC_FIELD           (32-bit calibrated compass)
    //    INV_ICM20948_SENSOR_LINEAR_ACCELERATION         (16-bit accel + 32-bit 6-axis quaternion)
    //    INV_ICM20948_SENSOR_ORIENTATION                 (32-bit 9-axis quaternion + heading accuracy)

    // Enable the DMP orientation sensor
    success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_ORIENTATION) == ICM_20948_Stat_Ok);
    
    // Enable any additional sensors / features
    success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_RAW_GYROSCOPE) == ICM_20948_Stat_Ok);
    success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_RAW_ACCELEROMETER) == ICM_20948_Stat_Ok);
    //success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_MAGNETIC_FIELD_UNCALIBRATED) == ICM_20948_Stat_Ok);

    // Configuring DMP to output data at multiple ODRs:
    // DMP is capable of outputting multiple sensor data at different rates to FIFO.
    // Setting value can be calculated as follows:
    // Value = (DMP running rate / ODR ) - 1
    // E.g. For a 5Hz ODR rate when DMP is running at 55Hz, value = (55/5) - 1 = 10.
    success &= (imu.setDMPODRrate(DMP_ODR_Reg_Quat9, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    success &= (imu.setDMPODRrate(DMP_ODR_Reg_Accel, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    success &= (imu.setDMPODRrate(DMP_ODR_Reg_Gyro, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    success &= (imu.setDMPODRrate(DMP_ODR_Reg_Gyro_Calibr, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    // success &= (imu.setDMPODRrate(DMP_ODR_Reg_Cpass, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    // success &= (imu.setDMPODRrate(DMP_ODR_Reg_Cpass_Calibr, 0) == ICM_20948_Stat_Ok); // Set to the maximum
    
    // Enable the FIFO
    success &= (imu.enableFIFO() == ICM_20948_Stat_Ok);
    // Enable the DMP
    success &= (imu.enableDMP() == ICM_20948_Stat_Ok);
    // Reset DMP
    success &= (imu.resetDMP() == ICM_20948_Stat_Ok);
    // Reset FIFO
    success &= (imu.resetFIFO() == ICM_20948_Stat_Ok);
    //Enable the Digital Low-pass filter on the Accelerometer and Gyroscope
    imu.enableDLPF(ICM_20948_Internal_Acc | ICM_20948_Internal_Gyr, true);
    // Check success
    if (success)
    {
        #ifdef DEBUG_MESSAGES
            Serial.println(F("DMP enabled!"));
        #endif
    }
    else
    {
        Serial.println(F("Enable DMP failed!"));
        Serial.println(F("Please check that you have uncommented line 29 (#define ICM_20948_USE_DMP) in ICM_20948_C.h..."));
        while (1)
        ; // Do nothing more
    }
    #ifdef DEBUG_MESSAGES 
        Serial.println();
        Serial.println(F("Configuration complete!"));
    #endif
    }

    void updateIMU()
    {
        imu.readDMPdataFromFIFO(&imuDMPData);

        if ((imu.status == ICM_20948_Stat_Ok) || (imu.status == ICM_20948_Stat_FIFOMoreDataAvail)) // Was valid data available?
        {
            if ((imuDMPData.header & DMP_header_bitmap_Quat9) > 0) // We have asked for orientation data so we should receive Quat9
            {
            // Q0 value is computed from this equation: Q0^2 + Q1^2 + Q2^2 + Q3^2 = 1.
            // In case of drift, the sum will not add to 1, therefore, quaternion data need to be corrected with right bias values.
            // The quaternion data is scaled by 2^30.
            quat.x = ((double)imuDMPData.Quat9.Data.Q1) / 1073741824.0; // Convert to double. Divide by 2^30
            quat.y = ((double)imuDMPData.Quat9.Data.Q2) / 1073741824.0;
            quat.z = ((double)imuDMPData.Quat9.Data.Q3) / 1073741824.0; 

            quat.w = sqrt(1.0 - ((quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z)));
            }

            // get acceleration and gyro values from the imu data
            if ((imuDMPData.header & DMP_header_bitmap_Accel) > 0){ // Check for Accel
                // DMP's default Full Scale (accel) setting: gpm4, meaning we divide the raw values by 8192 to get the acceleration in 'g'
                // To get m/s^2 we have to multiply the acceleration in 'g' by the earths (average) gravity (9.81 m/s^2) 
                accelData[0] = (float)(imuDMPData.Raw_Accel.Data.X * 9.81) / 8192;  
                accelData[1] = (float)(imuDMPData.Raw_Accel.Data.Y * 9.81) / 8192;
                accelData[2] = (float)(imuDMPData.Raw_Accel.Data.Z * 9.81) / 8192;
            }
            
            if ((imuDMPData.header & DMP_header_bitmap_Gyro) > 0){ // Check for Gyro
                // DMP's default Full Scale (gryo) setting: dps2000, meaning we divide the raw values by 16.4
                gyroData[0] = (float)imuDMPData.Raw_Gyro.Data.X / 16.4;
                gyroData[1] = (float)imuDMPData.Raw_Gyro.Data.Y / 16.4;
                gyroData[2] = (float)imuDMPData.Raw_Gyro.Data.Z / 16.4;
            }

            // Get the heading, pitch and roll
            calcEulerAnglesDeg();
        }
    }

    void getOrientationAngles(EulerAngles* _angles)
    {
        _angles->heading = orientationAngles.heading;
        _angles->pitch = orientationAngles.pitch;
        _angles->roll = orientationAngles.roll;
    }

    void getEKFData(Quaternion* _quat, float* ax, float* ay, float* az, float* gx, float* gy, float* gz){
        
        // get the sensor data
        *ax = accelData[0];
        *ay = accelData[1];
        *az = accelData[2];
        *gx = gyroData[0];
        *gy = gyroData[1];
        *gz = gyroData[2];

        //get the orientation quaternion
        _quat->w = quat.w;
        _quat->x = quat.x;
        _quat->y = quat.y;
        _quat->z = quat.z;
    }

    void calcEulerOrientationAngles_rad(){
        //calc the roll (x-axis rotation)
        double sinr_cosp = 2 * (quat.w * quat.x + quat.y * quat.z);
        //double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
        double cosr_cosp = 1 - 2 * (quat.x * quat.x + quat.y * quat.y);
        //double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
        orientationAngles_rad.roll = atan2(sinr_cosp, cosr_cosp);
        //angles.roll = std::atan2(sinr_cosp, cosr_cosp);

        //calc the pitch (y-axis rotation)
        double sinp = sqrt(1 + 2 * (quat.w * quat.y - quat.x * quat.z));
        // double sinp = std::sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
        double cosp = sqrt(1 - 2 * (quat.w * quat.y - quat.x * quat.z));
        // double cosp = std::sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
        orientationAngles_rad.pitch = 2 * atan2(sinp, cosp) - PI/2;
        // angles.pitch = 2 * std::atan2(sinp, cosp) - M_PI / 2;

        //calc the yaw (z-axis rotation)
        double siny_cosp = 2 * (quat.w * quat.z + quat.x * quat.y);
        // double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
        double cosy_cosp = 1 - 2 * (quat.y * quat.y + quat.z * quat.z);
        // double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
        orientationAngles_rad.heading = atan2(siny_cosp, cosy_cosp);
        // angles.yaw = std::atan2(siny_cosp, cosy_cosp);
    }
    
    void calcEulerAnglesDeg(){
        calcEulerOrientationAngles_rad();
        //orientationAngles.pitch = (double)map(orientationAngles_rad.pitch, -PI, PI, 0, 360);
        orientationAngles.pitch = orientationAngles_rad.pitch * (180/PI);
        //orientationAngles.roll = (double)map(orientationAngles_rad.roll, -PI, PI, -180, 360);
        orientationAngles.roll = orientationAngles_rad.roll * (180/PI);
        //orientationAngles.yaw = (double)map(orientationAngles_rad.yaw, -PI, PI, 0, 360);
        orientationAngles.heading = 360 - (180 + orientationAngles_rad.heading * (180/PI));
    }
}