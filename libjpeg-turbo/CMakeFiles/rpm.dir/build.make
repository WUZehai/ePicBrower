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

# Utility rule file for rpm.

# Include the progress variables for this target.
include CMakeFiles/rpm.dir/progress.make

CMakeFiles/rpm:
	pkgscripts/makerpm

rpm: CMakeFiles/rpm
rpm: CMakeFiles/rpm.dir/build.make

.PHONY : rpm

# Rule to build all files generated by this target.
CMakeFiles/rpm.dir/build: rpm

.PHONY : CMakeFiles/rpm.dir/build

CMakeFiles/rpm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rpm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rpm.dir/clean

CMakeFiles/rpm.dir/depend:
	cd /home/book/work/ePicBrower/libjpeg-turbo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles/rpm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rpm.dir/depend

