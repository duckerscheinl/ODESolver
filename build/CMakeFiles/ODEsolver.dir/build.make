# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/lucas/CLionProjects/ODESolver/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/CLionProjects/ODESolver/build

# Include any dependencies generated for this target.
include CMakeFiles/ODEsolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ODEsolver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ODEsolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ODEsolver.dir/flags.make

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o: CMakeFiles/ODEsolver.dir/flags.make
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o: /home/lucas/CLionProjects/ODESolver/main.cpp
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o: CMakeFiles/ODEsolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o -MF CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o.d -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o -c /home/lucas/CLionProjects/ODESolver/main.cpp

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/ODESolver/main.cpp > CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.i

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/ODESolver/main.cpp -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.s

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o: CMakeFiles/ODEsolver.dir/flags.make
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o: /home/lucas/CLionProjects/ODESolver/FunctionTree.cpp
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o: CMakeFiles/ODEsolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o -MF CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o.d -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o -c /home/lucas/CLionProjects/ODESolver/FunctionTree.cpp

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/ODESolver/FunctionTree.cpp > CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.i

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/ODESolver/FunctionTree.cpp -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.s

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o: CMakeFiles/ODEsolver.dir/flags.make
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o: /home/lucas/CLionProjects/ODESolver/Parser.cpp
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o: CMakeFiles/ODEsolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o -MF CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o.d -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o -c /home/lucas/CLionProjects/ODESolver/Parser.cpp

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/ODESolver/Parser.cpp > CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.i

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/ODESolver/Parser.cpp -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.s

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o: CMakeFiles/ODEsolver.dir/flags.make
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o: /home/lucas/CLionProjects/ODESolver/ODESolver.cpp
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o: CMakeFiles/ODEsolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o -MF CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o.d -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o -c /home/lucas/CLionProjects/ODESolver/ODESolver.cpp

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/ODESolver/ODESolver.cpp > CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.i

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/ODESolver/ODESolver.cpp -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.s

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o: CMakeFiles/ODEsolver.dir/flags.make
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o: /home/lucas/CLionProjects/ODESolver/StringUtils.cpp
CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o: CMakeFiles/ODEsolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o -MF CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o.d -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o -c /home/lucas/CLionProjects/ODESolver/StringUtils.cpp

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/CLionProjects/ODESolver/StringUtils.cpp > CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.i

CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/CLionProjects/ODESolver/StringUtils.cpp -o CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.s

# Object files for target ODEsolver
ODEsolver_OBJECTS = \
"CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o" \
"CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o" \
"CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o" \
"CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o" \
"CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o"

# External object files for target ODEsolver
ODEsolver_EXTERNAL_OBJECTS =

ODEsolver: CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/main.cpp.o
ODEsolver: CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/FunctionTree.cpp.o
ODEsolver: CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/Parser.cpp.o
ODEsolver: CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/ODESolver.cpp.o
ODEsolver: CMakeFiles/ODEsolver.dir/home/lucas/CLionProjects/ODESolver/StringUtils.cpp.o
ODEsolver: CMakeFiles/ODEsolver.dir/build.make
ODEsolver: CMakeFiles/ODEsolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/CLionProjects/ODESolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ODEsolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ODEsolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ODEsolver.dir/build: ODEsolver
.PHONY : CMakeFiles/ODEsolver.dir/build

CMakeFiles/ODEsolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ODEsolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ODEsolver.dir/clean

CMakeFiles/ODEsolver.dir/depend:
	cd /home/lucas/CLionProjects/ODESolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/CLionProjects/ODESolver/build /home/lucas/CLionProjects/ODESolver/build /home/lucas/CLionProjects/ODESolver/build /home/lucas/CLionProjects/ODESolver/build /home/lucas/CLionProjects/ODESolver/build/CMakeFiles/ODEsolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ODEsolver.dir/depend
