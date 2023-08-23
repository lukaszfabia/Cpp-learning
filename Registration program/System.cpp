#include "System.h"
#include <iostream>

bool System::registerUser()
{
    string username;
    string password;
    string email;
    string phoneNumber;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    Registration registration(username, password, email, phoneNumber);
    return registration.authorize();
}

bool System::loginUser(){
    // TODO: implement
    return true;
}