#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    this->firstName = "";
    this->lastName = "";
    this->age = 0;
    this->studentID = 0;
}

Student::Student(string firstName, string lastName, int age, int studentID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->studentID = studentID;
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

void Student::addCourse(Course *course)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] == nullptr)
        {
            courses[i] = course;
            break;
        }
    }
}

void Student::removeCourse(string name)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] != nullptr && courses[i]->getName() == name)
        {
            courses[i] = nullptr;
            break;
        }
    }
}

void Student::removeCourse(Course *course)
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] == course)
        {
            courses[i] = nullptr;
            break;
        }
    }
}

void Student::printCourses()
{
    for (int i = 0; i < 10; i++)
    {
        if (courses[i] != nullptr)
        {
            cout << courses[i]->getName() << endl;
        }
    }
}
