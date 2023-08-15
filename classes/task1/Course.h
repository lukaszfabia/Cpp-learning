#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;
class Course
{
    private:
        string name;
        int ects;
        double grade;

    public:
        Course();
        Course(string name, int ects, double grade);
        ~Course();

        string getName();
        int getEcts();
        double getGrade();

        void setName(string name);
        void setEcts(int ects);
        void setGrade(double grade);
        void print();
};
#endif