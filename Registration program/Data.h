#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include "Validator.h"
#include "Validator.cpp"

using namespace std;

class Data
{
    private:
        Validator validator;
        vector <Validator> data;
        string username;
        string email;
        string phoneNumber;

        bool check(Validator obj);
        bool isAllDataValid();
        bool isUnique();

    public:
        Data(Validator validator);
        ~Data();
        bool addData(Validator validator);
};

#endif
