#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> generateRandomTriangle(int n) {
  vector<vector<int>> triangle;

  /* TODO: Create a triangle with n rows where row[i] has (i+1) elements
     Each element should be a random number from 1 to 100. Use rand() */

  // If you want reproducible results, uncomment the next line
  srand(32);
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j <= i; j++) {
      row.push_back(1 + rand() % 100);
    }
    triangle.push_back(row);
  }

  return triangle;
}

pair<int, vector<int>> findMaxPathSum(const vector<vector<int>> &triangle) {
  int maxSum = 0;
  vector<int> path;

  /* TODO: Find the path from top to bottom that gives the maximum sum
     Return both the sum and the actual path taken
     Hint: You can use max(a, b) which returns the larger value */

  if (triangle.size() == 1) {
    maxSum += triangle.at(0).at(0);
    path.push_back(maxSum);
    return pair<int, vector<int>>(maxSum, path);
  }

  vector<vector<int>> sumTriangle = vector<vector<int>>(triangle);
  reverse(sumTriangle.begin(), sumTriangle.end());
  for (int i = 1; i < sumTriangle.size(); i++) {
    for (int j = 0; j < sumTriangle.at(i).size(); j++) {
      sumTriangle.at(i).at(j) +=
          max(sumTriangle.at(i - 1).at(j), sumTriangle.at(i - 1).at(j + 1));
    }
  }
  reverse(sumTriangle.begin(), sumTriangle.end());
  maxSum = sumTriangle.front().at(0);
  int idx = 0;
  for (int i = 0; i < sumTriangle.size(); i++) {
    path.push_back(triangle.at(i).at(idx));
    if (i == sumTriangle.size() - 1)
      break;
    idx +=
        (sumTriangle.at(i + 1).at(idx) > sumTriangle.at(i + 1).at(idx + 1) ? 0
                                                                           : 1);
  }

  return {maxSum, path};
}

void printTriangle(const vector<vector<int>> &triangle) {
  int n = triangle.size();
  int maxNum = 0;
  for (int val : triangle.at(n - 1)) {
    maxNum = (maxNum > val) ? maxNum : val;
  }

  int maxWidth = 1;
  while (maxNum >= 10) {
    maxNum /= 10;
    maxWidth++;
  }

  for (int i = 0; i < n; i++) {
    int spaces = (n - i - 1) * maxWidth;

    for (int s = 0; s < spaces; ++s)
      cout << ' ';

    for (int j = 0; j <= i; j++) {
      cout.width(maxWidth * 2);
      cout << triangle.at(i).at(j);
    }
    cout << endl;
  }
}

int main() {
  string input;

  while (true) {
    cout << "Enter triangle size (or 'quit' to exit): ";
    cin >> input;

    if (input == "quit") {
      cout << "Exiting program..." << endl;
      break;
    }

    int n = stoi(input);
    if (n <= 0) {
      cout << "Please enter a positive integer." << endl;
      continue;
    }

    cout << "\n=== Random Number Triangle (n = " << n << ") ===" << endl;
    vector<vector<int>> triangle = generateRandomTriangle(n);
    printTriangle(triangle);

    cout << "\n=== Maximum Path Sum ===" << endl;
    pair<int, vector<int>> result = findMaxPathSum(triangle);
    cout << "Maximum path sum from top to bottom: " << result.first << endl;

    cout << "Path taken: ";
    for (int i = 0; i < result.second.size(); i++) {
      cout << result.second.at(i);
      if (i < result.second.size() - 1)
        cout << " -> ";
    }
    cout << endl;

    cout << "Sum verification: ";
    int sum = 0;
    for (int val : result.second)
      sum += val;
    cout << sum << " (should equal " << result.first << ")" << "\n" << endl;
  }
  return 0;
}