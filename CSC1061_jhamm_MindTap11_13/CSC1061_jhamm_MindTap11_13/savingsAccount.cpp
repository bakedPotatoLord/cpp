// Implementation File savingsAccount.cpp

#include <iostream>
#include <iomanip>
#include "savingsAccount.h"

using namespace std;

// Get the interest rate
double savingsAccount::getInterestRate() const
{
	return interestRate;
}

// Set the interest rate, ensuring it's non-negative
void savingsAccount::setInterestRate(double rate)
{
	interestRate = (rate > 0) ? rate : 0;
}

// Withdraw specified amount from the balance, throw an exception if funds are insufficient
void savingsAccount::withdraw(double amount)
{
	if (balance - amount >= 0)
		balance -= amount;
	else
		throw "insufficient funds";
}

// Post interest to the account balance
void savingsAccount::postInterest()
{
	balance *= (1 + interestRate);
}

// Print account information, including account type and base class details
void savingsAccount::print() const
{
	cout << "Savings ACCT#:\t\t\t";
	bankAccount::print();  // Call the base class print function
}

// Constructor with initialization list to initialize base class
savingsAccount::savingsAccount(int acctNumber, double bal, double intRate) : bankAccount(acctNumber, bal)
{
	interestRate = intRate;
}
