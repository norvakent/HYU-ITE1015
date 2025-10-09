#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"

class Booklist
{
  private:
    Book books[3];
    int num;

  public:
    Booklist();
    void add(const Book &book, int index);
    void show() const;
    void remove(const string &name);
    bool checkAddInput(string &name, string &author, int &year, int &index);
};

#endif