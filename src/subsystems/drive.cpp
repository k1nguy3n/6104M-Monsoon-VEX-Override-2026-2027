#include "subsystems/drive.hpp"
#include <cmath>
#include "subsystems/localization.hpp"
#include "api.h"
#include "main.h"

// Drive namepsace for 
namespace drive{
    //pros::MotorGroup full_drive ({14, 9, -3, -19, -20, 7}); 
    // Left drive motors with appropiate signs for directions
    pros::MotorGroup left_drive ({-17, -12, -16});
    // Right drive motors with appropiate signs for directions
    pros::MotorGroup right_drive ({15, 18, 13}); 
    // Drivetrain components
    lemlib::Drivetrain drivetrain(&left_drive, // left motor group
                                &right_drive, // right motor group
                                11.0, // 10.8 inch track width
                                lemlib::Omniwheel::NEW_275, // New 3.25" omnis in drive
                                450, // Drive rpm is 450
                                8); // horizontal drift is 2 (for now)
    // Lateral PID controller constants
    // Odom system sensors (put in new file later?)
    pros::Imu imu(11);
    pros::Rotation vertical_sensor(-20);
    lemlib::TrackingWheel vert_tw(&vertical_sensor, lemlib::Omniwheel::NEW_2, -1);
    // Group odom components
    lemlib::OdomSensors sensors(&vert_tw, // vertical tracking wheels
                            nullptr,    // set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horiz tracking wheel 2, nullptr (don't have 2nd one)
                            &imu); // inertial sensor
    void odom_debug() {
        while (true) {
            lemlib::Pose pose = drive::chassis.getPose();
            printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
            printf("theta: %f\n", imu.get_heading());
            pros::delay(200);
        }
    }
    lemlib::ControllerSettings lateral_controller(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              127); // maximum acceleration (slew)
    // Angular PID controller constants

    // 4.5 0 9.5

    // 8 0 17.5
    // 8.5, 0, 26
    // 9.55 26.5
    // Ceiling = ~10
    lemlib::ControllerSettings angular_controller(2.5, // proportional gain (kP) 19.7 15.09 4.        when you did this you had 5.   when i did this i got 3.25
                                                0, // integral gain (kI)
                                                20, // derivative gain (kD) 10  11.5     13 || INCREASE     when you did this you had 7.75.     when i did this i got 18
                                                0, // anti windup
                                                1, // small error range, in inches
                                                200, // small error range timeout, in milliseconds
                                                3, // large error range, in inches
                                                500, // large error range timeout, in milliseconds
                                                127); // maximum acceleration (slew)
                                            // 0,0,0,0,0,0);
    // create the chassis
    lemlib::Chassis chassis(drivetrain, // Drivetrain settings
                        lateral_controller, // Lateral PID settings
                        angular_controller, // Angular PID settings
                        sensors); // Odometry sensors
    // Troubleshooting function that shows robot position in terminal
    // void odom_debug() {
    //     while (true) {
    //         lemlib::Pose pose = drive::chassis.getPose();
    //         printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    //         printf("theta: %f\n",localization::imu.get_heading());
    //         pros::delay(50);
    //     }
    // }

    // void odom_debug2() {
    //     while (true) {
    //         lemlib::Pose pose = drive::chassis.getPose();
    //         pros::delay(1000);
    //     }
    // }

    void torque_debug(){
        while (true){
            // std::cout << "Motor Torques: -17" << pros::Motor(-17).get_torque();
            // std::cout << "Motor Torques: -12" << pros::Motor(-12).get_torque();
            // std::cout << "Motor Torques: -16" << pros::Motor(-16).get_torque();
            // std::cout << "Motor Torques: 15" << pros::Motor(15).get_torque();
            // std::cout << "Motor Torques: 18" << pros::Motor(18).get_torque();
            // std::cout << "Motor Torques: 13" << pros::Motor(13).get_torque();
            printf("Motor Torques: -17: %f\n", pros::Motor(-17).get_torque());
            printf("Motor Torques: -12: %f\n", pros::Motor(-12).get_torque());
            printf("Motor Torques: -16: %f\n", pros::Motor(-16).get_torque());
            printf("Motor Torques: 15: %f\n", pros::Motor(15).get_torque());
            printf("Motor Torques: 18: %f\n", pros::Motor(18).get_torque());
            printf("Motor Torques: 13: %f\n", pros::Motor(13).get_torque());
        }
    }

    // Define controller
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    // Initialize drivetrain with a 3 second delay so it remins undisturbed
    void init(){
        chassis.calibrate();
        // imu.reset();
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