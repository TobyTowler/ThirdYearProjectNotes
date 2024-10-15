#include <Arduino.h>
#include "Orientation.h"
#include <Adafruit_BNO08x.h>

//#define QUAT_ANIMATION // Uncomment this line to output data in the correct format for ZaneL's Node.js Quaternion animation tool: https://github.com/ZaneL/quaternion_sensor_3d_nodejs
#define ORI

//imu object
#define BNO08X_RESET -1 // don't need for i2c
Adafruit_BNO08x  bno08x(BNO08X_RESET);

//quaternion data
Quaternion quat; // q0, q1, q2, q3

//Current Euler Angle
EulerAngles angles_rad;
EulerAngles angles_deg;

//IMU sensor Data
sh2_SensorValue_t sensorValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause until serial console opens

  //initialise the IMU
  if (!bno08x.begin_I2C()) {
    Serial.println("Failed to find BNO08x chip");
    while (1) { delay(10); }
  }
  
  Serial.println("IMU Connected.");

  for (int n = 0; n < bno08x.prodIds.numEntries; n++) {
    Serial.print("Part ");
    Serial.print(bno08x.prodIds.entry[n].swPartNumber);
    Serial.print(": Version :");
    Serial.print(bno08x.prodIds.entry[n].swVersionMajor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionMinor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionPatch);
    Serial.print(" Build ");
    Serial.println(bno08x.prodIds.entry[n].swBuildNumber);
  }

  delay(250);

  //configure the report option, etc...

  // Here is where you define the sensor outputs you want to receive
  if (! bno08x.enableReport(SH2_ROTATION_VECTOR, 2000)) {
    Serial.println("Could not enable ROTATION VECTOR");
  }
  if (! bno08x.enableReport(SH2_LINEAR_ACCELERATION, 2000)) {
    Serial.println("Could not enable LINEAR_ACCELERATION");
  }

  Serial.println(F("Configuration complete!"));
  delay(5000);
}

// void getQuaternionData(){

//   if (true) // Was valid data available?
//   {
//       // Q0 (w) value is computed from this equation: Q0^2 + Q1^2 + Q2^2 + Q3^2 = 1.
//       // In case of drift, the sum will not add to 1, therefore, quaternion data need to be corrected with right bias values.
//       // The quaternion data is scaled by 2^30.
//       quat.x = 
//       quat.y = 
//       quat.z =  

//       quat.w = sqrt(1.0 - ((quat.x * quat.x) + (quat.y * quat.y) + (quat.z * quat.z)));

//   }
// }

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
  Serial.println(quat.z, 3);
}

void plotQuat9Data(){
  Serial.print(quat.w, 5);
  Serial.print(F(","));
  Serial.print(quat.x, 5);
  Serial.print(F(","));
  Serial.print(quat.y, 5);
  Serial.print(F(","));
  Serial.println(quat.z, 5);
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
  Serial.print("");
  Serial.print(" Y: ");
  Serial.print("");
  Serial.print(" Z: ");
  Serial.println();

  Serial.print("IMU Gyro (DPS) X: ");
  Serial.print("");
  Serial.print(" Y: ");
  Serial.print("");
  Serial.print(" Z: ");
  Serial.println();

  Serial.print("IMU Mag (uT) X: ");
  Serial.print("");
  Serial.print(" Y: ");
  Serial.print("");
  Serial.print(" Z: ");
  Serial.println();

  Serial.println("===============================");

}

void plotImuData(){
  //serial plotter friendly format

  Serial.print("");
  Serial.print(","); 
  Serial.print("");
  Serial.print(","); 
  Serial.print("");
  Serial.print(",");
  Serial.print("");
  Serial.print(","); 
  Serial.print("");
  Serial.print(","); 
  Serial.print("");
  Serial.print(",");
  Serial.print("");
  Serial.print(","); 
  Serial.print("");
  Serial.print(",");
  Serial.print("");
  Serial.println();
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

void calcEulerAnglesDeg(){
  calcEulerAngles_rad();
  //angles_deg.pitch = (double)map(angles_rad.pitch, -PI, PI, 0, 360);
  angles_deg.pitch = angles_rad.pitch * (180/PI);
  //angles_deg.roll = (double)map(angles_rad.roll, -PI, PI, -180, 360);
  angles_deg.roll = angles_rad.roll * (180/PI);
  //angles_deg.yaw = (double)map(angles_rad.yaw, -PI, PI, 0, 360);
  angles_deg.yaw = 360 - (180 + angles_rad.yaw * (180/PI));
}


void loop() {
  // check if data is ready
  if (! bno08x.getSensorEvent(&sensorValue)) {
    return;
  }

  Serial.print("Calibration accuracy: ");
  Serial.print(sensorValue.status);
  Serial.print(", ");

  switch (sensorValue.sensorId) {
    case SH2_ROTATION_VECTOR:
      quat.w = sensorValue.un.rotationVector.real;
      quat.x = sensorValue.un.rotationVector.i;
      quat.y = sensorValue.un.rotationVector.j;
      quat.z = sensorValue.un.rotationVector.k;
      break;
    case SH2_LINEAR_ACCELERATION:
      Serial.print("Linear Acceration - x: ");
      Serial.print(sensorValue.un.linearAcceleration.x, 5);
      Serial.print(" y: ");
      Serial.print(sensorValue.un.linearAcceleration.y, 5);
      Serial.print(" z: ");
      Serial.println(sensorValue.un.linearAcceleration.z, 5);
      break;
  }

  calcEulerAnglesDeg();

  // getQuaternionData();
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
  delay(10);
}