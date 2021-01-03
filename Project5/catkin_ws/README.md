# Home service robot

## Write-up: Home Service function explanation:
 
- Idea: Subscribe to odom topic to get the current position of the robot. Compare this position with the goal position: If robot distance =  goal position (+-tolerance), pick up object. Same for drop off position: If robot distance = drop off position (+-tolerance) the object appears again. 

## Package Explanation

# Official ROS packages
The following four official packages are used. These packages need to be imported and installed in the src directory of the prior created catkin workspace. Be sure to clone the full GitHub directory and not just the package itself.

- slam_gmapping: This package contains a ROS wrapper for OpenSlam's Gmapping. The gmapping package provides laser-based SLAM (Simultaneous Localization and Mapping), as a ROS node called slam_gmapping. Using slam_gmapping, you can create a 2-D occupancy grid map from laser and pose data collected by a mobile robot. 
- turtlebot_rviz_launchers: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you. Within this rviz configuration a Marker is added that will be used as pick up object. 
- turtlebot_gazebo: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it. This package also includes the amcl.launch which runs the monte carlo localization. 

## Your Packages and Directories
The following packages need to be self created in the directories:
 
- scripts: Inside this directory, you’ll store your shell scripts. Shall scripts will be configured to automatically launch several ros launch files. The home_service.sh script is called to launch all files for running the robot in the world and let him pick up and drop off the object in rviz visualization. 
- config: Inside this directory, you’ll store your customized rviz configuration files (project5.rviz).
- pick_objects: You will write a navigation node that commands your robot to drive to the pickup and drop off zones. Robots inital and goal position are defined in the pick_object.cpp. 
- add_markers: You will write a node that model the object with a marker in rviz. The markers behavior; disappearing if pick up point is reached and appearing again as soon as the drop-off point is reached is defined in the add_markers.cpp. 


## File struction  
    ├──                                # Official ROS packages  
    |  
    ├── slam_gmapping                  # gmapping_demo.launch file                     
    │   ├── gmapping  
    │   ├── ...  
    ├── turtlebot_interactions         # view_navigation.launch file        
    │   ├── turtlebot_rviz_launchers  
    │   ├── ...  
    ├── turtlebot_simulator               
    │   ├── turtlebot_gazebo           # amcl_demo.launch file
    |   |                              # turtlebot_world.launch file
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

# Fruther Information:
For localization and navigation: pick_object.sh 
For mapping test: run test_slam.sh to manually run the robot
