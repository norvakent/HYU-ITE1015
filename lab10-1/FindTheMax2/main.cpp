#include <iostream>
using namespace std;

class Shape {
protected:
  string m_name;

public:
  Shape(string n) : m_name(n) {}
  virtual ~Shape() {}
  virtual double get_perimeter() const = 0;
  string get_name() const { return m_name; }
};

class Circle : public Shape {
private:
  double m_radius;
  const double PI = 3.14;

public:
  Circle(string n, double r) : Shape(n), m_radius(r) {}
  double get_perimeter() const override { return 2 * PI * m_radius; }
};

class Square : public Shape {
private:
  double m_side;

public:
  Square(string n, double s) : Shape(n), m_side(s) {}
  double get_perimeter() const override { return 4 * m_side; }
};

class RegularTriangle : public Shape {
private:
  double m_side;

public:
  RegularTriangle(string n, double s) : Shape(n), m_side(s) {}
  double get_perimeter() const override { return 3 * m_side; }
};

int main() {
  const Shape *shapes[3] = {new Circle("circle", 3), new Square("square", 4),
                            new RegularTriangle("regular_triangle", 5)};

  const Shape *maxObj = nullptr;
  string maxName;
  int maxIdx = -1;
  double maxVal = -1;
  double perimeter;

  for (int i = 0; i < 3; i++) {
    maxObj = shapes[i];
    perimeter = maxObj->get_perimeter();
    if (maxVal < perimeter) {
      maxName = maxObj->get_name();
      maxIdx = i;
      maxVal = perimeter;
    }
    delete maxObj;
  }

  cout << maxName << "[" << maxIdx << "]: " << maxVal << endl;

  return 0;
}