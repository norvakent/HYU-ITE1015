#include <iostream>
#include <string>
using namespace std;

// TODO
template <typename T> void Sort(T *arr, int n) {
  T min;
  int idx;
  for (int i = 0; i < n - 1; i++) {
    idx = i;
    min = arr[i];
    for (int j = i; j < n; j++) {
      if (arr[j] < min) {
        min = arr[j];
        idx = j;
      }
    }
    arr[idx] = arr[i];
    arr[i] = min;

    cout << "Iteration " << i + 1 << ": ";
    for (int q = 0; q < n; q++) {
      cout << arr[q] << " ";
    }
    cout << endl;
  }
}

// TODO
template <> void Sort(string *arr, int n) {
  string min;
  int idx;
  for (int i = 0; i < n - 1; i++) {
    idx = i;
    min = arr[i];
    for (int j = i; j < n; j++) {
      if (arr[j].length() < min.length()) {
        min = arr[j];
        idx = j;
      }
    }
    arr[idx] = arr[i];
    arr[i] = min;

    cout << "Iteration " << i + 1 << ": ";
    for (int q = 0; q < n; q++) {
      cout << '"' << arr[q] << '"' << " ";
    }
    cout << endl;
  }
}

int main() {

  int arrayLength = 10;

  int arrInt[] = {1, 5, 9, 4, 3, 8, 8, 2, 5, 7};
  Sort(arrInt, arrayLength);
  cout << "\n\n";

  char arrchar[] = {'g', 'e', 'q', 'a', 'a', 'p', 'w', 'z', 'r', 'l'};
  Sort(arrchar, arrayLength);
  cout << "\n\n";

  string arrString[] = {"kiwi", "apple", "blueberry", "banana", "grape"};
  int stringLength = 5;
  Sort(arrString, stringLength);
  cout << "\n\n";

  return 0;
}