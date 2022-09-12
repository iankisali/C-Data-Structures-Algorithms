# What is data structure?

**Data structures**, as the term implies, are a way of structuring data in order to efficiently store, find, use, and create data, depending on the task at hand. We will learn over time to select and properly use data structures which fit the nature of the data you are working with.

The choice of a good data structure makes it possible to perform a variety of critical operations effectively. An efficient data structure also uses minimum memory space and execution time to process the structure.

## Classification of data structures
Data structures are broadly classified into two:
- **Linear data stucture**. Data structure in which data elements are arranged sequentially or linearly, where each element is attached to its previous and next adjacent elements. 
- **Non-linear data strucures**. Data structures where data elements are not placed sequentially or linearly.

<img align="center" src="https://media.geeksforgeeks.org/wp-content/uploads/20220520182504/ClassificationofDataStructure-660x347.jpg" alt="DS flowchart" />

- **Static data structure:**  has a fixed memory size. The content of the data structure can be modified but without changing the memory space allocated to it. Example is an array that holds a fixed number of values of one data type.
- **Dynamic data structure:**  is that kind of data structure that changes its size during runtime. It can be randomly updated during the runtime which may be considered efficient concerning the memory (space) complexity of the code. 
Examples of this data structure are queue, stack, linked list etc

## Choosing the right data structure.

Choosing the right data structure is important for better perfomance. Choosing a bad data structure will make the system not perform well. It is therefore important choosing the appropriate tool for different task.

### ⚡ Quote: 
<i>❝Based on requirements, always pick the right tool for the job. - DrewMarsh❞</i>

### 1. Linked List
Linked list is a data structure that links each node to the next node. It can be used in the following cases:
- When data dynamically grows.
- Need for constant time for insertion and deletion.
- Do not access random elements from Linked list.
- Insert element in any position of list.

### 2. Doubly Linked List
Doubly linked list is a data structure in which each node contains data and two links. One link points to the previous node and another link point to the next node. It can be used because of following reasons :
- Easier to delete node
- Can be iterated in reverse order without recursion implmentation
- Insertion or removal is fast