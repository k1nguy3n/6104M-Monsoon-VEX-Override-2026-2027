#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/pneumatics.hpp"
#include "autons.hpp"
#include "subsystems/localization.hpp"
#include "lemlib/api.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	drive::init();
    intake::init();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */



void autonomous() {
    //pros::Task odom_debug(drive::odom_debug);
    // Test west sensor
    //localization::lazyPosN(localization::neg_x);
    //localization::lazyPosW(localization::neg_y);
    //intake::intake_hold();
    // set position to x:0, y:0, heading:0
    //drive::chassis.setPose(0, 0, 0);
	drive::chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    // Tuning
    //drive::chassis.turnToHeading(180, 10000);
	//drive::chassis.moveToPoint(0, 48, 10000);
    //drive::chassis.moveToPose(0, 48, 180, 10000);
    //drive::chassis.moveToPose(48, 48, 0, 3000, {.lead = 0.5});
    //drive::chassis.moveToPose(0, 48, 270, 10000);

    basic();
    // Standard Autons
    //right_standard();

    // Disrupt
    // left_disrupt();
    //right_disrupt();

   // Skills
    //bleh_skills();
    //super_basic();
    //forward();

    

    // drive::chassis.moveToPose(-42, 0, 90, 2000, {.forwards = false});

    // drive::chassis.moveToPoint(-40, 25, 2000);
    // drive::chassis.turnToHeading(-45, 1000);
    //drive::chassis.moveToPose(-41, 0, -90, 2000);
    
    
    //drive::chassis.moveToPose(-58, 24, 0, 2000); 
    
    
    //drive::chassis.moveToPose(-60, 20, -45, 2000);  
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    //drive::chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    pros::Task drive(drive::control, TASK_PRIORITY_DEFAULT + 4);
	pros::Task intake(intake::control, TASK_PRIORITY_DEFAULT + 3);
	pros::Task pneumatics(pneumatics::control, TASK_PRIORITY_DEFAULT + 2);
    // Defines controller
    // pros::Controller master (pros::E_CONTROLLER_MASTER);
    // drive::chassis.setPose(-48, 24, 270);
    // // Prints Initial Pose
    // auto pose = drive::chassis.getPose();
    // printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);

    // while (true){
    //     if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
    //         //When the button is pressed, it does the function
    //         localization::updatePos(localization::DSR.North);
    //         // Then gets the pose again
    //         pose = drive::chassis.getPose();
    //         // Then prints the dist sensor reading
    //         printf("Distance Sensor Reading: %f\n", (localization::DSR.North.calibrate * localization::DSR.North.sensor.get())/25.4);
    //         printf("Angle in Radians %f\n", pose.theta);
    //         // And the robot's position
    //         printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    //         //printf("Just X%f\n", pose.x);
    //         pros::delay(10);
    //     }
    // }
}