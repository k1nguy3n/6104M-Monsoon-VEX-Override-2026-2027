// Needed inclusions for now
#include <string>
#include <vector>
#include <cmath>
#include "subsystems/pure_pursuit.hpp"
// Namespace to keep things organized
namespace paths{
    // points need to be unit vectors?
    std::vector<std::pair<double, double>> points;
    // robot loc/circle center
    point current_loc = {x_odom(), y_odom(), imu.get_heading};
    std::pair<double, double> robotloc = {x_odom(), y_odom()};

    std::pair<double, double> goal;
    std::pair<double, double> origin = {0, 0};

    float trackwidth = 14;
    
    float leftVolt;
    float rightVolt;
    // Unit Vector (Direction) of robot
    float RobotUVX = sin(imu.get_heading);
    float RobotUVY = cos(imu.get_heading);
    
    float lookahead = 15;

    float DistBtwnPts(std::pair<double, double> p1, std::pair<double, double> p2) {
        float deltaX = p1.first - p2.first;
        float deltaY = p1.second - p2.second;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    float robot2goal = DistBtwnPts(robotloc, goal);

    
    void pure_pursuit(std::vector<std::pair<double, double>> points){
        // so once a robot has passed a point, we need to figure out
        bool withinError = false;
        if (((robotloc.first-goal.first) <= 1 || (robotloc.first-goal.first) >= 1) 
        && ((robotloc.first-goal.second) <= 1 || (robotloc.first-goal.second) >= 1)){
            withinError = true;
        }

        for (int x = 0; x < points.size(); x++){
            if (withinError == true){
                // Distance between points
                std::pair<double, double> p1 = points[x];
                std::pair<double, double> p2 = points[x+1];
                float p1vector = DistBtwnPts(origin, p1);
                float pt2pt = DistBtwnPts(p1, p2);
                float robot2pt = DistBtwnPts(robotloc, p1);
                float ChasingVectorPos = (p1vector + -(robot2pt*pt2pt) + std::pow(std::pow(robot2pt*pt2pt, 2)-(pt2pt*pt2pt)*(robot2pt*robot2pt-std::pow(lookahead, 2)), 0.5))/pt2pt;
                float ChasingVectorNeg = (p1vector + -(robot2pt*pt2pt) - std::pow(std::pow(robot2pt*pt2pt, 2)-(pt2pt*pt2pt)*(robot2pt*robot2pt-std::pow(lookahead, 2)), 0.5))/pt2pt;
                // swap x and y/sin and cos? figure out heading
                std::pair<double, double> ChasingPtPos = {ChasingVectorPos*cos(111111), ChasingVectorPos*sin(111111)};
                std::pair<double, double> ChasingPtNeg = {ChasingVectorNeg*cos(111111), ChasingVectorNeg*sin(111111)};
                // reminder to self to make thing to figure out which intersection point is closest

            }
            withinError = false;
        }




        //float pint = -(f*dist);
    }
}