/* Task 2
   Publisher Node
*/


//include all the neccessary libraries

#include "ros/ros.h"                   //for ROS
#include "std_msgs/String.h"           //For string messages
#include <sstream>                     //For making Stringstream objects


int main(int argc, char **argv)        //Main function
{
  
  ros::init(argc, argv, "talker");     //Initiates node
  ros::NodeHandle n;                   //Node identifier

  //Telling the master node that we are publishing a message in topic /team_abhiyaan
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/team_abhiyaan", 1000);
  
  ros::Rate loop_rate(10);             //for publishing messages at frequency of 10hz
  while (ros::ok())                    //ros::ok() checks if the process is not terminated by shutdown request 
                                       //or ctrl+c
                                       
  {
    std_msgs::String msg;
    std::stringstream ss;              //Stringstream object
    ss << "Team Abhiyaan rocks";       //adding our message to the stream
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());   //prints the message in the console
    
    chatter_pub.publish(msg);           //publishes the message
    ros::spinOnce();                    //useful if callback functions are present
   loop_rate.sleep(); 
    
  }
  
  return 0;
}
