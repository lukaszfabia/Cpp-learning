//
// Created by ufabi on 26.08.2023.
//

#include "headers/file headers/BinaryFile.h"
#include "headers/ReadInput.h"

BinaryFile::~BinaryFile() = default;


bool BinaryFile::load(vector<Account> &accounts, const string &fileName) {
    const std::string newFileName = fileName + ".bin";
    std::ifstream File(newFileName, std::ios::binary);

    if (File.is_open()) {
        while (true) {
            Account account;
            if (File.read(reinterpret_cast<char *>(&account), sizeof(Account))) {
                accounts.push_back(account);
            } else {
                if (File.eof()) {
                    break;
                } else {
                    ReadInput::print("Error reading from file!");
                    File.close();
                    return false;
                }
            }
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool BinaryFile::save(Registration &newAccount, const string &fileName) {
    const std::string newFileName = fileName + ".bin";
    std::ofstream File(newFileName, std::ios::binary);

    if (File.is_open()) {
        File.write(reinterpret_cast<const char *>(&newAccount), sizeof(Registration));
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}
