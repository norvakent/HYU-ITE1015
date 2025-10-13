#include "Player.h"
#include <iostream>

Player::Player() {
  // TODO: Use this-> to initialize all member variables
  // name = "", questions = nullptr, questionCount = 0, questionCapacity = 2
  // correct = 0, total = 0, pendingQuestionIndex = -1
  this->name = "";
  this->questions = nullptr;
  this->questionCount = 0;
  this->questionCapacity = 2;
  this->correct = 0;
  this->total = 0;
  this->pendingQuestionIndex = -1;

  // TODO: Allocate memory for questions array with initial capacity
  this->questions = new Question[questionCapacity];
}

Player::Player(std::string name) {
  // TODO: Use this-> to assign parameter to member variable
  this->name = name;

  // TODO: Initialize other member variables using this->
  // questions = nullptr, questionCount = 0, questionCapacity = 2
  // correct = 0, total = 0, pendingQuestionIndex = -1
  this->questions = nullptr;
  this->questionCount = 0;
  this->questionCapacity = 2;
  this->correct = 0;
  this->total = 0;
  this->pendingQuestionIndex = -1;

  // TODO: Allocate memory for questions array with initial capacity
  this->questions = new Question[questionCapacity];
}

Player::~Player() {
  // TODO: Deallocate the questions array
  delete[] this->questions;
}

void Player::setName(std::string name) {
  // TODO: set name of the player to parameter
  this->name = name;
}

std::string Player::getName() const {
  // TODO: return name of the player
  return this->name;
}

void Player::resizeQuestions() {
  int newCap = questionCapacity * 2; // TODO: double the current capacity

  // TODO: Create new array of Question with new capacity; type of newArr is
  // Question*
  Question *newArr = new Question[newCap];

  // TODO: Call reallocateQuestions() with new array
  reallocateQuestions(newArr, newCap);
}

void Player::reallocateQuestions(Question *questions, int questionCapacity) {
  // Copy existing
  for (int i = 0; i < questionCount;
       i++ /* TODO: loop through the number of question */) {
    // TODO: Copy existing questions to the new array
    questions[i] = this->questions[i];
  }

  // TODO: Deallocate old questions array
  delete[] this->questions;

  // TODO: Update member variables questions and questionCapacity
  this->questions = questions;
  this->questionCapacity = questionCapacity;
}

void Player::generateQuestion() {
  if (questionCount >= questionCapacity /* TODO: Check if resize is needed */) {
    // compare questionCount and
    // questionCapacity
    // TODO: Call this->resizeQuestions()
    this->resizeQuestions();
  }

  // TODO: Generate question for current question count; call generate() of the
  // Question at current position
  questions[questionCount].generate();

  // TODO: Set pendingQuestionIndex to current question count
  pendingQuestionIndex = questionCount;

  // TODO: Increment questionCount
  questionCount++;
}

bool Player::hasPendingQuestion() const {
  // Return true if pendingQuestionIndex is valid
  return (pendingQuestionIndex >= 0 && pendingQuestionIndex < questionCount);
  // TODO: (compare pendingQuestionIndex with 0) AND
  // (pendingQuestionIndex is less than questionCount)
}

void Player::printPendingQuestion() const {
  if (!this->hasPendingQuestion() /* TODO: Check if not has pending question */)
    return; // use hasPendingQuestion()

  // TODO: Print the pending question using printQuestion() of the Question at
  // pendingQuestionIndex
  questions[pendingQuestionIndex].printQuestion();
}

bool Player::answerPendingQuestion(int userAnswer) {
  if (!this->hasPendingQuestion() /* TODO: Check if not has pending question */)
    return false; // use hasPendingQuestion()

  // TODO: Increment total number of questions attempted
  total++;

  bool ok = questions[pendingQuestionIndex].checkAnswer(
      userAnswer); // TODO: Check answer using checkAnswer() of the pending
                   // question

  if (ok)
    correct++; // TODO: Increment number of correct answers

  this->pendingQuestionIndex = -1; // clear pending

  return ok;
}

int Player::getCorrect() const {
  // TODO: Return the number of correct answers
  return correct;
}

int Player::getTotal() const {
  // TODO: Return the total number of questions attempted
  return total;
}

double Player::getScorePercent() const {
  if (total == 0 /* TODO: total number of question attempted is 0 */)
    return 0.0; // avoid division by zero

  // TODO: Calculate percentage
  // (number of correct answers) / (total number of questions attempted) *
  // 100.0; cast to double before division
  return ((double)correct) / ((double)total) * 100.0;
}