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
CMAKE_SOURCE_DIR = /cygdrive/c/git/RF_EXAM_18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/git/RF_EXAM_18

# Include any dependencies generated for this target.
include src/CMakeFiles/StatementPrinter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/StatementPrinter.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/StatementPrinter.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/StatementPrinter.dir/flags.make

src/CMakeFiles/StatementPrinter.dir/Play.cpp.o: src/CMakeFiles/StatementPrinter.dir/flags.make
src/CMakeFiles/StatementPrinter.dir/Play.cpp.o: src/Play.cpp
src/CMakeFiles/StatementPrinter.dir/Play.cpp.o: src/CMakeFiles/StatementPrinter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/RF_EXAM_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/StatementPrinter.dir/Play.cpp.o"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StatementPrinter.dir/Play.cpp.o -MF CMakeFiles/StatementPrinter.dir/Play.cpp.o.d -o CMakeFiles/StatementPrinter.dir/Play.cpp.o -c /cygdrive/c/git/RF_EXAM_18/src/Play.cpp

src/CMakeFiles/StatementPrinter.dir/Play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StatementPrinter.dir/Play.cpp.i"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/RF_EXAM_18/src/Play.cpp > CMakeFiles/StatementPrinter.dir/Play.cpp.i

src/CMakeFiles/StatementPrinter.dir/Play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StatementPrinter.dir/Play.cpp.s"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/RF_EXAM_18/src/Play.cpp -o CMakeFiles/StatementPrinter.dir/Play.cpp.s

src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o: src/CMakeFiles/StatementPrinter.dir/flags.make
src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o: src/PlayType.cpp
src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o: src/CMakeFiles/StatementPrinter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/RF_EXAM_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o -MF CMakeFiles/StatementPrinter.dir/PlayType.cpp.o.d -o CMakeFiles/StatementPrinter.dir/PlayType.cpp.o -c /cygdrive/c/git/RF_EXAM_18/src/PlayType.cpp

src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StatementPrinter.dir/PlayType.cpp.i"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/RF_EXAM_18/src/PlayType.cpp > CMakeFiles/StatementPrinter.dir/PlayType.cpp.i

src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StatementPrinter.dir/PlayType.cpp.s"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/RF_EXAM_18/src/PlayType.cpp -o CMakeFiles/StatementPrinter.dir/PlayType.cpp.s

src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o: src/CMakeFiles/StatementPrinter.dir/flags.make
src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o: src/StatementPrinter.cpp
src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o: src/CMakeFiles/StatementPrinter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/git/RF_EXAM_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o -MF CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o.d -o CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o -c /cygdrive/c/git/RF_EXAM_18/src/StatementPrinter.cpp

src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.i"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/git/RF_EXAM_18/src/StatementPrinter.cpp > CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.i

src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.s"
	cd /cygdrive/c/git/RF_EXAM_18/src && /usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/git/RF_EXAM_18/src/StatementPrinter.cpp -o CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.s

# Object files for target StatementPrinter
StatementPrinter_OBJECTS = \
"CMakeFiles/StatementPrinter.dir/Play.cpp.o" \
"CMakeFiles/StatementPrinter.dir/PlayType.cpp.o" \
"CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o"

# External object files for target StatementPrinter
StatementPrinter_EXTERNAL_OBJECTS =

src/libStatementPrinter.a: src/CMakeFiles/StatementPrinter.dir/Play.cpp.o
src/libStatementPrinter.a: src/CMakeFiles/StatementPrinter.dir/PlayType.cpp.o
src/libStatementPrinter.a: src/CMakeFiles/StatementPrinter.dir/StatementPrinter.cpp.o
src/libStatementPrinter.a: src/CMakeFiles/StatementPrinter.dir/build.make
src/libStatementPrinter.a: src/CMakeFiles/StatementPrinter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/git/RF_EXAM_18/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libStatementPrinter.a"
	cd /cygdrive/c/git/RF_EXAM_18/src && $(CMAKE_COMMAND) -P CMakeFiles/StatementPrinter.dir/cmake_clean_target.cmake
	cd /cygdrive/c/git/RF_EXAM_18/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StatementPrinter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/StatementPrinter.dir/build: src/libStatementPrinter.a
.PHONY : src/CMakeFiles/StatementPrinter.dir/build

src/CMakeFiles/StatementPrinter.dir/clean:
	cd /cygdrive/c/git/RF_EXAM_18/src && $(CMAKE_COMMAND) -P CMakeFiles/StatementPrinter.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/StatementPrinter.dir/clean

src/CMakeFiles/StatementPrinter.dir/depend:
	cd /cygdrive/c/git/RF_EXAM_18 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/git/RF_EXAM_18 /cygdrive/c/git/RF_EXAM_18/src /cygdrive/c/git/RF_EXAM_18 /cygdrive/c/git/RF_EXAM_18/src /cygdrive/c/git/RF_EXAM_18/src/CMakeFiles/StatementPrinter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/StatementPrinter.dir/depend

