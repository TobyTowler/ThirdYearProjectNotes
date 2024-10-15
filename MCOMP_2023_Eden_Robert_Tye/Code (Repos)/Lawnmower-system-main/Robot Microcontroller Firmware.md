# Robot's Microcontroller Firmware

## Overview

Within the Robot's architecture/design we have a microcontroller layer that handles a range of lower level tasks and sensor interfaces.

## Page Navigation

- [Robot's Microcontroller Firmware](#robots-microcontroller-firmware)
  - [Overview](#overview)
  - [Page Navigation](#page-navigation)
  - [Robot (Serial) Commands](#robot-serial-commands)
    - [Command List:](#command-list)
  - [IMUs and Calibration](#imus-and-calibration)
  - [Config Options (RobotConfig.h)](#config-options-robotconfigh)


## Robot (Serial) Commands

The robot action are controller by a set of commands that are received via (USB) serial from the robot's Raspberry Pi.

### Command List:

| CMD | CMD Description | CMD ID Character | CMD Parameters/Arguments | Example |
|---|---|---|---|---|
| Clear | Resets/clear a range of the robot's tracking related variables | **c** | None | `c` |
| Set Motor Speed (RPM) | Set L and R motors to drive at a target RPM speed | **m** | - arg1: Left Motor RPM<br>- arg2: Right Motor RPM | `m <arg1> <arg2>` |
| Move Distance | Move a specific amount of distance (mm) at a set RPM | **d** | - arg1: speed (RPM)<br>- arg2: distance to travel | `d <arg1> <arg2>` |
| Rotate (Amount) | Rotate on the spot by specific amount (in degrees) | **r** | - arg1: speed (RPM)<br>- arg2: rotation amount (in degrees) | `r <arg1> <arg2>` |
| Rotate (Bearing) | Rotate on the spot to a specific bearing | **b** | - arg1: speed (RPM)<br>- arg2: target bearing (degrees from North) | `b <arg1> <arg2>` |
| Robot Orientation | Request the fused IMU sensor data that give the orientation of the robot's `heading`, `pitch`, and `roll` (as Euler angles) | **i** | None | `i` |
| EKF IMU Data | Request IMU sensor data needed for the EKF with the GPS (with the exception of the linear acceleration and instead provided the only the acceleration vector of the robot) | **e** | None | `e` |
| Halt | Halts the entire robot's actions (E.g. Stop moving) | **h** | None | `h` |
| Send Calibration | Send the IMU calibration data to the robot via serial at startup | **@** | - arg1: Hard Iron (Val 1)<br>- arg2: Hard Iron (Val 2)<br>- arg3: Hard Iron (Val 3)<br>- arg4: Soft Iron (Val 1)<br>- arg5: Soft Iron (Val 2)<br>- arg6: Soft Iron (Val 3)<br>- arg7: Soft Iron (Val 4)<br>- arg8: Soft Iron (Val 5)<br>- arg9: Soft Iron (Val 6)<br>- arg10: Soft Iron (Val 7)<br>- arg11: Soft Iron (Val 8)<br>- arg12: Soft Iron (Val 9)<br>- arg13: Magnetic Field | `@ <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7> <arg8> <arg9> <arg10> <arg11> <arg12> <arg13> <arg14>` |
| Debug Robot Information | Print various information about the current state of the robot variables | **s** | None | `s` |
<!-- |||||| -->

## IMUs and Calibration

In order to for the robot to accurately orientate it's self it has 2 IMU's installed which are used to obtain the robot's present orientation and use it for a range of applications during it's operation.

One IMU (an ICM-20948) is connected and used by the microcontroller for aiding the robot with a orientation reliant tasks/actions.
The other IMU (a BNO085) is connected and used by the Raspberry Pi for localisation task which require a more accessible and frequent stream of larger quantities of orientation data. This is connected and accessed within the ROS Network of the robot using [this](https://github.com/UEA-MComp/BNO085-ROS2-Node) interface node.

Both of these IMU's have an auto-calibration feature (as part of their internal fusion features) which allows the robot to be calibrated more easily and quickly instead of having to manually perform the calibration process, as it quite often that we would need to re-calibrate the robot between different operating environment or operating the robot at different times.

You can see more in the process on the [Calibration page](Calibration.md) where it details the calibration procedure required.

## Config Options (RobotConfig.h)

**TODO:** Explain Options

[RobotConfig.h](Microcontroller/Robot%20Sensor%20Motor%20Controller/src/Robot/RobotConfig.h)
