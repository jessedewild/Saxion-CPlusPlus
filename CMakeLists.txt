cmake_minimum_required(VERSION 3.15)
project(Saxion-CPlusPlus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(Week1 Week1/src/main.cpp Week1/src/io/io.cpp Week2/SortingAlgorithm/src/main.cpp)
add_executable(Week2-ArraysAndPointers Week2/ArraysAndPointers/src/main.cpp)
add_executable(Week2-SortingAlgorithm Week2/SortingAlgorithm/src/main.cpp)
add_executable(Week3-Blackjack Week3/main.cpp)