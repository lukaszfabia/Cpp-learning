#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>
#include "Validator.h"
#include "Validator.cpp" 

using namespace std;

class Registration
{
private:
    string username;
    string password;
    string email;
    string phoneNumber;

protected:
    Validator validator;

public: 
    Registration(string username, string password, string email, string phoneNumber);
    ~Registration();

    string getUsername();
    string getEmail();
    string getPhoneNumber();
    string getPassword();

    bool authorize();

};

#endif