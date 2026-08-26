// Necesary inclusions for funtioning program
#include "justifications/pid.hpp"
#include "justifications/odom.hpp"
#include <cmath>
#include "subsystems/drive.hpp"
// PID Namespace for organization
namespace pid {
    point current_loc = {x_odom(), y_odom(), imu.get_heading};
    // make an equation for error and then use a while error != 0?
    // PID constants (using struct)
    PIDconsts lateral;
    PIDconsts angular;
    // Initialize mathematical
    float error;
    float prev_error = 0;
    float integral_error = 0;
    float derivative;

    float percentage;
    float voltage = percentage * 120;
    float early_exit;
    
    enum axis axis;

    float DistBtwnPts(point p1, point p2) {
        float deltaX = p1.x - p2.x;
        float deltaY = p1.y - p2.y;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // PID for forward/back movement, need to figure out how to specify axis
    void lateralPID(point target){
        float error = DistBtwnPts(current_loc, target);
        // create early exit timeout range?
        while (error > error*early_exit || error < -error*early_exit){
            integral_error += error; // Add onto integral
            derivative = error-prev_error; // calculate derivative
            prev_error = error; // Update previous error
            // Add a delay to conserve resources?
            percentage = lateral.kP*error + lateral.kI*integral_error + lateral.kP*derivative;
            drive::left_drive.move_voltage(voltage);
            drive::right_drive.move_voltage(voltage);
        }
    }
    // PID for turns
    void angularPID(point target){
        error = target.theta - current_loc.theta;
        // Figure out the shortest path to an angle?
        enum direction direction = clockwise;
        if (error > 180){
            direction == counterclockwise;
        }
        // create early exit timeout range?
        while (error > error*early_exit || error < -error*early_exit){
            integral_error += error; // Add onto integral
            derivative = error-prev_error; // calculate derivative
            prev_error = error; // Update previous error
            percentage = lateral.kP*error + lateral.kI*integral_error + lateral.kP*derivative;
            if (direction == clockwise){
                drive::left_drive.move_voltage(voltage);
                drive::right_drive.move_voltage(-voltage);
            }
            else if (direction == counterclockwise){
                drive::left_drive.move_voltage(-voltage);
                drive::right_drive.move_voltage(voltage);
            }
        }
    }
}