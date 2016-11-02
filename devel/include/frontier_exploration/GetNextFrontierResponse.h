// Generated by gencpp from file frontier_exploration/GetNextFrontierResponse.msg
// DO NOT EDIT!


#ifndef FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERRESPONSE_H
#define FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERRESPONSE_H


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
struct GetNextFrontierResponse_
{
  typedef GetNextFrontierResponse_<ContainerAllocator> Type;

  GetNextFrontierResponse_()
    : next_frontier()  {
    }
  GetNextFrontierResponse_(const ContainerAllocator& _alloc)
    : next_frontier(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _next_frontier_type;
  _next_frontier_type next_frontier;




  typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetNextFrontierResponse_

typedef ::frontier_exploration::GetNextFrontierResponse_<std::allocator<void> > GetNextFrontierResponse;

typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierResponse > GetNextFrontierResponsePtr;
typedef boost::shared_ptr< ::frontier_exploration::GetNextFrontierResponse const> GetNextFrontierResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "df2ac5789785e819aa300966fa36644e";
  }

  static const char* value(const ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdf2ac5789785e819ULL;
  static const uint64_t static_value2 = 0xaa300966fa36644eULL;
};

template<class ContainerAllocator>
struct DataType< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "frontier_exploration/GetNextFrontierResponse";
  }

  static const char* value(const ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PoseStamped next_frontier\n\
\n\
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

  static const char* value(const ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.next_frontier);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetNextFrontierResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::frontier_exploration::GetNextFrontierResponse_<ContainerAllocator>& v)
  {
    s << indent << "next_frontier: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.next_frontier);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FRONTIER_EXPLORATION_MESSAGE_GETNEXTFRONTIERRESPONSE_H
