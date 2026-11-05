#include "autons.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/localization.hpp"
#include "subsystems/intake.hpp"

void left_auton(){



}

void right_auton(){
    drive::chassis.setPose(0, -58, 0);
    // Toggle
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -58, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -58, 1000, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(0, -48, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-18, -48, 1000);
    intake::score_macro();
    // Move to Pin 2
    drive::chassis.moveToPoint(-10, -48, 1000, {.forwards = false}, 1000);
    drive::chassis.turnToPoint(-24, -24, 1000);
    drive::chassis.moveToPoint(-24, -24, 1000, {.forwards = false, .maxSpeed = 50}, 1000);
    //
    drive::chassis.turnToPoint(-18, -48, 1000);
    drive::chassis.moveToPoint(-18, -48, 1000);
    intake::score_macro();
    //



}

void skills_auton(){
    drive::chassis.setPose(-58, 0, 90);
    // Toggle
    // wrist.move_absolute(340, 127);
     // Toggle
    drive::chassis.moveToPoint(-50, 0, 1000);
    drive::chassis.moveToPoint(-58, 0, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(-50, 0, 1000);
    drive::chassis.moveToPoint(-58, 0, 1000, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(-47, 0, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-47, -16, 1000);

   // outake the claw (no score macro)

    // Move to Pin 2
    drive::chassis.moveToPoint(-40, 0, 1000, {.forwards = false}, 1000);

    //raise the wrist to 600 degrees

    drive::chassis.turnToHeading(135, 500);
    drive::chassis.moveToPoint(-28, -16, 1000, {.forwards = true, .earlyExitRange = 4}, false);
    drive::chassis.moveToPoint(-24, -24, 1000, {.forwards = false, .maxSpeed = 50}, 1000);
    //

    //wrist.move_absolute(100, 127);
    //pros::delay(200);
    //wrist.move_absolute(340, 127);
    //raise the cascade for 400 ms 

    drive::chassis.moveToPoint(-24, -24, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-39, -24, 1000);

    //spin claw opposite driection

    drive::chassis.moveToPoint(-24, -24, 1000, {.forwards = false}, 1000);

    //lowerr the cascade for 400 ms
    // wrist.move_absolute(600, 127);

    drive::chassis.turnToHeading(225, 500);
    drive::chassis.moveToPoint(-44, -39, 1000, {.forwards = true, .earlyExitRange = 5}, false);
    drive::chassis.moveToPoint(-44, -39, 1000, {.forwards = false, .maxSpeed = 50}, 1000);

    //wrist.move_absolute(100, 127);
    //pros::delay(200);
    //wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms 

    drive::chassis.moveToPoint(-48, -48, 1000);
    drive::chassis.turnToHeading(0, 500);
    drive::chassis.moveToPoint(-48, -32, 1000);

    //spin claw opposite direction

    drive::chassis.moveToPoint(-48, -62, 1000, {.forwards = false}, 1000);

    //lowerr the cascade for 600 ms
    // wrist.move_absolute(0, 127);

    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-60, -62, 1000);

    //intake 400ms 
    // wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms

    drive::chassis.moveToPoint(-48, -62, 1000, {.forwards = false}, 1000);
    drive::chassis.turnToHeading(90, 500);
    drive::chassis.moveToPoint(-48, -32, 1000);

    //USE THE SCORE MACRO HERE 

    drive::chassis.moveToPoint(-48, -62, 1000, {.forwards = false}, 1000);

    //lowerr the cascade for 600 ms
    // wrist.move_absolute(0, 127);

    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-60, -62, 1000);

    //intake 400ms 

    drive::chassis.moveToPoint(-53, -62, 1000, {.forwards = false}, 1000);
    drive::chassis.turnToHeading(45, 500);
    drive::chassis.moveToPose(-17, -13, 45, 1000);

    // wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms

    drive::chassis.moveToPose(-6, -6, 45, 1000);
    //spin claw opposite direction

}




