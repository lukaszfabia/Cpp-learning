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
        "headers/Tools/File/File.h"
        "src/Tools/File/BinaryFile.cpp"
        "headers/Tools/File/BinaryFile.h"
        "headers/Tools/File/BinaryFile.h"
        "src/Tools/File/CasualFile.cpp"
        "headers/Tools/File/CasualFile.h"
        src/Processes/RegistrationProcess.cpp
        "headers/Processes/RegistrationProcess.h"
        src/Processes/Process.cpp
        "headers/Processes/Process.h"
        src/Processes/LoginProcess.cpp
        "headers/Processes/LoginProcess.h"
        "headers/Processes/LoginProcess.h"
        src/Menu/MainMenu.cpp
        src/Menu/RegisterMenu.cpp
        src/Menu/MenuManager.cpp
        src/Menu/LoginMenu.cpp
        headers/Menu/LoginMenu.h
        "headers/Tools/System and control/ConsoleControl.h"
        "src/Tools/System and control/ConsoleControl.cpp" "src/Tools/System and control/ReadInput.cpp" "src/Tools/System and control/Validator.cpp")

