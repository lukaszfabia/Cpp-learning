#include <cstdlib>
#include <thread>
#include <chrono>
#include "headers/Tools/System and control/ConsoleControl.h"

void ConsoleControl::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleControl::pause() {
    system("pause");
}

void ConsoleControl::sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}