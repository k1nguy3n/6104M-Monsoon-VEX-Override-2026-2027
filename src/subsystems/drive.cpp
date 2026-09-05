#include "main.h"
#include "subsystems/drive.hpp"
#include <cmath>
#include "subsystems/localization.hpp"
// Drive namepsace for 
namespace drive{
    
    pros::MotorGroup full_drive ({14, 9, -3, -19, -20, 7}); 
    // Left drive motors with appropiate signs for directions
    pros::MotorGroup left_drive ({14, 9, -3});
    // Right drive motors with appropiate signs for directions
    pros::MotorGroup right_drive ({-19, -20, 7}); 
    // Drivetrain components
    lemlib::Drivetrain drivetrain(&left_drive, // left motor group
                                &right_drive, // right motor group
                                10.8, // 10.8 inch track width
                                lemlib::Omniwheel::NEW_325, // New 3.25" omnis in drive
                                360, // Drive rpm is 360
                                2); // horizontal drift is 2 (for now)
    // Lateral PID controller constants
    lemlib::ControllerSettings lateral_controller(0, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20); // maximum acceleration (slew)
    // Angular PID controller constants
    lemlib::ControllerSettings angular_controller(19.7, // proportional gain (kP) 19.7
                                                0, // integral gain (kI)
                                                11.5, // derivative gain (kD) 10      
                                                3, // anti windup
                                                1, // small error range, in inches
                                                100, // small error range timeout, in milliseconds
                                                3, // large error range, in inches
                                                500, // large error range timeout, in milliseconds
                                                0); // maximum acceleration (slew)
                                            // 0,0,0,0,0,0);
    // create the chassis
    lemlib::Chassis chassis(drivetrain, // Drivetrain settings
                        lateral_controller, // Lateral PID settings
                        angular_controller, // Angular PID settings
                        localization::sensors); // Odometry sensors
    // Troubleshooting function that shows robot position in terminal
    void odom_debug() {
        while (true) {
            lemlib::Pose pose = drive::chassis.getPose();
            printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
            pros::delay(100);
        }
    }
    // Define controller
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    // Initialize drivetrain with a 3 second delay so it remins undisturbed
    void init(){
        chassis.calibrate();
        localization::imu.reset();
        pros::delay(3000);
    }
    void control() {
    // loop forever
        while (true) {
            drive::chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
            // Left y + Right x Positions
            int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            // Moving robot
            chassis.arcade(leftY, // Throttle
                       rightX, // Steer
                       true, // Enable drive curves
                       0.75); // Prioritize steering
            // Delay to save resources
            pros::delay(25);
        }
    }
}