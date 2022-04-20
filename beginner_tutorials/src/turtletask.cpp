#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "math.h"

ros::Publisher velocity_publisher1;
ros::Publisher velocity_publisher2;
//ros::Subscriber position;

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "turtles");

  ros::NodeHandle n;
  
  
  velocity_publisher1 = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
  velocity_publisher2 = n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",10);
  
  //position1 = n.subscribe("/turtle1/pose",10,positionone);
  
  
  while (ros::ok())
  {
    
    geometry_msgs::Twist vel;
    
    
    
    
    vel.linear.x = 3;
    vel.angular.z = -2;
    
    
    
    velocity_publisher1.publish(vel);
    velocity_publisher2.publish(vel);
   }
  
  ros::spin();


  return 0;
}

    

