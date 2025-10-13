#include "complex_number.h"
#include <iostream>

// Initialize real and imaginary to 0
ComplexNumber::ComplexNumber() {
  // TODO: Use this-> to assign 0 to both real and imaginary member variables
  this->real = 0;
  this->imaginary = 0;
}

// Initialize real to parameter value and imaginary to 0
ComplexNumber::ComplexNumber(double real) {
  // TODO: Use this-> to assign parameter to member variables
  this->real = real;
  this->imaginary = 0;
}

// Initialize real and imaginary to parameter values
ComplexNumber::ComplexNumber(double real, double imaginary) {
  // TODO: Use this-> to assign parameters to member variables
  this->real = real;
  this->imaginary = imaginary;
}

double ComplexNumber::getReal() const {
  // TODO: Return the real part
  return real;
}

double ComplexNumber::getImaginary() const {
  // TODO: Return the imaginary part
  return imaginary;
}

void ComplexNumber::set(double real, double imaginary) {
  // TODO: Use this-> to assign parameters to member variables
  this->real = real;
  this->imaginary = imaginary;
}

void ComplexNumber::print() const {
  std::cout << this->real;
  if (this->imaginary >= 0)
    std::cout << "+";
  std::cout << this->imaginary << "i" << std::endl;
}

ComplexNumber ComplexNumber::add(double real, double imaginary) const {
  double r = this->real + real; // TODO: calculate result of real part
  double i =
      this->imaginary + imaginary; // TODO: calculate result of imaginary part

  // TODO: return ComplexNumber object initialized with r and i
  return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::sub(double real, double imaginary) const {
  double r = this->real - real; // TODO: calculate result of real part
  double i =
      this->imaginary - imaginary; // TODO: calculate result of imaginary part

  // TODO: return ComplexNumber object initialized with r and i
  return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::mul(double real, double imaginary) const {
  double r = this->real * real -
             this->imaginary * imaginary; // TODO: calculate result of real part
  double i = this->real * imaginary +
             this->imaginary * real; // TODO: calculate result of imaginary part

  // TODO: return ComplexNumber object initialized with r and i
  return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::div(double real, double imaginary) const {
  double denominator =
      real * real + imaginary * imaginary; // TODO: calculate denominator

  // TODO: if denominator is 0, return ComplexNumber(0, 0)

  double r = (this->real * real + this->imaginary * imaginary) /
             denominator; // TODO: calculate result of real part
  double i = (this->imaginary * real - this->real * imaginary) /
             denominator; // TODO: calculate result of imaginary part

  // TODO: return ComplexNumber object initialized with r and i
  return ComplexNumber(r, i);
}
