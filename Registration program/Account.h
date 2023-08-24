#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Registration.h"

using namespace std;

class Account
{
private:
    string username;
    string password;
    string email;
    string phoneNumber;
    string nationality;
    double balance;

public:
    Account();
    Account(string username, string password, string email, string phoneNumber);
    Account(Registration registration);
    ~Account();

    //getters
    string getUsername();
    string getEmail();
    string getPhoneNumber();
    string getPassword();
    string getNationality();
    double getBalance();

    string information();
    void setNationality();
};

#endif