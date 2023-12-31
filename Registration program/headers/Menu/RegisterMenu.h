#ifndef CPP_LEARNING_REGISTERMENU_H
#define CPP_LEARNING_REGISTERMENU_H


#include "Menu.h"

class RegisterMenu : public Menu {
private:
    Registration *newRegistration;

    void showPrompts() override;

    int getChoice() override;

    std::string getData() override;

    void setRegistration(Registration *registration);

public:
    explicit RegisterMenu(vector<Account> &accounts) : Menu(accounts) {
        this->newRegistration = nullptr;
    };

    ~RegisterMenu() override {
        delete newRegistration;
    };

    void show() override;
};


#endif //CPP_LEARNING_REGISTERMENU_H
