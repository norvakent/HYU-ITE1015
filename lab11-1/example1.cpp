#include <iostream>
using namespace std;

class Information {
private:
  int idx;
  int info;

public:
  Information() : idx(0), info(0) {}
  Information(int _idx, int _info) : idx(_idx), info(_info) {}
  void show() { cout << "Index: " << idx << ", Info: " << info << endl; }
};

class Resource {
private:
  Information *dataObj;
  int size;

public:
  Resource(int _size) : size(_size) {
    dataObj = new Information[size];
    for (int i = 0; i < size; ++i) {
      dataObj[i] = Information(i, i * 19 % 13);
    }
  }
  Resource(const Resource &other) {
    size = other.size;
    dataObj = new Information[size];
    for (int i = 0; i < size; ++i) {
      dataObj[i] = other.dataObj[i];
    }
  }
  void showAll() {
    for (int i = 0; i < size; ++i) {
      dataObj[i].show();
    }
  }
  ~Resource() { delete[] dataObj; }
};

int main() {
  Resource res1(3);
  Resource res2 = res1;

  res1.showAll();
  res2.showAll();

  return 0;
}