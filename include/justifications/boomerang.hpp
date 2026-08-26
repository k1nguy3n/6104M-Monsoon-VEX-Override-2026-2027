#ifndef _BOOMERANG_HPP_
#define _BOOMERANG_HPP_

//inclusions
#include "lemlib/api.hpp"

#include "api.h"
#include "main.h"

struct point {float x; float y; float theta;};
namespace boomerang {
    float DistBtwnPts(point p1, point p2);
    void bomerang_movement(point target, float curve);
}


#endif