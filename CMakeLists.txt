cmake_minimum_required(VERSION 3.27)
project(3344GroupProject)

set(CMAKE_CXX_STANDARD 14)

# Optional: Help CMake find SDL2 installed via Homebrew (especially on Apple Silicon)
set(CMAKE_PREFIX_PATH "/usr/local/opt/sdl2")

# Add your source files
include_directories(TigerGame)

add_executable(3344GroupProject
        TigerGame/BearGame.cpp
        TigerGame/BearGame.h
        TigerGame/Color.h
        TigerGame/constants.h
        TigerGame/Line.h
        TigerGame/Point.h
        TigerGame/SDL_Plotter.cpp
        TigerGame/SDL_Plotter.h
        TigerGame/Team.h
        TigerGame/TigersNTurtlenecks.h
        TigerGame/Token.h
)

# Find and link SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(3344GroupProject ${SDL2_LIBRARIES})
