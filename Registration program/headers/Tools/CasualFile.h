//
// Created by ufabi on 26.08.2023.
//

#ifndef CPP_LEARNING_CASUALFILE_H
#define CPP_LEARNING_CASUALFILE_H


#include "File.h"

class CasualFile: public File {
private:
    Account *helpAccount;

    static bool conditionToRemove(Account *account, Account *helpAccount);
public:
    explicit CasualFile(vector<Account> &accounts, string fileName) : File(accounts, std::move(fileName)) {
        this->helpAccount = nullptr;
    };

    ~CasualFile() override {
        delete helpAccount;
    }

    bool load() override;

    bool save() override;

    bool update(Account *account) override;
};


#endif //CPP_LEARNING_CASUALFILE_H
