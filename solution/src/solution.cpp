#include <iostream>
#include <solution.h>

node::node(ros::NodeHandle *nh, ros::NodeHandle *nh2) {
    if (nh2->hasParam("/solution/node_rate")) {
        nh2->getParam("/solution/node_rate", _publish_freq);
    } else {
        nh2->setParam("/solution/node_rate", 10);
        ROS_WARN("RATE PARAM NOT FOUND setting Rate : %f", _publish_freq);
    }

    ROS_INFO("Rate : %f", _publish_freq);
    toggle_srv = nh->advertiseService("toggle", &node::toggle_callback, this);
    _pub = nh2->advertise<std_msgs::Float64>("/pub", 1000);
}
// service callback to start and stop publisher
bool node::toggle_callback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {
  if (req.data) {
    _toggle_pub = 1;
    ROS_INFO_STREAM("Publishing data : TRUE");
  } else {
    _toggle_pub = 0;
    ROS_INFO_STREAM("Publishing data : FALSE");
  }
  res.success = true;
  return true;
}
// main loop which publishes data over topic /pub
void node::run() {
    ros::Rate rate(_publish_freq);
    while (ros::ok()) {
        toggle_publisher();
        ros::spinOnce();
        rate.sleep();
    }
}
void node::toggle_publisher() {
    if (_toggle_pub) {
        std_msgs::Float64 new_msg;
        float x = (float)rand()/(float)(RAND_MAX/1);
        new_msg.data = x;
        _pub.publish(new_msg);
    }
}