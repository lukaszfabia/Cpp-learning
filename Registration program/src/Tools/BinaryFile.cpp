//
// Created by ufabi on 26.08.2023.
//

#include "headers/Tools/BinaryFile.h"
#include "headers/Tools/ReadInput.h"


// needs to be updated cause of the new save file style
bool BinaryFile::load() {
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

bool BinaryFile::save() {
    const std::string newFileName = fileName + ".bin";
    std::ofstream File(newFileName, std::ios::binary);

    if (File.is_open()) {
        for (Account &item: accounts) {
            File.write(reinterpret_cast<const char *>(&item), sizeof(Account));
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool BinaryFile::update(Account *accounts) {
    throw std::runtime_error("Not implemented yet!");
}
