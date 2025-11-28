#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> findScaledPatterns(vector<int> &data, vector<int> &pattern) {
  vector<int> result;
  if (pattern.empty() || data.size() < pattern.size())
    return result;

  for (auto it = data.begin(); it <= data.end() - pattern.size(); ++it) {
    bool ok = true;
    int scale = 0;

    auto pit = pattern.begin();
    auto dit = it;

    for (; pit != pattern.end(); ++pit, ++dit) {
      int p = *pit;
      int d = *dit;

      if (p == 0) {
        if (d != 0) {
          ok = false;
          break;
        }
        continue;
      }

      if (d % p != 0) {
        ok = false;
        break;
      }

      int currentScale = d / p;
      if (scale == 0)
        scale = currentScale;
      else if (scale != currentScale) {
        ok = false;
        break;
      }
    }

    if (ok) {
      int pos = it - data.begin();
      result.push_back(pos);
      result.push_back(scale);
    }
  }

  return result;
}

vector<int> findRotatedPatterns(vector<int> &data, vector<int> &pattern) {
  vector<int> result;

  int n = data.size();
  int m = pattern.size();
  if (m == 0 || n < m)
    return result;

  auto dataBegin = data.begin();
  auto dataEnd = data.end();
  auto patBegin = pattern.begin();

  for (auto it = dataBegin; it <= dataEnd - m; ++it) {
    int pos = it - dataBegin;

    for (int rot = 0; rot < m; rot++) {
      bool ok = true;
      auto dit = it;

      for (int j = 0; j < m; j++, ++dit) {
        int patIndex = rot + j;
        if (patIndex >= m)
          patIndex -= m;
        auto pit = patBegin + patIndex;

        if (*dit != *pit) {
          ok = false;
          break;
        }
      }

      if (ok) {
        result.push_back(pos);
        result.push_back(rot);
      }
    }
  }

  return result;
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

void printMatches(const vector<int> &matches) {
  cout << "{";
  for (auto it = matches.begin(); it != matches.end(); it += 2) {
    cout << "{" << *it << ", " << *(it + 1) << "}";
    if (it != matches.end() - 2)
      cout << ", ";
  }
  cout << "}" << endl;
}

void runPredefinedTests() {
  vector<pair<vector<int>, vector<int>>> testCases = {
      {{1, 2, 3, 2, 3, 1, 4, 8, 12, 3, 6, 9, 3, 1, 2}, {1, 2, 3}},
      {{15, 9, 4, 9, 4, 15, 4, 15, 9, 9, 4, 15, 4, 15, 9, 4, 15, 9, 36, 60},
       {9, 4, 15}}};

  for (size_t i = 0; i < testCases.size(); ++i) {
    cout << "\n=== Test Case " << (i + 1) << " ===" << endl;
    auto &data = testCases[i].first;
    auto &pattern = testCases[i].second;

    cout << "Data: ";
    printArray(data);
    cout << "Pattern: ";
    printArray(pattern);

    auto patternResult = findScaledPatterns(data, pattern);
    cout << "Pattern matches (position, scale): ";
    printMatches(patternResult);

    auto rotationResult = findRotatedPatterns(data, pattern);
    cout << "Rotation matches (position, rotation): ";
    printMatches(rotationResult);
  }
}

void runCustomInput() {
  cout << "\n=== Custom Input ===" << endl;

  cout << "Enter data array (space-separated): ";
  string dataLine;
  getline(cin, dataLine);

  vector<int> data;
  stringstream ss1(dataLine);
  int val;
  while (ss1 >> val) {
    data.push_back(val);
  }

  cout << "Enter pattern array (space-separated): ";
  string patternLine;
  getline(cin, patternLine);

  vector<int> pattern;
  stringstream ss2(patternLine);
  while (ss2 >> val) {
    pattern.push_back(val);
  }

  cout << "\nData: ";
  printArray(data);
  cout << "Pattern: ";
  printArray(pattern);

  auto patternResult = findScaledPatterns(data, pattern);
  cout << "Pattern matches (position, scale): ";
  printMatches(patternResult);

  auto rotationResult = findRotatedPatterns(data, pattern);
  cout << "Rotation matches (position, rotation): ";
  printMatches(rotationResult);
}

int main() {
  cout << "=== Pattern & Rotation Matcher ===" << endl;
  cout << "Choose mode:" << endl;
  cout << "1. Run predefined test cases" << endl;
  cout << "2. Enter custom input" << endl;
  cout << "3. Exit" << endl;

  while (true) {
    cout << "\nChoice (1-3): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
      runPredefinedTests();
    else if (choice == 2)
      runCustomInput();
    else if (choice == 3)
      break;
    else
      cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
  }
  return 0;
}