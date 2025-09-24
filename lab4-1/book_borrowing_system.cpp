#include <iostream>

using namespace std;

struct Book {
  string title;
  bool isAvailable;
};

void borrowBookPointer(Book* b) {
  if (b == nullptr) {
    cout << "Book does not exist." << endl;
  } else {
    cout << (b->isAvailable ? "Available: " : "Already borrowed: ") << b->title << endl;
    b->isAvailable = false;
  }
}

void borrowBookReference(Book& b) {
  cout << (b.isAvailable ? "Available: " : "Already borrowed: ") << b.title << endl;
  b.isAvailable = false;
}

int main() {
  Book book1 = {"C++ Programming", true};
  Book book2 = {"Computer Network", true};
  Book* ptr = nullptr;

  cout << "\n=== By Pointer ===\n";
  borrowBookPointer(ptr);
  ptr = &book1;
  borrowBookPointer(ptr);
  borrowBookPointer(ptr);

  cout << "\n=== By Reference ===\n";
  borrowBookReference(book2);
  borrowBookReference(book2);

  return 0;
}