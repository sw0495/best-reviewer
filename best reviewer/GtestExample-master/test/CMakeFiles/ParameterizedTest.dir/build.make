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
include test/CMakeFiles/ParameterizedTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/ParameterizedTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/ParameterizedTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/ParameterizedTest.dir/flags.make

test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o: test/CMakeFiles/ParameterizedTest.dir/flags.make
test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o: test/ParameterizedTest.cpp
test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o: test/CMakeFiles/ParameterizedTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o -MF CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o.d -o CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o -c /cygdrive/c/git/GtestExample-master/test/ParameterizedTest.cpp

test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.i"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/GtestExample-master/test/ParameterizedTest.cpp > CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.i

test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.s"
	cd /cygdrive/c/git/GtestExample-master/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/GtestExample-master/test/ParameterizedTest.cpp -o CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.s

# Object files for target ParameterizedTest
ParameterizedTest_OBJECTS = \
"CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o"

# External object files for target ParameterizedTest
ParameterizedTest_EXTERNAL_OBJECTS =

test/ParameterizedTest.exe: test/CMakeFiles/ParameterizedTest.dir/ParameterizedTest.cpp.o
test/ParameterizedTest.exe: test/CMakeFiles/ParameterizedTest.dir/build.make
test/ParameterizedTest.exe: src/libGtestSample.a
test/ParameterizedTest.exe: test/CMakeFiles/ParameterizedTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/GtestExample-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ParameterizedTest.exe"
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParameterizedTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/ParameterizedTest.dir/build: test/ParameterizedTest.exe
.PHONY : test/CMakeFiles/ParameterizedTest.dir/build

test/CMakeFiles/ParameterizedTest.dir/clean:
	cd /cygdrive/c/git/GtestExample-master/test && $(CMAKE_COMMAND) -P CMakeFiles/ParameterizedTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/ParameterizedTest.dir/clean

test/CMakeFiles/ParameterizedTest.dir/depend:
	cd /cygdrive/c/git/GtestExample-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master /cygdrive/c/git/GtestExample-master/test /cygdrive/c/git/GtestExample-master/test/CMakeFiles/ParameterizedTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/ParameterizedTest.dir/depend

