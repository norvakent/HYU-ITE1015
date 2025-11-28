#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> mergeKSortedArraysDedup(vector<vector<int>> &arrays) {
  /* TODO: Merge k sorted arrays into one sorted array without duplicates
  You must use iterators and the auto keyword

  The following hints and starter code are optional.
  1. Track current position in each array using iterators
  2. Find minimum value among current elements of all arrays
  3. Add to result only if not duplicate
  * Any correct implementation is acceptable. */

  vector<vector<int>::iterator> its, ends;

  for (auto &arr : arrays) {
    its.push_back(arr.begin());
    ends.push_back(arr.end());
  }

  vector<int> mergedArray;
  if (its.empty())
    return mergedArray;

  while (true) {
    bool any = false;
    for (auto it = its.begin(), e = ends.begin(); it != its.end(); ++it, ++e) {
      if (*it != *e) {
        any = true;
        break;
      }
    }
    if (!any)
      break;

    int minVal = 2147483647;
    int minIdx = -1;
    int idx = 0;
    for (auto it = its.begin(), e = ends.begin(); it != its.end();
         ++it, ++e, ++idx) {
      if (*it == *e)
        continue;
      int v = *(*it);
      if (v < minVal) {
        minVal = v;
        minIdx = idx;
      }
    }

    if (minIdx == SIZE_MAX)
      break;

    if (mergedArray.empty() || mergedArray.back() != minVal)
      mergedArray.push_back(minVal);

    while (its[minIdx] != ends[minIdx] && *its[minIdx] == minVal)
      ++its[minIdx];
  }

  return mergedArray;
}

void printArray(const vector<int> &arr) {
  cout << "[";
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    cout << *it;
    if (it != arr.end() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main() {
  cout << "=== K-way Merge with Deduplication ===" << endl;
  cout << "Enter number of sorted arrays: ";
  int k;
  cin >> k;
  cin.ignore();

  vector<vector<int>> arrays(k);
  for (int i = 0; i < k; i++) {
    cout << "Enter sorted array " << (i + 1) << " (space-separated): ";
    string line;
    getline(cin, line);

    stringstream ss(line);
    int val;
    while (ss >> val) {
      arrays[i].push_back(val);
    }
  }

  cout << "\n=== Input Arrays ===" << endl;
  for (int i = 0; i < arrays.size(); i++) {
    cout << "Array " << (i + 1) << ": ";
    printArray(arrays[i]);
  }

  vector<int> merged = mergeKSortedArraysDedup(arrays);
  cout << "\n=== Merged Result ===" << endl;
  cout << "Result: ";
  printArray(merged);

  return 0;
}
