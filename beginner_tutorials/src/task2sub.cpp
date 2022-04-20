/*Task 2 
  Reverse string publisher
*/


//including all libraries
#include "ros/ros.h"          //for ROS
#include "std_msgs/String.h"  //For string messages
#include <sstream>            //For making Stringstream objects
#include <bits/stdc++.h>      //general c++ library



void chatterCallback(const std_msgs::String::ConstPtr& msg );

int main(int argc, char **argv)                 //main function
{
  ros::init(argc, argv, "listener");            //initiates node
  ros::NodeHandle n;                            //node identifier
  
  //subscribes to the topic /team_abhiyaan and calls the callback function onreceiving messages
  ros::Subscriber sub = n.subscribe("/team_abhiyaan", 1000, chatterCallback);  
  
  ros::spin();                                  //Puts the calls the callback function in loop
  return 0;
 }
 
  void chatterCallback(const std_msgs::String::ConstPtr& msg )
{
  ROS_INFO("%s", msg->data.c_str());
  
  
  ros::NodeHandle n;                             //node identifier
  
  //Telling the master node that we are publishing a message in topic /team_abhiyaan
  ros::Publisher chatter_pub1 = n.advertise<std_msgs::String>("/naayihba_maet", 1000);
  ros::Rate loop_rate(10);                       //for publishing messages at frequency of 10hz
  
  while (ros::ok())
  {
    std_msgs::String msg1;                       //String message
    std::stringstream ss;                        //Stringstream object
    std::string rev = msg->data.c_str();         //rev - messsage that is to be reversed
       
    int length = rev.length();
    
    
   /*Reversing the string
   
   To reverse each word of the string , we first split the message with ' '(space) as the delimmiter
   
   Initial - index of 1st letter of the word
   
    */ 
    int initial = 0;                              
  
    for(int j =0;j<length;j++){                        
     if(rev[j]==' ' or j==length-1){                         //if (j+1)th character is space or if it is the last character
      
      std::string x = rev.substr(initial,j-initial+1);       //getting the substring(word)
      reverse(x.begin(), x.end());                           //reversing the word
     if(j==length-1){                                        //checks if end of character is reached
      ss<<" ";
    }
      ss<<x;                                                 //adding the word to the stringstream
      initial = j+1;                                         //Initial position of the next word
  }
  }
    msg1.data = ss.str();

    ROS_INFO("%s", msg1.data.c_str());                       //printing the message in console    
    chatter_pub1.publish(msg1);                              //publishing the message 

    ros::spinOnce();
    loop_rate.sleep(); 
   
  }
} 


