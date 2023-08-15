#include <iostream>
#include "BST.h"

using namespace std;

int compareInt(void* num1, void* num2);
void printBST(void* num);
void printMenu();

int main()
{
  int option;
  BST bst(compareInt);
  printMenu();
  while (cin >> option)
  {
    if (option == 1)
    {
      int* insert_num = new int;
      cout << "Enter an interger: ";
      cin >> *insert_num;
      bst.BST_Insert(reinterpret_cast<void*>(insert_num));
    }
    else if (option == 2)
    {
      int* del_num = new int;
      cout << "Enter an interger: ";
      cin >> *del_num;
      bool find;
      find = bst.BST_Delete(reinterpret_cast<void*>(del_num));
      if (find)
      {
        if (bst.BST_Count()) {cout << "New BST: ";}
        bst.BST_Traverse(printBST);
      }
    }
    else if (option == 3)
    {
      bst.BST_Traverse(printBST);
    }
    else if (option == 4)
    {
      if (bst.BST_Full())
      {
        cout << "BST is not full yet" << endl;
      }
    }
    else if (option == 5)
    {
      cout << "There are " << bst.BST_Count() <<" nodes in BST." << endl;
    }
    else if (option == 6)
    {
      cout << "<End of Program>" << endl;
      break;
    }
    printMenu();
  }
  return 0;
}

int compareInt(void* num1, void* num2)
{
  if (*reinterpret_cast<int*>(num1) > *reinterpret_cast<int*>(num2)) {return 0;} // root > new num
  else if (*reinterpret_cast<int*>(num1) < *reinterpret_cast<int*>(num2)) {return 1;} // root < new num
  else {return 2;} // root = new num
}

void printBST(void* num)
{
  cout << *reinterpret_cast<int*>(num) << " ";
}

void printMenu()
{
  cout << "The following are six options for your BST:" << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Print the BST" << endl;
  cout << "4. Check the BST is full or not" << endl;
  cout << "5. Print the number of nodes in BST" << endl;
  cout << "6. Exit" << endl;
  cout << "Please enter: ";
}