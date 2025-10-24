#include "BookingLogger.h"
#include "Ticket.h"

class Train : public Ticket {
protected:
  int km_;

public:
  Train(std::string p, int km) : Ticket(p, 2000), km_(km) {}
  int price() override { return base_ + 120 * km_; }
  void print(int idx) override {
    BookingLogger::log_train_ticket(idx, passenger_, km_, Train::price());
  }
};

class Flight : public Ticket {
protected:
  int km_;
  int bag_;

public:
  Flight(std::string p, int km, int bag)
      : Ticket(p, 5000), km_(km), bag_(bag) {}
  int price() override { return base_ + 3 * bag_ + 300 * km_; }
  void print(int idx) override {
    BookingLogger::log_flight_ticket(idx, passenger_, km_, bag_,
                                     Flight::price());
  }
};
