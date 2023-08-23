#include "Registration.h"
#include <string>

using namespace std;

Registration::Registration(string username, string password, string email, string phoneNumber)
{
    this->username = username;
    this->password = password;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->validator = Validator(username, password, email, phoneNumber);
}

Registration::~Registration()
{
}

string Registration::getUsername()
{
    return this->username;
}

string Registration::getEmail()
{
    return this->email;
}

string Registration::getPhoneNumber()
{
    return this->phoneNumber;
}

string Registration::getPassword()
{
    return this->password;
}

bool Registration::authorize()
{
    return !validator.isValid();
}
