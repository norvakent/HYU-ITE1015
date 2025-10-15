#include "Enemy.h"
#include "Person.h"

Enemy::Enemy() {
  setName("Enemy");
  win_count = 0;
}

void Enemy::chooseShape() { shape = rand() % 3 + 1; }

string Enemy::get_name() { return Person::get_name(); }