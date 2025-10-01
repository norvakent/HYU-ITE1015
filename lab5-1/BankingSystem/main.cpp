#include "BankAccount.h"

void display_menu() {
	cout << "\n=== Bank Account Menu ===" << endl;
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Check Balance" << endl;
	cout << "4. Account Info" << endl;
	cout << "5. Exit" << endl;
	cout << "Choose an option: ";
}

int main() {
	string Number;
	string Name;
	int balance;
	int choice;

	cout << "=== Bank Account Setup ===" << endl;
	cout << "Enter your account Number: ";
	cin >> Number;
	cout << "Enter your Name: ";
	cin >> Name;
	cout << "Enter your initial balance: ";
	cin >> balance;

	BankAccount account(Number, Name);
	account.set_balance(balance);

	cout << "\nAccount created" << endl;
	account.display_info();

	while (true) {
		display_menu();
		cin >> choice;

		switch (choice) {
			case 1:
				account.deposit();
				break;
			case 2:
				account.withdraw();
				break;
			case 3:
				cout << "Current balance: $" << account.get_balance() << endl;
				break;
			case 4:
				account.display_info();
				break;
			case 5:
				cout << "Good bye" << endl;
				return 0;
			default:
				cout << "Invalid choice" << endl;
			}
	}

	return 0;
}
