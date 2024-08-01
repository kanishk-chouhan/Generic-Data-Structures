#ifndef __TM_SLL__H
#define __TM_SLL__H 123
#include<tm_common.h>
typedef struct __$_tm_sll_node
{
void *ptr;
struct __$_tm_sll_node *next;
}SinglyLinkedListNode;
typedef struct __$_tm_sll
{
struct __$_tm_sll_node *start;
struct __$_tm_sll_node *end;
int size;
}SinglyLinkedList;
typedef struct __$_tm_sll_iteraor
{
struct __$_tm_sll_node *node;
}SinglyLinkedListIterator;
SinglyLinkedList * createSinglyLinkedList(bool *success);
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success);
void insertInToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success);
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success);
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList);
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success);
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator);
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success);
#endif