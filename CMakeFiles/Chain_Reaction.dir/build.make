# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sandesh/clion-2016.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sandesh/clion-2016.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/sandesh/ClionProjects/Chain Reaction"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sandesh/ClionProjects/Chain Reaction"

# Include any dependencies generated for this target.
include CMakeFiles/Chain_Reaction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chain_Reaction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chain_Reaction.dir/flags.make

CMakeFiles/Chain_Reaction.dir/main.c.o: CMakeFiles/Chain_Reaction.dir/flags.make
CMakeFiles/Chain_Reaction.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sandesh/ClionProjects/Chain Reaction/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Chain_Reaction.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Chain_Reaction.dir/main.c.o   -c "/home/sandesh/ClionProjects/Chain Reaction/main.c"

CMakeFiles/Chain_Reaction.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Chain_Reaction.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/sandesh/ClionProjects/Chain Reaction/main.c" > CMakeFiles/Chain_Reaction.dir/main.c.i

CMakeFiles/Chain_Reaction.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Chain_Reaction.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/sandesh/ClionProjects/Chain Reaction/main.c" -o CMakeFiles/Chain_Reaction.dir/main.c.s

CMakeFiles/Chain_Reaction.dir/main.c.o.requires:

.PHONY : CMakeFiles/Chain_Reaction.dir/main.c.o.requires

CMakeFiles/Chain_Reaction.dir/main.c.o.provides: CMakeFiles/Chain_Reaction.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Chain_Reaction.dir/build.make CMakeFiles/Chain_Reaction.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Chain_Reaction.dir/main.c.o.provides

CMakeFiles/Chain_Reaction.dir/main.c.o.provides.build: CMakeFiles/Chain_Reaction.dir/main.c.o


# Object files for target Chain_Reaction
Chain_Reaction_OBJECTS = \
"CMakeFiles/Chain_Reaction.dir/main.c.o"

# External object files for target Chain_Reaction
Chain_Reaction_EXTERNAL_OBJECTS =

Chain_Reaction: CMakeFiles/Chain_Reaction.dir/main.c.o
Chain_Reaction: CMakeFiles/Chain_Reaction.dir/build.make
Chain_Reaction: CMakeFiles/Chain_Reaction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sandesh/ClionProjects/Chain Reaction/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Chain_Reaction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chain_Reaction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chain_Reaction.dir/build: Chain_Reaction

.PHONY : CMakeFiles/Chain_Reaction.dir/build

CMakeFiles/Chain_Reaction.dir/requires: CMakeFiles/Chain_Reaction.dir/main.c.o.requires

.PHONY : CMakeFiles/Chain_Reaction.dir/requires

CMakeFiles/Chain_Reaction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chain_Reaction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chain_Reaction.dir/clean

CMakeFiles/Chain_Reaction.dir/depend:
	cd "/home/sandesh/ClionProjects/Chain Reaction" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sandesh/ClionProjects/Chain Reaction" "/home/sandesh/ClionProjects/Chain Reaction" "/home/sandesh/ClionProjects/Chain Reaction" "/home/sandesh/ClionProjects/Chain Reaction" "/home/sandesh/ClionProjects/Chain Reaction/CMakeFiles/Chain_Reaction.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chain_Reaction.dir/depend

