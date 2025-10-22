#ifndef RFIDDEVICE_H
#define RFIDDEVICE_H

#include <string>

#include "MagStripeDevice.h"

class RFIDDevice {
protected:
  std::string cardNo_;

public:
  RFIDDevice(std::string cardNo) : cardNo_(cardNo) {};
  void scan() { std::cout << "RFID OK: " << cardNo_ << std::endl; }
};

#endif