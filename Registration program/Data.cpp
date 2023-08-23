#include "Data.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Data::Data(Validator validator)
{
    this->validator = validator;
}

Data::~Data()
{
}

bool Data::check(Validator obj)
{
    return obj.getEmail() == this->validator.getEmail() ||
            obj.getPhoneNumber() == this->validator.getPhoneNumber() ||
            obj.getUsername() == this->validator.getUsername();
}

bool Data::isAllDataValid()
{
    return this->validator.isUsernameValid() &&
           this->validator.isPasswordValid() &&
           this->validator.isEmailValid() &&
           this->validator.isPhoneNumberValid();
}

bool Data::isUnique()
{
    for (Validator obj : data)
    {
        if (check(obj))
        {
            return false;
        }
    }
    return true;
}

bool Data::addData(Validator validator)
{
    if (data.empty())
    {
        data.push_back(validator);
    }
    else
    {
        if (isUnique() && isAllDataValid())
        {
            data.push_back(validator);
            return true;
        }
        else
        {
            return false;
        }
    }
}