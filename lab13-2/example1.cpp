#include <iostream>
using namespace std;

int main() {
  string text =
      "dream as if you will live forever, live as if you will die today.";

  int cntA = 0;
  int cntE = 0;
  int cntI = 0;
  int cntO = 0;
  int cntU = 0;

  for (auto it = text.begin(); it != text.end(); it++) {
    if (*it == 'a')
      cntA++;
    if (*it == 'e')
      cntE++;
    if (*it == 'i')
      cntI++;
    if (*it == 'o')
      cntO++;
    if (*it == 'u')
      cntU++;
  }

  cout << "The number of vowels in the given text" << endl;
  cout << "a: " << cntA << endl;
  cout << "e: " << cntE << endl;
  cout << "i: " << cntI << endl;
  cout << "o: " << cntO << endl;
  cout << "u: " << cntU << endl;
  cout << "Total number of vowels: " << cntA + cntE + cntI + cntO + cntU
       << endl;

  return 0;
}