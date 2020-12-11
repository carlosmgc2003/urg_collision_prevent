#include "../include/urg_collision_prevent.hpp"

UrgSimpleListener::UrgSimpleListener() {
    // Manejador del nodo
    n = ros::NodeHandle();
    // Instancia para acceder a los parametros
    private_n = ros::NodeHandle("~");

    // Inicializacion de las subscripciones
    lidar = n.subscribe<sensor_msgs::LaserScan>("scan", 10, &UrgSimpleListener::lidarMsgCallback, this);

    // Inicializacion de los publicadores
    obstacle = n.advertise<std_msgs::Int32>("obstacle", 10);

    // Inicializacion de las variables de estado
    this->msgObstacle.data = 0;
}

void UrgSimpleListener::lidarMsgCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    this->msgObstacle.data = 0;
    float minDist = msg->range_max;
    for(auto dist: msg->ranges){
        if(dist < minDist){
            minDist = dist;
        }
    }
    ROS_INFO("Distancia Minima %.2d", minDist);
    if(minDist < MIN_DIST){
        this->msgObstacle.data = 1;
    }
    obstacle.publish(msgObstacle);
}

int main(int argc, char **argv) {
    ros::init(argc,argv,"base_controller");
    UrgSimpleListener USL = UrgSimpleListener();
    ros::spin();
    return 0;
}