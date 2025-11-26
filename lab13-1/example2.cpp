#include <iostream>
using namespace std;

template <typename T> class MyVector {
private:
  T *vec;
  int vecSize;
  int vecCapacity;

public:
  MyVector(const int &temp = 10) {
    vec = new T[temp];
    vecSize = 0;
    vecCapacity = temp;
  }

  ~MyVector() { delete[] vec; }

  int size() { return vecSize; }
  int capacity() { return vecCapacity; }
  void clear() { vecSize = 0; }
  bool empty() { return vecSize == 0; }

  void resize(int newSize, T val = 0) {
    while (newSize > vecCapacity) {
      vecCapacity *= 2;
    }
    T *newVec = new T[vecCapacity];
    for (int i = 0; i < newSize; i++) {
      if (i < vecSize) {
        newVec[i] = vec[i];
      } else {
        newVec[i] = val;
      }
    }
    vecSize = newSize;
    delete[] vec;
    vec = newVec;
  }

  void print() {
    cout << "Print vector info" << endl;
    cout << "    Size: " << vecSize << endl;
    cout << "    Capacity: " << vecCapacity << endl;
    cout << "    Values: ";

    for (int i = 0; i < vecSize; i++) {
      cout << vec[i] << " ";
    }
    cout << endl;
  }

  T &front() { return vec[0]; }
  T &back() { return vec[vecSize - 1]; }
  T *begin() { return vec; }
  T *end() { return vec + vecSize; }
};

int main() {
  MyVector<int> myvector(3);
  myvector.resize(3, 0);
  myvector.print();
  myvector.resize(5, 1);
  myvector.print();
  cout << myvector.size() << endl;
  cout << myvector.capacity() << endl;

  return 0;
}