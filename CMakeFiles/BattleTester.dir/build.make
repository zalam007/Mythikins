# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133

# Include any dependencies generated for this target.
include CMakeFiles/BattleTester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BattleTester.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BattleTester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BattleTester.dir/flags.make

CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o: CMakeFiles/BattleTester.dir/flags.make
CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o: testing/BattleTester.cpp
CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o: CMakeFiles/BattleTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o -MF CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o.d -o CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/BattleTester.cpp

CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/BattleTester.cpp > CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.i

CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/BattleTester.cpp -o CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.s

CMakeFiles/BattleTester.dir/src/Battle.cpp.o: CMakeFiles/BattleTester.dir/flags.make
CMakeFiles/BattleTester.dir/src/Battle.cpp.o: src/Battle.cpp
CMakeFiles/BattleTester.dir/src/Battle.cpp.o: CMakeFiles/BattleTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BattleTester.dir/src/Battle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BattleTester.dir/src/Battle.cpp.o -MF CMakeFiles/BattleTester.dir/src/Battle.cpp.o.d -o CMakeFiles/BattleTester.dir/src/Battle.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Battle.cpp

CMakeFiles/BattleTester.dir/src/Battle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BattleTester.dir/src/Battle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Battle.cpp > CMakeFiles/BattleTester.dir/src/Battle.cpp.i

CMakeFiles/BattleTester.dir/src/Battle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BattleTester.dir/src/Battle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Battle.cpp -o CMakeFiles/BattleTester.dir/src/Battle.cpp.s

CMakeFiles/BattleTester.dir/src/Team.cpp.o: CMakeFiles/BattleTester.dir/flags.make
CMakeFiles/BattleTester.dir/src/Team.cpp.o: src/Team.cpp
CMakeFiles/BattleTester.dir/src/Team.cpp.o: CMakeFiles/BattleTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BattleTester.dir/src/Team.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BattleTester.dir/src/Team.cpp.o -MF CMakeFiles/BattleTester.dir/src/Team.cpp.o.d -o CMakeFiles/BattleTester.dir/src/Team.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Team.cpp

CMakeFiles/BattleTester.dir/src/Team.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BattleTester.dir/src/Team.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Team.cpp > CMakeFiles/BattleTester.dir/src/Team.cpp.i

CMakeFiles/BattleTester.dir/src/Team.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BattleTester.dir/src/Team.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/src/Team.cpp -o CMakeFiles/BattleTester.dir/src/Team.cpp.s

# Object files for target BattleTester
BattleTester_OBJECTS = \
"CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o" \
"CMakeFiles/BattleTester.dir/src/Battle.cpp.o" \
"CMakeFiles/BattleTester.dir/src/Team.cpp.o"

# External object files for target BattleTester
BattleTester_EXTERNAL_OBJECTS =

BattleTester: CMakeFiles/BattleTester.dir/testing/BattleTester.cpp.o
BattleTester: CMakeFiles/BattleTester.dir/src/Battle.cpp.o
BattleTester: CMakeFiles/BattleTester.dir/src/Team.cpp.o
BattleTester: CMakeFiles/BattleTester.dir/build.make
BattleTester: lib/libgtest.a
BattleTester: CMakeFiles/BattleTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BattleTester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BattleTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BattleTester.dir/build: BattleTester
.PHONY : CMakeFiles/BattleTester.dir/build

CMakeFiles/BattleTester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BattleTester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BattleTester.dir/clean

CMakeFiles/BattleTester.dir/depend:
	cd /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles/BattleTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BattleTester.dir/depend
