#ifndef CPP_LEARNING_EDITINFORMATION_H
#define CPP_LEARNING_EDITINFORMATION_H


#include "headers/Account.h"
#include "headers/Tools/File/File.h"
#include "headers/Tools/File/CasualFile.h"
#include "headers/Tools/System and control/Validator.h"

class EditInformation {
private:
    Account *actualAccount = nullptr;
    vector<Account> &accounts;
    File *file;
    Validator *validator;

    bool editUsername();

    bool editPassword();

    bool editEmail();

    bool editPhoneNumber();

    bool editNationality();

public:
    EditInformation(Account *account, vector<Account> &accounts) : accounts(accounts), actualAccount(account) {
        this->actualAccount = account;
        this->file = new CasualFile(accounts, "data");
        this->validator = new Validator();
    };

    ~EditInformation() {
        delete actualAccount;
        delete validator;
        delete file;
    }

    void run();
};


#endif //CPP_LEARNING_EDITINFORMATION_H
