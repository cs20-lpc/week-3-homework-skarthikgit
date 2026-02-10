// TODO:  Course class definitins go here.
#include <iosfwd>
#include <string>

class Course {
private:
    std::string  name;
    std::string  location; 

public:
    Course(std::string, std::string);

    std::string getName();
    std::string getLocation();

    friend std::ostream& operator<<(std::ostream& os, const Course& c);
    
};
