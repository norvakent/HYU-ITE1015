#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
  name = "-----"; author = "-----"; year = 0;
}

Book::Book(const string& name, const string& author, int year)
: name(name), author(author), year(year) {}

string Book::get_name() const {
  return name;
}

void Book::show() const {
  if (name == "-----") {
    cout << "\t-----\t-----\t----" << endl;
  } else {
    cout << "\t" << name << "\t" << author << "\t";
    cout << year << endl;
  }
}