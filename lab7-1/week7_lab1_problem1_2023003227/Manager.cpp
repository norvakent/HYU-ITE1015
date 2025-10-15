#include "Manager.h"
#include "Bank.h"

// Constructor
Manager::Manager(const string &n, int empId, double b)
    /* TODO: call the constructor of Employee and use initializer list */
    : Employee(n, empId), baseSalary(2000), bonus(b) {}

// Override calculateMonthlySalary
double Manager::calculateMonthlySalary() const {
  // TODO: calculate and return the manager's monthly salary
  // E.g., base salary plus bonus amount
  return baseSalary + bonus;
}

// Override openBankAccount
void Manager::openBankAccount(Bank &bank) {
  // TODO: calculate initial deposit as 5 times monthly salary
  double deposit = 5 * calculateMonthlySalary();

  // TODO: create premium account with appropriate deposit using
  // bank.createAccount()
  bank.createAccount(this, deposit);
}
