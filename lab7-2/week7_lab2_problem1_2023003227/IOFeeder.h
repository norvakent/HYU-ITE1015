#ifndef IOFEEDER_H
#define IOFEEDER_H

#include "FeederLogger.h"
#include <iostream>

class IOFeeder {
private:
  int id;
  bool is_activate_;

public:
  IOFeeder(int n) : id(n), is_activate_(true) {
    FeederLogger::log_init("IOFeeder", id);
  }
  ~IOFeeder() {
    is_activate_ = false;
    FeederLogger::log_stop("IOFeeder", id);
  }
  bool is_activate() { return is_activate_; }
};

#endif