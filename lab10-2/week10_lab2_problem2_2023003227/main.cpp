#include <iostream>
#include <string>

using namespace std;

// Abstract Character class
// TODO: Implement Character class
// Hint: Character class is a pure abstract class
class Character {
public:
  virtual ~Character() {}
  virtual string getJob() const = 0;
  virtual void getInfo(string info[3]) const = 0;
};

// Knight class
// TODO: Implement class Knight
class Knight : public Character {
private:
  int level;
  string nickname;

public:
  Knight(int level, string nickname) : level(level), nickname(nickname) {}
  virtual string getJob() const override { return "Knight"; }
  virtual void getInfo(string info[3]) const override {
    info[0] = "Knight";
    info[1] = to_string(level);
    info[2] = nickname;
  }
};

// Archer class
// TODO: Implement class Archer
class Archer : public Character {
private:
  int level;
  string nickname;

public:
  Archer(int level, string nickname) : level(level), nickname(nickname) {}
  virtual string getJob() const override { return "Archer"; }
  virtual void getInfo(string info[3]) const override {
    info[0] = "Archer";
    info[1] = to_string(level);
    info[2] = nickname;
  }
};

// Wizard class
// TODO: Implement class Wizard
class Wizard : public Character {
private:
  int level;
  string nickname;

public:
  Wizard(int level, string nickname) : level(level), nickname(nickname) {}
  virtual string getJob() const override { return "Wizard"; }
  virtual void getInfo(string info[3]) const override {
    info[0] = "Wizard";
    info[1] = to_string(level);
    info[2] = nickname;
  }
};

// Party class
class Party {
private:
  Character *knight;
  Character *archer;
  Character *wizard;

public:
  Party(Character *_knight, Character *_archer, Character *_wizard)
      : knight(_knight), archer(_archer), wizard(_wizard) {}

  ~Party() {}

  void printPartyInfo() const {
    string info[3];
    knight->getInfo(info);
    cout << "Job: " << info[0] << " Lv: " << info[1] << " Nickname: " << info[2]
         << endl;
    archer->getInfo(info);
    cout << "Job: " << info[0] << " Lv: " << info[1] << " Nickname: " << info[2]
         << endl;
    wizard->getInfo(info);
    cout << "Job: " << info[0] << " Lv: " << info[1] << " Nickname: " << info[2]
         << endl;
  }
};

// GameLobby class
class GameLobby {
private:
  Character **all_characters;
  Party **dungeonParties;

  int char_capacity; // Maximum capacity of the all_characters array
  int char_count;    // Current number of registered characters
  int partyCount;    // Current number of created parties

public:
  GameLobby(int n) {
    char_capacity = n;
    all_characters = new Character *[char_capacity];

    // Maximum number of parties is N/3
    dungeonParties = new Party *[char_capacity / 3];

    char_count = 0;
    partyCount = 0;
  }

  // Destructor: release all dynamically allocated memory
  ~GameLobby() {
    // TODO: Release all dynamically allocated memory
    for (int i = 0; i < char_count; i++) {
      delete all_characters[i];
    }
    for (int i = 0; i < partyCount; i++) {
      delete dungeonParties[i];
    }
    delete[] all_characters;
    delete[] dungeonParties;
  }

  // Register a character in the lobby (array)
  bool registerCharacter(Character *newChar) {
    // TODO: Implement registerCharacter method
    // Hint: Add new character to the all_characters array. Return true if
    // successful, false if failed. Hint: Think carefully about when
    // registration might fail.
    if (char_count >= char_capacity)
      return false;
    all_characters[char_count++] = newChar;
    return true;
  }

  void matchParties() {
    // TODO: Implement matchParties method
    // Hint: Add parties to dungeonParties array, each consisting of 3
    // characters with different jobs Hint: Follow the rule strictly and form
    // parties in the order characters were registered
    int matchedKnight = 0;
    int matchedArcher = 0;
    int matchedWizard = 0;
    bool *matched = new bool[char_count];

    while (true) {
      if (partyCount >= char_capacity / 3) {
        delete[] matched;
        return;
      }
      matchedKnight = -1;
      matchedArcher = -1;
      matchedWizard = -1;

      for (int i = 0; i < char_count; i++) {
        if (matchedKnight < 0 && !matched[i] &&
            all_characters[i]->getJob() == "Knight") {
          matchedKnight = i;
          matched[i] = true;
        }
        if (matchedArcher < 0 && !matched[i] &&
            all_characters[i]->getJob() == "Archer") {
          matchedArcher = i;
          matched[i] = true;
        }
        if (matchedWizard < 0 && !matched[i] &&
            all_characters[i]->getJob() == "Wizard") {
          matchedWizard = i;
          matched[i] = true;
        }
      }
      if ((matchedKnight >= 0) && (matchedArcher >= 0) && (matchedWizard >= 0))
        dungeonParties[partyCount++] = new Party(all_characters[matchedKnight],
                                                 all_characters[matchedArcher],
                                                 all_characters[matchedWizard]);
      else
        break;
    }
    delete[] matched;
  }

  // Print final results
  void printResults() {
    cout << "\n========================================\n";
    cout << "           LOBBY RESULTS" << endl;
    cout << "========================================\n";
    cout << "Total parties entered the dungeon: " << partyCount << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < partyCount; ++i) {
      cout << "--- Party " << i + 1 << " ---" << endl;
      dungeonParties[i]->printPartyInfo();
      cout << "----------------------------------------" << endl;
    }
  }
};

// main function
int main() {
  int N;
  cout << "Enter the total number of characters to register: ";
  cin >> N;

  GameLobby lobby(20);

  for (int i = 0; i < N; ++i) {
    string job, nickname;
    int level;

    cout << "\nEnter character " << i + 1 << " info (Job Level Nickname): ";
    cin >> job >> level >> nickname;

    Character *newChar = nullptr;
    if (job == "knight") {
      newChar = new Knight(level, nickname);
    } else if (job == "archer") {
      newChar = new Archer(level, nickname);
    } else if (job == "wizard") {
      newChar = new Wizard(level, nickname);
    } else {
      cout << "Invalid job type. Please re-enter." << endl;
      i--;
      continue;
    }

    if (lobby.registerCharacter(newChar)) {
      string info[3];
      newChar->getInfo(info);
      cout << "Registered Job: " << info[0] << " Lv: " << info[1]
           << " Nickname: " << info[2] << endl;
    } else {
      string info[3];
      newChar->getInfo(info);
      cout << "Lobby is full. Cannot register Job: " << info[0]
           << " Lv: " << info[1] << " Nickname: " << info[2] << endl;
      delete newChar;
      break;
    }
  }

  lobby.matchParties();
  lobby.printResults();

  return 0;
}
