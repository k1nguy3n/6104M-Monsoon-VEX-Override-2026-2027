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
    float curvature;

    float trackwidth = 14;
    float rightVoltage;
    float leftVoltage;

    // Unit Vector (Direction) of robot
    float RobotUVX = sin(imu.get_heading);
    float RobotUVY = cos(imu.get_heading);
    
    float lookahead = 15;

    float DistBtwnPtsScalar(std::pair<double, double> p1, std::pair<double, double> p2) {
        float deltaX = p1.first - p2.first;
        float deltaY = p1.second - p2.second;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    std::pair<double, double> DistBtwnPtsVector(std::pair<double, double> p1, std::pair<double, double> p2) {
        float deltaX = p2.first - p1.first;
        float deltaY = p2.second - p1.second;
        std::pair<double, double> result = {deltaX, deltaY};
    }

    

    
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
                float p1vector = DistBtwnPtsScalar(origin, p1);
                std::pair<double, double> pt2pt = DistBtwnPtsVector(p1, p2);
                std::pair<double, double> robot2pt = DistBtwnPtsVector(robotloc, p1);
                
                float DOTrobot2pt_pt2pt = (robot2pt.first*pt2pt.first) + (robot2pt.second*pt2pt.second);
                float DOTpt2pt_pt2pt = (pt2pt.first*pt2pt.first) + (pt2pt.second*pt2pt.second);
                float DOTrobot2pt_robot2pt = (robot2pt.first*robot2pt.first) + (robot2pt.second*robot2pt.second);
                // 
                float ScalarPos = (-(DOTrobot2pt_pt2pt) + std::pow(std::pow(DOTrobot2pt_pt2pt, 2)-(DOTpt2pt_pt2pt)*(DOTrobot2pt_robot2pt-std::pow(lookahead, 2)), 0.5))/(DOTpt2pt_pt2pt);
                float ScalarNeg = (-(DOTrobot2pt_pt2pt) - std::pow(std::pow(DOTrobot2pt_pt2pt, 2)-(DOTpt2pt_pt2pt)*(DOTrobot2pt_robot2pt-std::pow(lookahead, 2)), 0.5))/(DOTpt2pt_pt2pt);
                
                std::pair<double, double> ChasingPtPos = {p1.first + ScalarPos*pt2pt.first, p1.second+ScalarPos*pt2pt.second};
                std::pair<double, double> ChasingPtNeg = {p1.first + ScalarNeg*pt2pt.first, p1.second+ScalarNeg*pt2pt.second};
                // reminder to self to make thing to figure out which intersection point is closest
                std::pair<double, double> ChasingPt;
                if (DistBtwnPtsScalar(ChasingPtPos, p1) > DistBtwnPtsScalar(ChasingPtNeg, p1)){
                    ChasingPt = ChasingPtPos;
                }
                else {
                    ChasingPt = ChasingPtNeg;
                }

                // Need condition for 1 and 0 points of intersection

                curvature = (2*ChasingPt.second)/std::pow(lookahead, 2);

            }
            withinError = false;
            
            float u_pid = (rightVoltage+leftVoltage)/2;
            float K_pp = (trackwidth/2)*curvature*u_pid;
            rightVoltage = u_pid + K_pp*curvature;
            rightVoltage = u_pid - K_pp*curvature;

        }

        


        //float pint = -(f*dist);
    }
}