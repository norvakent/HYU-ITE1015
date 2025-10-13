#include "Locker.h"

Locker::Locker() {
  string password;
  cout << "Please set a new password : ";
  cin >> password;
  this->password = password;
  is_locked = true;

  for (int i = 0; i < 4; i++) {
    items[i] = "";
  }

  cout << "\n";
}

void Locker::lock() {
  if (is_open) {
    cout << "Cannot lock an open locker. Please close it first." << endl;
    return;
  }

  if (!is_locked) {
    is_locked = true;
    cout << "The locker has been locked." << endl;
  } else {
    cout << "The locker is already locked." << endl;
  }
}

void Locker::unlock() {
  is_locked = false;
  cout << "The locker has been unlocked." << endl;
}

void Locker::open() {
  if (is_open) {
    cout << "The locker is already open." << endl;
    return;
  }

  string password;
  if (is_locked) {
    cout << "The locker is locked. \nPlease enter the password.\npassword: ";
    cin >> password;

    if (password == this->password) {
      unlock();
    } else {
      cout << "The password is incorrect." << endl;
      return;
    }
  }
  is_open = true;
  cout << "The locker is now open." << endl;
}

void Locker::close() {
  if (!is_open) {
    cout << "The locker is already closed." << endl;
    return;
  }
  is_open = false;
  cout << "The locker is now closed." << endl;
}

void Locker::check_item() {
  bool empty = true;
  cout << "========================" << endl;
  for (int i = 0; i < 4; i++) {
    if (!this->items[i].empty()) {
      cout << items[i] << endl;
      empty = false;
    }
  }
  if (empty) {
    cout << "The locker is empty." << endl;
  }
  cout << "========================" << endl;
}

void Locker::place_item() {
  string item;

  cout << "Item : ";
  cin >> item;

  int i;
  for (i = 0; i < 4; i++) {
    if (this->items[i].empty()) {
      items[i] = item;
      cout << "Now " << item << " is in locker." << endl;
      return;
    }
  }
  cout << "The locker is full. Cannot place " << item << ".\n";
}

void Locker::remove_item() {
  string item;

  cout << "Item : ";
  cin >> item;

  for (int i = 0; i < 4; i++) {
    if (items[i] == item) {
      items[i] = "";
      cout << "Now " << item << " is out of locker." << endl;
      return;
    }
  }
  cout << "There is no " << item << " in the locker." << endl;
}

bool Locker::get_is_open() { return this->is_open; }
