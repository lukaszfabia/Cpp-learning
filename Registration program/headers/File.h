//
// Created by ufabi on 25.08.2023.
//

#ifndef CPP_LEARNING_FILE_H
#define CPP_LEARNING_FILE_H

#include <fstream>
#include <vector>
#include "Registration.h"
#include "Account.h"

using namespace std;

class File {
public:
    static bool load(vector<Account> &accounts, const string &fileName);

    static bool save(Registration &data, const string &fileName);
};


#endif //CPP_LEARNING_FILE_H
