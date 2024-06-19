//This code wait to run turtle sim first then it runs the rest of the code
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Spawn.h>
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "circle_walk_to");
    ros::NodeHandle nh;

  

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate rate(10);

    std::cout << "Starting square...\n";
    float linearSpeed = 1;

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



/*
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "circle_walk");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate rate(10);
    std::cout << "initializing 'circle_walk'\n";
    std::cout << "Starting square...\n";
    float linearSpeed = 0.5;
    

    for (int loop = 1; loop <= 2; ++loop)
    {
    	std::cout << "In main for loop, loop: " << loop << "\n";
    	if (loop % 2 == 0)

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
            twist.linear.x = 0.5;
            pub.publish(twist);
            rate.sleep();
        }
        //geometry_msgs::Twist twist;
        //twist.linear.x = 0.0;
        //pub.publish(twist);
        //rate.sleep();

        for (int i = 1; i <= 20; ++i)
        {
        	std::cout << "In second for loop, loop: " << i << "\n";
        	geometry_msgs::Twist twist;
        	twist.angular.z = M_PI / 4;
        	pub.publish(twist);
        	rate.sleep();
        }
        geometry_msgs::Twist twist;
        twist.linear.x = 0.0;
        twist.angular.z = 0.0;
        pub.publish(twist);
        rate.sleep();

        //for (int i = 0; i < 20; ++i)
        //{
        	//std:: cout << "In second for loop, loop: " << i << "\n";
            //geometry_msgs::Twist twist;
            //twist.angular.z = M_PI / 4;
            //pub.publish(twist);
            //rate.sleep();
        //}
        
    }
    return 0;
}

*/


/*
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "circle_walk");

	ros::NodeHandle nh;

	ros::Rate loop_rate(500);

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

	geometry_msgs::Twist twist;

	while (ros::ok())
	{
        twist.linear.x = 0.5; // radius (meters)
        twist.linear.y = 0;
        twist.linear.z = 0;
        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = 1; // direction (positive = left, negative = right)

		pub.publish(twist);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
*/