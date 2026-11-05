#include "autons.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/localization.hpp"
#include "subsystems/intake.hpp"

void left_auton(){



}

void right_auton(){
    drive::chassis.setPose(0, -58, 90);
    intake::claw.move_voltage(-12000);
    // Toggle
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -58, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -58, 1000, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(0, -48, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-18, -48, 1000);
    intake::score_macro();
    // Move to Pin 2
    drive::chassis.moveToPoint(-10, -48, 1000, {.forwards = false}, 1000);
    drive::chassis.turnToPoint(-24, -24, 1000);
    drive::chassis.moveToPoint(-24, -24, 1000, {.forwards = false, .maxSpeed = 50}, 1000);
    // Score on goal
    drive::chassis.turnToPoint(-20, -48, 1000);
    drive::chassis.moveToPoint(-20, -48, 1000);
    intake::score_macro();
    // Pin 3
    drive::chassis.moveToPoint(-20, -40, 1000);
    drive::chassis.turnToPoint(-48, -48, 1000);
    drive::chassis.moveToPoint(-48, -48, 1000, {.forwards = false, .maxSpeed = 50}, 1000);
    // Score on goal
    drive::chassis.turnToPoint(-20, -48, 1000);
    drive::chassis.moveToPoint(-20, -48, 1000);
    intake::score_macro();

}






