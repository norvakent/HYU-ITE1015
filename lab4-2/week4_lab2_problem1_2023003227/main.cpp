#include "func.h"

int main() {

  int ground[5 + 2][5 + 2];
  char map[5 + 2][5 + 2];
  int x, y, win_checker;

  int checker = 25;

  int mine_count = 3;

  for (y = 0; y < 5 + 2; y++) {
    for (x = 0; x < 5 + 2; x++) {
      ground[y][x] = 0;
      if (y == 0 || y == 5 + 1)
        map[y][x] = '=';
      else if (x == 0 || x == 5 + 1)
        map[y][x] = '|';
      else
        map[y][x] = '?';
    }
  }

  plant_mine(ground, mine_count);
  while (1) {
    get_position(x, y);

    if (ground[y][x] == 1) {
      explode(map, ground);
      show_map(map, ground);
      break;
    }
    dig(map, ground, x, y, &checker);

    if (checker == mine_count) {
      youwin();
      break;
    }
    show_map(map, ground);
  }
  return 0;
}