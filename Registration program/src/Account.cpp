#include "headers/Account.h"
#include "headers/ReadInput.h"
#include <string>
#include <utility>

using namespace std;

Account::Account() {
    this->username = "";
    this->password = "";
    this->email = "";
    this->phoneNumber = "";
    this->balance = 0;
}

Account::Account(string username, string password, string email, string phoneNumber) {
    this->username = std::move(username);
    this->password = std::move(password);
    this->email = std::move(email);
    this->phoneNumber = std::move(phoneNumber);
    this->balance = 0;
}

Account::Account(Registration registration) {
    this->username = registration.getUsername();
    this->password = registration.getPassword();
    this->email = registration.getEmail();
    this->phoneNumber = registration.getPhoneNumber();
    this->balance = 0;
}

Account::~Account()
= default;

string Account::getUsername() {
    return this->username;
}

string Account::getEmail() {
    return this->email;
}

string Account::getPhoneNumber() {
    return this->phoneNumber;
}

string Account::getPassword() {
    return this->password;
}

string Account::getNationality() {
    return this->nationality;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::setBalance(double money) {
    this->balance = money;
}

string Account::information() {
    return "\nLogin: " + username + "\nYour balance: " + to_string(getBalance()) + "\nNationality: " +
           getNationality() + "\n";
}

void Account::setNationality() {
    string new_nationality;
    ReadInput::print("Enter new nationality: ");
    //cout << "Enter new nationality: ";
    //cin >> new_nationality;

    this->nationality = ReadInput::readString(1);
}

