#ifndef _PURE_PURSUIT_HPP_
#define _PURE_PURSUIT_HPP_

//inclusions
#include "lemlib/api.hpp"

#include "api.h"
#include "main.h"

struct point {float x; float y; float theta;};

namespace pure_pursuit {
    float DistBtwnPts(point p1, point p2);
    
}


#endif