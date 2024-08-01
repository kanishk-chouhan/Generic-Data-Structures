#ifndef __TM_AVL__C
#define __TM_AVL__C
#include<tm_avl.h>
#include<stdlib.h>
#include<stdio.h>
#include<tm_stack.h>
AVLTree * createAVLTree(int (*predicate)(void *,void *),bool *success)
{
AVLTree *avlTree;
if(success) *success=false;
if(predicate==NULL) return NULL;
avlTree=(AVLTree *)malloc(sizeof(AVLTree));
if(avlTree==NULL) return NULL;
avlTree->start=NULL;
avlTree->size=0;
avlTree->predicate=predicate;
if(success) *success=true;
return avlTree;
}
void insertInToAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
AVLTreeNode *t,*j;
int weight;
bool succ;
Stack *stack;
if(success) *success=false;
if(avlTree==NULL || ptr==NULL) return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
if(success) *success=true;
avlTree->size++;
return;
}
stack=createStack(&succ);
if(succ==false) return;
j=avlTree->start;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0) return;
pushOnStack(stack,(void *)j,&succ);
if(succ==false)
{
destroyStack(stack);
return;
}
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL) return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
if(success) *success=true;
avlTree->size++;
balanceTheAVLTree(avlTree,stack);
}

int getSizeOfAVLTree(AVLTree *avlTree)
{
return avlTree->size;
}

int getHeightOfAVLTree(AVLTreeNode *root)
{
int leftHeight,rightHeight;
if(root==NULL) return 0;
leftHeight=getHeightOfAVLTree(root->left);
rightHeight=getHeightOfAVLTree(root->right);
if(leftHeight>rightHeight) return leftHeight+1;
else return rightHeight+1;
}

void * getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
AVLTreeNode *t;
int weight;
if(success) *success=false;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
if(success) *success=true;
return t->ptr;
}
void * removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
AVLTreeNode *t,*j,*e,*f;
AVLTreeNode **p2p;
void *foundPtr;
int weight;
if(success) *success=false;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
if(ptr==NULL) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) break;
j=t;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL) return NULL;
foundPtr=t->ptr;
if(avlTree->start==t) p2p=&(avlTree->start);
else if(j->left==t) p2p=&(j->left);
else p2p=&(j->right);
if(t->left==t->right)
{
*p2p=NULL;
}
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left)
{
f=e;
}
if(t->right==e)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
}
*p2p=e;
} // successor part ends here
else
{
for(e=t->left;e->right!=NULL;e=e->right)
{
f=e;
}
if(t->left!=e)
{
f->right=e->left;
e->left=t->left;
e->right=t->right;
}
*p2p=e;
} // predecessor part ends here
}
if(success) *success=true;
avlTree->size--;
return foundPtr;
}

void balanceTheAVLTree(AVLTree *avlTree,Stack *stack)
{
AVLTreeNode *root,*rc,*lc,*rclc,*lcrc,*j,*parent;
AVLTreeNode **p2p;
bool succ;
int lch,rch,diff;
while(!isStackEmpty(stack))
{
root=(AVLTreeNode *)popFromStack(stack,&succ);
lch=getHeightOfAVLTree(root->left);
rch=getHeightOfAVLTree(root->right);
diff=lch-rch;
if(diff>=-1 && diff<=1) continue;
if(root==avlTree->start)	
{
p2p=&(avlTree->start);
}
else
{
parent=(AVLTreeNode *)elementAtTopOfStack(stack,&succ);
if(root==parent->left) p2p=&(parent->left);
else p2p=&(parent->right);
}
if(lch<rch)     // right is heavy
{
rc=root->right;
if(getHeightOfAVLTree(rc->left)>getHeightOfAVLTree(rc->right)) // right is left heavy
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else        
{
lc=root->left;
if(getHeightOfAVLTree(lc->right)>getHeightOfAVLTree(lc->left)) // right is left heavy
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}
}
void clearAVLTree(AVLTree *avlTree)
{

}
void destroyAVLTree(AVLTree *avlTree)
{

}
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeInOrderIterator avlTreeInOrderIterator;
AVLTreeNode *j;
bool succ;
if(success) *success=false;
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
if(avlTree==NULL) return avlTreeInOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreeInOrderIterator;
j=avlTree->start;
while(j!=NULL)
{
pushOnStack(avlTreeInOrderIterator.stack,(void *)j,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
j=j->left;
}
avlTreeInOrderIterator.node=(AVLTreeNode *)popFromStack(avlTreeInOrderIterator.stack,&succ);
if(success) *success=true;
return avlTreeInOrderIterator;
}
bool hasNextInAVLTreeInOrderIterator(AVLTreeInOrderIterator *avlTreeInOrderIterator)
{
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return false;
return true;
}
void * getNextElementFromAVLTreeInOrderIterator(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success)
{
AVLTreeNode *j,*t;
bool succ;
if(success) *success=false;
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return NULL;
j=avlTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(avlTreeInOrderIterator->stack))
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
}
else
{
avlTreeInOrderIterator->node=(AVLTreeNode *)popFromStack(avlTreeInOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
}

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreePreOrderIterator avlTreePreOrderIterator;
bool succ;
avlTreePreOrderIterator.node=NULL;
avlTreePreOrderIterator.stack=NULL;
if(success) *success=false;
if(avlTree==NULL) return avlTreePreOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreePreOrderIterator;
}
avlTreePreOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePreOrderIterator;
avlTreePreOrderIterator.node=avlTree->start;
if(success) *success=true;
return avlTreePreOrderIterator;
}
bool hasNextInAVLTreePreOrderIterator(AVLTreePreOrderIterator *avlTreePreOrderIterator)
{
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL) return false;
return true;
}
void * getNextElementFromAVLTreePreOrderIterator(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
bool succ;
if(success) *success=false;
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL) return NULL;
j=avlTreePreOrderIterator->node;
if(j->right!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->right,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(j->left!=NULL)
{
pushOnStack(avlTreePreOrderIterator->stack,(void *)j->left,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
if(isStackEmpty(avlTreePreOrderIterator->stack))
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
}
else
{
avlTreePreOrderIterator->node=(AVLTreeNode *)popFromStack(avlTreePreOrderIterator->stack,&succ);
}
if(success) *success=true;
return j->ptr;
}

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreePostOrderIterator avlTreePostOrderIterator;
AVLTreeNode *t;
bool succ;
if(success) *success=false;
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(avlTree==NULL) return avlTreePostOrderIterator;
if(avlTree->start==NULL)
{
if(success) *success=true;
return avlTreePostOrderIterator;
}
avlTreePostOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePostOrderIterator;
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator.stack,(void *)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
}
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
t=t->left;
}
t=(AVLTreeNode *)popFromStack(avlTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator.stack) && t->right!=NULL && t->right==(AVLTreeNode *)elementAtTopOfStack(avlTreePostOrderIterator.stack,&succ))
{
popFromStack(avlTreePostOrderIterator.stack,&succ);
pushOnStack(avlTreePostOrderIterator.stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.stack=NULL;
return avlTreePostOrderIterator;
}
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator.node=t;
if(success) *success=true;
return avlTreePostOrderIterator;
}
bool hasNextInAVLTreePostOrderIterator(AVLTreePostOrderIterator *avlTreePostOrderIterator)
{
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return false;
return true;
}

void * getNextElementFromAVLTreePostOrderIterator(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
bool succ;
if(success) *success=false;
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return NULL;
j=avlTreePostOrderIterator->node;
if(isStackEmpty(avlTreePostOrderIterator->stack))
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=NULL;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)
{
pushOnStack(avlTreePostOrderIterator->stack,(void *)t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
}
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=t->left;
}
t=(AVLTreeNode *)popFromStack(avlTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator->stack) && t->right!=NULL && t->right==(AVLTreeNode *)elementAtTopOfStack(avlTreePostOrderIterator->stack,&succ))
{
popFromStack(avlTreePostOrderIterator->stack,&succ);
pushOnStack(avlTreePostOrderIterator->stack,(void *)t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->stack=NULL;
avlTreePostOrderIterator->node=NULL;
if(success) *success=true;
return j->ptr;
}
t=t->right;
}
else
{
break;
}
}
avlTreePostOrderIterator->node=t;
if(success) *success=true;
return j->ptr;
}
#endif