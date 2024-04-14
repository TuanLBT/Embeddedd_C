## *********************************************************
##
## File autogenerated for the dynamic_reconfigure_test package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'name': 'Default', 'type': '', 'state': True, 'cstate': 'true', 'id': 0, 'parent': 0, 'parameters': [{'name': 'int_enum_', 'type': 'int', 'default': 0, 'level': 1, 'description': 'Int enum', 'min': 0, 'max': 3, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': "{'enum': [{'name': 'Small', 'type': 'int', 'value': 0, 'srcline': 44, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A small constant', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Medium', 'type': 'int', 'value': 1, 'srcline': 45, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A medium value', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Large', 'type': 'int', 'value': 2, 'srcline': 46, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A large value', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'ExtraLarge', 'type': 'int', 'value': 3, 'srcline': 47, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'An extra large value', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'An enum to set the size.'}", 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'int_', 'type': 'int', 'default': 0, 'level': 1, 'description': 'Int parameter', 'min': -10, 'max': 10, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'double_', 'type': 'double', 'default': 0.0, 'level': 2, 'description': 'double parameter', 'min': -2.0, 'max': 10.0, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'double_no_minmax', 'type': 'double', 'default': 1.0, 'level': 2, 'description': 'double parameter without boundaries', 'min': -inf, 'max': inf, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'double_no_max', 'type': 'double', 'default': 2.0, 'level': 2, 'description': 'double parameter without max value', 'min': 0.0, 'max': inf, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'double_inf', 'type': 'double', 'default': inf, 'level': 2, 'description': 'double parameter with inf', 'min': inf, 'max': inf, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'double_negative_inf', 'type': 'double', 'default': -inf, 'level': 2, 'description': 'double parameter with negative inf', 'min': -inf, 'max': -inf, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'str_', 'type': 'str', 'default': 'foo', 'level': 4, 'description': 'String parameter', 'min': '', 'max': '', 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'std::string', 'cconsttype': 'const char * const'}, {'name': 'mstr_', 'type': 'str', 'default': 'bar', 'level': 4, 'description': 'Multibyte String parameter', 'min': '', 'max': '', 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'std::string', 'cconsttype': 'const char * const'}, {'name': 'bool_', 'type': 'bool', 'default': False, 'level': 8, 'description': 'Boolean parameter', 'min': False, 'max': True, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'bool', 'cconsttype': 'const bool'}, {'name': 'level', 'type': 'int', 'default': 0, 'level': 16, 'description': 'Contains the level of the previous change', 'min': -2147483648, 'max': 2147483647, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'int_nodefault', 'type': 'int', 'default': 0, 'level': 0, 'description': 'Checks against regression of #4499', 'min': -2147483648, 'max': 2147483647, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'i', 'type': 'int', 'default': 0, 'level': 0, 'description': 'Checks against regression of https://github.com/ros/dynamic_reconfigure/issues/6', 'min': -2147483648, 'max': 2147483647, 'srcline': 291, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}], 'groups': [{'name': 'Group_One', 'type': '', 'state': True, 'cstate': 'true', 'id': 1, 'parent': 0, 'parameters': [{'name': 'group1_int', 'type': 'int', 'default': 2, 'level': 1, 'description': 'A second level group parameter', 'min': -2147483648, 'max': 2147483647, 'srcline': 64, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}], 'groups': [{'name': 'GROUP2', 'type': 'collapse', 'state': False, 'cstate': 'false', 'id': 2, 'parent': 1, 'parameters': [{'name': 'group2_double', 'type': 'double', 'default': 3.333, 'level': 0, 'description': 'A third level group parameter', 'min': -inf, 'max': inf, 'srcline': 66, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'group2_string', 'type': 'str', 'default': 'test string', 'level': 0, 'description': 'A third level group parameter', 'min': '', 'max': '', 'srcline': 67, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'std::string', 'cconsttype': 'const char * const'}, {'name': 'some_other', 'type': 'str', 'default': 'AAAAAAGGHH', 'level': 0, 'description': 'Something', 'min': '', 'max': '', 'srcline': 68, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'std::string', 'cconsttype': 'const char * const'}, {'name': 'variable', 'type': 'bool', 'default': True, 'level': 0, 'description': 'A boolean', 'min': False, 'max': True, 'srcline': 69, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'bool', 'cconsttype': 'const bool'}], 'groups': [{'name': 'Group3', 'type': '', 'state': True, 'cstate': 'true', 'id': 3, 'parent': 2, 'parameters': [{'name': 'deep_var_int', 'type': 'int', 'default': 0, 'level': 0, 'description': 'Were very far down now', 'min': 0, 'max': 3, 'srcline': 71, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': "{'enum': [{'name': 'Small', 'type': 'int', 'value': 0, 'srcline': 44, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A small constant', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Medium', 'type': 'int', 'value': 1, 'srcline': 45, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A medium value', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Large', 'type': 'int', 'value': 2, 'srcline': 46, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'A large value', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'ExtraLarge', 'type': 'int', 'value': 3, 'srcline': 47, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'description': 'An extra large value', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'An enum to set the size.'}", 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'deep_var_bool', 'type': 'bool', 'default': True, 'level': 0, 'description': 'Were even farther down now!!', 'min': False, 'max': True, 'srcline': 72, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'bool', 'cconsttype': 'const bool'}, {'name': 'deep_var_double', 'type': 'double', 'default': -1.0, 'level': 0, 'description': 'Were super far down now!!', 'min': -inf, 'max': inf, 'srcline': 73, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}], 'groups': [], 'srcline': 124, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT::GROUP_ONE::GROUP2::GROUP3', 'parentclass': 'DEFAULT::GROUP_ONE::GROUP2', 'parentname': 'GROUP2', 'field': 'DEFAULT::GROUP_ONE::GROUP2::group3', 'upper': 'GROUP3', 'lower': 'group3'}], 'srcline': 124, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT::GROUP_ONE::GROUP2', 'parentclass': 'DEFAULT::GROUP_ONE', 'parentname': 'Group_One', 'field': 'DEFAULT::GROUP_ONE::group2', 'upper': 'GROUP2', 'lower': 'group2'}], 'srcline': 124, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT::GROUP_ONE', 'parentclass': 'DEFAULT', 'parentname': 'Default', 'field': 'DEFAULT::group_one', 'upper': 'GROUP_ONE', 'lower': 'group_one'}, {'name': 'Upper_Group_2', 'type': '', 'state': True, 'cstate': 'true', 'id': 4, 'parent': 0, 'parameters': [{'name': 'some_param', 'type': 'int', 'default': 20, 'level': 0, 'description': 'Some param', 'min': -2147483648, 'max': 2147483647, 'srcline': 76, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/cfg/Test.cfg', 'edit_method': '', 'ctype': 'int', 'cconsttype': 'const int'}], 'groups': [], 'srcline': 124, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT::UPPER_GROUP_2', 'parentclass': 'DEFAULT', 'parentname': 'Default', 'field': 'DEFAULT::upper_group_2', 'upper': 'UPPER_GROUP_2', 'lower': 'upper_group_2'}], 'srcline': 246, 'srcfile': '/home/pi/do_an_ws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT', 'parentclass': '', 'parentname': 'Default', 'field': 'default', 'upper': 'DEFAULT', 'lower': 'groups'}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

Test_int_const = 5
Test_double_const = 5.6
Test_str_const = 'foo'
Test_bool_const = True
Test_Small = 0
Test_Medium = 1
Test_Large = 2
Test_ExtraLarge = 3
