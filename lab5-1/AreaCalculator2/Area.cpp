#include "Area.h"

Area::Area(int w, int h) {
	shape = "rectangle";

	if (w <= 0 || h <= 0) {
		cout << "Invalid values, set to default 1" << endl;
	}
	width = w <= 0 ? 1 : w;
	height = h <= 0 ? 1 : h;
}

Area::Area(int size) {
	shape = "rectangle";

	if (size <= 0) {
		cout << "Invalid values, set to default 1" << endl;
		width = 1;
		height = 1;
	} else {
		width = size;
		height = size;
	}
}

Area::Area(const string& i_shape, int w, int h) {
	shape = i_shape;

	if (shape == "circle" && w != h) {
		cout << "Circle requires equal width and height, set height to width" << endl;
	}

	if (w <= 0 || h <= 0) {
		cout << "Invalid values, set to default 1" << endl;
	}

	width = w <= 0 ? 1 : w;
	if (shape == "circle") height = width;
	else if (h > 0) height = h;
	else height = 1;
}

void Area::calculate() {
	if (shape == "circle") {
		area = 3.14 * width * height;
	}
	else if (shape == "triangle") {
		area = width * height / 2.0;
	}
	else if (shape == "rectangle") {
		area = width * height;
	}
	else {
		area = 0;
		cout << "Unknown shape: " << shape << endl;
	}
}

void Area::print() const {
	cout << "shape is " << shape << " and area is " << area << endl;
}

