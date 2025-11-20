#include <iostream>
#include <string>

using namespace std;

// TODO 1. Implement toLower
string toLower(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += 32;
  }
  return s;
}

// TODO 2. Implement isEqual
// Generic helper
template <typename T> bool isEqual(T a, T b) { return a == b; }
// string specific overload
template <> bool isEqual(string a, string b) {
  return toLower(a) == toLower(b);
}

// TODO 3. Implement isGreator
// Generic helper
template <typename T> bool isGreater(T a, T b) { return a > b; }
// string specific overload
template <> bool isGreater(string a, string b) {
  return toLower(a) > toLower(b);
}

template <typename T> void printArray(T *arr, int size, string title) {
  cout << title << endl;
  if (size == 0) {
    cout << "(Empty)" << endl;
    return;
  }
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// TODO 4. Implement sort
template <typename T> void sort(T *arr, int size) {
  T min;
  int idx;
  for (int i = 0; i < size - 1; i++) {
    idx = i;
    min = arr[i];
    for (int j = i; j < size; j++) {
      if (isGreater(min, arr[j])) {
        min = arr[j];
        idx = j;
      }
    }
    arr[idx] = arr[i];
    arr[i] = min;
  }
}

// TODO 5. Implement getUnion
template <typename T>
T *getUnion(T *arr1, int size1, T *arr2, int size2, int &outSize) {
  sort(arr1, size1);
  sort(arr2, size2);
  T *temp = new T[size1 + size2];
  int conflictCount = 0;
  int i = 0;
  int j = 0;
  while (i < size1 && j < size2) {
    if (isGreater(arr2[j], arr1[i])) {
      temp[i + j - conflictCount] = arr1[i];
      while (true) {
        if (i == size1 - 1)
          break;
        if (isEqual(temp[i + j - conflictCount], arr1[i + 1])) {
          ++i;
          ++conflictCount;
        } else
          break;
      }
      ++i;
    } else if (isEqual(arr2[j], arr1[i])) {
      temp[i + j - conflictCount] = arr1[i];
      while (true) {
        if (i == size1 - 1)
          break;
        if (isEqual(temp[i + j - conflictCount], arr1[i + 1])) {
          ++i;
          ++conflictCount;
        } else
          break;
      }
      while (true) {
        if (j == size2 - 1)
          break;
        if (isEqual(temp[i + j - conflictCount], arr2[j + 1])) {
          ++j;
          ++conflictCount;
        } else
          break;
      }
      ++conflictCount;
      ++i;
      ++j;
    } else {
      temp[i + j - conflictCount] = arr2[j];
      while (true) {
        if (j == size2 - 1)
          break;
        if (isEqual(temp[i + j - conflictCount], arr2[j + 1])) {
          ++j;
          ++conflictCount;
        } else
          break;
      }
      ++j;
    }
  }
  if (i == size1) {
    for (; j < size2; j++) {
      temp[i + j - conflictCount] = arr2[j];
    }
  } else if (j == size2) {
    for (; i < size1; i++) {
      temp[i + j - conflictCount] = arr1[i];
    }
  }
  outSize = i + j - conflictCount;
  T *arr = new T[outSize];
  for (int k = 0; k < outSize; k++) {
    arr[k] = temp[k];
  }
  delete[] temp;

  return arr;
}

// Implement getIntersection
template <typename T>
T *getIntersection(T *arr1, int size1, T *arr2, int size2, int &outSize) {
  sort(arr1, size1);
  sort(arr2, size2);
  T *temp = new T[size1 + size2];
  int conflictCount = 0;
  int i = 0;
  int j = 0;
  while (i < size1 && j < size2) {
    if (isGreater(arr2[j], arr1[i])) {
      ++i;
    } else if (isEqual(arr2[j], arr1[i])) {
      temp[conflictCount] = arr1[i];
      ++conflictCount;
      ++i;
      ++j;
    } else {
      ++j;
    }
  }
  outSize = conflictCount;
  T *arr = new T[outSize];
  for (int k = 0; k < outSize; k++) {
    arr[k] = temp[k];
  }
  delete[] temp;

  return arr;
}

int main() {
  int size1 = 5, size2 = 4;
  int *intArr1 = new int[size1]{5, 5, 1, 10, 15};
  int *intArr2 = new int[size2]{25, 10, 20, 5};

  sort(intArr1, size1);
  sort(intArr2, size2);

  printArray(intArr1, size1, "\n--- Sorted intArr1 ---");
  printArray(intArr2, size2, "--- Sorted intArr2 ---");

  int unionSize = 0;
  int *intUnion = getUnion(intArr1, size1, intArr2, size2, unionSize);
  printArray(intUnion, unionSize, "\n--- Integer Union ---");

  int interSize = 0;
  int *intInter = getIntersection(intArr1, size1, intArr2, size2, interSize);
  printArray(intInter, interSize, "--- Integer Intersection ---");

  delete[] intArr1;
  delete[] intArr2;
  delete[] intUnion;
  delete[] intInter;

  int strSize1 = 4, strSize2 = 3;
  string *strArr1 = new string[strSize1];
  strArr1[0] = "Apple";
  strArr1[1] = "banana";
  strArr1[2] = "Cherry";
  strArr1[3] = "Grape";

  string *strArr2 = new string[strSize2];
  strArr2[0] = "BANANA";
  strArr2[1] = "grape";
  strArr2[2] = "Mango";

  sort(strArr1, strSize1);
  sort(strArr2, strSize2);

  printArray(strArr1, strSize1, "\n--- Sorted strArr1 ---");
  printArray(strArr2, strSize2, "--- Sorted strArr2 ---");

  int strUnionSize = 0;
  string *strUnion =
      getUnion(strArr1, strSize1, strArr2, strSize2, strUnionSize);
  printArray(strUnion, strUnionSize, "\n--- String Union ---");

  int strInterSize = 0;
  string *strInter =
      getIntersection(strArr1, strSize1, strArr2, strSize2, strInterSize);
  printArray(strInter, strInterSize, "--- String Intersection ---");

  delete[] strArr1;
  delete[] strArr2;
  delete[] strUnion;
  delete[] strInter;

  return 0;
}