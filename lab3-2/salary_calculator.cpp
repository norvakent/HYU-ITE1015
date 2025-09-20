#include <iostream>
#include <string>

using namespace std;

namespace staff {
  void salary(string name, int years) {
    cout << "Hi staff " << name << " your salary is " << (1000 + years * 100) << endl;
  }
}

namespace manager {
  void salary(string name, int years) {
    cout << "Hi manager " << name << " your salary is " << (2000 + years * 200) << endl;
  }
}

void calculate(string name, string position, int years = 0) {
  if (position == "staff") {
    staff::salary(name, years);
  } else if (position == "manager") {
    manager::salary(name, years);
  } else {
    cout << "wrong position" << endl;
  }
}

int main() {
  string name, position;
  int years, bonus;
  cout << "[User Input] Input your name : ";
  cin >> name;
  cout << "[User Input] Input your position : ";
  cin >> position;
  cout << "\nCalculate without entering years : ";
  calculate(name, position);
  cout << "\n";
  cout << "[User Input] How long did you work in this position? : ";
  cin >> years;
  cout << "\nCalculate with entering years : ";
  calculate(name, position, years);
  cout << "\n";
}