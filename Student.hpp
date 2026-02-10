// TO DO:  Student class definition  here.
#include <iosfwd>
#include <string>
#include "Course.hpp"
#include "LinkedList.hpp"

class Student {
private:
    int id;
    std::string name;
    double gpa;
    LinkedList<Course> course_list;

public:
    Student();
    Student(int id);
    Student(int id, std::string name);
    Student(int id, std::string name, double gpa);

    int getId();
    std::string getNmae();
    double getGpa();

    void addCourse(const Course &c);

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};
