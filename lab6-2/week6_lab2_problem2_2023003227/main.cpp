#include <iostream>
#include <string>
#include <cstdlib>
#include "GameManager.h"

using namespace std;

static void showMenu() {
    cout << "\n=== Quiz Tournament Manager ===" << endl;
    cout << "1. Add player" << endl;
    cout << "2. Display players" << endl;
    cout << "3. Play a round" << endl;
    cout << "4. Display leaderboard" << endl;
    cout << "5. Exit program" << endl;
    cout << "Choose option: ";
}

static bool getInt(int& x, const char* prompt) {
    if (prompt && *prompt) cout << prompt;
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return false;
    }
    return true;
}

int main() {
    srand(42); // fixed seed for deterministic questions

    GameManager gm;
    int choice;

    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "Enter player name: ";
                string name;
                if (!(cin >> name)) {
                    cout << "Invalid input." << endl;
                    break;
                }
                gm.addPlayer(name);
                cout << "Player added." << endl;
                break;
            }
            case 2: {
                if (gm.getPlayerCount() == 0) {
                    cout << "No players. Please add players first." << endl;
                } else {
                    cout << "\n=== Players ===" << endl;
                    gm.printPlayers();
                }
                break;
            }
            case 3: {
                int playerCount = gm.getPlayerCount();
                if (playerCount == 0) {
                    cout << "No players. Please add players first." << endl;
                    break;
                }

                cout << "\n=== New Round ===" << endl;
                for (int i = 0; i < playerCount; ++i) {
                    gm.generateQuestionForPlayer(i);
                }

                for (int i = 0; i < playerCount; ++i) {
                    Player* p = gm.getPlayer(i);
                    cout << "\nPlayer " << i << " (" << p->getName() << ")" << endl;
                    cout << "Question: ";
                    if (!gm.printPendingQuestionForPlayer(i)) {
                        cout << "No pending question." << endl;
                        continue;
                    }

                    int ans;
                    while (true) {
                        cout << "Enter answer: ";
                        if (cin >> ans) {
                            break;
                        }
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                    }

                    int result = gm.submitAnswerForPlayer(i, ans);
                    if (result == 1) {
                        cout << "Correct." << endl;
                    } else if (result == 0) {
                        cout << "Incorrect." << endl;
                    } else {
                        cout << "Invalid player index or no pending question." << endl;
                    }
                }

                cout << "\n=== Round Summary ===" << endl;
                gm.printLeaderboard();
                break;
            }
            case 4: {
                if (gm.getPlayerCount() == 0) {
                    cout << "No players. Please add players first." << endl;
                } else {
                    cout << "\n=== Leaderboard ===" << endl;
                    gm.printLeaderboard();
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please select 1-5." << endl;
        }
    }
}

