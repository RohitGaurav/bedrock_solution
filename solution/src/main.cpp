#include <iostream>
#include <solution.h>
int main(int argc, char** argv) {
    ros::init(argc, argv, "solution");
    ros::NodeHandle nh, nh2;
    node node_obj(&nh, &nh2);
    node_obj.run();
    return 0;
}
