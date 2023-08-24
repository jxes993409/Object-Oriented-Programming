#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Playlist.h"

Playlist::Playlist(string name, const vector<const Song*>& songs)
{
  this->name = name;
  const_cast<vector<const Song*>&>(this->songs) = songs;
  curr_song_index = 0;
}

Playlist::~Playlist()
{

}

void Playlist::show_song()
{
  cout << "|| SONG IN LIST ||" << endl;
  sort(song_in_list.begin(), song_in_list.end(), sortedbyLen);
  sort(song_in_list.begin(), song_in_list.end(), sortedbyName);
  for (const Song* s: song_in_list)
  {
    cout << setw(15) << left << s->getName() << setw(15) << left << s->getArtist() << s->getLen() << endl;
  }
}

void Playlist::add_song()
{
  string name;
  cout << "ADD SONG" << endl;
  cout << "Song Name: "; cin >> name;
  for (const Song* s: songs)
  {
    if (s->getName() == name)
    {
      song_in_list.push_back(s);
      return;
    }
  }
  cout << "Doesn't find the song." << endl;
  return;
}

void Playlist::remove_song()
{
  string name;
  cout << "REMOVE SONG" << endl;
  cout << "Song Name: "; cin >> name;
  for (int i = 0; i < static_cast<int>(song_in_list.size()); i++)
  {
    if (song_in_list[i]->getName() == name)
    {
      song_in_list.erase(song_in_list.begin() + i);
      return;
    }
  }
  cout << "Doesn't find the song." << endl;
  return;
}

void Playlist::play_song()
{
  if (song_in_list.empty())
  {
    cout << "The list is empty." << endl;
    return;
  }

  cout << "//// SONG INFO ////" << endl;
  cout << "Name: " << song_in_list[curr_song_index]->getName() << endl;
  cout << "Artist: " << song_in_list[curr_song_index]->getArtist() << endl;
  cout << "Length: " << song_in_list[curr_song_index]->getLen() << endl;
  cout << "//// SONG INFO ////" << endl;
}

void Playlist::next_song()
{
  curr_song_index = (curr_song_index + 1) % song_in_list.size();
}

void Playlist::prev_song()
{
  curr_song_index = (curr_song_index == 0) ? song_in_list.size() - 1 : curr_song_index - 1;
}

string Playlist::getName()
{
  return name;
}

bool Playlist::sortedbyLen(const Song* song1, const Song* song2)
{
  return song1->getLen() < song2->getLen();
}

bool Playlist::sortedbyName(const Song* song1, const Song* song2)
{
  if (song1->getLen() != song2->getLen()) {return false;}
  return song1->getName() < song2->getName();
}