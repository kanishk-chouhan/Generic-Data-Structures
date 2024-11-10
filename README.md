
# Generic Data Structures in C
## _A Collection of Common Data Structures for C_

This project provides a collection of generic data structures in C that can be easily used in various applications. It includes implementations of fundamental data structures like AVL Tree, Doubly Linked List, Queue, Singly Linked List, and Stack with type-agnostic implementations.

## Features

- **AVL Tree (Balanced Binary Search Tree)**: A self-balancing binary search tree that ensures O(log n) complexity for insertion, deletion, and look-up operations.
- **Doubly Linked List**: A list where each element points to both its next and previous elements, allowing for efficient bidirectional traversal.
- **Queue**: A First-In-First-Out (FIFO) data structure implemented using a singly linked list.
- **Singly Linked List**: A basic list where each element points to the next, supporting basic list operations.
- **Stack**: A Last-In-First-Out (LIFO) data structure implemented using a singly linked list.

## Data Structures Included

### 1. **AVL Tree**

The AVL Tree provides efficient operations for inserting, removing, and searching for elements. It maintains balance through rotations.

**Key Operations:**
- `createAVLTree()`: Create a new AVL tree with a custom comparison function.
- `insertInToAVLTree()`: Insert an element into the AVL tree.
- `getSizeOfAVLTree()`: Get the size of the AVL tree.
- `getFromAVLTree()`: Get an element from the tree.
- `removeFromAVLTree()`: Remove an element from the tree.
- `clearAVLTree()`: Clear all elements in the tree.
- Iterators for traversing the tree in in-order, pre-order, and post-order.

### 2. **Doubly Linked List**

A doubly linked list implementation that supports operations like insertion, deletion, and traversal in both directions.

**Key Operations:**
- `createDoublyLinkedList()`: Create a new doubly linked list.
- `addToDoublyLinkedList()`: Add an element at the end.
- `insertInToDoublyLinkedList()`: Insert an element at a specific index.
- `removeFromDoublyLinkedList()`: Remove an element at a specific index.
- `getSizeOfDoublyLinkedList()`: Get the size of the list.
- Iterators for traversing the list in both directions.

### 3. **Queue**

The Queue data structure is implemented using a singly linked list and supports typical queue operations like enqueue, dequeue, and peek.

**Key Operations:**
- `createQueue()`: Create a new queue.
- `addToQueue()`: Add an element to the queue.
- `removeFromQueue()`: Remove an element from the queue.
- `elementAtFrontOfQueue()`: Get the element at the front of the queue.
- `isQueueEmpty()`: Check if the queue is empty.

### 4. **Singly Linked List**

A singly linked list where each node contains a pointer to the next node. This basic data structure supports efficient insertion and deletion at the front and end of the list.

**Key Operations:**
- `createSinglyLinkedList()`: Create a new singly linked list.
- `addToSinglyLinkedList()`: Add an element at the end.
- `insertInToSinglyLinkedList()`: Insert an element at a specific index.
- `removeFromSinglyLinkedList()`: Remove an element at a specific index.
- `getSizeOfSinglyLinkedList()`: Get the size of the list.

### 5. **Stack**

A stack data structure implemented using a singly linked list, supporting push, pop, and top operations.

**Key Operations:**
- `createStack()`: Create a new stack.
- `pushOnStack()`: Push an element onto the stack.
- `popFromStack()`: Pop an element from the stack.
- `elementAtTopOfStack()`: Peek the top element.
- `isStackEmpty()`: Check if the stack is empty.

## Tech Stack

- **C**: All data structures are implemented in C.
- **Singly Linked List**: Used internally for implementing Queue, Stack, and other structures.
- **Stack**: Used for tree traversals and other auxiliary operations.

## Installation

To use the data structures, simply clone the repository and include the header files in your project.

```sh
git clone https://github.com/kanishk-chouhan/Generic-Data-Structure-in-C.git

Add the .c and .h files to your project and compile them along with your application.

## Usage

Example of Using the AVL Tree

Code:

```#include "tm_avl.h"

int compare(void *a, void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x - y);
}

int main() {
    bool success;
    AVLTree *avlTree = createAVLTree(compare, &success);
    int val = 10;
    insertInToAVLTree(avlTree, &val, &success);

    printf("AVL Tree size: %d\n", getSizeOfAVLTree(avlTree));
    return 0;
}
```

Compilation:

```gcc -o avl_example main.c tm_avl.c tm_stack.c tm_common.c
./avl_example
```

Example of Using the Queue

Code:

```#include "tm_queue.h"

int main() {
    bool success;
    Queue *queue = createQueue(&success);
    int val = 5;
    addToQueue(queue, &val, &success);

    printf("Front element: %d\n", *(int *)elementAtFrontOfQueue(queue, &success));
    return 0;
}
```
Compilation:

```gcc -o queue_example main.c tm_queue.c tm_sll.c tm_common.c
./queue_example
```

# Contact

#### Email: kanishk.chouhan@example.com

#### LinkedIn: Kanishk Chouhan
