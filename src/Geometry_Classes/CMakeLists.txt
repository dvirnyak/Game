project(Geometry_Classes)

cmake_minimum_required(VERSION 3.6)

include_directories(../../include/Geometry_CLasses)
include_directories(../../include)

add_library(${PROJECT_NAME} SHARED Coordinates.cpp Sizes.cpp Vector2D.cpp)