#include "PremiumAccount.h"

// Constructor
PremiumAccount::PremiumAccount(int id, const string &name, double deposit)
    /* TODO: call the constructor of Account */
    : Account(id, name, deposit) {}

// Override getInterestRate
double PremiumAccount::getInterestRate() const { return 0.05; }

// Override calculateInterest
double PremiumAccount::calculateInterest() const {
  // TODO: calculate interest by multiplying balance with interest rate
  return Account::getBalance() * PremiumAccount::getInterestRate();
}