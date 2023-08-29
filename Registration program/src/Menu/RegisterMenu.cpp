//
// Created by ufabi on 27.08.2023.
//

#include "headers/Menu/RegisterMenu.h"
#include "headers/Tools/System and control/ReadInput.h"
#include "headers/Processes/Process.h"
#include "headers/Processes/RegistrationProcess.h"
#include <string>

void RegisterMenu::showPrompts() {
    std::string username, password, email, phoneNumber;
    ReadInput::print("Registration\nEnter username: ");
    username = getData();
    ReadInput::print("Enter password: ");
    password = getData();
    ReadInput::print("Enter email: ");
    email = getData();
    ReadInput::print("Enter phone number: ");
    phoneNumber = getData();

    auto *registration = new Registration(username, password, email, phoneNumber);
    setRegistration(registration);
}

int RegisterMenu::getChoice() {
    return ReadInput::readInt(1);
}

void RegisterMenu::show() {
    showPrompts();
    Process *process = new RegistrationProcess(accounts, newRegistration);
    if (process->run()) {
        ReadInput::print("Registration successful!\nNow you can login.\n");
    } else {
        ReadInput::print("Registration failed!\n");
    }
}

void RegisterMenu::setRegistration(Registration *registration) {
    this->newRegistration = registration;
}


std::string RegisterMenu::getData() {
    return ReadInput::readString(1);
}
