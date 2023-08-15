#include "Student.h"
#include "Student.cpp"
#include "Course.h"
#include "Course.cpp"
#include <iostream>

int main() {
    Student s1("John", "Doe", 20, 123456789);
    s1.print();
    Course *c1 = new Course("C++", 3, 3.0);
    Course *c2 = new Course("Java", 4, 4.0);
    s1.addCourse(c1);
    s1.addCourse(c2);
    s1.printCourses();

    return 0;
}