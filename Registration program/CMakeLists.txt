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
        "src/Tools/Validator.cpp"
        "headers/Tools/Validator.h" src/Tools/ReadInput.cpp "headers/Tools/ReadInput.h" "headers/Tools/ReadInput.h" "headers/Tools/File.h" "src/Tools/BinaryFile.cpp" "headers/Tools/BinaryFile.h" "headers/Tools/BinaryFile.h" "src/Tools/CasualFile.cpp" "headers/Tools/CasualFile.h" src/Processes/RegistrationProcess.cpp "headers/Processes/RegistrationProcess.h" src/Processes/Process.cpp "headers/Processes/Process.h" src/Processes/LoginProcess.cpp "headers/Processes/LoginProcess.h" "headers/Processes/LoginProcess.h" src/Menu/MainMenu.cpp src/Menu/RegisterMenu.cpp src/Menu/MenuManager.cpp src/Menu/LoginMenu.cpp headers/Menu/LoginMenu.h)

