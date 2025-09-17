#include <iostream>
using namespace std;

struct PhoneSettings{
  int resolution;
  int batteryPercent;
};

PhoneSettings previewResolution(PhoneSettings phone, int newValue) {
  phone.resolution = newValue;
  return phone;
}

void applyResolution(PhoneSettings* phone, int newValue) {
  phone->resolution = newValue;
}

void printSettings(PhoneSettings phone) {
  cout << "Resolution: " << phone.resolution << "p" << endl;
  cout << "Battery: " << phone.batteryPercent << "%" << endl;
  cout << "------------------------" << endl;
}

int main() {
  PhoneSettings myPhone = {1080, 85};

  cout << "=== Current Settings ===" << endl;
  printSettings(myPhone);

  cout << "\n=== Preview Mode ===" << endl;
  PhoneSettings preview = previewResolution(myPhone, 720);
  cout << "Preview: resolution => 720p" << endl;
  printSettings(preview);
  cout << "Original:" << endl;
  printSettings(myPhone);

  cout << "\n=== Apply Changes ===" << endl;
  applyResolution(&myPhone, 720);
  cout << "Applied: resolution => 720p" << endl;
  printSettings(myPhone);

  return 0;
}