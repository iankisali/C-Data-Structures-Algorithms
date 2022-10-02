# Table of Contents

## What is a Linked List? 

A Linked List is a sequence of data structures, which are connected together via links i.e sequence of links which contains items. They include a series of connected nodes and each node stores the following :
- data item (i.e integer, strings etc)
- address of next node (connects one node to another)

Here is pictorial representation of a linked list :

![Linked-List](https://media.geeksforgeeks.org/wp-content/uploads/20220816144425/LLdrawio.png)

It has the following properties 
- If first node is empty, value of head points to NULL
- Successive elements are connected by pointer
- Last element points to NULL
- first node called the head of linked list
- Can grow or shrink in size during program execution
- Can be made as long as required.

## Types of Linked Lists:
**Simple Linked List**
: In this type, one can move or traverse the linked list in one direction.

**Doubly Linked List**
: In this type, one can traverse the linked list in both directions i.e forward or backward.

**Circular Linked List**
: Linked list in which the first and the last nodes are also connected to each other to form a circle. Here, the address of the last node consists of the address of the first node.

### How do we represent a node in C ?

In C, we represent a node using structures. Example below :
```
struct Node 
{
    int data;
    struct Node* next;
}
```
This is a node with an integer data type.

We can also represent a node as follows :
```
/**
 * struct listint_s - singly linked list
 * @data: integer type
 * @next: points to next node
 * Description: singly linked list node structure
 */

 typedef struct listint_s
 {
    int data;
    struct listint_s *next
 } listint_t;
```
We have used `typedef` to define a new data type. This data type can be used to define structure variables directly.

- `typedef` allows users to provide alternative names for the primitive (e.g int) and user defined (e.g struct) data types. This keyword adds a new name for existing data type but does not create a new type. Click [here](https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c) to learn more about `typedef` and `struct` in C.

We will create a simple linked list with three nodes containing different integers :
 
 ---

 ## Header File
**`header.h`** file contains function declaration and macro definitions to be shared with various source files. At the source files the header file is included using the preprocessing directive `#include "header.h"`. The construct of the header file is a **wrapper *`#ifndef`*** and this is the format used :

```
#ifndef _HEADER_
#define _HEADER_

The entire header file

#endif
```
---
 ## Printing a list
**`printList.c`** file contains code to print a Linked List. It print the data in the first node and updates the value to the next node. The loop ends when the data is NULL.

### Visual Representation of printing Linked List
![Print_LList](https://www.log2base2.com/images/ds/print-linked-list.png)
 
 ---

 ## Inserting a node
 We now have a linked list with three integers. We can insert a new node in the linked list in three ways :
 - At front of linked list
 - After given node
 - At end of linked list.
 
 ### **1. Inserting node at front**
 When a new node is added before the head of a given Linked List, it becomes the new head node of the list. Example if the Linked List is 2->4->6 and we want to add 5 at the front, the list becomes 5->2->4->6. Let us call the function insertHead(). The function must receive a pointer to head pointer since it changes the head pointer to point to new node.

  ![Insert_head](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png)

  #### Complexity Analysis
  - **Time Complexity** : O(1), we have a pointer to head and can directly add a node and change pointer. So time complexity of inserting node at head is O(1) as it does constant amount of time.
  - **Auxillary Space** : O(1).


  ### **2. Inserting node at nth position**
  We are given pointer to a node, and new node is inserted after given node.
  Steps include :
  - Check if previous node is NULL or not.
  - Allocate new node and assign data to new node
  - Make next of new node as next of previous node
  - Move next of previous node as new node.

  ![Insert_nth](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_middle.png)

  #### Complexity Analysis
  - **Time Complexity** : O(N), where N is size of linked list.

  - **Auxiliary Space** : O(1) since using constant space to modify pointers.

   ### **3. Inserting node at end**
   New node is always added after last node. Since a Linked List is typically represented by head we have to traverse till end then change next to last node to a new node.

   ![insert_end](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png)

   #### Complexity Analysis
  **Time Complexity** : O(N), where N is number of nodes in linked list. Since there is loop frim head to end, function O(n) work.

        The method can be optimized to work in O(1) by keeping extra pointer to tail of linked list.

  **Auxiliary Space** : O(1)

---
## Deleting a node
**`delete.c`** contains code for deletion of a node from a Linked List from the beginning(head), end, whole list and deleting from any position.

### Deleting from Beginning
We will create a variable to store original head value and make the next node to be equal to head. We then free the unused memory of the variable created.
 
### Deleting from End
We create a variable that is equal to head of Linked List and then loop through while updating the value of temporary variable. We then make the last node value equal to NULL. This will delete the value of last node.

### Deleting whole List
This are steps used to delete whole Linked List :
1. Create temp variable to store head value.
2. Introduce a loop and make next node equal to the temp variable
3. Free the temporary value
4. Make value of head equal to temp value

- **Time Complexity:** O(n)
- **Auxiliary Space:** O(1)

### Deleting from any positiom
This function takes two parameters i.e pointer to head and position to be deleted. 
1. First, create a temp variable pointing to head
2. If position to be deleted is 0 it prints the value and advances the head pointer to next value.
3. To delete at specific position, temp point to previous node of node to be deleted.
4. Delete pointer point to node to be deleted i.e by using `temp->next->next`
5. Remember to free the node

- **Best Case:** O(1) if given position is 1
- **Average & Worst Case:** O(N) if position given is size - 1 then need to traverse till position not found
- **Space Complexity:** O(1) no extra space required

---

## Reversing Linked List
**`reverse.c`** contains code to reverse a Linked List using three methods :
- Iterative method
- Tail Recursive Approach
- Head Recursive Approach

### Iterative 
1. Initializing 3 pointers. previous and next as NULL, current as head
2. Iterate through linked list. In loop do following:
  - store next node as next i.e `next = current->next`
  - change next of current. Reversing happens i.e `current->next=prev`
  - move previous and current one step forward
    -`previous = current` & `current->next`
3. Outside loop make head value as previous

Visual representation is as shown:

![Reversing Iteratively](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif) 

- **Time Complexity:** O(n)
- **Auxiliary Space:** O(1)

### Tail Recursive Method
The `reverseTail` function takes three parameters i.e current, previous and head. The if statement marks the last node as head and updates the next to previous node. Outside if statement, the next struct is saved for recursive call and the next is updated. 

In the `reverseTailRec` function it calls the `reverseTail` with the three parameters as (*head, NULL, head) i.e current as pointer to head, previous passed NULL, and head value

- **Time Complexity:**: O(N) We do certain operation for every node of linked list
- **Auxiliary Space:** O(1) Constant space used
