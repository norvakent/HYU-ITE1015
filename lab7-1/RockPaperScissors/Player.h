#ifndef PLAYER_H
#define PLAYER_H
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class Player : public Person {
public:
  Player();
  void chooseShape();
  string get_name();
};

#endif