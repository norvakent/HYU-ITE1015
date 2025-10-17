#include "RigLogger.h"

struct Block {
  int id;
  char hash[9];
};

class Component {
private:
  bool state;

public:
  Component() { state = false; }
  void enable() { state = true; }
  void disable() { state = false; }
  bool isOn() { return state; }
};

class PowerSupply : public Component {
private:
  int id;

public:
  PowerSupply(int n) : id(n) {
    // TODO: Enable the power supply and log its activation
    this->enable();
    RigLogger::log_psu_on(id);
  }
  ~PowerSupply() {
    // TODO: Disable the power supply and log its deactivation
    this->disable();
    RigLogger::log_psu_off(id);
  }
};

class CoolingFan : public Component {
private:
  int id;

public:
  CoolingFan(int n) : id(n) {
    // TODO: Enable the cooling fan and log its activation
    this->enable();
    RigLogger::log_fan_on(id);
  }
  ~CoolingFan() {
    // TODO: Disable the cooling fan and log its deactivation
    this->disable();
    RigLogger::log_fan_off(id);
  }
};

class GPUWorker : public Component {
private:
  int id;
  char *mem;
  CoolingFan *cooling_source_;

public:
  GPUWorker(int n, CoolingFan *source) : id(n), cooling_source_(source) {
    mem = new char[64];
    // TODO: Enable the GPU worker and log its activation
    this->enable();
    RigLogger::log_gpu_start(id);
  }
  ~GPUWorker() {
    /* TODO: Disable the GPU worker and log its deactivation
    Also, release the allocated memory
    */
    delete[] this->mem;
    this->disable();
    if (cooling_source_->isOn()) {
      RigLogger::log_gpu_stop_ok(id);
    } else {
      RigLogger::log_gpu_stop_meltdown(id);
    }
  }
  void mine(Block *b) {
    for (int i = 0; i < 8; i++)
      b->hash[i] = 'A' + (b->id + id + i) % 26;
    b->hash[8] = '\0';
    RigLogger::log_mine_success(b->id, b->hash);
  }
};

// TODO: Define SafeRig and BadRig classes
class SafeRig : public PowerSupply, public CoolingFan, public GPUWorker {
private:
  int pid;

public:
  SafeRig(int n) : pid(n), PowerSupply(n), CoolingFan(n), GPUWorker(n, this) {
    RigLogger::log_rig_ready("SafeRig", pid);
  };
  ~SafeRig() { RigLogger::log_rig_bye("SafeRig", pid); }
};

class BadRig : public GPUWorker, public CoolingFan, public PowerSupply {
private:
  int pid;

public:
  BadRig(int n) : pid(n), GPUWorker(n, this), CoolingFan(n), PowerSupply(n) {
    RigLogger::log_rig_ready("BadRig", pid);
  };
  ~BadRig() { RigLogger::log_rig_bye("BadRig", pid); }
};

#define MAX_RIG 8
class ClusterManager {
private:
  SafeRig *safeRigs[MAX_RIG];
  BadRig *badRigs[MAX_RIG];
  int rigTypes[MAX_RIG]; // 0: Empty slot, 1: SafeRig, 2: BadRig
  int used;              // Number of used slots

public:
  ClusterManager() : used(0) {
    for (int i = 0; i < MAX_RIG; i++) {
      // TODO: initialize pointers to nullptr
      safeRigs[i] = nullptr;
      badRigs[i] = nullptr;
    }
  }
  ~ClusterManager() { shutdownAll(); }

  void addRig(int mode, int idBase) {
    /* TODO
     1) Print warning if the slot is full and return
     2) Allocate a new rig:
      - if(mode==1) SafeRig;
      - else    BadRig;
     3) Set rigType[used] properly
     4) used++;
     */
    if (used >= 8) {
      RigLogger::log_slot_full();
      return;
    }
    if (mode == 1) {
      safeRigs[used] = new SafeRig(idBase);
      rigTypes[used] = 1;
    } else {
      badRigs[used] = new BadRig(idBase);
      rigTypes[used] = 2;
    }
    used++;
  }

  void mineAll(Block *pool, int count) {
    // TODO: Call mine on all rigs
    for (int i = 0; i < used; i++) {
      for (Block *j = pool; j < pool + 5; j++) {
        if (rigTypes[i] == 1) {
          safeRigs[i]->mine(j);
        } else if (rigTypes[i] == 2) {
          badRigs[i]->mine(j);
        }
      }
    }
  }

  void shutdownAll() {
    // TODO: Properly delete all rigs and reset used to 0
    for (int i = 0; i < used; i++) {
      if (rigTypes[i] == 1) {
        delete safeRigs[i];
      } else if (rigTypes[i] == 2) {
        delete badRigs[i];
      }
    }
    used = 0;
  }
};

/* ---------------------- Main ----------------------- */
int main() {
  int safe_id_counter = 100;
  int bad_id_counter = 200;

  Block pool[5];
  for (int i = 0; i < 5; i++) {
    pool[i].id = i + 1;
  }

  ClusterManager cm;

  int choice;
  while (true) {
    RigLogger::log_menu();
    std::cin >> choice;

    switch (choice) {
    case 1:
      cm.addRig(1, safe_id_counter++);
      break;
    case 2:
      cm.addRig(2, bad_id_counter++);
      break;
    case 3:
      cm.mineAll(pool, 5);
      break;
    case 4:
      cm.shutdownAll();
      break;
    case 0:
      cm.shutdownAll();
      return 0;
    default:
      RigLogger::log_invalid_input();
    }
  }
}
