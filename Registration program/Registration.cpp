#include <string>
#include <iostream>
#include <fstream>
#include "Registration.h"
#include "Validator.h"

using namespace std;

Registration::Registration()
{
    this->username = "";
    this->password = "";
    this->email = "";
    this->phoneNumber = "";
}

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

string Registration::authorize()
{
    bool isAllDataValid = validator.isUsernameValid() &&
                          validator.isPasswordValid() &&
                          validator.isEmailValid() &&
                          validator.isPhoneNumberValid();

    if (isAllDataValid)
    {
        save();
    }

    //return isAllDataValid ? "Registration successful!" : "Registration failed!";
    return to_string(validator.isPasswordValid());
}

void Registration::save()
{
    ofstream File;
    File.open("data.txt", ios::app);
    if (File.is_open()){
        File << this->username << " ";
        File << this->password << " ";
        File << this->email << " ";
        File << this->phoneNumber << endl;
        File.close();
    }else{
        cout << "Unable to open file";
    }
}

void Registration::form()
{
    cout << "Username: ";
    cin >> this->username;
    cout << "Password: ";
    cin >> this->password;
    cout << "Email: ";
    cin >> this->email;
    cout << "Phone number: ";
    cin >> this->phoneNumber;

    cout << authorize() << endl;
}

void Registration::setUsername(string username)
{
    this->username = username;
}

void Registration::setPassword(string password)
{
    this->password = password;
}

void Registration::setEmail(string email)
{
    this->email = email;
}

void Registration::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
