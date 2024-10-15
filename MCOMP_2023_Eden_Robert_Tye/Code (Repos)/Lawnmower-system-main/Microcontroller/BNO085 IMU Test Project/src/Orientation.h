#ifndef ORIENTATION_H
#define ORIENTATION_H

struct Quaternion {
    double w; // Q0
    double x; // Q1
    double y; // Q2
    double z; // Q3
};

struct EulerAngles {
    double roll;
    double pitch;
    double yaw;
};

#endif