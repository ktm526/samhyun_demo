# generated from rosidl_generator_py/resource/_idl.py.em
# with input from san_msgs:msg/Behavior.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Behavior(type):
    """Metaclass of message 'Behavior'."""

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
                'san_msgs.msg.Behavior')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__behavior
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__behavior
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__behavior
            cls._TYPE_SUPPORT = module.type_support_msg__msg__behavior
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__behavior

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Behavior(metaclass=Metaclass_Behavior):
    """Message class 'Behavior'."""

    __slots__ = [
        '_behavior_auto_started',
        '_behavior_slam_started',
        '_behavior_charge_started',
        '_behavior_docking_started',
        '_behavior_undocking_started',
        '_behavior_auto_completed',
        '_behavior_slam_completed',
        '_behavior_charge_completed',
        '_behavior_docking_completed',
        '_behavior_undocking_completed',
        '_behavior_auto_canceled',
        '_behavior_docking_canceled',
        '_behavior_manipulation_redocking_triggered',
        '_behavior_charging_redocking_triggered',
        '_behavior_manipulator_completed',
        '_behavior_manipulator_emergency_triggered',
        '_behavior_manual_mode_triggered',
    ]

    _fields_and_field_types = {
        'behavior_auto_started': 'boolean',
        'behavior_slam_started': 'boolean',
        'behavior_charge_started': 'boolean',
        'behavior_docking_started': 'boolean',
        'behavior_undocking_started': 'boolean',
        'behavior_auto_completed': 'boolean',
        'behavior_slam_completed': 'boolean',
        'behavior_charge_completed': 'boolean',
        'behavior_docking_completed': 'boolean',
        'behavior_undocking_completed': 'boolean',
        'behavior_auto_canceled': 'boolean',
        'behavior_docking_canceled': 'boolean',
        'behavior_manipulation_redocking_triggered': 'boolean',
        'behavior_charging_redocking_triggered': 'boolean',
        'behavior_manipulator_completed': 'boolean',
        'behavior_manipulator_emergency_triggered': 'boolean',
        'behavior_manual_mode_triggered': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.behavior_auto_started = kwargs.get('behavior_auto_started', bool())
        self.behavior_slam_started = kwargs.get('behavior_slam_started', bool())
        self.behavior_charge_started = kwargs.get('behavior_charge_started', bool())
        self.behavior_docking_started = kwargs.get('behavior_docking_started', bool())
        self.behavior_undocking_started = kwargs.get('behavior_undocking_started', bool())
        self.behavior_auto_completed = kwargs.get('behavior_auto_completed', bool())
        self.behavior_slam_completed = kwargs.get('behavior_slam_completed', bool())
        self.behavior_charge_completed = kwargs.get('behavior_charge_completed', bool())
        self.behavior_docking_completed = kwargs.get('behavior_docking_completed', bool())
        self.behavior_undocking_completed = kwargs.get('behavior_undocking_completed', bool())
        self.behavior_auto_canceled = kwargs.get('behavior_auto_canceled', bool())
        self.behavior_docking_canceled = kwargs.get('behavior_docking_canceled', bool())
        self.behavior_manipulation_redocking_triggered = kwargs.get('behavior_manipulation_redocking_triggered', bool())
        self.behavior_charging_redocking_triggered = kwargs.get('behavior_charging_redocking_triggered', bool())
        self.behavior_manipulator_completed = kwargs.get('behavior_manipulator_completed', bool())
        self.behavior_manipulator_emergency_triggered = kwargs.get('behavior_manipulator_emergency_triggered', bool())
        self.behavior_manual_mode_triggered = kwargs.get('behavior_manual_mode_triggered', bool())

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
        if self.behavior_auto_started != other.behavior_auto_started:
            return False
        if self.behavior_slam_started != other.behavior_slam_started:
            return False
        if self.behavior_charge_started != other.behavior_charge_started:
            return False
        if self.behavior_docking_started != other.behavior_docking_started:
            return False
        if self.behavior_undocking_started != other.behavior_undocking_started:
            return False
        if self.behavior_auto_completed != other.behavior_auto_completed:
            return False
        if self.behavior_slam_completed != other.behavior_slam_completed:
            return False
        if self.behavior_charge_completed != other.behavior_charge_completed:
            return False
        if self.behavior_docking_completed != other.behavior_docking_completed:
            return False
        if self.behavior_undocking_completed != other.behavior_undocking_completed:
            return False
        if self.behavior_auto_canceled != other.behavior_auto_canceled:
            return False
        if self.behavior_docking_canceled != other.behavior_docking_canceled:
            return False
        if self.behavior_manipulation_redocking_triggered != other.behavior_manipulation_redocking_triggered:
            return False
        if self.behavior_charging_redocking_triggered != other.behavior_charging_redocking_triggered:
            return False
        if self.behavior_manipulator_completed != other.behavior_manipulator_completed:
            return False
        if self.behavior_manipulator_emergency_triggered != other.behavior_manipulator_emergency_triggered:
            return False
        if self.behavior_manual_mode_triggered != other.behavior_manual_mode_triggered:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def behavior_auto_started(self):
        """Message field 'behavior_auto_started'."""
        return self._behavior_auto_started

    @behavior_auto_started.setter
    def behavior_auto_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_auto_started' field must be of type 'bool'"
        self._behavior_auto_started = value

    @builtins.property
    def behavior_slam_started(self):
        """Message field 'behavior_slam_started'."""
        return self._behavior_slam_started

    @behavior_slam_started.setter
    def behavior_slam_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_slam_started' field must be of type 'bool'"
        self._behavior_slam_started = value

    @builtins.property
    def behavior_charge_started(self):
        """Message field 'behavior_charge_started'."""
        return self._behavior_charge_started

    @behavior_charge_started.setter
    def behavior_charge_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_charge_started' field must be of type 'bool'"
        self._behavior_charge_started = value

    @builtins.property
    def behavior_docking_started(self):
        """Message field 'behavior_docking_started'."""
        return self._behavior_docking_started

    @behavior_docking_started.setter
    def behavior_docking_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_docking_started' field must be of type 'bool'"
        self._behavior_docking_started = value

    @builtins.property
    def behavior_undocking_started(self):
        """Message field 'behavior_undocking_started'."""
        return self._behavior_undocking_started

    @behavior_undocking_started.setter
    def behavior_undocking_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_undocking_started' field must be of type 'bool'"
        self._behavior_undocking_started = value

    @builtins.property
    def behavior_auto_completed(self):
        """Message field 'behavior_auto_completed'."""
        return self._behavior_auto_completed

    @behavior_auto_completed.setter
    def behavior_auto_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_auto_completed' field must be of type 'bool'"
        self._behavior_auto_completed = value

    @builtins.property
    def behavior_slam_completed(self):
        """Message field 'behavior_slam_completed'."""
        return self._behavior_slam_completed

    @behavior_slam_completed.setter
    def behavior_slam_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_slam_completed' field must be of type 'bool'"
        self._behavior_slam_completed = value

    @builtins.property
    def behavior_charge_completed(self):
        """Message field 'behavior_charge_completed'."""
        return self._behavior_charge_completed

    @behavior_charge_completed.setter
    def behavior_charge_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_charge_completed' field must be of type 'bool'"
        self._behavior_charge_completed = value

    @builtins.property
    def behavior_docking_completed(self):
        """Message field 'behavior_docking_completed'."""
        return self._behavior_docking_completed

    @behavior_docking_completed.setter
    def behavior_docking_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_docking_completed' field must be of type 'bool'"
        self._behavior_docking_completed = value

    @builtins.property
    def behavior_undocking_completed(self):
        """Message field 'behavior_undocking_completed'."""
        return self._behavior_undocking_completed

    @behavior_undocking_completed.setter
    def behavior_undocking_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_undocking_completed' field must be of type 'bool'"
        self._behavior_undocking_completed = value

    @builtins.property
    def behavior_auto_canceled(self):
        """Message field 'behavior_auto_canceled'."""
        return self._behavior_auto_canceled

    @behavior_auto_canceled.setter
    def behavior_auto_canceled(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_auto_canceled' field must be of type 'bool'"
        self._behavior_auto_canceled = value

    @builtins.property
    def behavior_docking_canceled(self):
        """Message field 'behavior_docking_canceled'."""
        return self._behavior_docking_canceled

    @behavior_docking_canceled.setter
    def behavior_docking_canceled(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_docking_canceled' field must be of type 'bool'"
        self._behavior_docking_canceled = value

    @builtins.property
    def behavior_manipulation_redocking_triggered(self):
        """Message field 'behavior_manipulation_redocking_triggered'."""
        return self._behavior_manipulation_redocking_triggered

    @behavior_manipulation_redocking_triggered.setter
    def behavior_manipulation_redocking_triggered(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_manipulation_redocking_triggered' field must be of type 'bool'"
        self._behavior_manipulation_redocking_triggered = value

    @builtins.property
    def behavior_charging_redocking_triggered(self):
        """Message field 'behavior_charging_redocking_triggered'."""
        return self._behavior_charging_redocking_triggered

    @behavior_charging_redocking_triggered.setter
    def behavior_charging_redocking_triggered(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_charging_redocking_triggered' field must be of type 'bool'"
        self._behavior_charging_redocking_triggered = value

    @builtins.property
    def behavior_manipulator_completed(self):
        """Message field 'behavior_manipulator_completed'."""
        return self._behavior_manipulator_completed

    @behavior_manipulator_completed.setter
    def behavior_manipulator_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_manipulator_completed' field must be of type 'bool'"
        self._behavior_manipulator_completed = value

    @builtins.property
    def behavior_manipulator_emergency_triggered(self):
        """Message field 'behavior_manipulator_emergency_triggered'."""
        return self._behavior_manipulator_emergency_triggered

    @behavior_manipulator_emergency_triggered.setter
    def behavior_manipulator_emergency_triggered(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_manipulator_emergency_triggered' field must be of type 'bool'"
        self._behavior_manipulator_emergency_triggered = value

    @builtins.property
    def behavior_manual_mode_triggered(self):
        """Message field 'behavior_manual_mode_triggered'."""
        return self._behavior_manual_mode_triggered

    @behavior_manual_mode_triggered.setter
    def behavior_manual_mode_triggered(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'behavior_manual_mode_triggered' field must be of type 'bool'"
        self._behavior_manual_mode_triggered = value
