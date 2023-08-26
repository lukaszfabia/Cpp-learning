//
// Created by ufabi on 26.08.2023.
//

#include "headers/file headers/CasualFile.h"
#include "headers/ReadInput.h"

CasualFile::~CasualFile()
= default;

bool CasualFile::load(vector<Account> &accounts, const string &fileName) {
    string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::in);

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

bool CasualFile::save(Registration &newAccount, const string &fileName) {
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
