#include <Arduino.h>
#include "Adafruit_Sensor_Calibration.h"
#include "Adafruit_ICM20X.h"
#include "Adafruit_ICM20948.h"

//#define CAL
#define CAL_WRITE
//#define CAL_READ

//create imu object
Adafruit_ICM20948 imu;


Adafruit_Sensor *accelerometer, *gyroscope, *magnetometer;
sensors_event_t mag_event, gyro_event, accel_event;

//EEPROM for storage:
Adafruit_Sensor_Calibration_EEPROM cal;

int loopcount = 0;

void readEEPROM(){
  Serial.begin(115200);
  while (!Serial) delay(10);

  delay(100);
  Serial.println("Calibration filesys test");
  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
    while (1) yield();
  }
  Serial.print("Has EEPROM: "); Serial.println(cal.hasEEPROM());
  Serial.print("Has FLASH: "); Serial.println(cal.hasFLASH());

  if (! cal.loadCalibration()) {
    Serial.println("**WARNING** No calibration loaded/found");
  }
  cal.printSavedCalibration();

  Serial.println("Calibrations found: ");
  Serial.print("\tMagnetic Hard Offset: ");
  for (int i=0; i<3; i++) {
    Serial.print(cal.mag_hardiron[i]); 
    if (i != 2) Serial.print(", ");
  }
  Serial.println();
  
  Serial.print("\tMagnetic Soft Offset: ");
  for (int i=0; i<9; i++) {
    Serial.print(cal.mag_softiron[i]); 
    if (i != 8) Serial.print(", ");
  }
  Serial.println();

  Serial.print("\tMagnetic Field Magnitude: ");
  Serial.println(cal.mag_field);

  Serial.print("\tGyro Zero Rate Offset: ");
  for (int i=0; i<3; i++) {
    Serial.print(cal.gyro_zerorate[i]); 
    if (i != 2) Serial.print(", ");
  }
  Serial.println();

  Serial.print("\tAccel Zero G Offset: ");
  for (int i=0; i<3; i++) {
    Serial.print(cal.accel_zerog[i]); 
    if (i != 2) Serial.print(", ");
  }
  Serial.println();
}

void writeEEPROM(){
  Serial.begin(115200);
  while (!Serial) delay(10);

  delay(100);
  Serial.println("Calibration filesys test");
  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
    while (1) yield();
  }
  Serial.print("Has EEPROM: "); Serial.println(cal.hasEEPROM());
  Serial.print("Has FLASH: "); Serial.println(cal.hasFLASH());

  if (! cal.loadCalibration()) {
    Serial.println("No calibration loaded/found... will start with defaults");
  } else {
    Serial.println("Loaded existing calibration");
  }

  // in uTesla
  cal.mag_hardiron[0] = 34.81;
  cal.mag_hardiron[1] = 6.25;
  cal.mag_hardiron[2] = 44.93;

  // in uTesla
  cal.mag_softiron[0] = 1.066;
  cal.mag_softiron[1] = 0.010;
  cal.mag_softiron[2] = 0.042;  
  cal.mag_softiron[3] = 0.010;
  cal.mag_softiron[4] = 0.946;
  cal.mag_softiron[5] = 0.015;  
  cal.mag_softiron[6] = 0.042;
  cal.mag_softiron[7] = 0.015;
  cal.mag_softiron[8] = 0.994;
  // Earth total magnetic field strength in uTesla (dependent on location and time of the year),
  // visit: https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml#igrfwmm)
  cal.mag_field = 48.14; // approximate value for locations along the equator

  // in Radians/s
  cal.gyro_zerorate[0] = 0.00;
  cal.gyro_zerorate[1] = -0.00;
  cal.gyro_zerorate[2] = -0.00;

  if (! cal.saveCalibration()) {
    Serial.println("**WARNING** Couldn't save calibration");
  } else {
    Serial.println("Wrote calibration");    
  }

  cal.printSavedCalibration();
}

// void setupCalibration(){
//   Serial.begin(115200);
//   while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens
//   Serial.println(F("Adafruit AHRS - IMU Calibration!"));
//   Serial.println("Calibration filesys test");
//   if (!cal.begin()) {
//     Serial.println("Failed to initialize calibration helper");
//     while (1) yield();
//   }
//   if (!cal.loadCalibration()) {
//     Serial.println("No calibration loaded/found... will start with defaults");
//   } else {
//     Serial.println("Loaded existing calibration");
//   }
//   accelerometer->printSensorDetails();
//   gyroscope->printSensorDetails();
//   magnetometer->printSensorDetails();
// }

void setupIMU(){
  Serial.begin(115200);

  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  if (!imu.begin_I2C()) {
    Serial.println("Failed to find ICM20948 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("ICM20948 Found!");
  // imu.setAccelRange(ICM20948_ACCEL_RANGE_16_G);
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

  // imu.setGyroRange(ICM20948_GYRO_RANGE_2000_DPS);
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

  // imu.setMagDataRate(AK09916_MAG_DATARATE_10_HZ);
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

  accelerometer = imu.getAccelerometerSensor();
  gyroscope = imu.getGyroSensor();
  magnetometer = imu.getMagnetometerSensor();
}

/*CALIBRATION CODE*/

byte caldata[68]; // buffer to receive magnetic calibration data
byte calcount=0;

uint16_t crc16_update(uint16_t crc, uint8_t a){
  int i;
  crc ^= a;
  for (i = 0; i < 8; i++) {
    if (crc & 1) {
      crc = (crc >> 1) ^ 0xA001;
    } else {
      crc = (crc >> 1);
    }
  }
  return crc;
}

void receiveCalibration() {
  uint16_t crc;
  byte b, i;

  while (Serial.available()) {
    b = Serial.read();
    if (calcount == 0 && b != 117) {
      // first byte must be 117
      return;
    }
    if (calcount == 1 && b != 84) {
      // second byte must be 84
      calcount = 0;
      return;
    }
    // store this byte
    caldata[calcount++] = b;
    if (calcount < 68) {
      // full calibration message is 68 bytes
      return;
    }
    // verify the crc16 check
    crc = 0xFFFF;
    for (i=0; i < 68; i++) {
      crc = crc16_update(crc, caldata[i]);
    }
    if (crc == 0) {
      // data looks good, use it
      float offsets[16];
      memcpy(offsets, caldata+2, 16*4);
      cal.accel_zerog[0] = offsets[0];
      cal.accel_zerog[1] = offsets[1];
      cal.accel_zerog[2] = offsets[2];
      
      cal.gyro_zerorate[0] = offsets[3];
      cal.gyro_zerorate[1] = offsets[4];
      cal.gyro_zerorate[2] = offsets[5];
      
      cal.mag_hardiron[0] = offsets[6];
      cal.mag_hardiron[1] = offsets[7];
      cal.mag_hardiron[2] = offsets[8];

      cal.mag_field = offsets[9];
      
      cal.mag_softiron[0] = offsets[10];
      cal.mag_softiron[1] = offsets[13];
      cal.mag_softiron[2] = offsets[14];
      cal.mag_softiron[3] = offsets[13];
      cal.mag_softiron[4] = offsets[11];
      cal.mag_softiron[5] = offsets[15];
      cal.mag_softiron[6] = offsets[14];
      cal.mag_softiron[7] = offsets[15];
      cal.mag_softiron[8] = offsets[12];

      if (! cal.saveCalibration()) {
        Serial.println("**WARNING** Couldn't save calibration");
      } else {
        Serial.println("Wrote calibration");    
      }
      cal.printSavedCalibration();
      calcount = 0;
      return;
    }
    // look for the 117,84 in the data, before discarding
    for (i=2; i < 67; i++) {
      if (caldata[i] == 117 && caldata[i+1] == 84) {
        // found possible start within data
        calcount = 68 - i;
        memmove(caldata, caldata + i, calcount);
        return;
      }
    }
    // look for 117 in last byte
    if (caldata[67] == 117) {
      caldata[0] = 117;
      calcount = 1;
    } else {
      calcount = 0;
    }
  }
}

// (Put in main loop)
void calibrate(){
  //get sensor data events
  magnetometer->getEvent(&mag_event);
  gyroscope->getEvent(&gyro_event);
  accelerometer->getEvent(&accel_event);

  // 'Raw' values to match expectation of MotionCal
  Serial.print("Raw:");
  Serial.print(int(accel_event.acceleration.x*8192/9.8)); Serial.print(",");
  Serial.print(int(accel_event.acceleration.y*8192/9.8)); Serial.print(",");
  Serial.print(int(accel_event.acceleration.z*8192/9.8)); Serial.print(",");
  Serial.print(int(gyro_event.gyro.x*SENSORS_RADS_TO_DPS*16)); Serial.print(",");
  Serial.print(int(gyro_event.gyro.y*SENSORS_RADS_TO_DPS*16)); Serial.print(",");
  Serial.print(int(gyro_event.gyro.z*SENSORS_RADS_TO_DPS*16)); Serial.print(",");
  Serial.print(int(mag_event.magnetic.x*10)); Serial.print(",");
  Serial.print(int(mag_event.magnetic.y*10)); Serial.print(",");
  Serial.print(int(mag_event.magnetic.z*10)); Serial.println("");

  // unified data
  Serial.print("Uni:");
  Serial.print(accel_event.acceleration.x); Serial.print(",");
  Serial.print(accel_event.acceleration.y); Serial.print(",");
  Serial.print(accel_event.acceleration.z); Serial.print(",");
  Serial.print(gyro_event.gyro.x, 4); Serial.print(",");
  Serial.print(gyro_event.gyro.y, 4); Serial.print(",");
  Serial.print(gyro_event.gyro.z, 4); Serial.print(",");
  Serial.print(mag_event.magnetic.x); Serial.print(",");
  Serial.print(mag_event.magnetic.y); Serial.print(",");
  Serial.print(mag_event.magnetic.z); Serial.println("");

  loopcount++;
  receiveCalibration();

  // occasionally print calibration
  if (loopcount == 50 || loopcount > 100) {
    Serial.print("Cal1:");
    for (int i=0; i<3; i++) {
      Serial.print(cal.accel_zerog[i], 3); 
      Serial.print(",");
    }
    for (int i=0; i<3; i++) {
      Serial.print(cal.gyro_zerorate[i], 3);
      Serial.print(",");
    }  
    for (int i=0; i<3; i++) {
      Serial.print(cal.mag_hardiron[i], 3); 
      Serial.print(",");
    }  
    Serial.println(cal.mag_field, 3);
    loopcount++;
  }
  if (loopcount >= 100) {
    Serial.print("Cal2:");
    for (int i=0; i<9; i++) {
      Serial.print(cal.mag_softiron[i], 4); 
      if (i < 8) Serial.print(',');
    }
    Serial.println();
    loopcount = 0;
  }

  delay(10); 
}

/*END OF CALIBRATION CODE*/

void setup() {
  setupIMU(); //setup the icm-20948 ready for calibration
  #ifdef CAL_WRITE
  writeEEPROM();
  #endif
  #ifdef CAL_READ
  readEEPROM();
  #endif
}

void loop() {
  #ifdef CAL
  calibrate();
  #endif
}