# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/git/GtestExample-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/git/GtestExample-master

# Include any dependencies generated for this target.
include test/CMakeFiles/FriendTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/FriendTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/FriendTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/FriendTest.dir/flags.make

test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o: test/CMakeFiles/FriendTest.dir/flags.make
test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o: test/FriendTest.cpp
test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o: test/CMakeFiles/FriendTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o -MF CMakeFiles/FriendTest.dir/FriendTest.cpp.o.d -o CMakeFiles/FriendTest.dir/FriendTest.cpp.o -c /cygdrive/c/git/GtestExample-master/test/FriendTest.cpp

test/CMakeFiles/FriendTest.dir/FriendTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendTest.dir/FriendTest.cpp.i"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/GtestExample-master/test/FriendTest.cpp > CMakeFiles/FriendTest.dir/FriendTest.cpp.i

test/CMakeFiles/FriendTest.dir/FriendTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendTest.dir/FriendTest.cpp.s"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/GtestExample-master/test/FriendTest.cpp -o CMakeFiles/FriendTest.dir/FriendTest.cpp.s

# Object files for target FriendTest
FriendTest_OBJECTS = \
"CMakeFiles/FriendTest.dir/FriendTest.cpp.o"

# External object files for target FriendTest
FriendTest_EXTERNAL_OBJECTS =

test/FriendTest.exe: test/CMakeFiles/FriendTest.dir/FriendTest.cpp.o
test/FriendTest.exe: test/CMakeFiles/FriendTest.dir/build.make
test/FriendTest.exe: src/libGtestSample.a
test/FriendTest.exe: test/CMakeFiles/FriendTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FriendTest.exe"
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FriendTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/FriendTest.dir/build: test/FriendTest.exe
.PHONY : test/CMakeFiles/FriendTest.dir/build

test/CMakeFiles/FriendTest.dir/clean:
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -P CMakeFiles/FriendTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/FriendTest.dir/clean

test/CMakeFiles/FriendTest.dir/depend:
	cd /cygdrive/c/git/GtestExample-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master/test/CMakeFiles/FriendTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/FriendTest.dir/depend

