//
// Created by ufabi on 25.08.2023.
//

#ifndef CPP_LEARNING_FILE_H
#define CPP_LEARNING_FILE_H

#include <fstream>
#include <utility>
#include <vector>
#include "headers/Registration.h"
#include "headers/Account.h"

using namespace std;

class File {
protected:
    vector<Account> &accounts;
    std::string fileName;

public:
    explicit File(vector<Account> &accounts, string fileName) : accounts(accounts), fileName(std::move(fileName)) {};

    virtual ~File() = default;

    virtual bool load() = 0;

    virtual bool save() = 0;

    virtual bool update(Account *account) = 0;
};


#endif //CPP_LEARNING_FILE_H
