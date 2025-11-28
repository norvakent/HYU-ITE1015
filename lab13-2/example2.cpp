#include <iostream>
#include <vector>
using namespace std;

struct DailyTemp {
  int high;
  int low;
};

int main() {
  vector<DailyTemp> temperatures = {{21, 10}, {19, 10}, {19, 8}, {17, 10},
                                    {20, 12}, {20, 13}, {12, 9}};

  cout << "Average maximum and minimum temperatures over 3-day intervals:"
       << endl;

  double highMean;
  double lowMean;
  int cnt = 1;
  for (auto it = temperatures.begin(); it != temperatures.end() - 2; it++) {
    highMean = ((*it).high + (*(it + 1)).high + (*(it + 2)).high) / 3.0;
    lowMean = ((*it).low + (*(it + 1)).low + (*(it + 2)).low) / 3.0;
    cout.precision(3);
    cout << "Days " << cnt << "-" << cnt + 2 << ": High " << highMean
         << " degree celsius, Low " << lowMean << " degree celsius" << endl;
    cnt++;
  }

  return 0;
}