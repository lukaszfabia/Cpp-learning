#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Registration.h"

using namespace std;

class Account {
private:
    string username;
    string password;
    string email;
    string phoneNumber;
    string nationality;
    double balance;
    int id;

public:
    Account();

    Account(string username, string password, string email, string phoneNumber, string nationality, double balance, int id);

    explicit Account(Registration *registration);

    ~Account();

    //getters
    string getUsername();

    string getEmail();

    string getPhoneNumber();

    string getPassword();

    string getNationality();

    [[nodiscard]] int getID() const;

    [[nodiscard]] double getBalance() const;

    //setters
    void setBalance(double money);

    void setNationality(string newNationality);

    void setUsername(string newUsername);

    void setPassword(string newPassword);

    void setPhoneNumber(string newPhoneNumber);

    void setEmail(string newMail);

    void setID(int new_id);

    string information();
};

#endif