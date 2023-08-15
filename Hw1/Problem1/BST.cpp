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
    // case 1 (0 children)
    if (dltNode->left == nullptr && dltNode->right == nullptr)
    {
      node* parNode = BST_Parent(root, dltNode);
      // left child
      if (compare(parNode->dataPtr, dltNode->dataPtr) == 0) {parNode->left = nullptr;}
      // right child
      else if (compare(parNode->dataPtr, dltNode->dataPtr) == 1) {parNode->right = nullptr;}
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      dltNode->dataPtr = nullptr;
      delete dltNode;
      dltNode = nullptr;
    }
    // case 2 (1 child)
    else if (dltNode->left == nullptr || dltNode->right == nullptr)
    {
      node* parNode = BST_Parent(root, dltNode);
      // left child
      if (compare(parNode->dataPtr, dltNode->dataPtr) == 0)
      {
        // dlt Node have left child
        if (dltNode->left != nullptr) {parNode->left = dltNode->left;}
        // dlt Node have right child
        else if (dltNode->right != nullptr) {parNode->left = dltNode->right;}
      }
      // right child
      else if (compare(parNode->dataPtr, dltNode->dataPtr) == 1)
      {
        // dlt Node have left child
        if (dltNode->left != nullptr) {parNode->right = dltNode->left;}
        // dlt Node have right child
        else if (dltNode->right != nullptr) {parNode->right = dltNode->right;}
      }
      // root
      else if (compare(parNode->dataPtr, dltNode->dataPtr) == 2)
      {
        // root Node have left child
        if (dltNode->left != nullptr) {root = dltNode->left;}
        // root Node have right child
        else if (dltNode->right != nullptr) {root = dltNode->right;}
      }
      if (dltNode->left != nullptr) {dltNode->left = nullptr;}
      else if (dltNode->right != nullptr) {dltNode->right = nullptr;}
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      dltNode->dataPtr = nullptr;
      delete dltNode;
      dltNode = nullptr;
    }
    // case 3 (2 children)
    else if (dltNode->left != nullptr && dltNode->right != nullptr)
    {
      node* sucNode = BST_Successor(dltNode);
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      if (count == 3) // delete the root, only have root and two leaves
      {
        root = sucNode;
        root->left = dltNode->left;
        dltNode->left = nullptr;
        dltNode->dataPtr = nullptr;
        delete dltNode;
        dltNode = nullptr;
      }
      else
      {
        node* parNode = BST_Parent(root, sucNode);
        dltNode->dataPtr = sucNode->dataPtr;
        parNode->left = (sucNode->right != nullptr) ? sucNode->right : nullptr;
        sucNode->left = nullptr;
        sucNode->right = nullptr;
        delete sucNode;
        sucNode = nullptr;
      }
    }
    count--;
    return true;
  }
}

void BST::BST_Traverse(void (*process) (void *dataPtr))
{
  if (BST_Empty()) {cout << "The BST is empty." << endl;}
  else
  {
    BST_Inorder(process, root);
    cout << endl;
  }
}

bool BST::BST_Empty()
{
  return (count) ? false : true;
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

node* BST::_insert(node* Node, node* newPtr)
{
  if (Node == nullptr) {Node = newPtr;}
  // Node > new num
  else if (compare(Node->dataPtr, newPtr->dataPtr) == 0) {Node->left = _insert(Node->left, newPtr);}
  // Node < new num
  else if (compare(Node->dataPtr, newPtr->dataPtr) == 1) {Node->right = _insert(Node->right, newPtr);}

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
  // Node > dlt Node
  if (compare(parNode->dataPtr, childNode->dataPtr) == 0)
  {
    if (compare(parNode->left->dataPtr, childNode->dataPtr) == 2) {return parNode;}
    else {return BST_Parent(parNode->left, childNode);}
  }
  // Node < dlt Node
  else if (compare(parNode->dataPtr, childNode->dataPtr) == 1)
  {
    if (compare(parNode->right->dataPtr, childNode->dataPtr) == 2) {return parNode;}
    else {return BST_Parent(parNode->right, childNode);}
  }
  // no parent, root
  else {return parNode;}
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
  if (Node == nullptr) {return nullptr;}
  else if (compare(Node->dataPtr, dltKey) == 0) {return BST_Key(Node->left, dltKey);}
  else if (compare(Node->dataPtr, dltKey) == 1) {return BST_Key(Node->right, dltKey);}
  else {return Node;}
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
    if (root->left == nullptr && root->right == nullptr)
    {
      delete reinterpret_cast<int*>(root->dataPtr);
      delete root;
      root = nullptr;
    }
    // case 2 (1 child)
    else if (root->left == nullptr || root->right == nullptr)
    {
      node* dltNode = root;
      // root Node have left child
      if (root->left != nullptr)
      {
        root = dltNode->left;
        dltNode->left = nullptr;
      }
      // root Node have right child
      else if (root->right != nullptr)
      {
        root = dltNode->right;
        root->right = nullptr;
      }
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      dltNode->dataPtr = nullptr;
      delete dltNode;
      dltNode = nullptr;
    }
    // case 3 (2 children)
    else if (root->left != nullptr && root->right != nullptr)
    {
      node* dltNode = root;
      node* sucNode = BST_Successor(dltNode);
      delete reinterpret_cast<int*>(dltNode->dataPtr);
      if (count == 3) // delete the root, only have root and two leaves
      {
        root = sucNode;
        root->left = dltNode->left;
        dltNode->left = nullptr;
        dltNode->dataPtr = nullptr;
        delete dltNode;
        dltNode = nullptr;
      }
      else
      {
        node* parNode = BST_Parent(root, sucNode);
        dltNode->dataPtr = sucNode->dataPtr;
        parNode->left = (sucNode->right != nullptr) ? sucNode->right : nullptr;
        sucNode->left = nullptr;
        sucNode->right = nullptr;
        delete sucNode;
        sucNode = nullptr;
      }
    }
  }
}