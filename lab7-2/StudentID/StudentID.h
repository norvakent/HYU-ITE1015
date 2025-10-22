#ifndef STUDENTID_H
#define STUDENTID_H

#include "BasicCard.h"
#include "MagStripeDevice.h"
#include "RFIDDevice.h"

class StudentID : public BasicCard, public MagStripeDevice, public RFIDDevice {
public:
  StudentID(std::string cardNo, std::string owner)
      : BasicCard(owner), MagStripeDevice(cardNo), RFIDDevice(cardNo) {};

  void testAll() {
    showOwner();
    swipe();
    scan();
  }
};

#endif