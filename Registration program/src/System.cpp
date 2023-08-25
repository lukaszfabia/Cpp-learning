#include "headers/System.h"
#include "headers/ReadInput.h"
#include "headers/File.h"
#include <algorithm>

System::System() {
    this->accounts = vector<Account>();
}

System::~System() {
    delete &accounts;
}

bool System::addNewAccount(Registration &registration) {
    if (accounts.empty() || isUnique(registration)) {
        Account account(registration);
        accounts.push_back(account);
        return File::save(registration, "data.txt");
    } else {
        return false;
    }
}

bool System::isUnique(const Registration &registration) {
    // functional example
    return all_of(accounts.begin(), accounts.end(), [registration](const Account &account) {
        return !equals(registration, account);
    });
}

bool System::equals(Registration registration, Account account) {
    return registration.getEmail() == account.getEmail() ||
           registration.getPhoneNumber() == account.getPhoneNumber() ||
           registration.getUsername() == account.getUsername();
}

bool System::registerUser() {
    string username;
    string password;
    string email;
    string phoneNumber;

    ReadInput::print("Enter username: ");
    username = ReadInput::readString(1);
    ReadInput::print("Enter password: ");
    password = ReadInput::readString(1);
    ReadInput::print("Enter email: ");
    email = ReadInput::readString(1);
    ReadInput::print("Enter phone number: ");
    phoneNumber = ReadInput::readString(1);


    Registration registration(username, password, email, phoneNumber);
    return registration.authorize() && addNewAccount(registration);
}

bool System::loginUser() {
    string username, password;
    ReadInput::print("Enter username: ");
    username = ReadInput::readString(1);
    ReadInput::print("Enter password: ");
    password = ReadInput::readString(1);

    for (Account account: accounts) {
        if (account.getUsername() == username && account.getPassword() == password) {
            ReadInput::print("Login successful!");
            setAccount(account);
            return true;
        }
    }
    ReadInput::print("Username or password is incorrect!");
    return false;
}


void System::setAccount(const Account &account) {
    this->temporaryAccount = account;
}

void System::home() {
    File::load(accounts, "data.txt");

    int choice;
    bool isRunning = true;
    while (isRunning) {
        ReadInput::print("1. Register\n");
        ReadInput::print("2. Login\n");
        ReadInput::print("3. Exit\n");
        ReadInput::print("Enter your choice: ");
        choice = ReadInput::readInt(1);

        switch (choice) {
            case 1:
                if (registerUser()) {
                    ReadInput::print("Registration successful!\n");
                } else {
                    ReadInput::print("Registration failed!\n");
                }
                break;
            case 2:
                if (loginUser()) {
                    mainMenu(temporaryAccount);
                    isRunning = false;
                }
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
    bool is_good = false;
    while (!is_good) {
        ReadInput::print("It looks like you don't have a set nationality! Do you want to fix it?\n");
        ReadInput::print("1. Yes\n");
        ReadInput::print("2. No\n");

        int choice = ReadInput::readInt(1);

        if (choice == 1) {
            account.setNationality();
            ReadInput::print(account.information());
            is_good = true;
        } else if (choice == 2) {
            ReadInput::print("It's ok then!\n");
            is_good = true;
        } else {
            ReadInput::print("Invalid choice!\n");
        }
    }
}

void System::mainMenu(Account &account) {
    ReadInput::print(account.information());

    if (account.getNationality().empty()) {
        handleNationality(account);
    }
}
