# Home service robot

## Home Service function explanation:
 
- subscribe to odom topic to get the current position of the robot
- compare this position with the goal position: If robot is close enough to goal position, pick up object. 
- same for drop off position: If robot close enough to drop off position the object appears again. 
  

## For localization and navigation: pick_object.sh 

## For mapping test: run test_slam.sh to manually run the robot


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
