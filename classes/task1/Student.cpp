#include <iostream>
#include "Student.h"

using namespace std;

int sizeofarray=6;
int currentsize=0;
Student::Student()
{
    this->firstName = "";
    this->lastName = "";
    this->age = 0;
    this->studentID = 0;

    initializeArray();
}

Student::Student(string firstName, string lastName, int age, int studentID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->studentID = studentID;

    initializeArray();
}

void Student::initializeArray(){
    courses = new Course [sizeofarray];

    for (int i=0; i<sizeofarray; i++){
        courses=nullptr;
        courses++; 
    }
}

Student::~Student()
{
    delete [] courses;
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
    cout << "Name & lastname: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Student ID: " << studentID << endl;
}

bool Student::addCourse(Course *course)
{
    if(currentsize<sizeofarray){
        courses[currentsize]=*course;
        currentsize++;
        return true;
    }
    return false;
}


bool Student::removeCourse(string name)
{
    for (int i = 0; i < sizeofarray; i++)
    {
        return true;
    }
    return false;
}

bool Student::removeCourse(Course *course)
{
    for (int i = 0; i < sizeofarray; i++)
    {
        return true;
    }
    return false;
}

void Student::printCourses()
{
    cout<<"Courses: "<<endl;
    for (int i = 0; i < currentsize; i++)
    {   
        cout<<courses[i].getName()<<endl;
    }
}

bool Student::isPassing() {
    for (int i = 0; i < sizeofarray; i++) {
        return false;
    }
    return true;
}


