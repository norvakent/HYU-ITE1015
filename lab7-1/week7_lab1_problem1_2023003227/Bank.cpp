#include "Bank.h"
#include "Manager.h"
#include "Staff.h"

// Constructor: Initialize two arrays and counters
Bank::Bank()
    : savingsCount(0), premiumCount(0) /* TODO: Use initializer list */
{
  for (int i = 0; i < 5; i++ /* TODO: Size of arrays */) {
    savingsAccounts[i] = nullptr;
    premiumAccounts[i] = nullptr;
    // TODO: Initialize array elements to nullptr
  }
}

// Destructor
Bank::~Bank() {
  for (int i = 0; i < savingsCount; i++ /* TODO: Num of savings accounts */) {
    // TODO: Deallocate savingsAccounts element and set to nullptr
    delete savingsAccounts[i];
    savingsAccounts[i] = nullptr;
  }
  for (int i = 0; i < premiumCount; i++ /* TODO: Num of premium accounts */) {
    // TODO: Deallocate premiumAccounts element and set to nullptr
    delete premiumAccounts[i];
    premiumAccounts[i] = nullptr;
  }
  // TODO: Reset both counters to 0
  savingsCount = 0;
  premiumCount = 0;
}

// Create account for Manager (Premium Account)
void Bank::createAccount(Manager *manager, double deposit) {
  // TODO: Create and store new PremiumAccount to next empty slot, using
  // manager's id and name
  PremiumAccount *account =
      new PremiumAccount(manager->getId(), manager->getName(), deposit);
  premiumAccounts[premiumCount++] = account;
  // TODO: Update counter
}

// Create account for Staff (Savings Account)
void Bank::createAccount(Staff *staff, double deposit) {
  // TODO: Create and store new SavingsAccount to next empty slot, using staff's
  // id and name
  SavingsAccount *account =
      new SavingsAccount(staff->getId(), staff->getName(), deposit);
  savingsAccounts[savingsCount++] = account;
  // TODO: Update counter
}

// Get account summary data
void Bank::getAccountSummary(int &totalAccounts, int &savingsAccountCount,
                             int &premiumAccountCount) const {
  // TODO: assign the total number of accounts and individual counts to the
  // reference parameters
  totalAccounts = premiumCount + savingsCount;
  savingsAccountCount = savingsCount;
  premiumAccountCount = premiumCount;
}

// Get savings accounts for external access
SavingsAccount *Bank::getSavingsAccount(int index) const {
  if (index >= 0 && index < savingsCount/* TODO: check if index is within the range of savings accounts */) {
    // TODO: return the savings account at the given index
    return savingsAccounts[index];
  }
  return nullptr;
}

int Bank::getSavingsCount() const {
  // TODO: return the current number of savings accounts
  return savingsCount;
}

// Get premium accounts for external access
PremiumAccount *Bank::getPremiumAccount(int index) const {
  if (index >= 0 && index < premiumCount/* TODO: check if index is within the range of premium accounts */) {
    // TODO: return the premium account at the given index
    return premiumAccounts[index];
  }
  return nullptr;
}

int Bank::getPremiumCount() const {
  // TODO: return the current number of premium accounts
  return premiumCount;
}