#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

// Miscellaneous configuration values
const bool RECV_IMU_CAL_VIA_SERIAL = true;

// Robot's communication configuration
#define CONNECTION_TIMEOUT 5000 // Connection check timeout length (Default: 5000 milliseconds)
#define CMD_ARG_LEN 14  // Max Number of command arguments (including command type/char)
#define ARG_LEN_MAX 16 // Max length of the CMD argument received

// Robot's IMU Calibration#

/// @brief Defined values for setting the program to wait and receive the IMU's calibration data via serial at the beginning of boot/setup
#define IMU_CAL_VIA_SERIAL false
#if (IMU_CAL_VIA_SERIAL)
    static bool cal_got = false;    
#endif

/// @brief Robot's IMU Calibration data for dealing with the hard iron interference on the magnetometer 
extern float IMU_CAL_MAG_HARD_IRON[3];

// extern void setIMU_CAL_MAG_HARD_IRON(float _values[3]);

/// @brief Robot's IMU Calibration data for dealing with the soft iron interference on the magnetometer 
extern float IMU_CAL_MAG_SOFT_IRON[9];

// extern void setIMU_CAL_MAG_SOFT_IRON(float _values[9]);

/// @brief Robot's IMU Calibrated Magnetic field value for the magnetometer 
extern float IMU_CAL_MAG_FIELD;

// extern void setIMU_CAL_MAG_FIELD(float _value);

// Robot's IMU configuration

// Robot's Motor configuration
/* CONNECTIONS:
 *
 * ESP32 D34 - Motor Driver PWM 1A Input
 * ESP32 D35 - Motor Driver PWM 1B Input
 * ESP32 D32 - Motor Driver PWM 2A Input
 * ESP32 D33  - Motor Driver PWM 2B Input
 * ESP32 GND - Motor Driver GND
 */

#define MOTOR_1A 32 // ORANGE wire, right motor
#define MOTOR_1B 33 // YELLOW wire, right motor
#define MOTOR_2A 26 // PURPLE wire, left motor
#define MOTOR_2B 25 // BLUE wire, left motor

#define MOTOR_ENCODER_1A 13 //right encoder
#define MOTOR_ENCODER_1B 12 //right encoder
#define MOTOR_ENCODER_2A 27 //left encoder
#define MOTOR_ENCODER_2B 14 //left encoder

#define PID_SAMPLE_RATE 33 // ~33ms = 30Hz. https://www.unitjuggler.com/convert-frequency-from-Hz-to-ms(p).html
// These let us convert ticks-to-RPM
#define GEARING     45
#define ENCODERMULT 14

#define MIN_PWM_L 0 // The Minimum activation value for rotating the motors
#define MIN_PWM_R 0 // The Minimum activation value for rotating the motors
#define MAX_PWM_L 255 // The Max PWM value for rotating the motors
#define MAX_PWM_R 255 // The Max PWM value for rotating the motors
#define MAX_RPM_L 150 // Would be best to cap this as it can spike 
#define MAX_RPM_R 150 // Would be best to cap this as it can spike

// ~266 counts per revolution (motor), ~1081 per full track rotation
#define CPR 575 //encoder counts per revolution (of motor) 
//#define CPT 1081 //encoder counts per track length (one full track rotation ~200mm +/-2mm) 
//#define TRACK_LENGTH 200.0f //track length in millimeter (one full track rotation ~200mm +/-2mm) 
#define CPM 4 //encoder counts per millimeter (real Value: ~4.167)


// Config values for rotation parameters
#define ROBOT_ROTATE_ACCEPTANCE_ERROR 1

#endif