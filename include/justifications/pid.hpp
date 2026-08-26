#ifndef _PID_HPP_
#define _PID_HPP_

#include "api.h"
struct point {float x; float y; float theta;};
namespace pid{
    struct PIDconsts {float kP; float kI; float kD;};
    enum axis {x, y};
    enum direction {clockwise, counterclockwise};
    void lateralPID(point target);
    void angularPID(point target);

}

#endif