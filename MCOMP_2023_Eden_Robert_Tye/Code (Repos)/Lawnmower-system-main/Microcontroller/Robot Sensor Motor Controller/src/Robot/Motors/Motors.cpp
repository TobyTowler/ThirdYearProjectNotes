#include "Motors.h"

namespace Motors{
    CytronMD motorR(PWM_PWM, MOTOR_1A, MOTOR_1B);
    CytronMD motorL(PWM_PWM, MOTOR_2A, MOTOR_2B);

    PID leftMotorPID(&motorCurrentRPML, &motorPWML, &motorTargetRPML, kp, ki, kd, DIRECT);
    PID rightMotorPID(&motorCurrentRPMR, &motorPWMR, &motorTargetRPMR, kp, ki, kd, DIRECT);
    
    // motor speed values
    double motorCurrentRPMR = 0, motorPWMR = 0;
    double motorTargetRPMR = 0;
    double motorCurrentRPML = 0, motorPWML = 0;
    double motorTargetRPML = 0;
    // current motor Direction
    bool motorCurDirR = false; // false->forward 
    bool motorCurDirL = false; // false->forward
    // required motor Direction
    int16_t motorTargetDirR = 1; // 1->forward, -1->Backward 
    int16_t motorTargetDirL = 1; // 1->forward, -1->Backward
    //last motor interrupt time
    long motorLastTimeR = 0;
    long motorLastTimeL = 0;
    // motor encoder counts
    long motorCountL = 0;
    long motorCountR = 0;

    // PID Tuning values
    float kp = 0.5;
    float ki = 1;
    float kd = 0;
    // float kp = 0.02;
    // float ki = 0.00015 ;
    // float kd = 0;

    void leftMotorInterrupt(){
        motorCurDirL = digitalRead(MOTOR_ENCODER_2B);
        // track the encoder counts with respect to the direction it's turning
        motorCurDirL ? motorCountL-- : motorCountL++;
        
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
        //Serial.println("left interupt");
    }

    void rightMotorInterrupt(){
        motorCurDirR = digitalRead(MOTOR_ENCODER_1B);
        // track the encoder counts with respect to the direction it's turning
        motorCurDirR ? motorCountR-- : motorCountR++;

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
        //Serial.println("right interupt");
    }

    void initMotorEncoders(){
        //set the motor direction state
        motorCurDirR = false;
        motorCurDirL = false;
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
        leftMotorPID.SetOutputLimits(MIN_PWM_L, MAX_PWM_L);
        
        rightMotorPID.SetMode(AUTOMATIC);
        rightMotorPID.SetSampleTime(PID_SAMPLE_RATE);
        rightMotorPID.SetOutputLimits(MIN_PWM_R, MAX_PWM_R);
    }

    void setMotorSpeedsPWM(int16_t _motorL, int16_t _motorR)
    {
        //get the target direction requested
        if (_motorL < 0) motorTargetDirL = -1;
        else motorTargetDirL = 1;
        if (_motorR < 0) motorTargetDirR = -1;
        else motorTargetDirR = 1;
  
        motorPWML = _motorL;
        motorPWMR = _motorR;

        motorR.setSpeed(_motorR);
        motorL.setSpeed(_motorL);
    }
    
    void setMotorSpeedsRPM(int16_t _motorL, int16_t _motorR)
    {
        //get the target direction requested
        if (_motorL < 0) motorTargetDirL = -1;
        else if (_motorR > 0) motorTargetDirL = 1;
        if (_motorR < 0) motorTargetDirR = -1;
        else if (_motorR > 0) motorTargetDirR = 1;

        //cap the requested RPM to the MAX value
        if (_motorL > MAX_RPM_L) _motorL = MAX_RPM_L;
        if (_motorR > MAX_RPM_R) _motorR = MAX_RPM_R;

        motorTargetRPMR = abs((double)_motorR);
        motorTargetRPML = abs((double)_motorL);

    }

    // ideally called before PID update, sets the motor's RPM equivelent PWM value with the correct target rotation direction
    void updateMotorSpeed(){
        //apply the requested direction
        // motorPWMR *= motorTargetDirR;
        // motorPWML *= motorTargetDirL;
        //set the motor speed
        motorL.setSpeed((int16_t)motorPWML * motorTargetDirL);
        motorR.setSpeed((int16_t)motorPWMR * motorTargetDirR);
    }

    void updatePID(){
        // Perform PID calc on motors
        if(leftMotorPID.Compute()){
            // Serial.print(motorCurrentRPML);  
            // Serial.print(", ");  
            // Serial.print(motorTargetRPML);  
            // Serial.print(", ");  
            // Serial.print(motorPWML);  
            // Serial.println();  
            motorCurrentRPML = 0;
        }
        if(rightMotorPID.Compute()){
            // Serial.print(motorCurrentRPMR);  
            // Serial.print(", ");  
            // Serial.print(motorTargetRPMR);  
            // Serial.print(", ");  
            // Serial.print(motorPWMR);  
            // Serial.println();  
            motorCurrentRPMR = 0;
        }
        //delay(10);
    }

    
    void tunePID(float _kp, float _ki, float _kd){
        kd = _kd;
        ki = _ki;
        kd = _kd;
        
        leftMotorPID.SetTunings(kd, ki, kd);
        rightMotorPID.SetTunings(kd, ki, kd);
    }
}
