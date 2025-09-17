#include <iostream>
#include <string>
using namespace std;

#define MAXCOUNT 5
struct Duration {
  int minutes;
  int seconds;
};

struct Song {
  string title;
  string artist;
  Duration length;
};

struct Playlist {
  string name;
  Song songs[MAXCOUNT];
  int songCount;
  Duration totalDuration;
};

Duration addDuration(Duration d1, Duration d2) {
  return {d1.minutes + d2.minutes + (d1.seconds + d2.seconds) / 60, (d1.seconds + d2.seconds) % 60};
}

Duration subtractDuration(Duration d1, Duration d2) {
  Duration result;
  int total1 = d1.minutes * 60 + d1.seconds;
  int total2 = d2.minutes * 60 + d2.seconds;
  int diff = total1 - total2;

  if (diff < 0) {
    diff = 0;
  }

  result.minutes = diff / 60;
  result.seconds = diff % 60;

  return result;
}

bool addSongToPlaylist(Playlist* playlist, Song* newSong) {
  if (playlist->songCount == MAXCOUNT) return false;

  for (int i = 0; i < playlist->songCount; i++) {
    if (playlist->songs[i].title == newSong->title) return false;
  }
  
  playlist->songs[playlist->songCount] = *newSong;
  playlist->songCount++;
  playlist->totalDuration = addDuration(playlist->totalDuration, newSong->length);
  return true;
}

bool removeSongFromPlaylist(Playlist* playlist, Song* newSong) {
  if (playlist->songCount == 0) return false;

  int i;
  for (i = 0; i < playlist->songCount; i++) {
    if ((playlist->songs[i].title == newSong->title) && (playlist-> songs[i].artist == newSong->artist)) break;
  }
  if (i >= playlist->songCount) return false;

  playlist->songCount--;
  for (; i < playlist->songCount; i++) {
    playlist->songs[i] = playlist->songs[i+1];
  }
  playlist->totalDuration = subtractDuration(playlist->totalDuration, newSong->length);
  return true;
}

void displayPlaylist(Playlist playlist) {
  cout << "\n\n=== Display Playlist: " << playlist.name << " ===" << endl;
  cout << "[Total songs]: " << playlist.songCount << endl;
  cout << "[Total duration]: " << playlist.totalDuration.minutes << "m " << playlist.totalDuration.seconds << "s" << endl;
  if (playlist.songCount == 0) {
    cout << "\n!Playlist is empty.!" << endl;
    cout << "=================================\n\n";
    return;
  }

  cout << endl;
  for (int i = 0; i < playlist.songCount; i++) {
    cout << i + 1 << ". " << playlist.songs[i].title << " - " << playlist.songs[i].artist << " (" << playlist.songs[i].length.minutes << ":";
    if (playlist.songs[i].length.seconds < 10) {
      cout << "0";
    }
    cout << playlist.songs[i].length.seconds << ")" << endl;
  }
  cout << "=================================\n\n" << endl;
}

int main() {
  // Create new playlist
  Playlist myPlaylist;
  myPlaylist.name = "Honmoon";
  myPlaylist.songCount = 0;
  myPlaylist.totalDuration = {0, 0};
  cout << "Created playlist: '" << myPlaylist.name << "'" << endl;

  Song song1;
  song1.title = "Golden";
  song1.artist = "HUNTR/X";
  song1.length.minutes = 3;
  song1.length.seconds = 14;

  Song song2;
  song2.title = "How It's Done";
  song2.artist = "HUNTR/X";
  song2.length.minutes = 2;
  song2.length.seconds = 56;

  Song song3;
  song3.title = "Golden";
  song3.artist = "HUNTR/X";
  song3.length.minutes = 3;
  song3.length.seconds = 14;

  if (addSongToPlaylist(&myPlaylist, &song1)) {
    cout << "Added: '" << song1.title << "'" << endl;
  }
  if (addSongToPlaylist(&myPlaylist, &song2)) {
    cout << "Added: '" << song2.title << "'" << endl;
  }
  if (addSongToPlaylist(&myPlaylist, &song3)) {
    cout << "Added: '" << song3.title << "'" << endl;
  }
  else {
    cout << "Fail to Add: " << song3.title << endl;
  }

  // Display playlist
  displayPlaylist(myPlaylist);

  Song song4;
  song4.title = "How It's Done";
  song4.artist = "HUNTR/X";
  song4.length.minutes = 2;
  song4.length.seconds = 56;
  if (removeSongFromPlaylist(&myPlaylist, &song4)) {
    cout << "Removed: " << song4.title << endl;
  }

  displayPlaylist(myPlaylist);

  Song longSong;
  longSong.title = "Long Song";
  longSong.artist = "Test Artist";
  longSong.length.minutes = 5;
  longSong.length.seconds = 75;

  if (addSongToPlaylist(&myPlaylist, &longSong)) {
    cout << "Added: '" << longSong.title << "' ";
    cout << "(Input: 5m 75s -> Actual: 9m 29s)" << endl;
  }

  displayPlaylist(myPlaylist);

  return 0;
}