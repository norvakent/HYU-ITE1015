#ifndef PREMIUMACCOUNT_H
#define PREMIUMACCOUNT_H

#include "Account.h"

class PremiumAccount : public Account {
public:
    // Constructor to initialize premium account
    PremiumAccount(int id, const string& name, double deposit);

    // Get premium account interest rate
    double getInterestRate() const;
    
    // Calculate interest for premium account
    double calculateInterest() const;
};

#endif