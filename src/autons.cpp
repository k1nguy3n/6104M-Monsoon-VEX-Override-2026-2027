#include "autons.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/localization.hpp"
#include "subsystems/intake.hpp"

void left_auton(){



}

void right_auton(){
    drive::chassis.setPose(0, -58, 90);
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
    // Pin 2
    drive::chassis.moveToPoint(-10, -48, 1000, {.forwards = false}, 1000);
    drive::chassis.turnToPoint(-24, -24, 1000);
    drive::chassis.moveToPoint(-24, -24, 1000, {.forwards = false, .maxSpeed = 50}, 1000);

    //
    intake::score_macro();




}






