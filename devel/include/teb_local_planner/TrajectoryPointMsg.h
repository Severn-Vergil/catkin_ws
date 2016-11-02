// Generated by gencpp from file teb_local_planner/TrajectoryPointMsg.msg
// DO NOT EDIT!


#ifndef TEB_LOCAL_PLANNER_MESSAGE_TRAJECTORYPOINTMSG_H
#define TEB_LOCAL_PLANNER_MESSAGE_TRAJECTORYPOINTMSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>

namespace teb_local_planner
{
template <class ContainerAllocator>
struct TrajectoryPointMsg_
{
  typedef TrajectoryPointMsg_<ContainerAllocator> Type;

  TrajectoryPointMsg_()
    : pose()
    , velocity()
    , acceleration()
    , time_from_start()  {
    }
  TrajectoryPointMsg_(const ContainerAllocator& _alloc)
    : pose(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)
    , time_from_start()  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef ros::Duration _time_from_start_type;
  _time_from_start_type time_from_start;




  typedef boost::shared_ptr< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> const> ConstPtr;

}; // struct TrajectoryPointMsg_

typedef ::teb_local_planner::TrajectoryPointMsg_<std::allocator<void> > TrajectoryPointMsg;

typedef boost::shared_ptr< ::teb_local_planner::TrajectoryPointMsg > TrajectoryPointMsgPtr;
typedef boost::shared_ptr< ::teb_local_planner::TrajectoryPointMsg const> TrajectoryPointMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace teb_local_planner

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'teb_local_planner': ['/home/rabot/catkin_ws/src/teb_local_planner/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4c309845772249e786605716950755c3";
  }

  static const char* value(const ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4c309845772249e7ULL;
  static const uint64_t static_value2 = 0x86605716950755c3ULL;
};

template<class ContainerAllocator>
struct DataType< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "teb_local_planner/TrajectoryPointMsg";
  }

  static const char* value(const ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Message that contains single point on a trajectory suited for mobile navigation.\n\
# The trajectory is described by a sequence of poses, velocities,\n\
# accelerations and temporal information.\n\
\n\
# Why this message type?\n\
# nav_msgs/Path describes only a path without temporal information.\n\
# trajectory_msgs package contains only messages for joint trajectories.\n\
\n\
# The pose of the robot\n\
geometry_msgs/Pose pose\n\
\n\
# Corresponding velocity\n\
geometry_msgs/Twist velocity\n\
\n\
# Corresponding acceleration\n\
geometry_msgs/Twist acceleration\n\
\n\
duration time_from_start\n\
\n\
\n\
\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/Twist\n\
# This expresses velocity in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.time_from_start);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TrajectoryPointMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::teb_local_planner::TrajectoryPointMsg_<ContainerAllocator>& v)
  {
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "time_from_start: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.time_from_start);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEB_LOCAL_PLANNER_MESSAGE_TRAJECTORYPOINTMSG_H
