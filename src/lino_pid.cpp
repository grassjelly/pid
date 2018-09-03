#include "lino_pid.h"

LinoPID::LinoPID(ros::NodeHandle nh, ros::NodeHandle pnh):
    nh_(nh),
    pnh_(pnh)
{
    msg_.p = 0.6;
    msg_.i = 0.5;
    msg_.d = 0.3;

    pid_publisher_ = nh_.advertise<lino_msgs::PID>("pid", 10);
}

void LinoPID::publishPID()
{
    pid_publisher_.publish(msg_);
}

void LinoPID::run()
{
    ros::Rate r(2);

    while (nh_.ok())
    {
        publishPID();
        ros::spinOnce();
        r.sleep();
    }
}