#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>
#include "headers/Tools/Validator.h"

using namespace std;

class Registration {
private:
    string username;
    string password;
    string email;
    string phoneNumber;

protected:
    Validator validator;

public:
    Registration(const string &username, const string &password, const string &email, const string &phoneNumber);

    ~Registration();

    string getUsername();

    string getEmail();

    string getPhoneNumber();

    string getPassword();

    bool authorize();

};

#endif