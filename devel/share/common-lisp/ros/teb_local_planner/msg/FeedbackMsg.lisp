; Auto-generated. Do not edit!


(cl:in-package teb_local_planner-msg)


;//! \htmlinclude FeedbackMsg.msg.html

(cl:defclass <FeedbackMsg> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (trajectories
    :reader trajectories
    :initarg :trajectories
    :type (cl:vector teb_local_planner-msg:TrajectoryMsg)
   :initform (cl:make-array 0 :element-type 'teb_local_planner-msg:TrajectoryMsg :initial-element (cl:make-instance 'teb_local_planner-msg:TrajectoryMsg)))
   (selected_trajectory_idx
    :reader selected_trajectory_idx
    :initarg :selected_trajectory_idx
    :type cl:fixnum
    :initform 0)
   (obstacles
    :reader obstacles
    :initarg :obstacles
    :type (cl:vector geometry_msgs-msg:PolygonStamped)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:PolygonStamped :initial-element (cl:make-instance 'geometry_msgs-msg:PolygonStamped))))
)

(cl:defclass FeedbackMsg (<FeedbackMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FeedbackMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FeedbackMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name teb_local_planner-msg:<FeedbackMsg> is deprecated: use teb_local_planner-msg:FeedbackMsg instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <FeedbackMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader teb_local_planner-msg:header-val is deprecated.  Use teb_local_planner-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'trajectories-val :lambda-list '(m))
(cl:defmethod trajectories-val ((m <FeedbackMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader teb_local_planner-msg:trajectories-val is deprecated.  Use teb_local_planner-msg:trajectories instead.")
  (trajectories m))

(cl:ensure-generic-function 'selected_trajectory_idx-val :lambda-list '(m))
(cl:defmethod selected_trajectory_idx-val ((m <FeedbackMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader teb_local_planner-msg:selected_trajectory_idx-val is deprecated.  Use teb_local_planner-msg:selected_trajectory_idx instead.")
  (selected_trajectory_idx m))

(cl:ensure-generic-function 'obstacles-val :lambda-list '(m))
(cl:defmethod obstacles-val ((m <FeedbackMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader teb_local_planner-msg:obstacles-val is deprecated.  Use teb_local_planner-msg:obstacles instead.")
  (obstacles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FeedbackMsg>) ostream)
  "Serializes a message object of type '<FeedbackMsg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'trajectories))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'trajectories))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'selected_trajectory_idx)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'selected_trajectory_idx)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'obstacles))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'obstacles))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FeedbackMsg>) istream)
  "Deserializes a message object of type '<FeedbackMsg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'trajectories) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'trajectories)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'teb_local_planner-msg:TrajectoryMsg))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'selected_trajectory_idx)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'selected_trajectory_idx)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'obstacles) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'obstacles)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:PolygonStamped))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FeedbackMsg>)))
  "Returns string type for a message object of type '<FeedbackMsg>"
  "teb_local_planner/FeedbackMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FeedbackMsg)))
  "Returns string type for a message object of type 'FeedbackMsg"
  "teb_local_planner/FeedbackMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FeedbackMsg>)))
  "Returns md5sum for a message object of type '<FeedbackMsg>"
  "f0ca746a67d34e8b00ad2e5fcd06d909")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FeedbackMsg)))
  "Returns md5sum for a message object of type 'FeedbackMsg"
  "f0ca746a67d34e8b00ad2e5fcd06d909")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FeedbackMsg>)))
  "Returns full string definition for message of type '<FeedbackMsg>"
  (cl:format cl:nil "# Message that contains intermediate results ~%# and diagnostics of the (predictive) planner.~%~%std_msgs/Header header~%~%# The planned trajectory (or if multiple plans exist, all of them)~%teb_local_planner/TrajectoryMsg[] trajectories~%~%# Index of the trajectory in 'trajectories' that is selected currently~%uint16 selected_trajectory_idx~%~%# List of active obstacles~%geometry_msgs/PolygonStamped[] obstacles~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: teb_local_planner/TrajectoryMsg~%# Message that contains a trajectory for mobile robot navigation~%~%std_msgs/Header header~%teb_local_planner/TrajectoryPointMsg[] trajectory~%~%~%~%================================================================================~%MSG: teb_local_planner/TrajectoryPointMsg~%# Message that contains single point on a trajectory suited for mobile navigation.~%# The trajectory is described by a sequence of poses, velocities,~%# accelerations and temporal information.~%~%# Why this message type?~%# nav_msgs/Path describes only a path without temporal information.~%# trajectory_msgs package contains only messages for joint trajectories.~%~%# The pose of the robot~%geometry_msgs/Pose pose~%~%# Corresponding velocity~%geometry_msgs/Twist velocity~%~%# Corresponding acceleration~%geometry_msgs/Twist acceleration~%~%duration time_from_start~%~%~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/PolygonStamped~%# This represents a Polygon with reference coordinate frame and timestamp~%Header header~%Polygon polygon~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FeedbackMsg)))
  "Returns full string definition for message of type 'FeedbackMsg"
  (cl:format cl:nil "# Message that contains intermediate results ~%# and diagnostics of the (predictive) planner.~%~%std_msgs/Header header~%~%# The planned trajectory (or if multiple plans exist, all of them)~%teb_local_planner/TrajectoryMsg[] trajectories~%~%# Index of the trajectory in 'trajectories' that is selected currently~%uint16 selected_trajectory_idx~%~%# List of active obstacles~%geometry_msgs/PolygonStamped[] obstacles~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: teb_local_planner/TrajectoryMsg~%# Message that contains a trajectory for mobile robot navigation~%~%std_msgs/Header header~%teb_local_planner/TrajectoryPointMsg[] trajectory~%~%~%~%================================================================================~%MSG: teb_local_planner/TrajectoryPointMsg~%# Message that contains single point on a trajectory suited for mobile navigation.~%# The trajectory is described by a sequence of poses, velocities,~%# accelerations and temporal information.~%~%# Why this message type?~%# nav_msgs/Path describes only a path without temporal information.~%# trajectory_msgs package contains only messages for joint trajectories.~%~%# The pose of the robot~%geometry_msgs/Pose pose~%~%# Corresponding velocity~%geometry_msgs/Twist velocity~%~%# Corresponding acceleration~%geometry_msgs/Twist acceleration~%~%duration time_from_start~%~%~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/PolygonStamped~%# This represents a Polygon with reference coordinate frame and timestamp~%Header header~%Polygon polygon~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FeedbackMsg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'trajectories) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     2
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'obstacles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FeedbackMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'FeedbackMsg
    (cl:cons ':header (header msg))
    (cl:cons ':trajectories (trajectories msg))
    (cl:cons ':selected_trajectory_idx (selected_trajectory_idx msg))
    (cl:cons ':obstacles (obstacles msg))
))
