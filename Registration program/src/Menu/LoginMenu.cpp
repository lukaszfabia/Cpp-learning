//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/LoginMenu.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Processes/LoginProcess.h"
#include "headers/Menu/MainMenu.h"

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
    this->process = new LoginProcess(accounts, loggedAccount);
    if (process->run()) {
        ReadInput::print("Login successful!\n");
        ReadInput::print(loggedAccount->getNationality());
        //this->mainMenu = new MainMenu(accounts, loggedAccount);
        //mainMenu->show();
    } else {
        ReadInput::print("Login failed!\n");
    }
}

void LoginMenu::setAccount(Account *account) {
    this->loggedAccount = account;
}


