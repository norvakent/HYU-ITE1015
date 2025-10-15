#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Bank;

class Employee {
private:
    string name;
    int id;

public:
    // Constructor to initialize employee with name and id
    Employee(const string& n, int empId);

    // Destructor
    ~Employee();

    // Calculate monthly salary
    double calculateMonthlySalary() const;

    // Open bank account
    void openBankAccount(Bank& bank);

    // Get employee information
    string getName() const;
    int getId() const;

};

#endif