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
  Complex operator*(const Complex c) {
    return Complex(real * c.real - imag * c.imag,
                   real * c.imag + imag * c.real);
  }
  Complex operator/(const Complex c) {
    double divisor = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / divisor,
                   (imag * c.real - real * c.imag) / divisor);
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

  Complex div = aa / bb;
  cout << "Mul: ";
  (aa * bb).print();
  cout << "Div: ";
  div.print();

  return 0;
}