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

// Set the account number
void bankAccount::setAccountNumber(int num)
{
    accountNumber = num;
}

// Get the account number
int bankAccount::getAccountNumber() const
{
    return accountNumber;
}

// Get the current balance
double bankAccount::getBalance() const
{
    return balance;
}

// Withdraw specified amount from the balance
void bankAccount::withdraw(double amount)
{
    balance -= amount;
}

// Deposit specified amount to the balance
void bankAccount::deposit(double amount)
{
    balance += amount;
}

// Print account information, including account number and balance
void bankAccount::print() const
{
    cout << accountNumber << "\t Balance: $";
    printf("%.*f", 2, balance);  // Print balance with 2 decimal places
    cout << '\n';
}
