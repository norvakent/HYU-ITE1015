#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string name;

protected:
  int win_count;
  int shape;

  void setName(const string &n);

public:
  string show_shape();
  int get_shape();
  int get_winCount();
  void incrementWinCount();
  void chooseShape();
  string get_name();
};

#endif