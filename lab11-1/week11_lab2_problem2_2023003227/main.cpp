#include <iostream>
#include <string>

using namespace std;

// Define the maximum capacity of the playlist as a global constant to be used
// throughout the program.
const int MAX_CAPACITY = 10;

class MP3_File {
private:
  string fileName; // file name

public:
  // Constructor
  MP3_File(string name = "unknown.mp3") : fileName(name) {}

  // Getter to access the private member fileName from outside.
  string getTitle() const { return fileName; }
};

// Class to manage multiple MP3_File objects.
class Playlist {
private:
  string name;             // Playlist name
  MP3_File **files;        // A dynamic array to hold MP3_File pointers
  int *p_currentFileCount; // An 'integer pointer' to store the current number
                           // of songs
  bool isShortcut; // A flag to indicate if this is a shortcut (shallow copy)

public:
  // Constructor: Creates a 'completely new' playlist from initial songs.
  Playlist(string n, MP3_File *initialFiles[], int initialCount) : name(n) {
    this->isShortcut = false;
    this->p_currentFileCount = new int(initialCount);

    this->files = new MP3_File *[MAX_CAPACITY];
    for (int i = 0; i < *p_currentFileCount; ++i) {
      this->files[i] = new MP3_File(*initialFiles[i]);
    }
    for (int i = *p_currentFileCount; i < MAX_CAPACITY; ++i) {
      this->files[i] = nullptr;
    }
  }

  // Destructor
  ~Playlist() {
    // TODO: Implement the destructor to avoid double free issues.
    delete this->p_currentFileCount;
    for (int i = 0; i < *p_currentFileCount; ++i) {
      delete this->files[i];
    }
    delete[] this->files;
  }

  // Copy Constructor
  Playlist(const Playlist &other, bool createShortcut) {
    this->name =
        (createShortcut ? "Shortcut-of-" : "FullCopy-of-") + other.getName();
    this->isShortcut = createShortcut;

    // TODO: Implement the copy constructor to perform a shallow copy if
    // createShortcut is true, and a deep copy otherwise.
    if (createShortcut) {
      this->p_currentFileCount = other.p_currentFileCount;
      this->files = other.files;
    } else {
      this->p_currentFileCount = new int(*other.p_currentFileCount);
      this->files = new MP3_File *[MAX_CAPACITY];
      for (int i = 0; i < *p_currentFileCount; ++i) {
        this->files[i] = new MP3_File(*other.files[i]);
      }
      for (int i = *p_currentFileCount; i < MAX_CAPACITY; ++i) {
        this->files[i] = nullptr;
      }
    }
  }

  // Method to add a song
  bool addSong(const MP3_File &newSong) {
    // TODO: Implement the addSong logic.
    // Hint: Return false if the current number of songs equals the max
    // capacity, otherwise add the song and return true.
    if (*p_currentFileCount < MAX_CAPACITY) {
      files[(*p_currentFileCount)++] = new MP3_File(newSong);
      return true;
    } else {
      return false;
    }
  }

  // Method to remove a song
  void removeSong(int index) {
    if (index < 0 || index >= *p_currentFileCount)
      return;
    // TODO: Implement the removeSong logic.
    int i;
    for (i = index; i < *p_currentFileCount - 1; i++) {
      files[i] = files[i + 1];
    }
    files[i] = nullptr;
    (*p_currentFileCount)--;
  }

  // Getter methods
  string getName() const { return name; }
  int getFileCount() const { return *p_currentFileCount; }
  string getSongTitle(int index) const {
    if (index >= 0 && index < *p_currentFileCount)
      return files[index]->getTitle();
    return "Error: Invalid Index";
  }
};

// Function to print the user menu
void printMenu() {
  cout << "\n--- Select an Action ---\n";
  cout << "1. Add Song\n";
  cout << "2. Remove Song\n";
  cout << "0. Exit\n";
  cout << "------------------------\n";
  cout << "Enter your choice: ";
}

// Main function
int main() {
  MP3_File *initialTracks[] = {new MP3_File("HypeBoy.mp3"),
                               new MP3_File("LoveDive.mp3")};

  Playlist original("Original", initialTracks, 2);
  Playlist shortcutFromOrig(original, true);
  Playlist fullCopyFromOrig(original, false);

  Playlist *allPlaylists[] = {&original, &shortcutFromOrig, &fullCopyFromOrig};

  while (true) {
    // Print the status of playlists
    cout << "\n\n==================== CURRENT STATUS ===================="
         << endl;
    for (int i = 0; i < 3; ++i) {
      Playlist *p = allPlaylists[i];
      cout << "\n" << i + 1 << ". Playlist: [" << p->getName() << "]" << endl;
      if (p->getFileCount() == 0) {
        cout << "  - (Empty)" << endl;
      } else {
        for (int j = 0; j < p->getFileCount(); ++j) {
          cout << "  [" << j << "] " << p->getSongTitle(j) << endl;
        }
      }
    }
    cout << "========================================================" << endl;

    printMenu();
    int choice;
    cin >> choice;

    if (choice == 0)
      break;

    cout << "Select a playlist (1-3): ";
    int plistChoice;
    cin >> plistChoice;

    Playlist *target = allPlaylists[plistChoice - 1];

    switch (choice) {
    case 1: { // Add a song
      cout << "Enter new song title: ";
      string title;
      cin >> title;

      if (target->addSong(MP3_File(title))) {
        cout << "Song added successfully." << endl;
      } else {
        cout << "Playlist is full. Cannot add more songs." << endl;
      }
      break;
    }
    case 2: { // Remove a song
      cout << "Enter song number to remove: ";
      int songNumber;
      cin >> songNumber;
      target->removeSong(songNumber);
      cout << "Song removed. Observe the changes." << endl;
      break;
    }
    }
  }

  cout << "Exiting program.\n";

  delete initialTracks[0];
  delete initialTracks[1];

  return 0;
}