cmake_minimum_required(VERSION 3.16.1)

project(simple-ecs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(simple-ecs ${SOURCE_FILES})
