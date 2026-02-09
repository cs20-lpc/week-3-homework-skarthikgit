// TO DO:  Student class definition  here.

class Student {
private:
    int id;
    std::string name;
    double gpa;
public:
    Student(int id);
    Student(int id, std::string name);
    Student(int id, std::string name, double gpa);

    int getId();
    std::string getNmae();
    double getGpa();

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};
