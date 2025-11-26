#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T> struct Subarray {
  /* TODO: Define members: start index, end index, product
     Implement operator< for sorting (descending by product, prefer shorter if
     equal) */
  int start;
  int end;
  T productValue;
  bool operator<(const Subarray &other) const {
    if (productValue != other.productValue)
      return productValue > other.productValue;

    int len = end - start;
    int otherLen = other.end - other.start;
    if (len != otherLen)
      return len < otherLen;

    return start < other.start;
  }
};

template <typename T>
vector<T> findKthLargestSubarray(const vector<T> &nums, int k) {
  /* TODO: Generate all subarrays with their products, sort them,
     and return the k-th largest subarray as a vector */
  vector<Subarray<T>> sub;
  T prod;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      prod = 1;
      for (int k = i; k <= j; k++) {
        prod *= nums.at(k);
      }
      Subarray<T> s;
      s.start = i;
      s.end = j;
      s.productValue = prod;
      sub.push_back(s);
    }
  }
  sort(sub.begin(), sub.end());

  vector<T> ret;
  for (int i = sub.at(k - 1).start; i <= sub.at(k - 1).end; i++) {
    ret.push_back(nums.at(i));
  }
  return ret;
}

template <typename T> T calculateProduct(const vector<T> &nums) {
  /* TODO: Calculate and return the product of all elements in the array */
  T prod = 1;
  for (T element : nums) {
    prod *= element;
  }
  return prod;
}

template <typename T> void printArray(const vector<T> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i < nums.size() - 1)
      cout << ", ";
  }
  cout << "]";
}

template <typename T> void runProgram(const string &line) {
  vector<T> nums;
  stringstream ss(line);
  T num;
  while (ss >> num) {
    nums.push_back(num);
  }

  if (nums.empty()) {
    cout << "No input provided. Exiting..." << endl;
    return;
  }

  cout << "\nInput Array: ";
  printArray(nums);
  cout << endl;

  int totalSubarrays = nums.size() * (nums.size() + 1) / 2;
  cout << "Total number of subarrays: " << totalSubarrays << endl;

  while (true) {
    cout << "\nWhich k-th largest product subarray would you like to find? ";
    cout << "(Enter 0 to quit): ";
    int k;
    cin >> k;

    if (k == 0) {
      cout << "Exiting..." << endl;
      break;
    }

    if (k < 0 || k > totalSubarrays) {
      cout << "Invalid input. Please enter a number between 1 and "
           << totalSubarrays << endl;
      continue;
    }

    vector<T> kthSub = findKthLargestSubarray(nums, k);

    if (kthSub.empty()) {
      cout << "Error finding the " << k << "-th largest subarray." << endl;
    } else {
      cout << k;
      if (k == 1)
        cout << "st";
      else if (k == 2)
        cout << "nd";
      else if (k == 3)
        cout << "rd";
      else
        cout << "th";

      cout << " Largest Product Subarray: ";
      printArray(kthSub);
      cout << " (Product: " << calculateProduct(kthSub) << ")" << endl;
    }
  }
}

int main() {
  cout << "=== Maximum Product Subarray Finder ===" << endl;
  cout << "Choose input type:" << endl;
  cout << "1. Integer" << endl;
  cout << "2. Decimal (floating-point)" << endl;
  cout << "Enter choice (1 or 2): ";

  int choice;
  cin >> choice;
  cin.ignore();

  if (choice == 1) {
    cout << "Enter integer array elements separated by spaces: ";
    string line;
    getline(cin, line);
    runProgram<long long>(line);
  } else if (choice == 2) {
    cout << "Enter decimal array elements separated by spaces: ";
    string line;
    getline(cin, line);
    runProgram<double>(line);
  } else {
    cout << "Invalid choice. Exiting..." << endl;
  }

  return 0;
}