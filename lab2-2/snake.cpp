#include <iostream>
#include <string>
using namespace std;

void move(int* x, int* y, string dir, char map[3][6]) {
  map[*y][*x] = 'O';
  if (dir == "right") (*x)++;
  else if (dir == "left") (*x)--;
  else if (dir == "down") (*y)++;
  else if (dir == "up") (*y)--;
  map[*y][*x] = '@';
}

void print_board(char map[3][6]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      cout << " " << map[i][j];
    }
    cout << endl;
  }
}

int main() {
  char map[3][6];
  string dir;
  int x, y;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      map[i][j] = 'X';
    }
  }

  x = 0;
  y = 0;
  map[y][x] = '@';

  while(1) {
    print_board(map);
    cout << endl;
    cout << "Move (left, right, up, down) :";
    cin >> dir;
    
    if (dir == "right" && x == 5) {
      cout << "You cannot move in this direction" << endl;
    }
    else if (dir == "left" && x == 0) {
      cout << "You cannot move in this direction" << endl;
    }
    else if (dir == "down" && y == 2) {
      cout << "You cannot move in this direction" << endl;
    }
    else if (dir == "up" && y == 0) {
      cout << "You cannot move in this direction" << endl;
    }
    else {
      move(&x, &y, dir, map);
    }
  }
}