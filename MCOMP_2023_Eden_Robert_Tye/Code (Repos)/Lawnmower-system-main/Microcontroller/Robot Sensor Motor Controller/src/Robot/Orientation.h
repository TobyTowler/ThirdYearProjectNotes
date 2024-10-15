#ifndef ORIENTATION_H
#define ORIENTATION_H

struct Quaternion {
    float w; // Q0
    float x; // Q1
    float y; // Q2
    float z; // Q3
};

struct EulerAngles {
    float roll;
    float pitch;
    float heading; // "heading" is similar/equal to "yaw". The angle from Magnetic North
};

#endif