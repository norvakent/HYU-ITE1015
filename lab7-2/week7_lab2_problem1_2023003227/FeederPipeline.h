#ifndef FEEDERPIPELINE_H
#define FEEDERPIPELINE_H

#include "CPUCore.h"
#include "FeederLogger.h"
#include "IOFeeder.h"

class CorrectFeeder : IOFeeder, CpuCore {
private:
  int pid;

public:
  CorrectFeeder(int n) : pid(n), IOFeeder(n), CpuCore(n, this) {
    FeederLogger::log_ready("CorrectFeeder", pid);
  }
  ~CorrectFeeder() { FeederLogger::log_bye("CorrectFeeder", pid); }
};

class IncorrectFeeder : CpuCore, IOFeeder {
private:
  int pid;

public:
  IncorrectFeeder(int n) : pid(n), CpuCore(n, this), IOFeeder(n) {
    FeederLogger::log_ready("IncorrectFeeder", pid);
  }
  ~IncorrectFeeder() { FeederLogger::log_bye("IncorrectFeeder", pid); }
};

#endif