#include "headers/Menu/LoginMenu.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Processes/LoginProcess.h"

void LoginMenu::showPrompts() {
    std::string username, password;
    ReadInput::print("Enter username: ");
    username = getData();
    ReadInput::print("Enter password: ");
    password = getData();

    setAccount(username, password);
}

int LoginMenu::getChoice() {
    return ReadInput::readInt(1);
}

std::string LoginMenu::getData() {
    return ReadInput::readString(1);
}

void LoginMenu::show() {
    showPrompts();
    if (process->run()) {
        ReadInput::print("Login successful!\n");
        mainMenu->buildMenu();
    } else {
        ReadInput::print("Login failed!\n");
    }
}

void LoginMenu::setAccount(const std::string& username, const std::string& password) {
    for (auto &item: accounts) {
        if (item.getUsername() == username && item.getPassword() == password) {
            auto *account = new Account(item.getUsername(), item.getPassword(), item.getEmail(), item.getPhoneNumber());
            account->setNationality(item.getNationality());
            account->setBalance(item.getBalance());
            this->loggedAccount = account;
            this->process = new LoginProcess(accounts, loggedAccount);
            this->mainMenu = new MainMenu(accounts, loggedAccount);
            return;
        }
    }
}


