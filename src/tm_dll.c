#ifndef __TM_DLL__C
#define __TM_DLL__C 123
#include<stdlib.h>
#include<tm_dll.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
DoublyLinkedList *doublyLinkedList;
if(success) *success=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
DoublyLinkedListNode *node;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;
if(success) *success=true;
}
void insertInToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *node,*p1;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL) return;
if(index<0 || index>doublyLinkedList->size) return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
if(success) *success=true;
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->next=NULL;
node->previous=NULL;
node->ptr=ptr;
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start->previous=node;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success) *success=true;
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
node->next=p1;
node->previous=p1->previous;
p1->previous->next=node;
p1->previous=node;
doublyLinkedList->size++;
if(success) *success=true;
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL || doublyLinkedList->size==0) return 0;
return doublyLinkedList->size;
}
void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p1;
int x;
void *ptr;
ptr=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL || doublyLinkedList->start==NULL) return ptr;
if(index< 0 || index>=doublyLinkedList->size) return ptr;
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(success) *success=true;
return ptr;
}
void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p1;
int x;
void *ptr;
if(success) *success=false;
if(doublyLinkedList==NULL || doublyLinkedList->start==NULL) return ptr;
if(index<0 || index>=doublyLinkedList->size) return ptr;
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(p1==doublyLinkedList->start && p1==doublyLinkedList->end)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
if(p1==doublyLinkedList->start)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
if(p1==doublyLinkedList->end)
{
doublyLinkedList->end=doublyLinkedList->end->previous;
doublyLinkedList->end->next=NULL;
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
free(p1);
doublyLinkedList->size--;
if(success) *success=true;
return ptr;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *node,*s,*e,*t;
bool done;
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->start==NULL)
{
if(success) *success=true;
return;
}
done=true;
s=NULL;
e=NULL;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
node->previous=NULL;
if(s==NULL && e==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
node->previous=e;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
s->previous=NULL;
free(node);
}
e=NULL;
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
s->previous=targetDoublyLinkedList->end;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
return;
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListIterator;
doublyLinkedListIterator.node=doublyLinkedList->start;
if(success) *success=true;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL) return false;
if(doublyLinkedListIterator->node==NULL) return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)
{
void *ptr;
ptr=NULL;
if(success) *success=false;
if(doublyLinkedListIterator==NULL) return ptr;
if(doublyLinkedListIterator->node==NULL) return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}

//reverse
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success) *success=false;
if(doublyLinkedList==NULL) return doublyLinkedListReverseIterator;
if(doublyLinkedList->start==NULL) return doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
if(success) *success=true;
return doublyLinkedListReverseIterator;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node==NULL) return false;
return true;
}
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success)
{
void *ptr;
ptr=NULL;
if(success) *success=false;
if(doublyLinkedListReverseIterator==NULL) return ptr;
if(doublyLinkedListReverseIterator->node==NULL) return ptr;
ptr=doublyLinkedListReverseIterator->node->ptr;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
if(success) *success=true;
return ptr;
}
#endif