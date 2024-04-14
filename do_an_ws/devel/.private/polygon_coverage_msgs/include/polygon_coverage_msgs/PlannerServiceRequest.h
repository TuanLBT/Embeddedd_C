// Generated by gencpp from file polygon_coverage_msgs/PlannerServiceRequest.msg
// DO NOT EDIT!


#ifndef POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H
#define POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseStamped.h>

namespace polygon_coverage_msgs
{
template <class ContainerAllocator>
struct PlannerServiceRequest_
{
  typedef PlannerServiceRequest_<ContainerAllocator> Type;

  PlannerServiceRequest_()
    : start_pose()
    , goal_pose()  {
    }
  PlannerServiceRequest_(const ContainerAllocator& _alloc)
    : start_pose(_alloc)
    , goal_pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _start_pose_type;
  _start_pose_type start_pose;

   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _goal_pose_type;
  _goal_pose_type goal_pose;





  typedef boost::shared_ptr< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PlannerServiceRequest_

typedef ::polygon_coverage_msgs::PlannerServiceRequest_<std::allocator<void> > PlannerServiceRequest;

typedef boost::shared_ptr< ::polygon_coverage_msgs::PlannerServiceRequest > PlannerServiceRequestPtr;
typedef boost::shared_ptr< ::polygon_coverage_msgs::PlannerServiceRequest const> PlannerServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator1> & lhs, const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.start_pose == rhs.start_pose &&
    lhs.goal_pose == rhs.goal_pose;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator1> & lhs, const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace polygon_coverage_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ccb37d0f7296f141cce9c011c27d07ac";
  }

  static const char* value(const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xccb37d0f7296f141ULL;
  static const uint64_t static_value2 = 0xcce9c011c27d07acULL;
};

template<class ContainerAllocator>
struct DataType< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "polygon_coverage_msgs/PlannerServiceRequest";
  }

  static const char* value(const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#request fields\n"
"geometry_msgs/PoseStamped start_pose #start pose for the planner\n"
"geometry_msgs/PoseStamped goal_pose #start pose for the planner\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.start_pose);
      stream.next(m.goal_pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PlannerServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::polygon_coverage_msgs::PlannerServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "start_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.start_pose);
    s << indent << "goal_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H
