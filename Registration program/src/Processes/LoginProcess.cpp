//
// Created by ufabi on 27.08.2023.
//


#include "headers/Tools/ReadInput.h"
#include "headers/Processes/LoginProcess.h"

LoginProcess::LoginProcess(vector<Account> &accounts) : Process(accounts) {
    this->accounts = accounts;
}

void LoginProcess::setAccount(Account *account) {
    this->loggedAccount = account;
}

bool LoginProcess::equals(Account *account) {
    return account->getUsername() == this->username &&
           account->getPassword() == this->password;
}

bool LoginProcess::loginUser() {
    getInput();

    for (auto &account: accounts) {
        if (equals(&account)) {
            ReadInput::print("Login successful!");
            setAccount(&account);
            return true;
        }
    }
    return false;
}

void LoginProcess::getInput() {
    ReadInput::print("Enter username: ");
    this->username = ReadInput::readString(1);
    ReadInput::print("Enter password: ");
    this->password = ReadInput::readString(1);
}

bool LoginProcess::run() {
    if (loginUser()) {
        ReadInput::print("\nWelcome " + loggedAccount->getUsername() + "!");
        return true;
    } else {
        ReadInput::print("Username or password is incorrect!");
        return false;
    }
}
