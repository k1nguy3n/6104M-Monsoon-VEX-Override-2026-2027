// #include <cmath> // math functions like sqrt()
// // provides information about the properties of arithmetic types
// #include <limits>

// class Point {
//     public:
//         // values at any point
//         float x;
//         float y;
//         /* theta is initialized at NaN so theta does not
//          need to be inputted */
//         float theta = std::numeric_limits<float>::quiet_NaN();

//         // Constructor
//         Point(float x, float y, float theta = std::numeric_limits<float>::quiet_NaN())
//             : x(x),
//               y(y),
//               theta(theta) {}

//         // Method to calculate distance between two points
//         float distanceTo(const Point& other) const {
//             float deltaX = x - other.x;
//             float deltaY = y - other.y;
//             return sqrt(deltaX * deltaX + deltaY * deltaY);
//         }

//         // Method to convert degrees to radians  float
//         degreesToRadians(float degrees) { return degrees * M_PI / 180.0; }

//         // angular error
//         float angleError(const Point& other) { return other.theta - theta; }
// };

// void boomerang(float x, float y, float theta, float dlead) {
//     // assuming you have a PID class
//     PID linearPID(4, 0, 6) PID angularPID(1, 0, 2);
//     float linearError;
//     float linearPower;
//     float angularError;
//     float angularPower;
//     // calculate target pose in standard form
//     Pose target(x, y, M_PI_2 - degreesToRadians(theta));

//     while (!angularSettled && !linearSetted) {
//         Point carrot(target.x - d * cos(theta) * dlead,
// 			         target.y - d * sin(theta) * dlead);
//         linearError = robot.distanceTo(carrot);
//         linearPower = linearPID.update(linearError);
//         angularError = robot.angleTo(theta);
//         angularPower = angularPID.update(angularError);
//         float leftPower = linearPower + angularPower;
//         float rightPower = linearPower - angularPower;

//         /* move the drivetrain 
//         (assuming you have motor groups for each sandwich) */
//         drivetrain.leftMotors->move(leftPower);
//         drivetrain.rightMotors->move(rightPower);
//     }

// Necessary inclusions for code to function properly
#include "justifications/boomerang.hpp"
#include "justifications/odom.hpp"
#include "justifications/pid.hpp"
#include <cmath>
// Namespace created, organizing boomerang related funcs
namespace boomerang {
    // Note points are made using a struct
    // Current location of robot using odom and imu
    point current_loc = {x_odom(), y_odom(), imu.get_heading};
    // Function to find distance between points (linear error)
    float DistBtwnPts(point p1, point p2) {
        float deltaX = p1.x - p2.x;
        float deltaY = p1.y - p2.y;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }
    // boomerang movement 
    void bomerang_movement(point target, float curve){
        float dist = DistBtwnPts(current_loc, target);
        while (dist != 0){
            point carrot = {curve*target.x-dist*cos(imu.get_heading()), 
                            curve*target.y-dist*sin(imu.get_heading()), 
                            target.theta};
            pid::lateralPID(carrot);
            pid::angularPID(carrot);
        }
    }
}

