# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:msg/RobotSendCMD.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotSendCMD(type):
    """Metaclass of message 'RobotSendCMD'."""

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
                'robot_interfaces.msg.RobotSendCMD')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_send_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_send_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_send_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_send_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_send_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CMD_CHR__DEFAULT': 64,
            'ARG1__DEFAULT': 0.0,
            'ARG2__DEFAULT': 0.0,
            'ARG3__DEFAULT': 0.0,
            'ARG4__DEFAULT': 0.0,
            'ARG5__DEFAULT': 0.0,
            'ARG6__DEFAULT': 0.0,
            'ARG7__DEFAULT': 0.0,
            'ARG8__DEFAULT': 0.0,
            'ARG9__DEFAULT': 0.0,
            'ARG10__DEFAULT': 0.0,
            'ARG11__DEFAULT': 0.0,
            'ARG12__DEFAULT': 0.0,
            'ARG13__DEFAULT': 0.0,
            'ARG14__DEFAULT': 0.0,
        }

    @property
    def CMD_CHR__DEFAULT(cls):
        """Return default value for message field 'cmd_chr'."""
        return 64

    @property
    def ARG1__DEFAULT(cls):
        """Return default value for message field 'arg1'."""
        return 0.0

    @property
    def ARG2__DEFAULT(cls):
        """Return default value for message field 'arg2'."""
        return 0.0

    @property
    def ARG3__DEFAULT(cls):
        """Return default value for message field 'arg3'."""
        return 0.0

    @property
    def ARG4__DEFAULT(cls):
        """Return default value for message field 'arg4'."""
        return 0.0

    @property
    def ARG5__DEFAULT(cls):
        """Return default value for message field 'arg5'."""
        return 0.0

    @property
    def ARG6__DEFAULT(cls):
        """Return default value for message field 'arg6'."""
        return 0.0

    @property
    def ARG7__DEFAULT(cls):
        """Return default value for message field 'arg7'."""
        return 0.0

    @property
    def ARG8__DEFAULT(cls):
        """Return default value for message field 'arg8'."""
        return 0.0

    @property
    def ARG9__DEFAULT(cls):
        """Return default value for message field 'arg9'."""
        return 0.0

    @property
    def ARG10__DEFAULT(cls):
        """Return default value for message field 'arg10'."""
        return 0.0

    @property
    def ARG11__DEFAULT(cls):
        """Return default value for message field 'arg11'."""
        return 0.0

    @property
    def ARG12__DEFAULT(cls):
        """Return default value for message field 'arg12'."""
        return 0.0

    @property
    def ARG13__DEFAULT(cls):
        """Return default value for message field 'arg13'."""
        return 0.0

    @property
    def ARG14__DEFAULT(cls):
        """Return default value for message field 'arg14'."""
        return 0.0


class RobotSendCMD(metaclass=Metaclass_RobotSendCMD):
    """Message class 'RobotSendCMD'."""

    __slots__ = [
        '_cmd_chr',
        '_arg1',
        '_arg2',
        '_arg3',
        '_arg4',
        '_arg5',
        '_arg6',
        '_arg7',
        '_arg8',
        '_arg9',
        '_arg10',
        '_arg11',
        '_arg12',
        '_arg13',
        '_arg14',
    ]

    _fields_and_field_types = {
        'cmd_chr': 'uint8',
        'arg1': 'float',
        'arg2': 'float',
        'arg3': 'float',
        'arg4': 'float',
        'arg5': 'float',
        'arg6': 'float',
        'arg7': 'float',
        'arg8': 'float',
        'arg9': 'float',
        'arg10': 'float',
        'arg11': 'float',
        'arg12': 'float',
        'arg13': 'float',
        'arg14': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd_chr = kwargs.get(
            'cmd_chr', RobotSendCMD.CMD_CHR__DEFAULT)
        self.arg1 = kwargs.get(
            'arg1', RobotSendCMD.ARG1__DEFAULT)
        self.arg2 = kwargs.get(
            'arg2', RobotSendCMD.ARG2__DEFAULT)
        self.arg3 = kwargs.get(
            'arg3', RobotSendCMD.ARG3__DEFAULT)
        self.arg4 = kwargs.get(
            'arg4', RobotSendCMD.ARG4__DEFAULT)
        self.arg5 = kwargs.get(
            'arg5', RobotSendCMD.ARG5__DEFAULT)
        self.arg6 = kwargs.get(
            'arg6', RobotSendCMD.ARG6__DEFAULT)
        self.arg7 = kwargs.get(
            'arg7', RobotSendCMD.ARG7__DEFAULT)
        self.arg8 = kwargs.get(
            'arg8', RobotSendCMD.ARG8__DEFAULT)
        self.arg9 = kwargs.get(
            'arg9', RobotSendCMD.ARG9__DEFAULT)
        self.arg10 = kwargs.get(
            'arg10', RobotSendCMD.ARG10__DEFAULT)
        self.arg11 = kwargs.get(
            'arg11', RobotSendCMD.ARG11__DEFAULT)
        self.arg12 = kwargs.get(
            'arg12', RobotSendCMD.ARG12__DEFAULT)
        self.arg13 = kwargs.get(
            'arg13', RobotSendCMD.ARG13__DEFAULT)
        self.arg14 = kwargs.get(
            'arg14', RobotSendCMD.ARG14__DEFAULT)

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
        if self.arg4 != other.arg4:
            return False
        if self.arg5 != other.arg5:
            return False
        if self.arg6 != other.arg6:
            return False
        if self.arg7 != other.arg7:
            return False
        if self.arg8 != other.arg8:
            return False
        if self.arg9 != other.arg9:
            return False
        if self.arg10 != other.arg10:
            return False
        if self.arg11 != other.arg11:
            return False
        if self.arg12 != other.arg12:
            return False
        if self.arg13 != other.arg13:
            return False
        if self.arg14 != other.arg14:
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
                isinstance(value, float), \
                "The 'arg1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg1 = value

    @builtins.property
    def arg2(self):
        """Message field 'arg2'."""
        return self._arg2

    @arg2.setter
    def arg2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg2 = value

    @builtins.property
    def arg3(self):
        """Message field 'arg3'."""
        return self._arg3

    @arg3.setter
    def arg3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg3 = value

    @builtins.property
    def arg4(self):
        """Message field 'arg4'."""
        return self._arg4

    @arg4.setter
    def arg4(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg4' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg4' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg4 = value

    @builtins.property
    def arg5(self):
        """Message field 'arg5'."""
        return self._arg5

    @arg5.setter
    def arg5(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg5' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg5' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg5 = value

    @builtins.property
    def arg6(self):
        """Message field 'arg6'."""
        return self._arg6

    @arg6.setter
    def arg6(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg6' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg6' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg6 = value

    @builtins.property
    def arg7(self):
        """Message field 'arg7'."""
        return self._arg7

    @arg7.setter
    def arg7(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg7' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg7' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg7 = value

    @builtins.property
    def arg8(self):
        """Message field 'arg8'."""
        return self._arg8

    @arg8.setter
    def arg8(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg8' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg8' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg8 = value

    @builtins.property
    def arg9(self):
        """Message field 'arg9'."""
        return self._arg9

    @arg9.setter
    def arg9(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg9' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg9' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg9 = value

    @builtins.property
    def arg10(self):
        """Message field 'arg10'."""
        return self._arg10

    @arg10.setter
    def arg10(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg10' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg10' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg10 = value

    @builtins.property
    def arg11(self):
        """Message field 'arg11'."""
        return self._arg11

    @arg11.setter
    def arg11(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg11' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg11' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg11 = value

    @builtins.property
    def arg12(self):
        """Message field 'arg12'."""
        return self._arg12

    @arg12.setter
    def arg12(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg12' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg12' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg12 = value

    @builtins.property
    def arg13(self):
        """Message field 'arg13'."""
        return self._arg13

    @arg13.setter
    def arg13(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg13' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg13' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg13 = value

    @builtins.property
    def arg14(self):
        """Message field 'arg14'."""
        return self._arg14

    @arg14.setter
    def arg14(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arg14' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'arg14' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._arg14 = value
