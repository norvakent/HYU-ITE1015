#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int make_random_number() {
  srand(time(0));
  int num_1 = rand() % 10;
  int num_2 = rand() % 10;

  while (num_2 == num_1) {
    num_2 = rand() % 10;
  }
  int num_3 = rand() % 10;
  while (num_3 == num_2 | num_3 == num_1) {
    num_3 = rand() % 10;
  }
  int num_4 = rand() % 10;
  while (num_4 == num_3 | num_4 == num_2 | num_4 == num_1) {
    num_4 = rand() % 10;
  }

  int out_num = num_4 * 1000 + num_3 * 100 + num_2 * 10 + num_1;

  return out_num;
}

int check(int secret, int guess) {
  int correct = 0;
  int bull = 0;
  int cow = 0;
  int guess_1 = guess % 10;
  int guess_2 = guess / 10 % 10;
  int guess_3 = guess / 100 % 10;
  int guess_4 = guess / 1000 % 10;
  int secret_1 = secret % 10;
  int secret_2 = secret / 10 % 10;
  int secret_3 = secret / 100 % 10;
  int secret_4 = secret / 1000 % 10;

  if (guess_1 == secret_1)
    bull++;
  else {
    if (guess_1 == secret_2)
      cow++;
    else if (guess_1 == secret_3)
      cow++;
    else if (guess_1 == secret_4)
      cow++;
  }

  if (guess_2 == secret_2)
    bull++;
  else {
    if (guess_2 == secret_1)
      cow++;
    else if (guess_2 == secret_3)
      cow++;
    else if (guess_2 == secret_4)
      cow++;
  }

  if (guess_3 == secret_3)
    bull++;
  else {
    if (guess_3 == secret_1)
      cow++;
    else if (guess_3 == secret_2)
      cow++;
    else if (guess_3 == secret_4)
      cow++;
  }

  if (guess_4 == secret_4)
    bull++;
  else {
    if (guess_4 == secret_1)
      cow++;
    else if (guess_4 == secret_2)
      cow++;
    else if (guess_4 == secret_3)
      cow++;
  }

  printf("%d bull  %d cow\n\n", bull, cow);
  if (bull == 4) {
    printf("you win\n");
    correct = 1;
  }

  return correct;
}

int main() {
  int guess;
  int correct = 0;
  int Try = 1;
  int secret_num = make_random_number();
  // printf("%d", secret_num);
  while (correct == 0) {
    printf("Try %d: ", Try);
    scanf("%d", &guess);
    Try++;

    int guess_1 = guess % 10;
    int guess_2 = guess / 10 % 10;
    int guess_3 = guess / 100 % 10;
    int guess_4 = guess / 1000 % 10;
    if (guess_1 == guess_2 || guess_1 == guess_3 || guess_1 == guess_4 ||
        guess_2 == guess_3 || guess_2 == guess_4 || guess_3 == guess_4) {
      printf("The digits must be all different\n");
      continue;
    }

    correct = check(secret_num, guess);
  }
}