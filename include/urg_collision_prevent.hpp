#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/LaserScan.h>

const float DEFAULT_MIN_DIST = 0.3;

class UrgSimpleListener {
    ros::NodeHandle n;
    ros::NodeHandle private_n;

    // Subscriptores
    ros::Subscriber lidar;

    // Publicadores
    ros::Publisher obstacle;

    // Mensajes
    std_msgs::Int32 msgObstacle;

    //Estado
    float MIN_DIST = 0.3;

    public:
    UrgSimpleListener();
    void setMinDist();
    void lidarMsgCallback(const sensor_msgs::LaserScan::ConstPtr&);
};