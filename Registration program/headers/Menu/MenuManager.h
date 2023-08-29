//
// Created by ufabi on 27.08.2023.
//

#ifndef CPP_LEARNING_MENUMANAGER_H
#define CPP_LEARNING_MENUMANAGER_H

#include "Menu.h"
#include "headers/Account.h"
#include "headers/Tools/File/CasualFile.h"
#include <vector>

// class above menu to build all menus
class MenuManager {
private:
    CasualFile *file;
    Menu *registerMenu;
    Menu *loginMenu;
    vector<Account> &accounts;
    void buildRegisterMenu();
    void buildLoginMenu();
    static int getChoice();
    static void showPrompts();
    void updateDataBase();
public:
    explicit MenuManager(vector<Account> &accounts);
    ~MenuManager();
    void build();
};


#endif //CPP_LEARNING_MENUMANAGER_H
