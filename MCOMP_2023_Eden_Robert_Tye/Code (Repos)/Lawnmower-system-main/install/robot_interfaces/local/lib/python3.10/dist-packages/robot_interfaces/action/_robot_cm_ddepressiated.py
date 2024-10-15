# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:action/RobotCMDdepressiated.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotCMDdepressiated_Goal(type):
    """Metaclass of message 'RobotCMDdepressiated_Goal'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CMD_CHR__DEFAULT': 64,
            'ARG1__DEFAULT': 0,
            'ARG2__DEFAULT': 0,
            'ARG3__DEFAULT': 0,
        }

    @property
    def CMD_CHR__DEFAULT(cls):
        """Return default value for message field 'cmd_chr'."""
        return 64

    @property
    def ARG1__DEFAULT(cls):
        """Return default value for message field 'arg1'."""
        return 0

    @property
    def ARG2__DEFAULT(cls):
        """Return default value for message field 'arg2'."""
        return 0

    @property
    def ARG3__DEFAULT(cls):
        """Return default value for message field 'arg3'."""
        return 0


class RobotCMDdepressiated_Goal(metaclass=Metaclass_RobotCMDdepressiated_Goal):
    """Message class 'RobotCMDdepressiated_Goal'."""

    __slots__ = [
        '_cmd_chr',
        '_arg1',
        '_arg2',
        '_arg3',
    ]

    _fields_and_field_types = {
        'cmd_chr': 'uint8',
        'arg1': 'int32',
        'arg2': 'int32',
        'arg3': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd_chr = kwargs.get(
            'cmd_chr', RobotCMDdepressiated_Goal.CMD_CHR__DEFAULT)
        self.arg1 = kwargs.get(
            'arg1', RobotCMDdepressiated_Goal.ARG1__DEFAULT)
        self.arg2 = kwargs.get(
            'arg2', RobotCMDdepressiated_Goal.ARG2__DEFAULT)
        self.arg3 = kwargs.get(
            'arg3', RobotCMDdepressiated_Goal.ARG3__DEFAULT)

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
        if self.cmd_chr != other.cmd_chr:
            return False
        if self.arg1 != other.arg1:
            return False
        if self.arg2 != other.arg2:
            return False
        if self.arg3 != other.arg3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd_chr(self):
        """Message field 'cmd_chr'."""
        return self._cmd_chr

    @cmd_chr.setter
    def cmd_chr(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd_chr' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cmd_chr' field must be an unsigned integer in [0, 255]"
        self._cmd_chr = value

    @builtins.property
    def arg1(self):
        """Message field 'arg1'."""
        return self._arg1

    @arg1.setter
    def arg1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg1' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'arg1' field must be an integer in [-2147483648, 2147483647]"
        self._arg1 = value

    @builtins.property
    def arg2(self):
        """Message field 'arg2'."""
        return self._arg2

    @arg2.setter
    def arg2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg2' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'arg2' field must be an integer in [-2147483648, 2147483647]"
        self._arg2 = value

    @builtins.property
    def arg3(self):
        """Message field 'arg3'."""
        return self._arg3

    @arg3.setter
    def arg3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg3' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'arg3' field must be an integer in [-2147483648, 2147483647]"
        self._arg3 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_Result(type):
    """Metaclass of message 'RobotCMDdepressiated_Result'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DATA_STRING__DEFAULT': '',
        }

    @property
    def DATA_STRING__DEFAULT(cls):
        """Return default value for message field 'data_string'."""
        return ''


class RobotCMDdepressiated_Result(metaclass=Metaclass_RobotCMDdepressiated_Result):
    """Message class 'RobotCMDdepressiated_Result'."""

    __slots__ = [
        '_data_string',
    ]

    _fields_and_field_types = {
        'data_string': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.data_string = kwargs.get(
            'data_string', RobotCMDdepressiated_Result.DATA_STRING__DEFAULT)

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
        if self.data_string != other.data_string:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def data_string(self):
        """Message field 'data_string'."""
        return self._data_string

    @data_string.setter
    def data_string(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'data_string' field must be of type 'str'"
        self._data_string = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_Feedback(type):
    """Metaclass of message 'RobotCMDdepressiated_Feedback'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_Feedback(metaclass=Metaclass_RobotCMDdepressiated_Feedback):
    """Message class 'RobotCMDdepressiated_Feedback'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_SendGoal_Request(type):
    """Metaclass of message 'RobotCMDdepressiated_SendGoal_Request'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__send_goal__request

            from robot_interfaces.action import RobotCMDdepressiated
            if RobotCMDdepressiated.Goal.__class__._TYPE_SUPPORT is None:
                RobotCMDdepressiated.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_SendGoal_Request(metaclass=Metaclass_RobotCMDdepressiated_SendGoal_Request):
    """Message class 'RobotCMDdepressiated_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'robot_interfaces/RobotCMDdepressiated_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robot_interfaces', 'action'], 'RobotCMDdepressiated_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Goal
        self.goal = kwargs.get('goal', RobotCMDdepressiated_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Goal
            assert \
                isinstance(value, RobotCMDdepressiated_Goal), \
                "The 'goal' field must be a sub message of type 'RobotCMDdepressiated_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_SendGoal_Response(type):
    """Metaclass of message 'RobotCMDdepressiated_SendGoal_Response'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_SendGoal_Response(metaclass=Metaclass_RobotCMDdepressiated_SendGoal_Response):
    """Message class 'RobotCMDdepressiated_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_RobotCMDdepressiated_SendGoal(type):
    """Metaclass of service 'RobotCMDdepressiated_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__robot_cm_ddepressiated__send_goal

            from robot_interfaces.action import _robot_cm_ddepressiated
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal_Request._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal_Request.__import_type_support__()
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal_Response._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal_Response.__import_type_support__()


class RobotCMDdepressiated_SendGoal(metaclass=Metaclass_RobotCMDdepressiated_SendGoal):
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_SendGoal_Request as Request
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_GetResult_Request(type):
    """Metaclass of message 'RobotCMDdepressiated_GetResult_Request'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_GetResult_Request(metaclass=Metaclass_RobotCMDdepressiated_GetResult_Request):
    """Message class 'RobotCMDdepressiated_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_GetResult_Response(type):
    """Metaclass of message 'RobotCMDdepressiated_GetResult_Response'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__get_result__response

            from robot_interfaces.action import RobotCMDdepressiated
            if RobotCMDdepressiated.Result.__class__._TYPE_SUPPORT is None:
                RobotCMDdepressiated.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_GetResult_Response(metaclass=Metaclass_RobotCMDdepressiated_GetResult_Response):
    """Message class 'RobotCMDdepressiated_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'robot_interfaces/RobotCMDdepressiated_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robot_interfaces', 'action'], 'RobotCMDdepressiated_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Result
        self.result = kwargs.get('result', RobotCMDdepressiated_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Result
            assert \
                isinstance(value, RobotCMDdepressiated_Result), \
                "The 'result' field must be a sub message of type 'RobotCMDdepressiated_Result'"
        self._result = value


class Metaclass_RobotCMDdepressiated_GetResult(type):
    """Metaclass of service 'RobotCMDdepressiated_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__robot_cm_ddepressiated__get_result

            from robot_interfaces.action import _robot_cm_ddepressiated
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult_Request._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult_Request.__import_type_support__()
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult_Response._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult_Response.__import_type_support__()


class RobotCMDdepressiated_GetResult(metaclass=Metaclass_RobotCMDdepressiated_GetResult):
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_GetResult_Request as Request
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotCMDdepressiated_FeedbackMessage(type):
    """Metaclass of message 'RobotCMDdepressiated_FeedbackMessage'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__robot_cm_ddepressiated__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__robot_cm_ddepressiated__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__robot_cm_ddepressiated__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__robot_cm_ddepressiated__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__robot_cm_ddepressiated__feedback_message

            from robot_interfaces.action import RobotCMDdepressiated
            if RobotCMDdepressiated.Feedback.__class__._TYPE_SUPPORT is None:
                RobotCMDdepressiated.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotCMDdepressiated_FeedbackMessage(metaclass=Metaclass_RobotCMDdepressiated_FeedbackMessage):
    """Message class 'RobotCMDdepressiated_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'robot_interfaces/RobotCMDdepressiated_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robot_interfaces', 'action'], 'RobotCMDdepressiated_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Feedback
        self.feedback = kwargs.get('feedback', RobotCMDdepressiated_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Feedback
            assert \
                isinstance(value, RobotCMDdepressiated_Feedback), \
                "The 'feedback' field must be a sub message of type 'RobotCMDdepressiated_Feedback'"
        self._feedback = value


class Metaclass_RobotCMDdepressiated(type):
    """Metaclass of action 'RobotCMDdepressiated'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.action.RobotCMDdepressiated')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__robot_cm_ddepressiated

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from robot_interfaces.action import _robot_cm_ddepressiated
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_SendGoal.__import_type_support__()
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_GetResult.__import_type_support__()
            if _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_FeedbackMessage._TYPE_SUPPORT is None:
                _robot_cm_ddepressiated.Metaclass_RobotCMDdepressiated_FeedbackMessage.__import_type_support__()


class RobotCMDdepressiated(metaclass=Metaclass_RobotCMDdepressiated):

    # The goal message defined in the action definition.
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Goal as Goal
    # The result message defined in the action definition.
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Result as Result
    # The feedback message defined in the action definition.
    from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from robot_interfaces.action._robot_cm_ddepressiated import RobotCMDdepressiated_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
