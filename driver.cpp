#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.
#include "LinkedList.hpp"

using namespace std;

void insert_student(LinkedList<Student> *);
void search_student(LinkedList<Student> *);
void delete_student(LinkedList<Student> *);
void choice_help();

int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
  LinkedList<Student> studentList;

  int choice = -1;

  choice_help();

  while (choice != 7) {
    cout << "Enter choice: ";
    cin >> choice;
    if ( choice < 1 || choice > 7) {
      cout << "Bad Choice!" << endl;
      choice_help();
      continue;
    }
    switch (choice)
    {
      case 1:
        insert_student(&studentList); 
        break;
      case 2:
        delete_student(&studentList);
        break;
      case 3:
        search_student(&studentList);
        break;
      case 4:
        cout << studentList << endl;
        break;
      case 5:
        cout << "Total students: " << studentList.getLength() << endl;
        break;
      case 6:
        break;
      case 7:
        break;
      default:
        break;
    }

  }
  return 0;
}

void insert_student(LinkedList<Student> *studentList) {
  int id;
  string name;
  double gpa;

  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter GPA: ";
  cin >> gpa;

  Student s = Student(id, name, gpa);
  (*studentList).append(s);
}

void search_student(LinkedList<Student> *studentList) {
  int id = 0;

  cout << "Enter ID to search: ";
  cin >> id;

  if (studentList->isEmpty()) {
    cout << "List is empty." << endl;
    return;
  }

  for (int i = 0; i < studentList->getLength(); i++) {
    Student s = studentList->getElement(i);
    if (s.getId() == id) {
      cout << "Found: " << s.getId() << " " << s.getNmae() << " " << s.getGpa() << endl;
      return;
    }
  }

  cout << "Student with ID " << id << " not found." << endl;
}

void delete_student(LinkedList<Student> *studentList) {
  int id = 0;

  cout << "Enter ID to delete: ";
  cin >> id;

  if (studentList->isEmpty()) {
    cout << "List is empty." << endl;
    return;
  }

  for (int i = 0; i < studentList->getLength(); i++) {
    Student s = studentList->getElement(i);
    if (s.getId() == id) {
      studentList->remove(i);
      cout << "Deleted student with ID " << id << endl;
      return;
    }
  }
  cout << "Student with ID " << id << " not found." << endl;
}
void choice_help() {
    cout << "1. Insert Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Display All" << endl;
    cout << "5. Count Students" << endl;
    cout << "6. Add a course" << endl;
    cout << "7. Exit" << endl;
}
