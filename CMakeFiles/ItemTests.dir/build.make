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
include CMakeFiles/ItemTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ItemTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ItemTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ItemTests.dir/flags.make

CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o: CMakeFiles/ItemTests.dir/flags.make
CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o: testing/ItemTester.cpp
CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o: CMakeFiles/ItemTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o -MF CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o.d -o CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o -c /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp

CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp > CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.i

CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/testing/ItemTester.cpp -o CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.s

# Object files for target ItemTests
ItemTests_OBJECTS = \
"CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o"

# External object files for target ItemTests
ItemTests_EXTERNAL_OBJECTS =

ItemTests: CMakeFiles/ItemTests.dir/testing/ItemTester.cpp.o
ItemTests: CMakeFiles/ItemTests.dir/build.make
ItemTests: lib/libgtest.a
ItemTests: CMakeFiles/ItemTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ItemTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ItemTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ItemTests.dir/build: ItemTests
.PHONY : CMakeFiles/ItemTests.dir/build

CMakeFiles/ItemTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ItemTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ItemTests.dir/clean

CMakeFiles/ItemTests.dir/depend:
	cd /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133 /home/csmajs/apere594/final-project-zalam007-apere594-jnguy887-dwong133/CMakeFiles/ItemTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ItemTests.dir/depend

