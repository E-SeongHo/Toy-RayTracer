cmake_minimum_required(VERSION 3.0)

project(RayTracer)

set(CMAKE_CXX_COMPILER g++)
set(SOURCES src/main.cpp
            src/color.h
            src/ray.h
            src/vec3.h)
add_executable(${PROJECT_NAME} ${SOURCES})