#include <iostream>
#include "Registration.h"
#include "Registration.cpp"


using namespace std;

int main()
{
    Registration registration;
    registration.setEmail("ufabiaw21@interia.pl");
    registration.setUsername("uFabiaw21");
    registration.setPassword("123456789AAAdmin!");
    registration.setPhoneNumber("12345891");
    cout<<registration.authorize()<<endl;
    return 0;
}