// Include necessary files for properly functioning program
#include "main.h"
#include <cmath>
#include "subsystems/intake.hpp"
// Intake namespace
namespace intake{
    // Define intake stages by motor ports
    pros::Motor intake (-8);
    pros::MotorGroup winch ({-21, 16});
    
    // Set winch position to 0
    void init(){
        winch.tare_position();
    }
    //B claw | R1 up slow | L1 Down slow | R2 Up fast | L2 Down fast
    // Def controller
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    // Controller functions
    void control() {
        while (true) {
                winch.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
                // Up slow
                if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                    if (winch.get_position() >= 360000000){winch.move_voltage(0);}
                    else {winch.move_voltage(6000);}
                }
                // Up fast
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                    if (winch.get_position() >= 360000000){winch.move_voltage(0);}
                    else {winch.move_voltage(12000);}
                }
                // down slow
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
                    if (winch.get_position() <= 0){winch.move_voltage(0);}
                    else {winch.move_voltage(-6000);}
                }
                // Down fast
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
                    if (winch.get_position() <= 0){winch.move_voltage(0);}
                    else {winch.move_voltage(-12000);}
                }   
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                    intake.move_voltage(12000);
                }
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
                    intake.move_voltage(-12000);
                }
                // Not running intake
                else {
                    winch.move_voltage(0);
                    intake.move_voltage(0);

                }
                pros::delay(10);
        }

    }
}