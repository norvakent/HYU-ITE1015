#include "SavingsAccount.h"

// Call parent constructor Account(id, name, deposit)
SavingsAccount::SavingsAccount(int id, const string &name, double deposit)
    /* TODO: call the constructor of Account */
    : Account(id, name, deposit) {}

double SavingsAccount::getInterestRate() const { return 0.03; }

// Return balance * interest rate (use getBalance() and getInterestRate())
double SavingsAccount::calculateInterest() const {
  // TODO: calculate interest by multiplying balance with interest rate
  return Account::getBalance() * SavingsAccount::getInterestRate();
}
