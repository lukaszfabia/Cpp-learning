#include <string>
#include <iostream>
#include <fstream>
#include "Registration.h"
#include "Validator.h"
#include "Data.h"

using namespace std;

Registration::Registration()
{
    this->username = "";
    this->password = "";
    this->email = "";
    this->phoneNumber = "";
    this->validator = Validator();
    this->data = Data(validator);
}

Registration::Registration(string username, string password, string email, string phoneNumber)
{
    this->username = username;
    this->password = password;
    this->email = email;
    this->phoneNumber = phoneNumber;
    this->validator = Validator(username, password, email, phoneNumber);
    this->data = Data(validator);
}

Registration::~Registration()
{
}

string Registration::authorize()
{
    if (data.addData(validator))
    {
        save();
        return "Registration successful";
    }
    else
    {
        return "Registration failed";
    }
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