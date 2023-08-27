//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/LoginMenu.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Processes/Process.h"
#include "headers/Processes/LoginProcess.h"

void LoginMenu::showPrompts() {
    std::string username, password;
    ReadInput::print("Enter username: ");
    username = getData();
    ReadInput::print("Enter password: ");
    password = getData();

    auto *account = new Account(username, password, "", "");
    setAccount(account);
}

int LoginMenu::getChoice() {
    return ReadInput::readInt(1);
}

std::string LoginMenu::getData() {
    return ReadInput::readString(1);
}

void LoginMenu::show() {
    showPrompts();
    Process *process = new LoginProcess(accounts, loggedAccount);
    if (process->run()) {
        ReadInput::print("Login successful!\n");
        // call main menu
    } else {
        ReadInput::print("Login failed!\n");
    }
}

void LoginMenu::setAccount(Account *account) {
    this->loggedAccount = account;
}


