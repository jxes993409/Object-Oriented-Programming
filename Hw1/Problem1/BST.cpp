#include <iostream>
#include <cassert>
#include "BST.h"

using namespace std;

BST::BST(int (*compare) (void* argu1, void* argu2))
{
  count = 0;
  this->compare = compare;
  root = nullptr;
}

BST::~BST()
{
  BST_Free();
}

bool BST::BST_Insert(void* dataPtr)
{
  node* newNode = createNode(dataPtr);
  root = _insert(root, newNode);
  count++;
  return true;
}

bool BST::BST_Delete(void *dltKey)
{
  node* dltNode = BST_Key(root, dltKey);
  if (dltNode == nullptr)
  {
    cout << "The number is not in BST." << endl;
    return false;
  }
  else
  {
    // y = dltNode or Successor(dltNode)
    node* y;
    if (dltNode->left == nullptr || dltNode->right == nullptr) {y = dltNode;}
    else {y = BST_Successor(dltNode);}

    // x = non NIL child of y or NIL
    node* x;
    if (y->left != nullptr) {x = y->left;}
    else if (y->right != nullptr) {x = y->right;}
    else {x = nullptr;}

    // splice out y and modify pointers in parent(y)
    node* par_y = BST_Parent(root, y);
    int y_pos;
    // y = 0 (left child)
    // y = 1 (right child)
    // y = -1 (parent(y) = NIL)
    if (par_y != nullptr) {y_pos = (par_y->left == y) ? 0 : 1;}
    else {y_pos = -1;}

    if (x != nullptr)
    {
      // parent(y)->leaf is defined by y_pos
      if (y_pos == 0) {par_y->left = x;}
      else if (y_pos == 1) {par_y->right = x;}
    }

    bool dltRoot = false;
    if (par_y == nullptr)
    {
      root = (x == nullptr) ? root : x;
      dltRoot = (x == nullptr) ? true : false;
    }
    else if (x == nullptr)
    {
      if (y_pos == 0) {par_y->left = x;}
      else if (y_pos == 1) {par_y->right = x;}
    }

    // if y = successor(dltNode), move y->dataPtr to dltNode->dataPtr
    // then delete y
    if (y != dltNode)
    {
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      dltNode->dataPtr = y->dataPtr;
      y->left = nullptr;
      y->right = nullptr;
      delete y;
      y = nullptr;
    }
    // delete dltNode
    else
    {
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      dltNode->dataPtr = nullptr;
      delete dltNode;
      dltNode = nullptr;
      // fix root do not point to NIL
      if (dltRoot) {root = nullptr;}
    }

    count--;
    return true;
  }
}

void BST::BST_Traverse(void (*process) (void *dataPtr))
{
  if (BST_Empty())
  {
    cout << "The BST is empty." << endl;
  }
  else
  {
    BST_Inorder(process, root);
    cout << endl;
  }
}

bool BST::BST_Full()
{
  node* tempNode = new node;
  assert(tempNode != nullptr);
  delete tempNode;
  tempNode = nullptr;
  return true;
}

int BST::BST_Count()
{
  return count;
}

bool BST::BST_Empty()
{
  return (count) ? false : true;
}

node* BST::_insert(node* Node, node* newPtr)
{
  int cmpValue = (Node == nullptr) ? -1 : compare(Node->dataPtr, newPtr->dataPtr);
  if (Node == nullptr) {Node = newPtr;}
  // Node > new num
  else if (cmpValue == 0) {Node->left = _insert(Node->left, newPtr);}
  // Node < new num
  else {Node->right = _insert(Node->right, newPtr);}

  return Node;
}

void BST::BST_Inorder(void (*process) (void* dataPtr), node* n)
{
  if (n == nullptr) return;
  BST_Inorder(process, n->left);
  process(n->dataPtr);
  BST_Inorder(process, n->right);
}

node* BST::BST_Parent(node* parNode, node* childNode)
{
  int cmpValue = compare(parNode->dataPtr, childNode->dataPtr);
  switch (cmpValue)
  {
  case 0:
    // Node > dlt Node
    return (parNode->left->dataPtr == childNode->dataPtr) ? parNode : BST_Parent(parNode->left, childNode);
    break;
  case 1:
    // Node < dlt Node
    return (parNode->right->dataPtr == childNode->dataPtr) ? parNode : BST_Parent(parNode->right, childNode);
    break;
  default:
    // no parent, root
    return nullptr;
    break;
  }
}

node* BST::BST_Successor(node* Node)
{
  if (Node->right != nullptr) {return BST_Mini(Node->right);}
  // ancNode is the lowest ancestor of Node whose left child is also an ancestor of x
  // (Node is ancNode's predecessor)
  else
  {
    node* ancNode = BST_Parent(root, Node);
    while (ancNode != nullptr && Node == ancNode->right)
    {
      Node = ancNode;
      ancNode = BST_Parent(root, ancNode);
    }
    return ancNode;    
  }
}

node* BST::BST_Mini(node* Node)
{
  if (Node->left != nullptr) {return BST_Mini(Node->left);}
  else {return Node;}
}

node* BST::BST_Key(node* Node, void* dltKey)
{
  int cmpValue = (Node == nullptr) ? -5 : compare(Node->dataPtr, dltKey);
  if (Node == nullptr) {return nullptr;} // Node = nullptr
  else if (cmpValue == 0) {return BST_Key(Node->left, dltKey);} // Node > dltKey
  else if (cmpValue == 1) {return BST_Key(Node->right, dltKey);} // Node < dltKey
  else {return Node;} // Node = dltKey
}

node* BST::createNode(void* dataPtr)
{
  node* newNode = new node;
  newNode->dataPtr = dataPtr;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

void BST::BST_Free()
{
  while (root != nullptr)
  {
    BST_Delete(root->dataPtr);
  }
}