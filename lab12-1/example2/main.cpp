#include <iostream>
using namespace std;

template <typename T> T findMax(T *arr, int size) {
  T max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

template <typename T> int findElement(T *arr, int size, T value) {
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] == value)
      return i;
  }
  return -1;
}

int main() {
  int intArr[] = {64, 34, 25, 12, 22, 11, 90};
  double doubleArr[] = {6.4, 3.4, 2.5, 1.2, 2.2, 1.1, 9.0};
  int Size = 7;

  cout << "Integer type array\n";
  int maxInt = findMax(intArr, Size);
  cout << "The index of the maximum value: "
       << findElement(intArr, Size, maxInt) << endl;

  cout << "\nDouble type array\n";
  cout << "The index of 2.2: " << findElement(doubleArr, Size, 2.2) << endl;
  return 0;
}