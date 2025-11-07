#include <iostream>
#include <string>
using namespace std;

#define MAXSOCKET 4

class Component {
public:
  virtual void install() = 0;
  virtual int getSpace() = 0;
  virtual string getInfo() = 0;
  virtual ~Component() {}
};

class HDD : public Component {
private:
  int space = 0;
  string info = "default";

public:
  HDD(int _space, string _info) : space(_space), info(_info) {}
  void install() override {
    cout << info << "_" << space << "GB installed" << endl;
  }
  int getSpace() { return space; }
  string getInfo() { return info; }
};
class SSD : public Component {
private:
  int space = 0;
  string info = "default";

public:
  SSD(int _space, string _info) : space(_space), info(_info) {}
  void install() override {
    cout << info << "_" << space << "GB installed" << endl;
  }
  int getSpace() { return space; }
  string getInfo() { return info; }
};

class Computer1 {
private:
  Component **componentsArray;

public:
  Computer1(Component **_comArray) : componentsArray(_comArray) {}
  void putTogether() {
    cout << "MAXSOCKET num: " << MAXSOCKET << endl;
    for (int i = 0; i < MAXSOCKET; i++) {
      componentsArray[i]->install();
    }
  }
};

int main() {
  Component *carr[MAXSOCKET] = {new HDD(512, "Sandisk"),
                                new SSD(128, "Samsung"), new SSD(256, "Hynix"),
                                new SSD(512, "Hynix")};

  Computer1 pc(carr);
  pc.putTogether();

  return 0;
}