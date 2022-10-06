# Stack
A **stack** is a linear data structure that is dynamic in nature and behaves like a real world stack. An exanple of stack is a deck of cards or a pile of plates. A stack follows the principle of **Last In First Out (LIFO)** meaning that the last element inserted in the stack is first removed.

You can take a pile of plates kept on top of other as a real-example. The plate that was last placed on top is,most probably, the first placed to be removed i.e last plate in is the first plate out. If one wants to place a plate at the bottom , you must first remove all the plates on top. Same happens in a deck of cards. This is the principle of Last In First Out.

## Operations on Stack
In order to make manipulations in a stack, there are certain operations provided to us :
- **push()** : Insert element into stack
- **pop()** : Remove element from stack
- **peek()** : Return value of top element without removing it
- **top()** : Returns top element of stack
- **isEmpty()** : Return True if stack is empty else false
- **isFull** : Return True if stack full else otherwise
- **size()** : Returns size of stack

### LIFO Principle
![LIFO](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

## Working of Stack Data Structure
Operations are as follows :

1. A pointer called `top` is used to keep track of top element in stack.
2. When initializing stack, set value to -1 so as to check if stack is empty by comparing `top == -1`.
3. On pushing, increase `top` and place new element in position pointed to `top`.
4. On popping, return element pointed by top and reduce it's value
5. Before pushing, check if stack is full.
6. Before popping, check if stack empty. 

![Working Principle](https://cdn.programiz.com/sites/tutorial2program/files/stack-operations.png)

We will now check algorithms of basic operations

### peek()
Return value of top element without removing it.
Algorithm is as follows :
```
begin procedure peek

    return stack[top]

end precedure
```
### isFull()
Return boolean i.e True if stack full else false.
Algorithm is as follows :
```
begin procedure isFull

    if top equals MAXSIZE
        return true
    else
        return false
    endif

end procedure
```
### isEmpty()
Return boolean i.e True if stack is empty else false.
Algorithm is as follows :
```
begin procedure isEmpty

    if top < 1
        return true
    else
        return false
    endif

end procedure
```
### push()
Adding new data element onto a stack. Steps include :
1. Check if stack is full
2. If full, is said to be **overflow** condition.
3. If stack not full, increment top to point to next empty space.
4. Add data element to stack where top is pointing.
5. Return success

Pictorial Representation :


![Push Operation](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_push_operation.jpg)


Algorithm is as follows :
```
begin procedure push

    if stack is full
        return
    endif

    increment top
    stack[top] assign data

end procedure
``` 
### pop()

Process of accessing an element and removing it from stack. In array implementation of stack, data is not actually removed but top is decremented in stack so as to point to next element. In linked list implementation pop removes data element and deallocates memory space.

Steps taken include :
1. Check if stack is empty
2. If stack empty, said to be **underflow** condition.
3. If stack not emty, access data element which top is pointing to.
4. Decrement top by 1
5. Return success.

Pictorial Representation :

![Pop operation](https://www.tutorialspoint.com/data_structures_algorithms/images/stack_pop_operation.jpg)

Algorithm is as follows :
```
begin procedure pop

    if stack is empty
        return
    endif
    
    store value of stack[top]
    decrement top
    return value

end procedure
```

### Complexity Analysis
All the operations perfomed above have a complexity of **O(1)**.

## Stack Implementation
Stack can be implemented using two methods ;
- Using array
- Using Linked List

### Advantages of array implementation
1. Memory saved as pointers is not used
2. Easier to implement

### Disadvantages of array implementation
1. Not dynamic
2. Does not shrink or grow depending on needs at runtime.

### Advantages of linked list implementation
1. Can grow or shrink depending on needs at runtime.
2. It does not waste memory with unoccupied array fields
3. Cleans objects automatically
4. They do not get corrupted easily hence more secure and reliable.

### Disadvantages of linked list implementation
1. Require extra memory due to using pointers.
2. Total size must be defined before
3. Random accessibility not possible.


## Applications of Stack
- **Browsers** - While using a browser the back button saves all the URL's visited in a stack. A new stack is added when visiting a new page and on pressing back the current URL is removed from stack and previous URL accessed

- **Reversing** - Putting all data in a stack and popping them will produce letters in reverse

- **Compilers** - Compilers use stack to calculate value of expression by converting expression to prefix and postfix them. More info [here](https://www.javatpoint.com/applications-of-stack-in-data-structure)

- **Backtracking** - This is a recursive algorithm used for solving optimization problem

- Delimiter or parenthesis checking 