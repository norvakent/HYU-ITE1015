#include "Truck.h"

Truck::Truck(const std::string &m, int cargoWeight)
    : Vehicle(m), cargoWeight(cargoWeight) {
  if (cargoWeight < 0)
    this->cargoWeight = 0;
}

int Truck::getWeight() { return Vehicle::getWeight() + cargoWeight; }