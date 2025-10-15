#ifndef ENEMY_H
#define ENEMY_H
#include "Person.h"
#include <iostream>
#include <string>

class Enemy : public Person {
public:
  Enemy();
  void chooseShape();
  string get_name();
};

#endif