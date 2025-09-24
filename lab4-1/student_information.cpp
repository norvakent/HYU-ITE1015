#include <iostream>
#include <string>
using namespace std;

struct Student {
  string name;
  int age;
  int score;
};

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;

  Student* students = new Student[n];
  int up = 0;
  int down = 0;

  for (int i = 0; i < n; i++) {
    cout << "Enter name for student 1: ";
    cin >> students[i].name;
    cout << "Enter age for student 1: ";
    cin >> students[i].age;
    cout << "Enter score for student 1: ";
    cin >> students[i].score;
    if (students[i].age < 20) down++;
    else up++;
  }

  Student* students_up20 = new Student[up];
  Student* students_under20 = new Student[down];

  cout << "\nStudent Information: \n";
  int upcnt = 0;
  int downcnt = 0;
  int upsum = 0;
  int downsum = 0;

  for (int i = 0; i < n; i++) {
    cout << "Name: " << students[i].name
    << ", Age: " << students[i].age
    << ", Score: " << students[i].score
    << endl;
    if (students[i].age < 20) students_under20[downcnt++] = students[i];
    else students_up20[upcnt++] = students[i];
  }

  for (int i = 0; i < up; i++) {
    upsum += students_up20[i].score;
  }
  upsum /= up;

  for (int i = 0; i < down; i++) {
    downsum += students_under20[i].score;
  }
  downsum /= down;

  cout << "Average score of over 20 students is : " << upsum << endl;
  cout << "Average score of under 20 students is : " << downsum << endl;

  delete[] students;
  delete[] students_up20;
  delete[] students_under20;

  return 0;
}