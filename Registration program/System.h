#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include "Registration.h"
#include "Registration.cpp"

using namespace std;

class System
{
private:
    // vector <Account> accounts;

public:
    bool registerUser();
    bool loginUser();
};

#endif
