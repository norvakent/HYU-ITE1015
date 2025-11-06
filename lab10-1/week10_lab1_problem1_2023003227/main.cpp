#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// Base class for a generic bank account.
class Account {
protected:
  // Core account attributes.
  const string owner;
  const int accountNumber;
  const double annualInterestRate;
  double balance;

public:
  // Constructor to initialize account properties.
  Account(const string ownerName, int accNum, double initBalance,
          double interestRate)
      : owner(ownerName), accountNumber(accNum), balance(initBalance),
        annualInterestRate(interestRate) {}

  // --- Getters ---
  double getBalance() const { return balance; }
  int getAccountNumber() const { return accountNumber; }
  string getOwner() const { return owner; }
  double getAnnualInterestRate() const { return annualInterestRate; }

  // Deposits a positive amount, returns true on success.
  bool deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      return true;
    }
    return false;
  }

  // Virtual method for withdrawing funds.
  virtual bool withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      return true;
    }
    return false;
  }

  // Virtual method for interest calculation. Default is 0.
  virtual double calculateInterest(int months) const { return 0.0; }

  // Applies calculated interest to the balance.
  void applyMonthlyInterest(int months) {
    balance += this->calculateInterest(months);
  }

  // Virtual destructor for proper cleanup of derived objects.
  virtual ~Account() {}
};

// Derived class for an account with an overdraft limit.
class OverdraftAccount : public Account {
  // TODO: implement OverdraftAccount
private:
  double creditLimit;

public:
  OverdraftAccount(const string ownerName, int accNum, double initBalance,
                   double interestRate, double creditLimit)
      : Account(ownerName, accNum, initBalance, interestRate),
        creditLimit(creditLimit) {}
  bool withdraw(double amount) override {
    if (amount > 0 && (balance + creditLimit) >= amount) {
      balance -= amount;
      return true;
    }
    return false;
  }
  double calculateInterest(int months) const override {
    if (balance >= 0)
      return balance * (annualInterestRate / 12) * months;
    double compoundInterest = 1;
    for (int i = 0; i < months; i++) {
      compoundInterest *= (1 + annualInterestRate / 12);
    }
    return balance * (compoundInterest - 1);
  }
};
// Derived class for a standard account without overdraft.
class RegularAccount : public Account {
  // TODO: implement RegularAccount
public:
  RegularAccount(const string ownerName, int accNum, double initBalance,
                 double interestRate)
      : Account(ownerName, accNum, initBalance, interestRate) {}
  double calculateInterest(int months) const override {
    return balance * (annualInterestRate / 12) * months;
  }
};

int main() {
  // Base class pointer for polymorphism.
  Account *acc = nullptr;

  // --- 1. Initial Account Creation ---
  cout << "[Account Program] Select account type to create." << endl;
  cout << "1. Regular Account" << endl;
  cout << "2. Overdraft Account" << endl;
  cout << "Enter choice: ";
  string choice_str;
  cin >> choice_str;

  string owner;
  int accNum;
  double initBalance, interestRate;

  if (choice_str == "1") {
    cout << "Enter Owner, AccountNumber, InitialBalance, InterestRate: ";
    cin >> owner >> accNum >> initBalance >> interestRate;
    acc = new RegularAccount(owner, accNum, initBalance, interestRate);
    cout << "[Account Program] Regular account for " << owner << " created."
         << endl;
  } else if (choice_str == "2") {
    double creditLimit;
    cout << "Enter Owner, AccountNumber, InitialBalance, InterestRate, "
            "CreditLimit: ";
    cin >> owner >> accNum >> initBalance >> interestRate >> creditLimit;
    acc = new OverdraftAccount(owner, accNum, initBalance, interestRate,
                               creditLimit);
    cout << "[Account Program] Overdraft account for " << owner << " created."
         << endl;
  } else {
    cout << "[Account Program] Invalid choice. Exiting." << endl;
    return 1; // Exit with an error code if choice is invalid.
  }

  // --- 2. Main Command Loop ---
  string command;
  while (true) {
    cout << "\n> Select an option by number or name:" << endl;
    cout << "  1. DEPOSIT" << endl;
    cout << "  2. WITHDRAW" << endl;
    cout << "  3. CALCULATE_INTEREST" << endl;
    cout << "  4. APPLY_INTEREST" << endl;
    cout << "  5. DISPLAY" << endl;
    cout << "  6. EXIT" << endl;
    cout << "Enter command: ";
    cin >> command;

    if (command == "DEPOSIT" || command == "1") {
      double amount;
      cout << "Amount to deposit: ";
      cin >> amount;
      if (acc->deposit(amount)) {
        cout << "[Account Program] Deposited $" << amount
             << ". Current balance: $" << acc->getBalance() << endl;
      } else {
        cout << "[Account Program] Invalid deposit amount." << endl;
      }
    } else if (command == "WITHDRAW" || command == "2") {
      double amount;
      cout << "Amount to withdraw: ";
      cin >> amount;
      if (acc->withdraw(amount)) {
        cout << "[Account Program] Withdrawn $" << amount
             << ". Current balance: $" << acc->getBalance() << endl;
      } else {
        cout << "[Account Program] Invalid withdrawal amount or insufficient "
                "funds/credit."
             << endl;
      }
    } else if (command == "CALCULATE_INTEREST" || command == "3") {
      int months;
      cout << "Number of months: ";
      cin >> months;
      double interest = acc->calculateInterest(months);
      cout << "[Account Program] Interest after " << months << " months: $"
           << interest << endl;
    } else if (command == "APPLY_INTEREST" || command == "4") {
      int months;
      cout << "Number of months: ";
      cin >> months;
      acc->applyMonthlyInterest(months);
      cout << "[Account Program] Interest applied for " << months
           << " months. Current balance: $" << acc->getBalance() << endl;
    } else if (command == "DISPLAY" || command == "5") {
      cout << "[Account Program] Owner: " << acc->getOwner() << ", Account No. "
           << acc->getAccountNumber() << endl;
      cout << "[Account Program] Current balance: $" << acc->getBalance()
           << endl;
      cout << "[Account Program] Annual Interest Rate: "
           << (acc->getAnnualInterestRate() * 100) << "%" << endl;
    } else if (command == "EXIT" || command == "6") {
      cout << "[Account Program] Exiting." << endl;
      break; // Exit the while loop
    } else {
      cout << "[Account Program] Invalid command." << endl;
    }
  }

  // --- 3. Final Cleanup ---
  if (acc != nullptr) {
    delete acc;
    acc = nullptr;
  }

  return 0;
}