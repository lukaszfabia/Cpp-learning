//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_MENU_H
#define CPP_LEARNING_MENU_H


#include "headers/Account.h"
#include <vector>

class Menu {
protected:
    vector<Account> &accounts;
    virtual void showPrompts() = 0;
    virtual int getChoice() = 0;
    virtual std::string getData() = 0;
public:
    explicit Menu(vector<Account> &accounts) : accounts(accounts) {};
    virtual ~Menu() = default;
    virtual void show() = 0;
};


#endif //CPP_LEARNING_MENU_H
