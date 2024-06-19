/*
//This code wait to run turtle sim first then it runs the rest of the code
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Spawn.h>
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_sim");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    ros::Rate rate(10);
    std::cout << "Starting square...\n";
    float linearSpeed = 0.5;

    for (int loop = 1; loop <= 2; ++loop)
    {
        std::cout << "In main for loop, loop: " << loop << "\n";
        if ( loop % 2 == 0 )
        {
            linearSpeed = -linearSpeed;
        }
        else
        {
            abs(linearSpeed);
        }
        for (int i = 1; i<= 20; ++i)
        {
            std::cout << "In first for loop, loop: " << i << "\n";
            geometry_msgs::Twist twist;
            twist.linear.x = linearSpeed;
            pub.publish(twist);
            rate.sleep();
        }

        for (int i = 1; i <= 20; i++)
        {
            std::cout << "In second for loop, loop: " << i << "\n";
            geometry_msgs::Twist twist;
            twist.linear.y = linearSpeed;
            pub.publish(twist);
            rate.sleep();
        }
        geometry_msgs:: Twist twist;
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        pub.publish(twist);    
        rate.sleep();
        //works for rotation 
        //for (int i = 0; i < 20; ++i)
        //{
            //std::cout << "In second for loop, loop: " << i << "\n";
            //geometry_msgs::Twist twist;
            //twist.angular.z = M_PI / 4;
            //pub.publish(twist);
            //rate.sleep();
        //}
    }


    return 0;
}

*/








#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_sim");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    ros::Rate rate(10);

    std::cout << "Starting square...\n";

    for (int j = 1; j <= 4; ++j)
    {
        //std::cout << "In main for loop, loop: " << j << "\n";
        for (int i = 1; i<= 20; ++i)
        {
            //std::cout << "In first for loop, loop: " << i << "\n";
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5;
            pub.publish(twist);
            rate.sleep();
        }

        for (int i = 0; i < 20; ++i)
        {
            //std::cout << "In second for loop, loop: " << i << "\n";
            geometry_msgs::Twist twist;
            twist.angular.z = M_PI / 4;
            pub.publish(twist);
            rate.sleep();
        }
    }
    return 0;
}



/*
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cmath>

//#define PI 3.1415926535897

void moveInLine(geometry_msgs::Twist& twist, ros::Publisher& pub, ros::Rate& rate)
{
    double distance = 1.0;
    double distanceTraveled = 0.0;
    double speed = 1.0;
    int i = 1;

    twist.linear.x = speed;
    double t0 = ros::Time::now().toSec();

    while (distanceTraveled < distance)
    {
        pub.publish(twist);
        //ROS_INFO("In 'moveInLine' while loop");
        std::cout << "In 'moveInLine' while loop, loop " << i <<"\n";
        double t1 = ros::Time::now().toSec();
        distanceTraveled = speed * (t1 - t0);
        std::cout<<"distance travelled: "<< distanceTraveled << "\n";
        rate.sleep();
        i++;
    }

    twist.linear.x = 0.0;
    pub.publish(twist);
}

void rotate(geometry_msgs::Twist& twist, ros::Publisher& pub, ros::Rate& rate)
{
    double angledTraveled = 0.0;
    double angleSpeed = .08;
    double angleTarget = M_PI / 2;
    int j =1;

    twist.angular.z = angleSpeed;
    double time0 = ros::Time::now().toSec();

    while (angledTraveled <  angleTarget)
    {
        pub.publish(twist);
        //ROS_INFO("In 'rotate' while loop");
        std::cout << "In 'rotate' while loop, loop "<< j << "\n";
        double time1 = ros::Time::now().toSec();
        angledTraveled = angleSpeed * (time1 - time0);
        std::cout << "angledTraveled: "<<angledTraveled << "\n";
        rate.sleep();
        j++;
    }

    twist.angular.z = 0.0;
    pub.publish(twist);
}

void squareParameters()
{
    ROS_INFO("Starting square...");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate rate(10);

    geometry_msgs::Twist twist;

    for(int i =0; i < 4; i++)
    {
      moveInLine(twist, pub, rate);
      rotate(twist, pub, rate);
    }
    
    //while (ros::ok())
    //{
        //moveInLine(twist, pub, rate);
        //rotate(twist, pub, rate);
    //}
    
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_sim");
    
    try
    {
        squareParameters();
    }
    catch (ros::Exception& e)
    {
        ROS_ERROR_STREAM("An exception occurred: " << e.what());
    }

    return 0;
}
*/










/*

//This code wait to run turtle sim first then it runs the rest of the code
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Spawn.h>
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_sim");
    ros::NodeHandle nh;

    // Wait for the "spawn" service of TurtleSim to become available
    bool turtleSimAvailable = ros::service::waitForService("/spawn", ros::Duration(10.0));

    if (turtleSimAvailable)
    {
        // TurtleSim has started

        ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
        ros::Rate rate(10);

        std::cout << "Starting square...\n";
        float linearSpeed = 0.0;

        for (int loop = 1; loop <= 2; ++loop)
        {
            std::cout << "In main for loop, loop: " << loop << "\n";
            if ( loop % 2 == 0 )
            {
                linearSpeed = -linearSpeed;
            }
            else
            {
                abs(linearSpeed);
            }
            for (int i = 1; i<= 20; ++i)
            {
                std::cout << "In first for loop, loop: " << i << "\n";
                geometry_msgs::Twist twist;
                twist.linear.x = linearSpeed;
                pub.publish(twist);
                rate.sleep();
            }

            for (int i = 1; i <= 20; i++)
            {
                std::cout << "In second for loop, loop: " << i << "\n";
                geometry_msgs::Twist twist;
                twist.linear.y = linearSpeed;
                pub.publish(twist);
                rate.sleep();
            }
            geometry_msgs:: Twist twist;
            twist.linear.x = 0.0;
            twist.linear.y = 0.0;
            pub.publish(twist);    
            rate.sleep();
            //works for rotation 
            //for (int i = 0; i < 20; ++i)
            //{
                //std::cout << "In second for loop, loop: " << i << "\n";
                //geometry_msgs::Twist twist;
                //twist.angular.z = M_PI / 4;
                //pub.publish(twist);
                //rate.sleep();
            //}
        }
    }
    else
    {
        ROS_ERROR("Failed to start TurtleSim. Exiting...");
        return 1;
    }

    return 0;
}








*/


































