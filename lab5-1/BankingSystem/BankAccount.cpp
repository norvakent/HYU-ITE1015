#include "BankAccount.h"
BankAccount::BankAccount(const string& accNum, const string& name)
	: accountNumber(accNum), ownerName(name), balance(0) {}

void BankAccount::set_balance(int bal) {
	balance = bal;
}

int BankAccount::get_balance() const {
	return balance;
}

void BankAccount::display_info() const {
	cout << "Account: " << accountNumber <<
		", Owner: " << ownerName <<
		", Balance: $" << balance << endl;
}

void BankAccount::deposit() {
	int amount;
	cout << "Deposit: $";
	cin >> amount;

	if (amount > 0) {
		balance += amount; 
		cout << "Deposited $" << amount <<
			", Balance: $" << balance << endl;
	} else {
		cout << "Invalid amount" << endl;
	}
}

void BankAccount::withdraw() {
	int amount;
	cout << "Withdraw: $";
	cin >> amount;

	if (amount > 0 && amount <= balance) {
		balance -= amount; 
		cout << "Withdrew $" << amount <<
			", Balance: $" << balance;
	} else if (amount > balance) {
		cout << "Insufficient funds, Balance: $" << balance << endl;
	} else {
		cout << "Invalid amount" << endl;
	}
}
