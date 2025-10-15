#include "Staff.h"
#include "Bank.h"

// Constructor
Staff::Staff(const string &n, int empId, int y)
    /* TODO: call the constructor of Employee and initialize the members */
    : Employee(n, empId), baseSalary(1000), years(y) {}

double Staff::calculateMonthlySalary() const {
  // TODO: calculate and return the staff member's monthly salary
  // E.g., base salary adjusted by years of experience
  return baseSalary + years * 100;
}

void Staff::openBankAccount(Bank &bank) {
  // TODO: Calculate initial deposit as 2 times monthly salary
  double deposit = 2 * calculateMonthlySalary();

  // TODO: create savings account with initial deposit using
  // bank.createAccount()
  bank.createAccount(this, deposit);
}
