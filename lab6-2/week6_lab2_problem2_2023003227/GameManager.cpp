#include "GameManager.h"
#include <iostream>

GameManager::GameManager() {
  // TODO: Use this-> to initialize all member variables
  // players = nullptr, size = 0, capacity = 2
  this->players = nullptr;
  this->size = 0;
  this->capacity = 2;

  // Allocate array of Player pointers
  this->players = new Player *[this->capacity];

  // TODO: Initialize all players pointers to nullptr using loop
  for (int i = 0; i < this->capacity; i++) {
    this->players[i] = nullptr;
  }
}

GameManager::~GameManager() {
  for (int i = 0; i < size; i++ /* TODO: loop through the size */) {
    // TODO: deallocate each Player object
    delete players[i];

    // TODO: set each pointer to nullptr
    players[i] = nullptr;
  }
  // TODO: Deallocate the players array
  delete[] players;

  // TODO: Set players pointer to nullptr
  players = nullptr;
}

void GameManager::resize() {
  int newCap = capacity * 2; // TODO: double the current capacity

  // TODO: Create newArr of Player pointers with new capacity; type of
  // newArr is Player**
  Player **newArr = new Player *[newCap];

  for (int i = 0; i < newCap; i++ /* TODO: loop through the new capacity */) {
    // TODO: initialize all pointers to nullptr in new array
    newArr[i] = nullptr;
  }

  // TODO: Call this->reallocate with new array
  this->reallocate(newArr, newCap);
}

void GameManager::reallocate(Player **players, int capacity) {
  for (int i = 0; i < size; i++ /* TODO: loop through the size */) {
    // TODO: Copy existing pointers of players to new array
    players[i] = this->players[i];
  }

  // TODO: Delete old array
  delete[] this->players;

  // TODO: Update member variables players and capacity with new values
  this->players = players;
}

void GameManager::addPlayer(std::string name) {
  if (size >= capacity /* TODO: Check if resize is needed */) { // compare size
                                                                // and capacity
    // TODO: Call this->resize()
    this->resize();
  }

  // TODO: Create new Player object at current size
  players[size] = new Player(name);

  // TODO: Increment the current size
  size++;
}

int GameManager::getPlayerCount() const {
  // TODO: Return the current number of players
  return size;
}

Player *GameManager::getPlayer(int index) const {
  // TODO: If index is invalid (compare index with 0 and size), return nullptr
  if (index < 0 || index >= size)
    return nullptr;

  // TODO: Return the player at given index
  return players[index];
}

void GameManager::printPlayers() const {
  for (int i = 0; i < size; i++ /* TODO: loop through the size */) {
    std::cout << "Player " << i << ": " << players[i]->getName() << std::endl;
  }
}

bool GameManager::generateQuestionForPlayer(int index) {
  // TODO: Get player of given index using getPlayer()
  Player *player = getPlayer(index);

  // TODO: Return false if player is nullptr
  if (!player)
    return false;

  // TODO: Call generateQuestion() of the player
  player->generateQuestion();

  return true;
}

bool GameManager::printPendingQuestionForPlayer(int index) const {
  // TODO: Get player of given index using getPlayer()
  Player *player = getPlayer(index);

  // TODO: Return false if player is nullptr
  if (!player)
    return false;

  // TODO: Return false if player has no pending question (use
  // hasPendingQuestion() of Player)
  if (!player->hasPendingQuestion())
    return false;

  // TODO: Call printPendingQuestion() of the player
  player->printPendingQuestion();

  return true;
}

int GameManager::submitAnswerForPlayer(int index, int userAnswer) {
  // TODO: Get player of given index using getPlayer()
  Player *player = getPlayer(index);

  // TODO: Return -1 if player is nullptr
  if (!player)
    return -1;

  // TODO: Return -1 if player has no pending question (use hasPendingQuestion()
  // of Player)
  if (!player->hasPendingQuestion())
    return -1;

  bool ok = player->answerPendingQuestion(
      userAnswer); // TODO: Call answerPendingQuestion() of
  // the player with userAnswer

  if (ok)
    return 1;
  return 0;
  // TODO: Return 1 if ok is true, otherwise return 0
}

void GameManager::printLeaderboard() const {
  // Use player's member functions
  for (int i = 0; i < size; i++ /* TODO: loop through the size */) {
    // TODO: Get player at index from the players array

    std::cout
        << players[i]->getName() /* TODO: player's name */ << ": "
        << players[i]->getCorrect() /* TODO: number of correct answers of the
                                       player */
        << "/" << players[i]->getTotal() /* TODO: total number of answers */
        << " (Score: "
        << players[i]->getScorePercent() /* TODO: score of the player */ << "%)"
        << std::endl;
  }
}