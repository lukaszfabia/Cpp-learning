cmake_minimum_required(VERSION 3.25)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 17)

include_directories("Registration program")

add_executable(cpp_learning
        "Registration program/src/Account.cpp"
        "Registration program/headers/Account.h"
        "Registration program/main.cpp"
        "Registration program/src/Registration.cpp"
        "Registration program/headers/Registration.h"
        "Registration program/src/System.cpp"
        "Registration program/headers/System.h"
        "Registration program/src/Validator.cpp"
        "Registration program/headers/Validator.h")
