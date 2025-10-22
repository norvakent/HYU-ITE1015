#ifndef MEDIA_LOGGER_H
#define MEDIA_LOGGER_H

#include <iostream>
#include <string>

namespace MediaLogger {

// --- Prompts ---
inline void log_prompt_playlist_size() {
  std::cout << "Enter the number of media items in the playlist: ";
}

inline void log_prompt_media_type(int item_num) {
  std::cout << "Select media type for item " << item_num
            << " (1: Song, 2: Podcast, 3: Audiobook): ";
}

inline void log_prompt_title(int item_num) {
  std::cout << "Enter title for item " << item_num << ": ";
}

// --- Playback Logs ---
inline void log_play_song(const std::string& title) {
  std::cout << "Playing song: " << title << std::endl;
}

inline void log_play_podcast(const std::string& title) {
  std::cout << "Playing podcast episode: " << title << std::endl;
}

inline void log_play_audiobook(const std::string& title) {
  std::cout << "Playing audiobook: " << title << std::endl;
}

// --- Status & Info ---
inline void log_playlist_item_info(int item_num, const std::string& type_name) {
  std::cout << "Item " << item_num << " (" << type_name << "): ";
}

// --- Error Logs ---
inline void log_error_invalid_media_type() {
  std::cout << "Invalid choice, defaulting to Song.\n";
}

}

#endif