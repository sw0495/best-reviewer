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
CMAKE_SOURCE_DIR = /cygdrive/c/git/HelloWorld_18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/git/HelloWorld_18

# Include any dependencies generated for this target.
include src/CMakeFiles/HelloWorld.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/HelloWorld.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/HelloWorld.dir/flags.make

src/CMakeFiles/HelloWorld.dir/hello.cpp.o: src/CMakeFiles/HelloWorld.dir/flags.make
src/CMakeFiles/HelloWorld.dir/hello.cpp.o: src/hello.cpp
src/CMakeFiles/HelloWorld.dir/hello.cpp.o: src/CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/HelloWorld_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/HelloWorld.dir/hello.cpp.o"
	cd /cygdrive/c/git/HelloWorld_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/HelloWorld.dir/hello.cpp.o -MF CMakeFiles/HelloWorld.dir/hello.cpp.o.d -o CMakeFiles/HelloWorld.dir/hello.cpp.o -c /cygdrive/c/git/HelloWorld_18/src/hello.cpp

src/CMakeFiles/HelloWorld.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/hello.cpp.i"
	cd /cygdrive/c/git/HelloWorld_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/HelloWorld_18/src/hello.cpp > CMakeFiles/HelloWorld.dir/hello.cpp.i

src/CMakeFiles/HelloWorld.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/hello.cpp.s"
	cd /cygdrive/c/git/HelloWorld_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/HelloWorld_18/src/hello.cpp -o CMakeFiles/HelloWorld.dir/hello.cpp.s

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/hello.cpp.o"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

src/libHelloWorld.a: src/CMakeFiles/HelloWorld.dir/hello.cpp.o
src/libHelloWorld.a: src/CMakeFiles/HelloWorld.dir/build.make
src/libHelloWorld.a: src/CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/HelloWorld_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHelloWorld.a"
	cd /cygdrive/c/git/HelloWorld_18/src && $(CMAKE_COMMAND) -P CMakeFiles/HelloWorld.dir/cmake_clean_target.cmake
	cd /cygdrive/c/git/HelloWorld_18/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/HelloWorld.dir/build: src/libHelloWorld.a
.PHONY : src/CMakeFiles/HelloWorld.dir/build

src/CMakeFiles/HelloWorld.dir/clean:
	cd /cygdrive/c/git/HelloWorld_18/src && $(CMAKE_COMMAND) -P CMakeFiles/HelloWorld.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/HelloWorld.dir/clean

src/CMakeFiles/HelloWorld.dir/depend:
	cd /cygdrive/c/git/HelloWorld_18 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/HelloWorld_18 /cygdrive/c/git/HelloWorld_18/src /cygdrive/c/git/HelloWorld_18 /cygdrive/c/git/HelloWorld_18/src /cygdrive/c/git/HelloWorld_18/src/CMakeFiles/HelloWorld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/HelloWorld.dir/depend

