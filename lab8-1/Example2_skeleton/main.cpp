#include "MediaLogger.h"

struct MediaType {
  int type; // 1: Song, 2: Podcast, 3: Audiobook
  std::string name;
};

class Media {
private:
  MediaType mediaType;
  std::string title;

public:
  Media(int t, std::string tit) {
    if (t < 1 || t > 3) {
      MediaLogger::log_error_invalid_media_type();
      t = 1;
    }

    mediaType.type = t;

    // TODO: Implement the proper constructor with 3-types (Song, Podcast,
    // Audiobook)
    title = tit;
    switch (t) {
    case 1:
      mediaType.name = "Song";
      break;
    case 2:
      mediaType.name = "Podcast";
      break;
    case 3:
      mediaType.name = "Audiobook";
      break;
    }
  }

  void play() {
    // TODO
    switch (mediaType.type) {
    case 1:
      MediaLogger::log_play_song(title);
      break;
    case 2:
      MediaLogger::log_play_podcast(title);
      break;
    case 3:
      MediaLogger::log_play_audiobook(title);
      break;
    }
  }

  std::string getType() { return mediaType.name; }
};

int main() {
  int playlistSize;
  MediaLogger::log_prompt_playlist_size();

  // TODO: Dynamic allocate object array
  std::cin >> playlistSize;
  Media **playlist = new Media *[playlistSize];

  for (int i = 0; i < playlistSize; ++i) {
    int choice;
    std::string title;

    // TODO: Get user inputs & handle invalid inputs
    MediaLogger::log_prompt_media_type(i + 1);
    std::cin >> choice;
    MediaLogger::log_prompt_title(i + 1);
    std::cin >> title;
    if (choice < 1 || choice > 3) {
      MediaLogger::log_error_invalid_media_type();
      choice = 1;
    }
    playlist[i] = new Media(choice, title);
  }

  for (int i = 0; i < playlistSize; ++i) {
    // TODO: Print out the type of items and play
    MediaLogger::log_playlist_item_info(i + 1, playlist[i]->getType());
    playlist[i]->play();
  }

  // TODO: Release memory properly
  for (int i = 0; i < playlistSize; i++) {
    delete playlist[i];
  }
  delete[] playlist;

  return 0;
};
