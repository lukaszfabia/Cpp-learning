#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

using namespace std;

class Validator
{
private:
    string username;
    string password;
    string email;
    string phoneNumber;

    bool hasProperLength(string data, size_t begin, size_t end);
    bool hasBigLetter(string data);
    bool hasOnlyLettersAndNumbers(string data);
    bool hasSpecialCharacter(string data);
    bool hasOnlyNumbers(string data);
    bool isProperEmail(string data);

    bool isUsernameValid();
    bool isPasswordValid();
    bool isEmailValid();
    bool isPhoneNumberValid();

public:
    Validator();
    Validator(string username, string password, string email, string phoneNumber);
    ~Validator();
    bool isValid();
    string getUsername();
    string getEmail();
    string getPhoneNumber();
};

#endif