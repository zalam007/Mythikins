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
include CMakeFiles/ItemTester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ItemTester.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ItemTester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ItemTester.dir/flags.make

CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o: CMakeFiles/ItemTester.dir/flags.make
CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o: /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp
CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o: CMakeFiles/ItemTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o -MF CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o.d -o CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp

CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp > CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.i

CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp -o CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.s

# Object files for target ItemTester
ItemTester_OBJECTS = \
"CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o"

# External object files for target ItemTester
ItemTester_EXTERNAL_OBJECTS =

ItemTester: CMakeFiles/ItemTester.dir/testing/ItemTester.cpp.o
ItemTester: CMakeFiles/ItemTester.dir/build.make
ItemTester: lib/libgtest.a
ItemTester: CMakeFiles/ItemTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ItemTester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ItemTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ItemTester.dir/build: ItemTester
.PHONY : CMakeFiles/ItemTester.dir/build

CMakeFiles/ItemTester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ItemTester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ItemTester.dir/clean

CMakeFiles/ItemTester.dir/depend:
	cd /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/build/CMakeFiles/ItemTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ItemTester.dir/depend

