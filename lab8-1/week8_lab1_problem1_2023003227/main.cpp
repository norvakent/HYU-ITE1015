#include <iostream>

class Member {
public:
  int idx;
  std::string first_name;
  std::string last_name;
  Member(int _id, std::string _first_name, std::string _last_name)
      : idx(_id), first_name(_first_name), last_name(_last_name) {};
  void show() {
    std::cout << idx << " id " << first_name << " " << last_name << std::endl;
  }
};

void swap_pointer(Member *p1, Member *p2) {
  Member p = *p1;
  *p1 = *p2;
  *p2 = p;
}

void swap_id(Member *p1, Member *p2) {
  int id = p1->idx;
  p1->idx = p2->idx;
  p2->idx = id;
}

void swap_name(Member *p1, Member *p2) {
  std::string first = p1->first_name;
  std::string last = p1->last_name;

  p1->first_name = p2->first_name;
  p1->last_name = p2->last_name;

  p2->first_name = first;
  p2->last_name = last;
}

void swap_first_last(Member *p1, Member *p2) { swap_name(p1, p2); }

void flip_name(Member *p) {
  std::string name = p->first_name;
  p->first_name = p->last_name;
  p->last_name = name;
}

void print_info(Member *p1, Member *p2, const std::string &header = "") {
  std::cout << "========= " << header << " =========" << std::endl;
  std::cout << "m1: ";
  p1->show();
  std::cout << "m2: ";
  p2->show();
}

int main() {
  Member *p1 = new Member(2017186453, "Hanyang", "Kim");
  Member *p2 = new Member(2024132542, "Seoul", "Lee");
  print_info(p1, p2, "Initial State");
  std::cout << p1 << " " << p2 << std::endl;

  swap_pointer(p1, p2);
  print_info(p1, p2, "After Pointer Swap");
  std::cout << p1 << " " << p2 << std::endl;

  swap_id(p1, p2);
  print_info(p1, p2, "After ID Swap");

  swap_first_last(p1, p2);
  print_info(p1, p2, "After First-Last Name Swap");

  flip_name(p1);
  print_info(p1, p2, "After Flipping First-Last Name of p1");

  delete p1, p2;
  return 0;
}