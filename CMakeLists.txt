project(MyCoolGame)

cmake_minimum_required(VERSION 3.6)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(include)
include_directories(include/SDL_CLasses)
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE MyLib)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL_Classes)

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE OFF)