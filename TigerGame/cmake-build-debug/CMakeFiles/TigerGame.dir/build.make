# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TigerGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TigerGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TigerGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TigerGame.dir/flags.make

CMakeFiles/TigerGame.dir/main.cpp.o: CMakeFiles/TigerGame.dir/flags.make
CMakeFiles/TigerGame.dir/main.cpp.o: /Users/carterlewis/Files/Baylor/CSI/CSI\ 3344/TigerGame/main.cpp
CMakeFiles/TigerGame.dir/main.cpp.o: CMakeFiles/TigerGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TigerGame.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TigerGame.dir/main.cpp.o -MF CMakeFiles/TigerGame.dir/main.cpp.o.d -o CMakeFiles/TigerGame.dir/main.cpp.o -c "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/main.cpp"

CMakeFiles/TigerGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TigerGame.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/main.cpp" > CMakeFiles/TigerGame.dir/main.cpp.i

CMakeFiles/TigerGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TigerGame.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/main.cpp" -o CMakeFiles/TigerGame.dir/main.cpp.s

CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o: CMakeFiles/TigerGame.dir/flags.make
CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o: /Users/carterlewis/Files/Baylor/CSI/CSI\ 3344/TigerGame/SDL_Plotter.cpp
CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o: CMakeFiles/TigerGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o -MF CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o.d -o CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o -c "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/SDL_Plotter.cpp"

CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/SDL_Plotter.cpp" > CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.i

CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/SDL_Plotter.cpp" -o CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.s

CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o: CMakeFiles/TigerGame.dir/flags.make
CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o: /Users/carterlewis/Files/Baylor/CSI/CSI\ 3344/TigersNTurtlenecks/tigerGame/main.cpp
CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o: CMakeFiles/TigerGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o -MF CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o.d -o CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o -c "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigersNTurtlenecks/tigerGame/main.cpp"

CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigersNTurtlenecks/tigerGame/main.cpp" > CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.i

CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigersNTurtlenecks/tigerGame/main.cpp" -o CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.s

# Object files for target TigerGame
TigerGame_OBJECTS = \
"CMakeFiles/TigerGame.dir/main.cpp.o" \
"CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o" \
"CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o"

# External object files for target TigerGame
TigerGame_EXTERNAL_OBJECTS =

TigerGame: CMakeFiles/TigerGame.dir/main.cpp.o
TigerGame: CMakeFiles/TigerGame.dir/SDL_Plotter.cpp.o
TigerGame: CMakeFiles/TigerGame.dir/Users/carterlewis/Files/Baylor/CSI/CSI_3344/TigersNTurtlenecks/tigerGame/main.cpp.o
TigerGame: CMakeFiles/TigerGame.dir/build.make
TigerGame: /opt/homebrew/Cellar/sdl2/2.30.11/lib/libSDL2.dylib
TigerGame: CMakeFiles/TigerGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TigerGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TigerGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TigerGame.dir/build: TigerGame
.PHONY : CMakeFiles/TigerGame.dir/build

CMakeFiles/TigerGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TigerGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TigerGame.dir/clean

CMakeFiles/TigerGame.dir/depend:
	cd "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame" "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame" "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug" "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug" "/Users/carterlewis/Files/Baylor/CSI/CSI 3344/TigerGame/cmake-build-debug/CMakeFiles/TigerGame.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/TigerGame.dir/depend

