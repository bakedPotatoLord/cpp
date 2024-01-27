#include "checkingAccount.h"
#include <iostream>

using namespace std;

// Constructor with initialization list to initialize base class
checkingAccount::checkingAccount(int acctNumber, double bal, double minBal, double intRate, double servC) : bankAccount(acctNumber, bal)
{
	minimumBalance = minBal;
	interestRate = intRate;
	serviceCharge = servC;
}

// Get the minimum balance
double checkingAccount::getMinimumBalance() const
{
	return minimumBalance;
}

// Set the minimum balance, ensuring it's non-negative
void checkingAccount::setMinimumBalance(double minBalance)
{
	minimumBalance = (minBalance > 0) ? minBalance : 0;
}

// Get the interest rate
double checkingAccount::getInterestRate() const
{
	return interestRate;
}

// Set the interest rate, ensuring it's non-negative
void checkingAccount::setInterestRate(double intRate)
{
	interestRate = (intRate > 0) ? intRate : 0;
}

// Get the service charge
double checkingAccount::getServiceCharge() const
{
	return serviceCharge;
}

// Set the service charge, ensuring it's non-negative
void checkingAccount::setServiceCharge(double serviceChg)
{
	serviceCharge = (serviceChg > 0) ? serviceChg : 0;
}

// Post interest to the account balance
void checkingAccount::postInterest()
{
	balance *= (1 + interestRate);
}

// Verify if the given amount is below the minimum balance
bool checkingAccount::verifyMinimumBalance(double amount)
{
	return amount < minimumBalance;
}

// Write a check, deducting the specified amount from the balance
void checkingAccount::writeCheck(double amount)
{
	balance -= amount;
}

// Withdraw specified amount from the balance, and apply service charge if necessary
void checkingAccount::withdraw(double amount)
{
	balance -= amount;
	if (balance < minimumBalance)
		balance -= serviceCharge;
}

// Print account information, including account type and base class details
void checkingAccount::print() const
{
	cout << "Interest Checking ACCT#:\t";
	bankAccount::print();  // Call the base class print function
}
