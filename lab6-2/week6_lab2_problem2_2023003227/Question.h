#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

class Question {
private:
    int left;
    int right;
    char op;      // '+' or '-'
    int answer;   // correct answer
    bool ready;   // whether a question is generated and pending

public:
    // Default constructor
    Question();

    // Generate a new question with random operands and operator
    void generate();

    // Print the question in the format: "<left> <op> <right> = ?"
    void printQuestion() const;

    // Check the user's answer against the correct one
    bool checkAnswer(int userAnswer) const;

    // Accessors
    bool isReady() const;
};

#endif

