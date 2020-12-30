// Generated by gencpp from file rtabmap_ros/GetNodesInRadiusResponse.msg
// DO NOT EDIT!


#ifndef RTABMAP_ROS_MESSAGE_GETNODESINRADIUSRESPONSE_H
#define RTABMAP_ROS_MESSAGE_GETNODESINRADIUSRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>

namespace rtabmap_ros
{
template <class ContainerAllocator>
struct GetNodesInRadiusResponse_
{
  typedef GetNodesInRadiusResponse_<ContainerAllocator> Type;

  GetNodesInRadiusResponse_()
    : ids()
    , poses()  {
    }
  GetNodesInRadiusResponse_(const ContainerAllocator& _alloc)
    : ids(_alloc)
    , poses(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _ids_type;
  _ids_type ids;

   typedef std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  _poses_type;
  _poses_type poses;





  typedef boost::shared_ptr< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetNodesInRadiusResponse_

typedef ::rtabmap_ros::GetNodesInRadiusResponse_<std::allocator<void> > GetNodesInRadiusResponse;

typedef boost::shared_ptr< ::rtabmap_ros::GetNodesInRadiusResponse > GetNodesInRadiusResponsePtr;
typedef boost::shared_ptr< ::rtabmap_ros::GetNodesInRadiusResponse const> GetNodesInRadiusResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rtabmap_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'rtabmap_ros': ['/home/robond/workspace/Project4/catkin_ws/src/rtabmap_ros/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c482b598f970eec6229687725ccf8844";
  }

  static const char* value(const ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc482b598f970eec6ULL;
  static const uint64_t static_value2 = 0x229687725ccf8844ULL;
};

template<class ContainerAllocator>
struct DataType< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rtabmap_ros/GetNodesInRadiusResponse";
  }

  static const char* value(const ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int32[] ids\n\
geometry_msgs/Pose[] poses\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ids);
      stream.next(m.poses);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetNodesInRadiusResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rtabmap_ros::GetNodesInRadiusResponse_<ContainerAllocator>& v)
  {
    s << indent << "ids[]" << std::endl;
    for (size_t i = 0; i < v.ids.size(); ++i)
    {
      s << indent << "  ids[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.ids[i]);
    }
    s << indent << "poses[]" << std::endl;
    for (size_t i = 0; i < v.poses.size(); ++i)
    {
      s << indent << "  poses[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "    ", v.poses[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RTABMAP_ROS_MESSAGE_GETNODESINRADIUSRESPONSE_H
