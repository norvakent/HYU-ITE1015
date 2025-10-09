#include <iostream>
#include "Booklist.h"
using namespace std;

void displayMenu() {
  cout << "1. Add book" << endl;
  cout << "2. Remove book" << endl;
  cout << "3. Show books" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter your choice: ";
}

int getMenuChoice() {
  int choice;

  while (true) {
    displayMenu();
    cin >> choice;

    if (choice < 1 || choice > 4) {
      cout << "Invalid choice. Please enter 1-4." << endl << endl;
      continue;
    }

    return choice;
  }
}

int main() {
  Booklist booklist;
  string name, author;
  int year, index;

  while (true) {
    int choice = getMenuChoice();

    switch (choice) {
      case 1:
        if (booklist.checkAddInput(name, author, year, index)) {
          booklist.add(Book(name, author, year), index);
        }
        break;
      case 2:
        cout << "Name: ";
        cin >> name;
        booklist.remove(name);
        break;
      case 3:
        booklist.show();
        break;
      case 4:
        cout << "Good bye" << endl;
        return 0;
    }
    cout << "\n";
  }
  return 0;
}