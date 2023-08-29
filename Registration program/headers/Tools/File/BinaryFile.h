//
// Created by ufabi on 26.08.2023.
//

#ifndef CPP_LEARNING_BINARYFILE_H
#define CPP_LEARNING_BINARYFILE_H


#include "File.h"

class BinaryFile: public File {
public:
    explicit BinaryFile(vector<Account> &accounts, string fileName) : File(accounts, std::move(fileName)) {};

    ~BinaryFile() override = default;

    bool load() override;

    bool save() override;

    bool update(Account  *accounts) override;
};


#endif //CPP_LEARNING_BINARYFILE_H
