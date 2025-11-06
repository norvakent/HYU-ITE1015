#include <iostream>
#include <string>

using namespace std;

// Vehicle: Base class with a new baseFee member
class Vehicle {
  // TODO: Implement class Vehicle
  // Hint: check UML diagram
protected:
  string vehicleNumber;
  int entryTime;
  double baseFee = 2000;

public:
  Vehicle(string number, int time) : vehicleNumber(number), entryTime(time) {}
  string getVehicleNumber() const { return vehicleNumber; }
  int getEntryTime() const { return entryTime; }
  virtual double calculateFee(int exitTime) const { return baseFee; }
};

class Car : public Vehicle {
  // TODO: Implement class Car
  //  Hint: Uses the inherited baseFee for calculations
public:
  Car(string number, int time) : Vehicle(number, time) {}
  double calculateFee(int exitTime) const override {
    return baseFee + (exitTime - entryTime) * 1000;
  }
};

class Motorcycle : public Vehicle {
  // TODO: Implement class Car
  //  Hint: Calculates its fee as a percentage of the baseFee
public:
  Motorcycle(string number, int time) : Vehicle(number, time) {}
  double calculateFee(int exitTime) const override {
    return baseFee + (exitTime - entryTime) * 500;
  }
};

class Truck : public Vehicle {
  // TODO: Implement class Truck
  //  Hint: Uses the inherited baseFee for its complex calculation
protected:
  double tonnage;

public:
  Truck(string number, int time, double tonnage)
      : Vehicle(number, time), tonnage(tonnage) {}
  double calculateFee(int exitTime) const override {
    return baseFee + (tonnage * 500 * (exitTime - entryTime));
  }
};

class ParkingLot {
  // TODO: Implement class ParkingLot
private:
  Vehicle *vehicles[100];
  int count;
  bool isVehicleNumberExists(string &number) const {
    for (int i = 0; i < count; i++) {
      if (vehicles[i]->getVehicleNumber() == number)
        return true;
    }
    return false;
  }

public:
  ParkingLot() : count(0) {}
  bool enter(Vehicle *v) {
    string number = v->getVehicleNumber();
    if (count >= 100 || isVehicleNumberExists(number))
      return false;
    vehicles[count++] = v;
    return true;
  }
  double exit(string &number, int exitTime) {
    double fee = -1;
    if (!isVehicleNumberExists(number))
      return fee;
    bool found = false;
    for (int i = 0; i < count; i++) {
      if (vehicles[i]->getVehicleNumber() == number) {
        fee = vehicles[i]->calculateFee(exitTime);
        found = true;
        delete vehicles[i];
      }
      if (found) {
        vehicles[i] = vehicles[i + 1];
      }
    }
    count--;
    return fee;
  }
  int getVehicleCount() const { return count; }
  Vehicle *getVehicleAt(int index) const { return vehicles[index]; }
};

// --- Main Function ---

void showMenu() {
  cout << "\n===== Parking Lot Management System =====" << endl;
  cout << "1. Enter a Vehicle" << endl;
  cout << "2. Exit a Vehicle" << endl;
  cout << "3. Display Parking Status" << endl;
  cout << "4. Exit Program" << endl;
  cout << "=======================================" << endl;
  cout << ">> Select an option: ";
}

int main() {
  ParkingLot myParkingLot;
  bool running = true;

  while (running) {
    showMenu();
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: { // Enter a Vehicle
      cout << ">> Select vehicle type to enter (1: Car, 2: Motorcycle, 3: "
              "Truck): ";
      int type;
      cin >> type;

      if (type < 1 || type > 3) {
        cout << ">> Invalid vehicle type." << endl;
        break;
      }

      cout << ">> Enter vehicle number: ";
      string number;
      cin >> number;

      cout << ">> Enter entry time (0-24): ";
      int time;
      cin >> time;

      Vehicle *newVehicle = nullptr;
      if (type == 1) {
        newVehicle = new Car(number, time);
      } else if (type == 2) {
        newVehicle = new Motorcycle(number, time);
      } else if (type == 3) {
        cout << ">> Enter truck's tonnage: ";
        double tonnage;
        cin >> tonnage;
        newVehicle = new Truck(number, time, tonnage);
      }

      if (myParkingLot.enter(newVehicle)) {
        cout << ">> Vehicle " << number << " has entered." << endl;
      } else {
        cout << ">> Parking lot is full." << endl;
      }
      break;
    }
    case 2: { // Exit a Vehicle
      cout << ">> Enter vehicle number to exit: ";
      string number;
      cin >> number;

      cout << ">> Enter current time (0-24): ";
      int exitTime;
      cin >> exitTime;

      double fee = myParkingLot.exit(number, exitTime);

      if (fee >= 0) {
        cout << ">> Vehicle " << number << " exited. Total fee: " << fee
             << endl;
      } else {
        cout << ">> Vehicle " << number << " not found." << endl;
      }
      break;
    }
    case 3: { // Display Parking Status
      cout << "\n--- Current Parking Status ---" << endl;
      int vehicleCount = myParkingLot.getVehicleCount();
      if (vehicleCount == 0) {
        cout << "No vehicles are parked." << endl;
      } else {
        cout << "Total " << vehicleCount << " vehicles are parked." << endl;
        for (int i = 0; i < vehicleCount; ++i) {
          const Vehicle *v = myParkingLot.getVehicleAt(i);
          if (v) {
            cout << "  - Vehicle Number: " << v->getVehicleNumber()
                 << ", Entry Time: " << v->getEntryTime() << ":00" << endl;
          }
        }
      }
      cout << "----------------------------" << endl;
      break;
    }
    case 4: { // Exit Program
      running = false;
      cout << ">> Exiting program." << endl;
      break;
    }
    default: {
      cout << ">> Please enter a number between 1 and 4." << endl;
      break;
    }
    }
  }
  return 0;
}