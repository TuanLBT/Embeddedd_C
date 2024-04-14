# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from polygon_coverage_msgs/PlannerServiceRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import std_msgs.msg

class PlannerServiceRequest(genpy.Message):
  _md5sum = "ccb37d0f7296f141cce9c011c27d07ac"
  _type = "polygon_coverage_msgs/PlannerServiceRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#request fields
geometry_msgs/PoseStamped start_pose #start pose for the planner
geometry_msgs/PoseStamped goal_pose #start pose for the planner

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
"""
  __slots__ = ['start_pose','goal_pose']
  _slot_types = ['geometry_msgs/PoseStamped','geometry_msgs/PoseStamped']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       start_pose,goal_pose

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlannerServiceRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.start_pose is None:
        self.start_pose = geometry_msgs.msg.PoseStamped()
      if self.goal_pose is None:
        self.goal_pose = geometry_msgs.msg.PoseStamped()
    else:
      self.start_pose = geometry_msgs.msg.PoseStamped()
      self.goal_pose = geometry_msgs.msg.PoseStamped()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.start_pose.header.seq, _x.start_pose.header.stamp.secs, _x.start_pose.header.stamp.nsecs))
      _x = self.start_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.start_pose.pose.position.x, _x.start_pose.pose.position.y, _x.start_pose.pose.position.z, _x.start_pose.pose.orientation.x, _x.start_pose.pose.orientation.y, _x.start_pose.pose.orientation.z, _x.start_pose.pose.orientation.w, _x.goal_pose.header.seq, _x.goal_pose.header.stamp.secs, _x.goal_pose.header.stamp.nsecs))
      _x = self.goal_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d().pack(_x.goal_pose.pose.position.x, _x.goal_pose.pose.position.y, _x.goal_pose.pose.position.z, _x.goal_pose.pose.orientation.x, _x.goal_pose.pose.orientation.y, _x.goal_pose.pose.orientation.z, _x.goal_pose.pose.orientation.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.start_pose is None:
        self.start_pose = geometry_msgs.msg.PoseStamped()
      if self.goal_pose is None:
        self.goal_pose = geometry_msgs.msg.PoseStamped()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.start_pose.header.seq, _x.start_pose.header.stamp.secs, _x.start_pose.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.start_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.start_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.start_pose.pose.position.x, _x.start_pose.pose.position.y, _x.start_pose.pose.position.z, _x.start_pose.pose.orientation.x, _x.start_pose.pose.orientation.y, _x.start_pose.pose.orientation.z, _x.start_pose.pose.orientation.w, _x.goal_pose.header.seq, _x.goal_pose.header.stamp.secs, _x.goal_pose.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.goal_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.goal_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.goal_pose.pose.position.x, _x.goal_pose.pose.position.y, _x.goal_pose.pose.position.z, _x.goal_pose.pose.orientation.x, _x.goal_pose.pose.orientation.y, _x.goal_pose.pose.orientation.z, _x.goal_pose.pose.orientation.w,) = _get_struct_7d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.start_pose.header.seq, _x.start_pose.header.stamp.secs, _x.start_pose.header.stamp.nsecs))
      _x = self.start_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.start_pose.pose.position.x, _x.start_pose.pose.position.y, _x.start_pose.pose.position.z, _x.start_pose.pose.orientation.x, _x.start_pose.pose.orientation.y, _x.start_pose.pose.orientation.z, _x.start_pose.pose.orientation.w, _x.goal_pose.header.seq, _x.goal_pose.header.stamp.secs, _x.goal_pose.header.stamp.nsecs))
      _x = self.goal_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_7d().pack(_x.goal_pose.pose.position.x, _x.goal_pose.pose.position.y, _x.goal_pose.pose.position.z, _x.goal_pose.pose.orientation.x, _x.goal_pose.pose.orientation.y, _x.goal_pose.pose.orientation.z, _x.goal_pose.pose.orientation.w))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.start_pose is None:
        self.start_pose = geometry_msgs.msg.PoseStamped()
      if self.goal_pose is None:
        self.goal_pose = geometry_msgs.msg.PoseStamped()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.start_pose.header.seq, _x.start_pose.header.stamp.secs, _x.start_pose.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.start_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.start_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.start_pose.pose.position.x, _x.start_pose.pose.position.y, _x.start_pose.pose.position.z, _x.start_pose.pose.orientation.x, _x.start_pose.pose.orientation.y, _x.start_pose.pose.orientation.z, _x.start_pose.pose.orientation.w, _x.goal_pose.header.seq, _x.goal_pose.header.stamp.secs, _x.goal_pose.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.goal_pose.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.goal_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 56
      (_x.goal_pose.pose.position.x, _x.goal_pose.pose.position.y, _x.goal_pose.pose.position.z, _x.goal_pose.pose.orientation.x, _x.goal_pose.pose.orientation.y, _x.goal_pose.pose.orientation.z, _x.goal_pose.pose.orientation.w,) = _get_struct_7d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_7d = None
def _get_struct_7d():
    global _struct_7d
    if _struct_7d is None:
        _struct_7d = struct.Struct("<7d")
    return _struct_7d
_struct_7d3I = None
def _get_struct_7d3I():
    global _struct_7d3I
    if _struct_7d3I is None:
        _struct_7d3I = struct.Struct("<7d3I")
    return _struct_7d3I
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from polygon_coverage_msgs/PlannerServiceResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy
import geometry_msgs.msg
import std_msgs.msg
import trajectory_msgs.msg

class PlannerServiceResponse(genpy.Message):
  _md5sum = "24e3de4f64c1b40cb092bff3f0d22c55"
  _type = "polygon_coverage_msgs/PlannerServiceResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# True on success, false on planning failure
bool success
# Either contains a polynomial trajectory:
trajectory_msgs/MultiDOFJointTrajectory sampled_plan


================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectory
# The header is used to specify the coordinate frame and the reference time for the trajectory durations
Header header

# A representation of a multi-dof joint trajectory (each point is a transformation)
# Each point along the trajectory will include an array of positions/velocities/accelerations
# that has the same length as the array of joint names, and has the same order of joints as 
# the joint names array.

string[] joint_names
MultiDOFJointTrajectoryPoint[] points

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectoryPoint
# Each multi-dof joint can specify a transform (up to 6 DOF)
geometry_msgs/Transform[] transforms

# There can be a velocity specified for the origin of the joint 
geometry_msgs/Twist[] velocities

# There can be an acceleration specified for the origin of the joint 
geometry_msgs/Twist[] accelerations

duration time_from_start

================================================================================
MSG: geometry_msgs/Transform
# This represents the transform between two coordinate frames in free space.

Vector3 translation
Quaternion rotation

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular
"""
  __slots__ = ['success','sampled_plan']
  _slot_types = ['bool','trajectory_msgs/MultiDOFJointTrajectory']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       success,sampled_plan

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlannerServiceResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.success is None:
        self.success = False
      if self.sampled_plan is None:
        self.sampled_plan = trajectory_msgs.msg.MultiDOFJointTrajectory()
    else:
      self.success = False
      self.sampled_plan = trajectory_msgs.msg.MultiDOFJointTrajectory()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_B3I().pack(_x.success, _x.sampled_plan.header.seq, _x.sampled_plan.header.stamp.secs, _x.sampled_plan.header.stamp.nsecs))
      _x = self.sampled_plan.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.sampled_plan.joint_names)
      buff.write(_struct_I.pack(length))
      for val1 in self.sampled_plan.joint_names:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.Struct('<I%ss'%length).pack(length, val1))
      length = len(self.sampled_plan.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.sampled_plan.points:
        length = len(val1.transforms)
        buff.write(_struct_I.pack(length))
        for val2 in val1.transforms:
          _v1 = val2.translation
          _x = _v1
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v2 = val2.rotation
          _x = _v2
          buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        length = len(val1.velocities)
        buff.write(_struct_I.pack(length))
        for val2 in val1.velocities:
          _v3 = val2.linear
          _x = _v3
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v4 = val2.angular
          _x = _v4
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        length = len(val1.accelerations)
        buff.write(_struct_I.pack(length))
        for val2 in val1.accelerations:
          _v5 = val2.linear
          _x = _v5
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v6 = val2.angular
          _x = _v6
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v7 = val1.time_from_start
        _x = _v7
        buff.write(_get_struct_2i().pack(_x.secs, _x.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.sampled_plan is None:
        self.sampled_plan = trajectory_msgs.msg.MultiDOFJointTrajectory()
      end = 0
      _x = self
      start = end
      end += 13
      (_x.success, _x.sampled_plan.header.seq, _x.sampled_plan.header.stamp.secs, _x.sampled_plan.header.stamp.nsecs,) = _get_struct_B3I().unpack(str[start:end])
      self.success = bool(self.success)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.sampled_plan.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.sampled_plan.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.sampled_plan.joint_names = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1 = str[start:end]
        self.sampled_plan.joint_names.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.sampled_plan.points = []
      for i in range(0, length):
        val1 = trajectory_msgs.msg.MultiDOFJointTrajectoryPoint()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.transforms = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Transform()
          _v8 = val2.translation
          _x = _v8
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v9 = val2.rotation
          _x = _v9
          start = end
          end += 32
          (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
          val1.transforms.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.velocities = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Twist()
          _v10 = val2.linear
          _x = _v10
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v11 = val2.angular
          _x = _v11
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.velocities.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.accelerations = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Twist()
          _v12 = val2.linear
          _x = _v12
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v13 = val2.angular
          _x = _v13
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.accelerations.append(val2)
        _v14 = val1.time_from_start
        _x = _v14
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2i().unpack(str[start:end])
        self.sampled_plan.points.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_B3I().pack(_x.success, _x.sampled_plan.header.seq, _x.sampled_plan.header.stamp.secs, _x.sampled_plan.header.stamp.nsecs))
      _x = self.sampled_plan.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      length = len(self.sampled_plan.joint_names)
      buff.write(_struct_I.pack(length))
      for val1 in self.sampled_plan.joint_names:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.Struct('<I%ss'%length).pack(length, val1))
      length = len(self.sampled_plan.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.sampled_plan.points:
        length = len(val1.transforms)
        buff.write(_struct_I.pack(length))
        for val2 in val1.transforms:
          _v15 = val2.translation
          _x = _v15
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v16 = val2.rotation
          _x = _v16
          buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        length = len(val1.velocities)
        buff.write(_struct_I.pack(length))
        for val2 in val1.velocities:
          _v17 = val2.linear
          _x = _v17
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v18 = val2.angular
          _x = _v18
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        length = len(val1.accelerations)
        buff.write(_struct_I.pack(length))
        for val2 in val1.accelerations:
          _v19 = val2.linear
          _x = _v19
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _v20 = val2.angular
          _x = _v20
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v21 = val1.time_from_start
        _x = _v21
        buff.write(_get_struct_2i().pack(_x.secs, _x.nsecs))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.sampled_plan is None:
        self.sampled_plan = trajectory_msgs.msg.MultiDOFJointTrajectory()
      end = 0
      _x = self
      start = end
      end += 13
      (_x.success, _x.sampled_plan.header.seq, _x.sampled_plan.header.stamp.secs, _x.sampled_plan.header.stamp.nsecs,) = _get_struct_B3I().unpack(str[start:end])
      self.success = bool(self.success)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.sampled_plan.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.sampled_plan.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.sampled_plan.joint_names = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8', 'rosmsg')
        else:
          val1 = str[start:end]
        self.sampled_plan.joint_names.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.sampled_plan.points = []
      for i in range(0, length):
        val1 = trajectory_msgs.msg.MultiDOFJointTrajectoryPoint()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.transforms = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Transform()
          _v22 = val2.translation
          _x = _v22
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v23 = val2.rotation
          _x = _v23
          start = end
          end += 32
          (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
          val1.transforms.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.velocities = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Twist()
          _v24 = val2.linear
          _x = _v24
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v25 = val2.angular
          _x = _v25
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.velocities.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.accelerations = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Twist()
          _v26 = val2.linear
          _x = _v26
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v27 = val2.angular
          _x = _v27
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          val1.accelerations.append(val2)
        _v28 = val1.time_from_start
        _x = _v28
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2i().unpack(str[start:end])
        self.sampled_plan.points.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2i = None
def _get_struct_2i():
    global _struct_2i
    if _struct_2i is None:
        _struct_2i = struct.Struct("<2i")
    return _struct_2i
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_B3I = None
def _get_struct_B3I():
    global _struct_B3I
    if _struct_B3I is None:
        _struct_B3I = struct.Struct("<B3I")
    return _struct_B3I
class PlannerService(object):
  _type          = 'polygon_coverage_msgs/PlannerService'
  _md5sum = '041d814b74649941198af640c3963ac3'
  _request_class  = PlannerServiceRequest
  _response_class = PlannerServiceResponse
