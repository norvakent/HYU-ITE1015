#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

// Forward declaration
class Bank;

class Staff : public Employee {
private:
    double baseSalary;
    int years;

public:
    // Constructor to initialize staff with name, id and years of experience
    Staff(const string& n, int empId, int y);

    // Calculate monthly salary based on experience
    double calculateMonthlySalary() const;

    // Open savings bank account
    void openBankAccount(Bank& bank);

};

#endif