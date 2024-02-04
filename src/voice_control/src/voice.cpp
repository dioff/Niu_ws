#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


void callback(const std_msgs::String::ConstPtr& msg)
{
    if (msg->data == "1")
    {
        // 创建ROS节点句柄
        ros::NodeHandle nh;
        ROS_INFO("111");
        // 创建一个Publisher，发布turtle1/cmd_vel话题
        ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

        // 创建一个Twist消息并设置速度
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 1.0; // 设置线速度为1.0 m/s
        vel_msg.angular.z = 1.0;

        // 发布速度消息
        while (ros::ok())
        {
            vel_pub.publish(vel_msg);
        }
    }
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "turtle_subscriber");

    // 创建ROS节点句柄
    ros::NodeHandle nh;
    // 创建一个Subscriber，订阅/xfspeech话题
    ros::Subscriber sub = nh.subscribe("xfspeech", 10, callback);

    // 循环等待消息
    ros::spin();

    return 0;
}
