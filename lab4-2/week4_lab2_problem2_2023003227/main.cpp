#include "func.h"

int main() {
  char map[10][10];
  char turn = 'O';

  int win_check = 0;
  int m = 0, n = 0;

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      map[y][x] = '+';
    }
  }

  while (true) {
    do {
      set_xy(turn, m, n);
      win_check = mark_map(map, turn, m, n);

      if (win_check == -1)
        banned();

    } while (win_check == -1);

    show_map(map);

    if (win_check == 1) {
      show_winner(turn);
      break;
    }

    if (turn == 'O')
      turn = 'X';
    else
      turn = 'O';
  }
  return 0;
}
