#ifndef _INTAKE_HPP_
#define _INTAKE_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"


namespace intake {
    
    pros::Motor intake (-14);
    pros::Motor claw (5);
    pros::MotorGroup cascade ({-1, 2},pros::MotorGears::green, pros::MotorUnits::degrees);
    pros::Motor wrist (3, pros::MotorGears::green, pros::MotorUnits::degrees);
    pros::adi::Pneumatics side_toggle('a', false);
   
    
    //controller + initialization funcs
    void init();
    void control();
    void score_macro(void); 
    
}  

#endif