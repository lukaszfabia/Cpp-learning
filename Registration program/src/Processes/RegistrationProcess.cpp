//
// Created by ufabi on 27.08.2023.
//

#include <vector>
#include <algorithm>
#include "headers/Processes/RegistrationProcess.h"
#include "headers/Tools/System and control/ReadInput.h"
#include "headers/Tools/File/File.h"
#include "headers/Tools/File/CasualFile.h"


bool RegistrationProcess::isUnique() {
    // functional example
    return all_of(accounts.begin(), accounts.end(), [this](const Account &account) {
        return !equals(account);
    });
}

bool RegistrationProcess::equals(Account account) {
    return registration->getEmail() == account.getEmail() ||
           registration->getPhoneNumber() == account.getPhoneNumber() ||
           registration->getUsername() == account.getUsername();
}

bool RegistrationProcess::addNewAccount() {
    if (accounts.empty() || isUnique()) {
        addUniqueID();
        auto *account=new Account(registration);
        accounts.push_back(*account);
        return saveData();
    } else {
        return false;
    }
}

bool RegistrationProcess::registerUser() {
    return registration->authorize() && addNewAccount();
}

bool RegistrationProcess::run() {
    return registerUser();
}

bool RegistrationProcess::saveData() {
    File *file = new CasualFile(accounts, "data");
    bool resultTxt = file->save();
    delete file;
    return resultTxt;
}

bool RegistrationProcess::addUniqueID() {
    int id=1;
    for (auto &account : accounts){
        if (account.getID()==registration->getID()){
            registration->setID(id);
            return true;
        }
        id++;
    }
    return false;
}

