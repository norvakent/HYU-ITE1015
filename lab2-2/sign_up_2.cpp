#include <iostream>
#include <string>
using namespace std;

int main() {
  string id, pw, check;
  cout << "Write ID" << endl;
  cin >> id;
  cout << "your ID is " << id << endl;

  while(1) {
    cout << "Write PW" << endl;
    cin >> pw;

    // use size() method 
    if (pw.size() < 10) {
      cout << "PW must be at least 10 characters long." << endl;
      continue;
    }

    int alpha = 0;
    int num = 0;
    // use size() method instead length()
    for (int i = 0; i < pw.size(); i++) {
      // if (((char) pw[i] >= 'A' && (char) pw[i] <= 'Z') || ((char) pw[i] >= 'a' && (char)pw[i] <= 'z')) alphabet++;
      // if ((char) pw[i] >= '0' && (char) pw[i] <= '9') number++;
      // use isdigit(), isalpha() method
      if (isdigit(pw[i])) num++;
      else if (isalpha(pw[i])) alpha++;
    }
    if ((num && alpha) != 1) {
      cout << "PW must be a combination of alphabets and numbers." << endl;
      continue;
    }

    if (pw.find(id) != -1) {
      cout << "PW cannot include ID." << endl;
      continue;
    }

    break;
  }

  while(1) {
    cout << "check PW" << endl;
    cin >> check;

    if (pw == check) {
      cout << "PW check success" << endl;
      break;
    } else {
      cout << "PW check fail" << endl;
    }
  }
  cout << "your email is " << id << "@hanyang.ac.kr" << endl;
}
