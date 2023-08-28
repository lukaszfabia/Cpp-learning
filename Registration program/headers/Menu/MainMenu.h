#ifndef CPP_LEARNING_MAIN_H
#define CPP_LEARNING_MAIN_H


#include "Menu.h"
#include "headers/Tools/File.h"
#include "headers/Tools/CasualFile.h"
#include <vector>

class MainMenu {
private:
    Account *actualAccount;
    vector<Account> &accounts;
    File *file;

    void showPrompts();

    static int getChoice();


public:
    explicit MainMenu(vector<Account> &accounts, Account *account) : accounts(accounts) {
        this->actualAccount = account;
        this->file = new CasualFile(accounts, "data");
    };

    ~MainMenu() {
        delete actualAccount;
        delete file;
    };

    void buildMenu();
};


#endif //CPP_LEARNING_MAIN_H
