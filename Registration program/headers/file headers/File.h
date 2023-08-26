//
// Created by ufabi on 25.08.2023.
//

#ifndef CPP_LEARNING_FILE_H
#define CPP_LEARNING_FILE_H

#include <fstream>
#include <vector>
#include "headers/Registration.h"
#include "headers/Account.h"

using namespace std;

class File {
public:
    virtual ~File() = default;

    virtual bool load(vector<Account> &accounts, const string &fileName) = 0;

    virtual bool save(Registration &newAccount, const string &fileName) = 0;
};


#endif //CPP_LEARNING_FILE_H
