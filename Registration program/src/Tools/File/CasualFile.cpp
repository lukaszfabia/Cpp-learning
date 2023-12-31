//
// Created by ufabi on 26.08.2023.
//

#include <algorithm>
#include "headers/Tools/File/CasualFile.h"
#include "headers/Tools/System and control/ReadInput.h"

bool CasualFile::load() {
    string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::in);
    if (File.is_open()) {
        string username, password, email, phoneNumber, nationality;
        basic_string<char> balance;
        string hashcode;
        while (File >> hashcode >> username >> password >> email >> phoneNumber >> nationality >> balance) {
            this->helpAccount = new Account(username, password, email, phoneNumber, nationality, std::stod(balance), std::stoull(hashcode));
            accounts.push_back(*this->helpAccount);
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool CasualFile::save() {
    const string newFileName = fileName + ".txt";
    fstream File;
    File.open(newFileName, ios::out | ios::trunc);
    if (File.is_open()) {
        for (Account &item: accounts) {
            File << item.getHashcode() << " ";
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

bool CasualFile::update(Account *account) {
    accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
                                  [&account](Account &item) {
                                      return conditionToRemove(&item, account);
                                  }), accounts.end());
    accounts.push_back(*account);
    return save();
}

bool CasualFile::conditionToRemove(Account *account, Account *helpAccount) {
    return account->getHashcode() == helpAccount->getHashcode();
}
