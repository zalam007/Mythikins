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
CMAKE_BINARY_DIR = /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build

# Include any dependencies generated for this target.
include CMakeFiles/MythikinTester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MythikinTester.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MythikinTester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MythikinTester.dir/flags.make

CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o: CMakeFiles/MythikinTester.dir/flags.make
CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o: /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/MythikinTester.cpp
CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o: CMakeFiles/MythikinTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o -MF CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o.d -o CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/MythikinTester.cpp

CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/MythikinTester.cpp > CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.i

CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/MythikinTester.cpp -o CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.s

# Object files for target MythikinTester
MythikinTester_OBJECTS = \
"CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o"

# External object files for target MythikinTester
MythikinTester_EXTERNAL_OBJECTS =

MythikinTester: CMakeFiles/MythikinTester.dir/testing/MythikinTester.cpp.o
MythikinTester: CMakeFiles/MythikinTester.dir/build.make
MythikinTester: lib/libgtest.a
MythikinTester: CMakeFiles/MythikinTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MythikinTester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MythikinTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MythikinTester.dir/build: MythikinTester
.PHONY : CMakeFiles/MythikinTester.dir/build

CMakeFiles/MythikinTester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MythikinTester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MythikinTester.dir/clean

CMakeFiles/MythikinTester.dir/depend:
	cd /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles/MythikinTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MythikinTester.dir/depend

