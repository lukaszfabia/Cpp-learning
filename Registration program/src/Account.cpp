#include "headers/Account.h"
#include <string>
#include <utility>

Account::Account() {
    this->username = "";
    this->password = "";
    this->email = "";
    this->phoneNumber = "";
    this->nationality = "NULL";
    this->balance = 0;
}

Account::Account(std::string username, std::string password, std::string email, std::string phoneNumber) {
    this->username = std::move(username);
    this->password = std::move(password);
    this->email = std::move(email);
    this->phoneNumber = std::move(phoneNumber);
    this->nationality = "NULL";
    this->balance = 0;
}

Account::Account(Registration *registration) {
    this->username = registration->getUsername();
    this->password = registration->getPassword();
    this->email = registration->getEmail();
    this->phoneNumber = registration->getPhoneNumber();
    this->nationality = "NULL";
    this->balance = 0;
}

Account::~Account() = default;

std::string Account::getUsername() {
    return this->username;
}

std::string Account::getEmail() {
    return this->email;
}

std::string Account::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Account::getPassword() {
    return this->password;
}

std::string Account::getNationality() {
    return this->nationality;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::setBalance(double money) {
    this->balance = money;
}

void Account::setNationality(std::string newNationality) {
    this->nationality = std::move(newNationality);
}

std::string Account::information() {
    return "\nUsername: " + getUsername() +
           "\nEmail: " + getEmail() +
           "\nPhone number: " + getPhoneNumber() +
           "\nNationality: " + getNationality() +
           "\nBalance: " + to_string(getBalance()) +
           "\n";
}

void Account::setUsername(std::string newUsername) {
    this->username = std::move(newUsername);
}

void Account::setPassword(std::string newPassword) {
    this->password = std::move(newPassword);
}

void Account::setEmail(std::string newMail) {
    this->email = std::move(newMail);
}

void Account::setPhoneNumber(std::string newPhoneNumber) {
    this->phoneNumber = std::move(newPhoneNumber);
}
