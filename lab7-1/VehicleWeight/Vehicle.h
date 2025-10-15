#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
  int basicWeight;
  std::string model;

public:
  Vehicle(const std::string &m);

  int getWeight();

  void setModel(const std::string &m);

  std::string getModel();
};

#endif