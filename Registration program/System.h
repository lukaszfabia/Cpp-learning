#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include "Registration.h"
#include "Registration.cpp"
#include "Account.h"
#include "Account.cpp"

using namespace std;

class System
{
private:
    vector <Account> accounts;
    Account temporaryAccount;

    bool addNewAccount(Registration registration);
    bool isUnique(Registration registration);
    bool equals(Registration registration, Account account);

    bool registerUser();
    bool loginUser();

    void setAccount(Account account);

public:
    System();
    ~System();
    void home();
    void mainMenu(Account &account);
};

#endif
