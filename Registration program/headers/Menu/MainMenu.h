#ifndef CPP_LEARNING_MAIN_H
#define CPP_LEARNING_MAIN_H


#include "Menu.h"
#include "headers/Tools/File/File.h"
#include "headers/Tools/File/CasualFile.h"
#include "EditInformation.h"
#include <vector>

class MainMenu {
private:
    Account *actualAccount;
    vector<Account> &accounts;
    EditInformation *edit;

    void welcomeMessage();

    static int getChoice();


public:
    explicit MainMenu(vector<Account> &accounts, Account *account) : accounts(accounts) {
        this->actualAccount = account;
        this->edit = new EditInformation(account, accounts);
    };

    ~MainMenu() {
        delete actualAccount;
        delete edit;
    };

    void buildMenu();

    void menu(int choice);
};


#endif //CPP_LEARNING_MAIN_H
