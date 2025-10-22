using namespace std;
#include "StudentLogger.h"

class Student {
private:
  // TODO
  string name;
  float scores[2];

public:
  Student() {
    // TODO: Initialize member variables with appropriate default values.
    name = "";
    scores[0] = 0.0;
    scores[1] = 0.0;
  }

  void set_name(string new_name) {
    // TODO
    name = new_name;
  }
  void set_score(int subject_idx, int score) {
    // TODO
    scores[subject_idx] = score;
  }

  string get_name() const { return name; }

  float get_score(int subject_idx) const {
    if (subject_idx >= 0 && subject_idx < 2) {
      return scores[subject_idx];
    }
    return -1;
  }

  float get_average() {
    // TODO: Calculate and return the average score of the two subjects.
    return (scores[0] + scores[1]) / 2;
  }
};

/**
 * @brief Sorts and prints all students (from the 2D array) in ascending order
 * based on a specific subject's score.
 * @param students (Student**): The 2D array of students.
 * @param rows (int): The number of classes.
 * @param cols (int): The number of students per class.
 * @param subject_idx (int): The subject index (0 or 1) to sort by.
 */
void sort_by_subject(Student **students, int rows, int cols, int subject_idx) {
  int total = rows * cols;

  // TODO: Create a dynamic array and sort all students based on the score of
  Student *all = new Student[total];

  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++)
      all[i * rows + j] = students[i][j];
  }

  Student temp;
  for (i = 0; i < total; i++) {
    int min_idx = i;
    for (j = i + 1; j < total; j++) {
      if (all[min_idx].get_score(subject_idx) > all[j].get_score(subject_idx)) {
        min_idx = j;
      }
    }
    temp = all[i];
    all[i] = all[min_idx];
    all[min_idx] = temp;
  }

  // --- Print Sorted List (No modification needed) ---
  StudentLogger::print_sorted_list_header(subject_idx);
  for (int i = 0; i < total; i++) {
    StudentLogger::print_sorted_student(all[i].get_name(),
                                        all[i].get_score(subject_idx));
  }

  // TODO: Deallocate the dynamic array properly.
  delete[] all;
}

int main() {
  int rows;
  int cols;

  // --- Standard Input (No modification needed) ---
  StudentLogger::prompt_num_classes();
  std::cin >> rows;
  StudentLogger::prompt_num_students_per_class();
  std::cin >> cols;
  std::cout << std::endl;

  // --- 2D Dynamic Array Allocation (No modification needed) ---
  Student **students = new Student *[rows];
  for (int i = 0; i < rows; i++) {
    students[i] = new Student[cols];
  }

  // --- Student Information Input (TODOs included) ---
  string name_input;
  float score_input;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      StudentLogger::prompt_student_name(i + 1, j + 1);
      std::cin >> name_input;

      // TODO: Set the name (name_input) for the students.
      students[i][j].set_name(name_input);

      for (int k = 0; k < 2; k++) {
        // TODO: Get the name from the students object for logging.
        StudentLogger::prompt_subject_score(students[i][j].get_name(), k + 1);

        std::cin >> score_input;

        // TODO: Set the score (score_input) for the students.
        students[i][j].set_score(k, score_input);
      }
    }
    std::cout << std::endl;
  }

  // --- Find Top Student (TODOs included) ---
  for (int i = 0; i < rows; i++) {
    Student topStudent;
    float highestAvg = -1.0;

    for (int j = 0; j < cols; j++) {
      // TODO: Get the average score for the current student
      float avg = students[i][j].get_average(); // TODO;

      if (avg > highestAvg) {
        highestAvg = avg;
        topStudent = students[i][j];
      }
    }

    // TODO: Get the name from the 'topStudent' object and pass it to the logger
    // function.
    StudentLogger::print_top_student(i + 1, topStudent.get_name(),
                                     topStudent.get_average());
  }

  // --- Sort by Subject (No modification needed) ---
  for (int subject = 0; subject < 2; subject++) {
    sort_by_subject(students, rows, cols, subject);
  }

  // TODO: Deallocate the 2D dynamic array properly.
  for (int i = 0; i < rows; i++) {
    delete[] students[i];
  }
  delete[] students;

  return 0;
}