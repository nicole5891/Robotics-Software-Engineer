#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <cmath>

double pickupX = -1.0;
double pickupY = -1.0;
double dropoffX = -2.0;
double dropoffY = -3.0;
bool robotAtPickUp = false;
bool robotAtDropOff = false;
double deltaPos = 0.6;
double distanceToPickUp;
double distanceToDropOff;
double robot_x;
double robot_y;

void get_current_odometry_pose(const nav_msgs::Odometry::ConstPtr& msg_position)
{
  robot_x = msg_position->pose.pose.position.x;
  robot_y = msg_position->pose.pose.position.y;

  if ((robotAtPickUp == false) && (robotAtDropOff == false))
  {
    distanceToPickUp = sqrt(pow((pickupX - robot_x), 2) + pow((pickupY - robot_y), 2));
    ROS_INFO("Distance to pickup = %f", distanceToPickUp);
    if (distanceToPickUp < deltaPos){
      ROS_INFO("Robot reached pick-up point");
      robotAtPickUp = true;
    }
  }
  if ((robotAtPickUp == true) && (robotAtDropOff == false))
  { 
    ROS_INFO("Robot driving to drop-off point");
    distanceToDropOff = sqrt(pow((dropoffX - robot_x), 2) + pow((dropoffY - robot_y), 2));
    if (distanceToDropOff < deltaPos){
      ROS_INFO("Robot reached drop-off point");
      robotAtDropOff = true;
    }
  }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  ros::Subscriber odometry_sub = n.subscribe("/odom", 1000, get_current_odometry_pose);

    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickupX;
    marker.pose.position.y = pickupX;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

  while (ros::ok())
  {
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    if(robotAtPickUp == true) 
    {
      // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker.action = visualization_msgs::Marker::DELETE;
      ROS_INFO("Pickerd up!");
      ros::Duration(2.0).sleep();
    }
    if(robotAtDropOff == true) 
    {
      marker.pose.position.x = dropoffX;
      marker.pose.position.y = dropoffY;
      // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
      marker.action = visualization_msgs::Marker::ADD;
      ROS_INFO("Dropped-off up!");
      ros::Duration(2.0).sleep();
    }
    marker_pub.publish(marker);
    ros::spinOnce();
  }
}