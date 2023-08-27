//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_MENUMANAGER_H
#define CPP_LEARNING_MENUMANAGER_H

#include "Menu.h"
#include "headers/Account.h"
#include <vector>

// class above menu to build all menus
class MenuManager {
private:
    Menu *registerMenu;
    Menu *loginMenu;
    vector<Account> &accounts;
    void showRegisterMenu();
    void showMainMenu();
    void showLoginMenu();
    static int getChoice();
    static void showPrompts();
    void saveToDataBase();
public:
    explicit MenuManager(vector<Account> &accounts);
    ~MenuManager();
    void build();
};


#endif //CPP_LEARNING_MENUMANAGER_H
