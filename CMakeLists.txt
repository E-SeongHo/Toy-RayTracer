cmake_minimum_required(VERSION 3.0)

project(RayTracer)

set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/includes)
