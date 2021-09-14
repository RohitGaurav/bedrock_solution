cmake_minimum_required(VERSION 2.8.3)
project(solution)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
include_directories(${roscpp_INCLUDE_DIRS})
## Declare Library
add_library(testing
	src/solution.cpp
)
target_link_libraries(testing ${catkin_LIBRARIES})

## Generate added messages and services
##generate_messages(DEPENDENCIES std_msgs)
## Declare a catkin package
catkin_package()


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(solution src/main.cpp src/solution.cpp include/solution.h)
target_link_libraries(solution ${catkin_LIBRARIES})

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(test_node test/test_launch.test test/test.cpp)
  target_link_libraries(test_node testing ${catkin_LIBRARIES})
endif()