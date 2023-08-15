#ifndef _BST_H
#define _BST_H_

struct node
{
  void* dataPtr;
  node* left;
  node* right;
};

class BST
{
  private:
    int count;
    int (*compare) (void* argu1, void* argu2);
    node* root;
  public:
    BST(int (*compare) (void* argu1, void* argu2));
    ~BST();
    bool BST_Insert(void* dataPtr);
    bool BST_Delete(void* dltKey);
    void BST_Traverse(void (*process) (void* dataPtr));
    bool BST_Empty();
    bool BST_Full();
    int BST_Count();
    node* _insert(node* Node, node* newPtr); //Call by BST_Insert
  private:
    void BST_Inorder(void (*process) (void* dataPtr), node* n);
    node* BST_Parent(node* parNode, node* childNode);
    node* BST_Successor(node* Node);
    node* BST_Mini(node* Node);
    node* BST_Key(node* Node, void* dltKey);
    node* createNode(void*);
    void BST_Free();
};

#endif