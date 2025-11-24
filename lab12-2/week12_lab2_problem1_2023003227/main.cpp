#include <iostream>
#include <string>
using namespace std;

template <typename T> class PyList {
private:
  T *data;
  int len;

public:
  PyList() : data(nullptr), len(0) {}

  ~PyList() { delete[] data; }

  PyList(const PyList &other) : len(other.len) {
    data = new T[len];
    for (int i = 0; i < len; ++i) {
      data[i] = other.data[i];
    }
  }

  PyList &operator=(const PyList &other) {
    if (this == &other) {
      return *this;
    }

    delete[] data;

    len = other.len;
    data = new T[len];
    for (int i = 0; i < len; ++i) {
      data[i] = other.data[i];
    }
    return *this;
  }

  // TODO 1. Implement append
  void append(T e) {
    T *newData = new T[++len];
    int i;
    for (i = 0; i < len - 1; i++) {
      newData[i] = data[i];
    }
    newData[i] = e;
    data = newData;
  }

  // TODO 2. Implement insert
  void insert(int p, T e) {
    if (p < 0 || p >= len)
      return;
    T *newData = new T[++len];
    bool inserted = false;
    for (int i = 0; i < len; i++) {
      if (i == p) {
        newData[i] = e;
        inserted = true;
      } else {
        newData[i] = data[i + (inserted ? -1 : 0)];
      }
    }
    data = newData;
  }

  // TODO 3. Implement remove
  void remove(int p) {
    if (p < 0 || p >= len)
      return;
    T *newData = new T[len - 1];
    bool removed = false;
    for (int i = 0; i < len; i++) {
      if (i == p) {
        removed = true;
      } else {
        newData[i + (removed ? -1 : 0)] = data[i];
      }
    }
    len--;
    data = newData;
  }

  // TODO 4. Implement pop
  T pop() {
    T *newData = new T[--len];
    int i;
    for (i = 0; i < len; i++) {
      newData[i] = data[i];
    }
    T ret = data[i];
    data = newData;
    return ret;
  }

  // TODO 5. Implement size
  int size() const { return len; }

  void print() const {
    cout << "[";
    for (int i = 0; i < len; ++i) {
      cout << data[i];
      if (i < len - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }
};

int main() {
  cout << "--- PyList<int> Test ---" << endl;
  PyList<int> nums;
  nums.append(3);
  nums.append(5);
  nums.append(2);
  nums.print();
  cout << "array length : " << nums.size() << "\n\n";

  nums.insert(1, 4);
  nums.print();
  cout << "array length : " << nums.size() << "\n\n";

  nums.remove(1);
  nums.print();
  cout << "array length : " << nums.size() << "\n\n";

  cout << "pop : " << nums.pop() << endl;
  nums.print();
  cout << "array length : " << nums.size() << "\n\n";

  cout << "--- PyList<string> Test ---" << endl;
  PyList<string> words;
  words.append("Hello");
  words.append("C++");
  words.append("Templates");
  words.print();
  cout << "array length : " << words.size() << "\n\n";

  words.insert(1, "World");
  words.print();
  cout << "array length : " << words.size() << "\n\n";

  words.remove(2);
  words.print();
  cout << "array length : " << words.size() << "\n\n";

  cout << "pop : " << words.pop() << endl;
  words.print();
  cout << "array length : " << words.size() << "\n\n";

  cout << "--- Copy Test ---" << endl;
  PyList<string> words_copy = words;
  words_copy.append("Test");

  cout << "Original: ";
  words.print();
  cout << "Copy: ";
  words_copy.print();

  return 0;
}