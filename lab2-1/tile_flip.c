#include <stdio.h>

void print_map(char arr[][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j < 4) {
        printf("%c ", arr[i][j]);
      } else {
        printf("%c\n", arr[i][j]);
      }
    }
  }
}

void flip(char (*arr)[5], int y, int x) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x + j > 0 && x + j <= 5 && y + i > 0 && y + j <= 5) {
        if (arr[y + i - 1][x + j - 1] == 'O') {
          arr[y + i - 1][x + j - 1] = 'X';
        } else {
          arr[y + i - 1][x + j - 1] = 'O';
        }
      }
    }
  }
}

int main() {
  char arr[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      arr[i][j] = 'X';
    }
  }

  print_map(arr);
  int x, y;
  while (1) {
    printf("\n");
    printf("x : ");
    scanf("%d", &x);
    printf("y : ");
    scanf("%d", &y);
    flip(arr, y, x);
    print_map(arr);

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (arr[i][j] == 'O')
          cnt++;
      }
    }
    if (cnt == 25) {
      printf("complete!!\n");
      return 0;
    }
  }
}