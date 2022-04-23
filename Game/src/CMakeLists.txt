#project(MyLib VERSION 1.0.1 DESCRIPTION "Libs")
project(MyLib)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_subdirectory(SDL_Classes)
add_library(MyLib SHARED SDL_Classes Game.cpp Coordinates.cpp Sizes.cpp Image.cpp Object.cpp Event.cpp Ship.cpp Vector2D.cpp Sails.cpp ShipObject.cpp)

#include_directories(../assets)
#target_link_libraries(${PROJECT_NAME} PRIVATE MyAssets)

include_directories(../include/SDL_CLasses)
include_directories(../include)
