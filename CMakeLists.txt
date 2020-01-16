cmake_minimum_required(VERSION 3.9)
project(Saxion-CPlusPlus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(Week1 Week1/src/main.cpp Week1/src/io/io.cpp Week2/SortingAlgorithm/src/main.cpp)
add_executable(Week2-ArraysAndPointers Week2/ArraysAndPointers/src/main.cpp)
add_executable(Week2-SortingAlgorithm Week2/SortingAlgorithm/src/main.cpp)
add_executable(Week3-Blackjack Week3/main.cpp)
add_executable(Week4-Redis Week4/main.cpp Week4/ValueInt/ValueInt.cpp Week4/KeyValue/KeyValue.cpp)
add_executable(Week5 Week5/main.cpp Week5/ValueInt/ValueInt.cpp Week5/KeyValue/KeyValue.cpp
        Week5/ValueBase/ValueBase.cpp Week5/ValueString/ValueString.cpp)
add_executable(Week6 Week6/main.cpp Week6/AllocateStatistics.cpp  Week6/graph.tpl  Week6//dygraph.min.js Week6/dygraph.css Week6/figure.txt Week6/Line.cpp Week6/Circle.cpp)
add_executable(Week7-Helpdesk Week7/main.cpp Week7/assets/input.txt Week7/Administration.cpp Week7/Administration.h Week7/Employee.cpp Week7/Employee.h Week7/HardwareTicket.cpp Week7/HardwareTicket.h Week7/ServiceDeskEmployee.cpp Week7/ServiceDeskEmployee.h Week7/SoftwareTicket.cpp Week7/SoftwareTicket.h Week7/Ticket.cpp Week7/Ticket.h)