#include "main.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/pneumatics.hpp"
#include "autons.hpp"
#include <iostream>

lemlib::Pose pose = drive::chassis.getPose();

void basic_blue(){
    pros::Task odom_debug(drive::odom_debug);
    // Start Centered
    drive::chassis.setPose(-63.5, 0, 90);
    std::cout <<"0 Initial" << std::endl;
    
    pneumatics::claw.retract();
    // Toggle
    pneumatics::toggle(extend);
    drive::chassis.moveToPoint(-55, 0, 1000);
    std::cout <<"1 Straight" << std::endl;
   
    
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, false);
    std::cout <<"2 Straight" << std::endl;
   
    
    drive::chassis.moveToPoint(-55, 0, 1000);
    std::cout <<"3 Straight" << std::endl;
    
    
    drive::chassis.moveToPoint(-63.5, 0, 1000, {.forwards = false}, false);
    std::cout <<"4 Straight" << std::endl;
    
    
    // Goal
    drive::chassis.moveToPoint(-50, 0, 1000);
    std::cout <<"5 Straight" << std::endl;
   
    
    drive::chassis.turnToHeading(0, 1000);
    std::cout <<"6 Turn" << std::endl;
   
    
    drive::chassis.moveToPoint(-48, 16, 1000, {.forwards = true}, false);
    std::cout <<"7 Straight" << std::endl;
   
    
    //pros::delay(1000); 
    pneumatics::claw.retract();
    
    // // Cup/Pin
    drive::chassis.moveToPoint(-48, 0, 1000, {.forwards = false}, true);
    std::cout <<"8 Straight" << std::endl;
   
    
    drive::chassis.turnToHeading(45, 1000);
    std::cout <<"9 Turn" << std::endl;
   
    
    // drive::chassis.moveToPoint(-33.5, 15.5, 1000); 
    //drive::chassis.moveToPoint(-33.25, 15.25, 1000, {.forwards = true}, false); 
    drive::chassis.moveToPoint(-33, 15, 1000, {.forwards = true}, false); 
    std::cout <<"10 Staight" << std::endl;
    
    
    //pneumatics::claw.retract();
    pneumatics::claw.extend();
    

    // Back to goal
    drive::chassis.moveToPoint(-50, 0, 1000, {.forwards = false}, true);
    std::cout <<"11 Straight" << std::endl;
    
    
    drive::chassis.turnToHeading(0, 1000);
    std::cout <<"12 Turn" << std::endl;
    
    
    drive::chassis.moveToPoint(-50, 16, 1000); 
    std::cout <<"13 Straight" << std::endl;
    
    
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