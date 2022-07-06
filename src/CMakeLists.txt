#project(MyLib VERSION 1.0.1 DESCRIPTION "Libs")
project(MyLib)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set (CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)

include_directories(../include/Geometry_Classes)
include_directories(../include/Ship_Classes)
include_directories(../include)

include_directories(../include/SDL_CLasses)

add_subdirectory(SDL_Classes)
add_subdirectory(Geometry_Classes)
add_library(MyLib SHARED  Geometry_Classes SDL_Classes Game.cpp Map.cpp Island.cpp Image.cpp Object.cpp Event.cpp Ship_Classes/Ship.cpp Ship_Classes/Sails.cpp Ship_Classes/ShipObject.cpp Ship_Classes/Cannon.cpp Ship_Classes/CannonBall.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Geometry_Classes)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL_Classes)

#include_directories(../assets)
#target_link_libraries(${PROJECT_NAME} PRIVATE MyAssets)
