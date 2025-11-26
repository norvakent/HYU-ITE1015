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

  void push_back(const T &element) {
    if (vecSize >= vecCapacity) {
      vecCapacity *= 2;
      T *newVec = new T[vecCapacity];
      for (int i = 0; i < vecSize; i++) {
        newVec[i] = vec[i];
      }
      delete[] vec;
      vec = newVec;
    }
    vec[vecSize++] = element;
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
  myvector.push_back(1);
  myvector.push_back(2);
  myvector.push_back(3);
  myvector.print();
  myvector.push_back(4);
  myvector.print();

  return 0;
}