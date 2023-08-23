#include <iostream>
#include "Registration.h"
#include "Registration.cpp"


using namespace std;

int main()
{
    Registration registration = Registration("nowePorawioene2002", "123456789AAAdmi!!n", "ufabiaw21@interia.pl", "123456789");
    cout<<registration.authorize()<<endl;
    registration.setEmail("ufabi1@interia.pl");
    registration.setPhoneNumber("123456781");
    registration.setUsername("nser202212HAAHAXD");
    cout<<registration.authorize()<<endl;
    registration.data.showData();

    return 0;
}