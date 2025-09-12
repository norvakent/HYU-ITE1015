#include <iostream>
using namespace std;

void show_board(char board[10][10]);
int mark_board(char board[10][10], char mark, int x, int y);
int check_omok(char board[10][10], char mark, int x, int y);
int check_line(char board[10][10], char mark, int x, int y, int x_dir, int y_dir);

int main() {
  char board[10][10];
  char turn = 'O';
  int win_checker = 0;
  int x, y;
  for (y = 0; y < 10; y++) {
    for (x = 0; x < 10; x++) {
      board[y][x] = '+';
    }
  }
  while(1) {
    do {
      printf("%c 's turn\n", turn);
      printf("\t\tx :");
      scanf("%d", &x);
      printf("\t\ty :");
      scanf("%d", &y);
      win_checker = mark_board(board, turn, x, y);
      printf("\n");
    } while (win_checker == -1);

    show_board(board);
    if (win_checker == 1)
      break;
    if (turn == 'O')
      turn = 'X';
    else
      turn = 'O';
  }
  printf("%c win\n", turn);
}

void show_board(char board[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 9)
        printf("%c\n", board[i][j]);
      else
        printf("%c ", board[i][j]);
    }
  }
}

int mark_board(char board[10][10], char mark, int x, int y) {
  if (x < 0 || x >= 10 || y < 0 || y >= 10 || board[y][x] != '+') {
    printf("cannot place this location");
    return -1;
  }
  board[y][x] = mark;
  return check_omok(board, mark, x, y);
}

int check_omok(char board[10][10], char mark, int x, int y) {
  if (1 + check_line(board, mark, x + 1, y, 1, 0) + check_line(board, mark, x - 1, y, -1, 0) >= 5) return 1;
  if (1 + check_line(board, mark, x, y + 1, 0, 1) + check_line(board, mark, x, y - 1, 0, -1) >= 5) return 1;
  if (1 + check_line(board, mark, x + 1, y + 1, 1, 1) + check_line(board, mark, x - 1, y - 1, -1, -1) >= 5) return 1;
  if (1 + check_line(board, mark, x + 1, y - 1, 1, -1) + check_line(board, mark, x - 1, y + 1, -1, 1) >= 5) return 1;
  return 0;
}

int check_line(char board[10][10], char mark, int x, int y, int x_dir, int y_dir) {
  if (x < 0 || x >= 10 || y < 0 || y >= 10 || board[y][x] != mark) return 0;
  return 1 + check_line(board, mark, x + x_dir, y + y_dir, x_dir, y_dir);
}