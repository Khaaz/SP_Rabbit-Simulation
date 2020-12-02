cmake_minimum_required(VERSION 3.17)
project(SP_Rabbit_Simulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(SP_Rabbit_Simulation main.cpp src/Rabbit.cpp src/Rabbit.h src/MaleRabbit.cpp src/MaleRabbit.h src/FemaleRabbit.cpp src/FemaleRabbit.h src/Simulation.cpp src/Simulation.h src/Generator.h src/Generator.cpp src/Constant.h src/Stats.cpp src/Stats.h)