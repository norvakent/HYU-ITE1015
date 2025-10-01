#include <stdio.h>

void dig(char (*map)[5 + 2], int ground[5 + 2][5 + 2], int x, int y,
         int *checker) {

  if (x < 1 || x > 5 || y < 1 || y > 5)
    return;
  if (map[y][x] != '?')
    return;

  static bool hint_provided = false;

  char zero = '0';
  int count = 0;
  int xhint, yhint;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      count += ground[y + i][x + j];
      if (!hint_provided && !ground[y + i][x + j]) {
        xhint = x + j;
        yhint = y + i;
      }
    }
  }
  map[y][x] = count ? zero + count : ' ';

  if (count == 2 && !hint_provided) {
    hint_provided = true;
    printf("\nHint: (%d, %d) is a safe spot!\n\n", xhint, yhint);
  } else if (count == 0) {
    dig(map, ground, x - 1, y, checker);
    dig(map, ground, x, y - 1, checker);
    dig(map, ground, x + 1, y, checker);
    dig(map, ground, x, y + 1, checker);
  }

  *checker -= 1;
}