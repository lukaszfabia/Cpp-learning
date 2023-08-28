//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/MenuManager.h"
#include "headers/Menu/RegisterMenu.h"
#include "headers/Tools/File.h"
#include "headers/Tools/CasualFile.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Processes/Process.h"
#include "headers/Menu/LoginMenu.h"

MenuManager::MenuManager(vector<Account> &accounts) : accounts(accounts) {
    this->registerMenu = nullptr;
    this->loginMenu = nullptr;
    this->file= new CasualFile();
}

MenuManager::~MenuManager() {
    delete this->registerMenu;
    delete this->loginMenu;
    delete this->file;
}

void MenuManager::buildRegisterMenu() {
    this->registerMenu = new RegisterMenu(accounts);
    this->registerMenu->show();
}


void MenuManager::buildLoginMenu() {
    this->loginMenu = new LoginMenu(accounts);
    this->loginMenu->show();
}


void MenuManager::build() {
    updateDataBase();

    bool isRunning = false;
    while (!isRunning) {
        showPrompts();
        switch (getChoice()) {
            case 1:
                buildRegisterMenu();
                break;
            case 2:
                buildLoginMenu();
                break;
            case 3:
                for (auto &account : accounts) {
                    ReadInput::print(account.getUsername());
                }
                //isRunning = true;
                break;
            default:
                isRunning = true;
                ReadInput::print("Invalid choice!\n");
                break;
        }
    }
}

int MenuManager::getChoice() {
    return ReadInput::readInt(1);
}

void MenuManager::showPrompts() {
    ReadInput::print("\n1. Register\n");
    ReadInput::print("2. Login\n");
    ReadInput::print("3. Exit\n");
    ReadInput::print("Enter your choice: ");
}

void MenuManager::updateDataBase() {
    this->file->load(accounts, "data");
}