//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/MainMenu.h"
#include "headers/Tools/ReadInput.h"

void MainMenu::show() {
    ReadInput::print(loggedAccount->getNationality());
    //showPrompts();

}

void MainMenu::showPrompts() {
    if (loggedAccount->getNationality()=="NULL") {
        ReadInput::print("It looks like you don't have a set nationality! Do you want to fix it?\n");
        ReadInput::print("1. Yes\n");
        ReadInput::print("2. No\n");
        ReadInput::print("Enter your choice: ");
        if (getChoice() == 1) {
            loggedAccount->setNationality();
        }
    }
    ReadInput::print("Welcome " + loggedAccount->getUsername() + "!\n");
    ReadInput::print("1. Show my information\n");
    ReadInput::print("2. Edit my information\n");
    ReadInput::print("3. Logout\n");
    ReadInput::print("Enter your choice: ");

}

int MainMenu::getChoice() {
    return ReadInput::readInt(1);
}

std::string MainMenu::getData() {
    return ReadInput::readString(1);
}

void MainMenu::setAccount(Account *account) {
    this->loggedAccount = account;
}




