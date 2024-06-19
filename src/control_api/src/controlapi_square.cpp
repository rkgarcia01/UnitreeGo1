#include <ros/ros.h>
#include <unitree_legged_msgs/HighCmd.h>
#include <unitree_legged_msgs/HighState.h>
#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include "convert.h"

using namespace UNITREE_LEGGED_SDK;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "example_walk_without_lcm");

    std::cout << "WARNING: Control level is set to HIGH-level." << std::endl
              << "Make sure the robot is standing on the ground." << std::endl
              << "Press Enter to continue..." << std::endl;
    std::cin.ignore();

    ros::NodeHandle nh;

    ros::Rate loop_rate(8);

    long motiontime = 0;

    unitree_legged_msgs::HighCmd high_cmd_ros;

    ros::Publisher pub = nh.advertise<unitree_legged_msgs::HighCmd>("high_cmd", 8);


        high_cmd_ros.head[0] = 0xFE;           //reserved, no need to set
        high_cmd_ros.head[1] = 0xEF;           //reserved, no need to set
        high_cmd_ros.levelFlag = HIGHLEVEL;    //reserved, no need to set
        high_cmd_ros.mode = 0;                 //mode: comments are at the bottom
        high_cmd_ros.gaitType = 1;             //gaitType: comments are at the bottom
        high_cmd_ros.speedLevel = 0;           //reserved
        high_cmd_ros.footRaiseHeight = 0;      //(unit: m, range: -0.06~0.03m, default: 0.09m), foot up height while walking, delta value
        high_cmd_ros.bodyHeight = 0;           //(unit: m, range: -0.13~0.03m, default: 0.31m), delta value
        high_cmd_ros.euler[0] = 0;             //euler: comments are at the bottom
        high_cmd_ros.euler[1] = 0;             //euler: comments are at the bottom
        high_cmd_ros.euler[2] = 0;             //euler: comments are at the bottom
        high_cmd_ros.velocity[0] = 0.0f;       //velocity: comments are at the bottom
        high_cmd_ros.velocity[1] = 0.0f;       //velocity: comments are at the bottom
        high_cmd_ros.yawSpeed = 0.0f;          //yawSpweed: comments are at the bottom
        high_cmd_ros.reserve = 0;              //reserve set to 0 (Default)

        for (int j = 1; j<= 4; ++j)
        {
            //high_cmd_ros.velocity[0] = 0.5;
            for (int i = 1; i<= 20; ++i )
            {
                high_cmd_ros.mode = 2;
                high_cmd_ros.velocity[0] = 0.5;
                pub.publish(high_cmd_ros);
                loop_rate.sleep();
            }
            
            high_cmd_ros.velocity[0] = 0.0f; // Stop forward movement
            pub.publish(high_cmd_ros);
            //high_cmd_ros.yawSpeed = M_PI / 4;
            for (int i = 1; i <= 20; ++i)
            {
                high_cmd_ros.mode = 2;
                high_cmd_ros.yawSpeed = M_PI/4;
                pub.publish(high_cmd_ros);
                loop_rate.sleep();
            }
            high_cmd_ros.mode = 0;
            high_cmd_ros.velocity[0] = 0.0f; // Stop forward movement 
            high_cmd_ros.yawSpeed = 0;
            pub.publish(high_cmd_ros);
        }
        
        high_cmd_ros.velocity[0] = 0.0f;
        high_cmd_ros.mode = 0;;
        pub.publish(high_cmd_ros);

        ros::spinOnce();
        loop_rate.sleep();
    

    return 0;
}







/*

// All the following bellow are only for High Command Messages "HighCMD"

/*
****mode: it is used to set the different modes for the robots****
 - mode = 0 : idle, default stand
 - mode = 1 : force stand (controlled by dBodyHeight + ypr)
 - mode = 2 : target velocity walking (controlled by velocity + yawSpeed)
 - mode = 3 : target position walking (controlled by position + ypr[0]), reserve
 - mode = 4 : path mode walking (reserve for future release), reserve
 - mode = 5 : position stand down.
 - mode = 6 : position stand up
 - mode = 7 : damping mode
 - mode = 8 : recovery stand
 - mode = 9 : backflip, reserve
 - mode = 10 : jumpYaw, only left direction. Note, to use this mode, you need to set mode = 1 first.
 - mode = 11 : straightHand. Note, to use this mode, you need to set mode = 1 first.

*/

/*
****gaitType: means that throughout the code, you might see conditional statements (like if or switch statements) 
that check the value of gaitType and then determine which gait or action the robot (or system) should perform based on this value. 
This approach is a simple and effective way to manage different states or modes in a system. ****
 
 - gaitType = 0 : idle
 - gaitType = 1 : trot
 - gaitType = 2 : trot running
 - gaitType = 3 : climb stair
 - gaitType = 4 : trot obstacle
*/

/*
****euler: (unit: rad), roll pitch yaw in "stand mode". orientation of an robot in 3D space when it's in "stand mode".****
 - (range: roll : -0.75~0.75rad)
 - (range: pitch: -0.75~0.75rad)
 - (range: yaw  : -0.6~0.6rad)
*/

/* 
****velocity: (unit: m/s), forwardSpeed, sideSpeed in body frame****
 - (range: trot : vx:-1.1~1.5m/s,  vy:-1.0~1.0m/s)
 - (range: run  : vx:-2.5~3.5m/s,  vy:-1.0~1.0m/s)
 - (range: stair: vx:-0.2~0.25m/s, vy:-0.15~0.15m/s)
 - velocity[0] : msg->linear.x
 - velocity[1] : msg->linear.y

*/

/*
****yawSpeed: (unit: rad/s), rotateSpeed in body frame****
 - (range: trot : -4.0~4.0rad/s)
 - (range: run  : -4.0~4.0rad/s)
 - (range: stair: -0.7~0.7rad/s)
*/

// All the following above are only for High Command Messages "HighCMD"
