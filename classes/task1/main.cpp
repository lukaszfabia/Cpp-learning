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
    Course *c3 = new Course("Analysis", 7, 5.0);
    cout<<s1.addCourse(c1)<<endl;
    cout<<s1.addCourse(c2)<<endl;
    cout<<s1.addCourse(c3)<<endl;
    cout<<"test"<<endl;
    s1.printCourses();

    return 0;
}