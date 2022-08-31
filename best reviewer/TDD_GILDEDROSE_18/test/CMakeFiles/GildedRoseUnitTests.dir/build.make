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
CMAKE_SOURCE_DIR = /cygdrive/c/git/TDD_GILDEDROSE_18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/git/TDD_GILDEDROSE_18

# Include any dependencies generated for this target.
include test/CMakeFiles/GildedRoseUnitTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/GildedRoseUnitTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/GildedRoseUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/GildedRoseUnitTests.dir/flags.make

test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o: test/CMakeFiles/GildedRoseUnitTests.dir/flags.make
test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o: test/GildedRoseUnitTests.cc
test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o: test/CMakeFiles/GildedRoseUnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/TDD_GILDEDROSE_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o"
	cd /cygdrive/c/git/TDD_GILDEDROSE_18/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o -MF CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o.d -o CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o -c /cygdrive/c/git/TDD_GILDEDROSE_18/test/GildedRoseUnitTests.cc

test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.i"
	cd /cygdrive/c/git/TDD_GILDEDROSE_18/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/TDD_GILDEDROSE_18/test/GildedRoseUnitTests.cc > CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.i

test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.s"
	cd /cygdrive/c/git/TDD_GILDEDROSE_18/test && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/TDD_GILDEDROSE_18/test/GildedRoseUnitTests.cc -o CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.s

# Object files for target GildedRoseUnitTests
GildedRoseUnitTests_OBJECTS = \
"CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o"

# External object files for target GildedRoseUnitTests
GildedRoseUnitTests_EXTERNAL_OBJECTS =

test/GildedRoseUnitTests.exe: test/CMakeFiles/GildedRoseUnitTests.dir/GildedRoseUnitTests.cc.o
test/GildedRoseUnitTests.exe: test/CMakeFiles/GildedRoseUnitTests.dir/build.make
test/GildedRoseUnitTests.exe: src/libGildedRose.a
test/GildedRoseUnitTests.exe: test/CMakeFiles/GildedRoseUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/TDD_GILDEDROSE_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GildedRoseUnitTests.exe"
	cd /cygdrive/c/git/TDD_GILDEDROSE_18/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GildedRoseUnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/GildedRoseUnitTests.dir/build: test/GildedRoseUnitTests.exe
.PHONY : test/CMakeFiles/GildedRoseUnitTests.dir/build

test/CMakeFiles/GildedRoseUnitTests.dir/clean:
	cd /cygdrive/c/git/TDD_GILDEDROSE_18/test && $(CMAKE_COMMAND) -P CMakeFiles/GildedRoseUnitTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/GildedRoseUnitTests.dir/clean

test/CMakeFiles/GildedRoseUnitTests.dir/depend:
	cd /cygdrive/c/git/TDD_GILDEDROSE_18 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/TDD_GILDEDROSE_18 /cygdrive/c/git/TDD_GILDEDROSE_18/test /cygdrive/c/git/TDD_GILDEDROSE_18 /cygdrive/c/git/TDD_GILDEDROSE_18/test /cygdrive/c/git/TDD_GILDEDROSE_18/test/CMakeFiles/GildedRoseUnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/GildedRoseUnitTests.dir/depend

