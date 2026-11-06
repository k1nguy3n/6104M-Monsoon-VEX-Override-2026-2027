#ifndef _INTAKE_HPP_
#define _INTAKE_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"
#include "main.h"


namespace intake {
    
    extern pros::Motor intake;
    extern pros::Motor claw;
    extern pros::MotorGroup cascade;
    extern pros::Motor wrist;
    extern pros::adi::Pneumatics side_toggle;
    

    enum cascade_pose {raise, lower};

    void intake_time (uint32_t millisec);
    void move_cascade(float height);
    void cascade_time(cascade_pose, uint32_t millisec);

    //controller + initialization funcs
    void init();
    void control();
    void score_macro(void); 

    
}  

#endif