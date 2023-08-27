//
// Created by ufabi on 26.08.2023.
//

#ifndef CPP_LEARNING_BINARYFILE_H
#define CPP_LEARNING_BINARYFILE_H


#include "File.h"

class BinaryFile: public File {
public:
    ~BinaryFile() override;

    bool load(vector<Account> &accounts, const string &fileName) override;

    bool save(Registration &data, const string &fileName, vector<Account> &accounts) override;
};


#endif //CPP_LEARNING_BINARYFILE_H
