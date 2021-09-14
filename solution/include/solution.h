// Header file defines class parameters
#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <std_srvs/SetBool.h>

class node {
 private:
  double _publish_freq;
  ros::Publisher _pub;
  ros::ServiceServer toggle_srv;
  bool _publish_state;  // true = start publish ; false = stop publish
 public:
  node(ros::NodeHandle *nh, ros::NodeHandle *nh2);
  node() {
      set_publish_state(false);
  }
  bool toggle_callback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
  void toggle_publisher();
  void run();
  bool get_publish_state();
  void set_publish_state(bool state);
};

#endif  // SOLUTION_H
