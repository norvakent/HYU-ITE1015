#include <iostream>
#include <string>
using namespace std;

struct Book
{
  private:
  string name_;
  string author_;
  int year_;
  double price_;

  public:
  void init() { name_ = "Empty";}

  void set_info(string name, string author, int year, double price)
  {
    name_ = name;
    author_ = author;
    year_ = year;
    price_ = price;
  }
  string get_name() { return name_;}  
  void show()
  {
    if (name_ == "Empty")
    {
      cout << "\tEmpty\tEmpty\tEmpty\tEmpty" << endl;
    }
    else
    {
      cout << "\t" << name_ << "\t" << author_ << "\t" << year_ << "\t" << price_ << endl;
    }
  }
};

int main()
{
  int MAX_LENGTH = 5;

  Book books[MAX_LENGTH];
  string cmd, name, author;

  int year;
  double price;
  int num = 0;

  for (int i = 0; i < MAX_LENGTH; i++) {
    books[i].init();
  }

  int index = 0;
  while (1)
  {
    cout << "[User Input] Enter command (register, show): ";
    cin >> cmd;

    int flag = 0;
    if (cmd == "register")
    {
      if (index == 5)
      {
        cout << "No more empty space\n"
        << endl;
        continue;
      }
      cout << "[User Input] Type Name: ";
      cin >> name;
      cout << "[User Input] Type Author: ";
      cin >> author;
      cout << "[User Input] Type Year: ";
      cin >> year;
      cout << "[User Input] Type Price: ";
      cin >> price;
      books[index].set_info(name, author, year, price);
      index += 1;
      cout << name << " registration has been completed." << endl;
    }
    else if (cmd == "show")
    {
      cout << "Index\tName\tAuthor\tYear\tPrice" << endl;
      for (int i = 0; i < 5; i++)
      {
        cout << i;
        books[i].show();
      }
    }
    cout << "\n";
  }
  return 0;
}