#include <iostream>
#include "EmployeeInfo.h"

using namespace std;

void EmployeeInfo::setName(string newName)
{
	name = newName;
}

string EmployeeInfo::getName()
{
	return name;
}

int EmployeeInfo::getID()
{
	return id;
}

void EmployeeInfo::print()
{
	cout << "Employee #" << id << "\t" << name << endl;
}

bool EmployeeInfo::operator==(EmployeeInfo const& other)
{
	return id == other.id;
}

bool EmployeeInfo::operator>(EmployeeInfo const& other)
{
	return id > other.id;
}

bool EmployeeInfo::operator<(EmployeeInfo const& other)
{
	return id < other.id;
}

bool EmployeeInfo::operator==(int const& other)
{
	return id == other;
}

bool EmployeeInfo::operator>(int const& other)
{
	return id > other;
}

bool EmployeeInfo::operator<(int const& other)
{
	return id < other;
}

EmployeeInfo::EmployeeInfo(string name, int id)
{
	this->name = name;
	this->id = id;
}

EmployeeInfo::EmployeeInfo()
{
	name = "unnamed";
	id = -1;
}


