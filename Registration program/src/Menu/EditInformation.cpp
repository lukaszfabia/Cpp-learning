#include "headers/Menu/EditInformation.h"
#include "headers/Tools/System and control/ReadInput.h"
#include "headers/Tools/System and control/ConsoleControl.h"

void EditInformation::run() {
    int choice = 0;
    while (choice != 6) {
        ConsoleControl::sleep(1);
        ConsoleControl::clearConsole();
        ReadInput::print("What do you want to edit:\n");
        ReadInput::print("1. Edit username\n");
        ReadInput::print("2. Edit password\n");
        ReadInput::print("3. Edit email\n");
        ReadInput::print("4. Edit phone number\n");
        ReadInput::print("5. Edit nationality\n");
        ReadInput::print("6. Main menu\n");
        ReadInput::print("Enter you choice: ");
        choice = ReadInput::readInt(1);
        switch (choice) {
            case 1:
                editUsername();
                break;
            case 2:
                editPassword();
                break;
            case 3:
                editEmail();
                break;
            case 4:
                editPhoneNumber();
                break;
            case 5:
                editNationality();
                break;
            case 6:
                // exit
                ConsoleControl::clearConsole();
                break;
            default:
                ReadInput::print("Wrong number!\n");
        }
    }
}

bool EditInformation::editUsername() {
    std::string username;
    while (true) {
        ReadInput::print("Actual username: " + actualAccount->getUsername() + "\n");
        ReadInput::print("Insert new username: ");
        username = ReadInput::readString(1);
        if (!validator->isUsernameValid(username)) {
            actualAccount->setUsername(username);
            bool isEdited = file->update(actualAccount);
            if (isEdited){
                ReadInput::print(actualAccount->getUsername() + " has been set!\n");
                return true;
            }else{
                ReadInput::print("Something went wrong!\n");
            }
        } else {
            ReadInput::print("Invalid username!\n");
        }
    }
}

bool EditInformation::editPassword() {
    std::string password;
    while (true) {
        ReadInput::print("Actual password: " + actualAccount->getPassword() + "\n");
        ReadInput::print("Insert new password: ");
        password = ReadInput::readString(1);
        if (!validator->isPasswordValid(password) && password != actualAccount->getPassword()) {
            actualAccount->setPassword(password);
            bool isEdited = file->update(actualAccount);
            if (isEdited){
                ReadInput::print(actualAccount->getPassword() + " has been set!\n");
                return true;
            }else{
                ReadInput::print("Something went wrong!\n");
            }
        } else {
            ReadInput::print("Invalid password!\n");
        }
    }
}

bool EditInformation::editEmail() {
    std::string newMail;
    while (true) {
        ReadInput::print("Actual email: " + actualAccount->getEmail() + "\n");
        ReadInput::print("Insert new email: ");
        newMail = ReadInput::readString(1);
        if (!validator->isEmailValid(newMail)) {
            actualAccount->setEmail(newMail);
            bool isEdited = file->update(actualAccount);
            if (isEdited){
                ReadInput::print(actualAccount->getEmail() + " has been set!\n");
                return true;
            }else{
                ReadInput::print("Something went wrong!\n");
            }
        } else {
            ReadInput::print("Invalid email!\n");
        }
    }
}

bool EditInformation::editNationality() {
    ReadInput::print("Actual nationality: " + actualAccount->getNationality() + "\n");
    ReadInput::print("Insert new nationality: ");
    std::string newNationality = ReadInput::readString(1);
    actualAccount->setNationality(newNationality);
    bool isEdited = file->update(actualAccount);
    ReadInput::print(actualAccount->getNationality() + " has been set!\n");
    return isEdited;
}

bool EditInformation::editPhoneNumber() {
    std::string newPhoneNumber;
    while (true) {
        ReadInput::print("Actual phone number: " + actualAccount->getPhoneNumber() + "\n");
        ReadInput::print("Insert new phone number: ");
        newPhoneNumber = ReadInput::readString(1);
        if (!validator->isPhoneNumberValid(newPhoneNumber)) {
            actualAccount->setPhoneNumber(newPhoneNumber);
            bool isEdited = file->update(actualAccount);
            if (isEdited){
                ReadInput::print(actualAccount->getPhoneNumber() + " has been set!\n");
                return true;
            }else{
                ReadInput::print("Something went wrong!\n");
            }
        } else {
            ReadInput::print("Invalid phone number!\n");
        }
    }
}