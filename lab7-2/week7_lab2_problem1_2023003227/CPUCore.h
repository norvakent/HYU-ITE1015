#ifndef CPUCORE_H
#define CPUCORE_H

#include "FeederLogger.h"
#include "IOFeeder.h"
#include <iostream>

class CpuCore {
private:
  int id;
  IOFeeder *source_;

public:
  CpuCore(int n, IOFeeder *source) : id(n), source_(source) {
    FeederLogger::log_init("CPUCore ", id);
  }
  ~CpuCore() {
    if (source_->is_activate()) {
      FeederLogger::log_cpu_stop_ok(id);
    } else {
      FeederLogger::log_cpu_stop_error(id);
    }
  }
};

#endif
