#ifndef MAGSTRIPEDEVICE_H
#define MAGSTRIPEDEVICE_H

#include <iostream>

#include "RFIDDevice.h"

class MagStripeDevice {
protected:
  std::string cardNo_;

public:
  MagStripeDevice(std::string cardNo) : cardNo_(cardNo) {};
  void swipe() { std::cout << "Magstripe OK: " << cardNo_ << std::endl; }
};

#endif
