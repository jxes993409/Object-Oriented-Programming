#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "Spotify.h"

Spotify::Spotify(string file)
{
  ifstream ifs(file, ios::in);
  string str;
  vector<string> str_vec;
  while (ifs >> str)
  {
    str_vec.push_back(str);
  }
  int songs_count = str_vec.size() / 3;
  for (int i = 0; i < songs_count; i++)
  {
    int index = 3 * i;
    const Song* push_song = new const Song(str_vec[0 + index], str_vec[1 + index], str_vec[2 + index]);
    songs.push_back(push_song);
  }
}

Spotify::~Spotify()
{
  for (const Song* s: songs) {delete s;}
  for (User* u: users) {delete u;}
}

void Spotify::controlManual()
{
  while (true)
  {
    string option;
    scene1();
    cout << ">> "; cin >> option;
    if (option == "i" || option == "I") {logIN();}
    else if (option == "q" || option == "Q") {break;}
    else if (option == "a" || option == "A") {addSong();}
    else if (option == "c" || option == "C") {createUser();}
    else if (option == "s" || option == "S") {printSongList();}
    else if (option == "u" || option == "U") {printUserList();}
  }
}

void Spotify::addSong()
{
  string name, artist, song_len;
  cout << "ADD SONG" << endl;
  cout << "Song Name: "; cin >> name;
  cout << "Artist: "; cin >> artist;
  cout << "Song Length: "; cin >> song_len;
  Song* push_song = new Song(name, artist, song_len);
  songs.push_back(push_song);
}

void Spotify::createUser()
{
  string name, passwd;
  cout << "CREATE USER" << endl;
  cout << "User Name: "; cin >> name;
  cout << "User Passwd: "; cin >> passwd;
  for (User* u: users)
  {
    if (u->getName() == name)
    {
      cout << "User already exists." << endl;
      return;
    }
  }
  User* push_user = new User(name, passwd, songs);
  users.push_back(push_user);
}

void Spotify::logIN()
{
  string name, passwd;
  cout << "LOG IN" << endl;
  cout << "User Name: "; cin >> name;
  cout << "User Passwd: "; cin >> passwd;
  bool bool_name = false;
  for (User* u: users)
  {
    if (u->getName() == name)
    {
      bool_name = true;
      if (u->getPasswd() == passwd)
      {
        cout << "Log In Successfully" << endl;
        cout << "Welcome, " << u->getName() << endl;
        // point curr_user to user
        curr_user = u;
      }
      else
      {
        cout << "The Password is wrong" << endl;
        return;
      }
      break;
    }
  }
  if (!bool_name)
  {
    cout << "The User doesn't exist" << endl;
    return;
  }
  while (curr_user)
  {
    // go to userpage
    scene2();
    string option;
    curr_user->show_list();
    cout << ">> "; cin >> option;
    if (option == "o" || option == "O") {logOUT();}
    else if (option == "a" || option == "A") {curr_user->add_list();}
    else if (option == "c" || option == "C")
    {
      // point curr_list to playlist
      curr_user->choose_list();
      while (curr_user->curr_list)
      {
        // go to playlist
        scene3();
        string option;
        curr_user->curr_list->show_song();
        cout << ">> "; cin >> option;
        if (option == "p" || option == "P")
        {
          while (true)
          {
            if (curr_user->curr_list->song_in_list.empty())
            {
              cout << "The list is empty." << endl;
              break;
            }
            scene4();
            curr_user->curr_list->play_song();
            string option;
            cout << ">> "; cin >> option;
            if (option == "n" || option == "N") {curr_user->curr_list->next_song();}
            else if (option == "p" || option == "P") {curr_user->curr_list->prev_song();}
            else if (option == "b" || option == "B") {break;}
          }
        }
        else if (option == "a" || option == "A") {curr_user->curr_list->add_song();}
        else if (option == "r" || option == "R") {curr_user->curr_list->remove_song();}
        else if (option == "b" || option == "B") {curr_user->curr_list = nullptr;}
      }
    }
  }
}

void Spotify::logOUT()
{
  string option;
  cout << "LOG OUT" << endl;
  cout << "Are You Sure to Log Out? (y/n) "; cin >> option;
  if (option == "y" || option == "Y")
  {
    curr_user = nullptr;
    return;
  }
  else if (option == "n" || option == "N")
  {
    return;
  }
}

void Spotify::printSongList()
{
  for (int i = 1; i < 26; i++) {cout << i % 10;}
  cout << endl;
  sort(songs.begin(), songs.end(), sortedbyLen);
  sort(songs.begin(), songs.end(), sortedbyName);
  for (const Song* s: songs)
  {
    cout << setw(15) << left << s->getName() << setw(15) << left << s->getArtist() << s->getLen() << endl;
  }
}

void Spotify::printUserList()
{
  for (User* u: users) {cout << u->getName() << "\t";}
  cout << endl;
}

bool Spotify::sortedbyLen(const Song* song1, const Song* song2)
{
  return song1->getLen() < song2->getLen();
}

bool Spotify::sortedbyName(const Song* song1, const Song* song2)
{
  if (song1->getLen() != song2->getLen()) {return false;}
  return song1->getName() < song2->getName();
}


void Spotify::scene1()
{
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::::::::'######::'########:::'#######::'########:'####:'########:'##:::'##:::::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::::::::'##... ##: ##.... ##:'##.... ##:... ##..::. ##:: ##.....::. ##:'##::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::::::: ##:::..:: ##:::: ##: ##:::: ##:::: ##::::: ##:: ##::::::::. ####:::::::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::::::::. ######:: ########:: ##:::: ##:::: ##::::: ##:: ######:::::. ##::::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::::::::..... ##: ##.....::: ##:::: ##:::: ##::::: ##:: ##...::::::: ##::::::::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::::::::'##::: ##: ##:::::::: ##:::: ##:::: ##::::: ##:: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::::::::. ######:: ##::::::::. #######::::: ##::::'####: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::::::::......:::..::::::::::.......::::::..:::::....::..:::::::::::..:::::::::::::::::::::::::::::::" << endl;
  cout << "               __   __                                         __       __         ___                              " << endl;
  cout << "   | .   |    /  \\ / _`    | |\\ |                             /  \\ .   /  \\ |  | |  |                               " << endl;
  cout << "   | .   |___ \\__/ \\__>    | | \\|                             \\__X .   \\__X \\__/ |  |                               " << endl;
  cout << "                                                                                                                           " << endl;
  cout << "               __   __      __   __        __                  __       __   __   ___      ___  ___          __   ___  __  " << endl;
  cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                /  ` .   /  ` |__) |__   /\\   |  |__     |  | /__` |__  |__) " << endl;
  cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                \\__, .   \\__, |  \\ |___ /~~\\  |  |___    \\__/ .__/ |___ |  \\ " << endl;
  cout << "                                                                                                                           " << endl;
  cout << " __              __  ___     __   __        __   __                            __  ___          __   ___  __   __          " << endl;
  cout << "/__` .   |    | /__`  |     /__` /  \\ |\\ | / _` /__`          |  | .   |    | /__`  |     |  | /__` |__  |__) /__`         " << endl;
  cout << ".__/ .   |___ | .__/  |     .__/ \\__/ | \\| \\__> .__/          \\__/ .   |___ | .__/  |     \\__/ .__/ |___ |  \\ .__/         " << endl;
  cout << endl;
}

void Spotify::scene2()
{
  cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::'##::::'##::'######::'########:'########:::::'########:::::'###:::::'######:::'########:::::::::::::::::" << endl;
  cout << ":::::::::::::::::: ##:::: ##:'##... ##: ##.....:: ##.... ##:::: ##.... ##:::'## ##:::'##... ##:: ##.....::::::::::::::::::" << endl;
  cout << ":::::::::::::::::: ##:::: ##: ##:::..:: ##::::::: ##:::: ##:::: ##:::: ##::'##:. ##:: ##:::..::: ##:::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::: ##:::: ##:. ######:: ######::: ########::::: ########::'##:::. ##: ##::'####: ######:::::::::::::::::::" << endl;
  cout << ":::::::::::::::::: ##:::: ##::..... ##: ##...:::: ##.. ##:::::: ##.....::: #########: ##::: ##:: ##...::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::: ##:::: ##:'##::: ##: ##::::::: ##::. ##::::: ##:::::::: ##.... ##: ##::: ##:: ##:::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::. #######::. ######:: ########: ##:::. ##:::: ##:::::::: ##:::: ##:. ######::: ########:::::::::::::::::" << endl;
  cout << ":::::::::::::::::::.......::::......:::........::..:::::..:::::..:::::::::..:::::..:::......::::........::::::::::::::::::" << endl;
  cout << " __            __   __         __       ___                                                                               " << endl;
  cout << "/  \\ .   |    /  \\ / _`       /  \\ |  |  |                                                                                " << endl;
  cout << "\\__/ .   |___ \\__/ \\__>       \\__/ \\__/  |                                                                                " << endl;
  cout << "                                                                                                                          " << endl;
  cout << "               __   __             __  ___                                                                                " << endl;
  cout << " /\\  .    /\\  |  \\ |  \\    |    | /__`  |                                                                                 " << endl;
  cout << "/~~\\ .   /~~\\ |__/ |__/    |___ | .__/  |                                                                                 " << endl;
  cout << "                                                                                                                          " << endl;
  cout << " __       __        __   __   __   ___            __  ___                                                                 " << endl;
  cout << "/  ` .   /  ` |__| /  \\ /  \\ /__` |__     |    | /__`  |                                                                  " << endl;
  cout << "\\__, .   \\__, |  | \\__/ \\__/ .__/ |___    |___ | .__/  |                                                                  " << endl;
  cout << endl;
}

void Spotify::scene3()
{
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::'########::'##::::::::::'###::::'##:::'##:'##:::::::'####::'######::'########::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ##.... ##: ##:::::::::'## ##:::. ##:'##:: ##:::::::. ##::'##... ##:... ##..:::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ##:::: ##: ##::::::::'##:. ##:::. ####::: ##:::::::: ##:: ##:::..::::: ##:::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ########:: ##:::::::'##:::. ##:::. ##:::: ##:::::::: ##::. ######::::: ##:::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ##.....::: ##::::::: #########:::: ##:::: ##:::::::: ##:::..... ##:::: ##:::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ##:::::::: ##::::::: ##.... ##:::: ##:::: ##:::::::: ##::'##::: ##:::: ##:::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::::::: ##:::::::: ########: ##:::: ##:::: ##:::: ########:'####:. ######::::: ##:::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::::::::..:::::::::........::..:::::..:::::..:::::........::....:::......::::::..::::::::::::::::::::::::::" << endl;
  cout << " __       __                                                   " << endl;
  cout << "|__) .   |__) |     /\\  \\ /                                    " << endl;
  cout << "|    .   |    |___ /~~\\  |                                     " << endl;
  cout << "                                                               " << endl;
  cout << "               __   __      __   __        __                  " << endl;
  cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                 " << endl;
  cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                 " << endl;
  cout << "                                                               " << endl;
  cout << " __       __   ___        __        ___     __   __        __  " << endl;
  cout << "|__) .   |__) |__   |\\/| /  \\ \\  / |__     /__` /  \\ |\\ | / _` " << endl;
  cout << "|  \\ .   |  \\ |___  |  | \\__/  \\/  |___    .__/ \\__/ | \\| \\__> " << endl;
  cout << "                                                               " << endl;
  cout << " __       __   __      __        __                            " << endl;
  cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/                      " << endl;
  cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\                      " << endl;
  cout << endl;
}

void Spotify::scene4()
{
  cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::'##::::'##:'##::::'##::'######::'####::'######::::'########:'####:'##::::'##:'########::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ###::'###: ##:::: ##:'##... ##:. ##::'##... ##:::... ##..::. ##:: ###::'###: ##.....:::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ####'####: ##:::: ##: ##:::..::: ##:: ##:::..::::::: ##::::: ##:: ####'####: ##::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ## ### ##: ##:::: ##:. ######::: ##:: ##:::::::::::: ##::::: ##:: ## ### ##: ######::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ##. #: ##: ##:::: ##::..... ##:: ##:: ##:::::::::::: ##::::: ##:: ##. #: ##: ##...:::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ##:.:: ##: ##:::: ##:'##::: ##:: ##:: ##::: ##:::::: ##::::: ##:: ##:.:: ##: ##::::::::::::::::::::::::" << endl;
  cout << "::::::::::::::::::: ##:::: ##:. #######::. ######::'####:. ######::::::: ##::::'####: ##:::: ##: ########::::::::::::::::::" << endl;
  cout << ":::::::::::::::::::..:::::..:::.......::::......:::....:::......::::::::..:::::....::..:::::..::........:::::::::::::::::::" << endl;
  cout << "               ___     ___     __   __        __" << endl;
  cout << "|\\ | .   |\\ | |__  \\_/  |     /__` /  \\ |\\ | / _`   " << endl;
  cout << "| \\| .   | \\| |___ / \\  |     .__/ \\__/ | \\| \\__>   " << endl;
  cout << "                                                    " << endl;
  cout << " __       __   __   ___          __   __        __  " << endl;
  cout << "|__) .   |__) |__) |__  \\  /    /__` /  \\ |\\ | / _` " << endl;
  cout << "|    .   |    |  \\ |___  \\/     .__/ \\__/ | \\| \\__> " << endl;
  cout << "                                                    " << endl;
  cout << " __       __   __      __        __                 " << endl;
  cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/           " << endl;
  cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\           " << endl;
  cout << endl;
}