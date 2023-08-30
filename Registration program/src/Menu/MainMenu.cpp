#include "headers/Menu/MainMenu.h"
#include "headers/Tools/System and control/ReadInput.h"
#include "headers/Tools/System and control/ConsoleControl.h"

void MainMenu::buildMenu() {
    welcomeMessage();
}

int MainMenu::getChoice() {
    return ReadInput::readInt(1);
}

void MainMenu::welcomeMessage() {
    ConsoleControl::clearConsole();
    ReadInput::print("Welcome " + actualAccount->getUsername() + "!\n");
    ReadInput::print("1. Show my information\n");
    ReadInput::print("2. Edit my information\n");
    ReadInput::print("3. Logout\n");

    int choice = 0;
    while (choice != 3) {
        ReadInput::print("Enter your choice: ");
        choice = getChoice();
        menu(choice);
    }
}

void MainMenu::menu(int choice) {
    switch (choice) {
        case 1:
            ReadInput::print(actualAccount->information());
            break;
        case 2:
            this->edit->run();
            break;
        case 3:
            this->actualAccount = nullptr;
            break;
        default:
            ReadInput::print("Wrong number!\n");
    }

}