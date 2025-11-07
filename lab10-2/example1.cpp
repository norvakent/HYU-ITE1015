#include <iostream>
using namespace std;
class Device {
public:
  Device() {}
  virtual ~Device() {}
  virtual void powerOn() = 0;
  virtual string name() = 0;
};

class SmartPhone : public Device {
public:
  virtual void powerOn() override { cout << "Power on" << endl; };
  virtual string name() override { return "iphone"; }
};

int main(void) {
  SmartPhone s;
  cout << s.name() << endl;
  s.powerOn();
}