#include "Validator.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;

Validator::Validator()
{
    this->email = "";
    this->password = "";
    this->phoneNumber = "";
    this->username = "";
}

Validator::Validator(string username, string password, string email, string phoneNumber)
{
    this->email = email;
    this->password = password;
    this->phoneNumber = phoneNumber;
    this->username = username;
}

Validator::~Validator()
{
}

bool Validator::isValid()
{
    return isUsernameValid() || isPasswordValid() || isEmailValid() || isPhoneNumberValid();
}

bool Validator::hasProperLength(string data, size_t begin, size_t end)
{
    return data.length() > begin && data.length() < end;
}

bool Validator::hasBigLetter(string data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data.at(i) <= 'Z' && data.at(i) >= 'A')
        {
            return true;
        }
    }
    return false;
}

bool Validator::hasOnlyLettersAndNumbers(string data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if ((data.at(i) < '0' || data.at(i) > '9') &&
            (data.at(i) < 'A' || data.at(i) > 'Z') &&
            (data.at(i) < 'a' || data.at(i) > 'z'))
        {
            return false;
        }
    }
    return true;
}

bool Validator::hasOnlyNumbers(string data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data.at(i) < '0' || data.at(i) > '9')
        {
            return false;
        }
    }
    return true;
}

bool Validator::hasSpecialCharacter(string data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if ((data.at(i) < '0' || data.at(i) > '9') &&
            (data.at(i) < 'A' || data.at(i) > 'Z') &&
            (data.at(i) < 'a' || data.at(i) > 'z'))
        {
            return true;
        }
    }
    return false;
}

bool Validator::isProperEmail(string data)
{
    string input = data;
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, '.'))
    {
        tokens.push_back(token);
    }

    return data.find('@') != string::npos &&
           (tokens[tokens.size() - 1] == "com" || tokens[tokens.size() - 1] == "pl");
}

bool Validator::isUsernameValid()
{
    return !(hasProperLength(username, 5, 40) && hasBigLetter(username) && hasOnlyLettersAndNumbers(username));
}

bool Validator::isPasswordValid()
{
    return !(hasProperLength(password, 8, 40) && hasBigLetter(password) && hasSpecialCharacter(password));
}

bool Validator::isEmailValid()
{
    return !(isProperEmail(email) && hasProperLength(email, 5, 40));
}

bool Validator::isPhoneNumberValid()
{
    return !(hasOnlyNumbers(phoneNumber) && hasProperLength(phoneNumber, 8, 10));
}

string Validator::getUsername()
{
    return this->username;
}

string Validator::getEmail()
{
    return this->email;
}

string Validator::getPhoneNumber()
{
    return this->phoneNumber;
}