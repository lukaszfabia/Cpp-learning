#include "headers/Menu/EditInformation.h"
#include "headers/Tools/System and control/ReadInput.h"
#include "headers/Tools/System and control/ConsoleControl.h"

void EditInformation::run() {
    ConsoleControl::clearConsole();
    int choice = 0;
    while (choice != 6) {
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
        ReadInput::print("Insert new username: ");
        username = ReadInput::readString(1);
        if (!validator->isUsernameValid(username)) {
            actualAccount->setUsername(username);
            return file->update(actualAccount);
        } else {
            ReadInput::print("Invalid username!\n");
        }
    }
}

bool EditInformation::editPassword() {
    std::string password;
    while (true) {
        ReadInput::print("Insert new password: ");
        password = ReadInput::readString(1);
        if (!validator->isPasswordValid(password)) {
            actualAccount->setPassword(password);
            return file->update(actualAccount);
        } else {
            ReadInput::print("Invalid password!\n");
        }
    }
}

bool EditInformation::editEmail() {
    std::string newMail;
    while (true) {
        ReadInput::print("Insert new email: ");
        newMail = ReadInput::readString(1);
        if (!validator->isEmailValid(newMail)) {
            actualAccount->setEmail(newMail);
            return file->update(actualAccount);
        } else {
            ReadInput::print("Invalid email!\n");
        }
    }
}

bool EditInformation::editNationality() {
    std::string newNationality = ReadInput::readString(1);
    actualAccount->setNationality(newNationality);
    bool isEdited = file->update(actualAccount);
    ReadInput::print(actualAccount->getNationality() + " has been set!\n");
    return isEdited;
}

bool EditInformation::editPhoneNumber() {
    std::string newPhoneNumber;
    while (true) {
        ReadInput::print("Insert new phone number: ");
        newPhoneNumber = ReadInput::readString(1);
        if (!validator->isPhoneNumberValid(newPhoneNumber)) {
            actualAccount->setPhoneNumber(newPhoneNumber);
            return file->update(actualAccount);
        } else {
            ReadInput::print("Invalid phone number!\n");
        }
    }
}