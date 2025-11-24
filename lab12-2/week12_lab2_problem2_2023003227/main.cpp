#include <iostream>
#include <string>

using namespace std;

template <typename T> class BaseArray {
protected:
  T *m_data;
  int m_size;
  int m_capacity;

public:
  BaseArray() {
    m_capacity = 10;
    m_size = 0;
    m_data = new T[m_capacity];
  }

  virtual ~BaseArray() {
    if (m_data != nullptr) {
      delete[] m_data;
      m_data = nullptr;
    }
  }

  // TODO 1. Implement push_back
  void push_back(T item) {
    if (m_size >= m_capacity) {
      this->resize();
    }
    m_data[m_size++] = item;
  }

  // TODO 2. Implement at
  T &at(int p) { return m_data[p]; }

  // TODO 3. Implement getSize
  int getSize() const { return m_size; }

private:
  // TODO 4. Implement resize
  void resize() {
    m_capacity *= 2;
    T *newData = new T[m_capacity];
    for (int i = 0; i < m_size; i++) {
      newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
  }
};

template <typename T> class StatArray : public BaseArray<T> {
public:
  StatArray() : BaseArray<T>() {}

  // TODO 5. Implement getSum
  T getSum() {
    T sum = 0;
    for (int i = 0; i < this->m_size; i++) {
      sum += this->m_data[i];
    }
    return sum;
  }

  // TODO 6. Implement getAverage
  double getAverage() { return getSum() / this->m_size; }
};

template <> class StatArray<string> : public BaseArray<string> {
public:
  StatArray() : BaseArray<string>() {}

  // TODO 7. Implement getSum
  string getSum() {
    string concated = "";
    for (int i = 0; i < m_size; i++) {
      concated += m_data[i];
    }
    return concated;
  }

  // TODO 8. Implement getAverage
  double getAverage() {
    double sum = 0;
    for (int i = 0; i < m_size; i++) {
      sum += m_data[i].length();
    }
    return sum / m_size;
  }
};

int main() {
  StatArray<int> intStats;

  for (int i = 1; i <= 12; ++i) {
    intStats.push_back(i * 10);
  }

  cout << "--- Integer Stats (10...120) ---" << endl;
  cout << "Size: " << intStats.getSize() << endl;
  cout << "Item at index 5: " << intStats.at(5) << endl;
  cout << "Sum: " << intStats.getSum() << endl;
  cout << "Average: " << intStats.getAverage() << endl;

  StatArray<string> strStats;
  strStats.push_back("C++");
  strStats.push_back("Java");
  strStats.push_back("Python");
  strStats.push_back("Rust");

  cout << "\n--- String Stats ---" << endl;
  cout << "Size: " << strStats.getSize() << endl;
  cout << "Item at index 2: " << strStats.at(2) << endl;

  cout << "Sum (Concat): " << strStats.getSum() << endl;

  cout << "Average (Length): " << strStats.getAverage() << endl;

  return 0;
}