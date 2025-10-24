#include <iostream>
using namespace std;

class Shape {
protected:
  string name;
  double area;

public:
  Shape(string n = "") : name(n), area(0.0) {};
  virtual void print_info() {
    cout << name << " (Shape): area = " << area << endl;
  }
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(string name, double radius) : Shape(name), radius(radius) {
    area = radius * radius * 3.14;
  };
  void print_info() override {
    cout << name << " (Circle): radius = " << radius << ", area = " << area
         << endl;
  }
};

class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  Rectangle(string name, double width, double height)
      : Shape(name), width(width), height(height) {
    area = width * height;
  };
  void print_info() override {
    cout << name << " (Rectangle): width = " << width << ", height = " << height
         << ", area = " << area << endl;
  }
};

int main() {
  Shape *shapes[3];

  shapes[0] = new Circle("CircleA", 10);
  shapes[1] = new Rectangle("RectB", 5, 8);
  shapes[2] = new Shape("Base");

  for (int i = 0; i < 3; ++i) {
    shapes[i]->print_info();
  }

  for (int i = 0; i < 3; ++i) {
    delete shapes[i];
  }

  return 0;
}