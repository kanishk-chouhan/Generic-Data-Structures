#ifndef __TM_QUEUE__H
#define __TM_QUEUE__H 123
#include<tm_sll.h>
typedef struct __$_tm_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;
Queue * createQueue(bool *success);
void addToQueue(Queue *queue,void *ptr,bool *success);
void * removeFromQueue(Queue *queue,bool *success);
void * elementAtFrontOfQueue(Queue *queue,bool *success);
int getSizeOfQueue(Queue *queue);
bool isQueueEmpty(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif