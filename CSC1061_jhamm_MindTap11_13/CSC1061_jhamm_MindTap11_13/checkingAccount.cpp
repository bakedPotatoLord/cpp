#include "checkingAccount.h"
#include <iostream>

using namespace std;

checkingAccount::checkingAccount(int acctNumber, double bal, double minBal, double intRate, double servC) :
bankAccount(acctNumber,bal)
{
	minimumBalance = minBal;
	interestRate = intRate;
	serviceCharge = servC;
}

double checkingAccount::getMinimumBalance() const
{
	return minimumBalance;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
	minimumBalance = (minBalance > 0) ? minBalance : 0;
}

double checkingAccount::getInterestRate() const
{
	return interestRate;
}

void checkingAccount::setInterestRate(double intRate)
{
	interestRate = (intRate > 0) ? intRate : 0;
}

double checkingAccount::getServiceCharge() const
{
	return serviceCharge;
}

void checkingAccount::setServiceCharge( double serviceChg)
{
	serviceCharge = (serviceChg> 0) ? serviceChg : 0;
}
void checkingAccount::postInterest()
{
	balance *= (1 + interestRate);
}

bool checkingAccount::verifyMinimumumBalance(double amount)
{
	return amount < minimumBalance;
}

void checkingAccount::writeCheck(double amount)
{
	balance -= amount;
}

void checkingAccount::withdraw(double amount)
{
	balance -= amount;
	if (balance < minimumBalance) balance -= serviceCharge;
}

void checkingAccount::print() const
{
	cout << "Interest Checking ACCT#:\t";
	bankAccount::print();
}





