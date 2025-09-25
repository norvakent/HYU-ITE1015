#include <iostream>
#include <string>
using namespace std;

void get_number(int index, float &num) {
	cout << "Number" << index << "   : ";
	cin >> num;
}

void get_operator(char &oper) {
	cout << "Operation : ";
	cin >> oper;
}

void show_error() { cout << "Error\n" << endl; }

void show_result(float a, float b, char oper, float result) {
	cout << a << " " << oper << " " << b << " = " << result << "\n" << endl;
}
