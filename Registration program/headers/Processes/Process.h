//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_PROCESS_H
#define CPP_LEARNING_PROCESS_H

#include <string>
#include <vector>
#include "headers/Account.h"

class Process {
protected:
    std::vector<Account> &accounts;

public:
    explicit Process(std::vector<Account> &accounts);

    virtual ~Process();

    virtual bool run() = 0;
};


#endif //CPP_LEARNING_PROCESS_H
