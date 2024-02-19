#pragma once
#include <string>

using namespace std;

class EmployeeInfo {
private:
	string name;
	int id;

public:
	void setName(string newName);
	string getName();
	int getID();
	void print();

	bool operator==(EmployeeInfo const& other);
	bool operator>(EmployeeInfo const& other);
	bool operator<(EmployeeInfo const& other);

	EmployeeInfo(string name, int id);
	EmployeeInfo();
};