#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
}

Course::Course(string name, int ects, double grade){
    this->name = name;
    this->ects = ects;
    this->grade = grade;
}

Course::~Course()
{
}

string Course::getName(){
    return name;
}

int Course::getEcts(){
    return ects;
}

double Course::getGrade(){
    return grade;
}

void Course::setName(string name){
    this->name = name;
}

void Course::setEcts(int ects){
    this->ects = ects;
}

void Course::setGrade(double grade){
    this->grade = grade;
}

void Course::printCourses(){
    cout << "Course: " << name << " ECTS: " << ects << " Grade: " << grade << endl;
}


