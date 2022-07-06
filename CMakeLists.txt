project(MyCoolGame)

cmake_minimum_required(VERSION 3.6)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(include/Geometry_CLasses)
include_directories(include)
include_directories(include/Ship_Classes)
include_directories(include/SDL_CLasses)



target_link_libraries(${PROJECT_NAME} PRIVATE Geometry_Classes)
target_link_libraries(${PROJECT_NAME} PRIVATE MyLib)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL_Classes)


set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE OFF)