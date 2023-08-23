#include "System.h"
#include "Account.h"
#include <iostream>

System::System()
{
    this->accounts = vector<Account>();
}

System::~System()
{
    delete &accounts;
}

bool System::addNewAccount(Registration registration)
{
    if (accounts.empty() || isUnique(registration))
    {
        accounts.push_back(registration);
        return true;
    }
    else
    {
        return false;
    }
}

bool System::isUnique(Registration registration)
{
    for (Account account : accounts)
    {
        if (equals(registration, account))
        {
            return false;
        }
    }
    return true;
}

bool System::equals(Registration registration, Account account)
{
    return registration.getEmail() == account.getEmail() ||
        registration.getPhoneNumber() == account.getPhoneNumber() ||
        registration.getUsername() == account.getUsername();
}

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
    return registration.authorize() && addNewAccount(registration);
}

bool System::loginUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (Account account : accounts)
    {
        if (account.getUsername() == username && account.getPassword() == password)
        {
            cout<<"Login successful!"<<endl;
            setAccount(account);
            return true;
        }
    }
    cout<<"Username or password is incorrect!"<<endl;
    return false;
}

void System::setAccount(Account account)
{
    this->temporaryAccount = account;
}

void System::home()
{
    int choice;
    bool isRunning = true;
    while (isRunning)
    {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (registerUser())
            {
                cout << "Registration successful!" << endl;
            }
            else
            {
                cout << "Registration failed!" << endl;
            }
            break;
        case 2:
            if (loginUser())
            {
                mainMenu(temporaryAccount);
                isRunning = false;
            }
            break;
        case 3:
            isRunning = false;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}

void handleNationality(Account &account) {
    cout << "It looks like you don't have a set nationality! Do you want to fix it?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        account.setNationality();
    } else if (choice == 2) {
        cout << "Ok, you can do it later!" << endl;
    } else {
        cout << "Invalid choice!" << endl;
        handleNationality(account);
    }
}

void System::mainMenu(Account &account) {
    cout << account.information() << endl;

    if (account.getNationality() == "") {
        handleNationality(account);
    }
}

