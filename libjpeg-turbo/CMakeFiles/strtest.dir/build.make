# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/cmake

# The command to remove a file.
RM = /home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/book/work/ePicBrower/libjpeg-turbo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/book/work/ePicBrower/libjpeg-turbo

# Include any dependencies generated for this target.
include CMakeFiles/strtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/strtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strtest.dir/flags.make

CMakeFiles/strtest.dir/strtest.c.o: CMakeFiles/strtest.dir/flags.make
CMakeFiles/strtest.dir/strtest.c.o: strtest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/strtest.dir/strtest.c.o"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strtest.dir/strtest.c.o   -c /home/book/work/ePicBrower/libjpeg-turbo/strtest.c

CMakeFiles/strtest.dir/strtest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strtest.dir/strtest.c.i"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/book/work/ePicBrower/libjpeg-turbo/strtest.c > CMakeFiles/strtest.dir/strtest.c.i

CMakeFiles/strtest.dir/strtest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strtest.dir/strtest.c.s"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/book/work/ePicBrower/libjpeg-turbo/strtest.c -o CMakeFiles/strtest.dir/strtest.c.s

# Object files for target strtest
strtest_OBJECTS = \
"CMakeFiles/strtest.dir/strtest.c.o"

# External object files for target strtest
strtest_EXTERNAL_OBJECTS =

strtest: CMakeFiles/strtest.dir/strtest.c.o
strtest: CMakeFiles/strtest.dir/build.make
strtest: CMakeFiles/strtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable strtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strtest.dir/build: strtest

.PHONY : CMakeFiles/strtest.dir/build

CMakeFiles/strtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strtest.dir/clean

CMakeFiles/strtest.dir/depend:
	cd /home/book/work/ePicBrower/libjpeg-turbo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles/strtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/strtest.dir/depend

