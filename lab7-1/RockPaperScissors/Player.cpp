#include "Player.h"
#include "Person.h"

Player::Player() {
  cout << "Enter your name : ";
  string m;
  cin >> m;
  setName(m);
  win_count = 0;
  cout << endl;
}

void Player::chooseShape() {
  do {
    cout << "Choose one (1:Rock, 2:Paper, 3:Scissors) :";
    cin >> shape;
    if (shape < 1 || shape > 3) {
      cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    }
  } while (shape < 1 || shape > 3);
}

string Player::get_name() { return Person::get_name(); }