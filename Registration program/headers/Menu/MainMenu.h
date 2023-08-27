//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_MAIN_H
#define CPP_LEARNING_MAIN_H


#include "Menu.h"

class MainMenu : public Menu {
private:
    Account *loggedAccount = nullptr;

    void showPrompts() override;

    int getChoice() override;

    std::string getData() override;

    void setAccount(Account *account);

public:
    explicit MainMenu(vector<Account> &accounts, Account *account) : Menu(accounts), loggedAccount(account) {};

    void show() override;
};


#endif //CPP_LEARNING_MAIN_H
