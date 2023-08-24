#ifndef _PLAYLIST_H
#define _PLAYLIST_H

#include <vector>
#include "Song.h"

using namespace std;

// Add any Boolean Function for sorting you need

class Playlist
{
  private:
    string name;
    int curr_song_index;
    vector<const Song*> song_in_list;
    const vector<const Song*> songs;
    void show_song();   // show song in playlist (sort by song length, if equal sort by song title)
    void add_song();    // add song into playlist (song must exists in streaming device)
    void remove_song(); // remove song from playlist
    void play_song();   // play current song
    void next_song();   // play next song (back to first song if meet the end of playlist)
    void prev_song();   // play previous song (go to last song if meet the start of playlist)
  public:
    Playlist(string name, const vector<const Song*>& songs);
    ~Playlist();
    string getName();
    // Add any Accessor & Mutator functions, or friend class declaration you need
    friend class Spotify;
    // friend class User;
    static bool sortedbyLen(const Song*, const Song*);
    static bool sortedbyName(const Song*, const Song*);
};

#endif