#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/pneumatics.hpp"
#include "autons.hpp"

lemlib::Pose pose = drive::chassis.getPose();

void basic_blue(){
    pros::Task odom_debug2(drive::odom_debug2);
    // Start Centered
    drive::chassis.setPose(-63.5, 0, 90);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    // Toggle
    pneumatics::toggle(extend);
    drive::chassis.moveToPoint(-55, 0, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, false);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.moveToPoint(-55, 0, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, false);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    // Goal
    drive::chassis.moveToPoint(-50, 0, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.turnToHeading(90, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.moveToPoint(-48, 16, 1000, {.forwards = true}, false);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    //pros::delay(1000); 
    pneumatics::claw.retract();
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    // // Cup/Pin
    drive::chassis.moveToPoint(-48, 0, 1000, {.forwards = false}, true);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.turnToHeading(45, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    // drive::chassis.moveToPoint(-33.5, 15.5, 1000); 
    //drive::chassis.moveToPoint(-33.25, 15.25, 1000, {.forwards = true}, false); 
    drive::chassis.moveToPoint(-33, 15, 1000, {.forwards = true}, false); 
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    //pneumatics::claw.retract();
    pneumatics::claw.extend();
    pros::delay(500); 

    // Back to goal
    drive::chassis.moveToPoint(-50, 0, 1000, {.forwards = false}, true);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.turnToHeading(90, 1000);
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    drive::chassis.moveToPoint(-50, 16, 1000); 
    pose = drive::chassis.getPose();
    printf("x: %f | y: %f | theta: %f\n", pose.x, pose.y, pose.theta);
    pneumatics::claw.retract();

    // drive::chassis.moveToPose(-27, 6, 135, false);
    // drive::chassis.moveToPose(-43, 22, -45, false);  
   
}

// void left_standard(){
// //     drive::chassis.setPose(-56, 11, -90);
// //     // Intake 3 blocks of quadrant
// //     intake::intake_hold();
// //     drive::chassis.moveToPose(-24, 24, -90, 1000, {.lead = 0.3}, false);
// //     // Line to matchloader
// //     drive::chassis.moveToPose(-48, 48, -90, 1000, {.forwards = false, .lead = 0.3}, false);
// //     drive::chassis.turnToHeading(-270, 750);
// //     // Matchload
// //     pneumatics::matchloader.extend();
// //     drive::chassis.moveToPoint(-75, 48, false);
// //     pros::delay(2000);
// //     drive::chassis.moveToPoint(-20, 48, 1000, {.forwards = false}, false);
// //     intake::in_out_take.move_voltage(0);
// //     intake::in_out_take.move_voltage(12000);
// // }