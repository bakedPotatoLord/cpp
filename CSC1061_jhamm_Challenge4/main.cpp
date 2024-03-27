// AI was used for autocompletion and comments in this project.
// code by @bakedPotatoLord 3/27/2024

#include "BinaryTree.h"
#include "EmployeeInfo.h"
#include <iostream>

using namespace std;

int main() {

  BinaryTree<EmployeeInfo> tree;

  tree.add(EmployeeInfo("John Williams", 1021));
  tree.add(EmployeeInfo("Bill Witherspoon", 1057));
  tree.add(EmployeeInfo("Jennifer Twain", 2487));
  tree.add(EmployeeInfo("Sophia Lancaster", 3769));
  tree.add(EmployeeInfo("Debbie Reece", 1017));

  tree.add(EmployeeInfo("George McMullen", 1275));
  tree.add(EmployeeInfo("Ashley Smith", 1899));
  tree.add(EmployeeInfo("Josh Plemmons", 4218));

  cout << "Welcome to Employee Binary Tree" << endl;
  cout << "-------------------------------" << endl;
  while (true) {
    cout << "Search for an Employee ID Number: ";
    int searchID;
    cin >> searchID;
    if (tree.hasID(searchID)) {
      EmployeeInfo info = tree.search(searchID);
      cout << "Employee found!  ";
      info.print();
    } else {
      cout << "Employee Not Found!" << endl;
    }
  }
  return 0;
}
