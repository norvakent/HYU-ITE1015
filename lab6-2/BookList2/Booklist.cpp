#include "Booklist.h"
#include <iostream>
using namespace std;

Booklist::Booklist() {
  for (int i = 0; i < 3; i++) {
    books[i] = Book();
  }
  num = 0;
}

void Booklist::add(const Book &book, int index) {
  cout << book.get_name() << " added\n";
  books[index] = book;
}

void Booklist::show() const {
  cout << "Index\tName\tAuthor\tYear\n";
  for (int i = 0; i < 3; i++) {
    cout << i;
    books[i].show();
  }
}

void Booklist::remove(const string &name) {
  for (int i = 0; i < 3; i++) {
    if (books[i].get_name() == name) {
      num--;
      books[i] = Book();
      cout << name << " is removed\n";
      return;
    }
  }
  cout << name << " is not existing\n";
}

bool Booklist::checkAddInput(string &name, string &author, int &year, int &index) {
  cout << "Name: ";
  cin >> name;
  cout << "Author: ";
  cin >> author;
  cout << "Year: ";
  cin >> year;
  cout << "Index: ";
  cin >> index;

  if (num == 3) {
    cout << "NO more empty space\n";
    return false;
  }
  if (books[index].get_name() != "-----") {
    cout << index << " index already has book\n";
    return false;
  }
  for (int i = 0; i < 3; i++) {
    if (books[i].get_name() == name) {
      cout << name << " is already existing\n";
      return false;
    }
  }
  num++;
  return true;
}