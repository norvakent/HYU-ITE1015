#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int ownerId;
    string ownerName;
    double balance;

public:
    // Constructor to initialize account with owner info and initial deposit
    Account(int id, const string& name, double deposit);

    // Destructor
    ~Account();

    // Get interest rate (returns 0 for base Account)
    double getInterestRate() const;

    // Calculate interest based on current balance
    double calculateInterest() const;

    // Get account balance
    double getBalance() const;

    // Get owner information
    int getOwnerId() const;
    string getOwnerName() const;
};

#endif