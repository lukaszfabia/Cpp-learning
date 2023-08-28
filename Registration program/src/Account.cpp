#include "headers/Account.h"
#include "headers/Tools/ReadInput.h"
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

void Account::setNationality() {
    ReadInput::print("Enter new nationality: ");
    this->nationality = ReadInput::readString(1);
}

void Account::setNationality(std::string newNationality) {
    this->nationality = std::move(newNationality);
}
