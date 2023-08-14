#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(string firstName, string lastName, int age, int studentID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->studentID = studentID;
}

Student::~Student()
{
    cout << "Student destructor called" << endl;
}

string Student::getFirstName()
{
    return this->firstName;
}

string Student::getLastName()
{
    return this->lastName;
}

int Student::getAge()
{
    return this->age;
}

int Student::getStudentID()
{
    return this->studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setStudentID(int studentID)
{
    this->studentID = studentID;
}

void Student::print()
{
    cout<<"Name & lastname: "<<firstName<<" "<<lastName<<endl;
    cout << "Age: " << age << endl;
    cout << "Student ID: " << studentID << endl;
}

