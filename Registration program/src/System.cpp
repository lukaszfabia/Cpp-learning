#include "headers/System.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Menu/MenuManager.h"

System::System() {
    this->accounts = vector<Account>();
}

System::~System() {
    for (auto &account : accounts) {
        delete &account;
    }
}

void System::home() {
    auto *menuManager=new MenuManager(accounts);
    menuManager->build();
}

void handleNationality(Account &account) {
    // to remove
    bool isGood = false;
    while (!isGood) {
        ReadInput::print("It looks like you don't have a set nationality! Do you want to fix it?\n");
        ReadInput::print("1. Yes\n");
        ReadInput::print("2. No\n");

        int choice = ReadInput::readInt(1);

        if (choice == 1) {
            account.setNationality();
            ReadInput::print(account.information());
            isGood = true;
        } else if (choice == 2) {
            ReadInput::print("It's ok then!\n");
            isGood = true;
        } else {
            ReadInput::print("Invalid choice!\n");
        }
    }
}

void System::mainMenu(Account &account) {
    //to remove
    ReadInput::print(account.information());

    // check is nationality set
    if (account.getNationality().empty()) {
        handleNationality(account);
    }
}
