#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"

namespace drive{
    extern pros::MotorGroup left_drive; // Left drive motors
    extern pros::MotorGroup right_drive; // Right drive motors
    // imu
    //extern pros::Imu imu;

    extern lemlib::Drivetrain drivetrain; // horizontal drift is 2 (for now)
    // lateral PID controller
    extern lemlib::ControllerSettings lateral_controller; // maximum acceleration (slew)
    // angular PID controller
    extern lemlib::ControllerSettings angular_controller; // maximum acceleration (slew)
    // create the chassis
    extern lemlib::Chassis chassis; // odometry sensors
    void control(void);
    void init(void);
    void odom_debug(void);

}

#endif