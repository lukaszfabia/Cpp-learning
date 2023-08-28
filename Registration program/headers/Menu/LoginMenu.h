//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_LOGINMENU_H
#define CPP_LEARNING_LOGINMENU_H


#include "Menu.h"
#include "headers/Processes/Process.h"
#include "MainMenu.h"

class LoginMenu : public Menu {
private:
    Account *loggedAccount;

    Process *process;

    MainMenu *mainMenu;

    void showPrompts() override;

    int getChoice() override;

    std::string getData() override;

    void setAccount(const std::string& username, const std::string& password);

public:
    explicit LoginMenu(std::vector<Account> &accounts) : Menu(accounts) {
        this->loggedAccount = nullptr;
        this->process = nullptr;
        this->mainMenu = nullptr;
    };

    ~LoginMenu() override {
        delete loggedAccount;
        delete process;
        delete mainMenu;
    };

    void show() override;

};


#endif //CPP_LEARNING_LOGINMENU_H
