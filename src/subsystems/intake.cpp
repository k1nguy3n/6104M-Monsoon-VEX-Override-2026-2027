#include "main.h"
#include "subsystems/intake.hpp"

namespace intake{
    
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    pros::Motor intake (-14);
    pros::Motor claw (5);
    pros::MotorGroup cascade ({-1, 2});
    pros::MotorGroup wrist ({3});
    
    
    

    void init(){
        cascade.tare_position();
       //claw.tare_position();
        wrist.tare_position();
    }
    
    void control(){
        float limit = 1042000;
        while (true) {
                // Up slow
                if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                   intake.move_voltage(12000);
                }
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
                   intake.move_voltage(-12000);
                }

                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                    if (cascade.get_position() <= 0){cascade.move_voltage(0);}
                    else {cascade.move_voltage(-12000);}
                   
                }
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                    if (cascade.get_position() >= limit){cascade.move_voltage(0);}
                    else {cascade.move_voltage(12000);}
                }
                // Need to do claw rotation stuff, get pos from motor? LB
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                    if (wrist.get_position() < 900 || wrist.get_position() < 1100){
                        if (wrist.get_position() < 900){
                            wrist.move_voltage(12000);
                        }
                        else if (wrist.get_position() > 1100){
                            wrist.move_voltage(-12000);
                        }
                    }
                    else{
                        wrist.move_voltage(0);
                        wrist.brake();
                    }

                }
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
                    claw.move_voltage(-12000);
                }




                // Not running intake
                else {
                    claw.move_voltage(12000*0.75);
                    intake.move_voltage(0);
                    cascade.move_voltage(0);
                    wrist.move_voltage(0);
                }
                pros::delay(10);
        }
    }



}


