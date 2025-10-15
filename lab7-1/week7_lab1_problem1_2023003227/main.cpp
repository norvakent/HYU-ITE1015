#include "Employee.h"
#include "Manager.h"
#include "Staff.h"
#include "Bank.h"

// Display the main menu options
void showMenu() {
    cout << "\n=== Bank Management System ===" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Display Employee Information" << endl;
    cout << "3. Open Bank Accounts for All Employees" << endl;
    cout << "4. Display Bank Account Summary" << endl;
    cout << "5. Display All Account Details" << endl;
    cout << "6. Exit program" << endl;
    cout << "Choose option: ";
}

// Get employee type from user input
string getEmployeeType() {
    string type;
    cout << "Enter employee type (Manager/Staff): ";
    if (!(cin >> type)) {
        return "";
    }
    
    if (type != "Manager" && type != "Staff") {
        cout << "Invalid employee type. Please enter 'Manager' or 'Staff'." << endl;
        return "";
    }
    
    return type;
}

// Get employee information from user
bool getEmployeeInfo(string& name, int& id, int& value, const string& employeeType) {
    cout << "Enter employee name: ";
    if (!(cin >> name)) {
        return false;
    }
    
    cout << "Enter employee ID: ";
    if (!(cin >> id)) {
        return false;
    }
    
    if (employeeType == "Manager") {
        cout << "Enter bonus amount: ";
    } else {
        cout << "Enter years of service: ";
    }
    
    if (!(cin >> value)) {
        return false;
    }
    
    return true;
}

// Handle adding a new employee
void addEmployee(Manager* managers[], Staff* staffs[], int& managerCount, int& staffCount) {
    if (managerCount + staffCount >= 10) {
        cout << "Maximum number of employees reached." << endl;
        return;
    }
    
    string type = getEmployeeType();
    if (type.empty()) {
        return;
    }
    
    string name;
    int id, value;
    if (!getEmployeeInfo(name, id, value, type)) {
        cout << "Invalid input." << endl;
        return;
    }
    
    if (type == "Manager") {
        if (managerCount >= 5) {
            cout << "Maximum number of managers reached." << endl;
            return;
        }
        managers[managerCount++] = new Manager(name, id, value);
    } else {
        if (staffCount >= 5) {
            cout << "Maximum number of staff reached." << endl;
            return;
        }
        staffs[staffCount++] = new Staff(name, id, value);
    }
}

// Display employee information
void displayEmployeeInfo(Manager* managers[], Staff* staffs[], int managerCount, int staffCount) {
    if (managerCount == 0 && staffCount == 0) {
        cout << "No employees found." << endl;
        return;
    }
    
    cout << "=== Employee Information ===" << endl;
    
    if (managerCount > 0) {
        cout << "Managers:" << endl;
        for (int i = 0; i < managerCount; i++) {
            cout << "Name: " << managers[i]->getName() << ", ID: " << managers[i]->getId() << endl;
            cout << "Monthly Salary: $" << managers[i]->calculateMonthlySalary() << endl;
            cout << endl;
        }
    }
    
    if (staffCount > 0) {
        cout << "Staff:" << endl;
        for (int i = 0; i < staffCount; i++) {
            cout << "Name: " << staffs[i]->getName() << ", ID: " << staffs[i]->getId() << endl;
            cout << "Monthly Salary: $" << staffs[i]->calculateMonthlySalary() << endl;
            cout << endl;
        }
    }
}

// Open bank accounts for all employees
void openBankAccounts(Manager* managers[], Staff* staffs[], int managerCount, int staffCount, Bank& myBank) {
    if (managerCount == 0 && staffCount == 0) {
        cout << "No employees found. Please add employees first." << endl;
        return;
    }
    
    cout << "=== Account Opening Process ===" << endl;
    
    // Managers open accounts
    for (int i = 0; i < managerCount; i++) {
        cout << managers[i]->getName() << " (Manager) is opening a bank account..." << endl;
        managers[i]->openBankAccount(myBank);
        cout << "Premium Account created for " << managers[i]->getName() 
             << " with $" << (managers[i]->calculateMonthlySalary() * 5) << " initial deposit" << endl;
        cout << endl;
    }
    
    // Staff open accounts
    for (int i = 0; i < staffCount; i++) {
        cout << staffs[i]->getName() << " (Staff) is opening a bank account..." << endl;
        staffs[i]->openBankAccount(myBank);
        cout << "Savings Account created for " << staffs[i]->getName() 
             << " with $" << (staffs[i]->calculateMonthlySalary() * 2) << " initial deposit" << endl;
        cout << endl;
    }
    
}

// Display bank account summary
void displayAccountSummary(Bank& myBank) {
    int totalAccounts, savingsAccountCount, premiumAccountCount;
    myBank.getAccountSummary(totalAccounts, savingsAccountCount, premiumAccountCount);
    
    if (totalAccounts == 0) {
        cout << "No bank accounts found. Please open accounts first." << endl;
        return;
    }
    
    cout << "=== Bank Account Summary ===" << endl;
    cout << "Total Accounts: " << totalAccounts << endl;
    cout << "Savings Accounts: " << savingsAccountCount << endl;
    cout << "Premium Accounts: " << premiumAccountCount << endl;
}

// Display all account details
void displayAllAccountDetails(Bank& myBank) {
    int totalAccounts, savingsAccountCount, premiumAccountCount;
    myBank.getAccountSummary(totalAccounts, savingsAccountCount, premiumAccountCount);
    
    if (totalAccounts == 0) {
        cout << "No bank accounts found. Please open accounts first." << endl;
        return;
    }
    
    cout << "=== All Account Details ===" << endl;
    
    // Display savings accounts
    for (int i = 0; i < myBank.getSavingsCount(); i++) {
        SavingsAccount* acc = myBank.getSavingsAccount(i);
        cout << "Account Owner: " << acc->getOwnerName() << " (ID: " << acc->getOwnerId() << ")" << endl;
        cout << "Account Type: Savings Account" << endl;
        cout << "Balance: $" << acc->getBalance() << endl;
        cout << "Interest Rate: " << (acc->getInterestRate() * 100) << "%" << endl;
        cout << "Interest Earned: $" << acc->calculateInterest() << endl;
        cout << "------------------------" << endl;
    }
    
    // Display premium accounts
    for (int i = 0; i < myBank.getPremiumCount(); i++) {
        PremiumAccount* acc = myBank.getPremiumAccount(i);
        cout << "Account Owner: " << acc->getOwnerName() << " (ID: " << acc->getOwnerId() << ")" << endl;
        cout << "Account Type: Premium Account" << endl;
        cout << "Balance: $" << acc->getBalance() << endl;
        cout << "Interest Rate: " << (acc->getInterestRate() * 100) << "%" << endl;
        cout << "Interest Earned: $" << acc->calculateInterest() << endl;
        cout << "*** PREMIUM CUSTOMER ***" << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    Manager* managers[5];
    Staff* staffs[5];
    int managerCount = 0;
    int staffCount = 0;
    Bank myBank;
    int choice;
    
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addEmployee(managers, staffs, managerCount, staffCount);
                break;
            case 2:
                displayEmployeeInfo(managers, staffs, managerCount, staffCount);
                break;
            case 3:
                openBankAccounts(managers, staffs, managerCount, staffCount, myBank);
                break;
            case 4:
                displayAccountSummary(myBank);
                break;
            case 5:
                displayAllAccountDetails(myBank);
                break;
            case 6:
                // Clean up memory before exit
                for (int i = 0; i < managerCount; i++) {
                    delete managers[i];
                    managers[i] = nullptr;
                }
                for (int i = 0; i < staffCount; i++) {
                    delete staffs[i];
                    staffs[i] = nullptr;
                }
                return 0;
            default:
                cout << "Invalid choice. Please select 1-6." << endl;
        }
    }
    
    return 0;
}