#pragma once
#ifndef _FRESH_HPP_
#define _FRESH_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"

namespace localization{
    extern pros::Distance left_dist;
    extern pros::IMU imu;
    // Odom system sensors
    extern lemlib::OdomSensors sensors; // inertial sensor
    enum Axis {x, neg_x, y, neg_y};
    enum Sensor {N = 1, S = 2, E = 3, W = 4};

    struct point {float x; float y; float angle;};

    struct distSensor {pros::Distance sensor; float Xoffset; float Yoffset; float Angoffset; float calibrate;};
    struct dsr {
        distSensor North;
        distSensor South;
        distSensor East;
        distSensor West;
        pros::IMU angle;
    };

    extern dsr DSR;


    void updatePos(distSensor sensor);
    void new_pos(enum Sensor sensor);
    
    
}

#endif