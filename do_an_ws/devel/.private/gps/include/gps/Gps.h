// Generated by gencpp from file gps/Gps.msg
// DO NOT EDIT!


#ifndef GPS_MESSAGE_GPS_H
#define GPS_MESSAGE_GPS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gps
{
template <class ContainerAllocator>
struct Gps_
{
  typedef Gps_<ContainerAllocator> Type;

  Gps_()
    : latitude(0.0)
    , longitude(0.0)  {
    }
  Gps_(const ContainerAllocator& _alloc)
    : latitude(0.0)
    , longitude(0.0)  {
  (void)_alloc;
    }



   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;





  typedef boost::shared_ptr< ::gps::Gps_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gps::Gps_<ContainerAllocator> const> ConstPtr;

}; // struct Gps_

typedef ::gps::Gps_<std::allocator<void> > Gps;

typedef boost::shared_ptr< ::gps::Gps > GpsPtr;
typedef boost::shared_ptr< ::gps::Gps const> GpsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gps::Gps_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gps::Gps_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::gps::Gps_<ContainerAllocator1> & lhs, const ::gps::Gps_<ContainerAllocator2> & rhs)
{
  return lhs.latitude == rhs.latitude &&
    lhs.longitude == rhs.longitude;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::gps::Gps_<ContainerAllocator1> & lhs, const ::gps::Gps_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace gps

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::gps::Gps_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gps::Gps_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gps::Gps_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gps::Gps_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gps::Gps_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gps::Gps_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gps::Gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "680c6dc7da65a2421a822205dcbdb600";
  }

  static const char* value(const ::gps::Gps_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x680c6dc7da65a242ULL;
  static const uint64_t static_value2 = 0x1a822205dcbdb600ULL;
};

template<class ContainerAllocator>
struct DataType< ::gps::Gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gps/Gps";
  }

  static const char* value(const ::gps::Gps_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gps::Gps_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 latitude\n"
"float64 longitude\n"
;
  }

  static const char* value(const ::gps::Gps_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gps::Gps_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.latitude);
      stream.next(m.longitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Gps_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gps::Gps_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gps::Gps_<ContainerAllocator>& v)
  {
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GPS_MESSAGE_GPS_H
