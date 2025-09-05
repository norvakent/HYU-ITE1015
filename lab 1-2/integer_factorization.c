#include <stdio.h>

int main() {
  int n;
  int current;
  printf("User input number : ");
  scanf("%d", &n);
  current = n;
  printf("\n");
  printf("%d = ", n);
  for (int i = 2; i <= n;) {
    if (current % i) {
      i++;
      continue;
    } else {
      printf(current == i ? "%d" : "%d X ", i);
      current /= i;
      continue;
    }
  }
  printf("\n");
}