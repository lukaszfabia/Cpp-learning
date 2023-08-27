//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_LOGINPROCESS_H
#define CPP_LEARNING_LOGINPROCESS_H


#include "Process.h"

class LoginProcess : public Process {
private:
    Account *loggedAccount = nullptr;

    bool loginUser();

    bool equals(Account *account);

public:
    explicit LoginProcess(vector<Account> &accounts, Account *loggedAccount) : Process(accounts),
                                                                               loggedAccount(loggedAccount) {};
    ~LoginProcess() override {
        delete loggedAccount;
    };

    bool run() override;
};


#endif //CPP_LEARNING_LOGINPROCESS_H
