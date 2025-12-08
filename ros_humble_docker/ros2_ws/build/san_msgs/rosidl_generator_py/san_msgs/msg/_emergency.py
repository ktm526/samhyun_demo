# generated from rosidl_generator_py/resource/_idl.py.em
# with input from san_msgs:msg/Emergency.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Emergency(type):
    """Metaclass of message 'Emergency'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'PHYSICAL_LAYER': 0,
        'OBSTACLE': 1,
        'LOW_BATTERY': 2,
        'REDOCKING': 3,
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
                'san_msgs.msg.Emergency')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__emergency
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__emergency
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__emergency
            cls._TYPE_SUPPORT = module.type_support_msg__msg__emergency
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__emergency

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'PHYSICAL_LAYER': cls.__constants['PHYSICAL_LAYER'],
            'OBSTACLE': cls.__constants['OBSTACLE'],
            'LOW_BATTERY': cls.__constants['LOW_BATTERY'],
            'REDOCKING': cls.__constants['REDOCKING'],
        }

    @property
    def PHYSICAL_LAYER(self):
        """Message constant 'PHYSICAL_LAYER'."""
        return Metaclass_Emergency.__constants['PHYSICAL_LAYER']

    @property
    def OBSTACLE(self):
        """Message constant 'OBSTACLE'."""
        return Metaclass_Emergency.__constants['OBSTACLE']

    @property
    def LOW_BATTERY(self):
        """Message constant 'LOW_BATTERY'."""
        return Metaclass_Emergency.__constants['LOW_BATTERY']

    @property
    def REDOCKING(self):
        """Message constant 'REDOCKING'."""
        return Metaclass_Emergency.__constants['REDOCKING']


class Emergency(metaclass=Metaclass_Emergency):
    """
    Message class 'Emergency'.

    Constants:
      PHYSICAL_LAYER
      OBSTACLE
      LOW_BATTERY
      REDOCKING
    """

    __slots__ = [
        '_emergency',
    ]

    _fields_and_field_types = {
        'emergency': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.emergency = kwargs.get('emergency', int())

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
        if self.emergency != other.emergency:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def emergency(self):
        """Message field 'emergency'."""
        return self._emergency

    @emergency.setter
    def emergency(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'emergency' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'emergency' field must be an unsigned integer in [0, 255]"
        self._emergency = value
