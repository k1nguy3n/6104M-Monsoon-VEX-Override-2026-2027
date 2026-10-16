#include "main.h"
#include "subsystems/intake.hpp"

namespace intake{
    
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    pros::Motor intake (-14);
    pros::Motor claw (5);
    pros::MotorGroup cascade ({-1, 2});
    pros::Motor wrist (3);
    
    
    void wrist_debug() {
        while (true) {
              printf("Motor Position: %lf\n", wrist.get_position());
             // printf("Raw Position: %lf\n", wrist.get_raw_position() );
            pros::delay(150);
        }
    }

    void init(){
        wrist.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        cascade.tare_position();
       //claw.tare_position();
        wrist.tare_position();
        wrist.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    
    void control(){ 
        pros::Task wrist_debug(intake::wrist_debug);
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
                    
                        if (wrist.get_position() < 890){
                            wrist.move_voltage(12000);
                            
                        }
                        else if (wrist.get_position() > 0){
                            wrist.move_voltage(0);
                            wrist.brake();
                            //SUPER BANDAID RN FIX IT 
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


