#include <fstream>
#include "Pair.h"

int Pair::count = 0;

void Pair::operator *=(Pair& pair)
{
	int temp_first, temp_second;
	temp_first = pair.first;
	temp_second = pair.second;
	pair.first = this->first;
	pair.second = this->second;
	this->first = temp_first;
	this->second = temp_second;
}

Pair::Pair()
{
	first = 0;
	second = 0;
	count++;
}

Pair::Pair(int _first)
{
	first = _first;
	second = 0;
	count++;
}

Pair::Pair(int _first, int _second)
{
	first = _first;
	second = _second;
	count++;
}

Pair::Pair(const Pair& pair)
{
  first = pair.first;
  second = pair.second;
  count ++;
}

Pair::~Pair()
{
	count--;
}

void Pair::setPair(int _first, int _second)
{
	first = _first;
	second = _second;
}

int Pair::getKey()
{
	return first;
}

int Pair::getValue()
{
	return second;
}

int Pair::getCount()
{
	return count;
}

Pair** Pair::readBinaryFile(char* file_path, int pair_num)
{
	ifstream ifs(file_path, ios::binary | ios::in);
	Pair** retPair = new Pair* [pair_num];
	for (int i = 0; i < pair_num; i++)
	{
		int key, value;
		ifs.read(reinterpret_cast<char*>(&key), sizeof(int));
		ifs.read(reinterpret_cast<char*>(&value), sizeof(int));
		retPair[i] = new Pair(key, value);
	}
	ifs.close();
	return retPair;
}

bool Pair::operator <(const Pair& pair)
{
	return this->first < pair.first;
}

ostream& operator <<(ostream& os, const Pair& pair)
{
	os << "key: " << pair.first << ", value: " << pair.second << endl;
	return os;
}