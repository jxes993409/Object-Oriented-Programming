#include "Container.h"

int Container::count = 0;

void Container::sort()
{
  for (int i = 0; i < capacity - 1; i++)
  {
    for (int j = 0; j < capacity - i - 1; j++)
    {
      if (!(*data[j] < *data[j + 1]))
      {
        *data[j] *= *data[j + 1];
      }
    }
  }
}

Container::Container()
{
  data = nullptr;
  capacity = 0;
  count++;
}

Container::Container(const Pair& pair)
{
  data = new Pair* [1];
  capacity = 1;
  data[0] = new Pair(pair);
  count++;
}

Container::Container(Pair** pair, int pair_num)
{
  data = nullptr;
  capacity = 0;
  for (int i = 0; i < pair_num; i++)
  {
    insert(*pair[i]);
  }
  count++;
  sort();
}

Container::Container(const Container& container)
{
  data = new Pair* [static_cast<unsigned int>(container.size())];
  capacity = container.size();
  for (int i = 0; i < capacity; i++)
  {
    data[i] = new Pair(container.data[i]->getKey(), container.data[i]->getValue());
  }
  count++;
}

Container::~Container()
{
  for (int i = 0; i < capacity; i++)
  {
    delete data[i];
  }
  delete [] data;
  data = nullptr;
  capacity = 0;
  count--;
}

void Container::erase(Pair*)
{
  Pair** newData = new Pair* [static_cast<unsigned int>(--capacity)];
  for (int i = 0; i < capacity; i++)
  {
    newData[i] = new Pair(data[i + 1]->getKey(), data[i + 1]->getValue());
  }
  for (int i = 0; i < capacity + 1; i++)
  {
    delete data[i];
  }
  delete [] data;
  data = newData;
}

void Container::clear()
{
  while (!empty()) {erase(begin());}
}

bool Container::empty()
{
  return capacity == 0;
}

bool Container::insert(const Pair& pair)
{
  if (find(pair.first)) {return false;}
  Pair **newData = new Pair*[static_cast<unsigned int>(++capacity)];
  // allocate memory and copy data
  for (int i = 0; i < capacity - 1; i++)
  {
    newData[i] = new Pair(data[i]->getKey(), data[i]->getValue());
  }
  newData[capacity - 1] = new Pair(pair.first, pair.second);
  // free old data
  for (int i = 0; i < capacity - 1; i++)
  {
    delete data [i];
  }
  delete [] data;
  data = newData;
  sort();
  return true;
}

int Container::size() const
{
  return capacity;
}

Pair* Container::find(int find_first)
{
  for (int i = 0; i < capacity; i++)
  {
    if (data[i]->getKey() == find_first)
    {
      return data[i];
    }
  }
  return nullptr;
}

Pair* Container::end()
{
  return nullptr;
}

Pair* Container::begin()
{
  if (!empty()) {return data[0];}
  return nullptr;
}

int Container::getCount()
{
  return count;
}

ostream& operator <<(ostream& os, const Container& container)
{
  for (int i = 0; i < container.size(); i++)
  {
    os << "key: " << container.data[i]->getKey() << ", value: " << container.data[i]->getValue() << endl;
  }
  return os;
}

Container& Container::operator +=(const Container& container)
{
  for (int i = 0; i < container.size(); i++)
  {
    Pair* retPair = this->find(container.data[i]->first);
    if (retPair) {retPair->setPair(retPair->getKey(), retPair->getValue() + container.data[i]->getValue());}
    else {insert(*container.data[i]);}
  }
  sort();
  return *this;
}

Container Container::operator +(const Container& container)
{
  Container retContainer(*this);
  for (int i = 0; i < container.size(); i++)
  {
    Pair* retPair = retContainer.find(container.data[i]->getKey());
    if (retPair) {retPair->setPair(retPair->getKey(), retPair->getValue() + container.data[i]->getValue());}
    else {retContainer.insert(*container.data[i]);}
  }
  retContainer.sort();
  return retContainer;
}

Container& Container::operator -=(const Container& container)
{
  for (int i = 0; i < container.size(); i++)
  {
    Pair* retPair = this->find(container.data[i]->first);
    if (retPair) {retPair->setPair(retPair->getKey(), retPair->getValue() - container.data[i]->getValue());}
    else {insert(*container.data[i]);}
  }
  sort();
  return *this;
}

Container Container::operator -(const Container& container)
{
  Container retContainer(*this);
  for (int i = 0; i < container.size(); i++)
  {
    Pair* retPair = retContainer.find(container.data[i]->getKey());
    if (retPair) {retPair->setPair(retPair->getKey(), retPair->getValue() - container.data[i]->getValue());}
    // else {retContainer.insert(*container.data[i]);}
  }
  retContainer.sort();
  return retContainer;
}

void Container::operator *=(Container& container)
{
  // copy container 1 data to tempData, and delete container 1 data
  int tempCapacity = capacity;
  Pair** tempData = new Pair* [capacity];
  for (int i = 0; i < capacity; i++)
  {
    tempData[i] = new Pair(data[i]->getKey(), data[i]->getValue());
    delete data[i];
  }
  delete [] data;
  // copy container 2 data to container 1, and delete container 2 data
  capacity = container.size();
  data = new Pair* [container.size()];
  for (int i = 0; i < container.size(); i++)
  {
    data[i] = new Pair(container.data[i]->getKey(), container.data[i]->getValue());
    delete container.data[i];
  }
  delete [] container.data;
  // copy tempData to container 2
  container.capacity = tempCapacity;
  container.data = new Pair* [container.size()];
  for (int i = 0; i < container.size(); i++)
  {
    container.data[i] = new Pair(tempData[i]->getKey(), tempData[i]->getValue());
    delete tempData[i];
  }
  delete [] tempData;
  tempData = nullptr;
}

Container& Container::operator =(const Container& container)
{
  capacity = container.size();
  data = new Pair* [container.size()];
  for (int i = 0; i < container.size(); i++)
  {
    data[i] = new Pair(container.data[i]->getKey(), container.data[i]->getValue());
  }
  return *this;
}