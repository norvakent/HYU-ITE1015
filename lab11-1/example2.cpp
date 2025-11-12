#include <iostream>
using namespace std;

class Shape {
private:
  int width;
  int height;
  string name;

public:
  Shape(int w, int h, string n) : width(w), height(h), name(n) {}
  friend int compareArea(Shape &rect, Shape &tri);
  virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
  Rectangle(int w, int h) : Shape(w, h, "Rectangle") {}
};

class Triangle : public Shape {
public:
  Triangle(int w, int h) : Shape(w, h, "Triangle ") {}
};

int compareArea(Shape &rect, Shape &tri) {
  double rectArea = rect.width * rect.height;
  double triArea = tri.width * tri.height / 2;
  if (rectArea > triArea) {
    return -1;
  } else if (rectArea < triArea) {
    return 1;
  } else {
    return 0;
  }
}

void visualizeAnswer(int answer) {
  if (answer == -1) {
    cout << "Rectangle > Triangle" << endl;
  } else if (answer == 1) {
    cout << "Rectangle < Triangle" << endl;
  } else if (answer == 0) {
    cout << "Rectangle == Triangle" << endl;
  }
}

int main() {
  Rectangle rect1(4, 3);
  Triangle tri1(4, 3);
  visualizeAnswer(compareArea(rect1, tri1));

  Rectangle rect2(4, 3);
  Triangle tri2(4, 12);
  visualizeAnswer(compareArea(rect2, tri2));

  Rectangle rect3(4, 3);
  Triangle tri3(4, 6);
  visualizeAnswer(compareArea(rect3, tri3));

  return 0;
}