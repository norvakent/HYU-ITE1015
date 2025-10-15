#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
  int capacity;

public:
  Car(const std::string &m, int capacity);

  int getWeight();
};

#endif