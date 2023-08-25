#include "headers/Validator.h"
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

Validator::Validator() {
    this->email = "";
    this->password = "";
    this->phoneNumber = "";
    this->username = "";
}

Validator::Validator(string username, string password, string email, string phoneNumber) {
    this->email = std::move(email);
    this->password = std::move(password);
    this->phoneNumber = std::move(phoneNumber);
    this->username = std::move(username);
}

Validator::~Validator()
= default;

bool Validator::isValid() {
    return isUsernameValid() || isPasswordValid() || isEmailValid() || isPhoneNumberValid();
}

bool Validator::hasProperLength(const string &data, size_t begin, size_t end) {
    return data.length() > begin && data.length() < end;
}

bool Validator::hasBigLetter(const string &data) {
    return any_of(data.begin(), data.end(), [](char i) { return i >= 'A' && i <= 'Z'; });
}

bool Validator::hasOnlyLettersAndNumbers(const string &data) {
    return all_of(data.begin(), data.end(), [](char i) { return (i < '0' || i > '9') &&
                                                                (i < 'A' || i > 'Z') &&
                                                                (i < 'a' || i > 'z'); });
}

bool Validator::hasOnlyNumbers(const string &data) {
    return all_of(data.begin(), data.end(), [](char i) { return i >= '0' && i <= '9'; });
}

bool Validator::hasSpecialCharacter(const string &data) {
    for (char i: data) {
        if ((i < '0' || i > '9') &&
            (i < 'A' || i > 'Z') &&
            (i < 'a' || i > 'z')) {
            return true;
        }
    }
    return false;
}

bool Validator::isProperEmail(const string &data) {
    const string &input = data;
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, '.')) {
        tokens.push_back(token);
    }

    return data.find('@') != string::npos &&
           (tokens[tokens.size() - 1] == "com" || tokens[tokens.size() - 1] == "pl");
}

bool Validator::isUsernameValid() {
    return !(hasProperLength(username, 5, 40) && hasBigLetter(username) && hasOnlyLettersAndNumbers(username));
}

bool Validator::isPasswordValid() {
    return !(hasProperLength(password, 8, 40) && hasBigLetter(password) && hasSpecialCharacter(password));
}

bool Validator::isEmailValid() {
    return !(isProperEmail(email) && hasProperLength(email, 5, 40));
}

bool Validator::isPhoneNumberValid() {
    return !(hasOnlyNumbers(phoneNumber) && hasProperLength(phoneNumber, 8, 10));
}

string Validator::getUsername() {
    return this->username;
}

string Validator::getEmail() {
    return this->email;
}

string Validator::getPhoneNumber() {
    return this->phoneNumber;
}