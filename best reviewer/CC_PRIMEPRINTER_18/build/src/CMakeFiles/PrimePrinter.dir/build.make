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
CMAKE_SOURCE_DIR = c:/git/CC_PRIMEPRINTER_18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = c:/git/CC_PRIMEPRINTER_18/build

# Include any dependencies generated for this target.
include src/CMakeFiles/PrimePrinter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/PrimePrinter.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/PrimePrinter.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/PrimePrinter.dir/flags.make

src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o: src/CMakeFiles/PrimePrinter.dir/flags.make
src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o: ../src/PrimePrinter.cc
src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o: src/CMakeFiles/PrimePrinter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=c:/git/CC_PRIMEPRINTER_18/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o"
	cd c:/git/CC_PRIMEPRINTER_18/build/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o -MF CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o.d -o CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o -c c:/git/CC_PRIMEPRINTER_18/src/PrimePrinter.cc

src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.i"
	cd c:/git/CC_PRIMEPRINTER_18/build/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E c:/git/CC_PRIMEPRINTER_18/src/PrimePrinter.cc > CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.i

src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.s"
	cd c:/git/CC_PRIMEPRINTER_18/build/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S c:/git/CC_PRIMEPRINTER_18/src/PrimePrinter.cc -o CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.s

# Object files for target PrimePrinter
PrimePrinter_OBJECTS = \
"CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o"

# External object files for target PrimePrinter
PrimePrinter_EXTERNAL_OBJECTS =

src/libPrimePrinter.a: src/CMakeFiles/PrimePrinter.dir/PrimePrinter.cc.o
src/libPrimePrinter.a: src/CMakeFiles/PrimePrinter.dir/build.make
src/libPrimePrinter.a: src/CMakeFiles/PrimePrinter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=c:/git/CC_PRIMEPRINTER_18/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPrimePrinter.a"
	cd c:/git/CC_PRIMEPRINTER_18/build/src && $(CMAKE_COMMAND) -P CMakeFiles/PrimePrinter.dir/cmake_clean_target.cmake
	cd c:/git/CC_PRIMEPRINTER_18/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrimePrinter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/PrimePrinter.dir/build: src/libPrimePrinter.a
.PHONY : src/CMakeFiles/PrimePrinter.dir/build

src/CMakeFiles/PrimePrinter.dir/clean:
	cd c:/git/CC_PRIMEPRINTER_18/build/src && $(CMAKE_COMMAND) -P CMakeFiles/PrimePrinter.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/PrimePrinter.dir/clean

src/CMakeFiles/PrimePrinter.dir/depend:
	cd c:/git/CC_PRIMEPRINTER_18/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" c:/git/CC_PRIMEPRINTER_18 c:/git/CC_PRIMEPRINTER_18/src c:/git/CC_PRIMEPRINTER_18/build c:/git/CC_PRIMEPRINTER_18/build/src c:/git/CC_PRIMEPRINTER_18/build/src/CMakeFiles/PrimePrinter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/PrimePrinter.dir/depend

