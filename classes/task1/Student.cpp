#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    this->firstName = "";
    this->lastName = "";
    this->age = 0;
    this->studentID = 0;

    for (int i=0; i<10; i++){
        courses[i] = nullptr;
    }
}

Student::Student(string firstName, string lastName, int age, int studentID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->studentID = studentID;

    for (int i=0; i<10; i++){
        courses[i] = nullptr;
    }
}

Student::~Student()
{
    for (int i=0; i<10; i++){
        if (courses[i] != nullptr){
            delete courses[i];
        }
    }
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

Course **Student::getCourses()
{
    return courses;
}

void Student::print()
{
    cout << "Name & lastname: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Student ID: " << studentID << endl;
}

bool Student::addCourse(Course *course)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] == nullptr)
        {
            courses[i] = course;
            return true;
        }
    }
    return false;
}

bool Student::removeCourse(string name)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] != nullptr && courses[i]->getName() == name)
        {
            courses[i] = nullptr;
            return true;
        }
    }
    return false;
}

bool Student::removeCourse(Course *course)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] == course)
        {
            courses[i] = nullptr;
            return true;
        }
    }
    return false;
}

void Student::printCourses()
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] != nullptr)
        {
            cout<<courses[i]->getName()<<endl;
        }
    }
}

bool Student::isPassing(){
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] != nullptr)
        {
            if (courses[i]->getGrade() < 3.0)
            {
                return false;
            }
        }
    }
    return true;
}
