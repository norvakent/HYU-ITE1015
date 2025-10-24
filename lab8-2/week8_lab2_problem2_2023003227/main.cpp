#include "BookingLogger.h"
#include "BookingMgr.h"
#include "Vehicles.h"

Ticket *makeTicket(char type) {
  // TODO: Implement makeTicket function properly
  std::string name;
  int km, bag;
  std::cout << "  ";
  switch (type) {
  case ('T'):
  case ('t'):
    BookingLogger::log_prompt_train_details();
    std::cin >> name >> km;
    return new Train(name, km);
  case ('F'):
  case ('f'):
    BookingLogger::log_prompt_flight_details();
    std::cin >> name >> km >> bag;
    return new Flight(name, km, bag);
  default:
    return nullptr;
  }
}

int main() {
  int N;
  BookingLogger::log_prompt_num_tickets();
  while (!(std::cin >> N) || N < 1 || N > 5) {
    BookingLogger::log_error_invalid_number();
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  BookingMgr bm;

  for (int i = 0; i < N; ++i) {
    char kind;
    BookingLogger::log_prompt_ticket_type(i + 1, N);
    while (true) {
      std::cin >> kind;
      if (kind == 'T' || kind == 't' || kind == 'F' || kind == 'f')
        break;
      BookingLogger::log_error_invalid_type();
    }

    Ticket *t = makeTicket(kind);
    bm.add(t);
  }

  BookingLogger::log_header_summary();
  bm.summary();
  return 0;
}