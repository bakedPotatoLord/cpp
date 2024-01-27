
// Implementation file bankAccountImp.cpp

#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

// Constructor
bankAccount::bankAccount(int acctNumber, double bal)
{
    accountNumber = acctNumber;
    balance = bal;
}

void bankAccount::setAccountNumber(int num)
{
    accountNumber = num;
}

int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

double bankAccount::getBalance() const
{
    return balance;
}

void bankAccount::withdraw(double amount)
{
    balance -= amount;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::print() const
{
    cout << accountNumber << "\t Balance: $";
    printf("%.*f", 2, balance);
    cout << '\n';
}
