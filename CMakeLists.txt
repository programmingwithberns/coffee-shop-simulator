cmake_minimum_required(VERSION 3.29)
project(CoffeeShopProgram LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC_FILES src/*.cpp)

message(STATUS "SRC FILES ARE ${SRC_FILES}")

add_executable(app ${SRC_FILES} main.cpp)

# for testing
enable_testing()
add_subdirectory(test)