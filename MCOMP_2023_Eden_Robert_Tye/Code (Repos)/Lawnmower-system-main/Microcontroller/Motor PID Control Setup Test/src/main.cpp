#include <Arduino.h>

#include "PID_v1.h"
#include "CytronMotorDriver.h"

/* CONNECTIONS:
 *
 * ESP32 D34 - Motor Driver PWM 1A Input
 * ESP32 D35 - Motor Driver PWM 1B Input
 * ESP32 D32 - Motor Driver PWM 2A Input
 * ESP32 D33  - Motor Driver PWM 2B Input
 * ESP32 GND - Motor Driver GND
 *
 */

  #define MOTOR_1A 33 // ORANGE wire, right motor
  #define MOTOR_1B 32 // YELLOW wire, right motor
  #define MOTOR_2A 25 // PURPLE wire, left motor
  #define MOTOR_2B 26 // BLUE wire, left motor

  #define MOTOR_ENCODER_1A 13 //right encoder
  #define MOTOR_ENCODER_1B 12 //right encoder
  #define MOTOR_ENCODER_2A 27 //left encoder
  #define MOTOR_ENCODER_2B 14 //left encoder

  #define PID_SAMPLE_RATE 33 // ~33ms = 30Hz. https://www.unitjuggler.com/convert-frequency-from-Hz-to-ms(p).html
  // These let us convert ticks-to-RPM
  #define GEARING     45
  #define ENCODERMULT 14

  #define MIN_PWM 0 // ~35 equal to 4 rpm
  #define MAX_RPM 133 // Would be best to cap this as it can spike (seen it hit 408 before)

  #define CPR 266 //encoder counts per revolution (of motor) 
  #define CPT 1081 //encoder counts per track length () 

  // current motor encoder counts
  double motorCurrentRPMR, motorPWMR, motorTargetRPMR = 35; // ~266 counts per revolution (motor), ~1081 per full track rotation
  double motorCurrentRPML, motorPWML, motorTargetRPML = 35; // ~266 counts per revolution (motor), ~1081 per full track rotation
  //double motorEncoderR;
  //double motorEncoderL;
  // current motor Direction
  bool motorDirR; // false->forward 
  bool motorDirL; // false->forward
  //last motor interrupt time
  long motorLastTimeR;
  long motorLastTimeL;

  // tuning resource guide: https://pidexplained.com/how-to-tune-a-pid-controller/
  // tuning Sim. -> http://grauonline.de/alexwww/ardumower/pid/pid.html
  //PID constants
  float kp = 0.5;
  float ki = 1;
  float kd = 0;
  PID leftMotorPID(&motorCurrentRPML, &motorPWML, &motorTargetRPML, kp, ki, kd, DIRECT);
  PID rightMotorPID(&motorCurrentRPMR, &motorPWMR, &motorTargetRPMR, kp, ki, kd, DIRECT);

  CytronMD motorR(PWM_PWM, MOTOR_1A, MOTOR_1B); //Right motor
  CytronMD motorL(PWM_PWM, MOTOR_2A, MOTOR_2B); //left motor

void leftMotorInterrupt(){
  motorDirL = digitalRead(MOTOR_ENCODER_2B);

  //calc the rpm
  uint32_t currentTime = micros();
  if (motorLastTimeL < currentTime){
    // did not wrap around
    double rev = currentTime - motorLastTimeL;  // us
    rev = 1.0 / rev;            // rev per us
    rev *= 1000000;             // rev per sec
    rev *= 60;                  // rev per min
    rev /= GEARING;             // account for gear ratio
    rev /= ENCODERMULT;         // account for multiple ticks per rotation
    motorCurrentRPML = rev;
  }
  motorLastTimeL = currentTime;
}

void rightMotorInterrupt(){
  motorDirR = digitalRead(MOTOR_ENCODER_1B);
  //calc the rpm
  uint32_t currentTime = micros();
  if (motorLastTimeR < currentTime){
    // did not wrap around
    double rev = currentTime - motorLastTimeR;  // us
    rev = 1.0 / rev;            // rev per us
    rev *= 1000000;             // rev per sec
    rev *= 60;                  // rev per min
    rev /= GEARING;             // account for gear ratio
    rev /= ENCODERMULT;         // account for multiple ticks per rotation
    motorCurrentRPMR = rev;
  }
  motorLastTimeR = currentTime;
}

void initMotorEncoders(){
  //set the motor direction state
  motorDirR = false;
  motorDirL = false;
  //set the encoder read input pins
  // Right:
  pinMode(MOTOR_ENCODER_1A, INPUT_PULLUP);
  pinMode(MOTOR_ENCODER_1B, INPUT_PULLUP);
  // left:
  pinMode(MOTOR_ENCODER_2A, INPUT_PULLUP);
  pinMode(MOTOR_ENCODER_2B, INPUT_PULLUP);

  //attach the interrupts to an encoder pin
  attachInterrupt(MOTOR_ENCODER_1A, rightMotorInterrupt, RISING);
  attachInterrupt(MOTOR_ENCODER_2A, leftMotorInterrupt, RISING);
}

void initPIDSettings(){
  leftMotorPID.SetMode(AUTOMATIC);
  leftMotorPID.SetSampleTime(PID_SAMPLE_RATE);
  leftMotorPID.SetOutputLimits(MIN_PWM, 255);
  
  rightMotorPID.SetMode(AUTOMATIC);
  rightMotorPID.SetSampleTime(PID_SAMPLE_RATE);
  rightMotorPID.SetOutputLimits(MIN_PWM, 255);
}

void PWMtoRPMrelationship(){
    for (int i = 0; i < 255; i++)
    {
      motorL.setSpeed(i);
      motorR.setSpeed(i);
      delay(200);
      Serial.print(i);
      Serial.print(",");
      Serial.print((int)motorCurrentRPMR);
      Serial.print(",");
      Serial.println((int)motorCurrentRPML);
    }
    delay(500);
    for (int i = 255; i > 0; i--)
    {
      motorL.setSpeed(i);
      motorR.setSpeed(i);
      delay(200);
      Serial.print(i);
      Serial.print(",");
      Serial.print((int)motorCurrentRPMR);
      Serial.print(",");
      Serial.println((int)motorCurrentRPML);
    }
    motorL.setSpeed(0);
    while (1)
    {
      /* code */
    }
}

void setup() {
  Serial.begin(115200);
  initMotorEncoders();
  initPIDSettings();
  motorL.setSpeed(0);
  motorR.setSpeed(0);

  PWMtoRPMrelationship();
}

void loop() {
  motorL.setSpeed((int16_t)motorPWML);
  motorR.setSpeed((int16_t)motorPWMR);

  // // Perform PID calc on motors
  // if(leftMotorPID.Compute()){
  //   // Serial.print(motorCurrentRPML);  
  //   // Serial.print(", ");  
  //   // Serial.print(motorTargetRPML);  
  //   // Serial.print(", ");  
  //   // Serial.print(motorPWML);  
  //   // Serial.println();  
  //   motorCurrentRPML = 0;
  // }
  // if(rightMotorPID.Compute()){
  //   // Serial.print(motorCurrentRPMR);  
  //   // Serial.print(", ");  
  //   // Serial.print(motorTargetRPMR);  
  //   // Serial.print(", ");  
  //   // Serial.print(motorPWMR);  
  //   // Serial.println();  
  //   motorCurrentRPMR = 0;
  // }
  //delay(10);
}

