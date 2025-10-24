#include "BookingLogger.h"
#include "Ticket.h"

class BookingMgr {
private:
  Ticket *tickets_[5];
  int n_;

public:
  BookingMgr() : n_(0) {}
  ~BookingMgr() {
    for (int i = 0; i < n_; ++i) {
      delete tickets_[i];
    }
  }
  bool add(Ticket *t) {
    if (n_ >= 5) {
      return false;
    }
    tickets_[n_++] = t;
    return true;
  }
  void summary() {
    int total = 0;
    for (int i = 0; i < n_; ++i) {
      tickets_[i]->print(i);
      total += tickets_[i]->price();
    }
    BookingLogger::log_total_price(total);
  }
};