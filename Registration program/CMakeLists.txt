cmake_minimum_required(VERSION 3.25)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 17)

include_directories(".")

add_executable(cpp_learning
        "src/Account.cpp"
        "headers/Account.h"
        "main.cpp"
        "src/Registration.cpp"
        "headers/Registration.h"
        "src/System.cpp"
        "headers/System.h"
        "src/Validator.cpp"
        "headers/Validator.h" src/ReadInput.cpp headers/ReadInput.h headers/ReadInput.h src/File.cpp headers/File.h)

