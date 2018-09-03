#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <lino_pid/LinoPIDConfig.h>
#include <lino_pid.h>

void callback(lino_pid::LinoPIDConfig &config, LinoPID *lino_pid) 
{
    lino_pid->msg_.p = config.p;
    lino_pid->msg_.i = config.i;
    lino_pid->msg_.d = config.d;

    ROS_INFO("P: %lf I: %lf D: %lf", lino_pid->msg_.p, lino_pid->msg_.i, lino_pid->msg_.d);
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "lino_pid");
    
    ros::NodeHandle nh, pnh("~");

    dynamic_reconfigure::Server<lino_pid::LinoPIDConfig> server;
    dynamic_reconfigure::Server<lino_pid::LinoPIDConfig>::CallbackType f;
    
    LinoPID *lino_pid = new LinoPID(nh, pnh);

    f = boost::bind(&callback, _1, lino_pid);
    server.setCallback(f);
    
    lino_pid->run();

    return 0;
}