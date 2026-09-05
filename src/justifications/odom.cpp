// Necessary inclusions for program to function properly
#include "justifications/odom.hpp"
#include "api.h"
#include <cmath>
// Odometry namespace for organization
namespace odom {
    // Define and initalize necessary sensors
    pros::Rotation x_sensor (1);
    pros::Rotation y_sensor (2);
    pros::Imu imu (3);
    // Function to find position on x axis
    float x_odom() {
        while (true){
            // Reset sensors to ensure accurate readings from sensors
            x_sensor.reset_position();
            imu.reset();
            // Initalize necessary variables (all on x axis)
            float final_pos; 
            float x_distance;
            float wheel_dist_from_center;
            // Wheel sizing
            float wheel_radius = 1;
            // Distance the rotation sensor reads
            x_distance = x_sensor.get_angle()*wheel_radius;
            // Final location on the x axis using derived equation
            final_pos = (x_distance/imu.get_heading()-wheel_dist_from_center)*sin(imu.get_heading()/2);
            return final_pos;
        }
    }
    // Function to find position on y axis
    float y_odom() {
        while (true){
            // Reset sensors to ensure accurate readings from sensors
            y_sensor.reset_position();
            imu.reset();
            // Initalize necessary variables (all on y axis)
            float final_pos;
            float y_distance;
            float wheel_dist_from_center;
            // Wheel sizing
            float wheel_radius = 1;
            // Distance the rotation sensor reads
            y_distance = y_sensor.get_angle()*wheel_radius;
            // Final location on the x axis using derived equation
            final_pos = (y_distance/imu.get_heading()-wheel_dist_from_center)*sin(imu.get_heading()/2);
            return final_pos;
        }
    }
}

