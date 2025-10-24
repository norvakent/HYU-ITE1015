#ifndef TICKET_H
#define TICKET_H
#include <iostream>

class Ticket {
protected:
  std::string passenger_;
  int base_;

public:
  Ticket(std::string p, int b) : passenger_(p), base_(b) {}
  virtual ~Ticket() {}
  virtual int price() = 0;
  virtual void print(int idx) = 0;
};

#endif