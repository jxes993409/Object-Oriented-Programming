#include "Song.h"

Song::Song(string name, string artist, string song_len)
{
  this->name = name;
  this->artist = artist;
  this->song_len = song_len;
}

Song::~Song()
{
}

string Song::getName() const
{
  return name;
}

string Song::getArtist() const
{
  return artist;
}

string Song::getLen() const
{
  return song_len;
}