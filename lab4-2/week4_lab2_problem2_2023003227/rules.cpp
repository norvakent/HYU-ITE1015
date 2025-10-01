int check_line(char map[10][10], char mark, int x, int y, int x_dir,
               int y_dir) {
  if (x < 0 || x > 9 || y < 0 || y > 9 || mark != map[y][x])
    return 0;
  return 1 + check_line(map, mark, x + x_dir, y + y_dir, x_dir, y_dir);
}

int check_forbidden_line(char map[10][10], char mark, int x, int y, int x_dir,
                         int y_dir, int &open) {
  if (x < 0 || x > 9 || y < 0 || y > 9)
    return 0;
  if (map[y][x] == '+') {
    open = 1;
    return 0;
  } else if (map[y][x] != mark)
    return 0;
  return 1 + check_forbidden_line(map, mark, x + x_dir, y + y_dir, x_dir, y_dir,
                                  open);
}

void check_forbidden_3x3(char map[10][10], char mark, int x, int y, int x_dir,
                         int y_dir, int &flag_3x3) {
  // TODO: Implement the logic to detect an "open three" on a single axis.
  //
  // 1. Use the check_forbidden_line() function twice to check both directions
  // along the given axis
  //    (e.g., right and left for the horizontal axis).
  //
  // 2. Sum the results to determine the total number of connected stones.
  //
  // 3. Check if both ends of the line are open.
  //
  // 4. If the conditions for an "open three" (+ O O O +) are met,
  //    set the flag_3x3 parameter to 1.
  int open1 = 0;
  int open2 = 0;
  int total = -1;
  total += check_forbidden_line(map, mark, x, y, x_dir, y_dir, open1);
  total += check_forbidden_line(map, mark, x, y, -x_dir, -y_dir, open2);
  if (open1 && open2 && total == 3) flag_3x3 += 1;
}

int check_forbidden(char map[10][10], char mark, int x, int y) {
  // TODO: Implement the final "3x3" forbidden move check.
  //
  // 1. Call the check_forbidden_3x3() function four times, once for each axis:
  //    - Horizontal (x_dir=1, y_dir=0)
  //    - Vertical (x_dir=0, y_dir=1)
  //    - Diagonal (x_dir=1, y_dir=1)
  //    - Anti-diagonal (x_dir=-1, y_dir=1)
  //
  // 2. Sum the results from all four calls.
  //
  // 3. If the total number of "open threes" is 2 or more, it's a "3x3"
  // forbidden move.
  //    In this case, return 1. Otherwise, return 0.
  int flag_3x3 = 0;
  check_forbidden_3x3(map, mark, x, y, 1, 0, flag_3x3);
  check_forbidden_3x3(map, mark, x, y, 0, 1, flag_3x3);
  check_forbidden_3x3(map, mark, x, y, 1, 1, flag_3x3);
  check_forbidden_3x3(map, mark, x, y, -1, 1, flag_3x3);

  if (flag_3x3 >= 2) return 1;
  return 0;
}

int check_omok(char map[10][10], char mark, int x, int y) {
  int check[4] = {0};
  check[0] = 1 + check_line(map, mark, x + 1, y, 1, 0) +
             check_line(map, mark, x - 1, y, -1, 0);
  check[1] = 1 + check_line(map, mark, x, y + 1, 0, 1) +
             check_line(map, mark, x, y - 1, 0, -1);
  check[2] = 1 + check_line(map, mark, x + 1, y + 1, 1, 1) +
             check_line(map, mark, x - 1, y - 1, -1, -1);
  check[3] = 1 + check_line(map, mark, x + 1, y - 1, 1, -1) +
             check_line(map, mark, x - 1, y + 1, -1, 1);

  if (mark == 'X') {
    if (check[0] >= 5 || check[1] >= 5 || check[2] >= 5 || check[3] >= 5)
      return 1;
  } else if (mark == 'O') {
    if (check[0] == 5 || check[1] == 5 || check[2] == 5 || check[3] == 5)
      return 1;
    if (check[0] >= 6 || check[1] >= 6 || check[2] >= 6 || check[3] >= 6)
      return -1;
    if (check_forbidden(map, mark, x, y) == 1)
      return -1;
  }
  return 0;
}