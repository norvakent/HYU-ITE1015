#include <stdio.h>

void explode(char (*map)[5 + 2], int ground[5 + 2][5 + 2]) {
  for (int y = 0; y < 5 + 2; y++) {
    for (int x = 0; x < 5 + 2; x++) {
      if (ground[y][x] == 1)
        map[y][x] = 'X';
    }
  }
  printf("explode!\n");
}