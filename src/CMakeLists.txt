#project(MyLib VERSION 1.0.1 DESCRIPTION "Libs")
project(MyLib)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set (CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)

add_subdirectory(SDL_Classes)
add_library(MyLib SHARED SDL_Classes Game.cpp Coordinates.cpp Sizes.cpp Image.cpp Object.cpp Event.cpp Ship.cpp Vector2D.cpp Sails.cpp ShipObject.cpp Map.cpp Island.cpp Cannon.cpp CannonBall.cpp)

#include_directories(../assets)
#target_link_libraries(${PROJECT_NAME} PRIVATE MyAssets)

include_directories(../include/SDL_CLasses)
include_directories(../include)
