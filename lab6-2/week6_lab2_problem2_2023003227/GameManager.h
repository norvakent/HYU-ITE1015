#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"

class GameManager {
private:
    Player** players;  // to avoid deep copies
    int size;
    int capacity;
    
    void resize();
    void reallocate(Player** players, int capacity);

public:
    GameManager();
    ~GameManager();

    // Player management
    void addPlayer(std::string name);
    int getPlayerCount() const;
    Player* getPlayer(int index) const;
    void printPlayers() const;

    // Quiz operations
    bool generateQuestionForPlayer(int index);
    bool printPendingQuestionForPlayer(int index) const;
    int  submitAnswerForPlayer(int index, int userAnswer); // returns 1 correct, 0 incorrect, -1 invalid/no pending

    // Leaderboard
    void printLeaderboard() const;
};

#endif

