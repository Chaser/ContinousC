cmake_minimum_required(VERSION 2.8)
project(ContinousC)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(SOURCE_FILES main.c)

add_executable(ContinousC ${SOURCE_FILES})
