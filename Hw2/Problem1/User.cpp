#include <iostream>
#include <algorithm>
#include "User.h"

User::User(string name, string passwd, vector<const Song*>& songs)
{
  this->name = name;
  this->passwd = passwd;
  const_cast<vector<const Song*>&>(this->songs) = songs;
  curr_list = nullptr;
}

void User::show_list()
{
  cout << "|| PLAY LIST: ";
  sort(all_list.begin(), all_list.end(), sortedbyName);
  for (Playlist* p: all_list) {cout << p->getName() << " ";}
  cout << "||" << endl;
}

User::~User()
{
  for (Playlist* p: all_list) {delete p;}
}

void User::choose_list()
{
  string list_name;
  cout << "CHOOSE LIST" << endl;
  cout << "List name: "; cin >> list_name;
  for (Playlist* p: all_list)
  {
    if (p->getName() == list_name)
    {
      curr_list = p;
      return;
    }
  }
  cout << "List doesn't exist" << endl;
  curr_list = nullptr;
}

void User::add_list()
{
  string name;
  cout << "ADD LIST" << endl;
  cout << "List name: "; cin >> name;
  Playlist* push_playlist = new Playlist(name, songs);
  all_list.push_back(push_playlist);
}

string User::getName()
{
  return name;
}

string User::getPasswd()
{
  return passwd;
}

bool User::sortedbyName(Playlist* playlist1, Playlist* playlist2)
{
  return playlist1->getName() < playlist2->getName();
}