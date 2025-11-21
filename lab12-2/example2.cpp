#include <iostream>
using namespace std;

template <typename T, typename U> class DigitManagement {
private:
  T thousand;
  U million;
  int total;

public:
  DigitManagement(T _thousand, U _million)
      : thousand(_thousand), million(_million), total(0) {}

  friend DigitManagement operator+(const DigitManagement &a,
                                   const DigitManagement &b) {
    T sumThousand = a.thousand + b.thousand;
    return DigitManagement(
        sumThousand % 1000,
        (sumThousand >= 1000 ? (((int)sumThousand) / 1000) : 0) + a.million +
            b.million);
  }

  void setTotal() { total = thousand * 1000 + million * 1000000; }

  void showTotal() {
    setTotal();
    cout << thousand << " * 1K + " << million << " * 1M = " << total << endl;
  }
};

int main() {
  DigitManagement<int, double> dm1(400, 0.01);
  DigitManagement<int, double> dm2(700, 0.01);
  (dm1 + dm2).showTotal();

  DigitManagement<int, int> dm4(100, 2);
  DigitManagement<int, int> dm5(200, 1);
  (dm4 + dm5).showTotal();
}