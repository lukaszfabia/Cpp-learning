#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Course.h"
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    int studentID;
    int age;
    Course *courses;


    void initializeArray();

public:
    Student();
    Student(string firstName, string lastName, int age, int studentID);
    ~Student();

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setStudentID(int id);
    void setAge(int age);

    string getFirstName();
    string getLastName();
    int getStudentID();
    int getAge();


    void print();
    bool addCourse(Course* course);
    bool removeCourse(Course* course);
    bool removeCourse(string name);
    void printCourses();

    bool isPassing();
};

#endif
