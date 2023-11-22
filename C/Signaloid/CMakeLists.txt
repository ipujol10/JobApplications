cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE release)

set(PROJECT_NAME Signaloid)

project(${PROJECT_NAME} VERSION 1.0)

add_executable(out main.c)
