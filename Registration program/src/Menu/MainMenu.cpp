#include "headers/Menu/MainMenu.h"
#include "headers/Tools/System and control/ReadInput.h"

void MainMenu::buildMenu() {
    showPrompts();
}

void MainMenu::showPrompts() {
    if (actualAccount->getNationality() == "NULL") {
        ReadInput::print("It looks like you don't have a set nationality! Do you want to fix it?\n");
        ReadInput::print("1. Yes\n");
        ReadInput::print("2. No\n");
        ReadInput::print("Enter your choice: ");
        if (getChoice() == 1) {
            actualAccount->setNationality();
            file->update(actualAccount);
            ReadInput::print(actualAccount->getNationality() + " has been set!\n");
        }
    }
    ReadInput::print("Welcome " + actualAccount->getUsername() + "!\n");
    ReadInput::print("1. Show my information\n");
    ReadInput::print("2. Edit my information\n");
    ReadInput::print("3. Logout\n");
    ReadInput::print("Enter your choice: ");

}

int MainMenu::getChoice() {
    return ReadInput::readInt(1);
}