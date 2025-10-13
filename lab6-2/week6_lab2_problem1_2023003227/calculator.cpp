#include "calculator.h"
#include <iostream>

// Initialize capacity to 2 and size to 0
Calculator::Calculator() {
  // TODO: Use "this->" to initialize capacity to 2 and size to 0
  this->capacity = 2;
  this->size = 0;

  // TODO: Allocate memory for numbers array using "this->"
  this->numbers = new ComplexNumber[capacity];
}

// Initialize capacity and size
Calculator::Calculator(int capacity) {
  // TODO: Use this-> to initialize the capacity and size; size is 0
  this->capacity = capacity;
  this->size = 0;

  // TODO: Allocate memory for numbers array using "this->"
  this->numbers = new ComplexNumber[capacity];
}

Calculator::~Calculator() {
  // TODO: Deallocate the memory used by the 'numbers' array
  delete[] this->numbers;
}

void Calculator::resize() {
  // TODO: Define new capacity as double of the current capacity
  capacity *= 2;

  ComplexNumber *new_numbers =
      new ComplexNumber[capacity]; // TODO: Create new array with new capacity

  // Call reallocate() with new array and new capacity
  this->reallocate(new_numbers, capacity);
}

void Calculator::reallocate(ComplexNumber *numbers, int capacity) {
  // Copy existing data to new array
  for (int i = 0; i < this->size; i++) {
    // TODO: use set() method to copy existing data from old numbers array to
    // the new array
    numbers[i].set(this->numbers[i].getReal(), this->numbers[i].getImaginary());
  }
  // TODO: Deallocate old array
  delete[] this->numbers;

  // TODO: Update member variables numbers and capacity using "this->"
  this->numbers = numbers;
}

void Calculator::addNumber(const ComplexNumber &num) {
  // TODO: Check if array is full, call resize() if needed
  if (this->size >= this->capacity) {
    resize();
  }

  // TODO: Use set() method to copy values of num to numbers[size], then
  // increment size
  this->numbers[size++].set(num.getReal(), num.getImaginary());
}

ComplexNumber Calculator::add(int index1, int index2) {
  // TODO: Check if both indices are valid (within bounds, 0 to size-1)
  // If invalid, return ComplexNumber(0, 0)
  if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
    return ComplexNumber(0, 0);
  }

  ComplexNumber result;

  result = numbers[index1].add(numbers[index2].getReal(),
                               numbers[index2].getImaginary());
  // TODO: Call add() of index1 object in numbers with real and
  // imaginary of index2 object

  return result;
}

ComplexNumber Calculator::sub(int index1, int index2) {
  // TODO: Check if both indices are valid (within bounds)
  // If invalid, return ComplexNumber(0, 0)
  if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
    return ComplexNumber(0, 0);
  }

  ComplexNumber result;

  result = numbers[index1].sub(numbers[index2].getReal(),
                               numbers[index2].getImaginary());
  // TODO: Call sub() of index1 object in numbers with real and
  // imaginary of index2 object
  return result;
}

ComplexNumber Calculator::mul(int index1, int index2) {
  // TODO: Check if both indices are valid (within bounds)
  // If invalid, return ComplexNumber(0, 0)
  if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
    return ComplexNumber(0, 0);
  }

  ComplexNumber result;

  result = numbers[index1].mul(numbers[index2].getReal(),
                               numbers[index2].getImaginary());
  // TODO: Call mul() of index1 object in numbers with real and
  // imaginary of index2 object

  return result;
}

ComplexNumber Calculator::div(int index1, int index2) {
  // TODO: Check if both indices are valid (within bounds)
  // If invalid, return ComplexNumber(0, 0)
  if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
    return ComplexNumber(0, 0);
  }

  ComplexNumber result;

  result = numbers[index1].div(numbers[index2].getReal(),
                               numbers[index2].getImaginary());
  // TODO: Call div() of index1 object in numbers with real and
  // imaginary of index2 object

  return result;
}

ComplexNumber Calculator::getNumber(int index) const {
  if (index < 0 || index >= size) {
    // TODO: Return a default ComplexNumber for an invalid index
    return ComplexNumber(0, 0);
  }
  // TODO: Return the ComplexNumber at the given index
  return numbers[index];
}

int Calculator::getSize() const {
  // TODO: Return the current size
  return size;
}

// Print function is provided for complex formatting
void Calculator::printAll() const {
  for (int i = 0; i < this->size; i++) {
    std::cout << "Number " << i << ": ";
    this->numbers[i].print();
  }
}