#include "Car.h"
#include "Truck.h"
#include "Vehicle.h"

int main() {
  Vehicle small_car("morning");
  Car sedan("k3", 5);
  Truck truck("porter", 1000);

  std::cout << "model name is " << small_car.getModel() << std::endl;
  std::cout << "basic weight is " << small_car.getWeight() << std::endl;

  std::cout << "model name is " << sedan.getModel() << std::endl;
  std::cout << "Car weight is " << sedan.getWeight() << std::endl;

  std::cout << "model name is " << truck.getModel() << std::endl;
  std::cout << "Truck weight is " << truck.getWeight() << std::endl;
}