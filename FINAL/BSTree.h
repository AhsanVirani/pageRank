// Binary Search Tree ADT interface ...

#ifndef BSTREE_H
#define BSTREE_H

#include "list.h"
#include <stdbool.h>

typedef char * Key;      // item is just a key

#define data(tree)  ((tree)->word)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

typedef struct t_Node {
   Key  word;
   List Url_List;
   struct t_Node *left, *right;
} t_Node;


typedef struct t_Node *Tree;

Tree newTree();        // create an empty Tree
void freeTree(Tree);   // free memory associated with Tree
void showTree(Tree);   // display a Tree (sideways)

bool TreeSearch(Tree, Key);   // check whether an item is in a Tree
int  TreeHeight(Tree);         // compute height of Tree
int  TreeNumNodes(Tree);       // count #nodes in Tree
Tree TreeInsert(Tree, Key, Key);   // insert a new item into a Tree
Tree TreeDelete(Tree, Key);   // delete an item from a Tree

// internal functions made visible for testing
Tree rotateRight(Tree);
Tree rotateLeft(Tree);
//Tree insertAtRoot(Tree, Key);
Tree partition(Tree, int);
Tree rebalance(Tree);

#endif 
