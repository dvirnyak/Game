project(SDL_Classes)

cmake_minimum_required(VERSION 3.6)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(../../include/SDL_CLasses)
include_directories(../../include)

add_library(${PROJECT_NAME} SHARED SDL_Interface.cpp GameObject.cpp TextureManager.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

