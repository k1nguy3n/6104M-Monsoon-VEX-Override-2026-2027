#include "main.h"
#include "subsystems/pneumatics.hpp"


namespace pneumatics {

    void toggle (enum pneumatics_state state){
        if (state ==  extend){
            toggler1.extend();
            toggler2.extend();
        }
        if (state == retract){
            toggler1.retract();
            toggler2.retract();
        }
    }

    pros::adi::Pneumatics claw('a', true);
    pros::adi::Pneumatics toggler1('b', false);
    pros::adi::Pneumatics toggler2('c', false);
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    void control(){
        while (true){
            // Note extend and retract are flipped on claw
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                claw.retract(); 
            }
            else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
                toggler1.retract();
                toggler2.retract();
            }
            else {
                claw.extend();
                toggler1.extend();
                toggler2.extend();
            }
        }
    }
}