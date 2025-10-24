#include <iostream>

class Sensor {
public:
  Sensor() {}
  virtual ~Sensor() {}
  virtual double readData() = 0;
  virtual std::string getType() = 0;
};

class TemperatureSensor : public Sensor {
public:
  double readData() override { return 25.5; }
  std::string getType() override { return "Temperature"; }
};

class HumiditySensor : public Sensor {
public:
  double readData() override { return 60.0; }
  std::string getType() override { return "Humidity"; }
};

class PressureSensor : public Sensor {
public:
  double readData() override { return 1013.25; }
  std::string getType() override { return "Pressure"; }
};

int main() {
  int numSensors;
  std::cout << "Enter the number of sensors: ";
  std::cin >> numSensors;

  Sensor *sensors[3];

  for (int i = 0; i < numSensors; ++i) {
    int choice;
    std::cout << "Select sensor type for sensor " << i + 1
              << " (1: Temperature, 2: Humidity, 3: Pressure): ";
    std::cin >> choice;

    if (choice == 2) {
      sensors[i] = new HumiditySensor();
    } else if (choice == 3) {
      sensors[i] = new PressureSensor();
    } else {
      sensors[i] = new TemperatureSensor();
    }
  }

  for (int i = 0; i < numSensors; ++i) {
    std::cout << "Sensor " << i + 1 << " (" << sensors[i]->getType()
              << "): " << sensors[i]->readData() << std::endl;
    delete sensors[i];
  }
  delete[] sensors;

  return 0;
}