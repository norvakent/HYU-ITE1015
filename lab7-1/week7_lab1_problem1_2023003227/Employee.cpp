#include "Employee.h"

// Constructor
Employee::Employee(const string &n, int empId)
    /* TODO: initialize name and id using initializer list */
    : name(n), id(empId) {}

// Destructor
Employee::~Employee() {}

// Get employee name
string Employee::getName() const {
  // TODO: return employee name
  return name;
}

// Get employee ID
int Employee::getId() const {
  // TODO: return employee id
  return id;
}

// Base salary calculation
double Employee::calculateMonthlySalary() const { return 0; }

// Base bank account opening
void Employee::openBankAccount(Bank &bank) {
  // Base implementation does nothing
}
