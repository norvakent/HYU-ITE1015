#include <iostream>
#include <string>
using namespace std;

// TODO: Define PlayableMedia abstract class
class PlayableMedia {
protected:
  string title;

public:
  PlayableMedia(const string &t) : title(t) {}
  virtual ~PlayableMedia() {}
  virtual void play() const = 0;
  virtual string getInfo() const = 0;
  virtual string getMediaType() const = 0;
  string getTitle() const { return title; };
};

class Song : public PlayableMedia {
private:
  string artist;

public:
  Song(const string &t, const string &a) : PlayableMedia(t), artist(a) {}

  void play() const override {
    cout << "Now Playing: " << title << " by " << artist << endl;
  }

  string getInfo() const override { return title + " - " + artist; }

  string getMediaType() const override { return "Song"; }
};

class Podcast : public PlayableMedia {
private:
  string host;

public:
  Podcast(const string &t, const string &h) : PlayableMedia(t), host(h) {}

  void play() const override {
    cout << "Now Playing: " << title << " hosted by " << host << endl;
  }

  string getInfo() const override { return title + " - Host: " + host; }

  string getMediaType() const override { return "Podcast"; }
};

// TODO: Implement MediaQueue class
class MediaQueue {
private:
  static const int MAX_QUEUE_SIZE = 10;
  PlayableMedia *queue[MAX_QUEUE_SIZE];
  int front;
  int rear;
  int size;

public:
  MediaQueue() : front(0), rear(0), size(0) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
      queue[i] = nullptr;
    }
  }

  // TODO: Implement enqueue (circular queue)
  bool enqueue(PlayableMedia *media) {
    if (size == MAX_QUEUE_SIZE) {
      return false;
    }
    queue[rear++] = media;
    rear %= MAX_QUEUE_SIZE;
    size++;
    return true;
  }

  // TODO: Implement dequeue
  PlayableMedia *dequeue() {
    if (size == 0) {
      return nullptr;
    }
    PlayableMedia *temp = queue[front++];
    front %= MAX_QUEUE_SIZE;
    size--;
    return temp;
  }

  // TODO: Implement playNext
  void playNext() {
    PlayableMedia *nowPlaying = dequeue();
    nowPlaying->play();
    delete nowPlaying;
  }

  // TODO: Implement playNext
  bool isEmpty() const { return (size == 0 ? true : false); }

  // TODO: Implement isFull
  bool isFull() const { return (size == MAX_QUEUE_SIZE ? true : false); }

  // TODO: Implement getSize
  int getSize() const { return size; }

  // TODO: Implement showQueue
  void showQueue() const {
    if (size == 0) {
      cout << "Queue is empty." << endl;
      return;
    }

    int currentIndex = front;
    for (int i = 0; i < size; i++) {
      cout << (i + 1) << ". [" << queue[currentIndex]->getMediaType() << "] "
           << queue[currentIndex]->getInfo() << endl;
      currentIndex = ++currentIndex % MAX_QUEUE_SIZE;
    }
  }

  // Destructor
  // TODO: Implement destructor to clean up queue
  ~MediaQueue() {
    int currentIndex = front;
    for (int i = 0; i < size; i++) {
      delete queue[currentIndex];
      currentIndex = ++currentIndex % MAX_QUEUE_SIZE;
    }
  }
};

// Function declarations (return only success/failure without output)
void printMenu();
bool addSongToQueue(MediaQueue &mediaQueue, string &songInfo);
bool addPodcastToQueue(MediaQueue &mediaQueue, string &podcastInfo);
bool playNextMedia(MediaQueue &mediaQueue);
int playAllMedia(MediaQueue &mediaQueue);

int main() {
  cout << "=== Streaming Media Player ===" << endl;

  MediaQueue mediaQueue;
  int choice;

  while (true) {
    printMenu();
    cin >> choice;
    cin.ignore(10000, '\n');

    switch (choice) {
    case 1: {
      string songInfo;
      if (addSongToQueue(mediaQueue, songInfo)) {
        cout << "Song added to queue: " << songInfo << endl;
      } else {
        cout << "[Error] Play queue is full or failed to add song!" << endl;
      }
      break;
    }
    case 2: {
      string podcastInfo;
      if (addPodcastToQueue(mediaQueue, podcastInfo)) {
        cout << "Podcast added to queue: " << podcastInfo << endl;
      } else {
        cout << "[Error] Play queue is full or failed to add podcast!" << endl;
      }
      break;
    }
    case 3: {
      if (playNextMedia(mediaQueue)) {
        cout << "\nPlaying next media..." << endl;
        mediaQueue.playNext();
        cout << "Queue size after playing: " << mediaQueue.getSize() << endl;
      } else {
        cout << "[Info] Play queue is empty." << endl;
      }
      break;
    }
    case 4: {
      cout << "\nCurrent Play Queue (Size: " << mediaQueue.getSize() << "/10)"
           << endl;
      mediaQueue.showQueue();
      break;
    }
    case 5: {
      int totalPlayed = playAllMedia(mediaQueue);
      if (totalPlayed > 0) {
        cout << "\nPlaying all media in queue..." << endl;
        for (int i = 1; i <= totalPlayed; i++) {
          cout << "\n--- Media " << i << " ---" << endl;
          // Actually already played in playAllMedia
        }
        cout << "\nFinished playing " << totalPlayed << " media items." << endl;
      } else {
        cout << "[Info] Play queue is empty." << endl;
      }
      break;
    }
    case 6:
      cout << "Shutting down media player..." << endl;
      return 0;
    default:
      cout << "[Error] Invalid selection." << endl;
    }
  }

  return 0;
}

void printMenu() {
  cout << "\n===== Media Player Queue =====" << endl;
  cout << "1. Add Song to Queue" << endl;
  cout << "2. Add Podcast to Queue" << endl;
  cout << "3. Play Next" << endl;
  cout << "4. Show Play Queue" << endl;
  cout << "5. Play All" << endl;
  cout << "6. Exit" << endl;
  cout << "===============================" << endl;
  cout << "Select: ";
}

// Functions return only success/failure, output handled in main
bool addSongToQueue(MediaQueue &mediaQueue, string &songInfo) {
  if (mediaQueue.isFull()) {
    return false;
  }

  string title, artist;

  cout << "-> Enter song title: ";
  getline(cin, title);
  cout << "-> Enter artist: ";
  getline(cin, artist);

  Song *newSong = new Song(title, artist);
  if (mediaQueue.enqueue(newSong)) {
    songInfo = newSong->getInfo();
    return true;
  } else {
    delete newSong;
    return false;
  }
}

bool addPodcastToQueue(MediaQueue &mediaQueue, string &podcastInfo) {
  if (mediaQueue.isFull()) {
    return false;
  }

  string title, host;

  cout << "-> Enter podcast title: ";
  getline(cin, title);
  cout << "-> Enter host: ";
  getline(cin, host);

  Podcast *newPodcast = new Podcast(title, host);
  if (mediaQueue.enqueue(newPodcast)) {
    podcastInfo = newPodcast->getInfo();
    return true;
  } else {
    delete newPodcast;
    return false;
  }
}

bool playNextMedia(MediaQueue &mediaQueue) { return !mediaQueue.isEmpty(); }

int playAllMedia(MediaQueue &mediaQueue) {
  if (mediaQueue.isEmpty()) {
    return 0;
  }

  int totalPlayed = 0;
  while (!mediaQueue.isEmpty()) {
    mediaQueue.playNext();
    totalPlayed++;
  }

  return totalPlayed;
}