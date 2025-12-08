# generated from rosidl_generator_py/resource/_idl.py.em
# with input from san_msgs:msg/Task.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Task(type):
    """Metaclass of message 'Task'."""

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
                'san_msgs.msg.Task')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__task
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__task
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__task
            cls._TYPE_SUPPORT = module.type_support_msg__msg__task
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__task

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Task(metaclass=Metaclass_Task):
    """Message class 'Task'."""

    __slots__ = [
        '_task_load_started',
        '_task_unload_started',
        '_task_move_started',
        '_task_home_started',
        '_task_cancel_started',
        '_task_load_completed',
        '_task_unload_completed',
        '_task_move_completed',
        '_task_home_completed',
        '_task_cancel_completed',
    ]

    _fields_and_field_types = {
        'task_load_started': 'boolean',
        'task_unload_started': 'boolean',
        'task_move_started': 'boolean',
        'task_home_started': 'boolean',
        'task_cancel_started': 'boolean',
        'task_load_completed': 'boolean',
        'task_unload_completed': 'boolean',
        'task_move_completed': 'boolean',
        'task_home_completed': 'boolean',
        'task_cancel_completed': 'boolean',
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
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_load_started = kwargs.get('task_load_started', bool())
        self.task_unload_started = kwargs.get('task_unload_started', bool())
        self.task_move_started = kwargs.get('task_move_started', bool())
        self.task_home_started = kwargs.get('task_home_started', bool())
        self.task_cancel_started = kwargs.get('task_cancel_started', bool())
        self.task_load_completed = kwargs.get('task_load_completed', bool())
        self.task_unload_completed = kwargs.get('task_unload_completed', bool())
        self.task_move_completed = kwargs.get('task_move_completed', bool())
        self.task_home_completed = kwargs.get('task_home_completed', bool())
        self.task_cancel_completed = kwargs.get('task_cancel_completed', bool())

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
        if self.task_load_started != other.task_load_started:
            return False
        if self.task_unload_started != other.task_unload_started:
            return False
        if self.task_move_started != other.task_move_started:
            return False
        if self.task_home_started != other.task_home_started:
            return False
        if self.task_cancel_started != other.task_cancel_started:
            return False
        if self.task_load_completed != other.task_load_completed:
            return False
        if self.task_unload_completed != other.task_unload_completed:
            return False
        if self.task_move_completed != other.task_move_completed:
            return False
        if self.task_home_completed != other.task_home_completed:
            return False
        if self.task_cancel_completed != other.task_cancel_completed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_load_started(self):
        """Message field 'task_load_started'."""
        return self._task_load_started

    @task_load_started.setter
    def task_load_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_load_started' field must be of type 'bool'"
        self._task_load_started = value

    @builtins.property
    def task_unload_started(self):
        """Message field 'task_unload_started'."""
        return self._task_unload_started

    @task_unload_started.setter
    def task_unload_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_unload_started' field must be of type 'bool'"
        self._task_unload_started = value

    @builtins.property
    def task_move_started(self):
        """Message field 'task_move_started'."""
        return self._task_move_started

    @task_move_started.setter
    def task_move_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_move_started' field must be of type 'bool'"
        self._task_move_started = value

    @builtins.property
    def task_home_started(self):
        """Message field 'task_home_started'."""
        return self._task_home_started

    @task_home_started.setter
    def task_home_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_home_started' field must be of type 'bool'"
        self._task_home_started = value

    @builtins.property
    def task_cancel_started(self):
        """Message field 'task_cancel_started'."""
        return self._task_cancel_started

    @task_cancel_started.setter
    def task_cancel_started(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_cancel_started' field must be of type 'bool'"
        self._task_cancel_started = value

    @builtins.property
    def task_load_completed(self):
        """Message field 'task_load_completed'."""
        return self._task_load_completed

    @task_load_completed.setter
    def task_load_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_load_completed' field must be of type 'bool'"
        self._task_load_completed = value

    @builtins.property
    def task_unload_completed(self):
        """Message field 'task_unload_completed'."""
        return self._task_unload_completed

    @task_unload_completed.setter
    def task_unload_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_unload_completed' field must be of type 'bool'"
        self._task_unload_completed = value

    @builtins.property
    def task_move_completed(self):
        """Message field 'task_move_completed'."""
        return self._task_move_completed

    @task_move_completed.setter
    def task_move_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_move_completed' field must be of type 'bool'"
        self._task_move_completed = value

    @builtins.property
    def task_home_completed(self):
        """Message field 'task_home_completed'."""
        return self._task_home_completed

    @task_home_completed.setter
    def task_home_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_home_completed' field must be of type 'bool'"
        self._task_home_completed = value

    @builtins.property
    def task_cancel_completed(self):
        """Message field 'task_cancel_completed'."""
        return self._task_cancel_completed

    @task_cancel_completed.setter
    def task_cancel_completed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'task_cancel_completed' field must be of type 'bool'"
        self._task_cancel_completed = value
