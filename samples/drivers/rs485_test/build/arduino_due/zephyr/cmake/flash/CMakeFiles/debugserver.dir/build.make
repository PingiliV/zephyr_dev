# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due

# Utility rule file for debugserver.

# Include the progress variables for this target.
include zephyr/cmake/flash/CMakeFiles/debugserver.dir/progress.make

zephyr/cmake/flash/CMakeFiles/debugserver:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging arduino_due"
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/cmake/flash && /usr/local/bin/cmake -E echo 'debugserver'\ is\ not\ supported\ with\ this\ board. Please\ check\ the\ documentation\ for\ alternate\ instructions.

debugserver: zephyr/cmake/flash/CMakeFiles/debugserver
debugserver: zephyr/cmake/flash/CMakeFiles/debugserver.dir/build.make

.PHONY : debugserver

# Rule to build all files generated by this target.
zephyr/cmake/flash/CMakeFiles/debugserver.dir/build: debugserver

.PHONY : zephyr/cmake/flash/CMakeFiles/debugserver.dir/build

zephyr/cmake/flash/CMakeFiles/debugserver.dir/clean:
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/cmake/flash && $(CMAKE_COMMAND) -P CMakeFiles/debugserver.dir/cmake_clean.cmake
.PHONY : zephyr/cmake/flash/CMakeFiles/debugserver.dir/clean

zephyr/cmake/flash/CMakeFiles/debugserver.dir/depend:
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/cmake/flash /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/cmake/flash /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/cmake/flash/CMakeFiles/debugserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : zephyr/cmake/flash/CMakeFiles/debugserver.dir/depend

