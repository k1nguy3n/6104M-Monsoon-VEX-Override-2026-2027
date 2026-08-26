#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/pneumatics.hpp"
#include "autons.hpp"
 
void basic(){
    drive::chassis.setPose(-70, 0, 90);
    // Toggle
    drive::chassis.moveToPoint(-60, 0, false);
    drive::chassis.moveToPoint(-70, 0, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(-60, 0, false);
    drive::chassis.moveToPoint(-70, 0, 1000, {.forwards = false}, false);
    // Goal
    drive::chassis.moveToPoint(-48, 0, false); 
    drive::chassis.turnToHeading(180, false);
    drive::chassis.moveToPoint(-48, -24, false);    
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