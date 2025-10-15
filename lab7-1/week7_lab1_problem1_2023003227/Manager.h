#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

// Forward declaration
class Bank;

class Manager : public Employee {
private:
    double baseSalary;
    double bonus;

public:
    // Constructor to initialize manager with name, id and bonus
    Manager(const string& n, int empId, double b);

    // Calculate monthly salary including bonus
    double calculateMonthlySalary() const;

    // Open premium bank account
    void openBankAccount(Bank& bank);

};

#endif