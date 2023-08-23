#include "Account.h"
#include "Validator.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account()
{
    this->username = "";
    this->password = "";
    this->email = "";
    this->phoneNumber = "";
    this->balance = 0;
}

Account::Account(string username, string password, string email, string phoneNumber)
{
    this->username = username;
    this->password = password;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->balance = 0;
}

Account::Account(Registration registration)
{
    this->username = registration.getUsername();
    this->password = registration.getPassword();
    this->email = registration.getEmail();
    this->phoneNumber = registration.getPhoneNumber();
    this->balance = 0;
}

Account::~Account()
{
}

string Account::getUsername()
{
    return this->username;
}

string Account::getEmail()
{
    return this->email;
}

string Account::getPhoneNumber()
{
    return this->phoneNumber;
}

string Account::getPassword()
{
    return this->password;
}

string Account::getNationality()
{
    return this->nationality;
}

string Account::information()
{
    return username + " " + to_string(balance);
}

void Account::setNationality()
{
    string new_nationality;
    cout<<"Enter new nationality: ";
    cin>>new_nationality;

    this->nationality = new_nationality;
}

