#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

void insert(vector<int>&);
void pop(vector<int>&);
bool check(int, int);
void output(vector<int>);
void output_tree(vector<int>);

int main(int argc, char* argv[])
{
  ifstream ifs(argv[1], ios::binary | ios::in);
  vector<int> heap;
  int temp;
  while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(int)))
  {
    heap.push_back(temp);
    if (heap.size() > 1) {insert(heap);}
    cout << temp << " ";
  }
  ifs.close();
  cout << endl;
  output_tree(heap);
  while (!heap.empty())
  {
    cout << heap[0] << " ";
    pop(heap);
  }
  cout << endl;
  return 0;
}

void insert(vector<int>& heap)
{
  int index = heap.size() - 1;
  while (index > 0)
  {
    int parent = !(index % 2) ? index / 2 - 1 : index / 2;
    if (!check(heap[parent], heap[index]))
    {
      swap(heap[parent], heap[index]);
    }
    index = parent;
  }
}

void pop(vector<int>& heap)
{
  swap(heap[heap.size() - 1], heap[0]);
  heap.pop_back();
  int index = 0;
  while (index * 2 + 1 < static_cast<int>(heap.size()))
  {
    if ((index * 2 + 2) >= static_cast<int>(heap.size())) // no right child
    {
      if (heap[index * 2 + 1] < heap[index]) // left
      {
        swap(heap[index * 2 + 1], heap[index]);
        index = index * 2 + 1;
      }
      else {break;}
    }
    else // has right child
    {
      if (heap[index * 2 + 1] < heap[index] || heap[index * 2 + 2] < heap[index])
      {
        if (heap[index * 2 + 1] < heap[index * 2 + 2]) // left < right
        {
          swap(heap[index * 2 + 1], heap[index]);
          index = index * 2 + 1;
        }
        else // left > right
        {
          swap(heap[index * 2 + 2], heap[index]);
          index = index * 2 + 2;
        }
      }
      else {break;}
    }
  }
}

bool check(int x, int y)
{
  return (x < y);
}

void output(vector<int> heap)
{
  for (int i: heap)
  {
    cout << i << " ";
  }
  cout << endl;
}

void output_tree(vector<int> heap)
{
  for (int i = 0; i < static_cast<int>(heap.size()); i++)
  {
    cout << setw(2) << heap[i] << "  ";
    if (!((i + 2) & (i + 1)) || i == 0) {cout << endl;}
  }
  cout << endl;
}