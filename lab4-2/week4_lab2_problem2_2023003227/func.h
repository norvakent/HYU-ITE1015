int mark_map(char (&map)[10][10], char mark, int x, int y);

void show_map(char map[10][10]);
void set_xy(char mark, int &x, int &y);
void show_winner(char mark);
void banned();

int check_line(char map[10][10], char mark, int x, int y, int x_dir, int y_dir);
int check_forbidden_line(char map[10][10], char mark, int x, int y, int x_dir, int y_dir, int &open);
void check_forbidden_3x3(char map[10][10], char mark, int x, int y, int x_dir, int y_dir, int &flag_3x3);
int check_forbidden(char map[10][10], char mark, int x, int y);
int check_omok(char map[10][10], char mark, int x, int y);