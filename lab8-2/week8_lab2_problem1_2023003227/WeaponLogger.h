#ifndef WEAPON_LOGGER_H
#define WEAPON_LOGGER_H

#include <iostream>
#include <string>

namespace WeaponLogger {

// --- UI & Prompts ---
inline void log_prompt_weapon_types() {
  std::cout << "Enter weapon types (S = Sword, B = Bow, T = Staff)\n";
}
inline void log_prompt_slot(int slot_num) {
  std::cout << "Slot " << slot_num << ": ";
}
inline void log_prompt_rounds() { std::cout << "\nHow many attack rounds? "; }

// --- Status & Headers ---
inline void log_header_weapons_in_slots() {
  std::cout << "\n[Weapons in slots]\n";
}
inline void log_weapon_in_slot(int slot_num, const std::string& kind) {
  std::cout << "Slot " << slot_num << ": " << kind << "\n";
}
inline void log_header_attack_before_swap() {
  std::cout << "\n[Attack before swapping]\n";
}
inline void log_header_attack_after_swap() {
  std::cout << "\n[Attack after swapping]\n";
}
inline void log_round_start(int round_num) {
  std::cout << "Round " << round_num << ":\n";
}

// --- Attack Logs ---
inline void log_sword_slash(int sharpness) {
  std::cout << "Slash! [sharpness=" << sharpness << "]\n";
}
inline void log_bow_shoot(int arrows) {
  std::cout << "Shoot! [# of arrows=" << arrows << "]\n";
}
inline void log_staff_cast(int mana) {
  std::cout << "Cast! [mana=" << mana << "]\n";
}

// --- Failure & Error Logs ---
inline void log_sword_dull() { std::cout << "Sword is dull!\n"; }
inline void log_bow_no_arrows() { std::cout << "No arrows left!\n"; }
inline void log_staff_no_mana() { std::cout << "Not enough mana!\n"; }
inline void log_error_invalid_input() {
  std::cout << "  → Invalid input! Please try again.\n";
}
inline void log_error_invalid_rounds() {
  std::cout << "Invalid number of rounds! Defaulting to 1.\n";
}
inline void log_error_invalid_weapon_type() {
  std::cout << "Invalid weapon type!\n";
}

}

#endif