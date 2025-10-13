#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Question.h"

class Player {
private:
    std::string name;
    Question* questions;
    int questionCount;
    int questionCapacity;
    int correct;
    int total;
    int pendingQuestionIndex; // index of the last generated but unanswered question; -1 if none

    void resizeQuestions();
    void reallocateQuestions(Question* questions, int questionCapacity);

public:
    Player();
    explicit Player(std::string name);
    ~Player();

    // Name management (parameters shadow members → use this-> in impl)
    void setName(std::string name);
    std::string getName() const;

    // Question flow
    void generateQuestion(); // append a new question and set as pending
    bool hasPendingQuestion() const;
    void printPendingQuestion() const;
    bool answerPendingQuestion(int userAnswer); // returns true if correct, false if incorrect; no-op if no pending

    // Stats
    int getCorrect() const;
    int getTotal() const;
    double getScorePercent() const; // 0..100
};

#endif

