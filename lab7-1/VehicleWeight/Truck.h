#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
  int cargoWeight;

public:
  Truck(const std::string &m, int cargoWeight);

  int getWeight();
};

#endif