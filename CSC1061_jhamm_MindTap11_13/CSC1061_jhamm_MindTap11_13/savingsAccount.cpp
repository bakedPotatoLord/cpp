
//Implementation File savingsAccountImp.cpp

#include <iostream>
#include <iomanip>
#include "savingsAccount.h"

using namespace std;

double savingsAccount::getInterestRate() const
{
	return interestRate;
}

void savingsAccount::setInterestRate(double rate)
{
	interestRate = (rate > 0) ? rate : 0;
}

void savingsAccount::withdraw(double amount)
{
	if (balance - amount >= 0) balance -= amount;
	else throw "insufficient funds";
}

void savingsAccount::postInterest()
{
	balance *= (1 + interestRate);
}

void savingsAccount::print() const
{
	cout << "Savings ACCT#:\t\t\t";
	bankAccount::print();
}

savingsAccount::savingsAccount(int acctNumber, double bal, double intRate):
	bankAccount(acctNumber,bal)
{
	interestRate = intRate;
}





