cmake_minimum_required(VERSION 3.29)
project(cli_atm_machine)

set(CMAKE_CXX_STANDARD 20)

add_executable(cli_atm_machine main.cpp
        Account.cpp
        AccountManager.h
        AccountManager.cpp
        Atm.cpp)
