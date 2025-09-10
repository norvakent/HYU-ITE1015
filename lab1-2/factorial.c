#include <stdio.h>

int recursive(int n) {
  if (n == 0)
    return 1;
  printf("%d ", n);
  printf(n == 1 ? "= " : "X ");
  return n * recursive(n - 1);
}

int main(void) {
  int n;
  printf("User Input :");
  scanf("%d", &n);
  printf("\n");
  printf("%d\n", recursive(n));
}