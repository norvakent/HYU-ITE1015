#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num;
  int guess;
  int chance = 6;

  srand(time(0));
  num = rand() % 100 + 1;
  while (1) {
    printf("Choose 1~100 number\n");
    printf("User input:");
    scanf("%d", &guess);
    printf("\n");
    if (num > guess) {
      printf("Up\n%d chances left!\n", --chance);
    } else if (num < guess) {
      printf("Down\n%d chances left!\n", --chance);
    } else if (num == guess) {
      printf("Correct\nYou win\n");
      break;
    }

    if (!chance) {
      printf("You lose\ncorrect number was %d\n", num);
      break;
    }
  }
}