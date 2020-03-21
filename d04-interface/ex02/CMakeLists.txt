# cmake_minimum_required(VERSION <specify CMake version here>)
project(ex02)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex02 main.cpp Squad.cpp TacticalMarine.cpp TacticalMarine.hpp AssaultTerminator.cpp AssaultTerminator.hpp ISpaceMarine.hpp ISquad.hpp)