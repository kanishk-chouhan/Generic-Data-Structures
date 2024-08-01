#ifndef __TM_STACK__C
#define __TM_STACK__C 123
#include<tm_stack.h>
#include<stdlib.h>
#include<tm_sll.h>
Stack * createStack(bool *success)
{
SinglyLinkedList *singlyLinkedList;
Stack *stack;
singlyLinkedList=createSinglyLinkedList(success);
if(*success==false) return NULL;
stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
stack->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return stack;
}
void pushOnStack(Stack *stack,void *ptr,bool *success)
{
if(success) *success=false;
if(stack==NULL || stack->singlyLinkedList==NULL) return;
insertInToSinglyLinkedList(stack->singlyLinkedList,0,ptr,success);
}
void * popFromStack(Stack *stack,bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackEmpty(stack)) return NULL;
ptr=removeFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(*success==false) return NULL;
return ptr;
}
void * elementAtTopOfStack(Stack *stack,bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackEmpty(stack)) return NULL;
ptr=getFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(*success==false) return NULL;
return ptr;
}
int getSizeOfStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL) return 0;
if(stack->singlyLinkedList->start==NULL) return 0;
return getSizeOfSinglyLinkedList(stack->singlyLinkedList);
}
bool isStackEmpty(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL) return true;
if(stack->singlyLinkedList->start==NULL) return true;
return false;
}
void clearStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList->start==NULL) return;
clearSinglyLinkedList(stack->singlyLinkedList);
}
void destroyStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList->start==NULL) return;
destroySinglyLinkedList(stack->singlyLinkedList);
free(stack);
}
#endif