#ifndef _SPOTIFY_H_
#define _SPOTIFY_H_

#include <fstream>
#include "User.h"

using namespace std;

// Add any Boolean Function for sorting you need
class Spotify
{
  private:
    vector<User*> users;
    vector<const Song*> songs;
    User* curr_user;
    void scene1();
    void scene2();
    void scene3();
    void scene4();
    void addSong();       // add new song into songs
    void createUser();    // create new user
    void logIN();         // log in to specific user
    void logOUT();        // log out from current user
    void printSongList(); // list all songs in device
    // (sort by song length, if equal sort by song title)
    void printUserList(); // list all users in device
    // (sort by creation)
  public:
    Spotify(string file);
    ~Spotify();
    void controlManual(); // controller of the whole device
    // Add any Accessor & Mutator functions, or friend class declaration you need
    static bool sortedbyLen(const Song*, const Song*);
    static bool sortedbyName(const Song*, const Song*);
};

#endif