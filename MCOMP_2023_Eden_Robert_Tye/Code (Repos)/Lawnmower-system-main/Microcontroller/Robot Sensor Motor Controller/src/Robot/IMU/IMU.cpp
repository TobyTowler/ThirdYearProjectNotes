#include "IMU.h"

namespace IMU
{
    // Filter declaration and tuning parameters (Kp - proportional gain, Ki - integral gain)
    Adafruit_Mahony fusionFilter(5, 0);
    Adafruit_ICM20948 imu;

    //private values/functions of the namespace
    namespace{
        /// @brief Call function to load the IMU's calibration data from the microcontroller's EEPROM
        void loadCalibrationEEPROM(){
                if (!imuCalibration.begin()) {
                    #ifdef DEBUG_MESSAGES
                    Serial.println("Failed to initialize calibration helper");
                    #endif
                    while (1) delay(10);
                }

                #ifdef DEBUG_MESSAGES
                Serial.print("Has EEPROM: "); Serial.println(imuCalibration.hasEEPROM());
                Serial.print("Has FLASH: "); Serial.println(imuCalibration.hasFLASH());
                #endif

                if (!imuCalibration.loadCalibration()) {
                    #ifdef DEBUG_MESSAGES
                    Serial.println("**WARNING** No calibration loaded/found");
                    #endif
                    while (1) delay(10);
                }

                #ifdef DEBUG_MESSAGES
                imuCalibration.printSavedCalibration();

                Serial.println("Calibrations found: ");
                Serial.print("\tMagnetic Hard Offset: ");
                for (int i=0; i<3; i++) {
                    Serial.print(imuCalibration.mag_hardiron[i]); 
                    if (i != 2) Serial.print(", ");
                }
                Serial.println();
                
                Serial.print("\tMagnetic Soft Offset: ");
                for (int i=0; i<9; i++) {
                    Serial.print(imuCalibration.mag_softiron[i]); 
                    if (i != 8) Serial.print(", ");
                }
                Serial.println();

                Serial.print("\tMagnetic Field Magnitude: ");
                Serial.println(imuCalibration.mag_field);

                Serial.print("\tGyro Zero Rate Offset: ");
                for (int i=0; i<3; i++) {
                    Serial.print(imuCalibration.gyro_zerorate[i]); 
                    if (i != 2) Serial.print(", ");
                }
                Serial.println();

                Serial.print("\tAccel Zero G Offset: ");
                for (int i=0; i<3; i++) {
                    Serial.print(imuCalibration.accel_zerog[i]); 
                    if (i != 2) Serial.print(", ");
                }
                Serial.println();
                #endif
        }

        /// @brief Call function to load the IMU's calibration data in from the passed parameters
        /// @param mag_hardiron // Array of 3 floats representing the magnetic calibration values for hard iron materials to reduce the error due to their interference.
        /// @param mag_softiron // Array of 9 floats representing the magnetic calibration values for soft iron materials to reduce the error due to their interference.
        /// @param mag_field // The measures magnetic field after calibrating the IMU sebnsor
        void loadCalibration(const float mag_hardiron[3], const float mag_softiron[9], const float mag_field){
            if (!imuCalibration.begin()) {
                #ifdef DEBUG_MESSAGES
                Serial.println("Failed to initialize calibration helper");
                #endif
                while (1) delay(10);
            }
            
            imuCalibration.mag_hardiron[0] = mag_hardiron[0];
            imuCalibration.mag_hardiron[1] = mag_hardiron[1];
            imuCalibration.mag_hardiron[2] = mag_hardiron[2];

            imuCalibration.mag_field = mag_field;

            imuCalibration.mag_softiron[0] = mag_softiron[0];
            imuCalibration.mag_softiron[1] = mag_softiron[1];
            imuCalibration.mag_softiron[2] = mag_softiron[2];
            imuCalibration.mag_softiron[3] = mag_softiron[3];
            imuCalibration.mag_softiron[4] = mag_softiron[4];
            imuCalibration.mag_softiron[5] = mag_softiron[5];
            imuCalibration.mag_softiron[6] = mag_softiron[6];
            imuCalibration.mag_softiron[7] = mag_softiron[7];
            imuCalibration.mag_softiron[8] = mag_softiron[8];

            #ifdef DEBUG_MESSAGES
            imuCalibration.printSavedCalibration();

            Serial.println("Calibrations found: ");
            Serial.print("\tMagnetic Hard Offset: ");
            for (int i=0; i<3; i++) {
                Serial.print(imuCalibration.mag_hardiron[i]); 
                if (i != 2) Serial.print(", ");
            }
            Serial.println();
            
            Serial.print("\tMagnetic Soft Offset: ");
            for (int i=0; i<9; i++) {
                Serial.print(imuCalibration.mag_softiron[i]); 
                if (i != 8) Serial.print(", ");
            }
            Serial.println();

            Serial.print("\tMagnetic Field Magnitude: ");
            Serial.println(imuCalibration.mag_field);

            Serial.print("\tGyro Zero Rate Offset: ");
            for (int i=0; i<3; i++) {
                Serial.print(imuCalibration.gyro_zerorate[i]); 
                if (i != 2) Serial.print(", ");
            }
            Serial.println();

            Serial.print("\tAccel Zero G Offset: ");
            for (int i=0; i<3; i++) {
                Serial.print(imuCalibration.accel_zerog[i]); 
                if (i != 2) Serial.print(", ");
            }
            Serial.println();
            #endif
        }

        /// @brief Fuction to call for setting up the IMU's Fusion algorithm ready for so that we can calculate the robot's orientation
        /// @param _sampleFrequency set the sample frequency of the fusion algorithm filter can update
        void setupFusionFilter(float _sampleFrequency){
            FILTER_UPDATE_RATE_HZ = _sampleFrequency;
            fusionFilter.begin(FILTER_UPDATE_RATE_HZ); // start the fusion filter at the requested frequency
            timestamp = millis();
        }
    }

    void setupIMU(float _sampleFrequency, bool load_cal_from_EEPROM)
    {
        if (!imu.begin_I2C()) {
            #ifdef DEBUG_MESSAGES
            Serial.println("Failed to find ICM20948 chip");
            #endif
            while (1) {
            delay(10);
            }
        }

        //configure the IMU sensors here:
        imu.setAccelRange(ICM20948_ACCEL_RANGE_4_G);
        imu.setGyroRange(ICM20948_GYRO_RANGE_500_DPS);
        imu.setMagDataRate(AK09916_MAG_DATARATE_100_HZ);
        
        #ifdef DEBUG_MESSAGES
        Serial.println("ICM20948 Found!");
        Serial.print("Accelerometer range set to: ");
        switch (imu.getAccelRange()) {
        case ICM20948_ACCEL_RANGE_2_G:
            Serial.println("+-2G");
            break;
        case ICM20948_ACCEL_RANGE_4_G:
            Serial.println("+-4G");
            break;
        case ICM20948_ACCEL_RANGE_8_G:
            Serial.println("+-8G");
            break;
        case ICM20948_ACCEL_RANGE_16_G:
            Serial.println("+-16G");
            break;
        }
        Serial.println("OK");

        Serial.print("Gyro range set to: ");
        switch (imu.getGyroRange()) {
        case ICM20948_GYRO_RANGE_250_DPS:
            Serial.println("250 degrees/s");
            break;
        case ICM20948_GYRO_RANGE_500_DPS:
            Serial.println("500 degrees/s");
            break;
        case ICM20948_GYRO_RANGE_1000_DPS:
            Serial.println("1000 degrees/s");
            break;
        case ICM20948_GYRO_RANGE_2000_DPS:
            Serial.println("2000 degrees/s");
            break;
        }

        //  imu.setAccelRateDivisor(4095);
        uint16_t accel_divisor = imu.getAccelRateDivisor();
        float accel_rate = 1125 / (1.0 + accel_divisor);

        Serial.print("Accelerometer data rate divisor set to: ");
        Serial.println(accel_divisor);
        Serial.print("Accelerometer data rate (Hz) is approximately: ");
        Serial.println(accel_rate);

        //  imu.setGyroRateDivisor(255);
        uint8_t gyro_divisor = imu.getGyroRateDivisor();
        float gyro_rate = 1100 / (1.0 + gyro_divisor);

        Serial.print("Gyro data rate divisor set to: ");
        Serial.println(gyro_divisor);
        Serial.print("Gyro data rate (Hz) is approximately: ");
        Serial.println(gyro_rate);

        Serial.print("Magnetometer data rate set to: ");
        switch (imu.getMagDataRate()) {
        case AK09916_MAG_DATARATE_SHUTDOWN:
            Serial.println("Shutdown");
            break;
        case AK09916_MAG_DATARATE_SINGLE:
            Serial.println("Single/One shot");
            break;
        case AK09916_MAG_DATARATE_10_HZ:
            Serial.println("10 Hz");
            break;
        case AK09916_MAG_DATARATE_20_HZ:
            Serial.println("20 Hz");
            break;
        case AK09916_MAG_DATARATE_50_HZ:
            Serial.println("50 Hz");
            break;
        case AK09916_MAG_DATARATE_100_HZ:
            Serial.println("100 Hz");
            break;
        }
        Serial.println();
        #endif

        accelerometer = imu.getAccelerometerSensor();
        gyroscope = imu.getGyroSensor();
        magnetometer = imu.getMagnetometerSensor();

        Wire.setClock(400000); // 400KHz
        
        //read the EEPROM for calibration data#
        if (load_cal_from_EEPROM){
            loadCalibrationEEPROM();
        }else{
            loadCalibration(IMU_CAL_MAG_HARD_IRON, IMU_CAL_MAG_SOFT_IRON, IMU_CAL_MAG_FIELD);
        }

        //setup the Fusion Filter
        setupFusionFilter(_sampleFrequency);
    }

    void updateIMU()
    {
        // see if we are ready to update
        if ((millis() - timestamp) < (1000 / FILTER_UPDATE_RATE_HZ)) {
            return; // not ready, exit
        }

        // we are ready to update
        timestamp = millis();

        //read the motion data
        accelerometer->getEvent(&accel_event);
        gyroscope->getEvent(&gyro_event);
        magnetometer->getEvent(&mag_event);

        // calibrate the events
        imuCalibration.calibrate(mag_event);
        imuCalibration.calibrate(accel_event);
        imuCalibration.calibrate(gyro_event);

        //convert the gyro reading from rads to degs
        gx = gyro_event.gyro.x * SENSORS_RADS_TO_DPS;
        gy = gyro_event.gyro.y * SENSORS_RADS_TO_DPS;
        gz = gyro_event.gyro.z * SENSORS_RADS_TO_DPS;

        //update the filter
        fusionFilter.update(
            gy, gx, gz, 
            accel_event.acceleration.y, accel_event.acceleration.x, accel_event.acceleration.z, 
            -mag_event.magnetic.y, mag_event.magnetic.x, -mag_event.magnetic.z);
        
        // Get the heading, pitch and roll
        orientationAngles.heading = fusionFilter.getYaw();
        orientationAngles.roll = fusionFilter.getRoll();
        orientationAngles.pitch = fusionFilter.getPitch();
    }

    void getOrientationAngles(EulerAngles* _angles)
    {
        _angles->heading = orientationAngles.heading;
        _angles->pitch = orientationAngles.pitch;
        _angles->roll = orientationAngles.roll;
    }

    void getEKFData(Quaternion* quat, float* ax, float* ay, float* az, float* gx, float* gy, float* gz){
        //read the motion data
        accelerometer->getEvent(&accel_event);
        gyroscope->getEvent(&gyro_event);
        magnetometer->getEvent(&mag_event);

        // calibrate the events
        imuCalibration.calibrate(mag_event);
        imuCalibration.calibrate(accel_event);
        imuCalibration.calibrate(gyro_event);
        
        *ax = accel_event.acceleration.x;
        *ay = accel_event.acceleration.y;
        *az = accel_event.acceleration.z;
        *gx = gyro_event.gyro.x;
        *gy = gyro_event.gyro.y;
        *gz = gyro_event.gyro.z;

        //get the orientation quaternion
        fusionFilter.getQuaternion(&(quat->w), &(quat->x), &(quat->y), &(quat->z));
    }

}