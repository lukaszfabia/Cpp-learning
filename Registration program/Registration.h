#ifndef REGISTRATION_H
#define REGISTRATION_H


#include <string>
#include "Validator.h"
#include "Validator.cpp"

using namespace std;

class Registration
{
private:
    Validator validator;
    string username;
    string password;
    string email;
    string phoneNumber;
    
    string authorize();

public:
    Registration();
    Registration(string username, string password, string email, string phoneNumber);
    ~Registration();

    void form();

    void setUsername(string username);
    void setPassword(string password);
    void setEmail(string email);
    void setPhoneNumber(string phoneNumber);
};

#endif
    