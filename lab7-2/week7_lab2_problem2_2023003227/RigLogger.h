#ifndef RIG_LOGGER_H
#define RIG_LOGGER_H

#include <iostream>
#include <string>

namespace RigLogger {

// --- Component Lifecycle Logs ---
inline void log_psu_on(int id) { std::cout << "[PSU]  ON  #" << id << "\n"; }
inline void log_psu_off(int id) { std::cout << "[PSU]  OFF #" << id << "\n"; }
inline void log_fan_on(int id) { std::cout << "[FAN]  ON  #" << id << "\n"; }
inline void log_fan_off(int id) { std::cout << "[FAN]  OFF #" << id << "\n"; }
inline void log_gpu_start(int id) {
  std::cout << "[GPU]  start #" << id << "\n";
}
inline void log_gpu_stop_ok(int id) {
  std::cout << "[GPU]  stop  #" << id << " (cooling OK)\n";
}
inline void log_gpu_stop_meltdown(int id) {
  std::cout << "[GPU]  stop  #" << id << " **MELTDOWN!**\n";
}

// --- Rig Lifecycle Logs ---
inline void log_rig_ready(const std::string& rig_type, int id) {
  std::cout << "[" << rig_type << "] ready #" << id << "\n";
}
inline void log_rig_bye(const std::string& rig_type, int id) {
  std::cout << "[" << rig_type << "] bye   #" << id << "\n";
}

// --- Operation Logs ---
inline void log_mine_success(int block_id, const char* hash) {
  std::cout << "    ▸ mined Block#" << block_id << " : " << hash << "\n";
}

// --- UI & System Logs ---
inline void log_slot_full() { std::cout << "slot full\n"; }
inline void log_menu() {
  std::cout << "\n=== MENU ===\n"
            << "1) Add SafeRig\n2) Add BadRig\n"
            << "3) Mine 5 blocks\n4) Shutdown ALL\n0) Exit\n> ";
}
inline void log_invalid_input() { std::cout << "Invalid input!\n"; }

}  // namespace RigLogger

#endif  // RIG_LOGGER_H
