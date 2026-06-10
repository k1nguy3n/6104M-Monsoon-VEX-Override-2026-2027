#ifndef _INTAKE_HPP_
#define _INTAKE_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"


namespace intake {
    

    extern pros::Motor first_stage; 
    extern pros::MotorGroup winch;
    //timed intake funcs
    
    //controller + initialization funcs
    void init();
    void control();
    
}  

#endif