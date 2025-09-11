#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_map(char map[5 + 2][5 + 2], int ground[5 + 2][5 + 2]);
void plant_mine(int (*ground)[5 + 2], int mines);
void dig(char (*map)[5 + 2], int ground[5 + 2][5 + 2], int x, int y,
         int *checker);
void explode(char map[5 + 2][5 + 2], int ground[5 + 2][5 + 2]);

int main() {
  int ground[5 + 2][5 + 2];
  char map[5 + 2][5 + 2];
  int x, y, win_checker;

  int checker = 25;

  int mine_count = 3;
  int attempts_left = 7;

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

  while (attempts_left > 0) {
    printf("x:");
    scanf("%d", &x);
    printf("y:");
    scanf("%d", &y);

    if (ground[y][x] == 1) {
      explode(map, ground);
      show_map(map, ground);
      break;
    }
    dig(map, ground, x, y, &checker);
    show_map(map, ground);

    attempts_left--;
    if (attempts_left == 0) {
      printf("you win!\n\n");
      break;
    }
  }
  return 0;
}

void show_map(char map[5 + 2][5 + 2], int ground[5 + 2][5 + 2]) {
  for (int y = 0; y < 5 + 2; y++) {
    for (int x = 0; x < 5 + 2; x++) {
      printf("%c ", map[y][x]);
    }
    printf("\n");
  }
  printf("\n");
}

void plant_mine(int (*ground)[5 + 2], int mines) {
  int m, n;
  int planted_mines = 0;

  srand(time(NULL));

  while (planted_mines < mines) {
    m = rand() % 5 + 1;
    n = rand() % 5 + 1;

    if (ground[m][n] != 1) {
      planted_mines++;
      ground[m][n] = 1;
    }
  }
  printf("%d mines have been placed\n\n", mines);
}

void dig(char (*map)[5 + 2], int ground[5 + 2][5 + 2], int x, int y,
         int *checker) {
  if (y < 1 || y > 5 || x < 1 || x > 5 || *checker == 0 || map[y][x] < '?')
    return;

  char zero = '0';
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      count += ground[y + i][x + j];
    }
  }
  map[y][x] = count ? zero + count : ' ';

  if (count == 0) {
    dig(map, ground, x - 1, y, checker);
    dig(map, ground, x, y - 1, checker);
    dig(map, ground, x + 1, y, checker);
    dig(map, ground, x, y + 1, checker);
  }

  *checker--;
}

void explode(char map[5 + 2][5 + 2], int ground[5 + 2][5 + 2]) {
  printf("explode!\n");
  for (int i = 0; i < 5 + 2; i++) {
    for (int j = 0; j < 5 + 2; j++) {
      if (ground[i][j])
        map[i][j] = 'X';
    }
  }
}