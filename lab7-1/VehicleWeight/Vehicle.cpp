#include "Vehicle.h"

Vehicle::Vehicle(const std::string &m) : basicWeight(1000), model(m) {};

int Vehicle::getWeight() { return basicWeight; }

void Vehicle::setModel(const std::string &m) { model = m; }

std::string Vehicle::getModel() { return model; }
