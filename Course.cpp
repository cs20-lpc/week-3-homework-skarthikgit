// TODO:  Course class methods implementation here.
#include "Course.hpp"
#include <iostream>
using namespace std;

Course::Course(std::string name, std::string location)
    : name(name), location(location) {}

std::string Course::getName()
{
    return name;
}

std::string Course::getLocation()
{
    return location;
}

std::ostream& operator<<(std::ostream& os, const Course& c) {
    // os << "Course(" << c.name << ", " << c.location << ")";
    os <<  "[" << c.name << ", " << c.location << "]";
    return os;
}
