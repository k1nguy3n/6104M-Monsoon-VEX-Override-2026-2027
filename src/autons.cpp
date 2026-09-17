#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/pneumatics.hpp"
#include "autons.hpp"
 
void basic(){
    // Start Centered
    drive::chassis.setPose(-63.5, 0, 90);
    // Toggle
    drive::chassis.moveToPoint(-55, 0, 1000);
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, 1000);
    drive::chassis.moveToPoint(-55, 0, false);
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, 1000);
    drive::chassis.moveToPoint(-48, 0, 1000);
    // Goal
    drive::chassis.turnToHeading(90, 1000);
    // drive::chassis.moveToPoint(-48, 20, 1000); 


    // drive::chassis.moveToPoint(-48, 20, 2000); 

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