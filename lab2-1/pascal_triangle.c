#include <stdio.h>

int main() {
  int n;
  int arr[101][101];
  printf("input height : ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }

  arr[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      printf("  ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d   ", arr[i][j]);
    }
    printf("\n");
  }
}