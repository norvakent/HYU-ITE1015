#ifndef STUDENT_LOGGER_H
#define STUDENT_LOGGER_H

#include <iostream>
#include <string>

namespace StudentLogger {

inline void prompt_num_classes() { std::cout << "Number of classes: "; }

inline void prompt_num_students_per_class() {
  std::cout << "Number of students for each class: ";
}

inline void prompt_student_name(int class_num, int student_order) {
  std::string order_suffix;
  if (student_order == 1)
    order_suffix = "st";
  else if (student_order == 2)
    order_suffix = "nd";
  else if (student_order == 3)
    order_suffix = "rd";
  else
    order_suffix = "th";

  std::cout << "Class " << class_num << "'s " << student_order << order_suffix
            << " student name: ";
}

inline void prompt_subject_score(const std::string& student_name,
                                 int subject_num) {
  std::cout << student_name << "'s subject " << subject_num << " score: ";
}

inline void print_top_student(int class_num, const std::string& name,
                              float avg) {
  std::cout << "\nClass " << class_num << " top student: " << name
            << ", avg: " << avg << std::endl;
}

inline void print_sorted_list_header(int subject_idx) {
  std::cout << "\n[Subject " << (subject_idx + 1)
            << " scores in ascending order (All classes)]\n";
}

inline void print_sorted_student(const std::string& name, float score) {
  std::cout << name << ": " << score << '\n';
}

}

#endif