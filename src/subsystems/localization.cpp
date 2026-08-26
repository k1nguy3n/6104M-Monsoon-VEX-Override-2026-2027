// I don't have the dopamine for ts
#include "main.h"
#include "subsystems/localization.hpp"
#include <cmath>
#include "subsystems/drive.hpp"

// Fresh localization namespace for organization
namespace localization{
    // Odom system sensors (put in new file later?)
    pros::IMU imu(11);
    pros::Rotation horiz_sensor(1);
    lemlib::TrackingWheel horiz_tw(&horiz_sensor, lemlib::Omniwheel::NEW_2, -1);
    // Group odom components
    lemlib::OdomSensors sensors(nullptr, // vertical tracking wheels
                            nullptr,    // set to nullptr as we are using IMEs
                            &horiz_tw, // horizontal tracking wheel 1
                            nullptr, // horiz tracking wheel 2, nullptr (don't have 2nd one)
                            &imu); // inertial sensor
   
    /* Sensors and lateral + angular offsets (all guessed lol) in a system
    {sensor, vertical offset, horizontal offset, angular offset, calibration const 
    (when robot faces forward)}*/
    dsr DSR {distSensor {pros::Distance(111), 0, 0, 0, 18.35/18.858268},
            distSensor {pros::Distance(6), 3.0, 4.0, 180, 1},
            distSensor {pros::Distance(15), 0, 4.5, 90, 1},
            distSensor {pros::Distance(13), 0, 4.5, 270.0, 1}, 
            imu};
    // Idk a good place to put this but paranoia func eventually
    float paranoia(float pose, auto position){
        float pos;
        if (pose - position >= 10 || pose - position <= -10 || position == NAN){
            pos = pose;
        }
        else {
            pos = position;
        }
    }
    // Function to find lateral distance (when at an angle too!)
    // Create function to read distances
    void updatePos(distSensor sensor) {
        // Find current position (odom)
        lemlib::Pose pose = drive::chassis.getPose();
        // Find angle to be used in trig
        // Find distance with sensor of user choice(mm to in)
        float dist = (sensor.calibrate * sensor.sensor.get())/25.4;
        // Finding angle of sensor in radians
        float angle = (pose.theta + sensor.Angoffset) * (M_PI/180);
        // Sensor position (starting point)
        float Xsensor_pos = sensor.Xoffset*cos(pose.theta * (M_PI/180)) + sensor.Yoffset*sin(pose.theta * (M_PI/180)) + pose.x;
        float Ysensor_pos = -sensor.Xoffset*sin(pose.theta * (M_PI/180)) + sensor.Yoffset*cos(pose.theta * (M_PI/180)) + pose.y;
        // Unit Vector Version (Direction)
        float UXbeam = sin(angle);
        float UYbeam = cos(angle);
        // Choose to update x or y
        float possibleX = (70-Xsensor_pos)/UXbeam;
        float possibleY = (70-Ysensor_pos)/UYbeam;
        if (possibleX < 0){
            possibleX = INFINITY;
        }
        else if (possibleY < 0){
            possibleY = INFINITY;
        }

        float loc;
        float test;
        if ((70-Xsensor_pos)/UXbeam < (70-Ysensor_pos)/UYbeam){
            if (UXbeam < 0){
                loc = -70 - dist*UXbeam - sensor.Xoffset*cos(pose.theta * (M_PI/180)) - sensor.Yoffset*sin(pose.theta * (M_PI/180));
                //test = dist*UXbeam + sensor.Xoffset*cos(imu.get_heading() * (M_PI/180)) + sensor.Yoffset*sin(imu.get_heading() * (M_PI/180));
            }
            else {
                loc = 70 - dist*UXbeam - sensor.Xoffset*cos(pose.theta * (M_PI/180)) - sensor.Yoffset*sin(pose.theta * (M_PI/180));
            }
            //loc = paranoia(pose.x, loc);
            drive::chassis.setPose({loc, pose.y, pose.theta});
        }

        else if ((70-Ysensor_pos)/UYbeam < (70-Xsensor_pos)/UXbeam){
            if (UYbeam < 0){
                loc = -70 - dist*UYbeam - sensor.Xoffset*sin(pose.theta * (M_PI/180)) - sensor.Yoffset*cos(pose.theta * (M_PI/180));
            }
            else {
                loc = 70 - dist*UYbeam + sensor.Xoffset*sin(pose.theta * (M_PI/180)) - sensor.Yoffset*cos(pose.theta * (M_PI/180));
            }
            //loc = paranoia(pose.y, loc);
            drive::chassis.setPose({pose.x, loc, pose.theta});
        }    
    
    } 
}