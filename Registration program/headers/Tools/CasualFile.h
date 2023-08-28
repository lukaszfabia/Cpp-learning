//
// Created by ufabi on 26.08.2023.
//

#ifndef CPP_LEARNING_CASUALFILE_H
#define CPP_LEARNING_CASUALFILE_H


#include "File.h"

class CasualFile: public File {
private:
    Account *account;
public:
    CasualFile(){
        this->account=nullptr;
    }
    ~CasualFile() override {
        delete this->account;
    }

    bool load(vector<Account> &accounts, const string &fileName) override;

    bool save(const string &fileName, vector<Account> &accounts) override;

    bool update(const string &fileName, Account  &accounts) override;
};


#endif //CPP_LEARNING_CASUALFILE_H
