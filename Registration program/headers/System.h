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

    bool addNewAccount(const Registration &registration);

    bool isUnique(const Registration &registration);

    static bool equals(Registration registration, Account account);

    bool registerUser();

    bool loginUser();

    static bool save(Registration newAccount);

    bool load();

    void setAccount(const Account &account);

public:
    System();

    ~System();

    void home();

    static void mainMenu(Account &account);
};

#endif
