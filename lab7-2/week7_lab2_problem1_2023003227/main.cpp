#include <iostream>

#include "FeederPipeline.h"

int main() {
  std::cout << "\n=== CorrectFeeder life cycle ===\n";
  {
    CorrectFeeder good(1);
  }

  std::cout << "\n=== IncorrectFeeder life cycle ===\n";
  {
    IncorrectFeeder bad(2);
  }

  return 0;
}