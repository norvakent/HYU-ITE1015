#ifndef BASICCARD_H
#define BASICCARD_H

#include <iostream>

class BasicCard {
protected:
  std::string owner_;

public:
  BasicCard(std::string owner) : owner_(owner) {};
  void showOwner() { std::cout << "Owner: " << owner_ << std::endl; }
};

#endif