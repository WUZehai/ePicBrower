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

# Utility rule file for tarball.

# Include the progress variables for this target.
include CMakeFiles/tarball.dir/progress.make

CMakeFiles/tarball:
	pkgscripts/maketarball

tarball: CMakeFiles/tarball
tarball: CMakeFiles/tarball.dir/build.make

.PHONY : tarball

# Rule to build all files generated by this target.
CMakeFiles/tarball.dir/build: tarball

.PHONY : CMakeFiles/tarball.dir/build

CMakeFiles/tarball.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tarball.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tarball.dir/clean

CMakeFiles/tarball.dir/depend:
	cd /home/book/work/ePicBrower/libjpeg-turbo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo /home/book/work/ePicBrower/libjpeg-turbo/CMakeFiles/tarball.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tarball.dir/depend

