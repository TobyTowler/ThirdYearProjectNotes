#include <Arduino.h>
#include "ICM_20948.h"
#include "Orientation.h"

//#define QUAT_ANIMATION // Uncomment this line to output data in the correct format for ZaneL's Node.js Quaternion animation tool: https://github.com/ZaneL/quaternion_sensor_3d_nodejs
#define ORI
//#define R_VEC

//I2C prep for IMU
#define WIRE_PORT Wire // desired Wire port.
// The value of the last bit of the I2C address.
// On the SparkFun 9DoF IMU breakout the default is 1, and when the ADR jumper is closed the value becomes 0
#define AD0_VAL 1
ICM_20948_I2C imu;

//raw quaternion data 
icm_20948_DMP_data_t imuQuatData;
//quaternion data
Quaternion quat; // q0, q1, q2, q3
int16_t quatAccuracy;

//Current Euler Angle
EulerAngles angles_rad;
EulerAngles angles_deg;

//IMU sensor Data
float accelData[3]; // x, y, z
float gyroData[3]; // x, y, z
float magData[3]; // x, y, z

float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause until serial console opens

  #ifndef QUAT_ANIMATION
    Serial.println();
    Serial.println(F("ICM-20948 Example"));
  #endif

  //initialise the IMU
  WIRE_PORT.begin();
  WIRE_PORT.setClock(400000);
  do{
    // With DMP is enabled, .begin performs a minimal startup so need to configure the sample mode etc... manually
    imu.begin(WIRE_PORT, AD0_VAL); 
    delay(500);
  } while(imu.status != ICM_20948_Stat_Ok);
  
  #ifndef QUAT_ANIMATION
    Serial.println("IMU Connected.");
  #endif

  // Do a SW reset to make sure the device starts in a known state
  imu.swReset();
  if (imu.status != ICM_20948_Stat_Ok)
  {
    #ifndef QUAT_ANIMATION
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
    #ifndef QUAT_ANIMATION
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
  //    INV_ICM20948_SENSOR_STEP_DETECTOR               (Pedometer Step Detector)
  //    INV_ICM20948_SENSOR_STEP_COUNTER                (Pedometer Step Detector)
  //    INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR        (32-bit 6-axis quaternion)
  //    INV_ICM20948_SENSOR_ROTATION_VECTOR             (32-bit 9-axis quaternion + heading accuracy)
  //    INV_ICM20948_SENSOR_GEOMAGNETIC_ROTATION_VECTOR (32-bit Geomag RV + heading accuracy)
  //    INV_ICM20948_SENSOR_GEOMAGNETIC_FIELD           (32-bit calibrated compass)
  //    INV_ICM20948_SENSOR_GRAVITY                     (32-bit 6-axis quaternion)
  //    INV_ICM20948_SENSOR_LINEAR_ACCELERATION         (16-bit accel + 32-bit 6-axis quaternion)
  //    INV_ICM20948_SENSOR_ORIENTATION                 (32-bit 9-axis quaternion + heading accuracy)

  // Enable the DMP orientation sensor
  #ifdef ORI
  success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_ORIENTATION) == ICM_20948_Stat_Ok);
  #endif
  // Enable the DMP Game Rotation Vector sensor
  #ifdef R_VEC
  success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_GAME_ROTATION_VECTOR) == ICM_20948_Stat_Ok);
  #endif
  
  // Enable any additional sensors / features
  //success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_RAW_GYROSCOPE) == ICM_20948_Stat_Ok);
  //success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_RAW_ACCELEROMETER) == ICM_20948_Stat_Ok);
  //success &= (imu.enableDMPSensor(INV_ICM20948_SENSOR_MAGNETIC_FIELD_UNCALIBRATED) == ICM_20948_Stat_Ok);

  // Configuring DMP to output data at multiple ODRs:
  // DMP is capable of outputting multiple sensor data at different rates to FIFO.
  // Setting value can be calculated as follows:
  // Value = (DMP running rate / ODR ) - 1
  // E.g. For a 5Hz ODR rate when DMP is running at 55Hz, value = (55/5) - 1 = 10.
  #ifdef ORI
  success &= (imu.setDMPODRrate(DMP_ODR_Reg_Quat9, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  #endif
  #ifdef R_VEC
  success &= (imu.setDMPODRrate(DMP_ODR_Reg_Quat6, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  #endif
  //success &= (imu.setDMPODRrate(DMP_ODR_Reg_Accel, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  //success &= (imu.setDMPODRrate(DMP_ODR_Reg_Gyro, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  //success &= (imu.setDMPODRrate(DMP_ODR_Reg_Gyro_Calibr, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  //success &= (imu.setDMPODRrate(DMP_ODR_Reg_Cpass, 0) == ICM_20948_Stat_Ok); // Set to the maximum
  //success &= (imu.setDMPODRrate(DMP_ODR_Reg_Cpass_Calibr, 0) == ICM_20948_Stat_Ok); // Set to the maximum

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
    #ifndef QUAT_ANIMATION
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


  #ifndef QUAT_ANIMATION
    Serial.println();
    Serial.println(F("Configuration complete!"));
  #endif
}

void getSensorData(){
  if (imu.dataReady())
  {
    imu.getAGMT();
    //get accel data (raw data values are in mg.)
    accelData[0] = imu.accX();
    accelData[1] = imu.accY();
    accelData[2] = imu.accZ();
    //get gyro data
    gyroData[0] = imu.gyrX();
    gyroData[1] = imu.gyrY();
    gyroData[2] = imu.gyrZ();
    //get mag data
    magData[0] = imu.magX();
    magData[1] = imu.magY();
    magData[2] = imu.magZ();
    //get temperature data
    temperature = imu.temp();
  }
}

void getQuaternionData(){
  imu.readDMPdataFromFIFO(&imuQuatData);

  if ((imu.status == ICM_20948_Stat_Ok) || (imu.status == ICM_20948_Stat_FIFOMoreDataAvail)) // Was valid data available?
  {
    #ifdef ORI
    if ((imuQuatData.header & DMP_header_bitmap_Quat9) > 0) // We have asked for orientation data so we should receive Quat9
    #endif
    #ifdef R_VEC
    if ((imuQuatData.header & DMP_header_bitmap_Quat6) > 0) // We have asked for orientation data so we should receive Quat6
    #endif
    {
      // Q0 value is computed from this equation: Q0^2 + Q1^2 + Q2^2 + Q3^2 = 1.
      // In case of drift, the sum will not add to 1, therefore, quaternion data need to be corrected with right bias values.
      // The quaternion data is scaled by 2^30.
      #ifdef ORI
      quat.x = ((double)imuQuatData.Quat9.Data.Q1) / 1073741824.0; // Convert to double. Divide by 2^30
      quat.y = ((double)imuQuatData.Quat9.Data.Q2) / 1073741824.0;
      quat.z = ((double)imuQuatData.Quat9.Data.Q3) / 1073741824.0; 
      #endif
      #ifdef R_VEC
      quat.x = ((double)imuQuatData.Quat6.Data.Q1) / 1073741824.0; // Convert to double. Divide by 2^30
      quat.y = ((double)imuQuatData.Quat6.Data.Q2) / 1073741824.0;
      quat.z = ((double)imuQuatData.Quat6.Data.Q3) / 1073741824.0; 
      #endif

      quat.w = sqrt(1.0 - ((quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z)));

      #ifdef ORI
      quatAccuracy = (imuQuatData.Quat9.Data.Accuracy);
      #endif
    }
  }
}

// Output the Quaternion data in the format expected by ZaneL's Node.js Quaternion animation tool
void printQuat9Data_DemoFormat(){
  Serial.print(F("{\"quat_w\":"));
  Serial.print(quat.w, 3);
  Serial.print(F(", \"quat_x\":"));
  Serial.print(quat.x, 3);
  Serial.print(F(", \"quat_y\":"));
  Serial.print(quat.y, 3);
  Serial.print(F(", \"quat_z\":"));
  Serial.print(quat.z, 3);
  Serial.println(F("}"));
}

void printQuat9Data(){
  Serial.print(F("quat_w (Q0):"));
  Serial.print(quat.w, 3);
  Serial.print(F(", quat_x (Q1):"));
  Serial.print(quat.x, 3);
  Serial.print(F(", quat_y (Q2):"));
  Serial.print(quat.y, 3);
  Serial.print(F(", quat_z (Q3):"));
  Serial.print(quat.z, 3);
  Serial.print(F(", quat_accuracy:"));
  Serial.println(quatAccuracy);
}

void calcEulerAngles_rad(){
  //calc the roll (x-axis rotation)
  double sinr_cosp = 2 * (quat.w * quat.x + quat.y * quat.z);
  //double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
  double cosr_cosp = 1 - 2 * (quat.x * quat.x + quat.y * quat.y);
  //double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
  angles_rad.roll = atan2(sinr_cosp, cosr_cosp);
  //angles.roll = std::atan2(sinr_cosp, cosr_cosp);

  //calc the pitch (y-axis rotation)
  double sinp = sqrt(1 + 2 * (quat.w * quat.y - quat.x * quat.z));
  // double sinp = std::sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
  double cosp = sqrt(1 - 2 * (quat.w * quat.y - quat.x * quat.z));
  // double cosp = std::sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
  angles_rad.pitch = 2 * atan2(sinp, cosp) - PI/2;
  // angles.pitch = 2 * std::atan2(sinp, cosp) - M_PI / 2;

  //calc the yaw (z-axis rotation)
  double siny_cosp = 2 * (quat.w * quat.z + quat.x * quat.y);
  // double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
  double cosy_cosp = 1 - 2 * (quat.y * quat.y + quat.z * quat.z);
  // double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
  angles_rad.yaw = atan2(siny_cosp, cosy_cosp);
  // angles.yaw = std::atan2(siny_cosp, cosy_cosp);
}

void calcEulerAngles_rad2(){
  //calc the roll (x-axis rotation)
  double sinr_cosp = 2 * (quat.w * quat.x + quat.y * quat.z);
  // double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
  double cosr_cosp = 1 - 2 * (quat.x * quat.x + quat.y * quat.y);
  // double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
  angles_rad.roll = atan2(sinr_cosp, cosr_cosp);
  // angles.roll = std::atan2(sinr_cosp, cosr_cosp);

  //calc the pitch (y-axis rotation)
  double sinp = 2 * (quat.w * quat.y - quat.z * quat.x);
  // double sinp = 2 * (q.w * q.y - q.z * q.x);
  sinp = sinp > 1.0 ? 1.0 : sinp;
  sinp = sinp < -1.0 ? -1.0 : sinp;
  angles_rad.pitch = asin(sinp);

  //calc the yaw (z-axis rotation)
  double siny_cosp = 2 * (quat.w * quat.z + quat.x * quat.y);
  // double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
  double cosy_cosp = 1 - 2 * (quat.y * quat.y + quat.z * quat.z);
  // double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
  angles_rad.yaw = atan2(siny_cosp, cosy_cosp);
  // angles.yaw = std::atan2(siny_cosp, cosy_cosp);
}

void calcEulerAnglesDeg(){
  calcEulerAngles_rad();
  //angles_deg.pitch = (double)map(angles_rad.pitch, -PI, PI, 0, 360);
  angles_deg.pitch = angles_rad.pitch * (180/PI);
  //angles_deg.roll = (double)map(angles_rad.roll, -PI, PI, -180, 360);
  angles_deg.roll = angles_rad.roll * (180/PI);
  //angles_deg.yaw = (double)map(angles_rad.yaw, -PI, PI, 0, 360);
  angles_deg.yaw = 360 - (180 + angles_rad.yaw * (180/PI));
}

void plotQuat9Data(){
  Serial.print(quat.w, 5);
  Serial.print(F(","));
  Serial.print(quat.x, 5);
  Serial.print(F(","));
  Serial.print(quat.y, 5);
  Serial.print(F(","));
  Serial.print(quat.z, 5);
  Serial.print(F(","));
  Serial.println(quatAccuracy);
}

void printEulerAngles_rad(){
  Serial.print("Roll (X): "); 
  Serial.print(angles_rad.roll, 5);
  Serial.print(", Pitch (Y): "); 
  Serial.print(angles_rad.pitch, 5);
  Serial.print(", Yaw (Z): "); 
  Serial.print(angles_rad.yaw, 5);
  Serial.println();
}

void printEulerAngles_deg(){
  Serial.print("Roll (X): "); 
  Serial.print(angles_deg.roll, 5);
  Serial.print(", Pitch (Y): "); 
  Serial.print(angles_deg.pitch, 5);
  Serial.print(", Yaw (Z): "); 
  Serial.print(angles_deg.yaw, 5);
  Serial.println();
}

void plotEulerAngles_rad(){
  Serial.print(angles_rad.roll, 5);
  Serial.print(","); 
  Serial.print(angles_rad.pitch, 5);
  Serial.print(",");
  Serial.print(angles_rad.yaw, 5);
  Serial.println();
}

void plotEulerAngles_deg(){
  Serial.print(angles_deg.roll, 1);
  Serial.print(","); 
  Serial.print(angles_deg.pitch, 1);
  Serial.print(",");
  Serial.print(angles_deg.yaw, 1);
  Serial.println();
}

void printImuData(){
  Serial.print("IMU Accel (mg) X: ");
  Serial.print(accelData[0]);
  Serial.print(" Y: ");
  Serial.print(accelData[1]);
  Serial.print(" Z: ");
  Serial.println(accelData[2]);

  Serial.print("IMU Gyro (DPS) X: ");
  Serial.print(gyroData[0]);
  Serial.print(" Y: ");
  Serial.print(gyroData[1]);
  Serial.print(" Z: ");
  Serial.println(gyroData[2]);

  Serial.print("IMU Mag (uT) X: ");
  Serial.print(magData[0]);
  Serial.print(" Y: ");
  Serial.print(magData[1]);
  Serial.print(" Z: ");
  Serial.println(magData[2]);

  Serial.print("Temperature (C): ");
  Serial.println(temperature);

  Serial.println("===============================");

}

void plotImuData(){
  //serial plotter friendly format
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(accelData[0]);
  Serial.print(","); 
  Serial.print(accelData[1]);
  Serial.print(","); 
  Serial.print(accelData[2]);
  Serial.print(",");
  Serial.print(gyroData[0]);
  Serial.print(","); 
  Serial.print(gyroData[1]);
  Serial.print(","); 
  Serial.print(gyroData[2]);
  Serial.print(",");
  Serial.print(magData[0]);
  Serial.print(","); 
  Serial.print(magData[1]);
  Serial.print(",");
  Serial.print(magData[2]);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  //getSensorData();
  getQuaternionData();
  //calcEulerAngles_rad();
  calcEulerAnglesDeg();
  #ifndef QUAT_ANIMATION
    //printImuData();
    //plotImuData();
    //plotQuat9Data();
    //printQuat9Data();
    //printEulerAngles_rad();
    //plotEulerAngles_rad();
    printEulerAngles_deg();
    // plotEulerAngles_deg();
  #else
    printQuat9Data_DemoFormat();
  #endif
  // If more data is available then we should read it right away - and not delay
  if (imu.status != ICM_20948_Stat_FIFOMoreDataAvail) 
  {
    delay(10);
  }
}