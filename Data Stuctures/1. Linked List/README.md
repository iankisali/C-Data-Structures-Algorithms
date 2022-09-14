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
 