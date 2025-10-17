#ifndef FEEDER_LOGGER_H
#define FEEDER_LOGGER_H

#include <iostream>
#include <string>

namespace FeederLogger {

inline void log_init(const std::string& component, int id) {
  std::cout << "[" << component << "] init  #" << id << "\n";
}

inline void log_stop(const std::string& component, int id) {
  std::cout << "[" << component << "] stop  #" << id << "\n";
}

inline void log_ready(const std::string& component, int id) {
  std::cout << "[" << component << "] ready #" << id << "\n";
}

inline void log_bye(const std::string& component, int id) {
  std::cout << "[" << component << "] bye   #" << id << "\n";
}

inline void log_cpu_stop_ok(int id) {
  std::cout << "[CPUCore ] stop  #" << id << "  (IOFeeder OK)\n";
}

inline void log_cpu_stop_error(int id) {
  std::cout << "[CPUCore ] stop  #" << id << "  **ERROR! IOFeeder gone**\n";
}

}  // namespace FeederLogger

#endif