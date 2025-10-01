void dig(char (*map)[5 + 2], int ground[5 + 2][5 + 2], int x, int y, int *checker);

void explode(char (*map)[5 + 2], int ground[5 + 2][5 + 2]);

void get_position(int &x, int &y);
void youwin();
void plant_mine(int (*ground)[5 + 2], int mines);
void show_map(char map[5 + 2][5 + 2], int ground[5 + 2][5 + 2]);