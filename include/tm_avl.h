#ifndef __TM_AVL__H
#define __TM_AVL__H 123
#include<tm_common.h>
#include<tm_stack.h>
typedef struct __$_tm_avl_node
{
void *ptr;
struct __$_tm_avl_node *left;
struct __$_tm_avl_node *right;
}AVLTreeNode;
typedef struct __$_tm_avl
{
struct __$_tm_avl_node *start;
int (*predicate)(void *,void *);
int size;
}AVLTree;
typedef struct __$_tm_avlTree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreeInOrderIterator;

typedef struct __$_tm_avlTree_pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePreOrderIterator;

typedef struct __$_tm_avlTree_post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePostOrderIterator;


AVLTree * createAVLTree(int (*predicate)(void *,void *),bool *success);
void insertInToAVLTree(AVLTree *avlTree,void *ptr,bool *success);
int getSizeOfAVLTree(AVLTree *avlTree);
int getHeightOfAVLTree(AVLTreeNode *root);
void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void clearAVLTree(AVLTree *avlTree);
void destroyAVLTree(AVLTree *avlTree);
void balanceTheAVLTree(AVLTree *avlTree,Stack *stack);

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInAVLTreeInOrderIterator(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void * getNextElementFromAVLTreeInOrderIterator(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInAVLTreePreOrderIterator(AVLTreePreOrderIterator *avlTreePreOrderIterator);
void * getNextElementFromAVLTreePreOrderIterator(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success);


AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInAVLTreePostOrderIterator(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void * getNextElementFromAVLTreePostOrderIterator(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);
#endif