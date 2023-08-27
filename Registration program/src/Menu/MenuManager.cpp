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
}


MenuManager::~MenuManager() {
    delete this->registerMenu;
    delete this->loginMenu;
}

void MenuManager::showRegisterMenu() {
    this->registerMenu = new RegisterMenu(accounts);
    this->registerMenu->show();
}


void MenuManager::showLoginMenu() {
    this->loginMenu = new LoginMenu(accounts);
    this->loginMenu->show();
}


void MenuManager::build() {
    saveToDataBase();

    bool isRunning = false;
    while (!isRunning) {
        showPrompts();
        switch (getChoice()) {
            case 1:
                showRegisterMenu();
                break;
            case 2:
                showLoginMenu();
                break;
            case 3:
                isRunning = true;
                break;
            default:
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

void MenuManager::saveToDataBase() {
    File *file = new CasualFile();
    file->load(accounts, "data");
    delete file;
}