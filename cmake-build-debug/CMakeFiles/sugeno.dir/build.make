# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sugeno.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sugeno.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sugeno.dir/flags.make

CMakeFiles/sugeno.dir/src/main.cpp.obj: CMakeFiles/sugeno.dir/flags.make
CMakeFiles/sugeno.dir/src/main.cpp.obj: CMakeFiles/sugeno.dir/includes_CXX.rsp
CMakeFiles/sugeno.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sugeno.dir/src/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sugeno.dir\src\main.cpp.obj -c D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\src\main.cpp

CMakeFiles/sugeno.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sugeno.dir/src/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\src\main.cpp > CMakeFiles\sugeno.dir\src\main.cpp.i

CMakeFiles/sugeno.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sugeno.dir/src/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\src\main.cpp -o CMakeFiles\sugeno.dir\src\main.cpp.s

# Object files for target sugeno
sugeno_OBJECTS = \
"CMakeFiles/sugeno.dir/src/main.cpp.obj"

# External object files for target sugeno
sugeno_EXTERNAL_OBJECTS =

../bin/sugeno.exe: CMakeFiles/sugeno.dir/src/main.cpp.obj
../bin/sugeno.exe: CMakeFiles/sugeno.dir/build.make
../bin/sugeno.exe: CMakeFiles/sugeno.dir/linklibs.rsp
../bin/sugeno.exe: CMakeFiles/sugeno.dir/objects1.rsp
../bin/sugeno.exe: CMakeFiles/sugeno.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\sugeno.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sugeno.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sugeno.dir/build: ../bin/sugeno.exe

.PHONY : CMakeFiles/sugeno.dir/build

CMakeFiles/sugeno.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sugeno.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sugeno.dir/clean

CMakeFiles/sugeno.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug D:\ENSISA\2A\Projets\Fuzzy\Fuzzy_Project\cmake-build-debug\CMakeFiles\sugeno.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sugeno.dir/depend

