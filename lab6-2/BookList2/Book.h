#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
  private:
    string name, author;
    int year;

  public:
    Book();
    Book(const string& name, const string& author, int year);
    string get_name() const;
    void show() const;
};

#endif