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

bool CasualFile::save(Registration &newAccount, const string &fileName, vector<Account> &accounts) {
    const string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::out | ios::trunc);
    if (File.is_open()) {
        for (Account &item: accounts) {
            File << item.getUsername() << endl;
            File << item.getPassword() << endl;
            File << item.getEmail() << endl;
            File << item.getPhoneNumber() << endl;
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}
