//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_LOGINMENU_H
#define CPP_LEARNING_LOGINMENU_H


#include "Menu.h"

class LoginMenu: public Menu {
private:
    Account *loggedAccount=nullptr;
    void showPrompts() override;
    int getChoice() override;
    std::string getData() override;
    void setAccount(Account *account);

public:
    explicit LoginMenu(vector<Account> &accounts) : Menu(accounts) {};
    ~LoginMenu() override {
        delete loggedAccount;
    };
    void show() override;

};


#endif //CPP_LEARNING_LOGINMENU_H
