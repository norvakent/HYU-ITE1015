#include <iostream>
using namespace std;

class Date {
private:
  int year, month, day;
  static int count;

public:
  Date(int y, int m, int d) : year(y), month(m), day(d) { count++; }

  // TODO
  Date operator+(int day) const {
    int days = toSerial(*this);
    return fromSerial(days + day);
  }

  // TODO
  int operator-(const Date &other) const {
    int diff = diffDays(*this, other);
    return diff < 0 ? -diff : diff;
  }

  // TODO
  bool operator<(const Date &other) const {
    if (year < other.year) {
      if (month < other.month) {
        if (day < other.day) {
          return true;
        }
        return false;
      }
      return false;
    }
    return false;
  }

  // TODO
  bool operator>(const Date &other) const {
    if (year > other.year) {
      if (month > other.month) {
        if (day > other.day) {
          return true;
        }
        return false;
      }
      return false;
    }
    return false;
  }
  // TODO
  bool operator==(const Date &other) const {
    return year == other.year && month == other.month && day == other.day;
  }

  // TODO
  static int getCount() { return count; }

  void show() const { cout << year << "/" << month << "/" << day; }

  bool isLeap(int y) const {
    if (y % 400 == 0)
      return true;
    if (y % 100 == 0)
      return false;
    if (y % 4 == 0)
      return true;
    return false;
  }

  int toSerial(const Date &date) const {
    static const int cumMonth[13] = {0,   0,   31,  59,  90,  120, 151,
                                     181, 212, 243, 273, 304, 334};
    int y = date.year;
    int m = date.month;
    int d = date.day;

    int y1 = (y - 1) - 1600;

    int daysYears = y1 * 365;
    for (int i = 1601; i < y; i++) {
      if (isLeap(i))
        daysYears++;
    }

    int daysMonths = cumMonth[m] + ((isLeap(y) && m > 2) ? 1 : 0);

    return daysYears + daysMonths + d - 1;
  }

  Date fromSerial(int days) const {
    if (days < 0)
      return Date(0, 0, 0);

    const int D400 = 146097;
    const int D100 = 36524;
    const int D4 = 1461;
    const int D1 = 365;

    int cycles400 = days / D400;
    int remaining = days % D400;

    int cycles100 = remaining / D100;
    if (cycles100 == 4)
      cycles100 = 3;
    remaining -= cycles100 * D100;

    int cycles4 = remaining / D4;
    remaining -= cycles4 * D4;

    int singleYears = remaining / D1;
    if (singleYears == 4)
      singleYears = 3;
    remaining -= singleYears * D1;

    int year =
        1601 + 400 * cycles400 + 100 * cycles100 + 4 * cycles4 + singleYears;

    int month = 1;
    while (true) {
      int daysInThisMonth = daysInMonth(year, month);

      if (remaining < daysInThisMonth)
        break;
      remaining -= daysInThisMonth;
      month++;
    }

    int day = remaining + 1;

    return Date(year, month, day);
  }

  int daysInMonth(int y, int m) const {
    static const int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m < 1 || m > 12)
      return 0;

    if (isLeap(y) && m == 2)
      return 29;

    return md[m - 1];
  }

  int diffDays(const Date &date1, const Date &date2) const {
    return toSerial(date2) - toSerial(date1);
  }

  friend ostream &operator<<(ostream &os, const Date &d);
};

ostream &operator<<(ostream &os, const Date &d) {
  os << d.year << "/" << d.month << "/" << d.day;
  return os;
}

int Date::count = 0;

int main() {
  Date d1(2025, 7, 26);
  Date d2(2024, 2, 29);
  Date d3(2023, 3, 9);

  cout << "d1 < d2  : ";
  if (d1 < d2)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  cout << "d1 > d3  : ";
  if (d1 > d3)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  cout << "d2 - d1  : " << (d2 - d1) << " days" << endl;

  cout << "d1 == d2 : ";
  if (d1 == d2)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  cout << "d1 + 45 : " << (d1 + 45) << endl;
  ;

  cout << "d2 + (-77) : " << (d2 + (-77)) << endl;

  cout << "count of dates  : " << Date::getCount() << endl;

  return 0;
}