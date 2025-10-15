#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    // Constructor to initialize savings account
    SavingsAccount(int id, const string& name, double deposit);

    // Get savings account interest rate
    double getInterestRate() const;
    
    // Calculate interest for savings account
    double calculateInterest() const;
};

#endif