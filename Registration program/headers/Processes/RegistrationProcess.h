//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_REGISTRATIONPROCESS_H
#define CPP_LEARNING_REGISTRATIONPROCESS_H


#include "Process.h"
#include "headers/Account.h"
#include <string>

class RegistrationProcess : public Process {
private:
    // variables
    std::string email;
    std::string phoneNumber;

    // static methods
    static bool equals(Registration registration, Account account);

    // methods
    bool isUnique(const Registration &registration);

    bool addNewAccount(Registration &registration);

    bool registerUser();

protected:

    void getInput() override;

public:
    explicit RegistrationProcess(std::vector<Account> &accounts);

    bool run() override;
};


#endif //CPP_LEARNING_REGISTRATIONPROCESS_H
