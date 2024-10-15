# Robot Microcontroller Software 

## Overview
TODO: Overview of the program

## Robot (Serial) Commands
The robot action are controller by a set of commands that are recieved via serial from the robot's Raspberry Pi.
### Command List:
| CMD | CMD Description | CMD ID Character | CMD Parameters/Arguments | Example |
|---|---|---|---|---|
| Clear | Resets/clear a range of the robot's tracking related variables | **c** | None | `c` |
| Set Motor Speed (RPM) | Set L and R motors to drive at a target RPM speed (**CURRENTLY BROKEN**) | **m** | - arg1: Left Motor RPM<br>- arg2: Right Motor RPM | `m <arg1> <arg2>` |
| Move Distance | Move a specific amount of distance (mm) at a set RPM | **d** | - arg1: speed (RPM)<br>- arg2: distance to travel | `d <arg1> <arg2>` |
| Rotate (Amount) | Rotate on the spot by specific amount (in degrees) | **r** | - arg1: speed (RPM)<br>- arg2: rotation amount (in degrees) | `r <arg1> <arg2>` |
| Rotate (Bearing) | Rotate on the spot to a specific bearing | **b** | - arg1: speed (RPM)<br>- arg2: target bearing (degrees from North) | `b <arg1> <arg2>` |
| Robot Orientation | Request the fused IMU sensor data that give the orientation of the robot's `heading`, `pitch`, and `roll` (as Euler angles) | **i** | None | `i` |
| EKF IMU Data | Request IMU sensor data needed for the EKF with the GPS | **e** | None | `e` |
| Halt | Halts the entire robot's actions (E.g. Stop moving) | **h** | None | `h` |
| Send Calibration | Send the IMU calibration data to the robot via serial at startup | **@** | - arg1: Hard Iron (Val 1)<br>- arg2: Hard Iron (Val 2)<br>- arg3: Hard Iron (Val 3)<br>- arg4: Soft Iron (Val 1)<br>- arg5: Soft Iron (Val 2)<br>- arg6: Soft Iron (Val 3)<br>- arg7: Soft Iron (Val 4)<br>- arg8: Soft Iron (Val 5)<br>- arg9: Soft Iron (Val 6)<br>- arg10: Soft Iron (Val 7)<br>- arg11: Soft Iron (Val 8)<br>- arg12: Soft Iron (Val 9)<br>- arg13: Magnetic Field | `@ <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7> <arg8> <arg9> <arg10> <arg11> <arg12> <arg13> <arg14>` |
| Debug Robot Information | Print various information about the current state of the robot variables | **s** | None | `s` |
<!-- |||||| -->

## IMU Calibration
TODO: Introduce Calibration
(see [IMU Calibration](../ICM-20948%20Calibration/README.md))

## Config Options (RobotConfig.h)
TODO: Explain Options