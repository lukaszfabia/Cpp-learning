//
// Created by ufabi on 26.08.2023.
//

#include "headers/BinaryFile.h"
#include "headers/ReadInput.h"

BinaryFile::~BinaryFile() = default;

bool BinaryFile::load(vector<Account> &accounts, const string &fileName) {
    const std::string newFileName = fileName+".bin";
    std::ifstream File(newFileName, std::ios::binary);

    if (File.is_open()){
        while (true){
            Account account;
            File.read(reinterpret_cast<char *>(&account), sizeof(Account));
            if (File.eof()) break;
            accounts.push_back(account);
        }
        File.close();
        return true;
    } else {
        ReadInput::print("Error opening file!");
        return false;
    }
}

bool BinaryFile::save(Registration &newAccount, const string &fileName) {
    const std::string newFileName = fileName+".bin";

}
