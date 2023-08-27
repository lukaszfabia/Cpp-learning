//
// Created by ufabi on 27.08.2023.
//


#include "headers/Tools/ReadInput.h"
#include "headers/Processes/LoginProcess.h"


bool LoginProcess::equals(Account *account) {
    return account->getUsername() == this->loggedAccount->getUsername() &&
           account->getPassword() == this->loggedAccount->getPassword();
}

bool LoginProcess::loginUser() {
    for (auto &account: accounts) {
        if (equals(&account)) {
            return true;
        }
    }
    return false;
}

bool LoginProcess::run() {
    return loginUser();
}
