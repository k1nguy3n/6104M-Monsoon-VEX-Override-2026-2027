#include "main.h"
#include "subsystems/pneumatics.hpp"


namespace pneumatics {
    pros::adi::Pneumatics claw('a', false);
    pros::Controller master (pros::E_CONTROLLER_MASTER);
    void control(){
        while (true){
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                claw.retract(); 
            }
            else {
                claw.extend();
            }
        }
    }
}