# generated from rosidl_generator_py/resource/_idl.py.em
# with input from san_msgs:srv/GetWaypoints.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetWaypoints_Request(type):
    """Metaclass of message 'GetWaypoints_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('san_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'san_msgs.srv.GetWaypoints_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_waypoints__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_waypoints__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_waypoints__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_waypoints__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_waypoints__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetWaypoints_Request(metaclass=Metaclass_GetWaypoints_Request):
    """Message class 'GetWaypoints_Request'."""

    __slots__ = [
        '_start_node',
        '_goal_node',
        '_node_file',
    ]

    _fields_and_field_types = {
        'start_node': 'uint16',
        'goal_node': 'uint16',
        'node_file': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.start_node = kwargs.get('start_node', int())
        self.goal_node = kwargs.get('goal_node', int())
        self.node_file = kwargs.get('node_file', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.start_node != other.start_node:
            return False
        if self.goal_node != other.goal_node:
            return False
        if self.node_file != other.node_file:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start_node(self):
        """Message field 'start_node'."""
        return self._start_node

    @start_node.setter
    def start_node(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'start_node' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'start_node' field must be an unsigned integer in [0, 65535]"
        self._start_node = value

    @builtins.property
    def goal_node(self):
        """Message field 'goal_node'."""
        return self._goal_node

    @goal_node.setter
    def goal_node(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'goal_node' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'goal_node' field must be an unsigned integer in [0, 65535]"
        self._goal_node = value

    @builtins.property
    def node_file(self):
        """Message field 'node_file'."""
        return self._node_file

    @node_file.setter
    def node_file(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_file' field must be of type 'str'"
        self._node_file = value


# Import statements for member types

# Member 'node_path'
import array  # noqa: E402, I100

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetWaypoints_Response(type):
    """Metaclass of message 'GetWaypoints_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('san_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'san_msgs.srv.GetWaypoints_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_waypoints__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_waypoints__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_waypoints__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_waypoints__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_waypoints__response

            from geometry_msgs.msg import PoseArray
            if PoseArray.__class__._TYPE_SUPPORT is None:
                PoseArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetWaypoints_Response(metaclass=Metaclass_GetWaypoints_Response):
    """Message class 'GetWaypoints_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_waypoints',
        '_node_path',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'waypoints': 'geometry_msgs/PoseArray',
        'node_path': 'sequence<uint16>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseArray'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint16')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        from geometry_msgs.msg import PoseArray
        self.waypoints = kwargs.get('waypoints', PoseArray())
        self.node_path = array.array('H', kwargs.get('node_path', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.waypoints != other.waypoints:
            return False
        if self.node_path != other.node_path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def waypoints(self):
        """Message field 'waypoints'."""
        return self._waypoints

    @waypoints.setter
    def waypoints(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseArray
            assert \
                isinstance(value, PoseArray), \
                "The 'waypoints' field must be a sub message of type 'PoseArray'"
        self._waypoints = value

    @builtins.property
    def node_path(self):
        """Message field 'node_path'."""
        return self._node_path

    @node_path.setter
    def node_path(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'H', \
                "The 'node_path' array.array() must have the type code of 'H'"
            self._node_path = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'node_path' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._node_path = array.array('H', value)


class Metaclass_GetWaypoints(type):
    """Metaclass of service 'GetWaypoints'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('san_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'san_msgs.srv.GetWaypoints')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_waypoints

            from san_msgs.srv import _get_waypoints
            if _get_waypoints.Metaclass_GetWaypoints_Request._TYPE_SUPPORT is None:
                _get_waypoints.Metaclass_GetWaypoints_Request.__import_type_support__()
            if _get_waypoints.Metaclass_GetWaypoints_Response._TYPE_SUPPORT is None:
                _get_waypoints.Metaclass_GetWaypoints_Response.__import_type_support__()


class GetWaypoints(metaclass=Metaclass_GetWaypoints):
    from san_msgs.srv._get_waypoints import GetWaypoints_Request as Request
    from san_msgs.srv._get_waypoints import GetWaypoints_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
