// Needed inclusions for now
#include <vector>
#include <cmath>
#include "subsystems/pure_pursuit.hpp"
#include "subsystems/drive.hpp"
#include "justifications/odom.hpp"

// Namespace to keep things organized
namespace pure_pursuit{
    // points need to be unit vectors?
    std::vector<std::pair<double, double>> points;
    // robot loc/circle center
    float angle = odom::imu.get_heading() * (M_PI/180);
    point current_loc = {odom::x_odom(), odom::y_odom(), angle};
    std::pair<double, double> robotloc = {odom::x_odom(), odom::y_odom()};

    std::pair<double, double> goal;
    std::pair<double, double> origin = {0, 0};
    float curvature;

    float trackwidth = 14;
    float rightVoltage;
    float leftVoltage;

    // Unit Vector (Direction) of robot
    float RobotUVX = sin(angle);
    float RobotUVY = cos(angle);
    
    float lookahead = 15;

    float DistBtwnPtsScalar(std::pair<double, double> p1, std::pair<double, double> p2) {
        float deltaX = p2.first - p1.first;
        float deltaY = p2.second - p1.second;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    std::pair<double, double> DistBtwnPtsVector(std::pair<double, double> p1, std::pair<double, double> p2) {
        float deltaX = p2.first - p1.first;
        float deltaY = p2.second - p1.second;
        std::pair<double, double> result = {deltaX, deltaY};
        return result;
    }
    
    void pure_pursuit(std::vector<std::pair<double, double>>& points){
        // so once a robot has passed a point, we need to figure out
        bool withinError = false;
        // If the error is within 1 inch in the x and y direction 
        if (((robotloc.first-goal.first) < 1 || (robotloc.first-goal.first) >= -1) 
        && ((robotloc.second-goal.second) < 1 || (robotloc.second-goal.second) >= -1)){
            withinError = true;
        }

        for (int x = 0; x < points.size(); x++){
            if (withinError){
                // Distance between points
                std::pair<double, double> p1 = points[x];
                std::pair<double, double> p2 = points[x+1];
                // float p1vector = DistBtwnPtsScalar(origin, p1);
                std::pair<double, double> pt2pt = DistBtwnPtsVector(p1, p2);
                std::pair<double, double> robot2pt = DistBtwnPtsVector(robotloc, p1);
                // 
                float DOTrobot2pt_pt2pt = (robot2pt.first*pt2pt.first) + (robot2pt.second*pt2pt.second);
                float DOTpt2pt_pt2pt = (pt2pt.first*pt2pt.first) + (pt2pt.second*pt2pt.second);
                float DOTrobot2pt_robot2pt = (robot2pt.first*robot2pt.first) + (robot2pt.second*robot2pt.second);
                // 
                if (std::pow(DOTrobot2pt_pt2pt, 2)-(DOTpt2pt_pt2pt)*(DOTrobot2pt_robot2pt-std::pow(lookahead, 2)) >= 0){
                        float ScalarPos = (-(DOTrobot2pt_pt2pt) + sqrt(DOTrobot2pt_pt2pt*DOTrobot2pt_pt2pt-(DOTpt2pt_pt2pt)*(DOTrobot2pt_robot2pt-lookahead*lookahead)))/(DOTpt2pt_pt2pt);
                        float ScalarNeg = (-(DOTrobot2pt_pt2pt) - sqrt(DOTrobot2pt_pt2pt*DOTrobot2pt_pt2pt-(DOTpt2pt_pt2pt)*(DOTrobot2pt_robot2pt-lookahead*lookahead)))/(DOTpt2pt_pt2pt);
                        
                        std::pair<double, double> ChasingPtPos = {p1.first + ScalarPos*pt2pt.first, p1.second+ScalarPos*pt2pt.second};
                        std::pair<double, double> ChasingPtNeg = {p1.first + ScalarNeg*pt2pt.first, p1.second+ScalarNeg*pt2pt.second};
                        // reminder to self to make thing to figure out which intersection point is closest
                        std::pair<double, double> ChasingPt;
                    
                        if (DistBtwnPtsScalar(ChasingPtPos, p1) > DistBtwnPtsScalar(ChasingPtNeg, p1)){
                            ChasingPt = ChasingPtPos;
                        }
                        else {ChasingPt = ChasingPtNeg;}

                        // Need condition for 1 and 0 points of intersection
                        float lateral_offset = -(robotloc.first - ChasingPt.first)*cos(angle)+(robotloc.second - ChasingPt.second)*sin(angle);
                        curvature = (2*lateral_offset)*(lookahead*lookahead);

                        withinError = false;
                        float u_pid = (rightVoltage+leftVoltage)/2;
                        float K_pp = (trackwidth/2)*curvature*u_pid;
                        rightVoltage = u_pid + K_pp*curvature;
                        leftVoltage = u_pid - K_pp*curvature;

                        
                        // Left drive motors with appropiate signs for directions
                        drive::left_drive.move_voltage(leftVoltage);
                        drive::right_drive.move_voltage(rightVoltage);
                        
                        pros::delay(500);
                      
                }
                else {
                    
                }       
            }

        //float pint = -(f*dist);
        }
    }

}