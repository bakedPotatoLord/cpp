// AI tooling was used for autocompletion and comments on this project
//  This program utilizes a binary tree data structure to store and search for
//  employee information. Author: @bakedPotatoLord Date: 3/27/2024

#include "BinaryTree.h" // Include the header file for the binary tree implementation
#include "EmployeeInfo.h" // Include the header file for the EmployeeInfo class
#include <iostream>       // Include the standard input/output stream library

using namespace std; // Using the standard namespace for cout and cin

int main() {
  BinaryTree<EmployeeInfo>
      tree; // Create an instance of BinaryTree with EmployeeInfo data type

  // Add sample employee information to the binary tree
  tree.add(EmployeeInfo("John Williams", 1021));
  tree.add(EmployeeInfo("Bill Witherspoon", 1057));
  tree.add(EmployeeInfo("Jennifer Twain", 2487));
  tree.add(EmployeeInfo("Sophia Lancaster", 3769));
  tree.add(EmployeeInfo("Debbie Reece", 1017));
  tree.add(EmployeeInfo("George McMullen", 1275));
  tree.add(EmployeeInfo("Ashley Smith", 1899));
  tree.add(EmployeeInfo("Josh Plemmons", 4218));

  // Display welcome message
  cout << "Welcome to Employee Binary Tree" << endl;
  cout << "-------------------------------" << endl;

  // Continuous loop for searching employee IDs
  while (true) {
    cout << "Search for an Employee ID Number: ";
    int searchID;
    cin >> searchID;

    // Check if the employee ID exists in the binary tree
    if (tree.hasID(searchID)) {
      // If found, retrieve and print the employee information
      EmployeeInfo info = tree.search(searchID);
      cout << "Employee found!  ";
      info.print();
    } else {
      // If not found, display a message indicating the employee was not found
      cout << "Employee Not Found!" << endl;
    }
  }
  return 0;
}
