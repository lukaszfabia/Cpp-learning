#include "headers/System.h"
#include "headers/Tools/ReadInput.h"
#include "headers/Tools/File.h"
#include "headers/Tools/CasualFile.h"
#include "headers/Processes/Process.h"
#include "headers/Processes/RegistrationProcess.h"
#include "headers/Processes/LoginProcess.h"
#include <algorithm>

System::System() {
    this->accounts = vector<Account>();
}

System::~System() {
    delete &accounts;
}

void System::home() {
    File *file = new CasualFile();
    file->load(accounts, "data");
    delete file;

    int choice;
    bool isRunning = true;
    while (isRunning) {
        ReadInput::print("\n1. Register\n");
        ReadInput::print("2. Login\n");
        ReadInput::print("3. Exit\n");
        ReadInput::print("Enter your choice: ");
        choice = ReadInput::readInt(1);
        Process *registerProcess = new RegistrationProcess(accounts);
        Process *loginProcess = new LoginProcess(accounts);
        switch (choice) {
            case 1:
                registerProcess->run();
                delete registerProcess;
                break;
            case 2:
                loginProcess->run();
                delete loginProcess;
                break;
            case 3:
                isRunning = false;

                break;
            default:
                ReadInput::print("Invalid choice!\n");
                break;
        }
    }
}

void handleNationality(Account &account) {
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
    ReadInput::print(account.information());

    // check is nationality set
    if (account.getNationality().empty()) {
        handleNationality(account);
    }
}
