#include "VendingMachine.h"
#include <iostream>
using namespace std;

VendingMachine::VendingMachine()
	: balance(0), priceA(500), priceB(700), priceC(1000), stockA(5), stockB(5), stockC(5) {}

bool VendingMachine::isValidCode(char code) const {
	if (code >= 'A' && code <= 'C') return true;
	return false;
}

int VendingMachine::getPrice(char code) const {
	switch (code) {
		case 'A':
			return priceA;
		case 'B':
			return priceB;
		case 'C':
			return priceC;
	}
	return 0;
}

int VendingMachine::getStock(char code) const {
	switch (code) {
		case 'A':
			return stockA;
		case 'B':
			return stockB;
		case 'C':
			return stockC;
	}
	return 0;
}

void VendingMachine::setPriceInternal(char code, int newPrice) {
	switch (code) {
		case 'A':
			priceA = newPrice;
			break;
		case 'B':
			priceB = newPrice;
			break;
		case 'C':
			priceC = newPrice;
			break;
	}
}

void VendingMachine::addStockInternal(char code, int quantity) {
	switch (code) {
		case 'A':
			stockA += quantity;
			break;
		case 'B':
			stockB += quantity;
			break;
		case 'C':
			stockC += quantity;
			break;
	}
}


void VendingMachine::printChange(int amount) const {
	int c500, c100, c50, c10;
	c500 = amount / 500;
	amount %= 500;
	c100 = amount / 100;
	amount %= 100;
	c50 = amount / 50;
	amount %= 50;
	c10 = amount / 10;
	amount %= 10;

	cout << "Change: 500x" << c500
	<< " 100x" << c100
	<< " 50x" << c50
	<< " 10x" << c10
	<< endl;
}

void VendingMachine::insert(int amount) {
	if (amount <= 0 || (amount % 10)) {
		cout << "Invalid amount" << endl;
		return;
	}

	balance += amount;

	cout << "Inserted: " << amount << endl;
}

bool VendingMachine::select(char code) {
	if (!isValidCode(code)) {
		cout << "Invalid code" << endl;
		return false;
	}

	if (getStock(code) == 0) {
		cout << "Out of stock" << endl;
		return false;
	}

	if (balance < getPrice(code)) {
		cout << "Insufficient balance" << endl;
		return false;
	}

	balance -= getPrice(code);
	addStockInternal(code, -1);

	cout << "Dispensed " << code << ". Balance: " << balance << endl;

	return true;
}

void VendingMachine::refund() {
	cout << "Refund: " << balance << endl;

	printChange(balance);

	balance = 0;
}

void VendingMachine::restock(char code, int quantity) {
	if (!isValidCode(code)) {
		cout << "Invalid code" << endl;
		return;
	}
	
	if (quantity <= 0) {
		cout << "Invalid quantity" << endl;
		return;
	}

	addStockInternal(code, quantity);

	cout << "Restocked " << code << " by " << quantity << ". Stock: " << getStock(code) << endl;
}

void VendingMachine::setPrice(char code, int newPrice) {
	if (!isValidCode(code)) {
		cout << "Invalid code" << endl;
		return;
	}

	if (newPrice < 100 || (newPrice % 10)) {
		cout << "Invalid price" << endl;
		return;
	}

	setPriceInternal(code, newPrice);

	cout << "Price updated " << code << ": " << getPrice(code) << endl;
}

void VendingMachine::status() const {
	cout << "A: price=" << priceA << ", stock=" << stockA <<
	" | B: price=" << priceB << ", stock=" << stockB << 
	" | C: price=" << priceC << ", stock=" << stockC <<
	" | balance=" << balance << endl;
}
