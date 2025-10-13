#include "Question.h"
#include <cstdlib>
#include <iostream>

Question::Question() {
  // TODO: Use this-> to initialize all member variables
  // left = 0, right = 0, op = '+', answer = 0, ready = false
  this->left = 0;
  this->right = 0;
  this->op = '+';
  this->answer = 0;
  this->ready = false;
}

void Question::generate() {
  // TODO: Generate random operands (0..9) using std::rand() % 10; assign to
  // left and right
  this->left = std::rand() % 10;
  this->right = std::rand() % 10;

  this->op = (std::rand() % 2 == 0) ? '+' : '-';

  // TODO: If operator is '+', answer is left + right
  this->answer = (this->op == '+') ? left + right : left - right;

  // TODO: If operator is '-', answer is left - right

  this->ready = true;
}

void Question::printQuestion() const {
  std::cout << this->left << " " << this->op << " " << this->right << " = ?"
            << std::endl;
}

bool Question::checkAnswer(int userAnswer) const {
  // TODO: Return true if userAnswer equals the correct answer
  if (answer == userAnswer)
    return true;
  return false;
}

bool Question::isReady() const {
  // TODO: Return whether the question is ready
  return ready;
}