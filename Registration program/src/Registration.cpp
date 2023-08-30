#include "headers/Registration.h"
#include <string>

using namespace std;

Registration::Registration(const string &username, const string &password, const string &email,
                           const string &phoneNumber) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->validator = Validator(username, password, email, phoneNumber);
}

Registration::~Registration()
= default;

string Registration::getUsername() {
    return this->username;
}

string Registration::getEmail() {
    return this->email;
}

string Registration::getPhoneNumber() {
    return this->phoneNumber;
}

string Registration::getPassword() {
    return this->password;
}

bool Registration::authorize() {
    return !validator.isValid();
}

void Registration::setHashcode() {
    this->hashcode = std::hash<std::string>{}(this->username + this->password + this->email + this->phoneNumber);
}

size_t Registration::getHashcode() const {
    return this->hashcode;
}
