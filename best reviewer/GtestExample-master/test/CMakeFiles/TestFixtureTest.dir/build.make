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
include test/CMakeFiles/TestFixtureTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/TestFixtureTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/TestFixtureTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/TestFixtureTest.dir/flags.make

test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o: test/CMakeFiles/TestFixtureTest.dir/flags.make
test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o: test/TestFixtureTest.cpp
test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o: test/CMakeFiles/TestFixtureTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o -MF CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o.d -o CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o -c /cygdrive/c/git/GtestExample-master/test/TestFixtureTest.cpp

test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.i"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/GtestExample-master/test/TestFixtureTest.cpp > CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.i

test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.s"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/GtestExample-master/test/TestFixtureTest.cpp -o CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.s

# Object files for target TestFixtureTest
TestFixtureTest_OBJECTS = \
"CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o"

# External object files for target TestFixtureTest
TestFixtureTest_EXTERNAL_OBJECTS =

test/TestFixtureTest.exe: test/CMakeFiles/TestFixtureTest.dir/TestFixtureTest.cpp.o
test/TestFixtureTest.exe: test/CMakeFiles/TestFixtureTest.dir/build.make
test/TestFixtureTest.exe: src/libGtestSample.a
test/TestFixtureTest.exe: test/CMakeFiles/TestFixtureTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestFixtureTest.exe"
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestFixtureTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/TestFixtureTest.dir/build: test/TestFixtureTest.exe
.PHONY : test/CMakeFiles/TestFixtureTest.dir/build

test/CMakeFiles/TestFixtureTest.dir/clean:
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -P CMakeFiles/TestFixtureTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/TestFixtureTest.dir/clean

test/CMakeFiles/TestFixtureTest.dir/depend:
	cd /cygdrive/c/git/GtestExample-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master/test/CMakeFiles/TestFixtureTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/TestFixtureTest.dir/depend

