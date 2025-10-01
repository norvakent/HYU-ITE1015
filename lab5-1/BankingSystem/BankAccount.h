#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
	private:
		string accountNumber;
		string ownerName;
		int balance;

	public:
		BankAccount(const string& accNum, const string& name);
		void set_balance(int bal);
		int get_balance() const;
		void display_info() const;
		void deposit();
		void withdraw();
};

#endif
