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
include CMakeFiles/tjexample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tjexample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tjexample.dir/flags.make

CMakeFiles/tjexample.dir/tjexample.c.o: CMakeFiles/tjexample.dir/flags.make
CMakeFiles/tjexample.dir/tjexample.c.o: tjexample.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tjexample.dir/tjexample.c.o"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tjexample.dir/tjexample.c.o   -c /home/book/work/ePicBrower/libjpeg-turbo/tjexample.c

CMakeFiles/tjexample.dir/tjexample.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tjexample.dir/tjexample.c.i"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/book/work/ePicBrower/libjpeg-turbo/tjexample.c > CMakeFiles/tjexample.dir/tjexample.c.i

CMakeFiles/tjexample.dir/tjexample.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tjexample.dir/tjexample.c.s"
	/home/book/work/100ask_stm32mp157_pro-sdk/ToolChain/arm-buildroot-linux-gnueabihf_sdk-buildroot/bin/arm-buildroot-linux-gnueabihf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/book/work/ePicBrower/libjpeg-turbo/tjexample.c -o CMakeFiles/tjexample.dir/tjexample.c.s

# Object files for target tjexample
tjexample_OBJECTS = \
"CMakeFiles/tjexample.dir/tjexample.c.o"

# External object files for target tjexample
tjexample_EXTERNAL_OBJECTS =

tjexample: CMakeFiles/tjexample.dir/tjexample.c.o
tjexample: CMakeFiles/tjexample.dir/build.make
tjexample: libturbojpeg.so.0.2.0
tjexample: CMakeFiles/tjexample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tjexample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tjexample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tjexample.dir/build: tjexample

.PHONY : CMakeFiles/tjexample.dir/build

CMakeFiles/tjexample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tjexample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tjexample.dir/clean

CMakeFiles/tjexample.dir/depend:
	cd /home/book/work/ePicBrower/libjpeg-turbo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles/tjexample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tjexample.dir/depend

