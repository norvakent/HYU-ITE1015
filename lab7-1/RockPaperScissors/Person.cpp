#include "Person.h"

void Person::setName(const string &n) { name = n; }

std::string Person::show_shape() {
  switch (shape) {
  case 1:
    return "Rock";
  case 2:
    return "Paper";
  case 3:
    return "Scissors";
  }
  return "";
}

int Person::get_shape() { return shape; }

int Person::get_winCount() { return win_count; }

std::string Person::get_name() { return name; }

void Person::incrementWinCount() { win_count++; }

void Person::chooseShape() {
  std::cout << "Base Person cannot choose a shape." << std::endl;
}
