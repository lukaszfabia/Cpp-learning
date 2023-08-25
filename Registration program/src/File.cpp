//
// Created by ufabi on 25.08.2023.
//

#include "headers/File.h"
#include "headers/ReadInput.h"
#include <vector>

bool File::save(Registration &newAccount, const string& fileName) {
    fstream File;
    File.open(fileName, ios::out);

    if (File.is_open()) {
        File << newAccount.getUsername() << endl;
        File << newAccount.getPassword() << endl;
        File << newAccount.getEmail() << endl;
        File << newAccount.getPhoneNumber() << endl;
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool File::load(vector<Account> &accounts, const string& fileName) {
    fstream File;
    File.open(fileName, ios::in);

    if (File.is_open()) {
        string username, password, email, phoneNumber;
        while (File >> username >> password >> email >> phoneNumber) {
            Account account(username, password, email, phoneNumber);
            accounts.push_back(account);
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}
