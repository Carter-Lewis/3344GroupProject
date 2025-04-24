cmake_minimum_required(VERSION 3.27)
project(3344GroupProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(TigerGame)

add_executable(3344GroupProject
        TigerGame/BearGame.h
        TigerGame/Color.h
        TigerGame/constants.h
        TigerGame/Line.h
        TigerGame/BearGame.cpp
        TigerGame/Point.h
        TigerGame/SDL_Plotter.cpp
        TigerGame/SDL_Plotter.h
        TigerGame/Team.h
        TigerGame/TigersNTurtlenecks.h
        TigerGame/Token.h
        TigerGame/BearGame.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})