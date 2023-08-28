//
// Created by ufabi on 26.08.2023.
//

#include "headers/Tools/CasualFile.h"
#include "headers/Tools/ReadInput.h"

bool CasualFile::load(vector<Account> &accounts, const string &fileName) {
    string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::in);
    if (File.is_open()) {
        string username, password, email, phoneNumber, nationality, balance;
        while (File >> username >> password >> email >> phoneNumber >> nationality >> balance) {
            this->account = new Account(username, password, email, phoneNumber);
            this->account->setNationality(nationality);
            this->account->setBalance(stod(balance));
            accounts.push_back(*this->account);
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool CasualFile::save(const string &fileName, vector<Account> &accounts) {
    const string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::out | ios::trunc);
    if (File.is_open()) {
        for (Account &item: accounts) {
            File << item.getUsername() << " ";
            File << item.getPassword() << " ";
            File << item.getEmail() << " ";
            File << item.getPhoneNumber() << " ";
            File << item.getNationality() << " ";
            File << item.getBalance() << endl;
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool CasualFile::update(const string &fileName, Account &accounts) {
    return false;
}
