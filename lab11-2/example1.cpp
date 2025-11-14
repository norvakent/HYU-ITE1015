#include <iostream>
using namespace std;

class Complex {
private:
  double real, imag;

public:
  Complex(double r, double i) : real(r), imag(i) {}
  Complex operator+(const Complex c) {
    return Complex(real + c.real, imag + c.imag);
  }
  Complex operator-(const Complex c) {
    return Complex(real - c.real, imag - c.imag);
  }
  void print() { cout << "(" << real << ", " << imag << ")" << endl; }
};

int main() {
  Complex aa(3, 4), bb(1, 2);
  Complex diff = aa - bb;

  cout << "Sum: ";
  (aa + bb).print();
  cout << "Difference: ";
  diff.print();

  return 0;
}