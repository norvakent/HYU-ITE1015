#include <iostream>
using namespace std;

template <typename T> class Base {
protected:
  T count;

public:
  Base(T v) : count(v) {}
  void showCount() const { cout << "count: " << count << endl; }
};

template <typename T> class Derived : public Base<T> {
public:
  Derived(T v) : Base<T>(v) {}
  void doubleCount() { this->count *= 2; }
  template <typename U> U multiplyFactor(U factor) {
    return this->count * factor;
  }
};

int main() {
  Derived<int> intDerived(1);
  intDerived.showCount();
  intDerived.doubleCount();
  intDerived.showCount();

  cout << intDerived.multiplyFactor<double>(3.14) << endl;

  Derived<double> doubleDerived(1.23);
  doubleDerived.showCount();
  doubleDerived.doubleCount();
  doubleDerived.showCount();

  cout << intDerived.multiplyFactor<int>(3) << endl;

  return 0;
}