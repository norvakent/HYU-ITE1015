#include "Enemy.h"
#include "Person.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

void check(Player &player, Enemy &enemy) {
  int yourShape = player.get_shape();
  int enemyShape = enemy.get_shape();

  cout << player.get_name() << ": " << player.show_shape();
  cout << " | " << enemy.get_name() << ": " << enemy.show_shape() << endl;

  if (yourShape == enemyShape) {
    cout << "Draw" << endl;
  } else if ((yourShape == 1 && enemyShape == 3) ||
             (yourShape == 2 && enemyShape == 1) ||
             (yourShape == 3 && enemyShape == 2)) {
    cout << "You win" << endl;
    player.incrementWinCount();
  } else {
    cout << "You lose" << endl;
    enemy.incrementWinCount();
  }
  cout << player.get_name() << ": " << player.get_winCount();
  cout << " | " << enemy.get_name() << ": " << enemy.get_winCount() << endl
       << endl;
}

int main() {
  Player player;
  Enemy enemy;

  srand(42);

  while (player.get_winCount() < 3 && enemy.get_winCount() < 3) {
    player.chooseShape();
    enemy.chooseShape();
    check(player, enemy);
  }

  if (player.get_winCount() == 3)
    cout << "You win" << endl;
  else
    cout << "You lose" << endl;
}