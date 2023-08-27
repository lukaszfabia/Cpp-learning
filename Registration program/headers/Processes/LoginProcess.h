//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_LOGINPROCESS_H
#define CPP_LEARNING_LOGINPROCESS_H


#include "Process.h"

class LoginProcess: public Process{
private:
    Account *loggedAccount=nullptr;

    bool loginUser();
    void setAccount(Account *account);
    bool equals(Account *account);

protected:
    void getInput() override;

public:
    explicit LoginProcess(vector<Account> &accounts);

    bool run() override;
};


#endif //CPP_LEARNING_LOGINPROCESS_H
