#include <iostream>

using namespace std;

class Circle {
private:
  string name;
  double radius;

public:
  Circle() {};
  Circle(string n, double r) : name(n), radius(r) {};
  string get_name() { return name; }
  double get_area() { return radius * radius * 3.14; }
};

int main() {
  int array_length = 0;
  cout << "Set length of object array: ";
  cin >> array_length;
  cout << endl;

  Circle *circle_array = new Circle[array_length];
  int radius = 0;
  std::string name;
  for (int i = 0; i < array_length; ++i) {
    cout << i << "_idx Set name of radius: ";
    cin >> name;
    cout << i << "_idx Set radius of radius: ";
    cin >> radius;
    circle_array[i] = Circle(name, radius);
  }

  cout << "====================" << endl;

  Circle *p = circle_array;
  for (int i = 0; i < array_length; ++i) {
    cout << "Circle's name is " << p->get_name() << endl;
    cout << "Area: " << p->get_area() << endl << endl;
    p++;
  }
  delete[] circle_array;
}