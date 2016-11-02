// Generated by gencpp from file frontier_exploration/GetNextFrontierRequest.msg
// DO NOT EDIT!


#ifndef FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERREQUEST_H
#define FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseStamped.h>

namespace frontier_exploration
{
template <class ContainerAllocator>
struct GetNextFrontierRequest_
{
  typedef GetNextFrontierRequest_<ContainerAllocator> Type;

  GetNextFrontierRequest_()
    : start_pose()  {
    }
  GetNextFrontierRequest_(const ContainerAllocator& _alloc)
    : start_pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _start_pose_type;
  _start_pose_type start_pose;




  typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetNextFrontierRequest_

typedef ::frontier_exploration::GetNextFrontierRequest_<std::allocator<void> > GetNextFrontierRequest;

typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierRequest > GetNextFrontierRequestPtr;
typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierRequest const> GetNextFrontierRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace frontier_exploration

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'frontier_exploration': ['/home/rabot/catkin_ws/src/frontier_exploration/msg', '/home/rabot/catkin_ws/devel/share/frontier_exploration/msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'visualization_msgs': ['/opt/ros/indigo/share/visualization_msgs/cmake/../msg'], 'move_base_msgs': ['/opt/ros/indigo/share/move_base_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5b059506b52a2ec83de1e33422377a1b";
  }

  static const char* value(const ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5b059506b52a2ec8ULL;
  static const uint64_t static_value2 = 0x3de1e33422377a1bULL;
};

template<class ContainerAllocator>
struct DataType< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "frontier_exploration/GetNextFrontierRequest";
  }

  static const char* value(const ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PoseStamped start_pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
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

  static const char* value(const ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.start_pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetNextFrontierRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::frontier_exploration::GetNextFrontierRequest_<ContainerAllocator>& v)
  {
    s << indent << "start_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.start_pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERREQUEST_H
