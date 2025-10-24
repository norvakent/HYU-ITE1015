#include <iostream>
#include <string>

#include "WeaponLogger.h"

using namespace std;

/* ---------- Base Class ---------- */
class Weapon {
public:
  virtual ~Weapon() {}
  virtual void attack() = 0;
  virtual string kind() = 0;
};

/* ---------- Derived Classes (Using Logger) ---------- */
class Sword : public Weapon {
private:
  int sharpness;

public:
  Sword(int state) : sharpness(state) {}
  void attack() override {
    if (sharpness <= 0) {
      WeaponLogger::log_sword_dull();
    } else {
      WeaponLogger::log_sword_slash(--sharpness);
    }
  }
  string kind() override { return "Sword"; }
};

class Bow : public Weapon {
private:
  int arrows;

public:
  Bow(int state) : arrows(state) {}
  void attack() override {
    if (arrows <= 0) {
      WeaponLogger::log_bow_no_arrows();
    } else {
      WeaponLogger::log_bow_shoot(--arrows);
    }
  }
  string kind() override { return "Bow"; }
};

class Staff : public Weapon {
private:
  int mana;

public:
  Staff(int state) : mana(state) {}
  void attack() override {
    if (mana <= 0) {
      WeaponLogger::log_staff_no_mana();
    } else {
      WeaponLogger::log_staff_cast(--mana);
    }
  }
  string kind() override { return "Staff"; }
};

/* ---------- Helper function ---------- */
Weapon *createWeapon(char c) {
  switch (c) {
  case 'S':
  case 's':
    return new Sword(5);
  case 'B':
  case 'b':
    return new Bow(5);
  case 'T':
  case 't':
    return new Staff(5);
  default:
    return nullptr;
  }
};

int main() {
  // TODO: Make slots to hold 3 Weapon pointers
  Weapon *weapons[3];
  WeaponLogger::log_prompt_weapon_types();

  for (int i = 0; i < 3; ++i) {
    char type;

    // Make loop to get valid weapon type input.

    while (true) {
      cout << "Slot " << i << ": ";
      cin >> type;
      // Note: Assume valid input is 'S', 's', 'B', 'b', 'T', or 't'
      // TODO: Get user input for weapon type and break the loop if valid
      if (type == 'S' || type == 's' || type == 'B' || type == 'b' ||
          type == 'T' || type == 't')
        break;
      else
        WeaponLogger::log_error_invalid_input();
    }

    // TODO: Create weapon using createWeapon and assign to slots
    weapons[i] = createWeapon(type);
  }

  int rounds = 0;
  WeaponLogger::log_prompt_rounds();
  std::cin >> rounds;

  if (rounds < 1) {
    WeaponLogger::log_error_invalid_rounds();
    rounds = 1;
  }

  // TODO: Print weapons in slots using logger
  WeaponLogger::log_header_weapons_in_slots();
  for (int i = 0; i < 3; ++i) {
    WeaponLogger::log_weapon_in_slot(i, weapons[i]->kind());
  }

  // TODO: Attack before swapping weapons
  WeaponLogger::log_header_attack_before_swap();
  for (int i = 0; i < rounds; ++i) {
    WeaponLogger::log_round_start(i + 1);
    for (int j = 0; j < 3; ++j) {
      weapons[j]->attack();
    }
  }

  // TODO: Implement swapping between slot 0 and slot 1
  Weapon *temp = weapons[1];
  weapons[1] = weapons[0];
  weapons[0] = temp;

  // TODO: Print weapons in slots using logger
  WeaponLogger::log_header_weapons_in_slots();
  for (int i = 0; i < 3; ++i) {
    WeaponLogger::log_weapon_in_slot(i, weapons[i]->kind());
  }

  // TODO: Attack after swapping weapons
  WeaponLogger::log_header_attack_after_swap();
  for (int i = 0; i < rounds; ++i) {
    WeaponLogger::log_round_start(i + 1);
    for (int j = 0; j < 3; ++j) {
      weapons[j]->attack();
    }
  }

  // TODO: Deallocate memory for weapons in slots properly
  for (int i = 0; i < 3; ++i) {
    delete weapons[i];
  }

  return 0;
}
