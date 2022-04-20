/* Task 2
   Subscriber Node
*/

//including all the neccessary libraries
#include "ros/ros.h"                   //for ROS
#include "std_msgs/String.h"           //For string messages
#include <sstream>                     //For making Stringstream objects

void chatterCallback(const std_msgs::String::ConstPtr& msg)  //Function that is called on recieving a message
{
  ROS_INFO(" Subscriber node %s", msg->data.c_str());  //Printing that message in console
}

int main(int argc, char **argv)         //Main function
{
    
  ros::init(argc, argv, "listener");    //Initiates node
  ros::NodeHandle n;                    //Node identifier
  ros::Subscriber sub = n.subscribe("/team_abhiyaan", 1000, chatterCallback);  
  //Subscribes to the topic /team_abhiyaan and the callback function is called
  ros::spin(); //Puts the calls the callback function in loop
  return 0;
}
