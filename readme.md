# Base Controller

## Facultad de Ingenieria del Ejercito

Paquete ROS que toma como input de un nodo sensor_msgs/LaserScan, busca el Range minimo del array float 32 ranges del mismo y lo compara con una constante para avisar en el topico "obstacle" si hay obstaculos.

### Requisitos

* ROS Melodic
* Alguna fuente de sensor_msgs/LaserScan

### Instalacion

```bash
cd ~/catkin_ws/src
git clone https://github.com/carlosmgc2003/urg_collision_prevent.git
cd ..
catkin_make -DCATKIN_WHITELIST_PACKAGES="urg_collision_prevent"

```

### Utilizacion
Iniciar los driver de VESC y Direction.
```bash
rosrun urg_collision_prevent urg_collision_prevent_node _min_dist:=0.7
```
