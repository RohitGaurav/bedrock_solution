#include "solution.h"
#include <ros/ros.h>
#include <gtest/gtest.h>

// using namespace std;

class TestSuite : public ::testing::Test {
 public:
    TestSuite() {
    }
    ~TestSuite() {}
};

TEST_F(TestSuite, default_state) {
  node n;
  bool state = n.get_publish_state();
  ASSERT_EQ(state, false) << "State should be false by default";
}

TEST_F(TestSuite, start) {
  node n;
  n.set_publish_state(true);
  bool state = n.get_publish_state();
  ASSERT_EQ(state, true) << "Value should be true";
}

TEST_F(TestSuite, stop) {
  node n;
  n.set_publish_state(false);
  bool state = n.get_publish_state();
  ASSERT_EQ(state, false) << "Value should be false";
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "test_node");
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    ros::shutdown();
    return res;
}
