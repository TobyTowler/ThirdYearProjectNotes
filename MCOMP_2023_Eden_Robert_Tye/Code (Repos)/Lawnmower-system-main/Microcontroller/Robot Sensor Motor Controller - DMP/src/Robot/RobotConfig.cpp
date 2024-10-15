#include "RobotConfig.h"

/// @brief Robot's IMU Calibration data for dealing with the hard iron interference on the magnetometer 
float IMU_CAL_MAG_HARD_IRON[3]{
    -1, -2,  3
};

// void setIMU_CAL_MAG_HARD_IRON(float _values[3]){
//     IMU_CAL_MAG_HARD_IRON[0] = _values[0];
//     IMU_CAL_MAG_HARD_IRON[1] = _values[1];
//     IMU_CAL_MAG_HARD_IRON[2] = _values[2];
// }

/// @brief Robot's IMU Calibration data for dealing with the soft iron interference on the magnetometer 
float IMU_CAL_MAG_SOFT_IRON[9]{
    -1,  2,  3,
    -4,  5, -6,
    -7,  8,  9
};

// void setIMU_CAL_MAG_SOFT_IRON(float _values[9]){
//     IMU_CAL_MAG_SOFT_IRON[0] = _values[0];
//     IMU_CAL_MAG_SOFT_IRON[1] = _values[1];
//     IMU_CAL_MAG_SOFT_IRON[2] = _values[2];
//     IMU_CAL_MAG_SOFT_IRON[3] = _values[3];
//     IMU_CAL_MAG_SOFT_IRON[4] = _values[4];
//     IMU_CAL_MAG_SOFT_IRON[5] = _values[5];
//     IMU_CAL_MAG_SOFT_IRON[6] = _values[6];
//     IMU_CAL_MAG_SOFT_IRON[7] = _values[7];
//     IMU_CAL_MAG_SOFT_IRON[8] = _values[8];
// }
/// @brief Robot's IMU Calibrated Magnetic field value for the magnetometer 
float IMU_CAL_MAG_FIELD = 0.0f;

// void setIMU_CAL_MAG_FIELD(float _value){
//     IMU_CAL_MAG_FIELD = _value;
// }