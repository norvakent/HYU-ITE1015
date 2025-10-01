#include <iostream>
#include "VendingMachine.h"
using namespace std;

void showMenu() {
	cout << "\n=== Vending Machine Menu ===" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Select" << endl;
	cout << "3. Refund" << endl;
	cout << "4. Restock" << endl;
	cout << "5. SetPrice" << endl;
	cout << "6. Status" << endl;
	cout << "7. Exit" << endl;
	cout << "Choose an option: ";
}

bool readInt(const string& prompt, int& out) {
	cout << prompt;
	if (!(cin >> out)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input." << endl;
		return false;
	}
	return true;
}

bool readCode(const string& prompt, char& code) {
	cout << prompt;
	if (!(cin >> code)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input." << endl;
		return false;
	}
	return true;
}

int main() {
	VendingMachine vm;
	int choice;

	while (true) {
		showMenu();
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		
		switch (choice) {
			case 1: {
				int amount;
				if (readInt("Amount: ", amount)) {
					vm.insert(amount);
				}
				break;
				}
			case 2: {
				char code;
				if (readCode("Code (A/B/C): ", code)) {
					vm.select(code);
				}
				break;
				}
			case 3: {
				vm.refund();
				break;
				}
			case 4: {
				char code; int quantity;
				if (readCode("Code (A/B/C): ", code) && readInt("Quantity: ", quantity)) {
					vm.restock(code, quantity);
				}
				break;
				}
			case 5: {
				char code; int price;
				if (readCode("Code (A/B/C): ", code) && readInt("price: ", price)) {
					vm.setPrice(code, price);
				}
				break;
				}
			case 6: {
				cout << "\n=== Vending Machine Status ===" << endl;
				vm.status();
				break;
				}
			case 7:
				return 0;
			default:
				cout << "Invalid choice. Please select 1-7." << endl;
		}
	}
	
	return 0;
}

