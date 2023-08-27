#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include "Registration.h"
#include "Account.h"

using namespace std;

class System {
private:
    vector<Account> accounts;
    Account temporaryAccount;

public:
    System();

    ~System();

    void home();

    static void mainMenu(Account &account);
};

#endif
