# Home service robot

## Home Service function explanation:
 
- subscribe to odom topic to get the current position of the robot
- compare this position with the goal position: If robot is close enough to goal position, pick up object. 
- same for drop off position: If robot close enough to drop off position the object appears again. 
  

## For localization and navigation: pick_object.sh 

## For mapping test: run test_slam.sh to manually run the robot


## Official ROS packages
Import these packages now and install them in the src directory of your catkin workspace. Be sure to clone the full GitHub directory and not just the package itself.

- gmapping: With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
- turtlebot_teleop: With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
- turtlebot_rviz_launchers: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
- turtlebot_gazebo: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.

## Your Packages and Directories
You’ll install these packages and create the directories as you go through the project.
 
- map: Inside this directory, you will store your gazebo world file and the map generated from SLAM.
- scripts: Inside this directory, you’ll store your shell scripts.
- rvizConfig: Inside this directory, you’ll store your customized rviz configuration files.
- pick_objects: You will write a node that commands your robot to drive to the pickup and drop off zones.
- add_markers: You will write a node that model the object with a marker in rviz.


## File struction  
    ├──                                # Official ROS packages  
    |  
    ├── slam_gmapping                  # gmapping_demo.launch file                     
    │   ├── gmapping  
    │   ├── ...  
    ├── turtlebot                      # keyboard_teleop.launch file  
    │   ├── turtlebot_teleop  
    │   ├── ...  
    ├── turtlebot_interactions         # view_navigation.launch file        
    │   ├── turtlebot_rviz_launchers  
    │   ├── ...  
    ├── turtlebot_simulator            # turtlebot_world.launch file   
    │   ├── turtlebot_gazebo  
    │   ├── ...  
    |  
    ├── map                            # map files  
    │   ├── ...  
    ├── scripts                        # shell scripts files  
    │   ├── ...  
    ├──pick_objects                    # pick_objects C++ node  
    │   ├── src/pick_objects.cpp  
    │   ├── ...  
    ├──add_markers                     # add_marker C++ node  
    │   ├── src/add_markers.cpp  
    │   ├── ...  
    └──  


## Build and Launch

1. Clone the project and initialize a catkin workspace
```
$ mkdir catkin_ws && cd catkin_ws
$ git clone https://github.com/nicole5891/Robotics-Software-Engineer
$ cd src && catkin_init_workspace
```

2. Navigate back to the catkin_ws folder and build the project
```
$ cd ..
$ catkin_make
```

3. Run the home_service script to launch
```
$ source devel/setup.bash
$ chmod u+x ./src/scripts/home_service.sh
$ ./src/scripts/home_service.sh
```
