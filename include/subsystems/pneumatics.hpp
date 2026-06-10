#ifndef _PNEUMATICS_HPP_
#define _PNEUMATICS_HPP_

//inclusions
#include "api.h"
#include "lemlib/api.hpp"

namespace pneumatics {
    extern pros::adi::Pneumatics claw;
    extern  pros::Controller master;
    //declarations of namespace functions
    void init();
    void control();

}  

#endif