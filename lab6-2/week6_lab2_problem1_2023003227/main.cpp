#include "complex_number.h"
#include "calculator.h"
#include <iostream>
using namespace std;

// Display the main menu options
void showMenu() {
    cout << "\n=== Complex Number Calculator ===" << endl;
    cout << "1. Add complex number" << endl;
    cout << "2. Display all complex numbers" << endl;
    cout << "3. Perform arithmetic operations" << endl;
    cout << "4. Exit program" << endl;
    cout << "Choose option: ";
}

// Display arithmetic operations menu
void showArithmeticMenu() {
    cout << "\n=== Arithmetic Operations ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Choose operation: ";
}

// Get complex number information from user input
bool getComplexInfo(double& real, double& imaginary) {
    cout << "Enter real part: ";
    if (!(cin >> real)) {
        return false;
    }
    
    cout << "Enter imaginary part: ";
    if (!(cin >> imaginary)) {
        return false;
    }
    
    return true;
}

// Handle adding a complex number
void addComplexNumber(Calculator& calc) {
    double real, imaginary;
    
    if (!getComplexInfo(real, imaginary)) {
        cout << "Invalid input." << endl;
        return;
    }
    
    ComplexNumber newNumber(real, imaginary);
    calc.addNumber(newNumber);
    cout << "Complex number added." << endl;
}

// Get two indices for arithmetic operations
bool getTwoIndices(int& index1, int& index2, int maxSize) {
    if (maxSize < 2) {
        cout << "Need at least 2 complex numbers for arithmetic operations." << endl;
        return false;
    }
    
    cout << "Available complex numbers (0 to " << (maxSize - 1) << "):" << endl;
    cout << "Enter first index: ";
    if (!(cin >> index1)) {
        return false;
    }
    
    cout << "Enter second index: ";
    if (!(cin >> index2)) {
        return false;
    }
    
    if (index1 < 0 || index1 >= maxSize || index2 < 0 || index2 >= maxSize) {
        cout << "Invalid indices. Please enter indices between 0 and " << (maxSize - 1) << "." << endl;
        return false;
    }
    
    return true;
}

// Handle arithmetic operations
void performArithmetic(Calculator& calc) {
    if (calc.getSize() < 2) {
        cout << "Need at least 2 complex numbers for arithmetic operations." << endl;
        return;
    }
    
    showArithmeticMenu();
    int operation;
    if (!(cin >> operation)) {
        cout << "Invalid input." << endl;
        return;
    }
    
    int index1, index2;
    if (!getTwoIndices(index1, index2, calc.getSize())) {
        return;
    }
    
    ComplexNumber result;
    cout << "\nOperation: ";
    calc.getNumber(index1).print();
    
    switch (operation) {
        case 1:
            cout << " + ";
            calc.getNumber(index2).print();
            cout << " = ";
            result = calc.add(index1, index2);
            result.print();
            break;
        case 2:
            cout << " - ";
            calc.getNumber(index2).print();
            cout << " = ";
            result = calc.sub(index1, index2);
            result.print();
            break;
        case 3:
            cout << " * ";
            calc.getNumber(index2).print();
            cout << " = ";
            result = calc.mul(index1, index2);
            result.print();
            break;
        case 4:
            cout << " / ";
            calc.getNumber(index2).print();
            cout << " = ";
            result = calc.div(index1, index2);
            result.print();
            break;
        default:
            cout << "Invalid operation choice." << endl;
            return;
    }
    cout << endl;
}

int main() {
    Calculator calc;
    int choice;
    
    
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addComplexNumber(calc);
                break;
            case 2:
                if (calc.getSize() == 0) {
                    cout << "No complex numbers found. Please add some first." << endl;
                } else {
                    cout << "\n=== All Complex Numbers ===" << endl;
                    calc.printAll();
                }
                break;
            case 3:
                performArithmetic(calc);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please select 1-4." << endl;
        }
    }
    
    return 0;
}