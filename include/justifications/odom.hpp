#ifndef _ODOM_HPP_
#define _ODOM_HPP_

#include "api.h"
#include "main.h"

namespace odom{
    float x_odom();
    float y_odom();
    extern pros::Rotation x_sensor;
    extern pros::Rotation y_sensor;
    extern pros::Imu imu;

}

#endif