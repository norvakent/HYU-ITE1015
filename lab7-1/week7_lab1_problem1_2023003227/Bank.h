#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "SavingsAccount.h"
#include "PremiumAccount.h"

// Forward declarations
class Manager;
class Staff;

class Bank {
private:
    SavingsAccount* savingsAccounts[5];    // Maximum 5 savings accounts
    PremiumAccount* premiumAccounts[5];    // Maximum 5 premium accounts
    int savingsCount;
    int premiumCount;

public:
    // Constructor
    Bank();

    // Destructor
    ~Bank();

    // Create account for Manager (overloaded function)
    void createAccount(Manager* manager, double deposit);

    // Create account for Staff (overloaded function) 
    void createAccount(Staff* staff, double deposit);

    // Get account summary data
    void getAccountSummary(int& totalAccounts, int& savingsAccountCount, int& premiumAccountCount) const;
    
    // Get savings accounts for external access
    SavingsAccount* getSavingsAccount(int index) const;
    int getSavingsCount() const;
    
    // Get premium accounts for external access
    PremiumAccount* getPremiumAccount(int index) const;
    int getPremiumCount() const;
};

#endif