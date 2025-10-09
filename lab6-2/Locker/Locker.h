#ifndef LOCKER_H
#define LOCKER_H

#include <iostream>
#include <string>
using namespace std;

class Locker {
  private:
    bool is_locked = false;
    bool is_open = false;
    string password;
    string items[4];
  
  public:
    Locker();
    void lock();
    void unlock();
    void open();
    void close();
    void check_item();
    void place_item();
    void remove_item();
    bool get_is_open();
};

#endif