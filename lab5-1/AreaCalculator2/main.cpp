#include <iostream>
#include "Area.h"
using namespace std;

int main(void) {
	string shape;
	int width, height;

	cout << "Choose shape (circle/triangle/rectangle): ";
	cin >> shape;
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;

	cout << "\n--- Custom shape ---" << endl;
	Area area1(shape, width, height);
	area1.calculate();
	area1.print();

	cout << "\n--- Rectangle ---" << endl;
	Area area2(width, height);
	area2.calculate();
	area2.print();

	cout << "\n--- Square ---" << endl;
	Area area3(width);
	area3.calculate();
	area3.print();

	return 0;
}
