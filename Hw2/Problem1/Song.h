#ifndef _SONG_H
#define _SONG_H

#include <string>

using namespace std;

// Add any Boolean Function for sorting you need
class Song
{
  private:
    string name;
    string artist;
    string song_len;
  public:
    Song(string name, string artist, string song_len);
    ~Song();
    // Add any Accessor & Mutator functions, or friend class declaration you need
    string getName() const;
    string getArtist() const;
    string getLen() const;
};

#endif