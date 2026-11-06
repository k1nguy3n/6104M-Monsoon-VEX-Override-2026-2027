#include "autons.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/localization.hpp"
#include "subsystems/intake.hpp"

void left_auton(){
    drive::chassis.setPose(-57, 0, 90);
    intake::claw.move_voltage(12000);
    intake::wrist.move_absolute(340, 127);
     // Toggle
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(-47.5, 0, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-47.5, -18.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);

    // Move to Pin 2
    drive::chassis.moveToPoint(-47.5, 0, 1000, {.forwards = false}, 1000);
    intake::claw.move_voltage(12000);
    //raise the wrist to 600 degrees
    intake::wrist.move_absolute(600, 127);
    // Pin 2 eaten yay
    drive::chassis.turnToHeading(135, 500);
    drive::chassis.moveToPoint(-29.5, -17, 1000, {.forwards = true, .earlyExitRange = 8}, false);
    drive::chassis.moveToPoint(-27.5, -22.25, 1000, {.forwards = true, .maxSpeed = 50}, 1000);
    //
    intake::wrist.move_absolute(-100, 127);
    pros::delay(700);
    intake::wrist.move_absolute(340, 127);

    //raise the cascade for 400 ms 
    // cascade_time(intake::raise, 400);
    intake::cascade.move_voltage(12000);
    pros::delay(600);
    intake::cascade.move_voltage(0);


    pros::delay(400);

    drive::chassis.moveToPoint(-24, -25, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-40, -25, 1000);

    // //spin claw opposite driection
    pros::delay(700);
    intake::claw.move_voltage(-12000);
    pros::delay(500);
    drive::chassis.moveToPoint(-24, -25, 1000);
    intake::cascade.move_voltage(-12000);
    intake::wrist.move_absolute(0, 127);


}







void right_auton(){
    drive::chassis.setPose(0, -58, 0);
    intake::claw.move_voltage(12000);
     intake::wrist.move_absolute(340, 127);
    // Toggle
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -61, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -61, 1000, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(0, -47.5, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-18, -47.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);
    // Move to Pin 2
    drive::chassis.moveToPoint(0, -47.5, 1000, {.forwards = false}, 1000);
    intake::claw.move_voltage(12000);
    //raise the wrist to 600 degrees
    intake::wrist.move_absolute(600, 127);
    // Pin 2 eaten yay
    drive::chassis.turnToHeading(315, 500);

    drive::chassis.moveToPoint(-17, -29.5, 1000, {.forwards = true, .earlyExitRange = 8}, false);
    drive::chassis.moveToPoint(-22.25, -27.5, 1000, {.forwards = true, .maxSpeed = 50}, 1000);
    // Score on goal
    intake::wrist.move_absolute(-100, 127);
    pros::delay(700);
    intake::wrist.move_absolute(340, 127);

    //raise the cascade for 400 ms 
    // cascade_time(intake::raise, 400);
    intake::cascade.move_voltage(12000);
    pros::delay(600);
    intake::cascade.move_voltage(0);


    pros::delay(400);

    drive::chassis.moveToPoint(-25, -24, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-25, -40, 1000);
    
    pros::delay(700);
    intake::claw.move_voltage(-12000);
    pros::delay(400);

    intake::cascade.move_voltage(12000);
    drive::chassis.moveToPoint(-25, -24, 1000);
    pros::delay(250);
    intake::cascade.move_voltage(0);
    intake::cascade.move_voltage(-12000);
    intake::wrist.move_absolute(0, 127);
   
}








void left_PRELOAD_ONLY_auton(){
    drive::chassis.setPose(-57, 0, 90);
    intake::claw.move_voltage(12000);
    intake::wrist.move_absolute(340, 127);
     // Toggle
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(-47.5, 0, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-47.5, -18.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);

    // Move to Pin 2
    drive::chassis.moveToPoint(-47.5, 0, 1000, {.forwards = false}, 1000);
    intake::wrist.move_absolute(0, 127);
    intake::claw.move_voltage(12000);
}







void right_PRELOAD_ONLY_auton(){
    drive::chassis.setPose(0, -58, 0);
    intake::claw.move_voltage(12000);
     intake::wrist.move_absolute(340, 127);
    // Toggle
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -61, 1000, {.forwards = false}, false);
    drive::chassis.moveToPoint(0, -50, 1000);
    drive::chassis.moveToPoint(0, -61, 1000, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(0, -47.5, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-18, -47.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);
    // Move to Pin 2
    drive::chassis.moveToPoint(0, -47.5, 1000, {.forwards = false}, 1000);
    intake::wrist.move_absolute(0, 127);
    intake::claw.move_voltage(12000);
}







void small_skills_auton(){
    drive::chassis.setPose(-57, 0, 90);
    intake::claw.move_voltage(12000);
    intake::wrist.move_absolute(340, 127);
     // Toggle
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(-47.5, 0, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-47.5, -18.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);

    // Move to Pin 2
    drive::chassis.moveToPoint(-47.5, 0, 1000, {.forwards = false}, 1000);
    intake::claw.move_voltage(12000);
    //raise the wrist to 600 degrees
    intake::wrist.move_absolute(600, 127);
    // Pin 2 eaten yay
    drive::chassis.turnToHeading(135, 500);
    drive::chassis.moveToPoint(-29.5, -17, 1000, {.forwards = true, .earlyExitRange = 8}, false);
    drive::chassis.moveToPoint(-27.5, -22.25, 1000, {.forwards = true, .maxSpeed = 50}, 1000);
    //
    intake::wrist.move_absolute(-100, 127);
    pros::delay(700);
    intake::wrist.move_absolute(340, 127);

    //raise the cascade for 400 ms 
    // cascade_time(intake::raise, 400);
    intake::cascade.move_voltage(12000);
    pros::delay(600);
    intake::cascade.move_voltage(0);


    pros::delay(400);

    drive::chassis.moveToPoint(-24, -25, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-40, -25, 1000);

    // //spin claw opposite driection
    pros::delay(700);
    intake::claw.move_voltage(-12000);
    pros::delay(500);
    drive::chassis.moveToPoint(-24, -25, 1000);
    intake::cascade.move_voltage(-12000);
    intake::wrist.move_absolute(0, 127);
    drive::chassis.turnToHeading(90, 500);
    drive::chassis.moveToPose(-6, -6, 45, 1000);

}
















void still_working_big_skills_auton(){
    drive::chassis.setPose(-57, 0, 90);
    intake::claw.move_voltage(12000);
    intake::wrist.move_absolute(340, 127);
     // Toggle
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    drive::chassis.moveToPoint(-52, 0, 500);
    drive::chassis.moveToPoint(-61, 0, 500, {.forwards = false}, false);
    // Drop preload into alliance stake
    drive::chassis.moveToPoint(-47.5, 0, 1000);
    drive::chassis.turnToHeading(180, 500);
    drive::chassis.moveToPoint(-47.5, -18.5, 1000);
    pros::delay(600);
    intake::claw.move_voltage(-12000);





    // first tower
    drive::chassis.moveToPoint(-47.5, 0, 1000, {.forwards = false}, 1000);
    intake::claw.move_voltage(12000);
    //raise the wrist to 600 degrees
    intake::wrist.move_absolute(600, 127);
    // Pin 2 eaten yay
    drive::chassis.turnToHeading(135, 500);
    drive::chassis.moveToPoint(-29.5, -17, 1000, {.forwards = true, .earlyExitRange = 8}, false);
    drive::chassis.moveToPoint(-27.5, -22.25, 1000, {.forwards = true, .maxSpeed = 50}, 1000);
    //
    intake::wrist.move_absolute(-100, 127);
    pros::delay(700);
    intake::wrist.move_absolute(340, 127);

    //raise the cascade for 400 ms 
    // cascade_time(intake::raise, 400);
    intake::cascade.move_voltage(12000);
    pros::delay(600);
    intake::cascade.move_voltage(0);


    pros::delay(400);

    drive::chassis.moveToPoint(-24, -25, 1000);
    drive::chassis.turnToHeading(270, 500);
    drive::chassis.moveToPoint(-40, -25, 1000);

    // //spin claw opposite driection
    pros::delay(700);
    intake::claw.move_voltage(-12000);

    //ts is a little chopped but if work works 
    pros::delay(500);
     intake::wrist.move_absolute(600, 127);
    drive::chassis.moveToPoint(-22, -25, 1000, {.forwards = false}, 1000);
    intake::cascade.move_voltage(-12000);

    intake::claw.move_voltage(12000);





//// seconds tower 


    drive::chassis.turnToHeading(225, 500);
    drive::chassis.moveToPoint(-44, -39, 1000, {.forwards = true, .earlyExitRange = 5}, false);
    drive::chassis.moveToPoint(-44, -39, 1000, {.forwards = true, .maxSpeed = 50}, 1000);

    intake::wrist.move_absolute(100, 127);
    pros::delay(200);
    intake::wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms 
    cascade_time(intake::raise, 600);
    drive::chassis.moveToPoint(-48, -48, 1000);
    drive::chassis.turnToHeading(0, 500);
    drive::chassis.moveToPoint(-48, -32, 1000);
    //spin claw opposite direction
    intake::claw.move_voltage(-12000);
    







    ///matchloader 
    drive::chassis.moveToPoint(-48, -62, 1000, {.forwards = false}, 1000);

    //lowerr the cascade for 600 ms
    cascade_time(intake::lower, 400);
    intake::wrist.move_absolute(0, 127);

    drive::chassis.turnToHeading(90, 500);
    drive::chassis.moveToPoint(-60, -62, 1000,{.forwards = false}, 1000);

    //intake 400ms 
    intake::intake_time(800);

    intake::wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms
    cascade_time(intake::raise, 600);

    drive::chassis.moveToPoint(-48, -62, 1000);
    drive::chassis.turnToHeading(0, 500);
    drive::chassis.moveToPoint(-48, -32, 1000);

    //USE THE SCORE MACRO HERE 

    drive::chassis.moveToPoint(-48, -62, 1000, {.forwards = false}, 1000);

    //lowerr the cascade for 600 ms
    cascade_time(intake::lower, 600);


    intake::wrist.move_absolute(0, 127);

    drive::chassis.turnToHeading(90, 500);
    drive::chassis.moveToPoint(-60, -62, 1000,{.forwards = false}, 1000);

    //intake 400ms 
    intake::intake_time(400);

    drive::chassis.moveToPoint(-53, -62, 1000);
    drive::chassis.turnToHeading(45, 500);
    drive::chassis.moveToPose(-17, -13, 45, 1000);

    intake::wrist.move_absolute(340, 127);
    //raise the cascade for 600 ms
    cascade_time(intake::raise, 600);


    drive::chassis.moveToPose(-6, -6, 45, 1000);
    //spin claw opposite direction
    intake::claw.move_voltage(-12000);

}





