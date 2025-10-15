cmake_minimum_required(VERSION 3.10)
project(TrafficLight)

add_library(MyLib STATIC 
    traficlight.h
    traficlight.cpp
)

add_executable(main main.cpp)

target_link_libraries(main MyLib)
target_include_directories(main PUBLIC .)