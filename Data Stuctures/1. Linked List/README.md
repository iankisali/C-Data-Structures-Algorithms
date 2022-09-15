# What is a Linked List? 

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
  **Time Complexity** : O(N), where N is size of linked list.
  **Auxiliary Space** : O(1) since using constant space to modify pointers.

   ### **3. Inserting node at end**
   New node is always added after last node. Since a Linked List is typically represented by head we have to traverse till end then change next to last node to a new node.

   ![insert_end](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png)

   #### Complexity Analysis
  **Time Complexity** : O(N), where N is number of nodes in linked list. Since there is loop frim head to end, function O(n) work.

        The method can be optimized to work in O(1) by keeping extra pointer to tail of linked list.
        
  **Auxiliary Space** : O(1)

