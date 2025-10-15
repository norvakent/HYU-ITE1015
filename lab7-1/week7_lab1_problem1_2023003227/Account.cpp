#include "Account.h"

// Constructor
Account::Account(int id, const string &name, double deposit)
    // TODO: Use initializer list to set ownerId, ownerName, and balance
    : ownerId(id), ownerName(name), balance(deposit) {}

// Destructor
Account::~Account() {}

// Get interest rate (returns 0 for base Account)
double Account::getInterestRate() const { return 0.0; }

// Calculate interest based on current balance
double Account::calculateInterest() const {
  // TODO: Multiply balance by interest rate and return result
  return balance * Account::getInterestRate();
}

// Get account balance
double Account::getBalance() const {
  // TODO: Return the current balance
  return balance;
}

// Get owner information
int Account::getOwnerId() const {
  // TODO: Return the owner ID
  return ownerId;
}

string Account::getOwnerName() const {
  // TODO: Return the owner name
  return ownerName;
}