// TODO:  Student class methods implementation here.
#include <iostream>
#include "Student.hpp"
#include "LinkedList.hpp"
using namespace std;

Student::Student()
    : id(-1), name(""), gpa(0.0) {}

Student::Student(int id)
    : id(id), name(""), gpa(0.0) {}

Student::Student(int id, std::string name)
    : id(id), name(name), gpa(0.0) {}

Student::Student(int id, std::string name, double gpa)
    : id(id), name(name), gpa(gpa) {}

int Student::getId() {
    return id;
}

std::string Student::getNmae() {
    return name;
}

double Student::getGpa() {
    return gpa;
}

void Student::addCourse(const Course &c) {
    course_list.append(c);
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Student(" << s.id;
    if (!s.name.empty()) os << ", " << s.name;
    if (s.gpa != 0.0) os << ", " << s.gpa;
    os << ", Courses: ";
    if (s.course_list.isEmpty()) {
        os << "None";
    } else {
        for (int i = 0; i < s.course_list.getLength(); i++) {
            os << s.course_list.getElement(i);
            if (i + 1 < s.course_list.getLength()) {
                os << " | ";
            }
        }
    }
    os << ")";
    return os;
}
