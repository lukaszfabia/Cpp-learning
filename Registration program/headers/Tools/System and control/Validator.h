#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

using namespace std;

class Validator {
private:
    string username;
    string password;
    string email;
    string phoneNumber;

    static bool hasProperLength(const string &data, size_t begin, size_t end);

    static bool hasBigLetter(const string &data);

    static bool hasOnlyLettersAndNumbers(const string &data);

    static bool hasSpecialCharacter(const string &data);

    static bool hasOnlyNumbers(const string &data);

    static bool isProperEmail(const string &data);

    bool isUsernameValid();

    bool isPasswordValid();

    bool isEmailValid();

    bool isPhoneNumberValid();

public:
    Validator();

    Validator(string username, string password, string email, string phoneNumber);

    ~Validator();

    bool isValid();

    bool isUsernameValid(const string& new_username);

    bool isPasswordValid(const string& new_password);

    bool isEmailValid(const string& new_email);

    bool isPhoneNumberValid(const string& new_phone_number);
};

#endif