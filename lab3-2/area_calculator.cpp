#include <iostream>

using namespace std;

float getArea(float radius) {
  return 3.14159 * radius * radius;
}

float getArea(float width, float height) {
  return width * height;
}

float getArea(float base, float height, bool isTriangle) {
  return (isTriangle ? 0.5 : 1) * base * height;
}

int main() {
  cout << "=== Shape Area Calculator ===" << endl;

  float circleArea = getArea(5);
  float rectArea = getArea(4, 6);
  float triangleArea = getArea(8, 3, true);

  cout << "Circle (radius=5): " << circleArea << endl;
  cout << "Rectangle (4x6): " << rectArea << endl;
  cout << "Triangle (base=8, height=3): " << triangleArea << endl;

  return 0;
}