#include "EmployeeInfo.h" // Include the header file that contains the class declaration
#include <iostream> // Include the standard input/output stream library

using namespace std; // Using the standard namespace for cout and endl

// Set the name of the employee
void EmployeeInfo::setName(string newName) { name = newName; }

// Get the name of the employee
string EmployeeInfo::getName() { return name; }

// Get the ID of the employee
int EmployeeInfo::getID() { return id; }

// Print the information of the employee
void EmployeeInfo::print() {
  cout << "Employee #" << id << "\t" << name << endl;
}

// Overloaded equality operator to compare two EmployeeInfo objects
bool EmployeeInfo::operator==(EmployeeInfo const &other) {
  return id == other.id;
}

// Overloaded greater than operator to compare two EmployeeInfo objects
bool EmployeeInfo::operator>(EmployeeInfo const &other) {
  return id > other.id;
}

// Overloaded less than operator to compare two EmployeeInfo objects
bool EmployeeInfo::operator<(EmployeeInfo const &other) {
  return id < other.id;
}

// Overloaded equality operator to compare an EmployeeInfo object with an
// integer
bool EmployeeInfo::operator==(int const &other) { return id == other; }

// Overloaded greater than operator to compare an EmployeeInfo object with an
// integer
bool EmployeeInfo::operator>(int const &other) { return id > other; }

// Overloaded less than operator to compare an EmployeeInfo object with an
// integer
bool EmployeeInfo::operator<(int const &other) { return id < other; }

// Constructor with parameters to initialize name and id
EmployeeInfo::EmployeeInfo(string name, int id) {
  this->name = name;
  this->id = id;
}

// Default constructor to initialize name and id with default values
EmployeeInfo::EmployeeInfo() {
  name = "unnamed";
  id = -1;
}
