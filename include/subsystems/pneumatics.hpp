#ifndef _PNEUMATICS_HPP_
#define _PNEUMATICS_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"

namespace pneumatics {
    extern pros::adi::Pneumatics claw;
    extern pros::adi::Pneumatics toggler1;
    extern pros::adi::Pneumatics toggler2;
    extern  pros::Controller master;
    //declarations of namespace functions
    void init();
    void control();

}  

#endif