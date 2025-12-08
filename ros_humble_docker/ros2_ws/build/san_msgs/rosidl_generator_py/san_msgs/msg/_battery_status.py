# generated from rosidl_generator_py/resource/_idl.py.em
# with input from san_msgs:msg/BatteryStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BatteryStatus(type):
    """Metaclass of message 'BatteryStatus'."""

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
                'san_msgs.msg.BatteryStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__battery_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__battery_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__battery_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__battery_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__battery_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BatteryStatus(metaclass=Metaclass_BatteryStatus):
    """Message class 'BatteryStatus'."""

    __slots__ = [
        '_voltage_top',
        '_current_top',
        '_soc_top',
        '_soh_top',
        '_voltage',
        '_current',
        '_soc',
        '_soh',
        '_charge_relay',
        '_charging_jack_state',
        '_charging_state',
    ]

    _fields_and_field_types = {
        'voltage_top': 'float',
        'current_top': 'float',
        'soc_top': 'float',
        'soh_top': 'float',
        'voltage': 'float',
        'current': 'float',
        'soc': 'float',
        'soh': 'float',
        'charge_relay': 'boolean',
        'charging_jack_state': 'boolean',
        'charging_state': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.voltage_top = kwargs.get('voltage_top', float())
        self.current_top = kwargs.get('current_top', float())
        self.soc_top = kwargs.get('soc_top', float())
        self.soh_top = kwargs.get('soh_top', float())
        self.voltage = kwargs.get('voltage', float())
        self.current = kwargs.get('current', float())
        self.soc = kwargs.get('soc', float())
        self.soh = kwargs.get('soh', float())
        self.charge_relay = kwargs.get('charge_relay', bool())
        self.charging_jack_state = kwargs.get('charging_jack_state', bool())
        self.charging_state = kwargs.get('charging_state', bool())

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
        if self.voltage_top != other.voltage_top:
            return False
        if self.current_top != other.current_top:
            return False
        if self.soc_top != other.soc_top:
            return False
        if self.soh_top != other.soh_top:
            return False
        if self.voltage != other.voltage:
            return False
        if self.current != other.current:
            return False
        if self.soc != other.soc:
            return False
        if self.soh != other.soh:
            return False
        if self.charge_relay != other.charge_relay:
            return False
        if self.charging_jack_state != other.charging_jack_state:
            return False
        if self.charging_state != other.charging_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def voltage_top(self):
        """Message field 'voltage_top'."""
        return self._voltage_top

    @voltage_top.setter
    def voltage_top(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage_top' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage_top' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage_top = value

    @builtins.property
    def current_top(self):
        """Message field 'current_top'."""
        return self._current_top

    @current_top.setter
    def current_top(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_top' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_top' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_top = value

    @builtins.property
    def soc_top(self):
        """Message field 'soc_top'."""
        return self._soc_top

    @soc_top.setter
    def soc_top(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'soc_top' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'soc_top' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._soc_top = value

    @builtins.property
    def soh_top(self):
        """Message field 'soh_top'."""
        return self._soh_top

    @soh_top.setter
    def soh_top(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'soh_top' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'soh_top' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._soh_top = value

    @builtins.property
    def voltage(self):
        """Message field 'voltage'."""
        return self._voltage

    @voltage.setter
    def voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._voltage = value

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current = value

    @builtins.property
    def soc(self):
        """Message field 'soc'."""
        return self._soc

    @soc.setter
    def soc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'soc' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'soc' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._soc = value

    @builtins.property
    def soh(self):
        """Message field 'soh'."""
        return self._soh

    @soh.setter
    def soh(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'soh' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'soh' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._soh = value

    @builtins.property
    def charge_relay(self):
        """Message field 'charge_relay'."""
        return self._charge_relay

    @charge_relay.setter
    def charge_relay(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charge_relay' field must be of type 'bool'"
        self._charge_relay = value

    @builtins.property
    def charging_jack_state(self):
        """Message field 'charging_jack_state'."""
        return self._charging_jack_state

    @charging_jack_state.setter
    def charging_jack_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charging_jack_state' field must be of type 'bool'"
        self._charging_jack_state = value

    @builtins.property
    def charging_state(self):
        """Message field 'charging_state'."""
        return self._charging_state

    @charging_state.setter
    def charging_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charging_state' field must be of type 'bool'"
        self._charging_state = value
