#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "geometry_msgs/Twist.h"

geometry_msgs::Twist msg_track;
geometry_msgs::Twist msg_turret;

void joyCallback(const sensor_msgs::Joy& msg)
{
    msg_track.linear.x = -msg.axes[1];
    msg_track.angular.z = msg.axes[0];

    msg_turret.angular.y = -msg.axes[5];
    msg_turret.angular.z =  msg.axes[2];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "joy_to_msgs");
    ros::NodeHandle n;

    ros::Subscriber joy_sub = n.subscribe("joy", 1000, joyCallback);

    ros::Publisher track_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    ros::Publisher turret_pub = n.advertise<geometry_msgs::Twist>("cmd_turret", 1000);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        //std::stringstream ss;

        track_pub.publish(msg_track);
        turret_pub.publish(msg_turret);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
