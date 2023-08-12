#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
using namespace std;

int main(int argc, char* argv[])
{
  ifstream ifs(argv[1]);
  vector<string> buffer, longest_words;
  string temp;
  while (ifs >> temp)
  {
    buffer.push_back(temp);
  }
  ifs.close();
  int num_word = buffer.size();
  int num_sentence = 0;
  int longest_sentence_length = -1;
  int longest_word_length = -1;
  int sentence_words = 0;
  for (string str: buffer)
  {
    sentence_words++;
    if (str.back() == '.')
    {
      num_sentence++; // a end of sentence, num_sentence + 1
      longest_sentence_length = (sentence_words >= longest_sentence_length) ? sentence_words : longest_sentence_length;
      sentence_words = 0; // reset counter
    }
    // find the position of the first and last alpha
    int word_length = static_cast<int>(str.find_last_of(alpha) - str.find_first_of(alpha)) + 1;
    longest_word_length = word_length >= longest_word_length ? word_length : longest_word_length;
  }
  for (string str: buffer)
  {
    int word_front = static_cast<int>(str.find_first_of(alpha));
    int word_back = static_cast<int>(str.find_last_of(alpha));
    int word_length = word_back - word_front + 1;
    if (word_length == longest_word_length) {longest_words.push_back(str.substr(word_front, word_back + 1));}
  }
  ostringstream oss;
  oss << "The number of words is: " << num_word << endl;
  oss << "The number of sentences is: " << num_sentence << endl;
  oss << "The longest sentence has a length of: " << longest_sentence_length << endl;
  oss << "The longest word has a length of: " << longest_word_length << endl;
  oss << "The longest words are: ";
  for (string str: longest_words) {oss << str << " ";}
  ofstream ofs(argv[2], ios::out);
  ofs << oss.str();
  ofs.close();
  return 0;
}