cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Autonomous_Vehicle_Project)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Autonomous_Vehicle_Project main.cpp Node.cpp)
target_link_libraries(Autonomous_Vehicle_Project sfml-graphics sfml-audio)