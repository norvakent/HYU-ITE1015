#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    ComplexNumber();

    // Constructor: Initialize with real part
    ComplexNumber(double real);

    // Constructor: Initialize with real and imaginary parts
    ComplexNumber(double real, double imaginary);

    // Get the real part
    double getReal() const;

    // Get the imaginary part
    double getImaginary() const;

    // Set both real and imaginary parts
    void set(double real, double imaginary);

    // Display the complex number
    void print() const;

    // Add this complex number with another complex number
    ComplexNumber add(double real, double imaginary) const;

    // Subtract another complex number from this complex number
    ComplexNumber sub(double real, double imaginary) const;

    // Multiply this complex number with another complex number
    ComplexNumber mul(double real, double imaginary) const;

    // Divide this complex number by another complex number
    ComplexNumber div(double real, double imaginary) const;
};

#endif

