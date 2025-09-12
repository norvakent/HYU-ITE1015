#include <stdio.h>

int main() {
  char id[20];
  char pw[20];
  char check[20];

  printf("Write ID\n");
  scanf("%s", id);
  printf("your ID is %s\n", id);

  printf("Write PW\n");
  scanf("%s", pw);

  int pass = 0;
  while (!pass) {
    printf("Check PW\n");
    scanf("%s", check);

    int i = 0;
    while (pw[i] != '\0') {
      if (pw[i] == check[i])
        i++;
      else
        break;
    }
    if (pw[i] == check[i])
      pass = 1;
    else
      printf("PW check fail\n");
  }
  printf("PW check success\n");
  printf("your email is %s@hanyang.ac.kr\n", id);
}