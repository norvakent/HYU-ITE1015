#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

class VendingMachine {
	private:
		int balance;
		int priceA, priceB, priceC;
		int stockA, stockB, stockC;

		bool isValidCode(char code) const;
		int getPrice(char code) const;
		int getStock(char code) const;
		void setPriceInternal(char code, int newPrice);
		void addStockInternal(char code, int quantity);
		void printChange(int amount) const;

	public:
		VendingMachine();

		void insert(int amount);
		bool select(char code);
		void refund();
		void restock(char code, int quantity);
		void setPrice(char code, int newPrice);
		void status() const;
};

#endif
