//
// Created by ufabi on 27.08.2023.
//

#include <vector>
#include <algorithm>
#include "headers/Processes/RegistrationProcess.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Tools/File.h"
#include "headers/Tools/CasualFile.h"

RegistrationProcess::RegistrationProcess(vector<Account> &accounts) : Process(accounts) {
    this->accounts = accounts;
    this->email = "";
    this->phoneNumber = "";
}

bool RegistrationProcess::isUnique(const Registration &registration) {
    // functional example
    return all_of(accounts.begin(), accounts.end(), [registration](const Account &account) {
        return !equals(registration, account);
    });
}

bool RegistrationProcess::equals(Registration registration, Account account) {
    return registration.getEmail() == account.getEmail() ||
           registration.getPhoneNumber() == account.getPhoneNumber() ||
           registration.getUsername() == account.getUsername();
}

bool RegistrationProcess::addNewAccount(Registration &registration) {
    if (accounts.empty() || isUnique(registration)) {
        Account account(registration);
        accounts.push_back(account);
        File *file = new CasualFile();
        bool resultTxt = file->save(registration, "data", accounts);
        delete file;

        return resultTxt;
    } else {
        return false;
    }
}

bool RegistrationProcess::registerUser() {
    getInput();

    Registration registration(username, password, email, phoneNumber);
    return registration.authorize() && addNewAccount(registration);
}

void RegistrationProcess::getInput() {
    ReadInput::print("Enter username: ");
    this->username = ReadInput::readString(1);
    ReadInput::print("Enter password: ");
    this->password = ReadInput::readString(1);
    ReadInput::print("Enter email: ");
    this->email = ReadInput::readString(1);
    ReadInput::print("Enter phone number: ");
    this->phoneNumber = ReadInput::readString(1);
}

bool RegistrationProcess::run() {
    if (registerUser()) {
        ReadInput::print("Registration successful!\n");
        return true;
    } else {
        ReadInput::print("Registration failed!\n");
        return false;
    }
}