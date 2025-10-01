#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_position(int &x, int &y) {
  printf("x (1~5):");
  scanf("%d", &x);
  printf("y (1~5):");
  scanf("%d", &y);
}

void youwin() {
  printf("you win");
  printf("\n");
}

void plant_mine(int (*ground)[5 + 2], int mines) {
  int planted_mines = 0;
  int m, n;

  srand(time(NULL));

  while (planted_mines < mines) {
    m = rand() % 5 + 1;
    n = rand() % 5 + 1;

    if (ground[m][n] == 0) {
      ground[m][n] = 1;
      planted_mines += 1;
    }
  }
  printf("%d mines have been placed\n\n", mines);
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