# **Queue**

A **queue** is a linear and dynamic data structure that is open at both ends and operations are performed in the First In First Out (FIFO) principle. This means that the first data in is the first data that is out and the last in in the last out.

A practical example is a queue outside a cinema hall. The first person to get to the cinema hall will be the first person to get into the hall and last person in will be last to get in. This is the **First In First Out (FIFO)** principle.

Queue can also be defined as a list in which all additions to the list are made at one end and all deletions perfomed at other end. Element which is first pushed into the order then the operation is first perfomed on the element. 

Queue representation:

![Queue Representation](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_diagram.jpg)

Entry position in a queue is ready to be servd i.e first entry to be removed from queue is called **front/head** whule position of last entry i.e most recently added is called **rear/tail**

![Property of queue](https://media.geeksforgeeks.org/wp-content/uploads/20220805131014/fifo.png)

## Working of Queue
1. Two pointers **front** and **rear**
2. **front** track first element of queue
3. **rear** track last element of queue
4. Initially set **front** and **rear** to -1


## Basic Oprations on Queue
**- enqueue():** Insert element at end of queue i.e at rear end
**- dequeue():** Removes and returns element that is at front of queue
**- front()/peek():** Returns element at front end without removing
**- rear():** Return element at rear end without removing it
**- isEmpty():** Check whether queue is empty or not
**- isFull():** Checks if the queue is full
**- size():** Returns size of queue i.e total number of elements it contains 


### **peek() / front()**
Check data at **front** of queue

#### Algorithm
```
begin procedure peek

    return queue[front]

end procedure
```

### **isEmpty()**
Checks if queue is empty and returns true or false

#### Algorithm
```
begin procedure isEmpty

    if front is less than MIN OR front is greater than rear
        return true
    else
        return false
    endif

end procedure
```

### **isFull()**
Checks if queue is full and returns true or false

#### Algorithm
```
begin procedure isFull

    if rear equals to MAXSIZE
        return true
    else
        return false
    endif

end procedure
```

### **Enqueue Operation**
- Check if queue is full. If full produce overflow error and exit
- First element set **front** to 0
- Increase **rear** index by 1
- Add new element in position pointed by **rear**


![Enqueue](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_enqueue_diagram.jpg)


#### Enqueue Algorithm
```
procedure enqueue(data)

    if queue is full
        return overflow
    endif

    rear <- rear + 1
    queue[rear] <- data
    return true

end procedure
```

### **Dequeue Operation**
- Check if queue is empty
- Return value pointed by **front**
- Increase **front** index by 1
- Last element, reset **front** and **rear** to -1

![Dequeue](https://www.tutorialspoint.com/data_structures_algorithms/images/queue_dequeue_diagram.jpg)


#### Dequeue Algorithm
```
procedure dequeue

    if queue is empty
        return underflow
    end if 
    
    data = queue[front]
    front <- front + 1
    return true

end procedure
```

## Applications of Queue