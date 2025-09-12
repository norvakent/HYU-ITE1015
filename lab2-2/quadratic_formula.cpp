#include <iostream>
#include <cmath>
using namespace std;

void Quadratic_formula(float a, float b, float c, float* r1, float* r2) {
  float d = sqrt(b * b - 4 * a * c);
  if (a == 0 || d < 0) {
    *r1 = NAN;
    *r2 = NAN;
  }
  else {
    *r1 = (-b + d) / 2 / a;
    *r2 = (-b - d) / 2 / a;
  }
}

int main() {
  float a, b, c;
  float r1, r2;
  cout << "input a" << endl;
  cin >> a;
  cout << "input b" << endl;
  cin >> b;
  cout << "input c" << endl;
  cin >> c;
  cout << "equation is " << a << "x^2 + " << b << "x + " << c << endl;

  Quadratic_formula(a, b, c, &r1, &r2);

  cout << "root1 = " << r1 << endl;
  cout << "root2 = " << r2 << endl;
}