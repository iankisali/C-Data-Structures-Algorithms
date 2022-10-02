# Doubly Linked List
**Doubly Linked List (DLL)**
: also called *two - way linked list* is a variation of Singly Linked List in which navigation is in both ways, either forward or backward.

A doubly linked list is a type of linked list in which the node consits of 3 components:
- ***prev** - address of previous node
- ***next** - address of next node
- **data** - data item

Below is a pictorial representation of a Doubly Linked List :

![DLL](https://cdn.programiz.com/cdn/farfuture/mljtoHadEO77LO97a_D4AP54FZNVSrSSZ32UVNV53Yg/mtime:1620967584/sites/tutorial2program/files/doubly-linked-list-created.png)

In C, a single node of a doubly linked list is represented as follows:
```
struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
}
```
Each struct node has a data item, pointer to previous struct node and a pointer to next struct node.

### Properties of Doubly Linked List
1. Doubly Linked List contains a link element called first and Last
2. Each link carries a data field(s) and two links called next and prev
3. Each link is linked with its next using next link
4. Each link is linked with its previous link using its previous link
5. The last link carries a link as NULL 

### Advantages of DLL over singly linked list :
1. Can be traversed in both forward and backward directions.
2. Deletion is more efficient if pointer to node to be deleted is given
3. Insertion is easy.

### Disadvantages of DLL over singly linked list :
1. An extra space is required for a previous pointer in a node.

---

## Header File
**`header.h`** file contains group of related function declaration and macro definitions to be shared with various source files. At the source files the header file is included using the preprocessing directive `#include "header.h"`. The construct of the header file is a **wrapper *`#ifndef`*** and this is the format used :

```
#ifndef _HEADER_
#define _HEADER_

The entire header file

#endif
```
Including header files produces same results as copying header file into each source file that needs it wich would be time consuming and hence the related declarations are in one place.

---
## Printing a List
**`printList.c`** file contains code to print a Linked List. It print the data in the first node and updates the value to the next node. The loop ends when the data is NULL.
**`printReverseRec`** contains code to print the list in reverse using recursion. The base case is when the temp value equals to a NULL. Otherwise the `printReverseRec` will be called inside the function. Once NULL is reached, the values will now be printed in reverse.

---

## Inserting a Node
Adding a node to a doubly linked list is similar to adding a node to a singly linked list but extra work is required to handle extra pointer to previous node.

We can insert elements at :
- Insertion at beggining
- Insertion between nodes
- Insertion at end

### Insertion at the Beginning
A new node can be added before head of a DLL and the new nodes becomes the new head of the list.

Steps include:
1. Allocate a new node and assign data into the new node
2. Point next of new node to first node of DLL and point prev to NULL
3. Point prev of first node to new node
4. Point head to new node

### Insertion after a node
Steps include :
1. Create a new node, allocate memory and assign data
2. Assign value of next of previous node to next of new node
3. Assign address of new node to nextof previous node
4. Assign address of new node to next of previous node
5. Assign value of previous of next node to prev of new node and address of new node to prev of next node

### Insertion at end
Steps include :
1. Create a new node, allocate memory and assign data. Next of new node is NULL
2. If list is empty, assign prev of new node as NULL and make new node head
3. If not, temporarily store head and traverse linked list.
4. On finding last value, make next of temp equal new node and previous of new node as temp

---

## Deleting a node
We can delete a node from 3 different positions of a doubly linked list

### Deleting first node
To delete the first node, we create a temp variable that will store the initial head value and point the next value in the linked list be equal to head. Temp is then free and made equal to NULL. `head->prev` will also be updated to be equal NULL.

#### Complexity Analysis
- **Time Complexity :** O(1) Sinc we do not traverse the linked list hence constant time complexity.
- **Auxiliary Space :** O(1) No extra space required so constant space complexity.

### Deleting at end
To delete the last node, we create a temp struct variable to store the value while updating till the last node is reached. The memory of last node is freed and the next pointer of previous node is made NULL.

#### Complexity Analysis
- **Time Complexity :** O(1) Sinc we do not traverse the linked list hence constant time complexity.
- **Auxiliary Space :** O(1) No extra space required so constant space complexity.

### Delete from user
This function takes two parameters, one is pointer to head node and position to be deleted. The code will traverse till the node to be deleted is reached. It will then make the the next of previous node point to the next node and the previous of next node point to next of previous node.
In code :
- `temp->prev->next = temp->next`
- `temp->next->prev = temp->prev;`

Temp is the freed. 

#### Complexity Analysis
- **Time Complexity :** O(n) where n is the position of the node to be deleted.

---

## Reversing 
The following steps are used to reverse a doubly linked list :

1. Traverse the linked list using a pointer
2. Swap the prev and next pointers for all nodes
3. Lastly, change thr head pointer of the doubly linked list 

#### Complexity Analysis
- **Time Complexity :** O(N) where N denotes the number of nodes of doubly linked list.
- **Auxiliary Space :** O(1)

We can also swap data instead of pointers to reverse the Doubly Linked List. Method used for reversing array can be used to swap data. Swapping data can be costly compared to pointers if the size of the data item(s) is more.

---