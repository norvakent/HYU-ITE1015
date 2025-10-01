#include "func.h" 

int mark_map(char (&map)[10][10], char mark, int x, int y) {
  int check;

  if (map[y][x] != '+') {
    return -1;
  }
  map[y][x] = mark;

  check = check_omok(map, mark, x, y);
  if (check == -1)
    map[y][x] = '+';

  return check;
}