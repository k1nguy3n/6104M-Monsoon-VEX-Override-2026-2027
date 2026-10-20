#include "main.h"
#include "subsystems/intake.hpp"

namespace intake{
    
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    pros::Motor intake (-14);
    pros::Motor claw (5);
    pros::MotorGroup cascade ({-1, 2},pros::MotorGears::green, pros::MotorUnits::degrees);
    pros::Motor wrist (3,pros::MotorGears::green, pros::MotorUnits::degrees);
    

    void wrist_debug() {
        while (true) {
            // int mode = wrist.get_brake_mode();
            std::printf("Motor Group Position: %f\n", cascade.get_position());
            pros::delay(150);
        }
    }

    void init(){
        cascade.tare_position();
        wrist.tare_position();
        wrist.set_brake_mode(pros::MotorBrake::hold);
        cascade.set_brake_mode(pros::MotorBrake::hold);
    }
    
    void control(){ 
        init();
         pros::Task debug_task(wrist_debug);
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
                else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
                    claw.move_voltage(-12000);
                }
                else {
                    claw.move_voltage(12000*0.75);
                    intake.move_voltage(0);
                    cascade.move_voltage(0);
                }

                // Need to do claw rotation stuff, get pos from motor? LB

                //CLAW
                if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                        if (wrist.get_position() < 340){
                            wrist.move_voltage(12000);
                            
                        }
                        else if (wrist.get_position() > 340){
                            wrist.brake();
                        }

                }


                // Not running intake
                else {
                    if (cascade.get_position() < 200){
                            wrist.move_absolute(0, 100);
                            
                        }
                        
                    else if (cascade.get_position() > 200){
                         wrist.move_absolute(340, 127);
                        }
                }
                pros::delay(10);
        }
    }



}


