/*
The magnometer uses a different axis system than accel & gyro. (Correct by our sensor it seems)
Have to correct the mag data to compensate, prob??? https://forums.adafruit.com/viewtopic.php?f=8&p=922080


*/
#include <Arduino.h>

#include "Adafruit_ICM20X.h"
#include "Adafruit_ICM20948.h"
#include "Adafruit_Sensor_Calibration.h"
#include "Adafruit_AHRS.h"

//#define ASAP
#define PLOT
// #define EVENT
//#define QUAT
#define FILTER_UPDATE_RATE_HZ 200 /*The best case (max) number of samples per second is 285-287, therefore ~300 is the Max Hz. We are more likely to hit a limit in the serial baud rate though (depending on update transmission requests)*/
#define PRINT_EVERY_N_UPDATES 25 /*Limit the Samples printed per N filter updates*/
uint32_t timestamp;

/* pick filter: (top to bottom)slower == better quality output */
// #define NXP /*3 deg out (Heading) (3 deg) <== SLOOWWW. (Had to rotate the sensor 180 to get accurate reading + can get out of control and cycling "forever"(1.5hr+))*/
// #define MADGWICK /*5 deg out (Heading) (355 deg) <== ~2-5 MIN. Seems Less reliable between Power cycles though??*/
#define MAHONY /*6 deg out (Heading) <=== SUPER SLOW to stablise on bot 30MIN+*/

//#define AHRS_DEBUG_OUTPUT /*UNCOMMENT TO ENABLE AHRS DEBUG*/
#define PRINT_CALIBRATION

#ifdef NXP
Adafruit_NXPSensorFusion filter; // slowest (High RAM)
#endif
#ifdef MADGWICK
Adafruit_Madgwick filter(2);  // faster than NXP (Middle ground)
#endif
#ifdef MAHONY
Adafruit_Mahony filter(5, 0);  // fastest/smallest (Cheapest)
#endif

//create imu object
Adafruit_ICM20948 imu;

Adafruit_Sensor *accelerometer, *gyroscope, *magnetometer;
sensors_event_t mag_event, gyro_event, accel_event;

//EEPROM for storage:
Adafruit_Sensor_Calibration_EEPROM cal;

float roll, pitch, heading; // "heading" is similar/equal to "yaw". The angle from Magnetic North
float gx, gy, gz; //deg value versions for the gyro
static uint8_t counter = 0;

void setupIMU(){

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

  Wire.setClock(400000); // 400KHz
}

void readEEPROM(){
  while (!Serial) delay(10);

  delay(100);

  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
    while (1) yield();
  }

  #ifdef PRINT_CALIBRATION
  Serial.print("Has EEPROM: "); Serial.println(cal.hasEEPROM());
  Serial.print("Has FLASH: "); Serial.println(cal.hasFLASH());
  #endif

  if (! cal.loadCalibration()) {
    Serial.println("**WARNING** No calibration loaded/found");
  }

  #ifdef PRINT_CALIBRATION
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
  #endif
}

void setupFilter(){
  filter.begin(FILTER_UPDATE_RATE_HZ);
  timestamp = millis();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  readEEPROM();
  setupIMU(); //setup the icm-20948
  //Setup up the AHRS Filter
  setupFilter();
}

void loop() {
  #ifndef ASAP
  if ((millis() - timestamp) < (1000 / FILTER_UPDATE_RATE_HZ)) {
    return;
  }
  #endif

  timestamp = millis();

  //read the motion data
  accelerometer->getEvent(&accel_event);
  gyroscope->getEvent(&gyro_event);
  magnetometer->getEvent(&mag_event);

  #ifdef AHRS_DEBUG_OUTPUT
  Serial.print("I2C took "); Serial.print(millis()-timestamp); Serial.println(" ms");
  #endif

  // calibrate the events
  cal.calibrate(mag_event);
  cal.calibrate(accel_event);
  cal.calibrate(gyro_event);

  //convert the gyro reading from rads to degs
  gx = gyro_event.gyro.x * SENSORS_RADS_TO_DPS;
  gy = gyro_event.gyro.y * SENSORS_RADS_TO_DPS;
  gz = gyro_event.gyro.z * SENSORS_RADS_TO_DPS;

  //update the filter
  filter.update(
    gx, gy, gz, 
    accel_event.acceleration.x, accel_event.acceleration.y, accel_event.acceleration.z, 
    mag_event.magnetic.x, -mag_event.magnetic.y, -mag_event.magnetic.z);
  #if defined(AHRS_DEBUG_OUTPUT)
  Serial.print("Update took "); Serial.print(millis()-timestamp); Serial.println(" ms");
  #endif

  #ifdef PRINT_EVERY_N_UPDATES
  // only print the calculated output once in a while
  if (counter++ <= PRINT_EVERY_N_UPDATES) {
    return;
  }
  // reset the counter
  counter = 0;
  #endif

  #ifdef AHRS_DEBUG_OUTPUT
  Serial.print("Raw: ");
  Serial.print(accel_event.acceleration.x, 4); Serial.print(", ");
  Serial.print(accel_event.acceleration.y, 4); Serial.print(", ");
  Serial.print(accel_event.acceleration.z, 4); Serial.print(", ");
  Serial.print(gx, 4); Serial.print(", ");
  Serial.print(gy, 4); Serial.print(", ");
  Serial.print(gz, 4); Serial.print(", ");
  Serial.print(mag_event.magnetic.x, 4); Serial.print(", ");
  Serial.print(mag_event.magnetic.y, 4); Serial.print(", ");
  Serial.print(mag_event.magnetic.z, 4); Serial.println("");
  #endif

#ifdef EVENT
  Serial.print(mag_event.orientation.x);
  Serial.print(", ");
  Serial.print(mag_event.orientation.y);
  Serial.print(", ");
  Serial.println(mag_event.orientation.z);
#endif

#ifndef QUAT
  // // print the heading, pitch and roll
  roll = filter.getRoll();
  pitch = filter.getPitch();
  heading = filter.getYaw();
  #ifndef PLOT
  Serial.print("Orientation: ");
  #endif
  Serial.print(heading);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.println(roll);
#else
  float qw, qx, qy, qz;
  filter.getQuaternion(&qw, &qx, &qy, &qz);
  #ifndef PLOT
  Serial.print("Quaternion: ");
  #endif
  Serial.print(qw, 4);
  Serial.print(", ");
  Serial.print(qx, 4);
  Serial.print(", ");
  Serial.print(qy, 4);
  Serial.print(", ");
  Serial.println(qz, 4);  
#endif
  #ifdef AHRS_DEBUG_OUTPUT
  Serial.print("Took "); Serial.print(millis()-timestamp); Serial.println(" ms");
  #endif
}