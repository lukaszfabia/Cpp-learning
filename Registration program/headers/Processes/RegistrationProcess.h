#ifndef CPP_LEARNING_REGISTRATIONPROCESS_H
#define CPP_LEARNING_REGISTRATIONPROCESS_H


#include "Process.h"
#include "headers/Account.h"
#include <string>

class RegistrationProcess : public Process {
private:
    // variables
    Registration *registration=nullptr;

    bool equals(Account account);

    // methods
    bool isUnique();

    bool addNewAccount();

    bool registerUser();

    bool saveData();

    bool addUniqueID();

public:
    explicit RegistrationProcess(vector<Account> &accounts, Registration *registration) : Process(accounts),
    registration(registration) {};

    ~RegistrationProcess() override{
        delete registration;
    }
    bool run() override;
};


#endif //CPP_LEARNING_REGISTRATIONPROCESS_H
