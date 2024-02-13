
// Class checkingAccount

#ifndef H_checkingAccount
#define H_checkingAccount

#include "bankAccount.h"

constexpr double DEFAULT_INTEREST_RATE_CHECKING = 0.04;
constexpr double DEFAULT_MIN_BALANCE = 500.00;
constexpr double DEFAULT_SERVICE_CHARGE = 20;

class checkingAccount : public bankAccount
{
public:
    double getMinimumBalance() const;
    void setMinimumBalance(double minBalance);
    double getInterestRate() const;
    void setInterestRate(double intRate);
    double getServiceCharge() const;
    void setServiceCharge(double serviceChg);
    void postInterest();
    bool verifyMinimumBalance(double amount);
    void writeCheck(double amount);
    void withdraw(double amount);
    void print() const;

    checkingAccount(int acctNumber, double bal,
                    double minBal = DEFAULT_MIN_BALANCE,
                    double intRate = DEFAULT_INTEREST_RATE_CHECKING,
                    double servC = DEFAULT_SERVICE_CHARGE);

protected:
    double interestRate;
    double minimumBalance;
    double serviceCharge;
};

#endif
