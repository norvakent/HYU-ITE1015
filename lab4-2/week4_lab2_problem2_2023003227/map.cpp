#include <iostream>
using namespace std;

void show_map(char map[10][10]) {
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++)
      cout << map[y][x] << ' ';
    cout << "\n";
  }
  cout << "\n";
}

void set_xy(char mark, int &x, int &y) {
  cout << mark << "'s turn" << endl;
  cout << "\t\tx :";
  cin >> x;
  cout << "\t\ty :";
  cin >> y;
}

void show_winner(char mark) { cout << mark << " win" << endl; }

void banned() { cout << "cannot place this location\n" << endl; }