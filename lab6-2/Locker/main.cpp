#include "Locker.h"

int main() {
  Locker my_locker = Locker();

  while (true) {
    int action;
    cout << "What should I do?" << endl;

    if (!my_locker.get_is_open()) {
      cout << "1. Open the locker\n2. Lock the locker\n0. Exit program\nChoose: ";
      cin >> action;

      if (action == 1) {
        my_locker.open();
      } else if (action == 2) {
        my_locker.lock();
      } else if (action == 0) {
        cout << "Good bye." << endl;
        break;
      } else {
        cout << "Invalid option. Please choose 0, 1, or 2." << endl;
      }
    } else {
      cout << "1. Check the items in the locker\n2. Place the item in the locker\n";
      cout << "3. Take the item out of the locker\n4. Close the locker\n0. Exit program\nChoose: ";
      cin >> action;

      if (action == 1) {
        my_locker.check_item();
      } else if (action == 2) {
        my_locker.place_item();
      } else if (action == 3) {
        my_locker.remove_item();
      } else if (action == 4) {
        my_locker.close();
      } else if (action == 0) {
        cout << "Good bye." << endl;
        break;
      } else {
        cout << "Invalid option. Please choose 0, 1, 2, 3, or 4. " << endl;
      }
    }
    cout << "\n";
  }
  
  return 0;
}