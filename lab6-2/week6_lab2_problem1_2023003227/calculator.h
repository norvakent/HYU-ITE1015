#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "complex_number.h"

class Calculator {
private:
    ComplexNumber* numbers;
    int size;
    int capacity;
    
    void resize();
    void reallocate(ComplexNumber* numbers, int capacity);

public:
    // Default constructor
    Calculator();

    // Constructor: Initialize calculator with capacity
    Calculator(int capacity);

    // Destructor
    ~Calculator();
    
    // Add a complex number
    void addNumber(const ComplexNumber& num);

    // Add two complex numbers and return result
    ComplexNumber add(int index1, int index2);

    // Subtract two complex numbers and return result
    ComplexNumber sub(int index1, int index2);

    // Multiply two complex numbers and return result
    ComplexNumber mul(int index1, int index2);

    // Divide two complex numbers and return result
    ComplexNumber div(int index1, int index2);
    
    // Get complex number at index
    ComplexNumber getNumber(int index) const;

    // Get number of complex numbers
    int getSize() const;

    // Display all complex numbers
    void printAll() const;
};

#endif