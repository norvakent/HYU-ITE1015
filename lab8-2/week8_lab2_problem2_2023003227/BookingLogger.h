#ifndef BOOKING_LOGGER_H
#define BOOKING_LOGGER_H

#include <iostream>
#include <string>

namespace BookingLogger {

// --- UI & Prompts ---
inline void log_prompt_num_tickets() {
  std::cout << "Enter the number of tickets to book (1-5): ";
}
inline void log_prompt_ticket_type(int current_num, int total_num) {
  std::cout << "\n[" << current_num << "/" << total_num << "] "
            << "Enter ticket type (T = Train, F = Flight): ";
}
inline void log_prompt_train_details() {
  std::cout << "Enter passenger name and distance (km): ";
}
inline void log_prompt_flight_details() {
  std::cout << "Enter passenger name, distance (km), and baggage weight (kg): ";
}

// --- Error Logs ---
inline void log_error_invalid_number() {
  std::cout << "Invalid number! Please enter an integer between 1 and 5: ";
}
inline void log_error_invalid_type() {
  std::cout << "Please enter only 'T' or 'F': ";
}

// --- Header summary ---
inline void log_header_summary() {
  std::cout << "\n===== Booking Summary =====\n";
}

// --- Ticket Printing ---
inline void log_train_ticket(int idx, const std::string& passenger, int km,
                             int price) {
  std::cout << "Ticket #" << idx << " | Train | " << passenger << " | " << km
            << "km | " << price << '\n';
}
inline void log_flight_ticket(int idx, const std::string& passenger, int km,
                              int bag, int price) {
  std::cout << "Ticket #" << idx << " | Flight | " << passenger << " | " << km
            << "km | Bag " << bag << "kg | " << price << '\n';
}

// --- Summary & Status ---
inline void log_total_price(int total) {
  std::cout << "Total : " << total << '\n';
}
} 

#endif 