#include <iostream>

void find(int *arr, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      std::cout << i << std::endl;
      return;
    }
  }
  std::cout << -1 << std::endl;
}

void append(int *&arr, int &size, int element) {
  int* newArr = new int[++size];
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      newArr[i] = element;
      break;
    }
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void insert(int *&arr, int &size, int index, int element) {
  if (index < 0 || index > size) {
    std::cout << "IndexError\n";
    return;
  }
  int *newArr = new int[size + 1];
  for (int i = 0; i < index; ++i) {
    newArr[i] = arr[i];
  }
  for (int i = index; i < size + 1; ++i) {
    newArr[i] = arr[i - 1];
  }
  delete[] arr;
  arr = newArr;
  arr[index] = element;
  ++size;
}

void remove(int *&arr, int &size, int index) {
  if (index < 0 || index > size) {
    std::cout << "IndexError\n";
    return;
  }
  int *newArr = new int[--size];
  for (int i = 0; i < index; i++) {
    newArr[i] = arr[i];
  }
  for (int i = index; i < size; i++) {
    newArr[i] = arr[i + 1];
  }
  delete[] arr;
  arr = newArr;
}

void pop(int *&arr, int &size) {
  if (size == 0) {
    std::cout << "Empty\n";
    return;
  }
  int* newArr = new int[--size];
  for (int i = 0; i < size; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void printArray(int *arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i];
    if (i < size - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

int main() {
  int total_tests = 10;
  for (int t = 1; t <= total_tests; ++t) {
    int size = 0;
    int *arr = new int[size];
    int Q;
    std::cin >> Q;

    while (Q--) {
      std::string cmd;
      std::cin >> cmd;

      if (cmd == "APPEND") {
        int x;
        std::cin >> x;
        append(arr, size, x);
      } else if (cmd == "INSERT") {
        int i, x;
        std::cin >> i >> x;
        insert(arr, size, i, x);
      } else if (cmd == "REMOVE") {
        int i;
        std::cin >> i;
        remove(arr, size, i);
      } else if (cmd == "POP") {
        pop(arr, size);
      } else if (cmd == "PRINT") {
        printArray(arr, size);
      } else if (cmd == "FIND") {
        int x;
        std::cin >> x;
        find(arr, size, x);
      }
    }
    delete[] arr;
  }
  return 0;
}