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

# Utility rule file for linker_script.

# Include the progress variables for this target.
include zephyr/CMakeFiles/linker_script.dir/progress.make

zephyr/CMakeFiles/linker_script: zephyr/linker.cmd


zephyr/linker.cmd: ../../../../../arch/arm/soc/atmel_sam/sam3x/linker.ld
zephyr/linker.cmd: ../../../../../arch/arm/soc/atmel_sam/sam3x/linker.ld
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating linker.cmd"
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr && /opt/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc -x assembler-with-cpp -nostdinc -undef -MD -MF linker.cmd.dep -MT zephyr/linker.cmd -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/kernel/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/soc/atmel_sam/sam3x -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/soc/atmel_sam/sam3x/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/soc/atmel_sam/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/boards/arm/arduino_due -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/include/drivers -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/include/generated -I/opt/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/lib/arm-zephyr-eabi/gcc/arm-zephyr-eabi/6.2.0/include -I/opt/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/lib/arm-zephyr-eabi/gcc/arm-zephyr-eabi/6.2.0/include-fixed -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/lib/libc/minimal/include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/ext/hal/atmel/asf/sam/include/sam3x -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/ext/hal/cmsis/Include -I/home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/soc/atmel_sam/common/. -D__GCC_LINKER_CMD__ -E /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/arch/arm/soc/atmel_sam/sam3x/linker.ld -P -o linker.cmd

linker_script: zephyr/CMakeFiles/linker_script
linker_script: zephyr/linker.cmd
linker_script: zephyr/CMakeFiles/linker_script.dir/build.make

.PHONY : linker_script

# Rule to build all files generated by this target.
zephyr/CMakeFiles/linker_script.dir/build: linker_script

.PHONY : zephyr/CMakeFiles/linker_script.dir/build

zephyr/CMakeFiles/linker_script.dir/clean:
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr && $(CMAKE_COMMAND) -P CMakeFiles/linker_script.dir/cmake_clean.cmake
.PHONY : zephyr/CMakeFiles/linker_script.dir/clean

zephyr/CMakeFiles/linker_script.dir/depend:
	cd /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr /home/tcs/00_vinay/Zephyr/GIT_MyWork/zephyr_dev/samples/drivers/rs485_test/build/arduino_due/zephyr/CMakeFiles/linker_script.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : zephyr/CMakeFiles/linker_script.dir/depend

