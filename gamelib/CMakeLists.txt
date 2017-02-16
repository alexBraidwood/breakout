cmake_minimum_required(VERSION 3.6)
project(gamelib)

add_library(gamelib "")
target_include_directories(gamelib PUBLIC include)
target_sources(gamelib PUBLIC src/GameMain.cpp)