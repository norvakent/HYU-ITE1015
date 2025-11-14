#include <iostream>
using namespace std;

// TODO
class Complex {
private:
  double real, imag;

public:
  Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
  Complex operator+(const Complex &c) const {
    return Complex(real + c.real, imag + c.imag);
  }
  Complex operator-(const Complex &c) const {
    return Complex(real - c.real, imag - c.imag);
  }
  Complex operator*(const Complex &c) const {
    return Complex(real * c.real - imag * c.imag,
                   real * c.imag + imag * c.real);
  }
  Complex operator/(const Complex &c) const {
    double divisor = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / divisor,
                   (imag * c.real - real * c.imag) / divisor);
  }
  void print() const { cout << "(" << real << ", " << imag << ")"; }
};

class ComplexMatrix {
private:
  Complex m11, m12, m21, m22;

public:
  ComplexMatrix(Complex m11, Complex m12, Complex m21, Complex m22)
      : m11(m11), m12(m12), m21(m21), m22(m22) {}

  // TODO
  ComplexMatrix operator+(const ComplexMatrix &m) const {
    return ComplexMatrix(m11 + m.m11, m12 + m.m12, m21 + m.m21, m22 + m.m22);
  }

  // TODO
  ComplexMatrix operator-(const ComplexMatrix &m) const {
    return ComplexMatrix(m11 - m.m11, m12 - m.m12, m21 - m.m21, m22 - m.m22);
  }
  // TODO
  ComplexMatrix operator*(const ComplexMatrix &m) const {
    return ComplexMatrix(m11 * m.m11 + m12 * m.m21, m11 * m.m12 + m12 * m.m22,
                         m21 * m.m11 + m22 * m.m21, m21 * m.m12 + m22 * m.m22);
  }
  // TODO
  ComplexMatrix operator/(const ComplexMatrix &m) const {
    Complex det = m.determinant();
    return ComplexMatrix(
        (m11 * m.m22 - m12 * m.m21) / det, (m12 * m.m11 - m11 * m.m12) / det,
        (m21 * m.m22 - m22 * m.m21) / det, (m22 * m.m11 - m21 * m.m12) / det);
  }

  // TODO
  Complex determinant() const { return m11 * m22 - m21 * m12; }

  void print() const {
    std::cout << "(";
    m11.print();
    std::cout << " ";
    m12.print();
    std::cout << ")\n";
    std::cout << "(";
    m21.print();
    std::cout << " ";
    m22.print();
    std::cout << ")\n";
  }
};

int main() {
  ComplexMatrix A(Complex(1, 2), Complex(3, 4), Complex(5, 6), Complex(7, 8));
  ComplexMatrix B(Complex(8, 7), Complex(6, 5), Complex(4, 3), Complex(2, 1));

  // A + B
  cout << "A + B =" << endl;
  (A + B).print();
  cout << "\n\n";

  // A - B
  cout << "A - B =" << endl;
  (A - B).print();
  cout << "\n\n";

  // A * B
  cout << "A * B =" << endl;
  (A * B).print();
  cout << "\n\n";

  // determinant(A)
  cout << "determinant(A) =" << endl;
  A.determinant().print();
  cout << "\n\n";

  // A / B
  cout << "A / B =" << endl;
  (A / B).print();
  cout << "\n\n";

  return 0;
}