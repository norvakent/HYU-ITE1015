#include <iostream>
#include <string>

struct Department {
  std::string name;
};

struct Employee {
  int id;
  std::string name;
  int salary;
  Department dept;
};

Employee *findEmployeeById(Employee employees[], int size, int targetId) {
  for (int i = 0; i < size; i++) {
    if (employees[i].id == targetId) return employees + i;
  }
  return nullptr;
}

void giveRaise(Employee &employee, int percentage) {
  employee.salary += employee.salary * percentage / 100;
}

double calculateAverageSalary(std::string deptName, Employee employees[], int size) {
  double avg = 0;
  int dept_cnt = 0;
  for (int i = 0; i < size; i++) {
    if (employees[i].dept.name == deptName) avg += employees[i].salary;
    dept_cnt++;
  }
  avg /= dept_cnt;
  return avg;
}

int main() {
  const int NUM_EMPLOYEES = 5;

  Employee* employees = new Employee[NUM_EMPLOYEES];

  employees[0] = {101, "Alice", 8000, {"Sales"}};
  employees[1] = {202, "Bob", 9500, {"Engineering"}};
  employees[2] = {303, "Charlie", 7200, {"Sales"}};
  employees[3] = {404, "David", 11000, {"Engineering"}};
  employees[4] = {505, "Eve", 12500, {"Engineering"}};

  std::string command;

  while (std::cin >> command) {
    if (command == "raise") {
      int targetId, percentage;
      std::cin >> targetId >> percentage;
      Employee *found = findEmployeeById(employees, NUM_EMPLOYEES, targetId);
      if (found == nullptr) {
        std::cout << "Employee with ID " << targetId << " not found."
                  << std::endl;
      } else {
        int oldSalary = found->salary;
        giveRaise(*found, percentage);
        std::cout << found->name << " (Dept: " << found->dept.name << ")"
                  << " | Salary updated: " << oldSalary << " -> "
                  << found->salary << std::endl;
      }
    } else if (command == "avg_salary") {
      std::string deptName;
      std::cin >> deptName;
      double average =
          calculateAverageSalary(deptName, employees, NUM_EMPLOYEES);
      if (average == 0.0) {
        std::cout << "Department '" << deptName
                  << "' not found or has no employees." << std::endl;
      } else {
        std::cout << "Average salary for " << deptName << ": "
                  << static_cast<int>(average) << std::endl;
      }
    }
  }

  delete[] employees;

  return 0;
}