#include "Car.h"

Car::Car(const std::string &m, int capacity) : Vehicle(m), capacity(capacity) {
  if (capacity < 0)
    this->capacity = 0;
};

int Car::getWeight() { return Vehicle::getWeight() + capacity * 60; }