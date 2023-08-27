//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/MainMenu.h"
#include "headers/Tools/ReadInput.h"

void MainMenu::show() {

}

void MainMenu::showPrompts() {
    ReadInput::print("It looks like you don't have a set nationality! Do you want to fix it?\n");
    ReadInput::print("1. Yes\n");
    ReadInput::print("2. No\n");
    ReadInput::print("Enter your choice: ");
    int choice = getChoice();
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




