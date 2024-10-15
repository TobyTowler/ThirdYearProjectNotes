# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/RobotCMD.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotCMD_Request(type):
    """Metaclass of message 'RobotCMD_Request'."""

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
                'robot_interfaces.srv.RobotCMD_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_cmd__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_cmd__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_cmd__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_cmd__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_cmd__request

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


class RobotCMD_Request(metaclass=Metaclass_RobotCMD_Request):
    """Message class 'RobotCMD_Request'."""

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
            'cmd_chr', RobotCMD_Request.CMD_CHR__DEFAULT)
        self.arg1 = kwargs.get(
            'arg1', RobotCMD_Request.ARG1__DEFAULT)
        self.arg2 = kwargs.get(
            'arg2', RobotCMD_Request.ARG2__DEFAULT)
        self.arg3 = kwargs.get(
            'arg3', RobotCMD_Request.ARG3__DEFAULT)

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


class Metaclass_RobotCMD_Response(type):
    """Metaclass of message 'RobotCMD_Response'."""

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
                'robot_interfaces.srv.RobotCMD_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_cmd__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_cmd__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_cmd__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_cmd__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_cmd__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CONTROLLER_DATA__DEFAULT': '',
        }

    @property
    def CONTROLLER_DATA__DEFAULT(cls):
        """Return default value for message field 'controller_data'."""
        return ''


class RobotCMD_Response(metaclass=Metaclass_RobotCMD_Response):
    """Message class 'RobotCMD_Response'."""

    __slots__ = [
        '_controller_data',
    ]

    _fields_and_field_types = {
        'controller_data': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.controller_data = kwargs.get(
            'controller_data', RobotCMD_Response.CONTROLLER_DATA__DEFAULT)

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
        if self.controller_data != other.controller_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def controller_data(self):
        """Message field 'controller_data'."""
        return self._controller_data

    @controller_data.setter
    def controller_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'controller_data' field must be of type 'str'"
        self._controller_data = value


class Metaclass_RobotCMD(type):
    """Metaclass of service 'RobotCMD'."""

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
                'robot_interfaces.srv.RobotCMD')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__robot_cmd

            from robot_interfaces.srv import _robot_cmd
            if _robot_cmd.Metaclass_RobotCMD_Request._TYPE_SUPPORT is None:
                _robot_cmd.Metaclass_RobotCMD_Request.__import_type_support__()
            if _robot_cmd.Metaclass_RobotCMD_Response._TYPE_SUPPORT is None:
                _robot_cmd.Metaclass_RobotCMD_Response.__import_type_support__()


class RobotCMD(metaclass=Metaclass_RobotCMD):
    from robot_interfaces.srv._robot_cmd import RobotCMD_Request as Request
    from robot_interfaces.srv._robot_cmd import RobotCMD_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
