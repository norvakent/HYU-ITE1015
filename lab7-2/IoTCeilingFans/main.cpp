#include <iostream>
#include <string>

class NetworkDevice {
private:
  std::string ip;

public:
  NetworkDevice(std::string addr) : ip(addr) {
    std::cout << "[Network] " << ip << " ready\n";
  };

  void ping() { std::cout << "Ping " << ip << std::endl; }
};

class TemperatureSensor {
private:
  int temp;

public:
  TemperatureSensor(int t) : temp(t) {};
  int read() { return temp; }
  void setTemperature(int t) { temp = t; }
};

class SwitchActuator {
private:
  bool state;

public:
  SwitchActuator() {};
  void toggle() {
    state = !state;
    std::cout << "[Actuator] " << (state ? "ON" : "OFF") << std::endl;
  }
  bool isOn() { return state; }
};

class SmartFan : public NetworkDevice,
                 public TemperatureSensor,
                 public SwitchActuator {
public:
  SmartFan(std::string ipAddr, int initialTemp)
      : NetworkDevice(ipAddr), TemperatureSensor(initialTemp),
        SwitchActuator() {};

  void autoControl() {
    if ((read() >= 30 && !isOn()) || (read() < 30 && isOn()))
      toggle();
  }
};

int main() {
  SmartFan sf("192.168.0.10", 32);

  sf.ping();

  sf.autoControl();

  sf.setTemperature(25);
  sf.autoControl();

  return 0;
}