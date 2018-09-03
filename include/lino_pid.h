#ifndef LINO_PID_H
#define LINO_PID_H

#include <ros/ros.h>
#include <lino_msgs/PID.h>

class LinoPID
{
public:
    LinoPID(ros::NodeHandle nh, ros::NodeHandle pnh);
    void publishPID();
    void run();

    lino_msgs::PID msg_;

private:
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    ros::Publisher pid_publisher_;
};
#endif