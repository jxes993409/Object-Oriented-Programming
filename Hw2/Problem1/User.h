#ifndef _USER_H
#define _USER_H

#include "Playlist.h"

using namespace std;

// Add any Boolean Function for sorting you need
class User
{
  private:
    string name;
    string passwd;
    Playlist* curr_list;
    vector<Playlist*> all_list;
    const vector<const Song*> songs;
    void show_list();   // show all playlists of the user (sort by list name)
    void choose_list(); // choose a playlist
    void add_list();    // add a playlist
  public:
    User(string name, string passwd, vector<const Song*>& songs);
    ~User();
    string getName();
    string getPasswd();
    // Add any Accessor & Mutator functions, or friend class declaration you need
    friend class Spotify;
    static bool sortedbyName(Playlist*, Playlist*);
};
#endif