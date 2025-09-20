#include <iostream>
#include <string>

namespace DeviceManager
{
  using namespace std;
  const string BASE_URL = "https://my.web.com";
  const string ERROR_MSG = "Error: Device model and ratio cannot be empty!";

  struct Device
  {
    string model;
    string ratio;
  };

  namespace iOS {
    namespace Apple {
      string showPage(Device* device, bool dark, string lang) {
        return (device->model.size() && device->ratio.size()) ? 
        BASE_URL + "/ios/apple/" + device->model + "?dark=" + (to_string(dark?1:0)) + "&ratio=" + device->ratio + "&lang=" + lang :
        "Error: Device model and ratio cannot be empty!";
      }
    }
  }

  namespace Android {
    namespace Samsung {
      string showPage(Device* device, bool dark, string lang) {
        return (device->model.size() && device->ratio.size()) ? 
        BASE_URL + "/android/samsung/" + device->model + "?dark=" + (to_string(dark?1:0)) + "&ratio=" + device->ratio + "&lang=" + lang :
        "Error: Device model and ratio cannot be empty!";
      }
    }
    namespace Google {
      string showPage(Device* device, bool dark, string lang) {
        return (device->model.size() && device->ratio.size()) ? 
        BASE_URL + "/android/google/" + device->model + "?dark=" + (to_string(dark?1:0)) + "&ratio=" + device->ratio + "&lang=" + lang :
        "Error: Device model and ratio cannot be empty!";
      }
    }
  }
}

int main()
{
  using namespace DeviceManager;

  Device iphone17{"iphone16pro", "21:9"};
  Device empty{"", ""};
  Device galaxyS26{"galaxyS25", "20:9"};
  Device pixel10{"pixel9", "19:9"};

  cout << iOS::Apple::showPage(&iphone17, false, "en") << endl;
  cout << Android::Samsung::showPage(&galaxyS26, true, "en") << endl;
  cout << Android::Google::showPage(&pixel10, true, "ko") << endl;
  cout << iOS::Apple::showPage(&empty, false, "en") << endl;

  return 0;
}