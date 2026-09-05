#ifndef _PURE_PURSUIT_HPP_
#define _PURE_PURSUIT_HPP_

//inclusions
#include "lemlib/api.hpp"

#include "api.h"
#include "main.h"

struct point {float x; float y; float theta;};

namespace pure_pursuit {
    std::pair<double, double> DistBtwnPtsVector(std::pair<double, double> p1, std::pair<double, double> p2);
    float DistBtwnPtsScalar(std::pair<double, double> p1, std::pair<double, double> p2);
    
}


#endif