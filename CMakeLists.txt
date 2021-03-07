cmake_minimum_required(VERSION 3.17)
project(Year1_CPP_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Year1_CPP_Project
        main.cpp
        Commands.cpp Commands.h
        Stock.cpp Stock.h
        FileHandler.cpp FileHandler.h
        Order.cpp Order.h
        Logs.cpp Logs.h
        Shopper.cpp Shopper.h
        Item.cpp Item.h)