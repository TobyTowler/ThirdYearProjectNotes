#include <Arduino.h>
#include "CytronMotorDriver.h"

/* CONNECTIONS:
 * 
 * Arduino D10 - Motor Driver PWM 1A Input
 * Arduino D11 - Motor Driver PWM 1B Input
 * Arduino D6  - Motor Driver PWM 2A Input
 * Arduino D7  - Motor Driver PWM 2B Input
 * Arduino GND - Motor Driver GND
 * 
 * Arduino A0  - Potentiometer
*/

CytronMD motor1(PWM_PWM, 10, 11);
CytronMD motor2(PWM_PWM, 6, 7);

int16_t speed = 0; //mapped pot read value to motor speed value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  speed = map(analogRead(A0),0,1023,0,255);
  Serial.print("Current Speed: ");
  Serial.print((speed/255.0)*100);
  Serial.println("\%");

  motor2.setSpeed(speed);  // Motor 2 runs forwards at Read speed.
}