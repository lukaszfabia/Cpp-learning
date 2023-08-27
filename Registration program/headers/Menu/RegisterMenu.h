//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_REGISTERMENU_H
#define CPP_LEARNING_REGISTERMENU_H


#include "Menu.h"

class RegisterMenu : public Menu {
private:
    Registration *newRegistration = nullptr;

    void showPrompts() override;

    int getChoice() override;

    std::string getData() override;

    void setRegistration(Registration *registration);

public:
    explicit RegisterMenu(vector<Account> &accounts) : Menu(accounts) {};
    void show() override;
};


#endif //CPP_LEARNING_REGISTERMENU_H
